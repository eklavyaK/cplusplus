#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
#define rapid_io ios_base::sync_with_stdio(0);cin.tie(0)
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    rapid_io;
    ll sum = 0;
    int n; cin>>n;
    vector<pair<ll,ll>> v(n);
    ll result = 0, cnt = 0;
    for(int i = 0; i<n; i++){
        cin>>v[i].second>>v[i].first;
        sum+=v[i].second;
    }
    int l=0, r=n-1;
    sort(v.begin(),v.end());
    while(cnt<sum){
        ll k = v[l].first-cnt;
        while(k>0 && cnt<sum){
            if(v[r].second<=k){
                cnt+=v[r].second;
                result+=v[r].second*2;
                k-=v[r].second;r--;
            }
            else{
                cnt+=k;
                result+=k*2;
                v[r].second-=k;k=0;
            }
        }
        if(cnt==sum)break;
        cnt+=v[l].second;
        result+=v[l].second;l++;
    }
    cout<<result<<endl;
    return 0;
}