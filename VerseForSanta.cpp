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
		int n,s,sum = 0; cin>>n>>s; int a[n],count=0;
		for(int i = 0; i<n; i++) cin>>a[i];
		for(int i = 0; i<n; i++){
			if(sum+a[i]<=s){
				sum+=a[i];
			}
			else{
				if(sum==0){
					count=1;
				}
				else{
					int k = 0, index = 0;
					for(int j = 0; j<=i; j++)if(a[j]>k){k=a[j];index = j;}
					count=index+1;
				}
				break;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}