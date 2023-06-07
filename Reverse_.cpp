#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

bool check(string s, string f){
    int n = s.size(), m = f.size();
    for(int i=0;i<=m-n;i++){
        bool c = true;
        for(int j=i;j<i+n;j++){
            if(s[j-i]!=f[j]){
                c = false; break;
            }
        }
        if(c && f.substr(i+n)==string(m-i-n,'1'))return true;
        if(f[i]=='0')break;
    }
    return false;
}

void code(){
    int x, y; cin>>x>>y;
    if(x==y){
        cout<<"YES"<<endl;
        return;
    }
    else if(!(y&1)){
        cout<<"NO"<<endl;
        return;
    }
    string s = bitset<64>(x).to_string();
    string t = bitset<64>(y).to_string();
    int n = s.size(), m = t.size();
    t = t.substr(t.find("1"));
    s = s.substr(s.find("1"));
    string s0 = s+"1";
    reverse(s.begin(),s.end());
    s = s.substr(s.find("1"));
    string s1 = s0, s2 = s;
    reverse(s.begin(),s.end());
    reverse(s0.begin(),s0.end());
    if(check(s,t)||check(s0,t)||check(s1,t)||check(s2,t)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1; while(t--)code();
    return 0;
}