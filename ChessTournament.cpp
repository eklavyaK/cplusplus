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
        int n; cin>>n; string s; cin>>s;
        int cnt1=0,cnt2=0;vector<int> v;
        for(int i = 0; i<n; i++){
            if(s[i]=='2'){cnt2++;v.push_back(i);}
        }
        if(cnt2==2 || cnt2==1)cout<<"NO"<<endl;
        else{
            int track = 1;
            cout<<"YES"<<endl;
            for(int i = 0; i<n; i++){
                if(s[i]=='1'){
                    for(int j = 0; j<n; j++){
                        if(i==j){cout<<'X';}
                        else cout<<'=';
                    }
                }
                else{
                    for(int j = 0; j<n; j++){
                        if(i==j){cout<<'X';}
                        else if(j==(track<cnt2?v[track]:v[0])){
                            cout<<'+';
                        }
                        else if(j==(track-2>=0?v[track-2]:v[cnt2-1])){
                            cout<<'-';
                        }
                        else cout<<'=';
                    }
                    track++;
                }
                cout<<endl;
            }
        }
    }
    return 0;
}