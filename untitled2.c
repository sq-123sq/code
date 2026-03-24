#include <stdio.h>
#include <math.h>
int max(int x,int y){
	if(x>y){
		return x;
	}else{
		return y;
	}
}
void swap(int* x,int* y){
	int s=*x;
	*x=*y;
	*y=s;
}
int shu(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
void nian(int n){
	if(((n%100!=0)&&(n%4)==0)||(n%400==0)){
		printf("是闰年\n");
	}else{
		printf("不是闰年\n");
	}
}
int BN(int* arr,int k,int sz){
	int right=sz-1;
	int left=0;
	while(left<=right){
		int mid=(right+left)/2;
		if(arr[mid]>k){
			right=mid-1;
		}else if(arr[mid]<k){
			left=mid+1;
		}else{
			return mid;
		}
	}
	return 0;
}
void plus(int x){
	while(1){
		x++;
		printf("%d ",x);
	}
}
void plas(int n){
	if(n>9){
		plas(n/10);
	}
	printf("%d ",n%10);
}
int pads(char* st){
	if(*st!='\0'){
		return 1+pads(st+1);
	}
	return 0;
}
int fib(int a){
	if(a<=2){
		return 1;
	}
		return fib(a-1)+fib(a-2);
}
int fic(int n){
	int a=1;
	int b=1;
	int c=1;
	while(n>2){
		c=a+b;
		a=b;
		b=c;
		n--;
	}
	return c;
}
int main(){
//	int a=0;
//	int b=0;
//	scanf("%d%d",&a,&b);
//	int c=max(a,b);
//	printf("%d\n",c);
//	printf("a=%d b=%d\n",a,b);
//	swap(&a,&b);
//	printf("a=%d b=%d\n",a,b);
//	for(int i=100;i<=200;i++){
//		if(shu(i)==1){
//			printf("%d ",i);
//		}
//	}
//	int a=0;
//	scanf("%d",&a);
//	nian(a);
//	int arr[]={1,34,56,88,90,123,456,567,890};
//	int k;
//	int sz=sizeof(arr)/sizeof(arr[0]);
//	for(int i=0;i<=sz-1;i++){
//		printf("%d ",arr[i]);
//	}
//	printf("\n请输入你想找的数字\n");
//	scanf("%d",&k);
//	int ret=BN(arr,k,sz);
//	if(ret==0){
//		printf("找不到\n");
//	}else{
//		printf("找到了，下标是%d\n",ret);
//	}
//	int num=0;
//	scanf("%d",&num);
//	plus(num);
//	int a=0;
//	scanf("%d",&a);
//	plas(a);
//	char arr[]="我是你爹";
//	int s=pads(arr);
//	printf("%d",s);
//	int a=0;
//	scanf("%d",&a);
//	int ret=fic(a);
//	printf("ret=%d\n",ret);
	return 0;
}
