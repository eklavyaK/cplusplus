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


void code(int TC){
    int n; cin>>n;
    vector<pair<int,int>> p(n);
    for(int i=0;i<n;i++) cin>>p[i].F>>p[i].S, p[i].F--,p[i].S--;
    function<int(int)> compute = [&](int base){
        vector<pair<int,int>> curr;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(p[i].S-p[i].F+1>=base){
                cnt++;  
                continue;
            }
            else if(p[i].S%base<p[i].F%base) curr.push_back({0,p[i].S%base}), curr.push_back({p[i].F%base,base-1});
            else curr.push_back({p[i].F%base,p[i].S%base});
        }
        sort(curr.begin(),curr.end());
        int rem = curr.size(), mx = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<rem;i++){
            while(!pq.empty() && pq.top().F<curr[i].F) pq.pop();
            pq.push({curr[i].S,i}); 
            while(i+1<rem && curr[i+1].F==curr[i].F){
                i++; pq.push({curr[i].S,i});
            }
            mx = max(mx,(int)pq.size());
        }
        return mx+cnt;
    };
    int dp[30];
    for(int i=0;i<30;i++) dp[i] = compute(1ll<<i);
    debugarr(dp,30);
    int q; cin>>q;
    while(q--){
        int w; cin>>w;
        for(int i=0;i<30;i++){
            if((1ll<<i)&w){
                cout<<dp[i]<<endl;
                break;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}