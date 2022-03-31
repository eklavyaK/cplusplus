#include <bits/stdc++.h>
using namespace std;
/*In a class when you pass a object as argument then the reference of the object is not passed. The receiving object is created as new 
object of the class and it receives a copy of the variables' values of the variables stored in object passed. Any change made to the 
the object which receives the values of the passed object does not affect the original object.*/
class Student
{
	int marks, rollno, srno;
	string name;
	static int count;

public:
	void AddData(int m, int rn, string n)
	{
		name = n;
		rollno = rn;
		marks = m;
		count++;
		srno = count;
	}
	void modifyData(int detect)
	{
		if (detect == 1)
		{
			marks = marks + 5;
			if (marks > 100)
				marks = 100;
		}
		else if (marks < 5)
			marks = 0;
		else
			marks = marks - 5;
	}
	int topper(Student *a)      //here we have received the argument as pointer, however we can also receive it as array but it'll create
	{//another copy of the array so to save memory we pass it's location
		int result = 0;
		for (int i = 1; i < count; i++)
		{
			if (a[i].marks > a[result].marks)
				result = i;
		}
		return result;
	}
	Student *swapStudentPosition(int indexc, Student a, int indexa, Student b, int indexb)  //One thing to note is that we are not writing 
	{//return type as Student[] because it is not java. Here we pass arrays using pointers. and It's always good to pass and receive arrays using pointers.

		//Swaping is such that calling object will have least srno and serial order of a wrt b will be reversed, i.e. if a is before b in serial
		//no then it'll go after b after the swap. But if it comes after b it'll go before a after the swap.
		Student temp;
		temp.name = name;
		temp.rollno = rollno;
		temp.marks = marks;
		if (indexc > indexa && indexc > indexb)
		{
			if (indexa < indexb)
			{
				name = a.name;
				rollno = a.rollno;
				marks = a.marks;
				a.name = temp.name;
				a.rollno = temp.rollno;
				a.marks = temp.marks;
			}
			else
			{
				name = b.name;
				rollno = b.rollno;
				marks = b.marks;
				b.name = temp.name;
				b.rollno = temp.rollno;
				b.marks = temp.marks;
			}
		}
		else if (indexa < indexb && indexc > indexa)
		{
			name = b.name;
			rollno = b.rollno;
			marks = b.marks;
			b.name = a.name;
			b.rollno = a.rollno;
			b.marks = a.marks;
			a.name = temp.name;
			a.rollno = temp.rollno;
			a.marks = temp.marks;
		}
		else if (indexb < indexa && indexc > indexb)
		{
			name = a.name;
			rollno = a.rollno;
			marks = a.marks;
			a.name = b.name;
			a.rollno = b.rollno;
			a.marks = b.marks;
			b.name = temp.name;
			b.rollno = temp.rollno;
			b.marks = temp.marks;
		}
		else
		{
			Student temp2;
			temp2.name = a.name;
			temp2.rollno = a.rollno;
			temp2.marks = a.marks;
			a.name = b.name;
			a.rollno = b.rollno;
			a.marks = b.marks;
			b.name = temp2.name;
			b.rollno = temp2.rollno;
			b.marks = temp2.marks;
		}
		Student * ret = new Student[2];     //we cannot simply create a local variable and return because local is at risk of 
		//getting deleted after the function is completed. So we do a dynamic memory allocation of the array and then return it to the main function
		ret[0] = a;
		ret[1] = b;
		return ret;
	}
	static int DisplayCount() { return count; } //static member methods only operate on static variables and cannot be called using object
	//because they are static.
	void Display()
	{
		cout << srno << "[" << rollno << " " << name << " " << marks << "]" << endl;
	}
};
int Student::count = 0;
int main()
{
	Student s[8];
	s[0].AddData(50, 10, "Dipesh");
	s[1].AddData(85, 16, "Kamal");
	s[2].AddData(58, 48, "Shruti");
	s[3].AddData(70, 35, "Yash");
	s[4].AddData(67, 26, "Prashant");
	s[5].AddData(45, 9, "Babal");
	s[6].AddData(39, 19, "Mohandas");
	s[7].AddData(74, 28, "Shayam");
	cout << "No of students: " << Student::DisplayCount() << endl;  //note that we cannot call the static method of an class without using <classname> and :: operator with class name
	cout << "\nStudents' provisional marks: \n" << endl;
	for (int i = 0; i < 8; i++)
		s[i].Display();

	s[1].modifyData(1);
	s[7].modifyData(0);
	s[3].modifyData(1);
	s[6].modifyData(1);
	cout << "\nFinal results after modification: \n" << endl;
	for (int i = 0; i < 8; i++)
		s[i].Display();

	cout << "\nCourse topper: " << endl;
	int result = s[1].topper(s);
	s[result].Display();

	Student *ret1 = s[7].swapStudentPosition(8, s[2], 3, s[5], 6);  //here we received the dynamic memory location of the array--> ret,
	//ret and ret1 are same things with different names because both point to same memory location
	s[2] = ret1[0];
	s[5] = ret1[1];
	cout << "\nSerial Positions after 1st swaps: \n" << endl;
	for (int i = 0; i < 8; i++)
		s[i].Display();

	Student *ret2 = s[0].swapStudentPosition(1, s[4], 3, s[6], 6);
	s[4] = ret2[0];
	s[6] = ret2[1];
	cout << "\nSerial Positions after 2nd swaps: \n" << endl;
	for (int i = 0; i < 8; i++)
		s[i].Display();
}
/*Output:
No of students: 8

Students' provisional marks:

1[10 Dipesh 50]
2[16 Kamal 85]
3[48 Shruti 58]
4[35 Yash 70]
5[26 Prashant 67]
6[9 Babal 45]
7[19 Mohandas 39]
8[28 Shayam 74]

Final results after modification:

1[10 Dipesh 50]
2[16 Kamal 90]
3[48 Shruti 58]
4[35 Yash 75]
5[26 Prashant 67]
6[9 Babal 45]
7[19 Mohandas 44]
8[28 Shayam 69]

Course topper:
2[16 Kamal 90]

Serial Positions after 1st swaps:

1[10 Dipesh 50]
2[16 Kamal 90]
3[28 Shayam 69]
4[35 Yash 75]
5[26 Prashant 67]
6[9 Babal 45]
7[19 Mohandas 44]
8[48 Shruti 58]

Serial Positions after 2nd swaps:

1[10 Dipesh 50]
2[16 Kamal 90]
3[28 Shayam 69]
4[35 Yash 75]
5[19 Mohandas 44]
6[9 Babal 45]
7[26 Prashant 67]
8[48 Shruti 58]
*/