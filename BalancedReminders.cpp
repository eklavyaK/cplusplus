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
        int c[3]={0};
        for(int i = 0; i<n; i++){
            c[a[i]%3]++;
        }
        n/=3;int cnt = 0;
        while(c[0]!=c[1] || c[0]!=c[2]){
            int temp = 0;
            if(c[2]>n){
                temp=(c[2]-n);
                c[0]+=temp;
                c[2]-=temp;
                cnt+=temp;
            }
            if(c[0]>n){
                temp=(c[0]-n);
                c[1]+=temp;
                c[0]-=temp;
                cnt+=temp;
            }
            if(c[1]>n){
                temp=(c[1]-n);
                c[2]+=temp;
                c[1]-=temp;
                cnt+=temp;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}