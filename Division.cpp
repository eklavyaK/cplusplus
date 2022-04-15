#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
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
    int tc;cin>>tc;
    sieve(2,31623);
    while(tc-->0){
        ll p,q;
        cin>>p>>q;
        if(p%q!=0){
            cout<<p<<endl;
        }
        else{
            map<int,int> m;
            ll result = p, c = p;
            for(int i = 0; i<counter && q!=1; i++){
                while(q%v[i]==0){
                    m[v[i]]++;
                    q/=v[i];
                }
            }
            if(q>1){
                m[q]=1;
            }
            for(auto i : m){
                int k = 0;ll temp = 1;
                while(p%i.first==0){
                    p/=i.first;k++;
                    if(k>i.second-1){
                        temp*=i.first;
                    }
                }
                result=min(result,temp);
            }
            cout<<c/result<<endl;
        }
    }
    return 0;
}