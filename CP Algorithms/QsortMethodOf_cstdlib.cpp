#include<iostream>
#include<cstdlib>
using namespace std;
int func(const void *a, const void *b)
{
    int l = *(const int*)a;
    int r = *(const int*)b;
    return l-r;
}
int main()
{
    int a[10];
    for(int i = 0; i<10; i++) a[i] = rand()%100;
    for(int i = 0; i<10; i++) cout<<a[i]<<" ";cout<<endl;
    qsort(a, sizeof(a)/sizeof(a[0]), sizeof(int),func);
    for(int i = 0; i<10; i++) cout<<a[i]<<" ";
    return 0;
}