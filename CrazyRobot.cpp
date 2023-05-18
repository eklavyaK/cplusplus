#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;


vector<pair<int,int>> a({{-1,0},{1,0},{0,-1},{0,1}});
void code(){
    int n,m; cin>>n>>m; string s[n];
    for(int i=0;i<n;i++) cin>>s[i];
    function<void(int,int)> dfs = [&](int i, int j){
        if(i<0 || i>=n || j<0 || j>=m ||s[i][j]!='.') return;
        int k = -1, cnt = 0;
        for(int l=0;l<4;l++){
            if(i+a[l].F>=0 && i+a[l].F<n && j+a[l].S>=0 && j+a[l].S<m && s[i+a[l].F][j+a[l].S]=='.'){
                k = l; cnt++;
            }
        }
        if(cnt<=1){
            s[i][j] = '+';
            if(cnt==1)dfs(i+a[k].F,j+a[k].S);
        }
    };
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='L'){
                for(int l=0;l<4;l++) dfs(i+a[l].F,j+a[l].S);
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<s[i]<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}