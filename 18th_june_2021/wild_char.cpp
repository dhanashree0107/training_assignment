/*
Wild character
Date: 14/06/2021
*/

#include<iostream>
using namespace std;

void func(string &str,string &new_str,int &str_index,int &patt_index){
     new_str =new_str + str[str_index];
     str_index++;
     patt_index++;
}

int main(){
    string str,patt;
    cout<<"Enter the string: ";
    cin>>str;
    cout<<"Enter the pattern: ";
    cin>>patt;
    int n=str.length();
    int m=patt.length();
    int flag=0;
    for(int str_index=0;str_index<n;){
        string str2="";
        for(int patt_index=0;patt_index<m;){
            if(str[str_index]==patt[patt_index]){           //if char of string and pattern matches
                func(str,str2,str_index,patt_index);
            }
            else if(patt[patt_index]=='?'){                 //if we found "?" 
                flag=1;
                func(str,str2,str_index,patt_index);
    }
            else if(patt[patt_index]=='*'){                 //if we found "*"
                flag=1;
                if(patt_index==m-1){                        //if "*" is the last character in pattern
                    for(str_index;str_index<n;str_index++){
                        str2+=str[str_index];
                    }
                    patt_index++;
                }else{
                    patt_index++;                           //otherwise increment patt_index(char after *)
                    while(patt_index<m){                    
                        if(patt[patt_index]==str[str_index])        //if char of string and pattern matches
                          {
                              func(str,str2,str_index,patt_index);
                          }
                           else{                                    //add characters in the new string till we not found the match in pattern
                            str2+=str[str_index];
                            str_index++;
                        }
                    }
                }
           }

            else{
                if(str_index<n){                //check if string is empty or not              
                    str_index++;
                    patt_index=0;               //again initialize patt_index to zero
                    str2="";                    //set string to empty
                }else{
                    exit(1);
                }
            }
        }
        if(flag==1)
             cout<<str2<<endl;
        else
            cout<<"NULL";
    }

    return 0;
}

