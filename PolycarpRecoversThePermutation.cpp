#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.precision(28);cin.tie(NULL);
	int tc;cin>>tc;
	while(tc-->0)
	{
		int n; cin>>n; int a[n],trackl=0,trackr=0;
		for(int i = 0; i<n; i++)cin>>a[i];vector<int> v;
		if(a[0]!=n && a[n-1]!=n) {cout<<-1<<endl;continue;}
		v.emplace_back(n);
		if(a[0]==n){
			for(int i = n-1; i>=1; i--){
				v.emplace_back(a[i]);
			}
		}
		else{
			for(int i = n-2;i>=0; i--){
				v.emplace_back(a[i]);
			}
		}
		for(auto i : v) cout<<i<<" ";cout<<endl;
	}
	return 0;
}