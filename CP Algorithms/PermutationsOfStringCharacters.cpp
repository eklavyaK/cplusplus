#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);

	string initial; cin>>initial; int n = initial.length();
	int total = 1; for(int i = 2; i<=n; i++) total*=i;
	string s[total];s[0]=initial;int track = 1;
	for(int i = 1; i<n; i++){      
		int t = track;
		for(int j = 0; j<t; j++){
			for(int k = 0; k<i; k++){
				string st = s[j];
				char temp = st[i];
				st[i]=st[k];
				st[k]=temp;
				s[track++]=st;
			}
		}
	}
	for(auto i : s) cout<<i<<endl;
	
	return 0;
}