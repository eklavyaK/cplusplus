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

const int N = 3e5+5;

vector<set<int>> occ(N);

void code(int TC){
    set<int> st;
    int n,m; 
    cin>>n>>m;
    int arr[n];
    set<pair<int,int>> bad;
    for(int i=0;i<n;i++) cin>>arr[i],bad.insert({arr[i],arr[i]});
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        bad.insert({min(u,v),max(u,v)});
    }
    sort(arr,arr+n);
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int c = i;
        while(i+1<n && arr[i+1]==arr[i]) i++;
        v.push_back({i-c+1,arr[i]});
    }
    sort(v.begin(),v.end());
    vector<vector<int>> vec;
    vector<int> cnt;
    int ans = 0;
    for(auto [c,a] : v){
        for(int j=0;j<cnt.size();j++){
            int k = vec[j].size();
            for(int i=k-1;i>=0;i--){
                if(!bad.count({min(vec[j][i],a),max(a,vec[j][i])})){
                    ans = max(ans,(vec[j][i]+a)*(c+cnt[j])); break;
                }
            }
        }
        if(cnt.empty() || cnt.back()!=c){
            cnt.push_back(c);
            vec.push_back({a});
        }
        else vec.back().push_back(a);
    }
    cout<<ans<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}