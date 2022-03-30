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
	int n; cin>>n; int a[n];
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	ll sum=0l,cnt=0;
	map<int,int> m;
	for(int i = 0; i<n; i++){
		if(sum+a[i]<0){
			if(!m.empty()){
				map<int,int>::iterator it=m.begin();
				if(it->first<a[i]){
					sum+=(a[i]-it->first);
					it->second--;m[a[i]]++;
					if(it->second==0){
						m.erase(it->first);
					}
				}
			}
		}
		else{
			sum+=a[i];
			if(a[i]<0){
				m[a[i]]++;
			}
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}