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
int a[500001],b[500001],c[500001],m[500001];
int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0){
        int n; cin>>n;
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        for(int i = 0; i<n; i++){
            cin>>b[i];
            m[b[i]]=i;
        }
        for(int i = 0; i<n; i++){
            cin>>c[i];
        }
        int cnt = 0;bool r[n]={false};
        for(int i = 0; i<n; i++){
            bool t = true;
            if(r[i]==false && c[i]==0){
                r[i]=true;
                if(a[m[a[i]]]==a[i] || c[m[a[i]]]!=0){
                    continue;
                }
                int k = a[m[a[i]]];
                r[m[a[i]]]=true;
                while(k!=a[i]){
                    if(c[m[k]]!=0){
                        t=false;
                        break;
                    }
                    else{
                        r[m[k]]=true;
                        k=a[m[k]];
                    }
                }
                if(t)cnt++;
            }
            else r[i]=true;
        }
        ll result = 1;
        for(int i = 0; i<cnt; i++){
            result=(result*2)%mod1;
        }
        cout<<result<<endl;
    }
    return 0;
}