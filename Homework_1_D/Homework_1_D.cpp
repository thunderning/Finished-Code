#include <iostream>
using namespace std;

template <class T>
struct DLNode
{
	T content;
	DLNode<T> *next,*prior;
    int freq;
};

template <class T>
class DoubleList
{
public:
    DoubleList(T x);
    void Insert(int pos, T x);
    void Locate(T x);
    void Print();
    ~DoubleList();

private:
    DLNode<T> *first,*last;
};

template <class T>
DoubleList<T>::DoubleList(T x)
{
    first = new DLNode<T>;
	first->content = x;
    first->freq = 0;
	first->next = NULL;
    last=first;
    first->prior = NULL;
	return;
}

template <class T>
DoubleList<T>::~DoubleList()
{
    DLNode<T> *temp;
    while(first!=NULL)
    {
        temp=first;
        first=first->next;
        delete temp;
    }
    return;
}

template <class T>
void DoubleList<T>::Insert(int pos, T x)
{
	int i = 1;
	DLNode<T>* p;
	for (p = first; i != pos; p = p->next)
	{
		i++;
	}
	DLNode<T> *temp = new DLNode<T>;
	temp->next = p->next;
    temp->prior=p;
    temp->freq = 0;
	temp->content = x;
	p->next = temp;
    temp->next->prior=temp;
	return;
}

template <class T>
void DoubleList<T>::Locate(T x)
{
    DLNode<T> *p;
    for(p=first;p!=NULL;p=p->next)
    {
        if(p->content == x) break;
    }
    p->freq++;
    while(p->prior!=NULL && p->prior->freq < p->freq)
    {
        DLNode<T> *temp=new DLNode<T>;
        temp->freq=p->freq;
        temp->content=p->content;
        p->freq=p->prior->freq;
        p->content=p->prior->content;
        p->prior->freq=temp->freq;
        p->prior->content=temp->content;
    }
    return;
}

template <class T>
void DoubleList<T>::Print()
{
    DLNode<T> *p;
    for(p=first;p->next!=NULL;p=p->next)
    {
        cout<<'<'<<p->content<<','<<p->freq<<">,";
    }
    cout<<'<'<<p->content<<','<<p->freq<<">"<<endl;
    return;
}

int main()
{
    int n,m;
    while(cin>>n)
    {
        cin>>m;
        int temp;
        cin>>temp;
        DoubleList<int> ll(temp);
        for(int i=1;i<n;i++)
        {
            cin>>temp;
            ll.Insert(i,temp);
        }
        for(int i=0;i<m;i++)
        {
            cin>>temp;
            ll.Locate(temp);
        }
        ll.Print();
    }
}