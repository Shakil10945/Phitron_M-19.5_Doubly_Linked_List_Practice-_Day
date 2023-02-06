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
struct Test
{
    int positions[10000];
};

void display(DoublyNode* &head);
void insertAtHead(DoublyNode* &head, int value);
void insertAtTail(DoublyNode* &head, int value);
int countSize(DoublyNode *head);
void insertAtSpecific(DoublyNode* &head, int value, int position);
int searchByValueUnique(DoublyNode* &head, int value);
Test searchByValueDuplicate(DoublyNode* &head, int value);

void display(DoublyNode* &head)
{
    if(head==NULL)
    {
        cout<< "Your Linked List is empty till now"<<endl;
    }
    else
    {
        DoublyNode *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->value;
            if(temp->Next!=NULL)
            {
                cout<< "->";
            }
            temp=temp->Next;
        }
    }
    cout<< endl;
}

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

void insertAtTail(DoublyNode* &head, int value)
{
    if(head==NULL)
    {
        insertAtHead(head,value);
    }
    else
    {
        DoublyNode *newNode=new DoublyNode(value);

        DoublyNode* temp=head;

        while(temp->Next!=NULL)
        {
            temp=temp->Next;
        }
        temp->Next=newNode;
        newNode->Prev=temp;
    }
}

int countSize(DoublyNode* head)
{
    int count=0;
    DoublyNode *temp=head;
    while(temp!=NULL)
    {
        temp=temp->Next;
        count++;
    }
    return count;
}

void insertAtSpecific(DoublyNode* &head, int value, int position)
{
    if(position==1)
    {
        insertAtHead(head,value);
    }
    else if(position==countSize(head)+1)
    {
        insertAtTail(head,value);
    }
    else if(position>1 && position<=countSize(head))
    {
        DoublyNode *newNode=new DoublyNode(value);

        DoublyNode *temp=head;
        int count=1;
        while(count+1!=position)
        {
            temp=temp->Next;
            count++;
        }
        newNode->Next=temp->Next;
        temp->Next->Prev=newNode;
        temp->Next=newNode;
        newNode->Prev=temp;
    }

    else
    {
        cout<< "Enter a valid position please : ";
        int pos;
        cin>> pos;
        insertAtSpecific(head,pos,value);
    }


}

int searchByValueUnique(DoublyNode* &head, int value)
{
    DoublyNode *temp=head;
    int position=0;

    while(temp!=NULL)
    {
        if(temp->value==value)
        {
            return position+1;
        }
        temp=temp->Next;
        position++;
    }
    cout<< "Enter a valid value please : ";
    int val;
    cin>>val;
    searchByValueUnique(head,val);
}

Test searchByValueDuplicate(DoublyNode* &head, int value)
{
    Test T;
    DoublyNode *temp=head;
    int position=1;
    int count=1;
    while(temp!=NULL)
    {
        if(temp->value==value)
        {
            T.positions[position]=count;
            position++;
        }
        temp=temp->Next;
        count++;
    }
    T.positions[0]=position;
    return T;
}


int main()
{
    DoublyNode *head=NULL;
    int value;
    int position;

    int choice;

    cout<< "Choice 1: for entering into head : "<<endl
        << "Choice 2: for entering into tail : "<<endl
        << "Choice 3: for counting the size : "<<endl
        << "Choice 4: for entering a value at a specific position : "<<endl
        << "Choice 5: for searching by a value in a unique linked list : "<<endl
        << "Choice 6: for searching by a value in a duplicated linked list :: "<<endl



        << endl
        << "Choice 50: for displaying the Doubly Linked List :"<<endl

        <<endl;

    cout<< "Enter your Choice : ";
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
                cout<< endl;
                break;
            }
        case 2:
            {
                cout<< "Enter the value you want to put into tail : ";
                cin>> value;
                insertAtTail(head,value);
                cout<< endl;
                break;
            }
        case 3:
            {
                int size=countSize(head);
                cout<< "Your doubly linked list's size is : "<<size<< endl;
                cout<< endl;
                break;
            }
        case 4:
            {
                cout<< "Enter the position after which you want to put a new value : ";
                cin>> position;
                cout<< "Enter your value : ";
                cin>>value;
                insertAtSpecific(head, value, position);
                cout<< endl;
                break;
            }
        case 5:
            {
                cout<< "Enter the value you want to search : ";
                cin>>value;
                position=searchByValueUnique(head,value);
                cout<< "The value "<<value<< " has been found at place "<<position<<endl;
                cout<< endl;
                break;
            }
        case 6:
            {
                cout<< "Enter the value you want to search : ";
                cin>>value;
                Test T;
                T=searchByValueDuplicate(head,value);
                int k=T.positions[0];
                for(int i=1;i<k;i++)
                {
                    cout<< T.positions[i];
                    if (i!=k-1)
                    {
                        cout<< "->";
                    }
                }
                cout<< endl;
                cout<<endl;
                break;
            }




        case 50:
            {
                display(head);
                break;
            }
        }
        cout<< "Enter your choice again : ";
        cin>>choice;
    }

    display(head);
    return 0;
}
