#include<stdio.h>
#define swap(a,b) (a^=b,b^=a,a^=b)
#define len(a) (sizeof(a)/sizeof(a[0]))

int main(void){
    char s[] = "123 45 6";
    puts(s);
    int t,i = 0 ,j = len(s)-2;//sizeof求的值包含了'\0'，所以是-2不是-1
    printf("%d",j);
    while(i<j){
        swap(s[i],s[j]);
        i++;
        j--;
    }
    puts(s);
    i = 0;
    while(i<len(s)-1){
        j = i;
        while(1){
            if(s[j+1] == '\0' || s[j+1] == ' ')
                break;
            else
                j++;
        }
        t = j+2;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        i = t;
    }
    puts(s);


}