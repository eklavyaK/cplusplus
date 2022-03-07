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
		int n,r; cin>>n>>r; int a[n];
		for(int i = 0; i<n; i++)cin>>a[i];
		sort(a,a+n); vector<int> v;makeset(v,a,n);
		int count = 1;long long sum = 0;n=v.size();
		for(int i = n-2; i>=0; i--){
			sum+=r; if(sum>=v[i])break; else count++;
		}
		cout<<count<<endl;
	}
	return 0;
}