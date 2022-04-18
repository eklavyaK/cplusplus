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
int a[1001];
int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int n,x,pos,mid;
    int cl = 0, cg = 0;
    cin>>n>>x>>pos;
    int l=0,r=n;
    while(l<r){
        mid=(l+r)/2;
        if(mid<=pos){
            cl++;
            l=mid+1;
        }
        else{
            cg++;
            r = mid;
        }
    }
    if(l-1==pos)cl--;
    ll result = 1l;
    int k = n-cg-cl-1;
    for(int i=k;i>=2;i--){
        result=(result*i)%mod1;
    }
    k = x-1; if(k-cl<0){
        cout<<0<<endl; 
        exit(0);
    }
    for(int i = 0; i<cl && k>1; i++){
        result=(result*k--)%mod1;
    }
    k = n-x;if(k-cg<0){
        cout<<0<<endl;
        exit(0);
    }
    for(int i = 0; i<cg && k>1; i++){
        result=(result*k--)%mod1;
    }
    cout<<result<<endl;
    return 0;
}