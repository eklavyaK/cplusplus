#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
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
    int tc;cin>>tc;while(tc--){
        int n,x,k; cin>>n>>x;
        vector<int> v;
        bool b=false;
        for(int i = 0; i<n; i++){
            cin>>k;
            if(k!=x)
            v.push_back(k);
            else b=true;
        }
        ll sum = 0;
        n=v.size();
        for(int i = 0; i<n; i++){
            sum+=(v[i]-x);
        }
        if(n==0)cout<<0<<endl;
        else if(sum==0 || b){
            cout<<1<<endl;
        }
        else cout<<2<<endl;
    }
    return 0;
}