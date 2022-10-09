#define PROGRAM int main(){rapid_iostream;int tc=1;cin>>tc;while(tc-->0){codeforce();}return 0;}
#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream cin.tie(0)->sync_with_stdio(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
#define println(n) cout<<n<<'\n'
#define MAIN void codeforce();
#define Y() cout<<"YES"<<endl
#define print(n) cout<<n<<' '
#define N() cout<<"NO"<<endl
#define pii pair<int,int>
#define mod1 1000000007ll
#define pli pair<ll,int>
#define pil pair<int,ll>
#define mod2 998244353ll
#include<bits/stdc++.h>
#define pll pair<ll,ll>
typedef long double ld;
typedef long long ll;
#define mp make_pair
using namespace std;
#define endl '\n'
#define S second
#define F first
Compare(pii)
/***************************************************/ MAIN PROGRAM /*******************************************************/



void codeforce(){
	int n; cin>>n;
	map<char,char> m;
	string s; cin>>s;
	set<char> st;
	for(int i=0;i<n;i++){
		if(m.count(s[i])){
			cout<<m[s[i]];
		}
		else{
			for(int j=0;j<26;j++){
				char c = 'a'+j;
				if(!st.count(c) && c!=s[i]){
					int cnt = 1;
					char now = c;
					while(m.count(now)){
						now = m[now];
						cnt++;
					}
					if(now==s[i] && cnt<26){
						continue;
					}
					m[s[i]] = c;
					st.insert(c);
					cout<<c;
					break;
				}
			}
		}
	}
	cout<<endl;
}