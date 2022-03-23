#include<bits/stdc++.h>
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

	int n,C;cin>>n>>C;int c,d,h;
	map<int,ll> cost; ll result[C+1]={0};
	for(int i = 0; i<n; i++){
		cin>>c>>d>>h;
		cost[c]=max((ll)d*h,cost[c]);
	}
	for(auto i : cost){
		for(int j = 1; i.first*j<=C; j++){
			result[i.first*j]=max(result[i.first*j],i.second*j-1);
		}
	}
	for(int i = 1; i<=C; i++){
		result[i]=max(result[i],result[i-1]);
	}
	vector<ll> x; vector<int> y;
	ll temp = 0;
	for(int i = 1; i<=C; i++){
		if(result[i]!=temp){
			temp=result[i];
			x.push_back(temp);
			y.push_back(i);
		}
	}
	n=x.size();
	int m; ll a,b; cin>>m;while(m--){
		cin>>a>>b;
		ll k = a*b;
		int in = lower_bound(x.begin(),x.end(),a*b)-x.begin();
		if(in==n){cout<<-1<<" ";}
		else cout<<y[in]<<" ";
	}

	return 0;
}