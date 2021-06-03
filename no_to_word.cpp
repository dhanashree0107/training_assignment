#include<iostream>
#include<cmath>
using namespace std;

string unit[] = { "", "one ", "two ", "three ", "four ","five ", "six ", "seven ", "eight ","nine ", "ten ", "eleven ", "twelve ","thirteen ", "fourteen ", "fifteen ","sixteen ", "seventeen ", "eighteen ","nineteen " };

string tenth[] = { "", "", "twenty ", "thirty ", "forty ","fifty ", "sixty ", "seventy ", "eighty ","ninety " };

string num_To_words(int no,string s){
    string str = "";
    if (no > 19)
        str += tenth[no / 10] + unit[no % 10];
    else
        str += unit[no];
 
    if (no)
        str += s;
 
    return str;
}

string numToWords(long long int no){
    string str ="";

    str=str+ num_To_words((no/pow(10,9)) , "arab ");
 
    str=str+ num_To_words((no/10000000 ) % 100 , "crore ");    //crore and 10 crore places

    str=str+ num_To_words((no/100000)%100 , "lakh ");       //lakh and ten lakh places

    str=str+ num_To_words((no/1000)%100 , "thousand ");    //thousands and ten thousands place

    str=str+ num_To_words((no/100)%100 , "hundred ");    //hundreads place

    str=str+ num_To_words((no%100) , "");    //unit and tenth place

    return str;

}

int main(){
    long long int number;
    cout<<"Enter the number";
    cin>>number;
    cout<<numToWords(number)<<endl;
    return 0;
}