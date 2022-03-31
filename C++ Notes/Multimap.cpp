#include<iostream>  /*********************************WILL BE UPDATED******************************************/
#include<map>
using namespace std;
/* multimap is a type of map where we can have duplicate keys i.e. keys need not be unique. All the methods are similar to map in all
properties, except some.

One thing to note that [] and at() method are not valid in multimap because keys are duplicate so there'll be ambiguity. */
int main()
{
    multimap<int,string> map{{10,"messi"},{7,"cristiano"},{11,"neymar"},{8,"inesta"},{9,"suarez"},{10,"maradona"},{10,"pele"}};
    multimap<int,int> m{{1,100},{2,200},{3,300},{4,400},{5,500}};
    for(auto i : map) cout<<i.first<<"    "<<i.second<<endl;
    for(auto i : m) cout<<i.first<<"    "<<i.second<<endl;
    cout<<endl;
    auto it = map.find(10);                 //find(key) returns the iterator to the first occurance of the key
    cout<<it->first<<" "<<it->second<<endl;
    cout<<endl;

    it = map.lower_bound(10);               //lower_bound(key) returns the iterator to the first occurance of the key
    cout<<it->first<<" "<<it->second<<endl;
    it = map.upper_bound(10);               //upper_bound(key) returns the iterator pointing just beyond the last occurance of the key
    cout<<it->first<<" "<<it->second<<endl;
    it = map.lower_bound(7);
    cout<<it->first<<" "<<it->second<<endl;
    it = map.upper_bound(7);
    cout<<it->first<<" "<<it->second<<endl;
    cout<<endl;

    auto itr = map.equal_range(10);   //equal_range(key) method returns a "pair" where pair.first is lower_bound(key) iterator
    //and pair.second is upper_bound(key) iterator
    cout<<itr.first->first<<" "<<itr.first->second<<endl;
    cout<<itr.second->first<<" "<<itr.second->second<<endl;
    return 0;
}
/*Output:

7    cristiano
8    inesta
9    suarez
10    messi
10    maradona
10    pele
11    neymar
1    100
2    200
3    300
4    400
5    500

10 messi

10 messi
11 neymar
7 cristiano
8 inesta

10 messi
11 neymar
*/