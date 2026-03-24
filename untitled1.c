#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//int main(){
//	char arr1[]="abc";//字符串
//	char arr2[]={'a','b','c',0};
//	printf("%s\n",arr1);
//	printf("%s\n",arr2);
//	printf("%d\n",strlen(arr1));//计算字符串的长度
//	printf("%d\n",strlen(arr2));
//	printf("\'");
//	return 0;
//}
//ADD为一个自定义函数
int ADD(int x,int y){//()是函数调用操作符
	int z=x+y;
	return z;
}
//创建一个结构体类型其实就相当于创建了一个类型不过访问里面的内容需要用到其他函数
struct Student{
	char name[20];
	int age;
};
int MAx(int g,int f){
	if(g>f){
		return g;
	}else{
		return f;
	}
}
//用宏的定义来计算两数和类似于上面函数
#define MAX(x,y) (x+y)
void change_dou_signal(int* arr,int sz){
	int left=0;
	int right=sz-1;
	while(left<right){
		while((arr[left]%2==1)&& left<right){
			left++;
		}
		while((arr[right]%2==0)&& left<right){
			right--;
		}
		if(left<right){
			int tmp=arr[left];
			arr[left]=arr[right];
			arr[right]=tmp;
			left++;
			right--;
			
		}
	}
}
int main(){
//	int line=0;
//	printf("加入比特\n");
//	//循环语句while
//	while(line<20000){
//		printf("写代码行数: %d\n",line);
//		line++;
//	}
//	if(line==20000){
//		printf("找到工作");
//	}
//	int a=0;
//	int b=0;
//	printf("请输入2个数字\n");
//	scanf("%d%d",&a,&b);
//	int sum=ADD(a,b);
//	printf("两数相加为: %d\n",sum);
//	int a=5%4;//%为取模计算符取的是余数
//	printf("%d\n",a);
//	int b=a>>1;//>>为右移操作符移动的是2进制位<<同理
//	//(二进制)位操作符
//	int c=a&b;//按位与指的是二进制位相与
//	int d=a|b;//按位或是二进制或
//	int e=a^b;//按位异或是二进制异或
//	int v=~a;//~按二进制位取反0变1,1变0
//	printf("%d\n",v);
//	printf("%d\n",b);
//	printf("%d\n",c);
//	printf("%d\n",d);
//	printf("%d\n",e);
//	//单（双，三）目操作符是指有一个（2个，3个）变量的操作数
//	a=!a;//单目操作符
//	printf("%d\n",a);
//	int a=0;
//	int b=0;
//	printf("请输入2个数字\n");
//	scanf("%d%d",&a,&b);
//	int c=MAx(a,b);
//	printf("较大的值为:%d\n",c);
//	extern int s;
//	printf("%d\n",s);
//    int a=20;
//	int b=30;
//	int c=MAX(a,b);
//	printf("和为%d\n",c);
//	int a=0;
//	printf("%p\n",&a);
//	printf("%d\n",a);
//	int* p=&a;//变量p为指针变量其数据类型为int*，指针变量的大小（只有这2种大小）在32位电脑占4个字节64位8个字节
//	*p=20;//*--为解引用操作符可以利用该符号改变a的值,而*p就相当于a
//	printf("%p\n",p);
//	printf("%d\n",a);
//	printf("%d\n",sizeof(p));
//    struct Student s={"张三",20};
//	struct Student* p=&s;//取结构体变量地址
//	strcpy(s.name,"李四");//拷贝函数用于改变结构体的字符类型
//	s.age=22;//改变结构体的整型变量
//	//.指向结构体变量用法是变量.成员   ->指向结构体指针用法是指针->成员
//	printf("%d\n",(*p).age);//利用指针p访问结构体
//	printf("%s\n",p->name);//同上
//	printf("%d\n",p->age);//同上
//	printf("%s\n",s.name);//结构体变量的打印
//	printf("%d\n",s.age);
//	int a=0;
//	scanf("%d",&a);
//	if(a%2==0){
//		printf("输入的数bu为奇数");
//	}
//	int a=0;
//	while(a<100){
//		if(a%2==1){
//		printf("%d ",a);	
//		}
//		a++;
//}
//	int a=0;
//	int b=0;
//	int c=0;
//	int num=0;
//	while(a<10){
//		scanf("%d",&num);
//		if(num%2==1){
//			b++;
//		}else if(num%2==0){
//			c++;
//		}
//		a++;
//		
//	}
//	printf("奇数的个数为 %d\n",b);
//	printf("偶数的个数为 %d\n",c);
//	int a=0;
//	int sum=0;
//	while(a<100){
//		if(a%2==1){
//			sum=sum+a;
//		}
//		a++;
//	}
//	printf("奇数和为:%d\n",sum);
//	int a=0;
//	int b=0;
//	int sum=0;
//	printf("请输入整数个数");
//	scanf("%d",&a);
//	while(b<a){
//		b++;
//		scanf("%d",&sum);
//		if(sum%2==1){
//			printf("其中奇数为:%d\n",sum);
//		}
//	}
//	int sum=1;
//	int s=0;
//	printf("请输入一个整数");
//	scanf("%d",&s);
//	for(int i=1;i<=s;i++){
//		sum=sum*i;
//	}
//	printf("该阶乘为%d\n",sum);
//	int sum=0;
//	for(int i=1;i<=10;i++){
//		int s=1;
//		for(int j=1;j<=i;j++){
//			s=s*j;
//		}
//		sum=sum+s;
//	}
	//计算1!+2!一直到10！
//	int sum=0;
//	int s=1;
//	for(int i=1;i<=10;i++){
//		s=s*i;
//		sum=sum+s;
//	}
//	printf("%d\n",sum);
	//二分查找算法-常用于有序的算法
//	int arr[]={1,2,3,4,5,6,23,45,67,88,90};
//	int sz=sizeof(arr)/sizeof(arr[0]);
//	int a=0;
//	int left=0;
//	int right=sz-1;
//	for(int i=0;i<=sz-1;i++){
//		printf("%d ",arr[i]);
//	}
//	printf("请输入其中一个数字\n");
//	scanf("%d",&a);
//	while(left<=right){
//		int mid=(left+right)/2;
//		if(arr[mid]<a){
//			left=mid+1;
//		}else if(arr[mid]>a){
//			right=mid-1;
//		}else{
//			printf("找到了，该数下标是%d\n",mid);
//			break;
//		}
//	}
//	if(left>right){
//		printf("找不到，该数不存在");
//	}
//	char arr1[]="fack! fack! fack!";
//	char arr2[]="#################";
//	int left=0;
//	int sz=strlen(arr1);
//	int right=sz-1;
//	while(left<=right){
//		arr1[left]=arr2[left];
//		left++;
//		arr1[right]=arr2[right];
//		right--;
//		printf("%s\n",arr1);
//	}
//	char arr[10]={};
//	for(int i=1;i<=3;i++){
//		scanf("%s",arr);
//		if(strcmp(arr,"123456")==0){
//			printf("登入成功\n");
//			break;
//		}else{
//			printf("登入失败\n");
//		}
//	}
//	int n=0;
//	scanf("%d",&n);
//	for(int i=0;i<n;i++){
//		printf("\n");
//		for(int j=0;j<n;j++){
//			printf("*");
//		}
//	}
//		int n=0;
//	scanf("%d",&n);
//	for(int i=0;i<=n;i++){
//		printf("\n");
//		for(int j=0;j<=i;j++){
//			printf("*");
//		}
//	}
//	int n=0;
//	scanf("%d",&n);
//	int sum=0;
//	for(int i=1;i<=n;i++){
//		sum=sum+i;
//	}
//	printf("%d\n",sum);
//	int n=0;
//	scanf("%d",&n);
//	for(int i=0;i<=n;i++){
//		printf("\n");
//		for(int j=1;j<=n-i;j++){
//			printf(" ");
//		}
//		for(int j=1;j<=2*i-1;j++){
//			printf("*");
//		}
//	}
//    for(int i=1;i<=9;i++){
//		printf("\n");
//		for(int j=1;j<=i;j++){
//			printf("%d*%d=%d ",i,j,i*j);
//		}
//	}
//	for(int i=1;i<=100;i++){
//		if(i%3==0){
//			printf("%d ",i);
//		}
//	}
//	int a=0;
//	int b=0;
//	int c=0;
//	scanf("%d %d %d",&a,&b,&c);
//	if(a<b){
//		int s=a;
//		a=b;
//		b=s;
//	}if(a<c){
//		int s=a;
//		a=c;
//		c=s;
//	}if(b<c){
//		int s=b;
//		b=c;
//		c=s;
//	}
//	printf("%d %d %d",a,b,c);	
//	for(int i=1000;i<=2000;i++){
//		if(i%400==0){
//			printf("%d ",i);
//			c++;
//		}else if(i%4==0 && i%100!=0){
//			printf("%d ",i);
//			c++;
//		}
//	}
//	printf("\n个数为 %d个",c);
//	int c=0;
//	for(int i=100;i<=200;i++){
//		int d=1;
//		for(int j=2;j<=sqrt(i);j++){
//			if(i%j==0){
//				d=0;
//				break;
//			}
//		}
//		if(d==1){
//			c++;
//			printf("%d ",i);
//		}
//	}
//	printf("\n个数为 %d",c);
//	int a, b, s;
//	scanf("%d%d", &a, &b);
//	while((s = a % b) != 0) {  // 先求余数，再判断是否为0
//		a = b;                  // b变成新的a
//		b = s;                  // 余数变成新的b
//		}
//	printf("最大公约数为：%d\n", b);  // 最后b就是GCD
	int arr[10]={0};
	int sz=sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<=sz-1;i++){
		scanf("%d",&arr[i]);
	}
	change_dou_signal(arr,sz);
	for(int i=0;i<=sz-1;i++){
		printf("%d ",arr[i]);
	}
	printf("hehe\n");
	return 0;
}


