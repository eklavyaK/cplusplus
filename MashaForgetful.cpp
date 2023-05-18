#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

struct node{
    int l,r,c;
};
void code(){
    int n,m; cin>>n>>m;
    node f2[100]{}, f3[1000]{};
    int f[m]{}, ans[m]{};
    for(int i=0;i<n;i++){
        string s; cin>>s;
        for(int j=1;j<m;j++){
            f2[(s[j]-'0')+(s[j-1]-'0')*10] = {.l = j, .r = j+1, .c = i+1};
            if(j>1) f3[(s[j]-'0')+(s[j-1]-'0')*10 + (s[j-2]-'0')*100] = {.l = j-1, .r = j+1, .c = i+1};
        }
    }
    string s; cin>>s;
    for(int i=1;i<m;i++){
        if((i==1 || f[i-2]) && f2[(s[i]-'0')+(s[i-1]-'0')*10].c) f[i] = true, ans[i] = i-2;
        if((i!=1) && (i==2 || f[i-3]) && f3[(s[i]-'0')+(s[i-1]-'0')*10 + (s[i-2]-'0')*100].c) f[i] = true, ans[i] = i-3;
    }
    if(!f[m-1]){
        cout<<-1<<endl;
        return;
    }
    int curr = m-1;
    stack<node> st;
    while(curr>0){
        if(ans[curr]==curr-2) st.push(f2[(s[curr]-'0')+(s[curr-1]-'0')*10]);
        else st.push(f3[(s[curr]-'0')+(s[curr-1]-'0')*10 + (s[curr-2]-'0')*100]);
        curr = ans[curr];
    }
    cout<<st.size()<<endl;
    while(!st.empty()){
        auto [l,r,c] = st.top(); st.pop();
        cout<<l<<' '<<r<<' '<<c<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}