/*
Number to word conversion(indian system)
Date: 03/06/2021
*/

#include<iostream>
#include<cmath>
using namespace std;

string unit[] = { "", "one ", "two ", "three ", "four ","five ", "six ", "seven ", "eight ","nine ", "ten ", "eleven ", "twelve ","thirteen ", "fourteen ", "fifteen ","sixteen ", "seventeen ", "eighteen ","nineteen " };

string tenth[] = { "", "", "twenty ", "thirty ", "forty ","fifty ", "sixty ", "seventy ", "eighty ","ninety " };

string count[] = {"","Thousand ", "Lakh ", "crore ", "Arab ", "kharab ", "Nil ", "padma ", "shankh ", "mahashankh "};

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

string numToWords(unsigned long long int no){
    string str = "";
    int length = to_string(no).length();
    if(length>3){
        for(int i=19;i>=3;i=i-2){
        unsigned long long int p=0;
        p=pow(10,i);
        str=str + num_To_words((no/p)%100 , count[i/2]);
        }
    }

   str=str+ num_To_words((no/100)%10 , "hundred ");    //hundreads place
   str=str+ num_To_words((no%100) , "");        // unit place

   return str;

}

int main(){
    unsigned long long int number;
    cout<<"Enter the number";
    cin>>number;
    cout<<numToWords(number)<<endl;
    return 0;
}

/* ...............OUTPUT......................

Enter the number18446744073709551615
one mahashankh eighty four shankh forty six padma seventy four Nil forty kharab seventy three Arab seventy crore ninety five Lakh fifty one Thousand six hundred fifteen

PS C:\Users\Dhanashree\Documents\Training_assignments> ./a
Enter the number: 9223372036854775807
ninety two shankh twenty three padma thirty seven Nil twenty kharab thirty six Arab eighty five crore forty seven Lakh seventy five Thousand eight hundred seven

PS C:\Users\Dhanashree\Documents\Training_assignments> ./a
Enter the number: 99999999999
ninety nine Arab ninety nine crore ninety nine Lakh ninety nine Thousand nine hundred ninety nine

PS C:\Users\Dhanashree\Documents\Training_assignments> ./a 
Enter the number: 4294967295
four Arab twenty nine crore forty nine Lakh sixty seven Thousand two hundred ninety five

*/