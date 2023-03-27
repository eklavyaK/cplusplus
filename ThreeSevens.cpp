#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int m; cin>>m;
    set<int> st;
    st.insert(0);
    vector<vector<int>> a(m);
    vector<vector<int>> v(m);
    for(int i=0;i<m;i++){
        int k; cin>>k;
        a[i].resize(k);
        while(k--){
            int c; cin>>c;
            v[i].push_back(c);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<v[i].size();j++){
            if(st.count(v[i][j]))a[i][j] = -1;
            else st.insert(v[i][j]);
        }
    }
    st.clear();
    st.insert(0);
    for(int i=m-1;i>=0;i--){
        for(int j=0;j<v[i].size();j++){
            if(st.count(v[i][j]))a[i][j] = 1;
            else st.insert(v[i][j]);
        }
    }
    vector<int> ans;
    st.clear();
    st.insert(0);
    for(int i=0;i<m;i++){
        bool f = false;
        for(int j=0;j<a[i].size();j++){
            if(a[i][j]==-1){
                ans.push_back(v[i][j]);
                f = true;
                break;
            }
        }
        if(!f){
            for(int j=0;j<a[i].size();j++){
                if(!a[i][j]){
                    ans.push_back(v[i][j]);
                    f = true;
                    break;
                }
            }
        }
        if(!f){
            cout<<-1<<endl;
            return;
        }
    }
    for(auto i : ans) cout<<i<<' ';cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}