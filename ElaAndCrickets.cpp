#include<iostream>
typedef long double ld;
typedef long long ll;
using namespace std;
int x, y;
int x0,yz,x1,yo,x2,yt;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cin>>x0>>yz>>x1>>yo>>x2>>yt;
        int xx,yy;
        cin>>xx>>yy;
        if((x0==x1||x0==x2)&&(yz==yo||yz==yt)){
            x = x0; y = yz;
        }
        else if((x1==x0||x1==x2)&&(yo==yz||yo==yt)){
            x = x1; y = yo;
        }
        else{
            x = x2; y = yt;
        }
        if((x==1 && (y==1||y==n))||(x==n && (y==1||y==n))){
            if(x==xx || y==yy)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else {if((abs(x-xx)&1)&&(abs(y-yy)&1))cout<<"NO"<<endl;
        else cout<<"YES"<<endl;}
    }
    return 0;
}