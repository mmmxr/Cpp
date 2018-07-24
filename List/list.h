#include <iostream>
#include <assert.h>
using namespace std;
template <class T>
struct ListNode
{
    ListNode<T>* _prev;
    ListNode<T>* _next;
    T _data;

    ListNode(const T& x)
        :_data(x)
         ,_prev(NULL)
         ,_next(NULL)
    {}
};
template <class T>
class List
{
    typedef ListNode<T> Node;
public:
    List()
    {
        _head=new Node(T());
        _head->_prev=_head;
        _head->_next=_head;
    }

    ~List()
    {
            
        Node* cur=_head->_next;
        while(cur!=_head)
        {
            _head->_next=cur->_next;
            delete cur;
            cur=_head->_next;
        }
        delete _head;
        _head=NULL;
    }

    List(const List<T>& l)
        :_head(new Node(T()))
    {
        Node* cur=l._head->_next;
        while(cur!=_head)
        {
            PushBack(cur->_data);
            cur=cur->_next;
        }
    }

    List<T>& operator=(const List<T>& l)
    {
        swap(_head,l._head);
        return *this;
    }

    void PushBack(const T x)
    {
        Insert(_head,x);
    }
    void PopBack()
    {
        Erase(_head->_prev);
    }
    void PushFront(const T x)
    {
        Insert(_head->_next,x);
    }
    void PopFront()
    {
        Erase(_head->_next);
    }
    //prev pos
    //prev newnode next
    void Insert(Node* pos,T x)
    {
        assert(pos);
        Node* new_node=new Node(x);
        Node* prev=pos->_prev;
        Node* next=pos;

        new_node->_next=next;
        next->_prev=new_node;
        new_node->_prev=prev;
        prev->_next=new_node;
    }
    //prev pos next
    void Erase(Node* pos)
    {
        assert(pos&&_head->_next!=_head);

        Node* next=pos->_next;
        Node* prev=pos->_prev;

        prev->_next=next;
        next->_prev=prev;

        delete pos;
    }
    const T& Front()
    {
        return _head->_next;
    }

    size_t Size()
    {
        Node* cur=_head->_next;
        size_t size=0;
        while(cur!=_head)
        {
            size++;
            cur=cur->_next;
        }
    }
    bool Empty()
    {
        return _head->_next==_head;
    }
    void Show()
    {
        Node* cur=_head->_next;
        while(cur!=_head)
        {
            cout<<cur->_data<<" ";
            cur=cur->_next;
        }
        cout<<endl;
    }



private:
    Node* _head;
};
#if 0
int main()
{
    List<int> L;
    L.PushBack(1);
    L.PushBack(2);
    L.PushBack(3);
    L.PushBack(4);
    L.PushBack(5);
    L.ListPrint();
    L.PopBack();
    L.PopBack();
    L.ListPrint();
    L.PushFront(9);
    L.PushFront(8);
    L.ListPrint();
    L.PopFront();
    L.ListPrint();
}
#endif
