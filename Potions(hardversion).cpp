#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
#define rapid_io ios_base::sync_with_stdio(0);cin.tie(0)
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    rapid_io;
    int n; cin>>n;
    int a[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    ll sum = 0, cnt = 0;
    priority_queue<int> q;
    for(int i = 0; i<n; i++){
        if(a[i]<0){
            if(a[i]+sum>=0){
                sum+=a[i];cnt++;
                q.push(-a[i]);
            }
            else{
                if(q.empty())
                    continue;
                ll k = q.top();
                if(k+a[i]>0){
                    q.pop();q.push(-a[i]);
                    sum+=(k+a[i]);
                }
            }
        }
        else{
            sum+=a[i];cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}