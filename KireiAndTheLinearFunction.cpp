#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    string a; cin>>a;
    int n = a.size();
    vector<int> s(n+1);
    for(int i=1;i<=n;i++)s[i] = a[i-1]-'0';
    vector<vector<int>> rem(9);
    int w,q; cin>>w>>q;
    int sum[n+1]{};
    for(int i=1;i<=n;i++){
        sum[i] = s[i]+sum[i-1];
        if(i>=w)rem[(sum[i]-sum[i-w])%9].push_back(i-w+1);
    }
    vector<vector<pair<int,int>>> m(9,vector<pair<int,int>>(9));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            for(int k=0;k<9;k++){
                int z = (i*j+k)%9;
                int l = 0, r = 0;
                if(j==k){
                    if(rem[k].size()<=1)continue;
                    l = rem[k][0], r = rem[k][1];
                }
                else if(rem[j].size() && rem[k].size()) l = rem[j][0], r = rem[k][0];
                else continue;
                if(m[i][z].F) m[i][z] = min(m[i][z],{l,r});
                else m[i][z] = {l,r};
            }
        }
    }
    while(q--){
        int l,r,k; cin>>l>>r>>k;
        int c = (sum[r]-sum[l-1])%9;
        !m[c][k].F?cout<<"-1 -1"<<endl:cout<<m[c][k].F<<' '<<m[c][k].S<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}