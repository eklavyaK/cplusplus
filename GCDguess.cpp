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
int m = pow(2,30);
int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0){
        int sum = 0;
        cout<<'?'<<' '<<m<<' '<<m+2<<endl<<flush;
        int k; cin>>k;
        if(k==1)sum=1;
        for(int i = 2; i<30; i++){
            cout<<'?'<<' '<<m-sum<<' '<<m-sum+pow(2,i)<<endl<<flush;
            cin>>k; if(k==pow(2,i-1))sum+=k;
        }
        if(sum+m/2>1000000000){cout<<'!'<<' '<<sum<<endl;continue;}
        cout<<'?'<<' '<<m/2+sum<<' '<<2*sum+m<<endl<<flush;
        cin>>k; int res = (k==(sum+m/2)?k:sum);
        cout<<'!'<<' '<<res<<endl;
    }
    return 0;
}