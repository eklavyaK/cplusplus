#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,k; cin>>n>>k;
    k = n*(n+1)/2-k;
    int ans[n];
    if(k==0){
        for(int i=0;i<n;i++){
            cout<<1<<" ";
        }
        cout<<endl;
        return;
    }
    int idx = 0, till = 0;
    for(int i=n;i>0;i--){
        if(k>i)k-=i,idx++;
        else{
            till = k; break;
        }
    }
    for(int i=idx+1;i<=idx+till-1;i++){
        ans[i] = 1;
    }
    ans[idx] = -till;
    if(idx+till<n)ans[idx+till] = -ans[idx]+till;
    for(int i=idx+till+1;i<n;i++){
        ans[i] = 1;
    }
    for(int i=0;i<idx;i++){
        ans[i] = -1000;
    }
    for(auto i : ans) cout<<i<<' ';cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}