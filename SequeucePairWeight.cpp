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
    int tc;cin>>tc;
    while(tc-->0){
        map<int,vector<int>> m;
        int n; cin>>n; int a[n];
        for(int i = 0; i<n; i++){
            cin>>a[i];
            m[a[i]].push_back(i+1);
        }
        ll result = 0;
        for(auto i : m){
            int k=i.second.size();
            if(n>1){
                ll cnt = i.second[0];
                for(int j = 1; j<k; j++){
                    result+=cnt*(n-i.second[j]+1);
                    cnt+=i.second[j];
                }
            }
        }
        cout<<result<<endl;
    }
    return 0;
}