#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n; cin>>n;
    vector<vector<pair<int,int>>>color(n+1);
    vector<vector<int>> id(n+1);
    vector<int> ans(n,1e9);
    int s = 0;
    for(int i=0;i<n;i++,s++){
        int l,r,c; cin>>l>>r>>c;
        color[c].push_back({l,r});
        id[c].push_back(s);
    }
    set<pair<int,int>> space;
    space.insert({-1e9,2e9});
    function<void(int,int)> compute = [&](int i, int k){
        for(auto [l,r] : color[i]){
            auto it = space.lower_bound({l,0});
            if(it==space.end()){
                it--;
                ans[id[i][k]] = min(ans[id[i][k]],min(l-it->F,it->S-r));
            }
            else{
                if(it->F<=r)ans[id[i][k]] = 0;
                else{
                    it--;
                    if(it->S<=r)ans[id[i][k]] = 0;
                    else ans[id[i][k]] = min(ans[id[i][k]],min(l-it->F,it->S-r));
                }
            }
            k++;
        }
    };
    function<void(int)> insert_range = [&](int i){
        for(auto [l,r] : color[i]){
            auto it = space.lower_bound({l,0});
            it--;
            if(it->S>l){
                space.insert({it->F,l});
                space.insert({l,it->S});
                space.erase(*it);
            }
            while(!space.empty()){
                it = space.lower_bound({l,0});
                if(r<=it->F)break;
                else if(r>=it->S)space.erase(*it);
                else{
                    space.insert({r,it->S});
                    space.erase(*it);
                    break;
                }
            }
        }
    };
    for(int i=1;i<=n;i++){
        compute(i,0);
        insert_range(i); 
    }
    space.clear();
    space.insert({-1e9,2e9});
    for(int i=n;i>=1;i--){
        compute(i,0);
        insert_range(i);
    }
    for(auto i : ans)cout<<i<<' ';cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}