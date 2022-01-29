#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,h;cin>>n>>m>>h; int l[n],f[m],k;
    for(int i = 0; i<m; i++) cin>>f[i];
    for(int i = 0; i<n; i++) cin>>l[i];
    for(int i = 0; i<n; i++) {for(int j = 0; j<m; j++) {cin>>k;if(k) cout<<min(f[j],l[i])<<" "; else cout<<0<<" ";}cout<<endl;}
    return 0;
}