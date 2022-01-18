#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        string s,result = ""; cin>>s;int i;
        int index=0;
        for(i = 0; i<s.length()-1; i++)
            if((s[i]+s[i+1]-96)>=10) index = i;
        cout<<(s.substr(0,index)+to_string(s[index]+s[index+1]-96)+s.substr(index+2))<<endl;
    }
    return 0;
}