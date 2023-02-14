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
    int done[n+1]{};
    vector<int> ans(n);
    if(k==1){
        for(int i=1;i<=n;i++)cout<<i<<' ';
        cout<<endl;
        return;
    }
    int idx = 0;
    int r = n, l = 1;
    while(true){
        for(int i=0;i<k-1;i++){
            ans[idx++] = r--;
            if(idx==n)goto end;
        }
        ans[idx++] = l++;
        if(idx==n)goto end;
    }
    end:
    for(auto i : ans) cout<<i<<' ';
    cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}