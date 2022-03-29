#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout.precision(28);cin.tie(NULL);
	int tc;cin>>tc;
	while(tc-->0){
		int n; cin>>n;
		vector<int> v(n),r(n),e,o;
		for(int i = 0; i<n; i++){
			cin>>v[i];
		}
		for(int i = 0; i<n; i+=2){
			e.push_back(v[i]);
		}
		for(int i = 1; i<n; i+=2){
			o.push_back(v[i]);
		}
		int track = 0;
		sort(e.begin(),e.end());
		sort(v.begin(),v.end());
		sort(o.begin(),o.end());
		for(int i = 0; i<n; i+=2){
			r[i]=e[track++];
		}track=0;
		for(int i = 1; i<n; i+=2){
			r[i]=o[track++];
		}
		if(v==r)Y();else N();
	}
	return 0;
}