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
		int n,k; cin>>n; int a[n+1];
		for(int i = 1; i<=n; i++){
			cin>>a[i];
		}
		if(n==1){cout<<a[1]<<endl;continue;}
		a[0]=0;k=*min_element(a+1,a+1+n);
		if(k<0){
			for(int i = 1; i<=n; i++){
				a[i]+=k;
			}
		}
		sort(a+1,a+n+1);int min=0;
		for(int i = 1; i<=n; i++){
			if(a[i]-a[i-1]>min)min=a[i]-a[i-1];
		}
		cout<<min<<endl;
	}
	return 0;
}