#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int n; cin>>n; int vw=0,vb=0;
	string s;cin>>s;for(int i = 0; i<n; i++){
		if(s[i]=='W') vw++;
		else vb++;
	}
	vector<int> v;
	if(vb%2 && vw%2) cout<<-1<<endl;
	else if(vb==0 || vw==0) cout<<0<<endl;
	else{
		if(vw%2){
			bool t = false;
			for(int i = 0; i<n-1; i++){
				if(t && s[i]=='W' && s[i+1]=='B') {v.emplace_back(i+++1);t=false;}
				else if(t && s[i]=='W' && s[i+1]=='W') v.emplace_back(i+1);
				else if(s[i]=='B' && s[i+1]=='W') {v.emplace_back(i+1);t=true;}
				else if(s[i]=='B' && s[i+1]=='B'){v.emplace_back(i+++1);t=false;}
			}
		}
		else{
			bool t = false;
			for(int i = 0; i<n-1; i++){
				if(t && s[i]=='B' && s[i+1]=='W') {v.emplace_back(i+++1);t=false;}
				else if(t && s[i]=='B' && s[i+1]=='B') v.emplace_back(i+1);
				else if(s[i]=='W' && s[i+1]=='B') {v.emplace_back(i+1);t=true;}
				else if(s[i]=='W' && s[i+1]=='W'){v.emplace_back(i+++1);t=false;}
			}
		}
		cout<<v.size()<<endl;
		for(auto i : v) cout<<i<<" ";cout<<endl;
	}

	return 0;
}