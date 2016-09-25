#include <iostream>
using namespace std;

template <class T>
struct CLNode
{
	T content;
	CLNode<T> *next;
};

template <class T>
class CircleList
{
public:
	CircleList(const T x);
	void Insert(int pos, T x);
	void Remove(int pos);
	bool Is_single() { return first->next == first; }
	CLNode<T>* Getfirst() { return first;}
	~CircleList();

private:
	CLNode<T> *first;
};

template <class T>
CircleList<T>::CircleList(const T x)
{
	first = new CLNode<T>;
	first->content = x;
	first->next = first;
	return;
}

template <class T>
CircleList<T>::~CircleList()
{
}

template <class T>
void CircleList<T>::Insert(int pos, T x)
{
	int i = 1;
	CLNode<T>* p;
	for (p = first; i != pos; p = p->next)
	{
		i++;
	}
	CLNode<T> *temp = new CLNode<T>;
	temp->next = p->next;
	temp->content = x;
	p->next = temp;
	return;
}

template <class T>
void CircleList<T>::Remove(int pos)
{
	int i = 1;
	CLNode<T>* p;
	for (p = first; i != pos - 1; p = p->next)
	{
		i++;
	}
	CLNode<T>* temp;
	temp = p->next;
	p->next = p->next->next;
	delete temp;
	return;
}



int main()
{
	int n, m;
	while (cin >> n)
	{
		cin >> m;
		int num=m;
		CircleList<int> a(1);
		for (int i = 2; i <= n; i++)
			a.Insert(i - 1, i);
		CLNode<int> *pre=NULL,*p=a.Getfirst();
		for (int i = 0; i < n - 1; i++) 
		{     									//执行n-1次
			for (int j = 1; j < m; j++) 		//数m-1个人
			{
				pre = p;  
				p = p->next;
			}
			pre->next = p->next;  
			delete p;     	//删去
			p = pre->next;
		}
		cout <<p->content<< endl;
		delete p;
	}
}