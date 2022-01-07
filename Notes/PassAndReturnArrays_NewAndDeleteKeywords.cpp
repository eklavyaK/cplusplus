#include <iostream>
#include <cstring>
#include <string>
using namespace std;
/*This file must be continously updated with new information*/

/*One thing to note that at source(passing or returning) we always write the name of the array. At destination we write * or [];*/

/*One thing to note that the we cannot pass arrays by value to a function in c++, like we are trying in func1() below. They are only passed by reference using
 pointers which behaves same as array in another function but the thing is that the locatoin of both are same, means if something changed in another will be reflcted everywhere.
 But however we can indirectly pass the array as value using struct*/
typedef struct arrays
{
	string p[10];
} ar;
struct integers
{
	int z[10];
};
void func(int *a, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum = sum + a[i];
	cout << sum << endl;
}
int *func1(int a[])
{
	int size = sizeof(a) / sizeof(a[0]); //compiler warns us that this statement will not give the size of the array because a is not a array it's pointer
	cout << size << endl;
	a[0] = 0;
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return a;
}
string *func2(string *a, int size)
{
	//int lengths[size];    //we cannot return this because length is a temporary pointer which will be lost or deleted just after function is closed
	//so to return a array we do dynamic memory allocation
	string *lengths = new string[10];
	for (int i = 0; i < size; i++)
	{
		lengths[i] = a[i] + " " + to_string(a[i].length());
	}
	return lengths;
}
ar func3(ar a)
{
	for (int i = 0; i < 10; i++)
	{
		a.p[i] = a.p[i] + string(9 - i, i + 97);
	}
	return a; //this method works we can return a array using struct
}
struct integers func4(struct integers a)
{
	for (int i = 0; i < 10; i++)
		a.z[i] = a.z[i] * 2;
	return a;
}
//int[] func1(int a[], int size){ return a[];} this is wrong way of returning array in c++. Here we can't return array directly we have to return it as pointer
/*******************************************************************MAIN METHOD********************************************************************************/
int main()
{
	int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int b[10];
	string s[10] = {"hello", "how", "his", "he", "him", "hi", "hey", "hola", "her", "has"};
	string sc[10];
	copy(begin(s), end(s), begin(sc)); // std::algorithm::copy()  is used to copy range of elements at a location to a new location
	copy(begin(a), end(a), begin(b));  //copy method of std namespace is can be used to copy the elements of one array to another;
	for (int i = 0; i < 10; i++)
	{
		cout << b[i] << " ";
	}
	cout << "\n"
		 << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << sc[i] << " ";
	}
	cout << "\n"
		 << endl;
	//proof of copying
	b[0] = 0;
	sc[0] = "hut";
	cout << "a[0] is: " << a[0] << "\n"
		 << "b[0] is: " << b[0] << "\n"
		 << "s[0] is: " << s[0] << "\n"
		 << "SC[0] is: " << sc[0] << endl;

	int c[10];
	memcpy(c, a, 32); //memcpy()  is used to copy a part of memory to another memory location.
	/*It's syntax is memcpy(destination*,source*,numberOfBytesToBeCopied).
	In the above statement since every element of the int array is 4bytes the number of elements copied is 8. so there is still garbage value
	in 9th and 10th location of the array c.*/
	for (int i = 0; i < 10; i++)
	{
		cout << c[i] << " ";
	}
	cout << "\n"
		 << endl;
	int size = sizeof(a) / sizeof(a[0]);
	func(a, size);
	int *p = func1(a);
	cout << a[0] << endl; //this prints 0 because it's value has been channged in func1() method so it's proved that array is being passed reference
	for (int i = 0; i < 10; i++)
		cout << p[i] << " "; //we can see that p behaves like array
	cout << "\n"
		 << endl;
	//now let's under dynamic memory allocation
	/*Dynamic memory allocation in C/C++ refers to performing memory allocation manually by programmer. 
	Dynamically allocated memory is allocated on Heap and non-static and local variables get memory allocated on Stack

	The new operator denotes a request for memory allocation on the Free Store.
	syntax: int* a = new int; float* b = new float; string *s = new string;
	in the syntax we can see that memory allocation requires the type of data to be stored so that number of bytes will be allocated

	to store a block of memory syntax is:
	int* a = new int[10]; float* b = new float[10]; string * s = new string[10];

	we can also do this for user defined data types: 
	`````````````
	struct cust{int p; cust(int q) : p(q) {}};
	cust* var1 = new cust;
	```````````````
	There is a difference between declaring a normal array and allocating a block of memory using new. 
	The most important difference is, normal arrays are deallocated by compiler (If array is local, then deallocated when function returns or completes).
	 However, dynamically allocated arrays always remain there until either they are deallocated by programmer or program terminates.*/
	a[0] = 10;
	string *sp = func2(s, size); //the returned array pointer is dynamically allocated so it'll remain in memory even after excution of function is complete
	for (int i = 0; i < 10; i++)
		cout << sp[i] << endl;
	cout << endl;
	int *t = new int;
	*t = 10;
	int u = 23, v;
	v = *t; //we can store a copy of value there in that memory location to another variable of that type but only copy not reference
	cout << *t + u << " " << u + v << endl;
	int *arr = new int[10];
	for (int i = 0; i < 10; i++)
		arr[i] = i * 2 + 1;

	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl;
	/*Since it is programmer’s responsibility to deallocate dynamically allocated memory, 
	programmers are provided delete operator by C++ language. */
	delete t;				//this is how to delete the memory with it's data
	delete[] arr;			//this is how to delete the chunk of memory with it's data
	cout << *t << endl;		//gives garbage value
	cout << arr[0] << endl; //gives garbage value

	cout << "\n"
		 << endl;
	ar A;
	for (int i = 0; i < 10; i++)
		A.p[i] = string(i + 1, char(i + 97));
	for (int i = 0; i < 10; i++)
		cout << A.p[i] << endl;
	cout << endl;
	ar B = func3(A); //this A is passed as value, reference of A is not passed and B stores the returned value
	for (int i = 0; i < 10; i++)
		cout << B.p[i] << endl;
	cout << endl;
	for (int i = 0; i < 10; i++)
		cout << A.p[i] << endl; //this provides different output than B so it's proved that reference of A is not passed
	//so passing array using struct is the best way to pass a array by value in c++

	//let's see another exaple for int array
	cout << "\n";
	struct integers q;
	for (int i = 0; i < 10; i++)
		q.z[i] = i + 1;
	for (int i = 0; i < 10; i++)
		cout << q.z[i] << " ";
	cout << endl;
	struct integers r = func4(q);
	for (int i = 0; i < 10; i++)
		cout << r.z[i] << " ";
	return 0;
}
//first few lines of the output contains a warning in which compiler warns that we are trying to find the size of a pointer rather than array

