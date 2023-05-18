#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

int mod = 1e9+7;

int exp(int a, int n){
    int res = 1;
    while(n>0){
        if(n&1) res = (res*a)%mod;
        a = (a*a)%mod; n>>=1;
    }
    return res;
}

void code(){
    int n; cin>>n;
    int arr[n];
    map<int,int> m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        int cnt = 0;
        while(arr[i]%2==0)arr[i]>>=1,cnt++;
        m[cnt]++;
    }
    int all = 0, minus = 0, ans = exp(2,n);
    vector<int> v;
    for(auto i : m){
        if(i.F==0) continue;
        all+=i.S;
        v.push_back(i.S);
    }
    for(int i=0;i<v.size();i++){
        minus = (minus+exp(2,v[i]-1)*exp(2,all-v[i]))%mod;
        all-=v[i];
    }
    cout<<(ans-1-minus+mod*2)%mod<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1; while(t--)code();
    return 0;
}