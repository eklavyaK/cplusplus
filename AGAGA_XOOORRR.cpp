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
		int n;cin>>n; int k;
		string s[n];int t[n][30];
		for(int i = 0; i<n; i++){
			for(int j = 0; j<30; j++){
				t[i][j]=0;
			}
		}
		for(int i = 0; i<n; i++){
			cin>>k;
			s[i]=binary(k,30);
			for(int j = 0; j<30; j++){
				if(s[i][j]=='1'){
					t[i][j]++;
				}
				if(i!=0){
					t[i][j]+=t[i-1][j];
				}
			}
		}
		if(n==2){
			s[0]==s[1]?Y():N();
			continue;
		}
		for(int i = 0; i<n-1; i++){
			bool detect = true;
			for(int j = 0; j<30; j++){
				if(t[i][j]%2!=(t[n-1][j]-t[i][j])%2){
					detect = false;break;
				}
			}
			if(detect){
				Y();goto end;
			}
			for(int k = i+1; k<n-1; k++){
				detect = true;
				for(int j = 0; j<30; j++){
					if(t[i][j]%2!=(t[k][j]-t[i][j])%2||
					t[i][j]%2!=(t[n-1][j]-t[k][j])%2){
						detect = false;break;
					}
				}
				if(detect){
					Y();goto end;
				}
			}
		}
		N();end:;
	}
	return 0;
}