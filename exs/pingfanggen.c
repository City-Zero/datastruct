#include<stdio.h>

double func(double n,double left,double right){
    if(n==1){
        return 1.0;
    }
    if(right-left < 0.01){
        //printf("%.2lf~%.2lf",left,right);
        return left;
    }
    double mid = (left+right)/2.0;
    double res;
    
    double test = mid * mid;
    //printf("%lf,%lf,%lf,%lf,%lf\n",left,right,mid,n,test);
    if(test > n){
        res = func(n,left,mid);
    }else if(test < n){
        res = func(n,mid,right);
    }else{
        return mid;
    }
    return res;
}

int main(void){
    double n;
    double right,left;
    scanf("%lf",&n);
    if(n<1){
        right = 1;
        left = n;
    }else{
        right = n;
        left = 0;
    }
    double res = func(n,left,right);
    if(res * res == n){
        printf("%.2lf",res);
    }else{
        printf("%.2lf~%.2lf",res,res+0.01);
    }

}