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
		ll sum=0l,k;cin>>k;
		for(int i = 0; i<n; i++){
			cin>>a[i];sum+=a[i];
		}
		sort(a,a+n);
		int h = a[0];ll cnt=0;
		int r = 1,track=n-1;
		while(sum>k){
			if(track>0 && a[track]-h>=r){
				sum-=(a[track]-h);
				cnt++; track--; r++; 
			}
			else if(track==0){
				cnt+=ceil((ld)(sum-k)/r);
				break;
			}
			else{
				int x = r+h-a[track];
				if(sum-(ll)x*r<=k){
					cnt+=ceil((ld)(sum-k)/r);
					break;
				}
				sum-=(ll)x*r;h-=x;cnt+=x;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}