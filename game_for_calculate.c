#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h> // 需要用到 isdigit 判断数字


#define NUM_STACK_SIZE 100
#define OP_STACK_SIZE  50

// ================= 错误码定义 =================
#define CALC_SUCCESS        0  // 计算成功
#define ERR_DECIMAL         1  // 小数点错误 (如 .0.2)
#define ERR_BRACKET         2  // 括号不匹配
#define ERR_DIV_ZERO        3  // 除数为0
#define ERR_INVALID_CHAR    4  // 非法字符
#define ERR_STACK_OVERFLOW  5  // 栈溢出(表达式过长)



// ================= 动态数字栈（链表实现） =================
typedef struct num_node {
    double data;
    struct num_node* next;
} num_node;

typedef struct task_num {
    num_node* top; // 栈顶指针指向链表头
} task_num;

task_num* init_stack_num() {
    task_num* p = (task_num*)malloc(sizeof(task_num));
    if (!p) return NULL;
    p->top = NULL;
    return p;
}

void destroy_stack_num(task_num* p) {
    if (!p) return;
    num_node* curr = p->top;
    while (curr) {
        num_node* tmp = curr->next;
        free(curr); // 逐个释放节点
        curr = tmp;
    }
    free(p); // 释放栈结构体
}

int push_num(task_num* p, double data) {
    if (!p) return 0;
    num_node* new_node = (num_node*)malloc(sizeof(num_node));
    if (!new_node) { printf("内存分配失败!\n"); return 0; }
    new_node->data = data;
    new_node->next = p->top; // 新节点指向原来的栈顶
    p->top = new_node;       // 栈顶更新为新节点
    return 1;
}

double pop_num(task_num* p) {
    if (!p || !p->top) { printf("错误：数字栈为空\n"); return 0; }
    num_node* tmp = p->top;
    double data = tmp->data;
    p->top = tmp->next; // 栈顶下移
    free(tmp);          // 释放弹出的节点
    return data;
}

// ================= 动态符号栈（链表实现） =================
typedef struct op_node {
    char data;
    struct op_node* next;
} op_node;

typedef struct task_op {
    op_node* top;
} task_op;

task_op* init_stack_op() {
    task_op* p = (task_op*)malloc(sizeof(task_op));
    if (!p) return NULL;
    p->top = NULL;
    return p;
}

void destroy_stack_op(task_op* p) {
    if (!p) return;
    op_node* curr = p->top;
    while (curr) {
        op_node* tmp = curr->next;
        free(curr);
        curr = tmp;
    }
    free(p);
}

int push_op(task_op* p, char data) {
    if (!p) return 0;
    op_node* new_node = (op_node*)malloc(sizeof(op_node));
    if (!new_node) { printf("内存分配失败!\n"); return 0; }
    new_node->data = data;
    new_node->next = p->top;
    p->top = new_node;
    return 1;
}

char pop_op(task_op* p) {
    if (!p || !p->top) { return '\0'; }
    op_node* tmp = p->top;
    char data = tmp->data;
    p->top = tmp->next;
    free(tmp);
    return data;
}

char get_op_top(task_op* p) {
    if (!p || !p->top) return '\0';
    return p->top->data;
}
int is_num(char c) { return (c>='0' && c<='9'); }
int get_op_priority(char c) {
    switch (c) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3; // 幂运算优先级最高
        default:  return 0; 
    }
}


double calculate1(double a, char c, double b, int* err_code) {
    if (c == '/' && b == 0) { *err_code = ERR_DIV_ZERO; return 0; }
    switch(c){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b); // 使用 math.h 的幂函数
        default: return 0;
    }
}


// 在 calculate 函数最开头调用此函数，将 √ 转换为 ^(1/2) 格式
// 预处理函数：将 √ 转换为 ^(1/2) 格式
void preprocess_expr(char* str) {
    if (str == NULL) return;
    
    int len = strlen(str);
    char* temp = (char*)malloc(len * 3 + 1); // 动态分配，最坏情况每字符扩展3倍 (如 s -> ^(1/2))
    if (temp == NULL) return;                 // 分配失败则放弃预处理
    
    int j = 0; 
    
    for (int i = 0; str[i] != '\0'; ) {
        if (str[i] == 's' || str[i] == 'S') {
            i++; // 跳过 's' 本身
            
            // 提取根号下的内容
            int start = i;
            int bracket_count = 0;
            
            if (str[i] == '(') {
                bracket_count = 1;
                i++;
                while (str[i] != '\0' && bracket_count > 0) {
                    if (str[i] == '(') bracket_count++;
                    else if (str[i] == ')') bracket_count--;
                    i++;
                }
            } else {
                while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
                    i++;
                }
            }
            
            // 直接拷贝组装，避免使用 sprintf
            temp[j++] = '(';
            int unit_len = i - start;
            memcpy(temp + j, str + start, unit_len);
            j += unit_len;
            // 追加 )^(1/2)
            const char* suffix = ")^(1/2)";
            int suffix_len = 7;
            memcpy(temp + j, suffix, suffix_len);
            j += suffix_len;
            
        } else {
            temp[j++] = str[i++];
        }
    }
    
    temp[j] = '\0';
    strcpy(str, temp);
    free(temp);
}



