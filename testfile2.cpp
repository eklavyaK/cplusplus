#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.precision(28);cin.tie(NULL);

	int n,l,k; cin>>n;
	vector<vector<int>> x(200001);
	vector<pair<int,int>> v(n);
	map<int,int> m;
	for(int i = 0; i<n; i++){
		cin>>l>>k;
		v[i].first=l;
		v[i].second=k;
		x[l].emplace_back(k);
		m[l];
	}
	for(auto i : m) sort(x[i.first].begin(),x[i.first].end());
	for(int i = 0; i<n; i++){
		int a=v[i].first,b=v[i].second;
		int d=1, detect = 1;
		while(detect){
			int u=a-d,v=b,w=a+d;
			if(u<1){cout<<u<<" "<<b<<endl;break;}
			else if(b-d<1){cout<<a<<" "<<b-d<<endl;break;}
			else if(b+d>200000){cout<<a<<" "<<b+d<<endl;break;}
			else if(w>200000){cout<<w<<" "<<b<<endl;detect=0;break;}
			for(int j = 0; j<=d; j++){
				int in = lower_bound(x[u+j].begin(),x[u+j].end(),v+j)-x[u+j].begin();
				if(in>=x[u+j].size()||x[u+j][in]!=v+j){
					cout<<u+j<<" "<<v+j<<endl;
					detect = 0;break;
				}
				in = lower_bound(x[u+j].begin(),x[u+j].end(),v-j)-x[u+j].begin();
				if(in>=x[u+j].size()||x[u+j][in]!=v-j){
					cout<<u+j<<" "<<v-j<<endl;
					detect = 0;break;
				}
				in = lower_bound(x[w-j].begin(),x[w-j].end(),v+j)-x[w-j].begin();
				if(in>=x[w-j].size()||x[w-j][in]!=v+j){
					cout<<w-j<<" "<<v+j<<endl;
					detect = 0;break;
				}
				in = lower_bound(x[w-j].begin(),x[w-j].end(),v-j)-x[w-j].begin();
				if(in>=x[w-j].size()||x[w-j][in]!=v-j){
					cout<<w-j<<" "<<v-j<<endl;
					detect = 0;break;
				}
			}
			d++;
		}
	}

	return 0;
}