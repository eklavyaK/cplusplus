#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

int add_dig(int n){
    int sum = 0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

void code(){
    string s; cin>>s;
    int n = s.size();
    bool  f = false;
    string a = "",b = "";
    for(int i=0;i<n;i++){
        if((s[i]-'0')&1){
            if(f){
                a.push_back((s[i]-'0')/2+'0');
                b.push_back((s[i]-'0')/2+1+'0');
                f = !f;
            }
            else {
                b.push_back((s[i]-'0')/2+'0');
                a.push_back((s[i]-'0')/2+1+'0');
                f = !f;
            }
        }
        else{
            a.push_back((s[i]-'0')/2+'0');
            b.push_back((s[i]-'0')/2+'0');
        }
    }
    cout<<stoi(a)<<' '<<stoi(b)<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}