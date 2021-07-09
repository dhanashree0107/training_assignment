/*
Program to count number of digits in the given number
Date: 02/06/2021 
*/
#include<iostream>
using namespace std;

int main(){
    long long int no;
    cout<<"Enter the number: ";
    cin>>no;
    int tot=0;
    while(no){
        tot+=1;
        no=no/10;
    }
    cout<<tot;
    return 0;
}