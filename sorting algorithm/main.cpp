#include <iostream>
#include<fstream>
#include<cmath>
#include "Student.h"
using namespace std;

template<class T>
void bubbleSortT( T*arr,int n)
{
    for(int i = 0 ; i<n-1; i++)
    {
        for(int j = 0 ; j <n-i-1; j++)
        {
            if(arr[j]<arr[j+1]==false)
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int partition1(Student*arr,int left, int right)
{
    Student p = arr[left];
    int i = left ;
    for (int j = left+1; j <=right ; ++j)
    {
        if (arr[j] < p==true)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i],arr[left]);
    return i;
}
template<class T>
void quickSortT(T*arr1,int x, int y )
{
    if(x<y)
    {
        int piv= partition1(arr1,x,y);
        quickSortT(arr1,x,piv-1);
        quickSortT(arr1,piv+1,y);
    }
}

template<class T>
void shellsort(T*arr2, int n)
{
    int i, j,k, increment;
    Student temp;
    int swp=0;
    int comp=0;
    int val;
    val=log(n+1)/log(2);
    increment =pow(2,val)-1;
    while (increment > 0)
    {
        for (i=0; i<increment; i++)
        {
            for(j=0; j<n; j+=increment)
            {
                temp=arr2[j];
                for(k=j-increment; k>=0&&temp<arr2[k]; k-=increment)
                {
                    comp++;
                    swp++;
                    arr2[k+increment]=arr2[k];
                }
                arr2[k+increment]=temp;
                swp++;
            }
        }
        comp++;
        val--;
        if(increment!=1)
            increment=pow(2,val)-1;
        else
            increment = 0;
    }
}

int binarySearch(Student*arr,int l,int r,string key)
{
    while(l<=r)
    {
        int m = (l+r)/2;
        if(arr[m].getName()==key)
        {
            return m ;
        }
        if(arr[m].getName()>key)
        {
            r=m-1;
        }
        else
        {
            l=m+1;
        }
    }
    return -1 ;
}
int main()
{
    int number ;
    string fullName;
    string  firstName;
    string lastName ;
    string idStudent;
    double gpaStudent;
    string x;
    string y;
    double z;
    ifstream inFile("student.txt");
    inFile>>number ;
    Student*a1=new Student[number];
    Student*a2=new Student[number];
    Student*a3=new Student[number];
    for(int i = 0 ; i < number ; i ++)
    {
        inFile>>firstName;
        inFile>>lastName;
        fullName=firstName+" "+lastName;
        inFile>>idStudent;
        inFile>>gpaStudent;
        a1[i]=Student(fullName,idStudent,gpaStudent);
        a2[i]=Student(fullName,idStudent,gpaStudent);
        a3[i]=Student(fullName,idStudent,gpaStudent);
    }
    bubbleSortT(a1,number);
    int temp1 = a1[0].getCounter();
    a1[0].setstaticCounter(0);
    quickSortT(a2,0,number-1);
    int temp2 = a2[0].getCounter();
    a2[0].setstaticCounter(0);
    shellsort(a3,number);
    int temp3 = a3[0].getCounter();
    ofstream outSort;
    outSort.open("Bubble.txt");
    outSort<<"the number of comparison : "<<temp1;
    outSort<<endl;
    for(int i = 0 ; i<number ; i++)
    {
        x= a1[i].getName();
        y = a1[i].getID();
        z = a1[i].getGpa();
        outSort<<x;
        outSort<<endl;
        outSort<<y;
        outSort<<endl;
        outSort<<z;
        outSort<<endl;
    }
    outSort.close();
    ofstream outSort2;
    outSort2.open("quick.txt");
    outSort2<<"the number of comparison: " <<temp2<<endl;
    for(int i = 0 ; i<number ; i++)
    {
        x= a2[i].getName();
        y = a2[i].getID();
        z = a2[i].getGpa();
        outSort2<<x;
        outSort2<<endl;
        outSort2<<y;
        outSort2<<endl;
        outSort2<<z;
        outSort2<<endl;
    }
    outSort2.close();


    ofstream outSort3;
    outSort3.open("shell.txt");
    outSort3<<"the number of comparison: " <<temp3<<endl;

    for(int i = 0 ; i<number ; i++)
    {
        x=  a3[i].getName();
        y = a3[i].getID();
        z = a3[i].getGpa();
        outSort3<<x;
        outSort3<<endl;
        outSort3<<y;
        outSort3<<endl;
        outSort3<<z;
        outSort3<<endl;
    }
    int inp;
    while(true){
        cout<<"1- Show number of comparisons and sorted array of Bubble Sort\n";
        cout<<"2- Show number of comparisons and sorted array of Shell Sort\n";
        cout<<"3- Show number of comparisons and sorted array of Quick Sort\n";
        cout<<"4- Search for a student by name\n";
        cout<<"5- Exit\n";
        cin>>inp;
        if(inp==1){
            for(int i=0; i<number; i++)
                a1[i].print();
        }else if(inp==2){
            for(int i=0; i<number; i++)
                a3[i].print();
        }else if(inp==3){
            for(int i=0; i<number; i++)
                a2[i].print();
        }else if(inp==4){
            string name1,name2;
            cout<<"Enter Full name: ";
            cin>>name1>>name2;
            int idx = binarySearch(a1,0,number-1,name1+" "+name2);
            cout<<idx<<endl;
        }else
            return 0;
        cout<<endl;
    }


    return 0;
}
