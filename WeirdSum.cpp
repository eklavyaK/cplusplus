#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,z,k;cin>>n>>z; 
	map<int,int> m;
	vector<map<int,int>> r(100001);
	vector<map<int,int>> c(100001);
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=z; j++){
			cin>>k;
			r[k][i]++;
			c[k][j]++;
			m[k];
		}
	}
	long long sum = 0l;
	for(auto i : m){
		long long temp = 0l;
		vector<pair<int,int>> cr(r[i.first].size()),cc(c[i.first].size());
		copy(r[i.first].begin(),r[i.first].end(),cr.begin());
		copy(c[i.first].begin(),c[i.first].end(),cc.begin());
		int sr=cr.size(),sc=cc.size(),n=cr[0].second;
		for(int j = 1; j<sr; j++){
			temp+=(long long)(cr[j].first-cr[j-1].first)*n;
			sum+=temp*cr[j].second;n+=cr[j].second;
		}
		temp=0l,n=cc[0].second;
		for(int j = 1; j<sc; j++){
			temp+=(long long)(cc[j].first-cc[j-1].first)*n;
			sum+=temp*cc[j].second;n+=cc[j].second;
		}
	}
	cout<<sum<<endl;
	return 0;
}