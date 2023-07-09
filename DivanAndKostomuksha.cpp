#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debug(c)
#define debugarr(a,n)
#define debugvar(c)
#endif

const int N = 5e6+5;
int spf[N], cnt[N], sum[N];
vector<int> pfac, fac, prime;
void spfac(int n){
    iota(spf,spf+n+1,0);
    for(int i=2;i*i<=n;i++){
        if(spf[i]!=i)continue;
        for(int c=i*i;c<=n;c+=i) if(spf[c]==c)spf[c]=i;
    }
    for(int i=2;i<=n;i++) if(spf[i]==i) prime.push_back(i);
}
void primefactor(int n){
    pfac.clear(); while(n!=1) pfac.push_back(spf[n]), n/=spf[n];
}
void allfactors(int n){
    fac.clear();
    primefactor(n);
    fac.push_back(1);
    for(int i=0;i<pfac.size();i++){
        n = i;
        while(i+1<pfac.size() && pfac[i+1]==pfac[i]) ++i;
        int cur = pfac[i], en = fac.size();
        for(int j=0; j<=(i-n); j++,cur*=pfac[i]){
            for(int l=0;l<en;l++){
                fac.push_back(fac[l]*cur);
            }
        }
    }
}

void code(int TC){
    spfac(N-5);
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        int c = i;
        while(i+1<n && arr[i+1]==arr[i]) i++;
        allfactors(arr[i]);
        for(auto j : fac) cnt[j] += (i-c+1);
    }
    for(int i=N-5;i>=1;i--){
        int mx = i*cnt[i];
        for(auto j : prime){
            if(j*i>N-5) break;
            mx = max(mx, sum[j*i] + (cnt[i] - cnt[j*i]) * i);
        }
        sum[i] = mx;
    }
    cout<<sum[1]<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}