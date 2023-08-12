#include<bits/stdc++.h>
#define endl "\n"
#define ff first
#define ss second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debugarr(a,n) 42
#define debug(...) 42
#endif

void knapsack(vector<int> & v){
     int n = v.size(), sum = 0;
     for(int i = 0; i < n; i++) sum += v[i];
     vector<int> act, cnt(sum + 1), can(sum + 1);
     for(int i = 0; i < n; i++) cnt[v[i]]++;
     for(int i = 1; i <= sum; i++){
          if(!cnt[i]) continue;
          int cur = 1;
          while(cur < cnt[i]) act.push_back(cur * i), cnt[i] -= cur, cur <<= 1;
          if(cnt[i]) act.push_back(cnt[i] * i);
     }
     can[0] = 1;
     for(auto u : act){
          for(int i = sum; i >= u; i--) if(can[i - u]) can[i] = 1;
     }
	vector<int> ans;
     for(int i = 1; i <= sum; i++) if(can[i]) can[0] = can[0] + 1, ans.push_back(i);
	cout << can[0] - 1 << endl;
	for(auto i : ans) cout << i << " ";
     cout << endl;
}


void code(int TC){
     int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	knapsack(v);
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}