#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
const int mod = 998244353;
int exp(int a, int n){
    int res = 1;
    while(n>0){
        if(n&1) res = (res*a)%mod;
        a = (a*a)%mod;
        n>>=1;
    }
    return res;
}

void code(){
    int n; cin>>n;
    vector<vector<int>> graph(n+1);
    vector<vector<int>> arr(2,vector<int>(n+1));
    for(int i=1;i<=n;i++)cin>>arr[0][i];
    for(int i=1;i<=n;i++)cin>>arr[1][i];
    for(int i=1;i<=n;i++){
        graph[arr[0][i]].push_back(arr[1][i]);
        graph[arr[1][i]].push_back(arr[0][i]);
    }
    vector<int> done(n+1);
    int c = 0, a = 0, b = 0, d = 0;
    bool f = false;
    function<void(int)> dfs = [&](int node){
        done[node] = 1; d++;
        for(auto i : graph[node]){
            c++;
            if(!done[i]) dfs(i);
            else if(i==node) f = true;
        }
    };
    for(int i=1;i<=n;i++){
        if(done[i])continue;
        f = false;
        dfs(i);
        if(d*2!=c){
            cout<<0<<endl;
            return;
        }
        b+=f,a+=!f;
    }
    cout<<exp(2,a)*exp(n,b)%mod<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}