#include <bits/stdc++.h>
#define removezeros(s) s.erase(0, s.find("1") != -1 ? s.find("1") : s.length() - 1)
#define binary(n, k) bitset<k>(n).to_string()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	while (tc-- > 0)
	{
		long long n,x,k,count=0; cin>>n>>x; map<long long,long long> m;
		for(int i = 0; i<n; i++){cin>>k; m[k]++;}
		if(x==1){
			for(auto i : m){
				count+=i.second%2;
			}
		}
		else{
			for(auto i : m){
				if(m[i.first*x]){
					if(i.second<m[i.first*x]){
						m[i.first*x]-=i.second;
					}
					else{
						count+=(i.second-m[i.first*x]);
						m[i.first*x]=0;
					}
				}
				else count+=i.second;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}