#include<iostream>
using namespace std;
/*
Quick sort:
    a pivot is chosen and all the elements greater than the pivot is sent to it's right and all the elements less than the pivot is sent
    to it's left. Then again right half and left are separately quick sorted recursively. Generally last element is chosen as pivot, but
    any other element can be chosen as pivot as well. This program chooses the last element of each partition as pivot

Time Complexity:
    the expected time complexity is O(nlogn) but in worst case the time complexity can be O(n^2) where the array is already sorted and
    pivot always comes as the last element
*/
int n, a[200000];
int arrange(int l, int r){
    int f = l;
    for(int i=l;i<r;i++){
        if(a[i]<a[r]){
            int temp=a[f];
            a[f]=a[i];f++;
            a[i]=temp;
        }
    }
    int temp=a[f]; 
    a[f]=a[r];a[r]=temp;
    return f;
}
void quick_sort(int l, int r){
    if(l>=r)return;
    int p = arrange(l,r);
    quick_sort(l,p-1);
    quick_sort(p+1,r);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quick_sort(0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
    return 0;
}