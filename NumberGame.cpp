#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;
/*from 1 to 100000 (1 lakh) there are 9592 prime numbers, these primes numbers can divide each and every composite number from 1 to
10000000000 (10^10)*/
vector<int> v; // this is the global array declared which will store all the primes from t to u (both included)
int counter;   // this is the actual number of primes stored in the array a after sieve is called using limits
int sieve(int t, int u){
    if(t>u||u<2){
        cout<<"Check the order of the range limits and make sure range contains at least one prime number."<<endl;
        return 0;
    }
    if(t<=1) t=2;
    int range=(u-t+1);
    vector<int> primes(range);
    int c = 0;
    for(int cnt=2; cnt<u; cnt++){
        int start=pow(cnt, 2);
        if(start>u) break;
        if(start<t){
            if (((float)t/cnt)==(t/cnt)) c=(t/cnt);
            else c=(t/cnt)+1;
            while(cnt*c<=u){
                if(primes[cnt*c-t]!=1) primes[cnt*c-t]=1;
                c++;
            }
        }
        else{
            c=cnt;
            while(cnt*c<=u){
                if(primes[cnt*c-t]!=1) primes[cnt*c-t]=1;
                c++;
            }
        }
    }
    for(int i=t; i<=u; i++){
        if(primes[i-t]!=1){
            v.emplace_back(i);
            counter++;
        }
    }
    return 0;
}
void start_again(){
    v.clear();counter=0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    sieve(3,100000);
    int tc;cin>>tc;
    while(tc-->0){
        int n; cin>>n;
        if(n==1){
            cout<<"FastestFinger"<<endl;
        }
        else if(n%2){
            cout<<"Ashishgup"<<endl;
        }
        else{
            if(n==2){
                cout<<"Ashishgup"<<endl;
            }
            else{
                int cnt=0;
                while(n>1 && n%2==0){n/=2;cnt++;}
                if(n==1){
                    cout<<"FastestFinger"<<endl;
                }
                else if(cnt!=1){
                    cout<<"Ashishgup"<<endl;
                }
                else{
                    int t = sqrt(n);
                    for(int i = 0; i<counter && v[i]<=t; i++){
                        if(n%v[i]==0){
                            cout<<"Ashishgup"<<endl;
                            goto end;
                        }
                    }
                    cout<<"FastestFinger"<<endl;
                    end:;
                }
            }
        }
    }
    return 0;
}