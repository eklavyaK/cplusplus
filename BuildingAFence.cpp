#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    rapid_iostream;
    int tc;cin>>tc;
    while(tc-->0){
        int n,k; cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int z = 0;
        bool c=(a[0]!=a[1]);
        bool d=(a[n-1]!=a[n-2]);
        vector<int> v;
        makeset(v,a,n);
        map<int,int> m;
        for(int i=0;i<n;i++){
            int y = 0;
            while(i+1<n && a[i]==a[i+1]){
                y=1;i++;
            }
            m[z]=y;z++;
        }
        vector<int> r;
        r.push_back(0);
        n=v.size();
        for(int i=1;i<n-1;i++){
            if(v[i]>v[i-1] && v[i]>v[i+1]){
                r.push_back(i);
            }
            else if(v[i]<v[i-1] && v[i]<v[i+1]){
                r.push_back(i);
            }
        }
        if(n>1)
        r.push_back(n-1);
        for(int i=1;i<r.size();i++){
            if(v[r[i]]>v[r[i-1]]){
                int curr_h=v[r[i-1]]+k-1;
                if(i==1&&c) curr_h=v[r[i-1]];
                for(int j=r[i-1]+1;j<=r[i];j++){
                    if(v[j]>curr_h+k-1){
                        N(); goto end;
                    }
                    else{
                        if(m[j])curr_h=v[j]+k-1;
                        else curr_h = min(curr_h+k-1,v[j]+k-1);
                    }
                }
            }
            else{
                int curr_h=v[r[i]]+k-1;
                if(i==r.size()-1 && d) curr_h=v[r[i]];
                for(int j=r[i]-1;j>=r[i-1];j--){
                    if(v[j]>curr_h+k-1){
                        N(); goto end;
                    }
                    else{
                        if(m[j])curr_h=v[j]+k-1;
                        else curr_h = min(curr_h+k-1,v[j]+k-1);
                    }
                }
            }
        }
        Y();
        end:;
    }
    return 0;
}