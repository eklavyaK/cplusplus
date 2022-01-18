#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n,detect = 1; cin>>n;string s; cin>>s;
        string temp = s;sort(s.begin(),s.end()); char min = '`';
        for(int i = 0; i<n; i++) {if(s[i]-min==1) min = s[i]; else if(s[i]-min>1){detect = 0;break;}}
        if(min!='z'){cout<<char(min+1)<<endl; continue;}
        string mins = "aa";
        for(int i = 0; i<n-1; i++) if(temp[i]==mins[0] && temp[i+1]==mins[1]){if(mins[1]=='z') {mins[0] = char(mins[0]+1);mins[1] = 'a';} else mins[1] = mins[1]+1; i = -1;}
        if(mins != "{a") {cout<<mins<<endl; continue;}
        mins = "aaa";
        for(int i = 0; i<n-2; i++)
        {
            if(temp[i]==mins[0]&&temp[i+1]==mins[1]&&temp[i+2]==mins[2])
            {
                if(mins[1]=='z'){mins[0]=mins[0]+1;mins[1]='a';mins[2]='a';}
                else if(mins[2]=='z'){mins[1]=mins[1]+1;mins[2]='a';}
                else mins[2]=mins[2]+1;
                i=-1;
            }
        }
        cout<<mins<<endl;
    }
    return 0;
}