#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

int mod = 99991, nod = 99989;     //complexity - n^2 log(mod)

int exp(int a, int n){
    int res = 1, mod = n+2;
    while(n>0){
        if(n&1) res = (res*a)%mod;
        a = (a*a)%mod; n>>=1;
    }
    return res;
}

void code(){
    string s,a; cin>>s>>a;
    int k = 0, ans = 0; cin>>k;
    int n = s.size(), sz[n+1]{};
    for(int i=1;i<=n;i++)sz[i] = sz[i-1]+(a[s[i-1]-'a']=='0');
    int fx[n+5]{1}, fy[n+5]{1};
    for(int i=1;i<=n;i++){
        fx[i] = (fx[i-1]*31)%mod;
        fy[i] = (fy[i-1]*31)%nod;
    }
    for(int i=1;i<=n;i++){
        set<int> id[n-i+5];
        map<int,int> modulo;
        int cx = 0, cy = 0, c = 0;
        for(int j=1;j<=i;j++){
            cx = (cx + fx[j]*(s[j-1]-'a'+1))%mod;
            cy = (cy + fy[j]*(s[j-1]-'a'+1))%nod;
        }
        if(sz[i]-sz[0]<=k){
            ++ans;
            modulo[cx] = ++c;
            id[c].insert(cy);
        }
        for(int j=i+1;j<=n;j++){
            cx = (cx+fx[i+1]*(s[j-1]-'a'+1)-fx[1]*(s[j-i-1]-'a'+1))%mod;
            cy = (cy+fy[i+1]*(s[j-1]-'a'+1)-fy[1]*(s[j-i-1]-'a'+1))%nod;
            cx = cx*exp(31,mod-2)%mod;
            cy = cy*exp(31,nod-2)%nod;
            if(sz[j]-sz[j-i]<=k){
                if(modulo.count(cx)){
                    int r = modulo[cx];
                    if(!id[r].count(cy))id[r].insert(cy),++ans;
                }
                else{
                    ++ans;
                    modulo[cx] = ++c;
                    id[c].insert(cy);
                }
            }
        }
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t  =   1; while(t--)code();
    return 0;
}