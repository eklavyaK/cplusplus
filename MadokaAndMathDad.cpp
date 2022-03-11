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
		int n; cin>>n;
		if(n%3==1){
			n--;int k = n/3;cout<<1;
			for(int i = 0; i<k; i++) cout<<"21";
		}
		else if(n%3==0){
			int k = n/3;
			for(int i = 0; i<k; i++) cout<<"21";
		}
		else{
			int k = (n-2)/3;
			for(int i = 0; i<k; i++) cout<<"21";
			cout<<2;
		}
		cout<<endl;
	}
	return 0;
}