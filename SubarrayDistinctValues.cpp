#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define binary(n,k) bitset<k>(n).to_string()
#include<bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define mod2 998244353ll
#define mod1 1000000007ll
#define print(n) cout<<n<<endl
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    rapid_iostream;

    int n,k; 
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int,int> m;
    ll ans = n;
    int l = 0, r = 0;
    while(l<=r && r<n){
        if(m.count(a[r])){
            ans+=(r-l);
            m[a[r]]++;
            r++;
        }
        else if(m.size()<k){
            ans+=(r-l);
            m[a[r]]++;
            r++;
        }
        else{
            m[a[l]]--;
            if(m[a[l]]==0)
            m.erase(a[l]);
            l++;
        }
    }
    cout<<ans;

    return 0;
}