#include<bits/stdc++.h>
using namespace std;

int main(){
int t; cin>>t;
while(t--){
string s = "codeforces";
int n = s.size();
char c; cin>>c;
for(int i=0;i<n;i++){
if(s[i]==c){
cout<<"YES"<<endl;
goto end;}
}
cout<<"NO"<<endl;
end:;
}
}
