#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int tc;cin>>tc;
	while(tc-->0)
	{
		int n,m,k; cin>>n>>m; vector<pair<int,int>> v(m); map<int,int> map;int count = 1;
		for(int i = 0; i<m; i++){cin>>v[i].second>>v[i].first;map[v[i].second]=count++;}
		sort(v.begin(),v.end()); int a[2*n];
		long long sum = 0l;
		for(int i = 0; i<2*n; i++){
			a[i]=v[i].second;
			sum+=v[i].first;
		}
		sort(a,a+2*n);cout<<endl<<sum<<endl;
		for(int i = 0; i<n; i++){
			cout<<map[a[i]]<<" "<<map[a[2*n-1-i]]<<endl;;
		}
	}
	return 0;
}