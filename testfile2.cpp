#include<bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;cin>>tc;
  while(tc-->0)
  {
    int n,m; cin>>n>>m; int res[n*m];
    for(int i = 0; i<n*m; i++){res[i]=max(i/m,n-1-i/m)+max(i%m,m-1-i%m);cout<<res[i]<<" ";}
  }
  return 0;
}