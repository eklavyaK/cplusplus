#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,m; cin>>n>>m;
    vector<string> s(n);
    for(int i=0;i<n;i++)cin>>s[i];
    vector<vector<int>> ans(n,vector<int>(m));
    vector<bool> f(m);
    for(int i=0;i<m;i++){
        int l = -1, r = -1;
        for(int j=0;j<n;j++){
            if(s[j][i]=='W')continue;
            if(l==-1) l = j;
            r = j;
        }
        if(l==-1) continue;
        f[i] = true;
        for(int j=0;j<n;j++)ans[j][i] = max(abs(j-l),abs(j-r));
    }
    auto left = ans, right = ans;
    for(int i=0;i<n;i++){
        int mx = ans[i][0];
        bool c = f[0];
        for(int j=1;j<m;j++){
            if(!c){
                c = f[j];
                mx = ans[i][j]-j;
                continue;
            }
            left[i][j] = max(ans[i][j],mx+j);
            mx = max(mx,ans[i][j]-j);
        }
        c = f[m-1];
        if(c)mx = ans[i][m-1]+m-1;
        for(int j=m-2;j>=0;j--){
            if(!c){
                c = f[j];
                mx = ans[i][j]+j;
                continue;
            }
            right[i][j] = max(ans[i][j],mx-j);
            mx = max(mx,ans[i][j]+j);
        }
    }
    int res = 1e9, l = 0, r = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(max(left[i][j],right[i][j])<res)res = max(left[i][j],right[i][j]),l = i+1, r = j+1;
        }
    }
    cout<<l<<" "<<r<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}