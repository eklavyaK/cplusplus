#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int n; cin>>n; string s; cin>>s;int count1=0,count2=0,res=0;
	for(int i = 0; i<n; i++) {if(s[i]=='(') count1++;else count2++;}
	if(count1!=count2)cout<<-1<<endl;
	else{
		count1=0;count2=0;
		bool detect = false;
		for(int i = 0; i<n; i++){
			if(s[i]=='(')count1++;
			else count2++;
			if(count2>count1){
				res++;detect = true;
			}
			else if(detect) {detect = false;res++;}
		}
		cout<<res<<endl;
	}

	return 0;
}