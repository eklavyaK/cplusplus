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
		int n; cin>>n;
		map<int,int> map;bool detect=false;
		vector<pair<int,int>> v(n-1);
		vector<pair<int,int>> a(n+1);int cnt[n+1]={0};
		for(int i = 0; i<n-1; i++){
			int l,r;cin>>l>>r;
			v[i].first=l;v[i].second=r;
			cnt[l]++;cnt[r]++;
			if(cnt[l]>=3|cnt[r]>=3)
			detect=true;
			if(!a[l].first)a[l].first=i;
			else a[l].second=i;
			if(!a[r].first)a[r].first=i;
			else a[r].second=i;
		}
		if(detect){cout<<-1<<endl;continue;}
		int b=0,e=0,track=1;
		for(int i = 1; i<=n; i++){
			if(!b){if(cnt[i]==1)b=i;}
			else if(cnt[i]==1)e=i;
		}
		vector<int> c(n-1);
		int in = a[b].first;
		c[in] = 2+(track++)%2;
		if(v[in].first==b){
			b=v[in].second;
		}
		else b=v[in].first; 
		for(int i = 0; i<n-2; i++){
			in = a[b].first==in?a[b].second:a[b].first;
			c[in] = 2+(track++)%2;
			if(v[in].first==b){
				b=v[in].second;
			}
			else b=v[in].first;
		}
		for(auto i : c) cout<<i<<" ";cout<<endl;
	}
	return 0;
}