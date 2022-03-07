#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int n; cin>>n;
	for(int i = 1; i<=n; i++){
		int k = i;
		for(int j = 1; j<=n; j++){
			cout<<k<<" ";
			k+=j%2?2*(n-i)+1:2*(i-1)+1;
		}
		cout<<endl;
	}

	return 0;
}