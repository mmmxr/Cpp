#include <iostream>
using namespace std;
template <class T>
class Auto_Ptr{
public:
    Auto_Ptr(T* ptr)
        :_ptr(ptr)
    {}
    ~Auto_Ptr()
    {
        if(_ptr!=NULL)
        {
            cout<<"delete _ptr"<<endl;
            delete _ptr;
        }
    }
    T& operator*()
    {
        return *_ptr;
    }

    T* operator->()
    {
        return _ptr;
    }
    Auto_Ptr(Auto_Ptr<T>& ap)
        :_ptr(ap._ptr)
    {
        ap._ptr=NULL;
    }
    //ap3=ap2;
    T& operator=(Auto_Ptr<T>& ap)
    {
        if(this!=&ap)
        {
            if(_ptr!=NULL)
            {
                delete _ptr;
            }
            _ptr=ap._ptr;
            ap._ptr=NULL;
        }
        return *this;
    }

private:
    T* _ptr;
};

template <class T>
class Scoped_Ptr
{
public:
    Scoped_Ptr(T* ptr)
        :_ptr(ptr)
    {}
    ~Scoped_Ptr()
    {
        delete _ptr;
    }
    T& operator*()
    {
        return *_ptr;
    }
    T* operator->()
    {
        return _ptr;
    }
private:
    //防拷贝
    //只声明不实现
    //定义为私有的，也不允许你在外面实现
    Scoped_Ptr(const Scoped_Ptr<T>& sp);
    Scoped_Ptr<T>& operator=(const Scoped_Ptr<T>& sp);
private:
    T* _ptr;
};

template<class T>
class Shared_Ptr
{
public:
    Shared_Ptr(T* ptr)
        :_ptr(ptr)
    {
        _pcount=new int(1);
    }
    ~Shared_Ptr()
    {
        if(--(*_pcount)==0)
        {
            delete _ptr;
            delete _pcount;
        }
    }
    Shared_Ptr(const Shared_Ptr& sp)
        :_ptr(sp._ptr)
         ,_pcount(sp._pcount)
    {
        ++(*_pcount);
    }
    //sp1=sp2;
    Shared_Ptr<T>& operator=(const Shared_Ptr<T>& sp)
    {
        if(_ptr!=sp._ptr)
        {
            if(--(*_pcount)==0)
            {
                delete _pcount;
                delete _ptr;
            }
            _ptr=sp._ptr;
            _pcount=sp._pcount;
            ++(*_pcount);
        }
        return *this;
    }
    T& operator*()
    {
        return *_ptr;
    }

    T* operator->()
    {
        return _ptr;
    }
private:
    T* _ptr;
    int* _pcount;

};

template<class T>
class Weak_Ptr{
public:
    Weak_Ptr(const Weak_Ptr<T>& ptr)
        :_ptr(ptr)
    {}
    T& operator*()
    {
        return *_ptr;
    }
    T* operator->()
    {
        return _ptr;
    }
private:
    T* _ptr;
};
int main()
{

    return 0;
}
