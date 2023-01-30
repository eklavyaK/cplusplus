#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
string s;


void code(){
    cin>>s;
    set<char> st;
    int n = s.size();
    vector<char> order;
    vector<int> cnt(26);
    for(int i=n-1;i>=0;i--){
        int k = st.size();
        st.insert(s[i]);
        cnt[s[i]-'a']++;
        if(k!=st.size())
        order.push_back(s[i]);
    }
    reverse(order.begin(),order.end());
    int m = order.size();
    for(int i=0;i<m;i++){
        if(cnt[order[i]-'a']%(i+1)){
            cout<<-1<<endl;
            return;
        }
        else cnt[order[i]-'a']/=(i+1);
    }
    string ans = "";
    vector<int> c(26);
    for(int i=0;i<n;i++){
        c[s[i]-'a']++;
        if(c==cnt){ans = s.substr(0,i+1);break;}
    }
    if(ans==""){
        cout<<-1<<endl;
        return;
    }
    vector<bool> expell(26);
    int l = 0, k = ans.size();
    string construct(k,' ');
    for(int i=0;i<k;i++){
        construct[i] = ans[i];
    }
    for(int i=0;i<m;i++){
        expell[order[i]-'a'] = 1;
        for(int j=0;j<k;j++){
            if(expell[ans[j]-'a'])continue;
            else construct.push_back(ans[j]);
        }
    }
    if(construct!=s){
        cout<<-1<<endl;
        return;
    }
    cout<<ans<<' ';
    for(int i=0;i<m;i++)cout<<order[i];
    cout<<endl;
    
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}