#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n; cin>>n;
    for(int i = 0; i<n; i++) 
    {
        int detect = 0;
        string s,t; cin>>s>>t;int index = 0;
        for(int i = 0; i<s.size();) 
        {
            char c = s[i];int counts=0,countt=0;while(i<s.size() && s[i]==c){counts++,i++;}
            while(index<t.size() && t[index]==c) {countt++;index++;}
            if(counts>countt) {detect = 1;break;}
        }
        if(detect||index!=t.size()) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

    return 0;
}