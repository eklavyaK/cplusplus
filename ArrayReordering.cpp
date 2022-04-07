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
        int n; cin>>n; int a[n];
        for(int i = 0; i<n; i++)cin>>a[i];
        vector<int> v;int k = 0;
        for(int i = 0; i<n; i++){
            if(a[i]%2)v.push_back(a[i]);
            else k++;
        }
        sort(v.begin(),v.end());
        n=v.size();int cnt = 0;
        for(int i = 0; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                if(gcd(v[j],v[i])>1)cnt++;
            }
        }
        cout<<k*n+k*(k-1)/2+cnt<<endl;
    }
    return 0;
}