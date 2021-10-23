// selection sort using recursion
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void swap_fun(int arr[],int a,int b)
{
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
void selection_sort(int arr[],int start,int no_of_elements)
{
   int min=start;
   for(int j=start+1; j<no_of_elements; j++)
   {
       if(arr[j]<arr[min])
        min=j;
   }
   swap_fun(arr,min,start);
   if(start+1<no_of_elements)
   {
       selection_sort(arr,start+1,no_of_elements);
   }
}
void print_arr(int arr[],int n)
{
    for(int i=0;i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n, x;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr[i] = x;
    }
    print_arr(arr,n);
    selection_sort(arr,0,n);
    print_arr(arr,n);
    return 0;
}