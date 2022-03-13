#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n,r=0,min=5; cin>>n;string s;cin>>s;
        bool detect = true;for(int i = 0; i<n; i++){
            if(s[i]=='a'){
                if(r){
                    if(i+2-r<min){
                        if(i+2-r<4){
                            min=i+2-r;
                            detect=false;
                        }
                        if(detect && i+2-r==4){
                            if(!((s[i-1]=='c'&&s[i-2]=='c')||(s[i-1]=='b'&&s[i-2]=='b'))){
                                min=4;detect=false;
                            }
                            else if(i+3<n && min!=7){
                                if(s[i-1]=='c'&&s[i-2]=='c'){
                                    if(s[i+1]=='b'&&s[i+2]=='b'&&s[i+3]=='a'){
                                        min=7;
                                    }
                                }
                                else if(s[i-1]=='b'&&s[i-2]=='b'){
                                    if(s[i+1]=='c'&&s[i+2]=='c'&&s[i+3]=='a'){
                                        min=7;
                                    }
                                }
                            }
                        }
                    }
                    r=i+1;
                }
                else r=i+1;
            }
        }
        min!=5?cout<<min<<endl:cout<<-1<<endl;
    }
    return 0;
}