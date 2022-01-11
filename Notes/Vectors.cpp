#include<iostream>       /*******************WILL BE UPDATED REGULARLY********************/
#include<vector>
using namespace std;

//Note: begin() iterator points to the first element of vector but end() iterator points to the element beyond the last element of the vector.
int main()
{
    //declaration of vectors
    vector <int> vint;
    vector <string> vstring;
    vector <bool> vbool; 
    vector <int> v(20);    //in this declaration the vector v is allocated 20 int spaces, all of which is initialized to 0
    for(auto i:v) cout<<i<<" "; cout<<endl;

    //different types of initialization of vectors
    for(int i = 0; i<10; i++) vint.push_back(i+10);      //push_back() method is used to add a element to the end of a vector
    for(int i = 0; i<10; i++) vstring.push_back("hello"+to_string(i+1));
    for(int i = 0; i<10; i++) cout<<vint[i]<<" ";cout<<'\n';
    for(int i = 0; i<10; i++) cout<<vstring[i]<<" ";cout<<'\n';
    vector<int> vint1={10,20,30,40,50}; //like arrays
    for(int i = 0; i<vint1.size(); i++) cout<<vint1[i]<<" ";cout<<endl;
    vector<int> vint2(5, 199); //this vector contains 199 five times
    for(int i = 0; i<vint2.size(); i++) cout<<vint2[i]<<" "; cout<<endl;
    vector<string> vstring1(5, "hellow");
    for(int i = 0; i<vstring1.size(); i++) cout<<vstring1[i]<<" "; cout<<endl;
    vector<string> vstring2;
    vstring2 = {"hello","hey","hi","hellow","hola"}; //like arrays but this is same as assigning a vector to another vector
    for(int i = 0; i<vstring2.size(); i++) cout<<vstring2[i]<<" "; cout<<endl;
    vstring2 = {"hello","hey","hi","hellow","hola","how"}; //we can see this is assignment
    for(int i = 0; i<vstring2.size(); i++) cout<<vstring2[i]<<" "; cout<<endl<<endl;

    //initializing from an array
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> vint3(arr, arr+sizeof(arr)/sizeof(arr[0])); //passing the starting reference and ending reference to constructor
    for(auto i:vint3) cout<<i<<" "; cout<<endl;
    vector<int> vint4(begin(arr),end(arr)); //passing the starting reference and ending to constructor
    for(auto i:vint4) cout<<i<<" "; cout<<endl;
    vector<int> vint5;
    vint5.assign(arr+1,arr+4); //assign function assigns the vector with values in the given range of references
    for(auto i:vint5) cout<<i<<" "; cout<<endl;
    vint5.insert(vint5.begin()+3,arr,arr+5); //insert function inserts the values to vector
    for(auto i:vint5) cout<<i<<" "; cout<<endl<<endl;

    //iterator
    vector<int> :: iterator itr = vint.begin();
    while(itr!=vint.end()) cout<<*itr++<<" "; cout<<endl<<endl;
    //itr = vstring.begin(); --------------> this throws error because iterator also has data type
    //iterator and pointers are similar in behavior but cannot be equalised to each other.
    
    cout<<vint.size()<<endl<<endl; //size() function is used to find the length of  the vector

    cout<<vint.at(0)<<endl;
    vint.at(0) = 11;       //at(index) method gives the reference to the particular index in vector
    cout<<vint.at(0)<<endl<<endl;

    cout<<vint.back()<<endl; //back() method gives the reference to the last element of the vector
    cout<<vint.front()<<endl<<endl; //back() method gives the reference to the first element of the vector
    //we can also change the values using front() and back() methods
    
    vint.swap(vint5);   //swap() method is used to swap elements of two vectors
    cout<<"\nSwapping elements of two vectors"<<endl;
    for(auto i:vint5) cout<<i<<" "; cout<<endl;
    for(auto i:vint) cout<<i<<" "; cout<<endl<<endl; //we can write multiple endls in one cout statement;

    vint.pop_back();      //pop_back() method is used to remove the last element of the vector
    for(auto i:vint) cout<<i<<" "; cout<<endl<<endl;

    cout<<vint.empty()<<endl<<endl;; //empty() methods returns true if vector is empty otherwise false

    //inserting elements in array, we use insert method to insert elements to vector
    vint.insert(vint.begin()+4,100); //insert(reference,value) this method is used to insert element to a particular reference index of the vector
    for(auto i:vint) cout<<i<<" "; cout<<endl;
    vint.insert(vint.end(),vint5.begin()+5,vint5.end()); /*insert(iterator to position where inserting starts, iterator to first
    input reference, iterator to last input reference) */ 
    for(auto i:vint) cout<<i<<" "; cout<<endl;
    vint.insert(vint.end(),5,10); /*insert(iterator to position where inserting starts, number of times value to be inserted, value)*/
    for(auto i:vint) cout<<i<<" "; cout<<endl;
    vstring.insert(vstring.end(),vstring.begin()+5,vstring.end());
    for(auto i:vstring) cout<<i<<" "; cout<<endl<<endl; //this proves that this method first copies the elements then inserts to the specified location
    //not in dynamic manner.

    //deletion of elements from vector, we use erase method for that
    vstring.erase(vstring.end()-1); //erase(iterator to the index which is to be deleted)
    for(auto i:vstring) cout<<i<<" "; cout<<endl;
    vstring.erase(vstring.end()-4,vstring.end());  //erase(range of references to be deleted)
    for(auto i:vstring) cout<<i<<" "; cout<<endl<<endl;

    //resizing a vector
    vint.resize(13); //it changes the size of the vector to first 13 elements
    for(auto i:vint) cout<<i<<" "; cout<<endl;
    vint.resize(15,20); //since size of the original vector is 13, to make the size of the vector to 15, 
    //two 20s addec in the end
    for(auto i:vint) cout<<i<<" "; cout<<endl;
    vint.resize(20);
    for(auto i:vint) cout<<i<<" "; cout<<endl; //in case of no value given, default value in case of int vector is 0
    vstring1.resize(10);
    for(auto i:vstring1) cout<<i<<" "; cout<<endl; 
    if(vstring1[9]=="") cout<<"true"<<endl; //in case of no value given, default value in case of string vector is ""

    vstring1.clear(); //clear() method is used to clear everything from the vector
    for(auto i:vstring1) cout<<i<<" "; cout<<endl; 

    //assign() method is used to assign a new vector to a vector
    v.assign(10,25);  //this method assigns vector v as vector with 10 elements all of which are 25
    for(auto i:v) cout<<i<<" "; cout<<endl;
    vint.assign(vint.begin(),vint.end()-5); //in this method a vector is formed by copying the values from the given range of iterators
    //and then assigned to the vector
    for(auto i:vint) cout<<i<<" "; cout<<endl<<endl;

    //assigning a vector to another vector
    v = vint;  //the elements of vint are copied to v;
    vint.pop_back();
    for(auto i:v) cout<<i<<" "; cout<<endl;
    for(auto i:vint) cout<<i<<" "; cout<<endl<<endl;
   
    v.emplace(v.end()-1,21); //emplace is used to insert an element to a specific index of vector
    //it is more efficient than insert in case of objects, but for primitive data types both have same efficiency
    for(auto i:v) cout<<i<<" "; cout<<endl<<endl;

    v.emplace_back(22); //emplace_back(args) is used to add a element to the vector at the end. same function as push_back()
    //but it is faster than push_back. so we will use emplace_back instead for push_back for normal operations but while
    //dealing with graphs(vecor of vectors) we will use push_back() method cuz it is errorless.
    for(auto i:v) cout<<i<<" "; cout<<endl<<endl;

    //conversion to array
    int *p = v.data();      //wait, this p is not a array but pointer which behaves like an array where p points to the first element of vector
    //we cannot get the size of this array using pointer so we have to use the v.size() function
    for(int i = 0; i<v.size(); i++) cout<<p[i]<<" "; cout<<endl;
    v.emplace_back(23);
    for(int i = 0; i<v.size(); i++) cout<<p[i]<<" "; cout<<endl;
    //here we can see that it is not a array but a pointer to the first element of the vector which is behaving like a array
    p[v.size()] = 24;
    for(int i = 0; i<v.size()+1; i++) cout<<p[i]<<" "; cout<<endl;
    for(int i = 0; i<v.size(); i++) cout<<v[i]<<" "; cout<<endl;
    //here we can see that vector size remains the same
    return 0;
}
/*Output:

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
10 11 12 13 14 15 16 17 18 19 
hello1 hello2 hello3 hello4 hello5 hello6 hello7 hello8 hello9 hello10 
10 20 30 40 50 
199 199 199 199 199 
hellow hellow hellow hellow hellow 
hello hey hi hellow hola 
hello hey hi hellow hola how 

1 2 3 4 5 
1 2 3 4 5 
2 3 4 
2 3 4 1 2 3 4 5 

10 11 12 13 14 15 16 17 18 19 

10

10
11

19
11


Swapping elements of two vectors
11 11 12 13 14 15 16 17 18 19   
2 3 4 1 2 3 4 5 

2 3 4 1 2 3 4 

0

2 3 4 1 100 2 3 4
2 3 4 1 100 2 3 4 15 16 17 18 19
2 3 4 1 100 2 3 4 15 16 17 18 19 10 10 10 10 10
hello1 hello2 hello3 hello4 hello5 hello6 hello7 hello8 hello9 hello10 hello6 hello7 hello8 hello9 hello10

hello1 hello2 hello3 hello4 hello5 hello6 hello7 hello8 hello9 hello10 hello6 hello7 hello8 hello9 
hello1 hello2 hello3 hello4 hello5 hello6 hello7 hello8 hello9 hello10

2 3 4 1 100 2 3 4 15 16 17 18 19
2 3 4 1 100 2 3 4 15 16 17 18 19 20 20
2 3 4 1 100 2 3 4 15 16 17 18 19 20 20 0 0 0 0 0
hellow hellow hellow hellow hellow
true

25 25 25 25 25 25 25 25 25 25
2 3 4 1 100 2 3 4 15 16 17 18 19 20 20

2 3 4 1 100 2 3 4 15 16 17 18 19 20 20 
2 3 4 1 100 2 3 4 15 16 17 18 19 20

2 3 4 1 100 2 3 4 15 16 17 18 19 20 21 20

2 3 4 1 100 2 3 4 15 16 17 18 19 20 21 20 22

2 3 4 1 100 2 3 4 15 16 17 18 19 20 21 20 22
2 3 4 1 100 2 3 4 15 16 17 18 19 20 21 20 22 23 
2 3 4 1 100 2 3 4 15 16 17 18 19 20 21 20 22 23 24
2 3 4 1 100 2 3 4 15 16 17 18 19 20 21 20 22 23
*/