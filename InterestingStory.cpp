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
		int n; cin>>n; string s;
		vector<int> v(n);
		int cnt[n][5],sz[n];
		for(int i = 0; i<n; i++){
			vector<int> c(5);
			cin>>s;sz[i] = s.size();
			for(int j = 0; j<s.size(); j++){
				c[s[j]-'a']++;
			}
			for(int j = 0; j<5; j++){
				cnt[i][j]=c[j];
			}
		}int result = 0;
		for(int j = 0; j<5; j++){
			for(int i = 0; i<n; i++){
				v[i]=sz[i]-2*cnt[i][j];
			}
			int sum = 0,cn=0;
			sort(v.begin(),v.end());
			for(int i = 0; i<n; i++){
				sum+=v[i];
				if(sum>=0)break;
				else cn++;
			}
			result=max(result,cn);
		}
		cout<<result<<endl;
	}
	return 0;
}