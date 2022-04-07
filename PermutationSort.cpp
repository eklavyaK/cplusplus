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
        int n; cin>>n;int a[n];
        for(int i = 0; i<n; i++)cin>>a[i];
        if(is_sorted(a,a+n))cout<<0<<endl;
        else{
            int k = *min_element(a,a+n);
            int t = *max_element(a,a+n);
            if(k==a[0]||t==a[n-1])cout<<1<<endl;
            else if(a[0]!=t || a[n-1]!=k){
                cout<<2<<endl;
            }
            else{
                int cntk=0,cntt=0;
                for(int i = 0; i<n; i++){
                    if(a[i]==k)cntk++;
                    else if(a[i]==t)cntt++;
                }
                if(cntt==1 && cntk==1){
                    cout<<3<<endl;
                }
                else cout<<2<<endl;
            }
        }
    }
    return 0;
}