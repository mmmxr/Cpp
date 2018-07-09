#pragma once

class Date
{
public:
    //构造函数
    Date(int year=1900,int month=1,int day=1);

    //析构函数
    ~Date();

    //拷贝构造函数
    Date(const Date& d);

    //运算符重载
    void operator=(const Date& d);
    bool operator==(const Date& d);
    bool operator!=(const Date& d);
    bool operator>=(const Date& d); 
    bool operator<=(const Date& d); 
    bool operator>(const Date& d); 
    bool operator<(const Date& d); 
    // d1 + 10 
    Date operator+(int day); 
    Date& operator+=(int day); 
    Date operator-(int day); 
    Date& operator-=(int day); 
    int operator-(const Date& d); 

    Date& operator++(); // 前置 
    Date operator++(int); // 后置 
    Date operator--(); 
    Date operator--(int); 

    void Show();
    int GetMonthDay(int year,int month);
    bool IsValid();
    bool IsLeap(int year);
private:
    int _year;
    int _month;
    int _day;
};

