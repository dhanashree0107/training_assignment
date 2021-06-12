/*
    Book Management System using linked list
    To store the records of books like ID , Book name, Author name, Cost
    We can create, insert, delete, search and display the record of books
    Can search by ID, book name or author name 
    Date: 08/06/2021
*/

#include <bits/stdc++.h>
using namespace std;
void create_book();
void insert_book();
void display_list();
void search();
void delete_book();

struct book_management
{
    int id;
    string book_name;
    string Author= "";
    float cost;
    struct book_management *next;
}*head;

int main(){
    head=NULL;
    int ch;
    cout<<"\n ..................Book Management System..................\n";
    do{
        cout<<"\n 1. Create list";
        cout<<"\n 2. Insert a new book";
        cout<<"\n 3. Search a book";
        cout<<"\n 4. Detete a book record";
        cout<<"\n 5. Display book list";
        cout<<"\n 6. exit";
        cout<<"\n Enter your choice:";
        cin>>ch;
        switch(ch){
            case 1 : create_book();
                     break;

            case 2 : insert_book();
                    break;
            
            case 3 : search();
                     break;

            case 4 : delete_book();
                     break;

            case 5 : display_list();
                     break;

            case 6 : exit;
        }
    }while(ch<6);

    return 0;
}

void create_book(){
    struct book_management *temp;
    temp = new book_management();     //Allocate memory
    cout<<"Enter the ID of book: ";      //store data in memory and making address null
    cin>>temp->id;
    cout<<"Enter the name of book: ";
    getline(cin>>ws,temp->book_name);
    cout<<"Enter the Auther of book: ";
    getline(cin>>ws,temp->Author);
    cout<<"Enter the cost of book: ";
    cin>>temp->cost;
    temp->next = NULL;
    if(head==NULL){
        head =temp;                 //Attach new node in list
    }else
        cout<<"Head is already created!!";

}

void insert_book(){
    struct book_management *temp,*p;
    temp = new book_management();
    cout<<"Enter the ID of book: ";      //store data in memory and making address null
    cin>>temp->id;
    cout<<"Enter the name of book: ";
    getline(cin>>ws,temp->book_name);
    cout<<"Enter the Auther of book: ";
    getline(cin>>ws,temp->Author);
    cout<<"Enter the cost of book: ";
    cin>>temp->cost;
    temp->next = NULL;
    p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=temp;
}


void search_by_id(){
    int id_search,flag=0;
    struct book_management *p;
    cout<<"\n Enter the ID to search:";
    cin>>id_search;
    p=head;
    while(p != NULL){
        if(id_search == p->id){
            flag=1;
            break;
        }
        p=p->next;
    }
    if(flag==0){
        cout<<"\n Record Not found";
    }else cout<<"\n Record found";
}

void search_by_book_name(){
    int flag=0;
    string name_search;
    struct book_management *p;
    cout<<"\n Enter the Book name to search:";
    getline(cin>>ws,name_search);
    p=head;
    while(p != NULL){
        if(name_search == p->book_name){
            flag=1;
            break;
        }
        p=p->next;
    }
    if(flag==0){
        cout<<"\n Record Not found";
    }else cout<<"\n Record found";
}

void search_by_author(){
    int flag=0;
    string author_search;
    struct book_management *p;
    cout<<"\n Enter the Book name to search:";
    getline(cin>>ws,author_search);
    p=head;
    while(p != NULL){
        if(author_search == p->Author){
            flag=1;
            break;
        }
        p=p->next;
    }
    if(flag==0){
        cout<<"\n Record Not found";
    }else cout<<"\n Record found";
}

void search(){
   // int id_search, flag=0,ch;
   int ch;  
            
        do{
            cout<<"\n 1. Search by ID";
            cout<<"\n 2. Search by book name";
            cout<<"\n 3. Search by author name";
            cout<<"\n 4. Quit";
            cout<<"\n Enter the Choice:";
            cin>>ch;
            switch(ch){
            case 1 : search_by_id();
                     break;

            case 2 : search_by_book_name();
                     break;

            case 3 : search_by_author(); 
                     break;

            case 4 : exit;
        }
        }while(ch<4);
        
}

void delete_book(){
    int search_id,flag=0;
    struct book_management *p,*q;
    cout<<"\n Enter ID to search: ";
    cin>>search_id;
    p=q=head;
    while(p != NULL){
        if(search_id == p->id){
            if(p == head){
                head = head->next;
                delete p;
                cout<<"Record is deleted for ID "<<search_id;
            }else{
                q->next = p->next;
                delete p;
                cout<<"Record is deleted for ID "<<search_id;
            }
            flag=1;
        }
        q=p;
        p=p->next;
    }

}



void display_list(){
    struct book_management* p = head;
    cout<<"\n";
    cout<<"............Book list............\n";
    cout<<"ID \t Book Name \t Author \t Cost \n";
    while(p != NULL){
       
        cout<<p->id<<"\t";
        cout<<p->book_name<<"\t";
        cout<<p->Author<<"\t";
        cout<<p->cost<<"\n";
        p=p->next;
        //cout<<"\n";
    }
    cout<<"\n";
}