#include<iostream>
using namespace std;
//================================================================FRIEND CLASS EXAMPLE===================================================================================
//Forward Declaratoin is important because if compiler starts from X class and there it'll find Y so it'll throw error. 
//to avoid such case we have to give prior information to compiler that class Y is there in the program by declaring it before it enters X class
class Y;

class X
{
	int p;
	friend void swapVal(X&,Y&);
	public:
		void setVal(int k) 
		{
			p = k;
		}
		void display()
		{
			cout<<"The value of p is: "<<p<<endl;
		}
};
class Y
{
	int q;
	public: 
		void setVal(int l)
		{
			q = l;
		}
		friend void swapVal(X&,Y&);
		void display()
		{
			cout<<"The value of q is: "<<q<<endl;
		}
};
//=======================================================FRIEND CLASS EXAMPLE==========================================================================================
class Complex;           //if we don't werite this compiler will throw error because it'll read class name complex before it's 
//actual declaration in the class calculator. So we declare the class before hand and define afterwards to help compiler understand the code

class Calculator
{
public:
    int add(int a, int b)
    {
        return (a + b);
    }
    int sumRealComplex(Complex, Complex);
    int sumCompComplex(Complex, Complex);
};
class Complex
{
    int a, b;
    // Individually declaring functions as friends
    // friend int Calculator ::sumRealComplex(Complex, Complex);   //instead of defininig individual functionos as friends we can define entire class as friend
    // friend int Calculator ::sumCompComplex(Complex, Complex);

    // Aliter: Declaring the entire calculator class as friend
    friend class Calculator;

public:
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }

    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

int Calculator ::sumRealComplex(Complex o1, Complex o2)
{
    return (o1.a + o2.a);
}

int Calculator ::sumCompComplex(Complex o1, Complex o2)
{
    return (o1.b + o2.b);
}
void swapVal(X &a, Y &b)
{
	int temp;
	temp = a.p;
	a.p = b.q;
	b.q = temp;
}
int main()
{
    Complex o1, o2;
    o1.setNumber(1, 4);
    o2.setNumber(5, 7);
    Calculator calc;
    int res = calc.sumRealComplex(o1, o2);
    cout << "The sum of real part of o1 and o2 is " << res << endl;
    int resc = calc.sumCompComplex(o1, o2);
    cout << "The sum of complex part of o1 and o2 is " << resc << endl;

	//Swap values of p and q
	X x; Y y;
	x.setVal(23);
	y.setVal(56);
	x.display();
	y.display();
	swapVal(x,y);
	cout<<"\n";
	x.display();
	y.display();
    return 0;
}
