#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
    Solved by: Saqlain Mansab
    URL: https://www.hackerrank.com/challenges/virtual-functions/problem
*/

class Person
{
    public:
        string name;
        int age;
        virtual void getdata()
        {
            cin >> name >> age;
        }
        virtual void putdata()
        {
            cout << name << ' ' << age << ' ';
        }
};

class Professor : public Person
{
    public:
        int publication, cur_id;
        static int id;
        Professor()
        {
            cur_id = id++;
        }
        virtual void getdata()
        {
            Person::getdata();
            cin >> publication;
        }
        virtual void putdata()
        {
            Person::putdata();
            cout << publication << ' ' << cur_id << endl;
        }
};

class Student : public Person
{
    public:
        int marks[6], cur_id, sum = 0;
        static int id;
        Student()
        {
            cur_id = id++;
        }
        virtual void getdata()
        {
            Person::getdata();
            for (int i = 0; i < 6; i++)
            {
                cin >> marks[i];
                sum += marks[i];
            }
        }
        virtual void putdata()
        {
            Person::putdata();
            cout << sum << ' ' << cur_id << endl;
        }
};
int Professor::id = 1;
int Student::id = 1;

// this is the previous provided code.
int main()
{
    int n = 0;
    int val;
    cin >> n; // The number of objects that is going to be created.
    Person* per[n];

    for (int i = 0; i < n; i++)
    {
        cin >> val;
        if (val == 1)
        {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;
        }
        else
            per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.
    }

    for (int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;
}
