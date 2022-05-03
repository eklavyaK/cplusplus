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
        int cnt = 0,r=0;
        int n;cin>>n;int a[n];bool c=true;
        for(int i = 0; i<n; i++)cin>>a[i];
        vector<int> v;
        for(int i = 0; i<n; i++){
            if(a[i]==0){
                if(r>0){
                    v.push_back(r);
                }
                r=0;
            }
            else r++;
        }
        if(r>0)v.push_back(r);
        n = v.size();
        if(a[0]){
            v[0]--;cnt++;
            cnt+=v[0]/3;
        }
        else if(n>0){
            cnt+=v[0]/3;
        }
        for(int i = 1; i<n; i++){
            cnt+=v[i]/3;
        }
        cout<<cnt<<endl;
    }
    return 0;
}