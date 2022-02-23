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
		int n; cin>>n; int a[n],count=0;
		for(int i = 0; i<n; i++)cin>>a[i];
		int l = 0,r=n-1,track=0,move=0;int bob=0,alice=0;
		while(l<=r){
			if(track){
				int sum=0;
				while(move>=sum&&l<=r){
					sum+=a[r--];
				}
				count++;move=sum;
				bob+=sum;track=!track;
			}
			else{
				int sum=0;
				while(move>=sum&&l<=r){
					sum+=a[l++];
				}
				count++;move=sum;
				alice+=sum;track=!track;
			}
		}
		cout<<count<<" "<<alice<<" "<<bob<<endl;
	}
	return 0;
}