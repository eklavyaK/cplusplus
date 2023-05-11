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
    string s[2]; cin>>s[0]>>s[1];
    int f[n+1][2];
    memset(f,0,sizeof(f));
    bool k = true;
    for(int i=1;i<=n;i++){
        if(k){
            if(s[1][i-1]=='*'||s[0][i-1]=='*'){
                k = false;
                f[i][1] = (s[0][i-1]=='*');
                f[i][0] = (s[1][i-1]=='*');
            }
            continue;
        }
        if(s[0][i-1]=='*') f[i][1] = min(f[i-1][1],f[i-1][0])+2;
        else f[i][1] = f[i-1][1]+1;
        if(s[1][i-1]=='*') f[i][0] = min(f[i-1][0],f[i-1][1])+2;
        else f[i][0] = f[i-1][0]+1;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(s[0][i]=='*'||s[1][i]=='*') ans = min(f[i+1][0],f[i+1][1]);
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}