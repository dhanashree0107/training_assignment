#include<iostream>
using namespace std;

bool palindrome(string str){
    int flag=0;
    int length=str.length();
    for(int i=0,j=length-1;i<length,j>=0;i++,j--){
        if(i<j || i!=j){                //i<j - condition for odd string , i!=j - condition for even string
            if(str[i]==str[j])
                flag=1;
            else    return 0;
        }
    }
    if(flag==1)
        return 1;
    else return 0;
}

int main(){
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    bool u=palindrome(str);
    cout<<u;
}

/* ..........................OUTPUT.......................

Enter the string: NITIN
1

Enter the string: MALAYALAM
1

Enter the string: aaaaabbbbbbaaaaa
1

Enter the string: aaaaaaaaaaabbbbbbbbbbbbbbb
0

*/
