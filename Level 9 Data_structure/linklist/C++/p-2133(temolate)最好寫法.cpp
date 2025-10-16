#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <string>
//#include <conio.h>
//#include <stdlib.h>
using namespace std;
//2133
 
template <class T>
class node
{
    public:
        T data;
         node<T> *next;
};
 
template <class T>
class LinkedList
{
    public:
        LinkedList();
        void insert(T &value);
        void remove(T &value);
        void find(T &value);
        void print();
        int  length ();
    private:
        node<T> *getnode ();
        void freenode (node<T> *p) ;
        void insert_node (node<T> *ptr, T &value);
        void delete_node(node<T> *ptr);
        node<T> *find_node(T &num);
 
        node<T> *head;
        node<T> *tail;
};
 
template <class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    tail = NULL;
}
 
template <class T>
node<T> *LinkedList<T>::getnode () /* ????????@??s?`?I */
{
    node<T> *p;
    p = new node<T>;
    if ( p == NULL)
    {
        cout << "?O??????" << endl;
        exit(1);
    }
    return(p);
}
 
template <class T>
void LinkedList<T>::freenode (node<T> *p) /* ?????N?`?I????O???? */
{
    delete p;
}
 
template <class T>
void LinkedList<T>::insert_node ( node<T> *ptr, T &value)
{
    node<T> *new_node;            /* ?s?`?I??????? */
    new_node = getnode();    /* ???s?`?I,???o?@??i?£c`?I */
    new_node->data = value; /* ???`?I???e */
    new_node->next = NULL; /* ?]?w?????? */
 
    if ( ptr == NULL ) /* ????ptr?O?_?ONULL */
    {
        /* ??@????p: ???J??@??`?I */
        new_node->next = head; /* ?s?`?I??????C?}?l */
        head = new_node;
    }
    else
    {
        if ( ptr->next == NULL ) /* ?O?_?O??C???? */
            /* ??G????p: ???J???@??`?I */
            ptr->next = new_node; /* ?????V?s?`?I */
        else
        {
            /* ??T????p: ???J?????????`?I */
            new_node->next = ptr->next; /* (3) ?s?`?I???V?U?@?`?I (3)*/
            ptr->next = new_node; /* ?`?Iptr???V?s?`?I (4)*/
        }
    }
}
 
template <class T>
void LinkedList<T>::delete_node(node<T> *ptr)
{
    node<T> *previous; /* ???V?e?@?`?I */
    if ( ptr == head ) /* ?O?_?O??C?}?l */
    /* ??@????p: ?R????@??`?I */
    {
        head = head->next;
    }
    else
    {
        previous = head;
        while ( previous->next != ptr ) /* ??`?Iptr???e?`?I */
            previous = previous->next;
        if ( ptr->next == NULL ) /* ?O?_?O??C???? */
        /* ??G????p: ?R?????@??`?I */
            previous->next = NULL; /* ???@??`?I */
        else
        /* ??T????p: ?R???????`?I */
            previous->next = ptr->next; /* ??(3)???B?J(1) */
    }
    freenode(ptr); /* ?????N?`?I?k????O???? */
}
template <class T>
node<T> *LinkedList<T>::find_node(T &num)
{
    node<T> *ptr;
    ptr = head; /* ???V??C?_?l */
    while ( ptr != NULL ) /* ???X??C */
    {
        if ( ptr->data == num ) /* ??Mdata */
        return (ptr);
        ptr = ptr->next; /* ???V?U?@?`?I */
    }
    return (ptr);
}
template <class T>
int LinkedList<T>::length () /* ?????p??`?I???????? */
{
    int num=0;
    node<T> *q = head;
    while (q != NULL)
    {
        num ++;
        q = q->next;
    }
    return(num);
}
 
template <class T>
void LinkedList<T>::insert(T &value)
{
    if(head==NULL)
    {
        head = getnode();
        head->data=value;
        head->next=NULL;
        tail = head;
    }
    else
    {
        insert_node(tail, value);
        tail = tail->next;
    }
    //cout << "data insert success" <<  endl;
}
 
template <class T>
void LinkedList<T>::remove(T &value)
{
    node<T> *prev, *ptr;
    ptr = find_node(value);
    if(ptr != NULL)
    {
        if(length()==1)
        {
            delete_node(ptr);
            tail = NULL;
        }
        else if(ptr->next==NULL)
        {
            prev = head;
            while(prev->next != ptr)
                prev = prev->next;
            delete_node(ptr);
            tail = prev;
        }
        else
        {
            delete_node(ptr);
        }
        cout << "Delete ok" <<  endl;
    }
    else
    {
        cout << "No data" <<  endl;
    }
}
 
template <class T>
void LinkedList<T>::find(T &value)
{
    node<T> *ptr;
    ptr = find_node(value);
    if(ptr != NULL)
    {
        cout << "found " <<  ptr->data << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}
 
template <class T>
void LinkedList<T>::print()
{
    node<T> *q = head;
    while (q != NULL)
    {
        cout << q->data << " ";
        q = q->next;
    }
    cout << endl;
}
 
template<class T>
void useList(T value)
{
    LinkedList<T> list;
    //string value;
    int  num_item;
    //char key;
    int ikey;
    while(1)
    {    /*
        cout << "1: ???J" << endl;
        cout << "2: ?R??" << endl;
        cout << "3: ?M??" << endl;
        cout << "5: ????" << endl;
        cout << "6: ?C?L" << endl;
        cout << "4: ???}" << endl;
        cout << "> ";
        //key = getche();
        cout << endl;
        */
        cin >> ikey;
        switch(ikey)
        {
            case 1:
                //cout << "??J???J?????e: ";
                cin >> value;
                list.insert(value);
                break;
            case 2:
                //cout << "??J?R???????e: ";
                cin >> value;
                list.remove(value);
                break;
            case 3:
                //cout << "??J?M??????e: ";
                cin >> value;
                list.find(value);
                break;
            case 5:
                num_item=list.length();
                cout << "Number of item is " << num_item << endl;
                break;
            case 6:
                list.print();
                break;
            case 4:
                //cout << "ByeBye!" << endl;
                exit(0);
            default:
                cout << "Input error!" << endl;
            //    break;
        }
        //cout << endl;
    }
}
 
int main()
{   
    int sel;
    cin >> sel;
    switch(sel)
    {
        case 1://int
            cout <<"<Integer List>" << endl;
            useList(1);           
 
        break;
        case 2://double
            cout <<"<Double List>" << endl;   
            useList(1.1);
 
        break;
        case 3://char
            cout <<"<Char List>" << endl;
            useList('A');           
 
        break;
        case 4://string
            string s;
            cout <<"<String List>" << endl;
            useList(s);           
 
        break;
 
        //default:
        //    cout << "??J????~!" << endl;
        //break;
    }
 
    return 0;
}
