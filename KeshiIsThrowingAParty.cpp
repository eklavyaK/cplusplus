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
int n, a[200000],b[200000];
bool check(int k){
    int x = 0;
    for(int i = 0; i<n; i++){
        if(a[i]+1+x>=k && x<=b[i]){
            x++;
        }
    }
    return x>=k;
}
int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0){
        cin>>n;
        for(int i = 0; i<n; i++){
            cin>>a[i]>>b[i];
        }
        int r = n, l = 0;
        while(r>=l){
            int mid = (r+l)/2;
            if(check(mid))l=mid+1;
            else r=mid-1;
        }
        cout<<l-1<<endl;
    }
    return 0;
}
