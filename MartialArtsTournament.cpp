#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debug(c)
#define debugarr(a,n)
#define debugvar(c)
#endif



set<int> shifter;

void code(int TC){
    int n; cin>>n;
    int cnt[n+1]{};
    for(int i=0;i<n;i++){
        int k; cin>>k;
        cnt[k]++;
    }
    for(int i=1;i<=n;i++) cnt[i] += cnt[i-1];
    int ans = (1<<20);
    for(int i=1;i<=n;i++){
        if(!cnt[i]) continue;
        int div1 = *shifter.lower_bound(cnt[i])-cnt[i];
        for(int j=0;j<20;j++){
            int id = upper_bound(cnt+i,cnt+n+1,(1<<j)+cnt[i])-cnt-1;
            int div2 = (1<<j) - cnt[id] + cnt[i], div3 = *shifter.lower_bound(n-cnt[id]) + cnt[id] - n;
            ans = min(ans, div2+div1+div3);
        }
    }
    cout<<ans<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    for(int i=0;i<20;i++) shifter.insert((1<<i));
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}