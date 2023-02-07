#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;

    Node(int value)
    {
        this->value=value;
        Next=NULL;
    }
};
void insertionAtTail(Node* &head,int value)
{
    Node *newNode=new Node(value);
    Node *temp=head;

    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        while(temp->Next!=NULL)
        {
            temp=temp->Next;
        }
        temp->Next=newNode;
    }
}

void display(Node* head)
{
    if(head==NULL)
    {
        cout<< "Sorry the Linked List is empty";
    }
    else
    {
        Node *temp=head;
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
    cout<<endl;
}

int main()
{
    Node *head=NULL;
    int n;
    cin>>n;
    while(n--)
    {
        int value;
        cin>>value;
        if(value%2==0)
        {
            insertionAtTail(head,-1);
        }
        else
        {
            insertionAtTail(head,value);
        }

    }
display(head);


    return 0;
}
