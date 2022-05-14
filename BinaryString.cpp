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
int cnt0[200001],cnt1[200001];
string s;int c0,c1,n,result;
bool check(int k){
    int l=0, r=0;
    for(int i = 0; i<n; i++){
        if(s[i]=='1'){
            l=i;break;
        }
    }
    for(int i = l; i<n; i++){
        if(s[i]=='1' && c1-(cnt1[i]-cnt1[l]+1)<=k){
            r=i;break;
        }
    }
    int x = cnt0[r]-cnt0[l];
    while(x>k){
        l++;r++;
        while(l<n && s[l]=='0'){
            l++;
        }
        while(r<n && s[r]=='0'){
            r++;
        }
        if(r>=n || l>=n)break;
        x = cnt0[r]-cnt0[l];
    }
    return x<=k;
}
int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc; int d=0;
    while(tc-->0){
        n; cin>>s;
        n = s.length();
        c1=0,c0=0;
        for(int i = 0; i<n; i++){
            if(s[i]=='1'){
                c1++;
            }
            else c0++;
            cnt0[i]=c0;
            cnt1[i]=c1;
        }
        if(c1==0 || c0==0){
            cout<<0<<endl;continue;
        }
        int l = 0, r = c0;
        int mid = r;
        while(l<=r){
            if(check(mid))r=mid-1;
            else l=mid+1;
            mid = (l+r)/2;
        }
        cout<<r+1<<endl;
    }
    return 0;
}