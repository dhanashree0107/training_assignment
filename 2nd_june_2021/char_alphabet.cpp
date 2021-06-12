/*
Problem Statement: write a program to find the given character is an alphabet or not
Date: 02/06/2021
*/

#include<iostream>
using namespace std;

int main(){
    char ch;
    cout<<"Enter the char: ";
    cin>>ch;
    if((ch>='a' && ch <='z') || (ch>='A' && ch <='Z'))
        cout<<ch<<" is an alphabet";
    else
        cout<<ch<<" is not an alphabet";
    return 0;
}