/*Output:
testfile.cpp: In function 'int* func1(int*)':
testfile.cpp:23:21: warning: 'sizeof' on array function parameter 'a' will return size of 'int*' [-Wsizeof-array-argument]
  int size = sizeof(a) / sizeof(a[0]); //compiler warns us that this statement will not give the size of the array because a is not a array it's pointer
                     ^
testfile.cpp:21:18: note: declared here
 int *func1(int a[])
                  ^
10 20 30 40 50 60 70 80 90 100 

hello how his he him hi hey hola her has

a[0] is: 10
b[0] is: 0
s[0] is: hello
SC[0] is: hut
10 20 30 40 50 60 70 80 6421624 3

550
1
0 20 30 40 50 60 70 80 90 100 
0
0 20 30 40 50 60 70 80 90 100

hello 5
how 3
his 3
he 2
him 3
hi 2
hey 3
hola 4
her 3
has 3

33 33
1 3 5 7 9 11 13 15 17 19 
16482072
16481160


a
bb
ccc
dddd
eeeee
ffffff
ggggggg
hhhhhhhh
iiiiiiiii
jjjjjjjjjj

aaaaaaaaaa
bbbbbbbbbb
cccccccccc
dddddddddd
eeeeeeeeee
ffffffffff
gggggggggg
hhhhhhhhhh
iiiiiiiiii
jjjjjjjjjj

a
bb
ccc
dddd
eeeee
ffffff
ggggggg
hhhhhhhh
iiiiiiiii
jjjjjjjjjj

1 2 3 4 5 6 7 8 9 10
2 4 6 8 10 12 14 16 18 20 
*/