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
    int arr[n];
    vector<pair<int,int>> w;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i] = n-arr[i];
        w.push_back({arr[i],i});
    }
    set<int> st;
    st.insert(-1);
    st.insert(n);
    int cnt[n+1]{};
    cnt[n] = n;
    sort(w.begin(),w.end());
    for(int i=0;i<=n;i++){
        int id = lower_bound(w.begin(),w.end(),make_pair(i,0ll))-w.begin();
        vector<int> v;
        while(id<n && w[id].F==i){
            v.push_back(w[id].S);
            st.insert(w[id].S);
            id++;
        }
        int k = v.size();
        for(int j=0;j<k;j++){
            auto it = st.lower_bound(v[j]);
            it--;
            int s = *it;
            cnt[v[j]-s-1]+=(n-i);
            it++;it++;
            int l = v[j];
            while(j+1<k && *it==v[j+1]){
                j++;
                cnt[v[j]-l-1]+=(n-i);
                l = v[j];
                it++;
            }
            cnt[*it-l-1]+=(n-i);
            cnt[*it-s-1]-=(n-i);
        }
    }
    int m; cin>>m;
    int curr = m, ans = 0;
    debugarr(cnt,n+1);
    for(int i=n;i>=1 && curr>0;i--){
        if(cnt[i]*i>=curr){
            ans+=ceil((ld)curr/i);
            curr = 0;
        }
        else{
            ans+=cnt[i];
            curr-=cnt[i]*i;
        }
    }
    cout<<m-ans<<endl;
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cerr.tie(0)->sync_with_stdio(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}