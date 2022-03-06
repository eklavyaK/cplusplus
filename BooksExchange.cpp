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
		int n; cin>>n; int a[n+1],b[n+1]={0};map<int,int> m;
		for(int i = 1; i<=n; i++)cin>>a[i];int track = 1;
		for(int i = 1; i<=n; i++){
			if(!b[i]){
				b[i]=track; int j = i, count=1;
				while(a[j]!=i){b[j]=track;count++;j=a[j];}
				m[track]=count;track++;
			}
		}
		for(int i = 1; i<=n; i++){
			cout<<m[b[i]]<<" ";
		}cout<<endl;
	}
	return 0;
}