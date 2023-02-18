#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;


map<char,int> m;
void code(){
    int n; cin>>n;
    m['i']=0,m['n']=1,m['w']=2;
    vector<pair<int,int>> p(3);
    p[0]={1,2},p[1]={0,2},p[2]={0,1};
    vector<vector<int>> v(6);
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        sort(s.begin(),s.end());
        if(s[0]==s[1] && s[0]==s[2]){
            v[m[s[0]]*2].push_back(i);
            v[m[s[0]]*2+1].push_back(i);
        }
        else if(s[0]==s[1]){
            if(m[s[2]]==p[m[s[0]]].F)v[m[s[0]]*2+1].push_back(i);
            else v[m[s[0]]*2].push_back(i);
        }
        else if(s[1]==s[2]){
            if(m[s[0]]==p[m[s[1]]].F)v[m[s[1]]*2+1].push_back(i);
            else v[m[s[1]]*2].push_back(i);
        }
    }
    vector<pair<int,int>> pos;
    vector<pair<char,char>> letters;
    vector<int> idx(6),next({1,0,3,2,5,4});
    vector<pair<char,char>> exchange({{'i','n'},{'i','w'},{'n','i'},{'n','w'},{'w','i'},{'w','n'}});
    vector<pair<int,int>> supplier({{2,3},{4,5},{0,1},{4,5},{0,1},{2,3}});
    for(int j=0;j<6;j++){
        auto [x,y] = supplier[j];
        for(;idx[j]<v[j].size();idx[j]++){
            if(idx[x]<v[x].size()){
                pos.push_back({v[j][idx[j]],v[x][idx[x]]});
                letters.push_back(exchange[j]);
                idx[x]++;
            }
            else if(idx[y]<v[y].size()){
                pos.push_back({v[j][idx[j]],v[y][idx[y]]});
                letters.push_back(exchange[j]);
                v[next[j]].push_back(v[y][idx[y]]);
                idx[y]++;
            }
        }
    }
    n = pos.size();
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<pos[i].F<<' '<<letters[i].F<<' '<<pos[i].S<<' '<<letters[i].S<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}