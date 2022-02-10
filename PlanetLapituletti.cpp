#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int h,m; cin>>h>>m; string s,hour,minute,check="01258"; cin>>s;
        int x = stoi(s.substr(0,s.find(':'))), y = stoi(s.substr(s.find(':')+1));
        while(true)
        {
            hour = x<10?'0'+to_string(x): to_string(x), minute = y<10? '0'+to_string(y):to_string(y);
            if(check.find(hour[0]) != -1 && check.find(hour[1]) != -1 &&check.find(minute[0]) != -1 && check.find(minute[1]) != -1)
            {
                s = hour+':'+minute;
                char temp = hour[0]; hour[0] = (hour[1]=='2'||hour[1]=='5')? hour[1]=='2'?'5':'2':hour[1];
                hour[1] = (temp=='2'||temp=='5')? temp=='2'?'5':'2':temp; temp = minute[0];
                minute[0] = (minute[1]=='2'||minute[1]=='5')? minute[1]=='2'?'5':'2':minute[1];
                minute[1] = (temp=='2'||temp=='5')? temp=='2'?'5':'2':temp;
                if(stoi(hour)<m && stoi(minute)<h){cout<<s<<endl; break;}
            }
            y=(y+1)%m; if(!y) x=(x+1)%h;
        }
    }
    return 0;
}