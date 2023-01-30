#include<bits/stdc++.h>
using namespace std;

int main(){
           int t;
           cin>>t;
           while(t--){
                 int n;
                 cin>>n;
                 int arr[n];
                 for(int i=0;i<n;i++){
                       cin>>arr[i];
                       
                 }
                 sort(arr,arr+n,greater<int>());
                 for(int i=1;i<n;i++){
                       if(arr[i]!=arr[0]){
                             swap(arr[i],arr[1]);
                             break;
                       }
                       else if(i==n-1){
                            cout<<"NO"<<endl;
                            goto finish;
                       }
                 }
                 cout<<"YES"<<endl;
                 for(auto i:arr)cout<<i<<' ';cout<<endl;
                 finish:;
           }
      return 0;
}