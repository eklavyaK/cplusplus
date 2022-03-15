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
        int n; cin>>n;int cnt[5];
        vector<array<int,5>> v(n);
        for(int i = 0; i<n; i++){
            cin>>v[i][0]>>v[i][1]>>v[i][2]>>v[i][3]>>v[i][4];
            if(v[i][0]==1)cnt[0]++;
            if(v[i][1]==1)cnt[1]++;
            if(v[i][2]==1)cnt[2]++;
            if(v[i][3]==1)cnt[3]++;
            if(v[i][4]==1)cnt[4]++;
        }
        if(n%2){cout<<"NO"<<endl;continue;}
        for(int i = 0; i<5; i++){
            for(int j = i+1; j<5; j++){
                if(cnt[i]>=n/2 && cnt[j]>=n/2){
                    int k=0,l=0,m=0;
                    for(int a = 0; a<n; a++){
                        if(v[a][i]==1 && v[a][j]==0){
                            k++;
                        }
                        else if(v[a][i]==0 && v[a][j]==1){
                            l++;
                        }
                        else if(v[a][i]==1 && v[a][j]==1){
                            m++;
                        }
                    }
                    k=min(k,n/2);l=min(l,n/2);
                    if(l+k+m==n){goto print;}
                }
            }
        }
        cout<<"NO"<<endl;continue;
        print:cout<<"YES"<<endl;
    }
    return 0;
}