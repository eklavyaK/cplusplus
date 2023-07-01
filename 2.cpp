#include <bits/stdc++.h>
using namespace std;
using V=vector<int>;
const int MOD=1e9+7;int main(){int n,k; cin>> n>>k;V a(n);vector<int> o;for(int i=0;i<n;i++){cin>>a[i];if(a[i])o.push_back(i);}int m =o.size();vector<V> dp(m+1, V(k+1,0));dp[0][0]=1;for(int i=1;i<=n;i++)for(int j=m;j>=1;j--){int D=abs((i-1)-o[j-1]); for(int l=k;l>=D;l--){dp[j][l] = (dp[j][l]+dp[j-1][l-D])%MOD;}}int S =0;for(int i=0;i<=k;i++)if((i%2)==(k%2))S=(S+dp[m][i])%MOD,cout<<dp[m][i]<<' ';cout<<S<<endl;} 
