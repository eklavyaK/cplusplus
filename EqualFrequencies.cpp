#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
	int n; cin>>n;
	string s; cin>>s;
	int cnt[26]{}; string s1 = s;
	for(int i=0;i<n;i++)cnt[s[i]-'a']++;
	vector<pair<int,int>> v;
	for(int i=0;i<26;i++){
		v.push_back({cnt[i],i});
	}
	sort(v.begin(),v.end(),greater<pair<int,int>>());
	int mn[26]{}, mnn = 1e9, y = 26;
	for(int i=0;i<26;i++){
		if(n%(i+1)==0){
			int k = n/(i+1);
			for(int j=0;j<=i;j++){
				if(v[j].first<k)mn[i]+=abs(v[j].first-k);
			}
			if(mn[i]<=mnn){
				y = i+1; 
				mnn = mn[i];
			}
		}
	}
	int av = n/y;
	map<int,int> m,x,u;
	vector<int>z(26);
	for(int i=0;i<y;i++){
		if(v[i].first>av)m[v[i].second]=v[i].first-av;
		else if(v[i].first==av)u[v[i].second];
		else if(v[i].first<av)z[v[i].second]=av-v[i].first,x[v[i].second];
	}
	int t = 0;
	for(int i=0;i<n;i++){
		int r = (s[i]-'a');
		if(u.count(r))continue;
		while(t+1<26 && z[t]==0)t++;
		if((!m.count(r)) && (!x.count(r))){
			s[i] = 'a'+t; z[t]--;
		}
		else if(m.count(r)){
			s[i] = 'a'+t; m[r]--; z[t]--;
			if(!m[r])m.erase(r),u[r];
		}
	}
	mnn = 0;
	for(int i=0;i<n;i++){
		if(s1[i]!=s[i]) mnn++;
	}
	cout<<mnn<<endl<<s<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}