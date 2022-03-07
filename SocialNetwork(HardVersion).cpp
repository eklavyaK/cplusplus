#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int n,c,k; cin>>n>>k; int a[n],t=0;
	int track = 0; vector<int> v;map<int,bool> map;
	for(int i = 0; i<n; i++){
		cin>>c;if(map[c])continue;
		if(track<k){
			track++;map[c]=true;
			v.emplace_back(c);
		}
		else{
			map[v[t]]=false;t++;
			map[c]=true;v.emplace_back(c);
		}
	}
	n = v.size();cout<<n-t<<endl;
	for(int i = n-1; i>=t; i--)cout<<v[i]<<" ";
	cout<<endl;
	return 0;
}