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
	vector<char> c{'2','3','5','7'};
	vector<string> f{"23","37","53","73"};
	int tc;cin>>tc;
	while(tc-->0){
		int n; cin>>n;
		string s;cin>>s;
		for(int i = 0; i<n; i++){
			if(find(c.begin(),c.end(),s[i])==c.end()){
				cout<<1<<endl<<s[i]<<endl;goto end;
			}
		}
		for(int i = 0; i<n-1; i++){
			for(int j = i+1; j<n; j++){
				string t(1,s[i]);t+=s[j];
				if(find(f.begin(),f.end(),t)==f.end()){
					cout<<2<<endl<<t<<endl;goto end;
				}
			}
		}
		cout<<3<<endl<<s[0]<<s[1]<<s[2]<<endl;
		end:;
	}
	return 0;
}