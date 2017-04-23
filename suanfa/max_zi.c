#include<stdio.h>

int lis(int arr[],int len)
{
	int longest[len];
	int i;
	for(i = 0;i<len;i++)
		longest[i] = 1;
	
	int j;
	for(j = 1;j<len;j++){
		for(i = 0;i < j;i++){
			if(arr[j] > arr[i] && longest[j] < longest[i]+1){
				longest[j] = longest[i] + 1; 
			}
		}
	}
	
	int max = 0;
	for(j = 0;j<len;j++){
		printf("longest[%d]=%d\n",j,longest[j]);
		if(longest[j] > max)
			max = longest[j];
	}
	return max;
}

int main()
{
	int arr[] = {3,4,1,5,6,7,2};
	int n = sizeof(arr)/sizeof(int);
	int ret = lis(arr,n);
	printf("max len:%d",ret);
}
