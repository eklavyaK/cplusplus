#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,k,x; cin>>n>>k>>x;
    int xr = 0;
    set<int> st;
    for(int i=1;i<=n;i++) xr^=i, st.insert(i);
    if(((k&1) && xr!=x) || (k%2==0 && xr)){
        cout<<"NO"<<endl;
        return;
    }
    vector<int> remains;
    vector<vector<int>> ans(k-1);
    function<bool(int)> extract = [&](int i){
        while(!st.empty()){
            int k = *st.begin();
            st.erase(k);
            if(k==x){
                ans[i].push_back(k);
                return true;
            }
            if(st.count(k^x)){
                st.erase(k^x);
                ans[i] = {k,k^x};
                return true;
            }
            else remains.push_back(k);
        }
        return false;
    };
    for(int i=0;i<k-1;i++){
        if(!extract(i)){
            cout<<"NO"<<endl;
            return;
        }
    }
    for(auto i : st) remains.push_back(i);
    cout<<"YES\n"<<remains.size()<<endl;
    for(auto i : remains) cout<<i<<" ";
    cout<<endl;
    for(auto i : ans){
        cout<<i.size()<<endl;
        for(auto j : i) cout<<j<<" ";
        cout<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}