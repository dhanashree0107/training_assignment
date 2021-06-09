#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
using namespace std;

 typedef map<string, int> StrIntMap;

   void countWords(istream& in, StrIntMap& words) {
     string s;
     while (in >> s) {
        ++words[s];
     }
  }

int main() {
    string word;
    string filename;
    cout<<"\n Enter the filename: ";
    cin>>filename;
    ifstream inFile;
    inFile.open(filename);
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    
    StrIntMap w;
    countWords(inFile, w);
    cout<<"Enter the word to search:";
    cin>>word;
    for (StrIntMap::iterator p = w.begin();p != w.end(); ++p) {
              if(p->first == word){
                  cout << p->first << " occurred "<< p->second << " times.\n";
              }
    }
    inFile.close(); 
    return 0;
}