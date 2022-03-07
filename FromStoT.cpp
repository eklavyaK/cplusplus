#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int tc;cin>>tc;
	while(tc-->0)
	{
		string s,t,p; cin>>s>>t>>p;map<char,int> map;
		for(int i = 0; i<p.length(); i++)map[p[i]]++;
		int n = t.length(),track=0; bool detect = false;
		for(int i = 0; i<n; i++){
			if(s[track]!=t[i] && map[t[i]]<=0){
				detect = true; break;
			}
			else if(s[track]==t[i])track++;
			else{
				map[t[i]]--;
			}
		}
		if(track!=s.length())detect = true;
		detect?cout<<"NO"<<endl:cout<<"YES"<<endl;
	}
	return 0;
}