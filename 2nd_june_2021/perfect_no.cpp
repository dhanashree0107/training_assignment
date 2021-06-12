/*
	finding the perfect numbers between the given range
	Date: 03/06/2021
*/

#include<iostream>
using namespace std;

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