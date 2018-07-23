#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
template <class T>
class Vector
{
protected:
    void Expand(size_t newcapacity)
    {
        if (newcapacity > Capacity())
        {
            T* tmp = new T[newcapacity];
            size_t size = Size();
            if (_first)
            {
                memcpy(tmp, _first, sizeof(T)*Size());
                for (size_t i = 0; i < Size(); i++)
                {
                    tmp[i] = _first[i];
                }
                delete[] _first;
            }
            _first = tmp;
            _finish = _first + size;
            _endofstorage = _first + newcapacity;
        }
    }
public:
    //默认成员函数
    Vector()
        : _first(NULL)
          , _finish(NULL)
          , _endofstorage(NULL)
    {}
    //v1=v2;
    Vector(const Vector<T>& v)
    {
        _first = new T[v.size()];
        _finish = _first + v.Size();
        _endofstorage = _first + v.Size();

        for (int i = 0; i < v.Size(); i++)
        {
            _first[i] = v._first[i];
        }
    }
    Vector<T>& operator=(const Vector<int>& v)
    {
        swap(_first, v._first);
        swap(_finish, v._finish);
        swap(_endofstorage, v._endofstorage);
        return *this;
    }


    ~Vector()
    {
        if (_first)
        {
            delete[] _first;
        }
        _first = _finish = _endofstorage;
    }

    void PushBack(const T x)
    {
        Insert(Size(), x);
    }
    void PopBack()
    {
        Erase(Size());
    }


    void Insert(size_t pos, const T& x)
    {
        //assert(pos <= Size());
        if (_finish == _endofstorage)
        {
            size_t newcapacity = Capacity() == 0 ? 3 : Capacity() * 2;
            Expand(newcapacity);
        }
        //搬运
        T* end = _finish - 1;
        while (end >= _first + pos)
        {
            *(end + 1) = *end;
            end--;
        }
        _first[pos] = x;
        ++_finish;
    }
    void Erase(size_t pos)
    {
        assert(pos <= Size());

        T* start = _first + pos;
        while (start < _finish - 1)
        {
            *start = *(start + 1);
            start++;
        }
        --_finish;
    }
    size_t Size() const
    {
        return _finish - _first;
    }
    size_t Capacity()
    {
        return _finish - _first;
    }
    bool Empty()
    {
        return _finish == _first;
    }
    T& operator[](size_t pos)
    {
        assert(pos < Size());
        return _first[pos];
    }
    void Resever(size_t size);

    void Resize(size_t size, const T& value = T());

protected:

    T* _first;
    T* _finish;
    T* _endofstorage;

};



