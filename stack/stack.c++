#include <iostream>
#include<string>
#include<algorithm>
#include<array>
#include <stack>

using namespace std;

template<class T, size_t S>
class Stack
{

public:


	void push(const T& val)
	{
		arr[cont] = val;
		cont++;
	}
	void pop()
	{
		if (cont) { cont--; }
		else { __debugbreak(); }
	}

	const bool full()const
	{
		return cont == S;
	}
	const bool empty()const
	{
		if (cont == 0) { return true; }
		else return false;
	}
	const T& top()const
	{
		if (!empty()) { return arr[cont - 1]; }
		else { __debugbreak(); }
	}

	const int count()const
	{
		return cont;
	}

	void change(int pos, T val)
	{
		arr[pos] = val;
	}

	const T& peek(int pos)const
	{
		return arr[pos];
	}

	const void display()const
	{
		for (int i = cont - 1; i >= 0; i--)
		{
			cout << arr[i] << endl;
		}
	}
	void insert(int index, T& value)
	{
		for (int i = cont; i > index; i--)
		{
			arr[i] = arr[i - 1];
		}
		//because we will insert new element
		cont++;
		arr[index] = value;
	}

private:
	int cont = 0;
	T arr[S];

};
