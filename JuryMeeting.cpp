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
		int n; cin>>n; int a[n];
		for(int i = 0; i<n; i++)cin>>a[i];
		sort(a,a+n,greater<int>());
		vector<int> v,s;
		for(int i = 0; i<n; i++){
			int cnt = 1;s.push_back(a[i]);
			while(i+1<n && a[i+1]==a[i]){
				cnt++;i++;
			}
			v.push_back(cnt);
			if(v.size()==2)break;
		}
		ll result = 1l;
		if(v.size()==1){
			n++;
			while(n-->1){
				result=(result*n)%mod2;
			}
		}
		else{
			if(v[0]==1){
				if(s[0]-s[1]>1){
					cout<<0<<endl; 
					goto end;
				}
				else{
					int m = n-(v[0]+v[1]);
					for(int i = 0; i<m; i++){
						result=(result*n)%mod2;
						n--;
					}
					n--;result=(result*n)%mod2;n++;
					while(n-->1){
						result=(result*n)%mod2;
					}
				}
			}
			else{
				n++;
				while(n-->1){
					result=(result*n)%mod2;
				}
			}
		}
		cout<<result<<endl;
		end:;
	}
	return 0;
}