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
using namespace std;int a[200001],n;
bool possibility(int x){
	vector<int> v(a,a+n);
	for(int i=n-1;i>=2;i--){
		if(v[i]<x) return false;
		int k = min(a[i],v[i]-x)/3;
		v[i-1]+=k;v[i-2]+=k*2;
	}
	return v[0]>=x & v[1]>=x;
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.precision(28);cin.tie(NULL);
	int tc;cin>>tc;
	while(tc-->0){
		cin>>n;
		for(int i = 0; i<n; i++)cin>>a[i];
		int l = 0,r=*max_element(a,a+n);
		while(l<r){
			int mid = l+(r-l+1)/2;
			if(possibility(mid))l=mid;
			else r=mid-1;
		}
		cout<<l<<endl;
	}
	return 0;
}