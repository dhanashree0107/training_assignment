#include<iostream>
#include<cmath>
using namespace std;

string unit[] = { "", "one ", "two ", "three ", "four ","five ", "six ", "seven ", "eight ","nine ", "ten ", "eleven ", "twelve ","thirteen ", "fourteen ", "fifteen ","sixteen ", "seventeen ", "eighteen ","nineteen " };

string tenth[] = { "", "", "twenty ", "thirty ", "forty ","fifty ", "sixty ", "seventy ", "eighty ","ninety " };

string count[] = {"","Thousand ", "Lakh ", "crore ", "Arab ", "kharab ", "Nil ", "padma ", "shankh ", "mahashankh "};

string num_To_words(int no,string s){
    string str = "";
    cout<<no<<endl;
    if (no > 19)
        str += tenth[no / 10] + unit[no % 10];
    else
        str += unit[no];
 
    if (no)
        str += s;
 
    return str;
}

string numToWords(long long int no){

    string str = "";

    int length = to_string(no).length();
    
   if(length>3){
       for(int i=19;i>=3;i=i-2){
        long long tot=0;
        tot= no/pow(10,i);
        str=str + num_To_words(tot%100 , count[i/2]);

    }
   }

   str=str+ num_To_words((no/100)%10 , "hundred ");    //hundreads place

   str=str+ num_To_words((no%100) , "");

   return str;

}

int main(){
    long long int number;
    cout<<"Enter the number";
    cin>>number;
    cout<<numToWords(number)<<endl;
    return 0;
}