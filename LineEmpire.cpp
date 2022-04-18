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
        int n,a,b; cin>>n>>a>>b; int v[n];
        for(int i = 0; i<n; i++)cin>>v[i];
        ll dist = 0, c = 0, track = 0;
        ll result = 0;
        while(n>0){
            while(c<track && (v[c]-dist)*a<=n*(v[c]-dist)*b){
                result+=(v[c]-dist)*a;dist=v[c];c++;
            }
            result+=(v[track]-dist)*b;track++;n--;
        }
        cout<<result<<endl;
    }
    return 0;
}