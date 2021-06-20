/*
	finding the perfect numbers between the given range using recursion
	Date: 20/06/2021
*/

#include<iostream>
using namespace std;

int sumofDivisors(int no, int x)
{
        if(x==1)
            return 1;
        if(no%x==0)
            return x + sumofDivisors(no,x-1);   //if x is divisor then add it
        else
            return sumofDivisors(no,x-1);
}

int main()
{
        int n;
        cout<<"Enter the number: ";
		cin>>n;
		for(int i=2;i<=n;i++){
				 if(sumofDivisors(i, i/2) == i) //checking if the no is eqal to the addition of divisors
				 	cout<<i<<"\t";
		}
       
}
