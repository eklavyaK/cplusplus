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
		int n,l,r; cin>>n; int cnt[n+1]={0};
		map<int,int> m; map<long long, int> in;
		int v[n-1];bool detect = false,node[n+1]={false};
		vector<pair<int,int>> vi(n-1);
		for(int i = 0; i<n-1; i++){
			cin>>l>>r;in[(long long)l*r]=i;
			vi[i].first=l;vi[i].second=r;
			cnt[l]++;cnt[r]++;
		}
		cout<<endl;
		int a=0,b=0;
		for(int i = 0; i<n-1; i++){
			if(cnt[vi[i].first]>=3){detect = true;break;}
			else if(cnt[vi[i].first]==2 && cnt[vi[i].second]==2){
				if(m[vi[i].first] && m[vi[i].second]){
					if(cnt[m[vi[i].first]]==1){
						int temp = m[vi[i].first];
						m.erase(vi[i].first);
						m[temp]=vi[i].first;
						m[vi[i].first]=vi[i].second;
						node[vi[i].second]=true;
					}
					else{
						int temp = m[vi[i].second];
						m.erase(vi[i].second);
						m[temp]=vi[i].second;
						m[vi[i].second]=vi[i].first;
						node[vi[i].first]=true;
					}
				}
				else if(m[vi[i].first]) {m[vi[i].second]=vi[i].first;node[vi[i].first]=true;}
				else if(m[vi[i].second]){m[vi[i].first]=vi[i].second;node[vi[i].second]=true;}
				else if(node[vi[i].first]) {m[vi[i].first]=vi[i].second;node[vi[i].second]=true;}
				else if(node[vi[i].second]){m[vi[i].second]=vi[i].first;node[vi[i].first]=true;}
				else {
					m[vi[i].first]=vi[i].second;
					node[vi[i].second]=true;
				}
			}
			else if(!a)a=i+1;else b=i;
			//for(auto i : m) cout<<i.first<<" "<<i.second<<endl; cout<<endl;
		}
		//for(auto i : m) if(i.second==0)m.erase(i.first);
		//cout<<a<<" "<<b<<endl;
		if(detect){cout<<-1<<endl;continue;}
		{
			a--;int temp;
			if(m[vi[a].first]){
				m[vi[a].second]=vi[a].first;
				a=vi[a].second;
				if(cnt[vi[b].second]==1){
					m[vi[b].second]=vi[b].first;
					b=vi[b].second;
				}
				else{
					m[vi[b].first]=vi[b].second;
					b=vi[b].first;
				}
			}
			else if(cnt[vi[a].first]==2){
				temp=b;
				m[vi[a].first]=vi[a].second;
				b=vi[a].second;
				if(cnt[vi[temp].second]==1){
					m[vi[temp].second]=vi[temp].first;
					a=vi[temp].second;
				}
				else{
					m[vi[temp].first]=vi[temp].second;
					a=vi[temp].first;
				}
			}
			else{
				m[vi[a].first]=vi[a].second;
				a=vi[a].first;
				if(cnt[vi[b].second]==1){
					m[vi[b].first]=vi[b].second;
					b=vi[b].second;
				}
				else{
					m[vi[b].second]=vi[b].first;
					b=vi[b].first;
				}
			}
		}
		for(auto i : m) cout<<i.first<<" "<<i.second<<endl;//exit(0);
		cout<<endl<<a<<" "<<b<<endl;cout<<endl;
		for(auto i : in) cout<<i.first<<" "<<i.second<<endl;
		int track = 1;
		while(m[a]!=b){
			v[in[(long long)a*m[a]]*abs(a-m[a])]=2+track%2;
			a=m[a];track++;
		}
		v[in[(long long)a*m[a]]]=2+track%2;
		for(auto i : v) cout<<i<<" ";cout<<endl;
	}
	return 0;
}