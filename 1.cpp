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
    for(int i=0;i<n;i++){
        int l = -1, r = -1;
        for(int j=0;j<m;j++){
            if(s[i][j]=='W')continue;
            if(l==-1) l = j;
            r = j;
        }
        for(int j=0;j<m;j++)ans[i][j] = max(abs(i-l),abs(i-r));
    }
    auto left = ans, right = ans;
    for(int i=0;i<n;i++){
        int mx = left[i][0];
        for(int j=1;j<m;j++){
            left[i][j] = max(left[i][j],mx+j);
            mx = max(mx,left[i][j] - j);
        }
        mx = right[i][m-1]+m-1;
        for(int j=m-2;j>=0;j--){
            right[i][j] = max(right[i][j],mx-j);
            mx = max(mx,left[i][j]+j);
        }
    }
    int res = 1e9;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) res = min(res,max(left[i][j],right[i][j]));
    }
    cout<<res<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}