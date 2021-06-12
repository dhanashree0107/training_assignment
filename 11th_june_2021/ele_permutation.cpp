/*
Problem statement: Given an array of elements, return all possible permutations of the elements in the array
Date:12/06/2021
*/

#include<iostream>
using namespace std;

void printarray(int arr[], int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<"\t";
    }
   cout<<"\n";
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(int *arr, int start, int end)
{
    if(start==end)
    {
        printarray(arr, end+1);
        return;
    }
    int i;
    for(i=start;i<=end;i++)
    {
        swap((arr+i), (arr+start));
        permutation(arr, start+1, end);
        swap((arr+i), (arr+start));
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int i;
    int arr[n];
    cout<<"Enter the elements: "<<endl;
    for(i=0;i<n;i++)
        cin>>arr[i];

    cout<<"\n Possible permutations are: "<<endl;
    permutation(arr, 0, n-1);
    return 0;
}
