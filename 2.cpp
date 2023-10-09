#include <bits/stdc++.h>
  using namespace std;
  
  vector<vector<vector<int>>> dp;
  string ans;
  
  void raam( string& s, int i, int ct, char ch){
    
    if(i==s.size()){
      // cout<<s<<endl;
      ans= min(ans,s);
      return;
    }
    
    if(dp[i][ct][ch-'a']!=-1) return;
    dp[i][ct][ch-'a']=0;
    
    
    if(s[i]=='?' && ((ch=='a' && ct<2) || (ch!='a'))){
      s[i]='a';
      int cnt= ( ch=='a') ? ct+1: 1;

      raam(s,i+1,cnt,'a');
      s[i]='?';
    } 
    
    //b daalo
    if(s[i]=='?' && ((ch=='b' && ct<2) || (ch!='b'))){
      s[i]='b';
      int cnt= ( ch=='b') ? ct+1: 1;
      raam(s,i+1,cnt,'b');

      s[i]='?';
    }
    
    //kuch na
    if(s[i]!='?' && ((ch==s[i] && ct<2) || (ch!=s[i]))){
      // cout<<s[i]<<" "<<i<<endl;
      int cnt= ( ch==s[i]) ? ct+1: 1;
      raam(s,i+1,cnt,s[i]);
    }
    
    return;
  }
  

  int main() {

    // int n;
    string s = "??bb?baab???";
    ans="z";
    dp.resize(s.size()+1,vector<vector<int>>(4, vector<int>(27,-1)));
    
    raam(s,0,0,'c');
    if(ans=="z") cout<<"-1"<<endl;
    else{
       cout<<ans<<endl;
    }
    
    // cin>>n;

  }