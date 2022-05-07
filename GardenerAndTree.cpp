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
int l,r;
int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0){
        int n,k; cin>>n>>k;int c[n+1]={0};
        vector<map<int,int>> v(n+1);
        for(int i = 0; i<n-1; i++){
            cin>>l>>r;
            c[r]++;c[l]++;
            v[r][l]=1;
            v[l][r]=1;
        }
        queue<int> q;int cnt = n;
        for(int i = 1; i<=n; i++){
            if(c[i]==1){
                q.push(i);
            }
            else if(c[i]==0){
                cnt--;
            }
        }
        for(int i = 0; i<k && !q.empty(); i++){
            int t = q.size();cnt-=t;
            for(int j = 0; j<t; j++){
                int f = q.front();q.pop();
                if(!v[f].size())continue;
                int r = v[f].begin()->first;
                v[r].erase(f);if(v[r].size()==1){
                    q.push(r);
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}