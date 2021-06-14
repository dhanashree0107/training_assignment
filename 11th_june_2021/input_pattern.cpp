/*
Wild character
Date: 14/06/2021
*/

#include<iostream>
using namespace std;
int main(){
    string str,patt;
    cout<<"Enter the string: ";
    cin>>str;
    cout<<"Enter the pattern: ";
    cin>>patt;
    int n=str.length();
    int m=patt.length();
    int flag=0;
    for(int i=0;i<n;){
        string str2="";
        for(int j=0;j<m;){
            if(str[i]==patt[j]){
                str2+=str[i];
                i++;
                j++;
            }
            else if(patt[j]=='?'){
                flag=1;
               str2+=str[i];
                i++;
                j++;
            }
            else if(patt[j]=='*'){
                flag=1;
                if(j==m-1){
                    for(i;i<n;i++){
                        str2+=str[i];
                    }
                    j++;
                }else{
                    j++;
                    while(j<m){
                        if(patt[j]==str[i]){
                            str2+=str[i];
                            i++;
                            j++;
                        }else{
                            str2+=str[i];
                            i++;
                        }
                    }
                }
           }

            else{
                if(i<n){
                    i++;
                    j=0;
                    str2="";
                }else{
                    exit(1);
                }
            }
        }
        if(flag==1)
             cout<<str2<<endl;
        else
            cout<<" ";
    }

    return 0;
}

/*
...........................OUTPUT.........................
Enter the string: abcpaqc
Enter the pattern: a?c
abc

Enter the string: 123abcgrdgdb
Enter the pattern: a*

Enter the string: acde
Enter the pattern: abc

Enter the string: adfhjhcghjkaghjc
Enter the pattern: a*c
adfhjhc
aghjc


*/