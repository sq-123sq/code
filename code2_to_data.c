#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct TData{
    int year;
    int month;
    int day;
}tdata;
tdata* create_data()
{
    tdata* data = (tdata*)malloc(sizeof(tdata));
    if(data == NULL){
        return NULL;
    }
    data->year = 0;
    data->month = 0;
    data->day = 0;
    return data;
}
void setdata(struct TData* data){
    scanf("%d %d %d", &data->year, &data->month, &data->day);
}
void printdata(struct TData* data){
    printf("%d/%d/%d\n", data->day, data->month, data->year);
}
// int main(){
//     tdata* data= create_data();
//     setdata(data);
//     printdata(data);
//     return 0;
// }




typedef struct rectangle{
    int width;
    int height;
}rectangle;
typedef struct circle{
    int radius;
}circle;
typedef struct square{
    int side;
}square;
typedef struct shape{
    rectangle rect;
    circle circle;
    square square;
}shape;
shape* create_shape(){
    shape* shape1 = (shape*)malloc(sizeof(shape));
    if(shape1 == NULL){
        return NULL;
    }
    shape1->rect.width = 0;
    shape1->rect.height = 0;
    shape1->circle.radius = 0;
    shape1->square.side = 0;
    return shape1;
}
void getarea(shape* shape1){
    printf("%d\n", shape1->rect.width * shape1->rect.height);
    printf("%lf\n", shape1->circle.radius * shape1->circle.radius * 3.14);
    printf("%d\n", shape1->square.side * shape1->square.side);
}
// int main(){
//     shape* shape1 = create_shape();
//     printf("长方形: ");
//     scanf("%d %d", &shape1->rect.width, &shape1->rect.height);
//     printf("圆形: ");
//     scanf("%d", &shape1->circle.radius);
//     printf("正方形: ");
//     scanf("%d", &shape1->square.side);
//     getarea(shape1);
//     return 0;
// }

#define EPS 1e-6
typedef struct book{
    char name[20];
    double price;
}book;
book* create_book(int n){
    book* book1 = (book*)malloc(sizeof(book)*n);
    if(book1 == NULL){
        return NULL;
    }
    for(int i = 0; i < n; i++){
        book1[i].price = 0.0;
        strcpy(book1[i].name, "");
    }
    return book1;
}
int cmp_double(const void* a, const void* b)
{
    // 安全解引用
    double da = *(const double*)a;
    double db = *(const double*)b;

    // 处理 NaN 情况
    // 如果两个都是 NaN，视为相等
    if (isnan(da) && isnan(db)) {
        return 0;
    }
    // 如果只有 a 是 NaN，视 a 为更大（排在后面）
    if (isnan(da)) {
        return 1;
    }
    // 如果只有 b 是 NaN，视 b 为更大（即 a 更小，排在前面）
    if (isnan(db)) {
        return -1;
    }
    if(da>db) return 1;
    if(da<db) return -1;
    return 0;

    // 处理正常数值比较
    // if (da > db) {
    //     return 1;
    // } else if (da < db) {
    //     return -1;
    // } else {
    //     // 相等时返回 0，修复原代码中相等返回 -1 的逻辑bug
    //     return 0;
    // }
}
void swap_book(book* a, book* b)
{
    book temp = *a;
    *a = *b;
    *b = temp;
}
void bookbubble(book* book1, int n)
{
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(book1[j].price > book1[j + 1].price + EPS){
                swap_book(&book1[j], &book1[j + 1]);
        }
    }
 }
}
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     book* book1 = create_book(n);
//     for(int i = 0; i < n; i++){
//         scanf("%s %lf", book1[i].name, &book1[i].price);
//     }
//     qsort(book1,n,sizeof(book),cmp_double);
//     //bookbubble(book1, n);
//     for(int i = 0; i < n; i++){
//         printf("%s %lf\n", book1[i].name, book1[i].price);
//     }
//     return 0;
// }


typedef struct direction{
    int x;
    int y;
}direction;
direction* create_direction(int n){
    direction* dir = (direction*)malloc(sizeof(direction)*n);
    if(dir == NULL){
        return NULL;
    }
    for(int i = 0; i < n; i++){
        dir[i].x = 0;
        dir[i].y = 0;
    }
    return dir;
}
void print_direction(direction* dir, int n){
    int sumx=0;
    int sumy=0;
    for(int i = 0; i < n; i++){
        sumx += dir[i].x;
        sumy += dir[i].y;
    }
    printf("%d %d\n", sumx, sumy);
}
// int main(){
//     int n;
//     scanf("%d", &n);
//     direction* dir = create_direction(n);
//     for(int i = 0; i < n; i++){
//         scanf("%d%d", &dir[i].x, &dir[i].y);
//     }
//     print_direction(dir, n);
//     return 0;
// }



typedef struct time2{
    int hour;
    int minute;
    int second;
}time2;
time2* create_time(int n){
    time2* reltime = (time2*)malloc(sizeof(time2)*n);
    if(reltime == NULL){
        return NULL;
    }
    for(int i = 0; i < n; i++){
        reltime[i].hour = 0;
        reltime[i].minute = 0;
        reltime[i].second = 0;
    }
    return reltime;
}
void time_to_times(time2* time1, int* times, int n){
    for(int i=0;i<n;i++){
        int sum=0;//sum 为 第 i 个时间段的总秒数,一定要置0防重复
        for(int j=0;j<=i;j++){
            sum+=times[j];
        }
        time1[i].hour = sum/3600;
        time1[i].minute = sum/60;
        time1[i].second = sum%60;
    }
}
void print_time(time2* time1, int n){
    for(int i = 0; i < n; i++){
        printf("%02d:%02d:%02d\n", time1[i].hour, time1[i].minute, time1[i].second);
    }
}
// int main(){
//     int n;
//     scanf("%d", &n);
//     time2* time1 = create_time(n);
//     int* times = (int*)malloc(sizeof(int)*n);
//     if(times == NULL){
//         return 1;
//     }
//     for(int i=0;i<n;i++){
//         scanf("%d",&times[i]);
//     }
//     time_to_times(time1,times,n);
//     print_time(time1,n);
//     return 0;
// }

void digit(int x, int i){
    int temp = x;
    int count = 0;
    while(temp){
        count++;
        temp /= 10;
    }
    if(i > count){
        printf("error\n");
    }
    else{
        int digit = x %(int)pow(10, i) ;
        printf("%d\n", digit);
    }
}
// int main(){
//     int x,i;
//     scanf("%d%d",&x,&i);
//     digit(x,i);
//     return 0;
// }