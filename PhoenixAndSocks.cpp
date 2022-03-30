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
		int n,l,r,k; cin>>n>>l>>r;
		map<int,int> c,ml,mr;
		for(int i = 0; i<l; i++){
			cin>>k;ml[k]++;c[k];
		}
		for(int i = 0; i<r; i++){
			cin>>k;mr[k]++;c[k];
		}
		int cnt=0;l=0,r=0;
		map<int,int> vl,vr;
		for(auto i : c){
			if(mr[i.first]>ml[i.first]){
				int k = mr[i.first]-ml[i.first];
				if(k>0){vr[i.first]=k;r+=k;}
			}
			else{
				int k = ml[i.first]-mr[i.first];
				if(k>0){vl[i.first]=k;l+=k;}
			}
		}
		if(l>r){
			int d=l-r;
			for(auto i : vl){
				if(i.second>1){
					int t = i.second-i.second%2;
					if(d>=t){
						l-=t;cnt+=t/2;d-=t;
					}
					else{
						cnt+=d/2;
						l=r;
					}
					if(l==r)break;
				}
			}
		}
		else if(r>l){
			int d=r-l;
			for(auto i : vr){
				if(i.second>1){
					int t = i.second-i.second%2;
					if(d>=t){
						r-=t;cnt+=t/2;d-=t;
					}
					else{
						cnt+=d/2;
						r=l;
					}
					if(l==r)break;
				}
			}
		}
		cnt+=(min(l,r)+abs(l-r));
		cout<<cnt<<endl;
	}
	return 0;
}