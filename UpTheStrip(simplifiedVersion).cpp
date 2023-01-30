#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;

int main(){
	ll n,m; cin>>n>>m;
	ll cnt[n+1]{}, sub = 0;
	cnt[n] = 1;
	for(int i=n;i>=2;i--){
		cnt[i]=(cnt[i]+sub)%m;
		ll k = i, rt = sqrt(i);
		if(rt==1){
			cnt[1] = (cnt[1]+(i-1)*cnt[i])%m;
			sub = (sub+cnt[i])%m;
			continue;
		}
		vector<int> freq; 
		int now = 2;
		while(true){
			int t = i/now; now++;
			if(t<rt) break;
			cnt[t]=(cnt[t]+cnt[i])%m;
			freq.push_back(k - t);
			k = t;
		}
		for(int j=1;j<rt;j++){
			cnt[j] = (cnt[j] + freq[j-1]*cnt[i])%m;
		}
		sub = (sub+cnt[i])%m;
	}
	cout<<(cnt[1]+sub)%m<<endl;
	return 0;
}