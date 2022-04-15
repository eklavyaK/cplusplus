#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0){vector<array<int,6>> v;
        int n,m; cin>>n>>m; string s[n];
        for(int i = 0; i<n; i++)cin>>s[i];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(s[i][j]=='1'){
                    array<int,6> arr;
                    if(i+1<n && j+1<m){
                        arr[0]=i;arr[1]=j;
                        arr[2]=i;arr[3]=j+1;
                        arr[4]=i+1;arr[5]=j;
                        v.push_back(arr);
                        arr[4]=i+1;arr[5]=j+1;
                        v.push_back(arr);
                        arr[2]=i+1;arr[3]=j;
                        v.push_back(arr);
                    }
                    else if(i+1<n){
                        arr[0]=i;arr[1]=j;
                        arr[2]=i;arr[3]=j-1;
                        arr[4]=i+1;arr[5]=j;
                        v.push_back(arr);
                        arr[4]=i+1;arr[5]=j-1;
                        v.push_back(arr);
                        arr[2]=i+1;arr[3]=j;
                        v.push_back(arr);
                    }
                    else if(j+1<m){
                        arr[0]=i;arr[1]=j;
                        arr[2]=i;arr[3]=j+1;
                        arr[4]=i-1;arr[5]=j+1;
                        v.push_back(arr);
                        arr[4]=i-1;arr[5]=j;
                        v.push_back(arr);
                        arr[2]=i-1;arr[3]=j+1;
                        v.push_back(arr);   
                    }
                    else{
                        arr[0]=i;arr[1]=j;
                        arr[2]=i;arr[3]=j-1;
                        arr[4]=i-1;arr[5]=j;
                        v.push_back(arr);
                        arr[4]=i-1;arr[5]=j-1;
                        v.push_back(arr);
                        arr[2]=i-1;arr[3]=j;
                        v.push_back(arr);
                    }
                }
            }
        }
        cout<<v.size()<<endl;
        for(auto i : v){
            cout<<i[0]+1<<' '<<i[1]+1<<' '
            <<i[2]+1<<' '<<i[3]+1<<' '
            <<i[4]+1<<' '<<i[5]+1<<'\n';
        }
    }
    return 0;
}