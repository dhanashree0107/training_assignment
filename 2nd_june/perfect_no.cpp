/*
	finding the perfect numbers between the given range
	Date: 03/06/2021
*/
#include<iostream>
using namespace std;
/*
int main(){

    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int sum;
   for(int i=1;i<=n;i++){
   	sum=0;
   	for(int j=1;j<=i/2;j++){
   		if(i%j==0){
   			sum+=j;
		   }
	   }
	   if(sum==i){
	   	cout<<i<<" ";
	   }
   }
    return 0;
}

*/


int sumofDivisors(int num, int x)
{
        if(x==1)
                return 1;
        if(num%x==0)
                return x + sumofDivisors(num,x-1);
        else
                return sumofDivisors(num,x-1);
}

int main()
{
        int n;
        cout<<"Enter the number: ";
		cin>>n;
		for(int i=2;i<=n;i++){
				 if(sumofDivisors(i, i/2) == i)
				 	cout<<i<<"\t";
		}

}

