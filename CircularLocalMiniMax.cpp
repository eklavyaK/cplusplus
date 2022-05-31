#include<bits/stdc++.h>
#define mp make_pair
#define mod2 998244353ll
#define mod1 1000000007ll
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
#define print(n) cout<<n<<endl;
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    rapid_iostream;
    int tc;cin>>tc;
    while(tc-->0){
        int n; cin>>n; int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        if(n%2){N();continue;}
        sort(a,a+n);
        vector<int> l(n/2),m(n/2);
        for(int i=0;i<n;i++){
            if(i<n/2)l[i]=a[i];
            else m[i-n/2]=a[i];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(i%2)ans[i]=m[i/2];
            else ans[i]=l[i/2];
        }
        for(int i=1;i<n-1;i++){
            if(!((ans[i]>ans[i-1] && ans[i]>ans[i+1])||(ans[i]<ans[i-1] && ans[i]<ans[i+1]))){N();goto end;}
        }
        Y();for(auto i : ans) cout<<i<<' ';cout<<endl;end:;
    }
    return 0;
}