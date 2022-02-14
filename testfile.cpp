#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int n,q; cin>>n>>q;
    vector<vector<pair<int,int>>> val(n+1);
    for(int i = 1; i<=n; i++) val[i].emplace_back(0,1);
    vector<pair<int,int>> c(q+1);
    for(int j = 1; j<=q; j++) 
    {
        string s; cin>>s;
        if(s[0]=='Q') {
            int k,l,r; cin>>k; long long sum=0; 
            for(int m = 0; m<val[k].size()-1; m++) {
                l = val[k][m].first+1; r=val[k][m+1].first;
                int color = val[k][m].second;
                for(int i = l; i<r; i++){
                    if(c[i].first==color) sum+=c[i].second;
                }
            }
            l = val[k][val[k].size()-1].first+1;
            r = val[k][val[k].size()-1].second;
            for(int i = l; i<j; i++){
                if(c[i].first==r) sum+=c[i].second;
            } 
            cout<<sum<<endl;
        }
        else if(s[0]=='A'){
            int t,x; cin>>t>>x;
            c[j]=make_pair(t,x);
        }
        else {
            int l,r,t; cin>>l>>r>>t;
            for(int i = l; i<=r; i++) val[i].emplace_back(make_pair(j,t));
        }
    }

    return 0;
}