#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <iostream>
#include<fstream>
#include<cmath>
using namespace std;
class Student
{
    static int counter;
    string name;
    string id;
    double gpa;
public:
    Student() {}
    Student( string n, string i, double g)
    {
        name=n;
        id=i;
        gpa=g;
    }
    Student(const Student&obj)
    {
        name=obj.name;
        id=obj.id;
        gpa=obj.gpa;
    }
    void print()
    {
        cout<<name<<endl;
        cout<<id<<endl;
        cout<<gpa<<endl;
    }
    bool operator<(const Student&obj)
    {
        counter++;
        bool statues;
        if(name<=obj.name)
        {
            statues=true;
            return statues;
        }
        else
        {
            statues=false;
            return statues;
        }
    }
    string getName()
    {
        return name;
    }
    string getID()
    {
        return id;
    }
    double getGpa()
    {
        return gpa;
    }
    void setstaticCounter(int x)
    {
        counter=0;
    }
    static getCounter()
    {
        return counter;
    }
};
int Student::counter=0;
#endif // STUDENT_H_INCLUDED
