#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        string s; cin>>s;
        int count_a = 0,count_onea = 0,count_b = 0,count_oneb = 0;
        for(int i = 0; i<10; i++)
        {
           if(i%2) {if(s[i]=='1') count_b++; else if(s[i]=='?') count_oneb++;}
           else {if(s[i]=='1') count_a++; else if(s[i]=='?') count_onea++;}
           if(i>4)
           {
                if(i%2)
                {    
                    if(count_a+count_onea>5-(i+1)/2+count_b) {cout<<i+1<<endl; break;}
                    else if(count_b+count_oneb>5-(i+1)/2+count_a) {cout<<i+1<<endl; break;}
                }
                else
                {
                    if(count_a+count_onea>5-i/2+count_b) {cout<<i+1<<endl; break;}
                    else if(count_b+count_oneb>5-i/2-1+count_a) {cout<<i+1<<endl; break;}
                }
           }
           if(i==9) cout<<10<<endl;
        }
    }
    return 0;
}