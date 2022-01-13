#include<iostream>
#include<set>
/*Multiset is a set which can have duplicate elements. Like set all elements are present in sorted order. It's mostly like a sorted vecror
, it's hardly useful. Only deemed advantage it has over a vector is that it all the elements with same value can be erased at once and 
multiple times a element can be added to the set at once.

Most of the functions are similar to set so we won't study about every function  here again*/
using namespace std;

int main()
{
    multiset<int> set{1,2,2,2,2,2,2,3,3,3,3,3,3,4,5,6,8,8,8,9};
    set.insert(10);
    set.insert(11);
    set.insert(12);
    set.insert(12);
    for(auto i : set) cout<<i<<" "; cout<<endl<<endl;

    set.erase(2);    //this will erase all 2's present in the set, because we don't specify which 2 must be erased   
    for(auto i : set) cout<<i<<" ";cout<<endl;
    auto it = set.find(3);
    set.erase(it);   //this will erase only one occurance the element pointed by the iterator
    for(auto i : set) cout<<i<<" ";cout<<endl;
    set.erase(set.find(12));  //his will erase only one occurance of the element pointed by the iterator returned by find() method
    for(auto i : set) cout<<i<<" ";cout<<endl;
    return 0;
}
/*Output:

1 2 2 2 2 2 2 3 3 3 3 3 3 4 5 6 8 8 8 9 10 11 12 12 

1 3 3 3 3 3 3 4 5 6 8 8 8 9 10 11 12 12
1 3 3 3 3 3 4 5 6 8 8 8 9 10 11 12 12
1 3 3 3 3 3 4 5 6 8 8 8 9 10 11 12
*/