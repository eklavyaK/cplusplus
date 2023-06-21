#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N=1e5+5;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debug(c)
#define debugarr(a,n)
#define debugvar(c)
#endif
int l[N],r[N];
int ans[30];

vector<pii> f;

bool cmp(pii a,pii b){
	if(a.first==b.first){
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
	}
	for(int i=0;i<=29;i++){
		int step=(1<<i);
		f.clear();
		for(int j=1;j<=n;j++){
			if(r[j]-l[j]+1>=step){
				f.push_back({0,1});
				f.push_back({step,-1});
				continue;
			}
			int x=l[j]%step;
			int y=x+r[j]-l[j];
			f.push_back({0,1});
			f.push_back({max(y-step+1,0),-1});
			f.push_back({x,1});
			f.push_back({min(step,y+1),-1});
		}
		sort(f.begin(),f.end(),cmp);
		int num=0;
		for(int j=0;j<f.size();j++){
			num+=f[j].second;
			ans[i]=max(ans[i],num); 
		}
	}
    debugarr(ans,30);
	// int q;
	// cin>>q;
	// while(q--){
	// 	int w;
	// 	scanf("%d",&w);
	// 	int k;
	// 	for(int i=0;i<=29;i++){
	// 		if((w>>i)&1){
	// 			k=i;
	// 			break;
	// 		}
	// 	}
	// 	printf("%d\n",ans[k]);
	// }
	// return 0;
}