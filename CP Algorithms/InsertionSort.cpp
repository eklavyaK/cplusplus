#include<iostream>

using namespace std;
/*
Insertion sort:
    The array is divided into two parts, the left part is sorted and right part is unsorted. An element is brought from sorted part
    to unsorted part one by one and placed to it's respective position in the sorted part. Initially the element at i=0 is already in
    left half. So the element from position 1 to n-1 is sequentially brought to the left half and placed at it's respective position.
*/
int main(){
    int n; cin>>n;int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=1;i<n;i++){
        int k = a[i],j=i-1;
        while(j>=0 && k<a[j]){
            a[j+1]=a[j];j--;
        }
        a[j+1]=k;
    }
    for(auto i : a)
    cout<<i<<' ';cout<<endl;
    return 0;
}