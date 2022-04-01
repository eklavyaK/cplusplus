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
		string r1,r2;
		cin>>r1>>r2;
		int cnt = 0,z=0,o=0;
		for(int i = 0; i<n; i++){
			if(r1[i]-'0'+r2[i]-'0'==1){
				cnt+=2;
				if(z==1)cnt++;
				z=0,o=0;
			}
			else if(r1[i]=='0'&&r2[i]=='0'){
				if(z==1)cnt++;
				else z++;
				if(o==1){
					cnt+=2;
					o=0;z=0;
				}
			}
			else{
				o=1;
				if(z==1){
					cnt+=2;
					o=0;z=0;
				}
			}
		}
		if(z==1)cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}