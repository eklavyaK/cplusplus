#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
int n;
bool check(int x,vector<int> a){
    int st = 0, en = n-1;
    while(x!=0 && st<=en){
        if(st<n && a[st]<=x){
            st++; a[en]+=x;
            x--; en--;
        }
        else st++;
    }
    return x==0;
};

int main(){
    int t; cin>>t;
    while(t--){
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        int l = 0, r = n;
        sort(arr.begin(),arr.end(),greater<int>());
        while(l<=r){
            int mid = (l+r)>>1;
            if(check(mid,arr))l = mid+1;
            else r = mid-1;
        }
        cout<<max(0,l-1)<<endl;
    }
}