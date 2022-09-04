#define PROGRAM int main(){rapid_iostream;int tc=1;cin>>tc;while(tc-->0){codeforce();}return 0;}
#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream cin.tie(0)->sync_with_stdio(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
#define println(n) cout<<n<<'\n'
#define MAIN void codeforce();
#define Y() cout<<"YES"<<endl
#define print(n) cout<<n<<' '
#define N() cout<<"NO"<<endl
#define pii pair<int,int>
#define mod1 1000000007ll
#define pli pair<ll,int>
#define pil pair<int,ll>
#define mod2 998244353ll
#include<bits/stdc++.h>
#define pll pair<ll,ll>
typedef long double ld;
typedef long long ll;
#define mp make_pair
using namespace std;
#define endl '\n'
#define S second
#define F first
Compare(pii)
/***************************************************/ MAIN PROGRAM /*******************************************************/



void codeforce(){
    int n,m; cin>>n>>m;
    vector<vector<int>> dp(n,vector<int>(m));
    string s[n]; int cnt = 0;
    for(int i=0;i<n;i++)cin>>s[i];
    function<bool(int,int)> dfs = [&](int i, int j){
        dp[i][j] = 1; cnt++;
        if(i-1>=0 && !dp[i-1][j] && s[i-1][j]=='*'){
            dfs(i-1,j);
        }
        if(j-1>=0 && !dp[i][j-1] && s[i][j-1]=='*'){
            dfs(i,j-1);
        }
        if(i+1<n && !dp[i+1][j] && s[i+1][j]=='*'){
            dfs(i+1,j);
        }
        if(j+1<m && !dp[i][j+1] && s[i][j+1]=='*'){
            dfs(i,j+1);
        }
        if(i-1>=0 && j+1<m && !dp[i-1][j+1] && s[i-1][j+1]=='*'){
            if(cnt==2) dfs(i-1,j+1);
            else {cnt = 4; return false;}
        }
        if(i-1>=0 && j-1>=0 && !dp[i-1][j-1] && s[i-1][j-1]=='*'){
            cnt = 4; return false;
        }
        if(i+1<n && j+1<m && !dp[i+1][j+1] && s[i+1][j+1]=='*'){
            cnt = 4; return false;
        }
        if(i+1<n && j-1>=0 && !dp[i+1][j-1] && s[i+1][j-1]=='*'){
            cnt = 4; return false;
        }
        return true;
    };
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='*' && !dp[i][j]){
                cnt = 0; bool res = dfs(i,j);
                if((!res) || cnt!=3){
                    N(); return;
                }
                else if(i+2<n && s[i+1][j]=='*' && s[i+2][j]=='*'){
                    N(); return;
                }
                else if(j+2<m && s[i][j+1]=='*' && s[i][j+2]=='*'){
                    N(); return;
                }
            }
        }
    }
    Y();
}