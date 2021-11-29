
#include <iostream>
#include<string>

using namespace std;

template<class T, size_t S>
class Queue
{

public:


	void push_back(const T& val)
	{
		if (is_full()) { __debugbreak(); }

		else if (is_empty())
		{
			rear = front = 0;
		}
		else { rear = (rear + 1) % S; } //--> use circale array to solve the problem of pop, so the next index is not just rear+1 its rear+1 %size

		arr[rear] = val;
	}
	void pop_front()
	{
		if (is_empty()) { cerr << "queue is empty"; }
		//rear == front meaning that i have only one element in the queue
		else if (rear == front) { front = rear = -1; }
		else { front = (front + 1) % S; }
	}
	T Front()
	{
		if (is_empty()) { cerr << "queue is empty"; }
		else { return arr[front]; }
	}

	bool is_full()
	{
		if (((rear + 1) % S) == front) { return true; }
		else { return false; }
	}
	bool is_empty()
	{
		if (rear == -1 && front == -1) { return true; }
		else { return false; }
	}
	void display()
	{
		if (front < rear)
		{
			for (int i = front; i <= rear; i++)
			{
				cout << arr[i] << endl;
			}
		}
		else
		{
			cout << "bs yallaa";
		}
	}
	int front = -1;
	int rear = -1;
	T arr[S];

};


int main()
{

	Queue<int, 5>q;
	q.push_back(5);
	q.push_back(4);
	q.push_back(3);
	q.push_back(2);
	q.push_back(1);
	q.display();

}
