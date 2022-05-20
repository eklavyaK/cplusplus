#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    rapid_iostream;
    int tc;cin>>tc;
    while(tc-->0){
        ll result = 0;
        int n; cin>>n;
        int a[n],b[n],c[n];
        for(int i=0;i<n;i++){
            cin>>c[i];
        }
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        int cnt = 0;ll s = 0, w = 0;
        vector<vector<ll>> r(n);
        vector<vector<int>> f(n);
        s = abs(b[1]-a[1]);w+=s;
        vector<ll> tot(n);
        r[cnt].push_back(s);
        f[cnt].push_back(0);
        for(int i=2;i<n;i++){
            if(a[i]==b[i]){
                s=(1+c[i-1]);w+=s;
                r[cnt].push_back(s);
                f[cnt].push_back(i-1);
                tot[cnt]=w;cnt++;s=0;w=0;
                r[cnt].push_back(s);
                f[cnt].push_back(i-1);
            }
            else{
                s=(1-abs(a[i]-b[i])+c[i-1]);w+=s;
                r[cnt].push_back(s);
                f[cnt].push_back(i-1);
            }
        }
        s=(1+c[n-1]);w+=s;
        r[cnt].push_back(s);
        f[cnt].push_back(n-1);
        tot[cnt]=w;cnt++;
        for(int i=0;i<cnt;i++){
            int k = 0;
            result = max(tot[i],result);s=0;
            for(int j=0;j<f[i].size()-1;j++){
                s+=r[i][j];int in = f[i][j];
                if(s<abs(b[in+1]-a[in+1])){
                    result=max(result,s+abs(b[in+1]-a[in+1]));
                    s=abs(b[in+1]-a[in+1]);k=j;
                }
            }
            s+=r[i][f[i].size()-1];
            result=max(s,result);s=0;
            for(int j=f[i].size()-1;j>k;j--){
                s+=r[i][j];int in = f[i][j];
                if(j==f[i].size()-1)continue;
                if(s-r[i][j]<abs(b[in+1]-a[in+1])){
                    result=max(result,s-r[i][j]+abs(b[in+1]-a[in+1]));
                    s=c[in]+1;
                }
            }
            s+=abs(b[f[i][k]+1]-a[f[i][k]+1]);
            result=max(s,result);
        }
        cout<<result<<endl;
    }
    return 0;
}