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
	int tc;cin>>tc;
	while(tc-->0){
		int n; cin>>n;
		int l[n],r[n],c[n];
		for(int i = 0; i<n; i++){
			cin>>l[i]>>r[i]>>c[i];
		}
		vector<int> cost(n);
		int cf=0,ce=0,f=l[0],e=r[0];
		int inf=0,ine=0;cost[0]=c[0];
		for(int i = 1; i<n; i++){
			cost[i]=cost[i-1];
			if(l[i]<f)cf=i;if(r[i]>e)ce=i;
			if(l[i]==f && c[i]<c[cf])cf=i;
			if(r[i]==e && c[i]<c[ce])ce=i;
			if(r[i]==e && l[i]==f && c[i]==c[ce] && c[i]==c[cf]){ce=i;cf=i;}
			if(l[i]<=f && r[i]>=e){
				if(f==l[i]&&e==r[i]){
					if(inf!=ine && c[inf]+c[ine]>=c[i]){inf=i;ine=i;cost[i]=c[i];}
					else if(c[i]<cost[i]){inf=i;ine=i;cost[i]=c[i];}}
				else{f=l[i];e=r[i];inf=i;ine=i;cost[i]=c[i];}
			}
			else if(l[i]<=f){
				if(l[i]<f){if(inf!=ine)cost[i]=c[ine]+c[i];else cost[i]+=c[i];inf=i;f=l[i];ine=ce;}
				else if(inf!=ine)if(c[i]<c[inf]){cost[i]+=(c[i]-c[inf]);inf=i;}}
			else if(r[i]>=e){
				if(r[i]>e){if(inf!=ine)cost[i]=c[inf]+c[i];else cost[i]+=c[i];ine=i;e=r[i];inf=cf;}
				else if(inf!=ine)if(c[i]<c[ine]){cost[i]+=(c[i]-c[ine]);ine=i;}}
			cost[i]=min(cost[i],ce==cf?c[cf]:(c[ce]+c[cf]));
		}
		for(auto i : cost){
			cout<<i<<endl;
		}
	}
	return 0;
}