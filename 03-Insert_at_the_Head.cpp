#include<bits/stdc++.h>
using namespace std;

class DoublyNode
{
public:
    int value;
    DoublyNode* Prev;
    DoublyNode* Next;

    DoublyNode(int value)
    {
        this->value=value;
        Prev=NULL;
        Next=NULL;
    }
};

void insertAtHead(DoublyNode* &head, int value)
{
    DoublyNode *newNode=new DoublyNode(value);
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        newNode->Next=head;
        head->Prev=newNode;
        head=newNode;
    }
}










int main()
{
    DoublyNode *head=NULL;
    int value;

    int choice;

    cout<< "Choice 1: for entering into head : "<<endl



        << endl
        << "Choice 50: for displaying the Doubly Linked List :"<<endl

        <<endl;

    cout<< "Enter your Choice";
    cin>> choice;

    while(choice)
    {
        switch(choice)
        {
        case 1:
            {
                cout<< "Enter the value you want to put into head : ";
                cin>> value;
                insertAtHead(head,value);
                break;
            }
        }
        cout<< "Enter your choice again : ";
        cin>>choice;
    }



    return 0;
}
