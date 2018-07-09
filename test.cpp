#include "test.h"
#include <iostream>
#include <assert.h>
#include <unistd.h>
using namespace std;
//构造
Date::Date(int year,int month,int day)
    :_year(year)
     ,_month(month)
     ,_day(day)
{
    if(!IsValid())
    {
        assert(false);
    }
}
bool Date::IsValid()
{
    return _year>=1900 && 
        _month>0 && _month<13 &&
        _day>0 && _day<=GetMonthDay(_year,_month);
}
int Date::GetMonthDay(int year,int month)
{
    int arr[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(month==2 && IsLeap(year))
    {
        ++arr[2];
    }
    return arr[month];
}
bool Date::IsLeap(int year)
{
    return (year%4==0 && year%100!=0) || year%400==0;
}
void Date::Show()
{
    cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
}
//析构
Date::~Date()
{
    cout<<"~Date()"<<endl;
}
//拷贝构造
Date::Date(const Date& d)
{
    cout<<"Date(Date& d)"<<endl;
    _year=d._year;
    _month=d._month;
    _day=d._day;
}
//d1 == d2
bool Date::operator==(const Date& d)
{
    if(_year==d._year && _month==d._month && _day==d._day)
    {
        return true;
    }
    return false;
}
//d1 != d2
bool Date::operator!=(const Date& d)
{
    if(_year==d._year && _month==d._month && _day==d._day)
    {
        return false;
    }
    return true;
}
//d1 > d2
bool Date::operator>(const Date& d)
{
    if(_year==d._year)
    {
        if(_month==d._month)
        {
            if(_day>d._day)
            {
                return true;
            }
        }
        else if(_month>d._month)
        {
            return true;
        }
    }
    else if(_year>d._year)
    {
        return true;
    }
    return false;
}
// d1 >= d2
bool Date::operator>=(const Date& d)
{
    return !(*this<d);
}
//d1 < d2
bool Date::operator<(const Date& d)
{
    return !(*this==d) && !(*this>d);
}
//d1 <= d2
bool Date::operator<=(const Date& d)
{
    return !(*this>d);
}
//d1 + 10
Date Date::operator+(int day)
{
    Date tmp(*this);
    tmp+=day;
    return tmp;
}
//d1 += 10
Date& Date::operator+=(int day)
{
    _day+=day;
    while(_day>GetMonthDay(_year,_month))
    {
        _day -= GetMonthDay(_year, _month);
        _month+=1;
        if(_month>12)
        {
            _year+=1;
            _month = 1;
        }
    }
    return *this;
}
//d1 - 10
Date Date::operator-(int day)
{
    Date tmp(*this);
    tmp -= day;
    return tmp;
}
//d1 -= 10
Date& Date::operator-=(int day)
{
    while(_day<=day)
    {
        _month-=1;
        if(_month==0)
        {
            _year-=1;
            _month=12;
        }
        _day+=GetMonthDay(_year,_month);
    }
    _day-=day;
    return *this; 
}
//d1 = d2
void Date::operator=(const Date& d)
{
    _day=d._day;
    _month=d._month;
    _day=d._day;
}
//d1 - d2
int Date::operator-(const Date& d)
{
    Date max(*this);
    Date min(d);
    int flag=1;
    if((*this)<d)
    {
        max=d;
        min=*this;
        flag=-1;
    }
    int count=0;

    while(max!=min)
    {
        min++;
        count++;
    }

    return flag*count;
}
//++d1 
Date& Date::operator++()
{
    *this+=1;
    return *this;
}

//d1++ 
Date Date::operator++(int)
{
    Date tmp(*this);
    *this+=1;
    return tmp;
}
//--d1
Date Date::operator--()
{
    *this-=1;
    return *this;
}
//d1--
Date Date::operator--(int)
{
    Date tmp(*this);
    *this-=1;
    return tmp;
}
//测试函数
void test()
{
    Date d1(2018,7,8);
//    d1.Show();
    Date d2(d1);
//    d2.Show();
//    bool ret= (d1==d2);
//    cout<<"ret expect true,actual:"<<ret<<endl;
//    Date d3(2018,7,9);
//    d3.Show();
//    ret= (d3!=d2);
//    cout<<"ret expect true,actual:"<<ret<<endl;
//
//    ret = d3>d1;
//    cout<<"ret expect true,actual:"<<ret<<endl;
//    ret = d3>=d1;
//    cout<<"ret expect true,actual:"<<ret<<endl;
//
//    ret = d1<d3;
//    cout<<"ret expect true,actual:"<<ret<<endl;
//    ret = d3<=d1;
//    cout<<"ret expect false,actual:"<<ret<<endl;

   Date d4=d1+10; 
   d4.Show();
   d4+=10; 
   d4.Show();

   Date d5=d1-10;
   d5.Show();
   d5-=10;
   d5.Show();

   Date d6(2018,9,1);
   --d6;
   d6.Show();
   d6--.Show();
   d6.Show();

   //int day = d5 - d6;
   //cout<<day<<endl;
}
int main()
{
    test();
    return 0;
}