// ================= 核心逻辑 =================
// 返回值改为 int（错误码），计算结果通过指针参数带出
int calculate(char* str, double* out_result) {
    if (str == NULL) return ERR_INVALID_CHAR;

    task_num* p_num = init_stack_num();
    task_op* p_op = init_stack_op();
    if (!p_num || !p_op) { destroy_stack_num(p_num); destroy_stack_op(p_op); return ERR_STACK_OVERFLOW; }

    int i = 0;
    int error = CALC_SUCCESS; // 记录错误类型

    while (str[i] != '\0') {
        if (str[i] == ' ') { i++; continue; }

        if (is_num(str[i]) || str[i] == '.') {
            double num = 0; double point = 0.1; int flag = 0;
            if (str[i] == '.') flag = 1;
           
            while (is_num(str[i]) || str[i] == '.') {
                if (str[i] == '.') {
                    if (flag == 1) {
                        // 【关键修改1】：发现连续小数点，记录错误并立刻退出
                        error = ERR_DECIMAL;
                        goto ERROR_EXIT;
                    }
                    flag = 1; i++; continue;
                }
                if (flag == 0) { num = num * 10 + (str[i] - '0'); } 
                else { num = num + point * (str[i] - '0'); point *= 0.1; }
                i++;
            }
            if (!push_num(p_num, num)) { error = ERR_STACK_OVERFLOW; goto ERROR_EXIT; }
        }
        else if (str[i] == '(') {
            if (!push_op(p_op, str[i])) { error = ERR_STACK_OVERFLOW; goto ERROR_EXIT; }
            i++;
        }
        else if (str[i] == ')') {
            while (p_op->top != NULL && get_op_top(p_op) != '(') {
                char op = pop_op(p_op); double b = pop_num(p_num); double a = pop_num(p_num);
                double ret = calculate1(a, op, b, &error);
                if (error != CALC_SUCCESS) goto ERROR_EXIT;
                if (!push_num(p_num, ret)) { error = ERR_STACK_OVERFLOW; goto ERROR_EXIT; }
            }
            if (p_op->top != NULL) {
                pop_op(p_op); 
            } else {
                // 【关键修改2】：右括号多出来了，括号不匹配
                error = ERR_BRACKET; 
                goto ERROR_EXIT;
            }
            i++;
        }
        else { 
            if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '^') {
                // 遇到不认识的字符（排除了幂运算 ^）
                error = ERR_INVALID_CHAR;
                goto ERROR_EXIT;
            }

            // 处理一元负号
            if (str[i] == '-') {
                int is_unary = 0;
                if (i == 0) { is_unary = 1; } 
                else {
                    int pre = i - 1;
                    while (pre >= 0 && str[pre] == ' ') pre--;
                    if (pre < 0 || str[pre] == '(' || get_op_priority(str[pre]) > 0) is_unary = 1;
                }
                if (is_unary) { if (!push_num(p_num, 0)) { error = ERR_STACK_OVERFLOW; goto ERROR_EXIT; } }
            }

            while (get_op_priority(str[i]) <= get_op_priority(get_op_top(p_op))) {
                char op = pop_op(p_op); double b = pop_num(p_num); double a = pop_num(p_num);
                double ret = calculate1(a, op, b, &error);
                if (error != CALC_SUCCESS) goto ERROR_EXIT;
                if (!push_num(p_num, ret)) { error = ERR_STACK_OVERFLOW; goto ERROR_EXIT; }
            }
            if (!push_op(p_op, str[i])) { error = ERR_STACK_OVERFLOW; goto ERROR_EXIT; }
            i++;
        }
    }
    
    while (p_op->top != NULL) {
        char op = pop_op(p_op);
        if (op == '(') { 
            // 【关键修改4】：扫完字符串还有左括号，括号不匹配
            error = ERR_BRACKET; 
            goto ERROR_EXIT; 
        }
        double b = pop_num(p_num); double a = pop_num(p_num);
        double ret = calculate1(a, op, b, &error);
        if (error != CALC_SUCCESS) goto ERROR_EXIT;
        if (!push_num(p_num, ret)) { error = ERR_STACK_OVERFLOW; goto ERROR_EXIT; }
    }

    *out_result = pop_num(p_num);
    destroy_stack_num(p_num);
    destroy_stack_op(p_op);
    return CALC_SUCCESS; // 成功返回0

ERROR_EXIT:
    destroy_stack_num(p_num);
    destroy_stack_op(p_op);
    return error; // 失败返回对应错误码
}

// ================= 交互主函数 =================
int main()
{
    char str[512]; // 稍微开大点，因为预处理可能会让字符串变长
    double result = 0.0;

    while (1) {
        printf("\n请输入表达式（用 s 表示根号，如 s9=3，^ 表示幂，输入 q 退出）：\n> ");

        
        if (fgets(str, sizeof(str), stdin) == NULL) break;
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') str[len - 1] = '\0';
        
        if (strcmp(str, "q") == 0) {
            printf("程序已退出。\n");
            break;
        }
        if (strlen(str) == 0) continue;

        // ==========================================
        // 关键顺序：先预处理，再计算！
        // ==========================================
        preprocess_expr(str); // 把 √9 变成 (9)^(1/2)
        
        // 调试用：如果你想看看预处理后变成了什么，可以把下面这行注释去掉
        // printf("预处理后的内部表达式：%s\n", str); 

        int err_code = calculate(str, &result);

        // ... 后面的错误码判断逻辑保持不变 ...
        switch (err_code) {
            case CALC_SUCCESS:
                printf("结果：%lf\n", result);
                break;
            case ERR_DECIMAL:
                printf("? 错误：小数点格式错误（如出现了 .0.2），请重新输入！\n");
                break;
            case ERR_BRACKET:
                printf("? 错误：括号不匹配，请重新输入！\n");
                break;
            case ERR_DIV_ZERO:
                printf("? 错误：除数不能为0，请重新输入！\n");
                break;
            case ERR_INVALID_CHAR:
                printf("? 错误：表达式中包含无法识别的字符，请重新输入！\n");
                break;
            case ERR_STACK_OVERFLOW:
                printf("? 错误：表达式过长导致栈溢出，请重新输入！\n");
                break;
            default:
                printf("? 未知错误，请重新输入！\n");
                break;
        }
    }  
    return 0;
}
