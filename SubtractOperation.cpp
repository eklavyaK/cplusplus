#include<bits/stdc++.h>
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
		int n,k; cin>>n>>k; 
		map<int,int> m;int c;
		for(int i = 0; i<n; i++){
			cin>>c;m[c]=1;
		}
		for(auto i : m){
			if(m[i.first+k]){
				Y();goto end;
			}
			else m.erase(i.first+k);
		}
		N();end:;
	}
	return 0;
}