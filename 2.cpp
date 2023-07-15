#include<bits/stdc++.h>
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define vi vector<int>
#define si set<int>
#define mii map<int,int>
#define pb push_back
#define PI acos(-1)
#define pii pair<int,int>
#define endl "\n"
#define all(a) a.begin(),a.end()
#define len(s) (int)s.size()
#define F first
#define S second
const int mod=1e9+7;
int dp[20001][101][101];
int a[101];
const int add=10000;
const int L=-10000;
const int R=10000;
int f(int sum,int l,int r)
{
	//count number of non-empty subsequence of subarray [l,r] 
	//with adding=sum
	if( !(sum>=L and sum<=R))
		return 0;
	
	if(l==r)
	{

		if(sum==a[l])
			return 1;
		return 0;
	}
	if(dp[sum+add][l][r]!=-1)
		return dp[sum+add][l][r];
	int ans1=f(sum,l,r-1);
	int ans2=f(sum,l+1,r);
	int rem=0;
	if(l+1<=r-1)
		rem=f(sum,l+1,r-1);
	int ans3=0;
	if(l+1<=r-1)
		ans3=f(sum-a[l]-a[r],l+1,r-1)+(sum==(a[l]+a[r]));
	else
		ans3=(sum==(a[l]+a[r]));
	
	return dp[sum+add][l][r]=(((ans1+ans2)%mod-rem+mod)%mod+ans3)%mod;
}
void solve()
{
	int n,x;
	cin>>n>>x;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<3)
	{
		cout<<0;
		return ;
	}
	else
	{
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			a[i]-=x;
		int ans=0;
	
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				ans+=f(0,i+1,j-1);
				ans%=mod;
                if(i==1)cout<<ans<<endl;
			}
		}
		cout<<ans;
	}
}
signed main()
{
fastio
int TestCases=1;
//cin>>TestCases;
while(TestCases--)
{
solve();
cout<<endl;
}
}