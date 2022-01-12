#include<iostream>
#include<list>         /*a list iterator moves in cycle and never comes out of the list when it reaches l.end() it displays the 
                        size of the list, then on incrementing it comes back to l.begin()this has been shown in line no. 85*/
#include<vector>
using namespace std;
//list in c++ are doubly-linked list structure which facilitates constant time insertion and deletion from anywhere in the list
//they can store multiple copies of same elements.
//Searching of elements in list is slower than in vector because of randomm stoarge locatoins rather accumulated contiguously
int main()
{
   //declaration and initialization
   vector<int> v{1,2,3,4,4,5,2,5,8,9,7,10,6};
   int arr[] = {1,2,3,4,4,5,2,5};
   list<int> l; list<string> s;
   s.emplace_back("c++");       //emplace_back() function is used to add a new element to the end of the list
   s.emplace_back("java");
   s.emplace_back("c");
   s.emplace_back("javascript");
   s.emplace_back("php");
   s.emplace_back("typescript");
   s.emplace_back("python");
   s.emplace_back("css");
   s.emplace_back("rust");
   s.emplace_back("go");
   s.emplace_back("Node.js");
   for(int i = 0; i<10; i++) l.push_back(i+1); //push_back() function is used to insert a element to the end of the list
   list<int> l1(v.begin(),v.end());            //initialazation with range by passing the iterator at the beginning and end of the range
   list<int> l2(arr, arr+sizeof(arr)/sizeof(arr[0])); //passing the iterator of the beginning and end of the range to initialize the list
   for(auto i : s) cout<<i<<" ";cout<<endl;  
   for(auto i : l) cout<<i<<" ";cout<<endl;
   for(auto i : l1) cout<<i<<" ";cout<<endl;
   for(auto i : l2) cout<<i<<" ";cout<<endl;
   s.push_front("html");                      //push_front(arg) adds a element at the front of the list
   for(auto i : s) cout<<i<<" ";cout<<endl;
   s.emplace_front("java");                    //emplace_front(arg) has same functionality as push_front()
   for(auto i : s) cout<<i<<" ";cout<<endl;
   list<int> l3(l);                             //initialization by passing a list
   for(auto i : l3) cout<<i<<" ";cout<<endl<<endl;

   //transversing a list like index
   auto it = s.begin();
   for(int i = 0; i<s.size(); i++) {cout<<*it<<" ";advance(it,1);} //advance method advances(iterator,n) "any" iterator by n increaments
      cout<<endl<<endl; 

   s.pop_back(); //pop_back() is used to remove a element from the back of the list
   s.pop_front(); //pop_front() removes first element of the list
   s.pop_front();
   for(auto i : s) cout<<i<<" ";cout<<endl<<endl;

   cout<<l.size()<<endl<<endl;       //size() method gives the number of elements in the list

   l.front() = 100; //front() returns the reference of the front element of the list
   cout<<l.front()<<endl;
   l.back() = 100;  //back() returns the reference of the last element of the list
   cout<<l.back()<<endl<<endl;

   l1.swap(l2);       //swap() method swap the entire elements of two lists of same type
   for(auto i : l1) cout<<i<<" ";cout<<endl;
   for(auto i : l2) cout<<i<<" ";cout<<endl<<endl;

   l.reverse();         //reverse() method reverses the i.e. makes last element to begin() iterator and end() iterator to first element
   for(auto i : l) cout<<i<<" ";cout<<endl<<endl;

   l.sort();           //sort() method sorts the list
   for(auto i : l) cout<<i<<" ";cout<<endl<<endl;

   l1.merge(l2);        /*C++ List merge() function merges two sorted list in an increasing order. 
   It merges y list into the given list container and this removes all the elements from y.*/
   for(auto i : l1) cout<<i<<" ";cout<<endl;
   for(auto i : l2) cout<<i<<" ";cout<<endl;  //this doesn't print anything because all the elements of l2 has been removed
   
   auto itr = l.end();
   l.insert(itr,101);  /* insert() opearator inserts the given value at the position where iterator points and then increments
   the value of the iterator by 1. If iterator is incremented beyond l.end() then it directly goes to l.begin()*/
   for(auto i : l) cout<<i<<" ";cout<<endl;
   l.insert(itr,2,99); /* insert() opearator inserts the given value at the position where iterator points and then increments
   the value of the iterator by 1. this continues till the element is added given number of times*/
   for(auto i : l) cout<<i<<" ";cout<<endl;
   l.insert(itr,l1.begin(),l1.end());/* insert() opearator inserts the given value at the position where iterator points and then increments
   the value of the iterator by 1. this continues till all the elements are added*/
   for(auto i : l) cout<<i<<" ";cout<<endl;
   for(auto i : l1) cout<<i<<" ";cout<<endl<<endl;  //you can see insert is different from merge because here values are copied not moved

   itr = l1.begin();
   for(int i = 0; i<100;i++) cout<<*itr++<<" "; cout<<endl<<endl; //we can see that iterator m0ves in cycle and never comes out of the list
   for(int i = 0; i<100;i++) cout<<*itr--<<" "; cout<<endl<<endl; //we can see that iterator m0ves in cycle and never comes out of the list
   
   l.unique();  //unique() removes two duplicate elements that are positioned consecutive
   for(auto i : l) cout<<i<<" ";cout<<endl<<endl;

   itr = l.begin();
   advance(itr,11);
   l.emplace(itr,102);         //emplace() method is used to insert a value at particular position in list
   for(auto i : l) cout<<i<<" ";cout<<endl<<endl;

   //assign() method changes a list to a completely new list
   l.assign(10,100);    //assign(n, val) assigns n values to the list
   for(auto i : l) cout<<i<<" "; cout<<endl;
   l.assign(l1.begin(),l1.end());     //assign(itr1,itr2) assign copies the values from a range specified by iterators
   for(auto i : l) cout<<i<<" "; cout<<endl;
   for(auto i : l1) cout<<i<<" "; cout<<endl<<endl; //we can see that values of l1 are copied not moved
   
   return 0;
}
/*Output:

c++ java c javascript php typescript python css rust go Node.js 
1 2 3 4 5 6 7 8 9 10
1 2 3 4 4 5 2 5 8 9 7 10 6
1 2 3 4 4 5 2 5
html c++ java c javascript php typescript python css rust go Node.js 
java html c++ java c javascript php typescript python css rust go Node.js
1 2 3 4 5 6 7 8 9 10

java html c++ java c javascript php typescript python css rust go Node.js

c++ java c javascript php typescript python css rust go

10

100
100

1 2 3 4 4 5 2 5
1 2 3 4 4 5 2 5 8 9 7 10 6

100 9 8 7 6 5 4 3 2 100

2 3 4 5 6 7 8 9 100 100

1 1 2 2 3 3 4 4 4 4 5 2 5 5 2 5 8 9 7 10 6 

2 3 4 5 6 7 8 9 100 100 101
2 3 4 5 6 7 8 9 100 100 101 99 99
2 3 4 5 6 7 8 9 100 100 101 99 99 1 1 2 2 3 3 4 4 4 4 5 2 5 5 2 5 8 9 7 10 6 
1 1 2 2 3 3 4 4 4 4 5 2 5 5 2 5 8 9 7 10 6

1 1 2 2 3 3 4 4 4 4 5 2 5 5 2 5 8 9 7 10 6 21 1 1 2 2 3 3 4 4 4 4 5 2 5 5 2 5 8 9 7 10 6 21 1 1 2 2 3 3 4 4 4 4 5 2 5 5 2 5 8 9 7 10 6 21 1 1 2 2 3 3 4 4 4 4 5 2 5 5 2 5 
8 9 7 10 6 21 1 1 2 2 3 3 4 4 4 4 5 2 

5 2 5 4 4 4 4 3 3 2 2 1 1 21 6 10 7 9 8 5 2 5 5 2 5 4 4 4 4 3 3 2 2 1 1 21 6 10 7 9 8 5 2 5 5 2 5 4 4 4 4 3 3 2 2 1 1 21 6 10 7 9 8 5 2 5 5 2 5 4 4 4 4 3 3 2 2 1 1 21 6 11 6 10 7 9 8 5 2 5 5 2 5 4 4 4 4 3 3 2 2 1

2 3 4 5 6 7 8 9 100 101 99 1 2 3 4 5 2 5 2 5 8 9 7 10 6

2 3 4 5 6 7 8 9 100 101 99 102 1 2 3 4 5 2 5 2 5 8 9 7 10 6

100 100 100 100 100 100 100 100 100 100
1 1 2 2 3 3 4 4 4 4 5 2 5 5 2 5 8 9 7 10 6
1 1 2 2 3 3 4 4 4 4 5 2 5 5 2 5 8 9 7 10 6

*/