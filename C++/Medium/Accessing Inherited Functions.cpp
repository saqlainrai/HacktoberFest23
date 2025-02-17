#include <iostream>
using namespace std;

/*
    Solved by: Saqlain Mansab
    URL: https://www.hackerrank.com/challenges/accessing-inherited-functions/problem
*/

class A
{
    public:
        A()
        {
            callA = 0;
        }

    private:
        int callA;
        void inc()
        {
            callA++;
        }

    protected:
        void func(int &a)
        {
            a = a * 2;
            inc();
        }

    public:
        int getA()
        {
            return callA;
        }
};

class B
{
    public:
        B()
        {
            callB = 0;
        }

    private:
        int callB;
        void inc()
        {
            callB++;
        }

    protected:
        void func(int &a)
        {
            a = a * 3;
            inc();
        }

    public:
        int getB()
        {
            return callB;
        }
};

class C
{
    public:
        C()
        {
            callC = 0;
        }

    private:
        int callC;
        void inc()
        {
            callC++;
        }

    protected:
        void func(int &a)
        {
            a = a * 5;
            inc();
        }

    public:
        int getC()
        {
            return callC;
        }
};

class D : C, B, A
{

    int val;

    public:
        // Initially val is 1
        D()
        {
            val = 1;
        }

        // Implement this function
        void update_val(int new_val)
        {
            while (new_val != 1)
            {
                if (new_val % 2 == 0)
                {
                    A::func(val);
                    new_val /= 2;
                }
                else if (new_val % 3 == 0)
                {
                    B::func(val);
                    new_val /= 3;
                }
                else if (new_val % 5 == 0)
                {
                    C::func(val);
                    new_val /= 5;
                }
            }
        }
        // For Checking Purpose
        void check(int); 
};

void D::check(int new_val)
{
    update_val(new_val);
    cout << "Value = " << val << endl;
    cout << "A's func called " << getA() << " times " << endl;
    cout << "B's func called " << getB() << " times" << endl;
    cout << "C's func called " << getC() << " times" << endl;
}

int main()
{
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);
}