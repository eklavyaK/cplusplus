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
		map<ld,pair<int,int>> m;
		int cd[n],ck[n],td=0,tk=0;
		for(int i = 0; i<n; i++){
			s[i]=='K'?tk++:td++;
			ck[i]=tk;cd[i]=td;
		}
		for(int i = 0; i<n; i++){
			int g=gcd(ck[i],cd[i]);
			if(g==1){
				cout<<1<<" ";
				continue;
			}
			ld ratio = (ld)ck[i]/cd[i];
			int k = (ck[i]+cd[i])/g;
			int cnt = 0,j=k-1;
			if(m[ratio].first){
				j=m[ratio].first+k;
				cnt=m[ratio].second;
			}
			for(;j<=i;j+=k){
				if(ratio==(ld)ck[j]/cd[j]){
					cnt++;
				}
			}
			cout<<cnt<<" ";
			m[ratio].first=i;
			m[ratio].second=cnt;
		}
		cout<<endl;
	}
	return 0;
}