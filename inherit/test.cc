#include <iostream>
using namespace std;
//class Person
//{
//public:
//    void Display()
//    {
//        cout<<_name<<endl;
//    }
//    void f()
//    {
//        cout<<"Person()"<<endl;
//    }
//protected:
//    string _name;
//};
//
//class Student: public Person
//{
//public:
//    void f(int a)
//    {
//        cout<<"Person()"<<endl;
//    }
//public:
//        int _num;
//};
//int main()
//{
//    Person p;
//    Student s;
//    //子类对象赋值给父类对象-被称为切割
//    p=s;
//    //父类对象不能赋值给子类对象
//    //s=p;
//
//    //父类的指针可以指向子类对象
//    Person *p1=&s;
//
//    //父类的引用可以指向子类对象
//    Person &p2=s;
//
//    Student* s1=(Student*)&p;
//    Student& s2=(Student&)p;
//
//    s1->Student::_num=10;
//    s2._num=20;
//
//    cout<<s1->_num<<endl;
//    cout<<s2._num<<endl;
//    return 0;
//}


class Person//父类的成员函数
{
public:
    Person(char* name)
        :_name(name)
    {
        cout<<"Person()"<<endl;
    }
    Person(const Person& p)
       :_name(p._name) 
    {
        cout<<"Person(const Person& p)"<<endl;
    }
    Person& operator=(const Person& p)
    {
        cout<<"operator=()"<<endl;
        if(this!=&p)
        {
            _name=p._name;
        }
        return *this;
    }
    ~Person()
    {
        cout<<"~Person()"<<endl;
    }
protected:
    string _name;
};


class Student: public Person
{
public:
    Student(char* name,int num)
        :Person(name)
        ,_num(num)
    {
        cout<<"Student()"<<endl;
    }

    Student(const Student& s)
        :Person(s)
         ,_num(s._num)
    {
        cout<<"Student(const Student& s)"<<endl;
    }

    Student& operator=(const Student& s)
    {
        if(this!=&s)
        {
            Person::operator=(s);
            _num=s._num;
        }
        return *this;
    }

    ~Student()
    {
        cout<<"~Student()"<<endl;
    }
private:
    int _num;
};

void test()
{
    Student s1("jack",18);
    Student s2(s1);
    Student s3("rode",12);
    s1=s3;
}




int main()
{
    test();
}









