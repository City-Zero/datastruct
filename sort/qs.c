#include<stdio.h>

int qs_pass(int list[],int s,int e){
    int flag = list[s];
    while(s<e){
        while(list[e]>flag && e>s) e--;
        if(s<e){
            list[s] = list[e];
            s++;
        }
        while(list[s]<flag && e>s) s++;
        if(s<e){
            list[e] = list[s];
            e--;
        }
    }
    list[s] = flag;
    return s;
}

void qs(int list[],int s,int e){
    if(s<e){
        int pass = qs_pass(list,s,e);
        qs(list,s,pass-1);
        qs(list,pass+1,e);
    }
}

int main(void){
    int list[10];
    int i = 0;
    for(i = 0;i<10;i++){
        scanf("%d",&list[i]);
    }
    qs(list,0,9);
    for(i = 0;i<10;i++){
        printf("%d ",list[i]);
    }
}