#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;
int result = 0;
string s;int k = 0;
vector<array<int,7>> v(7);
void dfs(int x, int y, int z){
    if(x==6 && y==0){
        if(z==48)result++;
        return;
    }
    else if(z==48)return;

    //making sure that if path touches the wall of the grid then it will divide the grid and it can choose to go only in one direction, so in other direction there must be all the ones and no zeros. This is done for optimization
    if(y==0){bool c=false,d=false;for(int i=0;i<x;i++)if(!v[i][y]){c=true;break;}for(int i=x+1;i<7;i++)if(!v[i][y]){d=true;break;}if(c&&d)return;}
    if(x==0){bool c=false,d=false;for(int i=0;i<y;i++)if(!v[x][i]){c=true;break;}for(int i=y+1;i<7;i++)if(!v[x][i]){d=true;break;}if(c&&d)return;}
    if(x==6){bool c=false,d=false;for(int i=0;i<y;i++)if(!v[x][i]){c=true;break;}for(int i=y+1;i<7;i++)if(!v[x][i]){d=true;break;}if(c&&d)return;}
    if(y==6){bool c=false,d=false;for(int i=0;i<x;i++)if(!v[i][y]){c=true;break;}for(int i=x+1;i<7;i++)if(!v[i][y]){d=true;break;}if(c&&d)return;}

    //making sure that there is no zero which is already enclosed and cannot be reached or even if it is possible to reach then there is no return from there. This is done to optimize the program
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if(v[i][j]==0){
                if(i==6 && j==0){            //for i==6 && j==0 assume there is a 0 at i==6 and j==-1 because we don't want to return back from it as it is the final target
                    if((i==0||v[i-1][j]) + (i==6||v[i+1][j]) + (j==6||v[i][j+1]) == 4)return;         
                    if((i==0||v[i-1][j]) + (i==6||v[i+1][j]) + (j==6||v[i][j+1]) == 3 && abs(x-i)+abs(y-j)>1)return;
                }
                else if((i==0||v[i-1][j]) + (j==0||v[i][j-1]) + (i==6||v[i+1][j]) + (j==6||v[i][j+1]) == 4)return;
                else if((i==0||v[i-1][j]) + (j==0||v[i][j-1]) + (i==6||v[i+1][j]) + (j==6||v[i][j+1]) == 3 && abs(x-i)+abs(y-j)>1)return;
            }
        }
    }
    if((s[z]=='?'||s[z]=='R') && y+1<7 && v[x][y+1]==0){
        v[x][y+1]=1;
        dfs(x,y+1,z+1);
        v[x][y+1]=0;
    }
    if((s[z]=='?'||s[z]=='D') && x+1<7 && v[x+1][y]==0){
        v[x+1][y]=1;
        dfs(x+1,y,z+1);
        v[x+1][y]=0;
    }
    if((s[z]=='?'||s[z]=='L') && y-1>=0 && v[x][y-1]==0){
        v[x][y-1]=1;
        dfs(x,y-1,z+1);
        v[x][y-1]=0;
    }
    if((s[z]=='?'||s[z]=='U') && x-1>=0 && v[x-1][y]==0){
        v[x-1][y]=1;
        dfs(x-1,y,z+1);
        v[x-1][y]=0;
    }
}
int main(){
    rapid_iostream;
    cin>>s;
    v[0][0]=1;
    dfs(0,0,0);
    cout<<result<<endl;              //program is correct if it gives 88418 as output on inputting ---> ????????????????????????????????????????????????
    return 0;
}