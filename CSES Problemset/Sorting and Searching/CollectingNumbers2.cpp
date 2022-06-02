#include<bits/stdc++.h>
#define mp make_pair
#define mod2 998244353ll
#define mod1 1000000007ll
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
#define print(n) cout<<n<<endl
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    rapid_iostream;
    int n,z; cin>>n>>z;
    int a[n],cnt=1;
    map<int,int> m;
    for(int i=0;i<n;i++)
    {cin>>a[i];m[a[i]]=i;}
    for(int i=2;i<=n;i++){
        if(m[i]<m[i-1]){
            cnt++;
        }
    }
    while(z--){
        int u,v;
        cin>>u>>v;
        u--;v--;
        int temp = a[u];
        a[u]=a[v];a[v]=temp;
        m[a[u]]=u;m[a[v]]=v;
        int x = min(u,v);
        int y = max(u,v);
        if(abs(a[x]-a[y])==1){
            if(a[x]>a[y]){
                cnt++;
                if(a[x]!=n && m[a[x]+1]>x && m[a[x]+1]<=y){
                    cnt--;
                }
                if(a[y]!=1 && m[a[y]-1]>=x && m[a[y]-1]<y){
                    cnt--;
                }
            }
            else{
                cnt--;
                if(a[x]!=1 && m[a[x]-1]>x && m[a[x]-1]<=y){
                    cnt++;
                }
                if(a[y]!=n && m[a[y]+1]>=x && m[a[y]+1]<y){
                    cnt++;
                }
            }
        }
        else{
            if(a[x]!=1 && m[a[x]-1]>x && m[a[x]-1]<=y){
                cnt++;
            }
            if(a[x]!=n && m[a[x]+1]>x && m[a[x]+1]<=y){
                cnt--;
            }
            if(a[y]!=1 && m[a[y]-1]>=x && m[a[y]-1]<y){
                cnt--;
            }
            if(a[y]!=n && m[a[y]+1]>=x && m[a[y]+1]<y){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
}