#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        string s; cin>>s; int ucount=0,dcount=0,rcount=0,lcount=0;
        for(int i = 0; i<s.size(); i++) 
        {
            if(s[i]=='D') dcount++;
            else if(s[i]=='U') ucount++;
            else if(s[i]=='R') rcount++;
            else lcount++;
        }
        if((dcount == 0|| ucount==0) && (rcount ==0 || lcount==0)) cout<<0<<'\n'<<endl;
        else if(dcount>0 && ucount>0 && rcount>0 && lcount>0)
        {
            ucount = min(ucount,dcount);
            rcount = min(rcount,lcount);cout<<(2*(ucount+rcount))<<endl;
            for(int i = 0; i<ucount; i++) cout<<'U';
            for(int i = 0; i<rcount; i++) cout<<'R';
            for(int i = 0; i<ucount; i++) cout<<'D';
            for(int i = 0; i<rcount; i++) cout<<'L';
            cout<<endl;
        }
        else if(rcount==0 || lcount==0) cout<<2<<'\n'<<"UD"<<endl;
        else cout<<2<<'\n'<<"RL"<<endl;
    }
    return 0;
}