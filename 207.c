#include<stdio.h>
#include<stdbool.h>
#include<math.h>
bool Narcissistic(int x){
    if(x==0) return 1;
    int p = 0, now = x, checker = 0;
    while(now>0)now/=10, p++;
    now = x;
    while(now>0) checker += pow(now%10,p),now/=10;
    return checker==x;
}
int main(){
    int x = 9474;
    bool z = Narcissistic(x);  
    if(z==1) printf("YES Narcissistic");
    else  printf("NO Narcissistic");
}