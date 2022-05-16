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

map<int,vector<int>> graph;
ll f[100001][2]; vector<int> check(100001);
vector<array<int,2>> arr(100001);
void dfs(int x, int y){
    for(auto it = graph[x].begin(); it!=graph[x].end(); it++){
        if(*it!=y){
            dfs(*it,x);
            f[x][1]+=max(f[*it][1]+abs(arr[x][1]-arr[*it][1]),f[*it][0]+abs(arr[x][1]-arr[*it][0]));
            f[x][0]+=max(f[*it][1]+abs(arr[x][0]-arr[*it][1]),f[*it][0]+abs(arr[x][0]-arr[*it][0]));
        }
    }
}
int main(){
    rapid_io;
    int tc;cin>>tc;
    while(tc-->0){
        graph.clear();int n; cin>>n;
        for(int i = 1; i<=n; i++){
            cin>>arr[i][0]>>arr[i][1];
            f[i][0]=0;f[i][1]=0;
        }
        for(int i = 0; i<n-1; i++){
            int l , r; cin>>l>>r;
            graph[l].push_back(r);
            graph[r].push_back(l);
        }
        dfs(1,0); cout<<max(f[1][1],f[1][0])<<endl;
    }
    return 0;
}