#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
string compute(string s, int n, int f){
    string shift = "";
    if(f<0) shift = string(-f,'0')+s.substr(0,n+f);
    else shift = s.substr(f)+string(f,'0');
    for(int i=0;i<n;i++){
        s[i] = '0'+((s[i]-'0')^(shift[i]-'0'));
    }
    return s;
}
void code(){
    int n; cin>>n;
    string a, b;
    cin>>a>>b;
    if((a==string(n,'0')||b==string(n,'0'))&&a!=b){
        cout<<-1<<endl;
        return;
    }
    string now = a;
    bool f = false;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(a[i]==b[i])continue;
        int x = 0;
        for(int j=0;j<n;j++){
            if(a[j]=='1'){
                x = j; break;
            }
        }
        if(x-i==0)continue;
        ans.push_back(x-i);
        a = compute(a,n,ans.back());
    }
    for(int i=n-1;i>=0;i--){
        if(a[i]==b[i])continue;
        int x = 0;
        for(int i=n-1;i>=0;i--){
            if(a[i]=='1'){
                x = i; break;
            }
        }
        ans.push_back(x-i);
        a = compute(a,n,ans.back());
    }   
    cout<<ans.size()<<endl;
    for(auto i : ans) cout<<i<<' ';cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}