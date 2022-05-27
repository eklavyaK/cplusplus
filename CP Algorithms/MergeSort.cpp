#include<iostream>
using namespace std;      ///****///Merge Sort has Time Complexity of just O(nlogn)///*****///
/*
Merge sort:
    the array elements are divided into subarrays till the point where one element is left in the subarray. Then two subarrays are sorted using two pointer method and then merged into one. This is followed till the whole array is sorted.
*/
int a[200000],n;
void merge(int l, int r){
    int z = l;
    int c[r-l+1];
    int x = (l+r)/2;
    int y = x+1,i=0;
    while(true){
        if(l<=x && y<=r){              //two pointer method to push elements from two sorted subarrays to form single sorted array
            if(a[l]<a[y])
            {c[i]=a[l];i++;l++;}
            else 
            {c[i]=a[y];i++;y++;}
        }
        else if(l<=x){
            while(l<=x)
            {c[i]=a[l];i++;l++;}
            break;
        }
        else if(y<=r){
            while(y<=r)
            {c[i]=a[y];i++;y++;}
            break;
        }
        else break;
    }
    for(i=z;i<=r;i++)a[i]=c[i-z];
}
void merge_sort(int l, int r){
    if(l==r)return;
    int mid = (l+r)/2;
    merge_sort(l,mid);                   //BST is used to divide the array into subarrays
    merge_sort(mid+1,r);
    merge(l,r);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    merge_sort(0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
    return 0;
}