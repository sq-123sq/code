#include <stdio.h>
void print(int (*p)[3],int c,int r){
	for(int i=0;i<c;i++){
		for(int j=0;j<r;j++){
			printf("%d ",*(*(p+i)+j));
		}
		printf("\n");
	}
}
int main(){
//	int arr[3]={1,2,3};
//	int (*p)[3]=&arr;
//	for(int i=0;i<3;i++){
//		printf("%d ",*((*p)+i));
//	}
	int arr[2][3]={1,2,3,4,5,65};
	print(arr,2,3);
	return 0;
}
