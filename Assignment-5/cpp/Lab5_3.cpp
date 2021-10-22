#include <bits/stdc++.h>

using namespace std;

void merge(int a[], int m, int l, int h)
{
	int i = l;
	int j = m + 1;
	int k = l;
	int *b = new int(h + 1);
	while (i <= m && j <= h)
	{
		if (a[i] < a[j])
		{
			b[k] = a[i];
			i++;
			k++;
		}
		else
		{
			b[k] = a[j];
			j++;
			k++;
		}
	}
	while (i <= m)
	{
		b[k] = a[i];
		k++;
		i++;
	}

	while (j <= h)
	{
		b[k] = a[j];
		j++;
		k++;
	}
	for (i = l; i <= h; i++)
	{
		a[i] = b[i];
	}
}

void MS(int a[], int l, int h)
{
	int m;
	if (l < h)
	{
		m = (l + h) / 2;

		MS(a, l, m);
		MS(a, m + 1, h);
		merge(a, m, l, h);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{

	int n, x;
	cout << "Enter the size of the array" << endl;
	cin >> n;
	int *arr = new int[n];
	cout << "Enter the elements of the array" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		arr[i] = x;
	}
	MS(arr, 0, n);
	printArray(arr, n);
	return 0;
}
