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
		int n; cin>>n; string a,b;
		cin>>a>>b;int c1=0,c0=0;
		int t1=0,t0=0;
		for(int i = 0; i<n; i++){
			if(a[i]!=b[i]){
				if(a[i]=='1')c1++;
				else c0++;
			}
			else if(a[i]=='1')t1++;
			else t0++;
		}
		if(c0==c1&&((t1+t0)%2 && t1-t0==1)){
			cout<<min(c0+c1,t0+t1)<<endl;
		}
		else if((t1+t0)%2 && t1-t0==1){
			cout<<t0+t1<<endl;
		}
		else if(c0==c1){
			cout<<c0+c1<<endl;
		}
		else cout<<-1<<endl;
	}
	return 0;
}