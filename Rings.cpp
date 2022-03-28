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
		int n; cin>>n; string s; cin>>s;
		int k=n/2+n%2;
		for(int i = 0; i<k; i++){
			if(s[i]=='0'){
				cout<<i+1<<' '<<n<<' '<<i+2<<' '<<n<<endl;
				goto end;
			}
		}
		if(n==2){
			cout<<1<<' '<<2<<' '<<1<<' '<<1<<endl;
		}
		else if(n%2==0){
			if(s[k]=='0'){
				cout<<1<<' '<<k+1<<' '<<1<<' '<<k<<endl;
			}
			else cout<<1<<' '<<k<<' '<<2<<' '<<k+1<<endl;
		}
		else cout<<2<<' '<<k<<' '<<1<<' '<<k-1<<endl;
		end:;
	}
	return 0;
}