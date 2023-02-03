#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int k; cin>>k;
    string s; cin>>s;
    int cnt[(int)pow(2,k)]{};
    vector<vector<int>> v(k+1);
    v[0] = vector<int>(pow(2,k),1);
    int l = 0, idx[k+1][(int)pow(2,k)];
    vector<pair<int,int>> sdx(s.size());
    for(int i=1;i<=k;i++){
        for(int j=0;j<pow(2,k-i+1);j+=2){
            if(s[l]=='?')v[i].push_back(v[i-1][j]+v[i-1][j+1]);
            else if(s[l]=='1')v[i].push_back(v[i-1][j+1]);
            else v[i].push_back(v[i-1][j]);
            idx[i][v[i].size()-1] = l;
            sdx[l] = {i,v[i].size()-1};
            l++;
        }
    }
    int q; cin>>q;
    while(q--){
        int u; char c; 
        cin>>u>>c;
        u--; s[u] = c;
        int x = sdx[u].F, y = sdx[u].S;
        while(true){
            if(s[idx[x][y]]=='?')v[x][y]=v[x-1][2*y]+v[x-1][2*y+1];
            else if(s[idx[x][y]]=='1')v[x][y]=v[x-1][2*y+1];
            else v[x][y] = v[x-1][2*y];
            x++;y/=2;
            if(x==k+1)break;
        }
        cout<<v[k][0]<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}