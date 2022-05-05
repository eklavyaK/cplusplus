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
        int n,x; cin>>n>>x; int a[n];
        for(int i = 0; i<n; i++)cin>>a[i];
        int c = *min_element(a,a+n);
        int b = *max_element(a,a+n);
        ll sum = 0;
        for(int i = 1; i<n; i++){
            sum+=abs(a[i]-a[i-1]);
        }
        if(a[0]==c || a[n-1]==c){
            sum+=(c-1);
        }
        else{
            sum+=min(min(a[0],a[n-1])-1,(c-1)*2);
        }
        if(b<x){
        if(a[0]==b || a[n-1]==b){
            sum+=(x-b);
        }
        else{
            sum+=min(x-max(a[0],a[n-1]),(x-b)*2);
        }
        }
        cout<<sum<<endl;
    }
    return 0;
}