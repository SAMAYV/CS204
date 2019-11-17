#include<bits/stdc++.h>

using namespace std;

#define lli long long 

struct node{
    lli data;
    node *next;
};

class LL{
    public:
    void insertend(lli x)
    {
        node *t=(node *)malloc(sizeof(node));
        if(t==NULL)
        {
            cout<<"Failed"<<endl; return;
        }
        t->data=x;
        t->next=NULL;
        if(this->start==NULL)
        {
            this->end=t;
            this->start=t;
        }
        else{
        this->end->next=t;
        this->end=t;
        }
        cout<<"Added "<<x<<endl;
    }
    void insertfront(lli x)
    {
        node *t=(node *)malloc(sizeof(node));
        if(t==NULL)
        {
            cout<<"Failed"<<endl; return;
        }
        t->data=x;
        t->next=NULL;
        if(this->start==NULL)
        {
            this->end=t;
            this->start=t;
        }
        else{
        t->next=this->start;
        this->start=t;
        }
        cout<<"Added "<<x<<endl;
    }
    void search(lli x)
    {
        node *t=this->start;
        while(t!=NULL)
        {
            if(t->data==x)
            {
                cout<<x<<" is present."<<endl;
                return;
            }
            t=t->next;
        }    
        cout<<x<<" is not in the list.";
        cout<<endl;
    }
    void deletekey(lli x)
    {
        node *t=this->start,*prev=NULL;
        while(t!=NULL)
        {
            if(t->data==x)
            {
                if(prev==NULL)
                {
                    this->start=t->next;
                }
                else
                {
                    prev->next=t->next;
                }
                delete t;
                cout<<"Deleted."<<endl;
                return;
            }
            prev=t;
            t=t->next;
        }
        cout<<"Not found"<<endl;  
    }
    void show()
    {
        node *t=this->start;
        while(t!=NULL)
        {
            cout<<t->data<<' ';
            t=t->next;
        }    
        cout<<endl;
    }
    LL()
    {
        this->end=NULL;
        this->start=NULL;
    }
    private:
    node *start,*end;
};

int main()
{
    LL Q;
    while(1){
    cout<<"Enter choice : \n 1. Insert \n 3. Show \n 4. Search \n 5. Delete \n 6. Exit \n";
    lli x;
    lli c;
    cin>>c;
    switch(c)
    {
        case 1: cin>>x;
                Q.insertfront(x);
                break;
        case 3: Q.show();
                break;
        case 4: cin>>x;
                Q.search(x);
                break;
        case 5: cin>>x;
                Q.deletekey(x);
                break;
        case 6: return 0;
        default: cout<<"Wrong choice!!"<<endl;

    }
    }
    return 0;
}