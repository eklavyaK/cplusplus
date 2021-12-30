#include <iostream>
#include <string>
using namespace std;
int main()
{
	long long int i;
	cin>>i;
	while(i>1)
	{
		int detect = 0;
		for(long long int j = 2;j<i;j++)
		{
			if(i%j==0)
			{detect = 1;break;}
		}
		if(detect == 1)
			cout<<"not prime"<<endl;
		else cout<<"prime"<<endl;
		cin>>i;
	}
	return 0;
}