#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int tc;cin>>tc;
	while(tc-->0)
	{
		int n,k; cin>>n>>k; int a[n], subarray_sum[n+1]={0};
		for(int i = 0; i<n; i++)cin>>a[i];
		for(int j = 0; j<=n; j++){
			int temp = 0;
			for(int i = 0; i<j; i++) temp+=a[i];
			int m = temp;
			for(int i = 1; i<=n-j; i++) {temp=temp-a[i-1]+a[i+j-1];if(temp>m)m=temp;}
			subarray_sum[j]=m;
		}
		for(int i = 0; i<n+1; i++){subarray_sum[i]=subarray_sum[i]+i*k;}
		int m=0;
		for(int i = 0; i<=n; i++){
			int ma=0;if(m<subarray_sum[i])m=subarray_sum[i];
			for(int j = i+1; j<n+1; j++){
				if(subarray_sum[j]-(j-i)*k>ma)ma=subarray_sum[j]-(j-i)*k;
			}
			cout<<max(m,ma)<<" ";
		}
		cout<<endl;
	}
	return 0;
}