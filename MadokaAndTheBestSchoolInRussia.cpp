#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;
vector<int> v; // this the global array declared which will store all the primes from
int counter;   // this is the actual number of primes stored in the array a after sieve is called using limits

int sieve(int lim1, int lim2)
{
	if (lim1 > lim2 || lim2 < 2)
	{
		cout << "Not a valid range!!" << endl;
		return 0;
	}
	else
	{
		if (lim1 <= 1)
			lim1 = 2;
		int range = lim2 - lim1 + 1;
		vector<int> primes(range);
		int multiplier = 0;
		for (int count = 2; count < lim2; count++)
		{
			int start = pow(count, 2);
			if (start > lim2)
				break;
			if (start < lim1)
			{
				if ((float)lim1 / count == lim1 / count)
					multiplier = lim1 / count;
				else
					multiplier = lim1 / count + 1;
				while (count * multiplier <= lim2)
				{
					if (primes[count * multiplier - lim1] != 1)
						primes[count * multiplier - lim1] = 1;
					multiplier++;
				}
			}
			else
			{
				multiplier = count;
				while (count * multiplier <= lim2)
				{
					if (primes[count * multiplier - lim1] != 1)
						primes[count * multiplier - lim1] = 1;
					multiplier++;
				}
			}
		}
		for (int i = lim1; i <= lim2; i++)
			if (primes[i - lim1] != 1)
			{
				v.emplace_back(i);
				counter++;
			}
		return 0;
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;sieve(1,100000);
    while(tc-->0)
    {
        int n,x,cnt = 0; cin>>x>>n;
        while(x%n==0){cnt++;x/=n;}
        if(cnt>1){
            int detect = 0,count=0;
            if(cnt==2){
                for(int i = 0; i<counter && v[i]<x; i++){
                    if(x%v[i]==0){detect=1;break;}
                }
                detect?cout<<"YES"<<endl:cout<<"NO"<<endl;
            }
            if(cnt>2){
                for(int i = 0; i<counter && x>v[i]; i++){
                    if(x%v[i]==0){detect = 1;break;}
                }
                if(detect){cout<<"YES"<<endl;continue;}
                int t = n,a = 0;
                for(int i = 0; i<counter && t>v[i]; i++){
                    if(n%v[i]==0){
                        count++;n/=v[i];a=v[i];
                        if(n%v[i]==0) n/=v[i];
                        if(n%v[i]==0)count++;
                    }
                    if(count>1){detect = 1;break;}
                }
                if(count==0){cout<<"NO"<<endl;continue;}
                if(x==1){if(count>0)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;continue;}
                if(count==1){if(a!=x)cout<<"YES"<<endl;
                else{if(cnt>3)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;}continue;}
                if(count>1){cout<<"YES"<<endl;}
            }
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}