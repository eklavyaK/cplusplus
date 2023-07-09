#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debugarr(a,n) 42
#define debug(...) 42
#endif





void code(int TC){
    string s; cin>>s;
    int n = s.size();
    int c[26]{}, all = 0;
    for(int i=0;i<n;i++) c[s[i]-'a']++;
    for(int i=0;i<26;i++){
        if(c[i]) all++;
        if(c[i]==1){
            cout<<(char)('a'+i);
            for(int j=0;j<26;j++){
                if(i==j || c[j]==0) continue;
                cout<<string(c[j],'a'+j);
            }
            cout<<endl;
            return;
        }
    }
    bool f = false;
    int cnt = 0, id = 0;
    for(int i=0;i<26;i++){
        if(c[i]==0) continue;
        if(!f){
            if(all == 1){
                cout<<string(n,'a'+i)<<endl;
                return;
            }
            cnt = c[i]-2;
            if(cnt>n-c[i]){
                if(all==2){
                    cout<<(char)('a'+i);
                    c[i]--;
                    for(int j=i+1;j<26;j++){
                        if(c[j]==0) continue;
                        cout<<string(c[j],'a'+j);
                        cout<<string(c[i],'a'+i);
                        cout<<endl;
                        return;
                    }
                }
                else{
                    cout<<(char)('a'+i);
                    c[i]--;
                    for(int j=i+1;j<26;j++){
                        if(c[j]==0) continue;
                        if(!f){
                            cout<<(char)('a'+j);
                            c[j]--;
                            cout<<string(c[i],'a'+i);
                            cnt = 0;
                            f = true;
                            continue;
                        }
                        c[j]--;
                        cout<<(char)('a'+j);
                        break;
                    }
                }
            }
            else cout<<string(2,'a'+i);
            id = i;
            f = true;
            continue;
        }
        for(int j=0;j<c[i];j++){
            if(cnt>0) cout<<(char)('a'+i)<<(char)('a'+id), cnt--;
            else cout<<(char)('a'+i);
        }
    }
    cout<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}