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
    int tc;cin>>tc;
    while(tc-->0){
        int n; cin>>n;
        int a[n];
        vector<vector<int>> v;
        for(int i = 0; i<n; i++)cin>>a[i];
        for(int i = 1; i<n; i++){
            vector<int> t(i);
            if(a[0]<a[i])t[0]=1;
            for(int j = 1; j<i; j++){
                if(a[j]<a[i]){
                    t[j]=1;
                }
                t[j]+=t[j-1];
            }
            v.push_back(t);
        }
        ll cnt = 0;
        for(int i=n-3;i>=1;i--){
            ll k = 0;
            for(int j = i+1; j<n; j++){
                if(a[i]>a[j]){
                    cnt+=k;
                }
                k+=v[j-1][i-1];
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}