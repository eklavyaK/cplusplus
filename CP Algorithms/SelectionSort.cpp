#include<iostream>

using namespace std;
/*
Selection sort:
    the array is transversed completely and minimum element is found and swapped with the element at the beginning. Then next iteration
    starts from second element and again minimum element is found and swapped with element at position 2. This continues till n-1 th 
    element.

Time Complexity:
    Obviously the time complexity is O(n^2)
*/
int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        int in = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[in]){
                in = j;
            }
        }
        int temp=a[i];
        a[i]=a[in];
        a[in]=temp;
    }
    for(auto i : a)
    cout<<i<<' ';cout<<endl;
    return 0;
}