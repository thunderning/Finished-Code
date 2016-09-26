#include <iostream>
using namespace std;

template <class T>
class SeqList
{
public:
	SeqList(int num);
	void Write(int pos, T temp) { content[pos] = temp; }
	T Read(int pos) { return content[pos]; }
	void Print()
	{
		for (int i = 0; i < max-1; i++)
		{
			cout << content[i] << " ";
		}
        cout <<content[max-1]<< endl;
		return;
	}
	void Merge(SeqList<T> *a, SeqList<T> *b, SeqList<T> *ret);
	~SeqList();
private:
	T *content;
	int max;
};
template <class T>
void SeqList<T>::Merge(SeqList<T> *a, SeqList<T> *b, SeqList<T> *ret)
{
	if (a->max > b->max)
	{
		SeqList<T>* temp = a;
		a = b;
		b = temp;
	}
	int i = 0, j = 0, k = 0;
	for (; i < a->max; i++)
	{
		for (; j < b->max; j++)
		{
			if (a->Read(i) <= b->Read(j))
			{
				ret->Write(k++,a->Read(i));
				break;
			}
			else
			{
				ret->Write(k++,b->Read(j) );
			}
		}
		if (j == b->max) break;
	}
	if (i < a->max)
	{
		for (; i < a->max; i++)
		{
			ret->Write(k++,a->Read(i));
		}
	}
	if (j < b->max)
	{
		for (; j < b->max; j++)
		{
			ret->Write(k++,b->Read(j));
		}
	}
	return;
}

template <class T>
SeqList<T>::SeqList(int num)
{
	content = new T[num];
	max = num;
	return;
}

template <class T>
SeqList<T>::~SeqList()
{
	delete content;
	return;
}

int main()
{
	int m, n;
	while (cin >> m)
	{
		cin >> n;
		SeqList<int> l1(m), l2(n), l3(m + n);
		int temp;
		for (int i = 0; i < m; i++)
		{
			cin >> temp;
			l1.Write(i, temp);
		}
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			l2.Write(i, temp);
		}
		l1.Merge(&l1, &l2,&l3);
		l3.Print();
	}
	return 0;
}