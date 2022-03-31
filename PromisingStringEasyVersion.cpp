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
		string s; cin>>s;
		int cp[n],cm[n];
		if(s[0]=='+'){cp[0]=1;cm[0]=0;}
		else {cm[0]=1;cp[0]=0;}
		for(int i = 1; i<n; i++){
			cp[i]=cp[i-1];
			cm[i]=cm[i-1];
			if(s[i]=='+'){
				cp[i]++;
			}
			else{
				cm[i]++;
			}
		}
		int cnt = 0;
		for(int i = 2; i<=n; i++){
			for(int j = i-1; j<n; j++){
				int l =cp[j],r=cm[j];
				if(j-i>=0){l-=cp[j-i];r-=cm[j-i];}
				if(l==r){
					cnt++;
				}
				else if(r-l>=3 && (r-l)%3==0){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}