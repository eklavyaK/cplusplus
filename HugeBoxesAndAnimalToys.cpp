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
        int a,b,c,d; cin>>a>>b>>c>>d;
        if(!a && !b)
        {
            if(!c) cout<<"Tidak Tidak Tidak Ya"<<endl;
            else if(!d) cout<<"Tidak Tidak Ya Tidak"<<endl;
            else cout<<"Tidak Tidak Ya Ya"<<endl;
        }
        else if(!a && b)
        {
            if(b%2){
                if(!c && d) cout<<"Ya Ya Tidak Tidak"<<endl;
                else if(!d && c) cout<<"Tidak Ya Tidak Tidak"<<endl;
                else if(!c && !d) cout<<"Tidak Ya Tidak Tidak"<<endl;
                else cout<<"Ya Ya Tidak Tidak"<<endl;
            }
            else{
                if(!c && d) cout<<"Tidak Tidak Ya Ya"<<endl;
                else if(!d && c) cout<<"Tidak Tidak Ya Tidak"<<endl;
                else if(!c && !d) cout<<"Tidak Tidak Ya Tidak"<<endl;
                else cout<<"Tidak Tidak Ya Ya"<<endl;
            }
        }
        else if(!b && a)
        {
            if(a%2){
                if(!c && d) cout<<"Ya Tidak Tidak Tidak"<<endl;
                else if(!d && c) cout<<"Ya Ya Tidak Tidak"<<endl;
                else if(!c && !d) cout<<"Ya Tidak Tidak Tidak"<<endl;
                else cout<<"Ya Ya Tidak Tidak"<<endl;
            }
            else{
                if(!c && d) cout<<"Tidak Tidak Tidak Ya"<<endl;
                else if(!d && c) cout<<"Tidak Tidak Ya Ya"<<endl;
                else if(!c && !d) cout<<"Tidak Tidak Tidak Ya"<<endl;
                else cout<<"Tidak Tidak Ya Ya"<<endl;
            }
        }
        else if(a && b)
        {
            if((a+b)%2){
                cout<<"Ya Ya Tidak Tidak"<<endl;
            }
            else{
                cout<<"Tidak Tidak Ya Ya"<<endl;
            }
        }
    }
    return 0;
}