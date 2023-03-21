#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
int f[200005];
void code(){
    int n; cin>>n;
    vector<vector<int>> v(n);
    map<int,vector<int>> m;
    for(int i=0;i<n;i++){
        int k,c;
        cin>>k>>c;
        v[i].push_back(c);
        for(int j=1;j<k;j++){
            cin>>c;
            if(v[i].back()<c)v[i].push_back(c);
        }
        m[v[i].back()].push_back(i);
    }
    m[0];
    int ans = 0;
    for(auto i : m){
        f[i.F] = ans;
        for(auto r : i.S){
            int k = v[r].size();
            for(int j=0;j<k;j++){
                auto it = m.lower_bound(v[r][j]);
                it--;
                f[i.F] = max(f[i.F],f[it->F]+k-j);
            }
        }
        ans = f[i.F];
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}