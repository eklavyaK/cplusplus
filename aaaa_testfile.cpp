#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
#define pb push_back
#define mp make_pair
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
		int n; cin>>n; int a[n+1];a[n]=0;
		for(int i = 0; i<n; i++){
			cin>>a[i];
		}
		bool t=true;
		vector<pair<int,pair<int,int>>> vec;
		int cn1=0,cn2=0,c2=0,l=0,r=n,u=-1,v=-1,cu=0,cv=0;
		for(int i = 0; i<=n; i++){
			if(a[i]==0){
				t=true;r=i;
				if((cn2+cn1)%2==0){
					vec.pb(mp(c2+cu,mp(l,n-r)));
				}
				else{
					if(u==v){
						cv>(cu-(a[u]==-2))?
						vec.pb(mp(cv,mp(u+1,n-r))):
						vec.pb(mp(cu-(a[u]==-2),mp(l,n-v)));
					}
					else if(cv>cu){
						vec.pb(mp(c2,mp(u+1,n-r)));
					}
					else{
						vec.pb(mp(c2-cv+cu,mp(l,n-v)));
					}
				}
				cn1=0,cn2=0,c2=0,u=-1,v=-1,cu=0,cv=0;
				l=i+1;
			}
			else{
				if(a[i]==-2){
					cn2++;
					if(!t)c2++;
					if(t){
						cu++;
						v=i;u=i;
						t=false;
					}
					else{
						v=i;cv=1;
					}
				}
				else if(a[i]==-1){
					cn1++;
					if(t){
						v=i;u=i;
						t=false;
					}
					else{
						v=i;cv=0;
					}
				}
				else if(a[i]==2){
					if(!t){c2++;cv++;}
					else cu++;
				}
			}
		}
		vec.pb(mp(0,mp(0,0)));
		sort(vec.begin(),vec.end());
		cout<<vec[vec.size()-1].second.first<<" "<<vec[vec.size()-1].second.second<<endl;
	}
	return 0;
}