#include<stdio.h>

void func(int a[],int len,int now){
    int i;
    if(len == now){
        for(i = 0;i<len;i++){
            printf("%d",a[i]);
        }
        puts("");
        return;
    }
    
    for(i=now;i<len;i++){
        int t = a[now];
        a[now] = a[i];
        a[i] = t;
        func(a,len,now+1);
        t = a[now];
        a[now] = a[i];
        a[i] = t;
    }
}

int main(void){
    int a[3] = {1,2,3};
    func(a,3,0);
    return 0;
}