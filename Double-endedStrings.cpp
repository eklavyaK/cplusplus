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
        string a,b; cin>>a>>b;
        int cnt = 0;
        int n=a.size(),m=b.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(a[i]==b[j]){
                    int k = 1;
                    while(i+k<n && j+k<m && a[i+k]==b[j+k])k++;
                    cnt = max(k,cnt);
                }
            }
        }
        cout<<n+m-2*cnt<<endl;
    }
    return 0;
}