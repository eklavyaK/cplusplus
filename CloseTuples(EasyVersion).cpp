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
        sort(a,a+n); 
        int cnt=0,c=0;
        ll result = 0;
        map<int,int> m;
        for(int i = 0; i<n; i++){
            if(a[i]-a[c]>2){
                if(i-c>=3)
                m[c]=i-1;c++;
                while(a[i]-a[c]>2)c++;
            }
        }
        if(a[n-1]-a[c]<=2 && n-c>=3){
            m[c]=n-1;
        }
        if(m.size()==0){
            cout<<0<<endl;
            continue;
        }
        map<int,int>:: iterator it=m.begin();
        int k = it->second-it->first+1;
        c=it->second;it++;
        if(k>=3){
            result+=(ll)(k-1)*(k-2)*k/6;
        }
        for(;it!=m.end(); it++){
            k=it->second-it->first+1;
            result+=(ll)(k-1)*(k-2)*k/6;
            if(c-it->first+1>=3){
                int f = c-it->first+1;
                result-=(ll)(f-2)*(f-1)*f/6;
            }
            c=it->second;
        }
        cout<<result<<endl;
    }
    return 0;
}