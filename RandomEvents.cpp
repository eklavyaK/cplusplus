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
    cout<<setprecision(6)<<fixed;cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0){
        int n,m,k=0; cin>>n>>m; int a[n];
        for(int i = 0; i<n; i++)cin>>a[i];
        vector<int> v(a,a+n);
        sort(v.begin(),v.end());
        for(int i=n-1;i>=0;i--){
            if(v[i]!=a[i]){
                k = i+1;break;
            }
        }
        if(k==0){
            ld f,c;
            while(m--){
                cin>>c>>f;
            }
            cout<<1<<endl;
            continue;
        }
        else{
            ld f,c;
            ld result = 0;
            while(m--){
                cin>>c>>f;
                if(c>=k){
                    if(result==0){
                        result=f;
                    }
                    else{
                        result=result+f-result*f;
                    }
                }
            }
            cout<<min(result,(ld)1)<<endl;
        }
    }
    return 0;
}