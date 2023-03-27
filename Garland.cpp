#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    string s; cin>>s;
    set<char> st;
    vector<int> cnt(10);
    for(int i=0;i<4;i++){
        st.insert(s[i]);
        cnt[s[i]-'0']++;
    }
    if(st.size()>2)cout<<4<<endl;
    else if(st.size()==2){
        if(cnt[*st.begin()-'0']==2){
            cout<<4<<endl;
        }
        else cout<<6<<endl;
    }
    else cout<<-1<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}