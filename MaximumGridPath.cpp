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
        bool c=false;ll result = LLONG_MAX;
        ll mv[n],mh[n],sv[n],sh[n];
        mv[0]=a[0];mh[0]=INT_MAX;
        sv[0]=a[0];sh[0]=0;
        for(int i = 1; i<n; i++){
            if(c){
                mv[i]=min(mv[i-1],(ll)a[i]);
                sv[i]=a[i]+sv[i-1];
                mh[i]=mh[i-1];
                sh[i]=sh[i-1];
            }
            else{
                mh[i]=min(mh[i-1],(ll)a[i]);
                sh[i]=a[i]+sh[i-1];
                mv[i]=mv[i-1];
                sv[i]=sv[i-1];
            }
            c=!c;
        }
        for(int i = 2; i<=n; i++){
            if(i%2){
                result=min(sh[i-1]+sv[i-1]+(n-i/2)*mh[i-1]+(n-i/2-1)*mv[i-1],result);
            }
            else result=min(sh[i-1]+sv[i-1]+(n-i/2)*mh[i-1]+(n-i/2)*mv[i-1],result);
        }
        cout<<result<<endl;
    }
    return 0;
}