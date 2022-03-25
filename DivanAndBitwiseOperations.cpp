#include<bits/stdc++.h>
#define mod 1000000007ll
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
		int n,m; cin>>n>>m;int a,b,c,x=0;
		for(int i = 0; i<m; i++){
			cin>>a>>b>>c;
			x|=c;
		}
		long long result=x%mod;n--;
		while(n--)result=(result*2)%mod;
		cout<<result<<endl;
	}
	return 0;
}