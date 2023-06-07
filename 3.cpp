#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

vector<string> start({"(()","(((","())","()(",")()",")((",")))","))("});
vector<string> end({"))(",")))",")((",")()","()(","())","(((","(()"});
void code(){
    int n,q; cin>>n>>q;
    map<char,int> m;
    m['('] = 1, m[')'] = -1;
    string s; cin>>s;
    while(q--){
        int k; cin>>k;
        k--;
        s[k] = s[k]==')'?'(':')';
        cout<<s<<endl;
        if(n==1) cout<<"NO"<<endl;
        else if(n==2 && s=="()") cout<<"YES"<<endl;
        else if(n==2) cout<<"NO"<<endl;
        else{
            int l = 0, r = 0;
            for(int i=0;i<3;i++) l+=m[s[i]];
            for(int i=n-1;i>=n-3;i--) r+=m[s[i]];
            if(l>0 && r<0 && s[0]=='(' && s[n-1]==')') cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1; while(t--)code();
    return 0;
}