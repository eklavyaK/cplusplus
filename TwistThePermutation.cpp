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
		int n,k; cin>>n; int a[n+1];
		vector<int> v(n);
		for(int i = 1; i<=n; i++){cin>>k;a[k]=i;}
		for(int i=n;i>0;i--){
			v[i-1]=a[i]%i;
			if(a[i]==i)continue;
			else{
				for(int j = 1; j<i; j++){
					a[j]=(a[j]+(i-a[i]))%i;
				}
			}
		}
		for(auto i : v) cout<<i<<" ";cout<<endl;
	}
	return 0;
}