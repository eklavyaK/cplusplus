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
    if(s.size()==1){
        if(s=="X"||s=="_"||s=="0")cout<<1<<endl;
        else cout<<0<<endl;
        return;
    }
    int x = 1, n = s.size();
    if((s[n-1]!='_'&&s[n-1]!='0'&&s[n-1]!='5'&&s[n-1]!='X') || s[0]=='0' ||
    (s[n-2]!='_'&&s[n-2]!='0'&&s[n-2]!='5'&&s[n-2]!='X'&&s[n-2]!='7'&&s[n-2]!='2')){
        cout<<0<<endl;
        return;
    }
    if(s.size()==2){
        if(s=="XX")cout<<0<<endl;
        else if(s=="__"||s=="X_"||s=="_X")cout<<3<<endl;
        else if(s[1]=='5' && (s[0]=='X'||s[0]=='_') )cout<<2<<endl;
        else cout<<1<<endl;
        return;
    }
    else{
        int ans = 1;
        if(s.substr(n-2)=="XX" && s[0]!='X')ans = 1;
        else if(s.substr(n-2)=="XX" && s[0]=='X')ans = 0;
        else if(s.substr(n-2)=="_X" && s[0]=='X')ans = 2;
        else if(s.substr(n-2)=="X_" && s[0]=='X')ans = 3;
        else if(s.substr(n-2)=="__"||(s.substr(n-2)=="X_"||s.substr(n-2)=="_X"))ans = 4;
        else if(s[n-1]=='X'&&s[n-2]=='0'&&s[0]=='X')ans = 0;
        else if(s[n-1]=='X'&&s[n-2]=='5'&&s[0]=='X')ans = 1;
        else if(s[n-1]=='X')ans = 1;
        else if(s[n-2]=='X'&&s[n-1]=='0'&&s[0]=='X')ans=1;
        else if(s[n-2]=='X'&&s[n-1]=='5')ans=2;
        else if(s[n-2]=='X'&&s[n-1]=='0')ans=2;
        else if(s[n-1]=='_')ans=1;
        else if(s[n-2]=='_')ans=2;
        if(s[n-1]!='X'&&s[n-2]!='X'){
            if(s[0]=='X')ans*=9;
            else if(s.substr(1,n-2).find("X")!=-1)ans*=10;
        }
        for(int i=0;i<n-2;i++){
            if(s[i]=='_'){
                if(i==0)ans*=9;
                else ans*=10;
            }
        }
        cout<<ans<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}