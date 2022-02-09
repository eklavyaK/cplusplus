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
        int W,H,x1,y1,x2,y2,w,h;cin>>W>>H>>x1>>y1>>x2>>y2>>w>>h;
        if((((y2-y1+h>H)?x2-x1:0)+w>W) || (((x2-x1+w>W)?y2-y1:0)+h>H)) cout<<-1<<endl;
        else 
        {
            int a = max(x1,W-x2), b = max(y1,H-y2);
            cout<<fixed<<setprecision(8);cout<<min((x2-x1+w<=W)?max(0,w-a):INT_MAX,(y2-y1+h<=H)?max(0,h-b):INT_MAX)<<endl;
        }
    }
    return 0;
}