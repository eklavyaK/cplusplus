#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;

void code(){
    ll n; cin>>n;
    vector<ll> ans(n);
    ll s = n*2-2;
    ll diff = s*s-n*n;
    ll extra = diff/n;
    if(diff%n==1){
        for(int i=0;i<n;i++){
            ans[i] = extra;
        }
        ans[1]++;
    }
    else if(diff%n){
        int last = diff%n;
        for(int i=0;i<n;i++){
            if(i<last-1)ans[i] = extra+1;
            else ans[i] = extra;
        }
        ans[n-1]++;
    }
    else{
        for(int i=0;i<n;i++){
            ans[i] += extra;
        }
    }
    int cnt = 1;
    for(auto i : ans){cout<<i+cnt<<' ';cnt+=2;}
    cout<<endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}