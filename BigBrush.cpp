#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
typedef long long ll;
typedef long double ld;
using namespace std;

vector<pair<int,int>> c({{0,0},{1,0},{0,1},{1,1}});
void code(){
    int n,m; cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    stack<pair<int,pair<int,int>>> st;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>arr[i][j];
    }
    set<int> s;
    function<bool(int,int)> check = [&](int i, int j){
        s.clear();
        for(auto [x,y] : c) if(arr[i+x][j+y]) s.insert(arr[i+x][j+y]);
        return s.size()==1;
    };
    queue<pair<int,int>> q;
    function<void(int,int)> dfs = [&](int i, int j){  
        function<void(int,int)> call = [&](int i, int j){
            for(int k=0;k<4;k++) if(arr[i+c[k].F][j+c[k].S]) arr[i+c[k].F][j+c[k].S] = 0, q.push({i+c[k].F,j+c[k].S});
        };
        if(i>0 && j>0 && check(i-1,j-1)) st.push({*s.begin(),{i-1,j-1}}),call(i-1,j-1);
        if(i<n-1 && j<m-1 && check(i,j)) st.push({*s.begin(),{i,j}}),call(i,j);
        if(i>0 && j<m-1 && check(i-1,j)) st.push({*s.begin(),{i-1,j}}),call(i-1,j); 
        if(i<n-1 && j>0 && check(i,j-1)) st.push({*s.begin(),{i,j-1}}),call(i,j-1);
    };
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            if(arr[i][j] && arr[i][j]==arr[i+1][j] && arr[i][j]==arr[i][j+1] && arr[i][j]==arr[i+1][j+1]) dfs(i,j);
            while(!q.empty()){
                auto [x,y] = q.front(); q.pop();
                dfs(x,y);
            }
        }
    }
    bool ans = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]){
                cout<<-1<<endl;
                return;
            }
        }
    }
    cout<<st.size()<<endl;
    while(!st.empty()){
        auto X = st.top(); st.pop();
        cout<<X.S.F+1<<' '<<X.S.S+1<<' '<<X.F<<endl;
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1; while(t--)code();
    return 0;
}