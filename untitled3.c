#include <stdio.h>
#include <stdlib.h>
#define 
void print(int (*p)[3],int c,int r){
	for(int i=0;i<c;i++){
		for(int j=0;j<r;j++){
			printf("%d ",*(*(p+i)+j));//*(p+i)指的是滴i行的首元素地址，p+i指的是第i行的指针，*(p+i)+j则是第i行第j列的元素地址，*(*(p+i)+j)第i行第j列元素的值
		}
		printf("\n");
	}
}
int ADD(int x,int y){
	return x+y;
}
int ESC(int x,int y){
	return x-y;
}
int ASD(int x,int y){
	return x*y;
}
int DIV(int x,int y){
	return x/y;
}
void menu(){
	printf("\n*****************************\n");
	printf("***1.ADD         2.ESC  *****\n");
	printf("***3.ASD         4.DIV ******\n");
	printf("***0.exit              ******\n");
}
void calc(int (*pa)(int,int)){
	int a=0;
	int b=0;
	int ret=0;
	printf("请输入2个操作数:");
	scanf("%d%d",&a,&b);
	ret=pa(a,b);
	printf("%d",ret);
}
void bublt(int arr[],int sz){
	for(int i=0;i<sz-1;i++){
		int flag=1;
		for(int j=0;j<sz-i-1;j++){
			if(arr[j]>arr[j+1]){
				int tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
				flag=0;
			}
		}
		if(flag==1){
			break;
		}
	}
}
//比较函数
int cmp_int(const void* e1,const void* e2){
	return *(int*)e1-*(int *)e2;
}
//交换函数
void Swap(int width,char* buf1,char* buf2){
	for(int i=0;i<width;i++){
		char tmp=*buf1;
		*buf1=*buf2;
		*buf2=tmp;
		buf1++;
		buf2++;
	}
}
//通用类型比较
void bubble_sort(void* base,int sz,int width, int (*cmp)(const void* e1,const void* e2)){
	for(int i=0;i<sz-1;i++){
		int flag=1;
		for(int j=0;j<sz-i-1;j++){
			if(cmp((char*)base+j*width,(char*)base+(j+1)*width)>0){
				Swap(width,(char*)base+j*width,(char*)base+(j+1)*width);
				flag=0;
			}
		}
		if(flag==1){
			break;
		}
	}
}
int main(){
//	int arr[3]={1,2,3};
//	int (*p)[3]=&arr;
//	for(int i=0;i<3;i++){
//		printf("%d ",*((*p)+i));
//	}
//	int arr[2][3]={1,2,3,4,5,65};
//	print(arr,2,3);
//	int arr[]={1,2,3,4,5,6,7,8};
//	int (*pa)[8]=&arr;//pa是数组指针是指向数组的指针它的类型是int (*)[8]
//    for(int i=0;i<8;i++){
//		printf("%d ",*((*pa)+i));//利用pa打印数组
//	}
//	int a=0;
//	int b=0;
//	scanf("%d%d",&a,&b);
//	int ret=0;
//	int (*ptr)(int,int)=&ADD;//ptr是一个函数指针它的数据类型是int (*)(int,int)
//	ret=ptr(a,b);//ptr的使用也可以用(*ptr)(a,b);
//	printf("%d\n",ret);
//	int input=0;
//	do{
//		menu();
//		printf("请输入数字:");
//		scanf("%d",&input);
//		switch (input) {
//		case 1:
//		    calc(ADD);
//			break;
//		case 2:
//			calc(ESC);
//			break;
//		case 3:
//			calc(ASD);
//			break;
//		case 4:
//			calc(DIV);
//			break;
//		case 0:
//			printf("退出程序\n");
//			break;
//		default:
//			printf("输入错误，请重新输入\n");
//			break;
//		}
//	}while(input);
//下面的是之前的计算器，上面是利用函数指针改良的计算器更加简单易懂，二者效果相同	
//	int a=0;
//	int b=0;
//	int ret=0;
//	int input=0;
//	do{
//		menu();
//		printf("请输入数字:");
//		scanf("%d",&input);
//		switch (input) {
//		case 1:
//			printf("请输入2个操作数:");
//			scanf("%d%d",&a,&b);
//			ret=ADD(a,b);
//			printf("%d",ret);
//			break;
//		case 2:
//			printf("请输入2个操作数:");
//			scanf("%d%d",&a,&b);
//			ret=ESC(a,b);
//			printf("%d",ret);
//			break;
//		case 3:
//			printf("请输入2个操作数:");
//			scanf("%d%d",&a,&b);
//			ret=ASD(a,b);
//			printf("%d",ret);
//			break;
//		case 4:
//			printf("请输入2个操作数:");
//			scanf("%d%d",&a,&b);
//			ret=DIV(a,b);
//			printf("%d",ret);
//			break;
//		case 0:
//			printf("退出程序\n");
//			break;
//		default:
//			printf("输入错误，请重新输入\n");
//			break;
//		}
//	}while(input);
//	int (*ptr)(int,int)=&ADD;//ptr是一个函数指针是指向函数的指针
//	int ret=ptr(2,3);
//	printf("%d\n",ret);
//	int (*pptr[4])(int,int)={ADD,ASD,DIV,ESC};//pptr是函数指针的数组
//	for(int i=0;i<4;i++){
//		int sq=pptr[i](2,3);//对函数指针数组的遍历就相当于用操作数对数组中的函数进行传参调用并打印结果
//		printf("%d\n",sq);
//	}
	//利用函数指针数组再次优化的计算器不使用Switch语句更加简单易懂
//	int a=0;
//	int b=0;
//	int ret=0;
//	int input=0;
//	do{
//		menu();
//		printf("请输入数字:");
//		scanf("%d",&input);
//		int (*pptr[5])(int,int)={0,ADD,ESC,ASD,DIV};
//		if(input==0){
//			printf("退出程序\n");
//		}else if(input>=1 &&input<=4){
//			printf("请输入2个操作数:");
//			scanf("%d%d",&a,&b);
//			ret=pptr[input](a,b);
//			printf("%d",ret);
//		}else{
//			printf("输入错误，请重新输入\n");
//		}
//	}while(input);
//	int nums[4]={0};
//	int target=0;
//		for(int i=0;i<4;i++){
//			scanf("%d",&nums[i]);
//		}
//		scanf("%d",&target);
//	for(int i=0;i<4;i++){
//		for(int j=i+1;j<4;j++){
//			if(nums[i]+nums[j]==target){
//				printf("%d %d",i,j);
//			}
//		}
//	}
	int arr[]={9,8,7,6,5,4,2,1,0};
	int sz=sizeof(arr)/sizeof(arr[0]);
	//qsort(arr,sz,sizeof(arr[0]),cmp_int);//qsort有给任意数据类型排序的功能，只不过cmp_int比较函数需要自己写但可以利用宏自动生成各种比较函数
	//bublt(arr,sz);
	bubble_sort(arr,sz,sizeof(arr[0]),cmp_int);
	for(int i=0;i<sz;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
