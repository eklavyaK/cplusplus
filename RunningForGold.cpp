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
		int n; cin>>n; int a[n][5];
		for(int i = 0; i<n; i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4];
		}
		int r = 0;
		for(int i = 1; i<n; i++){
			int k = (a[r][0]<a[i][0])+(a[r][1]<a[i][1])+(a[r][2]<a[i][2])+(a[r][3]<a[i][3])+(a[r][4]<a[i][4]);
			if(k<3)r=i;
		}
		for(int i = 0; i<n; i++){
			if(r!=i){
				int k = (a[r][0]<a[i][0])+(a[r][1]<a[i][1])+(a[r][2]<a[i][2])+(a[r][3]<a[i][3])+(a[r][4]<a[i][4]);
				if(k<3){cout<<-1<<endl;goto end;}
			}
		}
		cout<<r+1<<endl;end:;
	}
	return 0;
}