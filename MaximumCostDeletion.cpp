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
        int n,a,b; cin>>n>>a>>b;
        string s; cin>>s;
        if(b<0){
            int z1=0,z2=0;
            for(int i = 0; i<n; i++){
                if(s[i]=='1'){
                    while(i+1<n&&s[i]==s[i+1])i++;
                    z1++;
                }
                else{
                    while(i+1<n&&s[i]==s[i+1])i++;
                    z2++;
                }
            }
            cout<<min(z1,z2)*b+b+a*n<<endl;
        }
        else{
            cout<<(a+b)*n<<endl;
        }
    }
    return 0;
}