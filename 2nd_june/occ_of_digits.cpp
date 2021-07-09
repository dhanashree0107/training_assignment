/*
to count Occurence of digit in the number
Date: 03/06/2021
*/
#include<iostream>
using namespace std;
void occ_of_digit(long long int number,int digit){
    int occ=0,rem;
    while(number){
        rem=number%10;
        if(rem==digit)
            occ++;
        number/=10;
    }
    cout<<"occ of "<<digit<<" in the number: "<<occ<<endl;
}

int main(){
    long long int number;
    int digit;
    cout<<"Enter the number: ";
    cin>>number;
    for(int i=0;i<=9;i++){
        occ_of_digit(number,i);
    }
    return 0;
}