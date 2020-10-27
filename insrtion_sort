#include <iostream>

using namespace std;


/*o(n) steps and o(n) operation(reversed sorted list ,is n/2 and and last element i will
	go n times till it reach the beginning so its o(n^2) algorithm)*/

void selection_sort(int arr[],int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = arr[i];
		int j = i - 1;
		int s = i;
		while (j >= 0 && arr[j] > key)
		{
			//arr[j+1]=arr[j];
			swap(arr[s], arr[j]);
			j -= 1;
			s -= 1;
		}
		//arr[j+1]=key;
	}

}
