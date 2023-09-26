#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;

    

int n,cnt;string s;
vector<int> position(10);
vector<bool> present(10);
void compute(){
    for(int i=0;i<10;i++){
        for(int j=cnt;j<n;j++){
            if(s[j]-'0'==i){
                present[i] = 1;
                position[i] = j;
                cnt = j+1;
            }
        }
    }
}
int main(){
    int t; cin>>t;
    while(t--){
    fill(position.begin(),position.end(),0);
    fill(present.begin(),present.end(),0);
    vector<string> ans;
    cin>>s; cnt = 0;
    n = s.size();
    int done[n]{};
    int l = 0;
    compute();
    for(int i=0;i<10;i++){
        if(present[i]){cnt = 0;
        for(int j=l;j<=position[i];j++){
            if(s[j]-'0'==i){cnt++;done[j] = 1;}
        }
        l =  position[i]+1;
        ans.push_back(string(cnt,'0'+i));}
    }
    int c[10]{};
    for(int i=0;i<n;i++){
        if(!done[i])c[s[i]-'0']++;
    }
    for(int i=0;i<10;i++){
        ans.push_back(string(c[i],(i!=9?'0'+i+1:'9')));
    }
    sort(ans.begin(),ans.end());
    int k = ans.size();
    for(int i=0;i<k;i++){
        cout<<ans[i];
    }
    cout<<endl;
    }
}