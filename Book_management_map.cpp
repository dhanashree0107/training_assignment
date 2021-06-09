// CPP program to demonstrate how a map can
// be used to have a user defined data type
// as key.
#include <bits/stdc++.h>
using namespace std;


struct Test {
	int id;
    string book_name;
    string Author;
    float cost;
}HT[10];

map<Test, int> mp1;
// We compare Test objects by their ids.
bool operator<(const Test& t1, const Test& t2)
{
	return (t1.id < t2.id);
}

void create(map<int,Test> mp){
    
    //Test t1;
    int id;
  	cin>>id;
    getline(cin>>ws,HT[id].book_name);
    getline(cin>>ws,HT[id].Author);
    cin>>HT[id].cost;
	mp[id] = HT[id];

    cout<<"Hello";
   // return mp;
}

void display(map<int,Test> mp){
    for(auto x:mp)
    {
        cout<<x.first<<" "<<x.second.book_name<<" "<<x.second.Author<<" "<<x.second.cost<<endl;
    }
}

int main()
{
    int n=1;
    map<int,Test> mp1;
	create(mp1);
    display(mp1);

  
	return 0;
}