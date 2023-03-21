#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

const int N = 1e6+5;
bool f[N];
void code(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int k; cin>>k;
        f[k] = 1;
    }
    for(int i=1e6;i>=1;i--){
        if(f[i]) continue;
        int g = 0;
        for(int j=2;j*i<N;j++){
            if(f[j*i])g = gcd(j*i,g);
        }
        if(g==i)f[i]=1;
    }
    int ans = 0;
    for(int i=1;i<N;i++){
        if(f[i])ans++;
    }
    cout<<ans-n<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}  