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
		int n; cin>>n; int a[n], in[n+1]; vector<int> v;
		for(int i = 0; i<n; i++){cin>>a[i];in[a[i]]=i+1;}
		int l=in[1],r=in[1]; v.emplace_back(1);
		for(int i = 2; i<=n; i++){
			if(in[i]<l){
				l=in[i];
			}
			else if(in[i]>r){
				r=in[i];
			}
			if(r-l+1==i){
				v.emplace_back(i);
			}
		}
		int track=0;
		for(int i = 1; i<=n; i++){
			if(track<v.size() && v[track]==i){track++;cout<<1;}
			else cout<<0;
		}
		cout<<endl;
	}
	return 0;
}