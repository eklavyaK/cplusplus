#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;


int mod = 998244353;
int exp(int a, int n){
    int res = 1;
    while(n>0){
        if(n&1) res = (a*res)%mod;
        n>>=1; a = (a*a)%mod;
    }
    return res;
}
void code(){
    int k; cin>>k;
    int n = (1<<k);
    int f[n+1]{1};
    for(int i=1;i<=n;i++){
        f[i] = f[i-1]*i%mod;
    }
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].F;
        int cnt = 0;
        if(arr[i].F==-1) continue;
        int l = 0, r = k;
        while(l<=r){
            int mid = (l+r)>>1;
            if(arr[i].F<=exp(2,mid)) r = mid-1;
            else l = mid+1;
        }
        arr[i].S = k-r;
    }
    int ans = 1;
    function<bool()> go = [&](){
        int n = arr.size();
        vector<pair<int,int>> ret(n/2);
        int cntz = 0, cnta = 0, cnt = 0,com=0;
        for(int i=0;i<n;i+=2,cnt++){
            if(arr[i].F!=-1 && arr[i+1].F!=-1){
                if((arr[i].S!=1 && arr[i+1].S!=1) || (arr[i].S==arr[i+1].S)){
                    ans = 0; 
                    return false;
                }
                com++;
            }
            if(arr[i].F!=-1){
                if(arr[i].F<=n/2) cnta++;
                else cntz++;
                arr[i].S--;
                if(!arr[i].S) arr[i].F = -1;
                else ret[cnt] = arr[i];
            }
            if(arr[i+1].F!=-1){
                if(arr[i+1].F<=n/2) cnta++;
                else cntz++;
                arr[i+1].S--;
                if(!arr[i+1].S) arr[i+1].F = -1;
                else ret[cnt] = arr[i+1];
            }
            if(!ret[cnt].F) ret[cnt] = {-1,0};
        }
        ans = ans*f[n/2-cntz]%mod*exp(2,n/2-cntz-cnta+com)%mod;
        arr = ret;
        return true;
    };
    for(int i=0;i<k;i++) if(!go()) break;
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1; while(t--)code();
    return 0;
}