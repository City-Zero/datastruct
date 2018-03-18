#include<stdio.h>
#define swap(a,b) (a^=b,b^=a,a^=b)
#define LENGTH(array) ((sizeof(array)) / (sizeof(array[0])))

void maxheap_down(int *a,int index,int end){
    int c = index;
    int l = 2*c+1; //left Children
    for(;l<=end;c=l,l=2*l+1){
        if(l<end && a[l+1] > a[l])
            l++;
        if(a[c]>=a[l])
            break;
        else{
            swap(a[c],a[l]);
        }
    }
}

void minheap_down(int *a,int index,int end){
    int c = index;
    int l = c*2+1;
    for(;l<=end;c = l,l = l*2+1){
        if(l<end && a[l+1] < a[l])
            l++;
        if(a[l] >= a[c])
            break;
        else
            swap(a[l],a[c]);

    }
}

void heap_sort_asc(int *a,int len){
    int i;
    for(i = len/2-1;i>=0;i--){
        maxheap_down(a,i,len-1);
    }

    for(i = len-1;i>0;i--){
        swap(a[0],a[i]);
        maxheap_down(a,0,i-1);
    }
}

void heap_sort_desc(int *a,int len){
    int i;
    for( i = len/2-1;i>=0;i--){
        minheap_down(a,i,len-1);
    }
    for(i = len-1;i>0;i--){
        swap(a[0],a[i]);
        minheap_down(a,0,i-1);
    }
}

int main(void){
    int a[] = {2,47,38,19,16,89,89,45,18,29,16,78,8,57,38,97,56,98,18,20};
    int len = LENGTH(a);
    int i;
    for(i = 0;i<len;i++){
        printf("%d ",a[i]);
    }
    puts("");
    heap_sort_desc(a,len);
    for(i = 0;i<len;i++){
        printf("%d ",a[i]);
    }
    puts("");
    return 0;
}