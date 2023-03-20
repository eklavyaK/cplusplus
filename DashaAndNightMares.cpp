#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n; cin>>n;
    int ans = 0;
    unordered_map<vector<bool>,vector<int>> mp;
    set<vector<bool>> st;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        int m = s.size();
        vector<int> cnt(26);
        for(int j=0;j<m;j++){
            cnt[s[j]-'a']++;
        }
        vector<int> push(26);
        vector<bool> comp(26);
        for(int j=0;j<26;j++){
            if(cnt[j]&1) push[j]=1;
            else comp[j] = 1;
            if(!cnt[j]) push[j]=-1;
        }
        for(int j=0;j<26;j++){
            if(push[j]==-1){
                comp[j] = 0;
                if(st.count(comp))ans+=mp[comp][j];
                comp[j] = 1;
            }
        }
        vector<bool> ins(26);
        for(int j=0;j<26;j++)if(push[j]==1)ins[j] = 1;
        st.insert(ins);
        mp[ins].resize(26);
        for(int j=0;j<26;j++)if(push[j]==-1)mp[ins][j]++;
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}