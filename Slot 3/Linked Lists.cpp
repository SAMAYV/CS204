#include<bits/stdc++.h>
using namespace std;

struct node
{
 int x;
 int y;
 struct node* next;
}*head;

struct node* createnode(int x,int y)
{
 struct node* temp = (struct node*)malloc(sizeof(struct node));
 temp->x = x;
 temp->y = y;
 temp->next = NULL;
 return temp;
}

void initialize()
{
 head = NULL;
}

void AddFirst(int x,int y)
{
 if(head == NULL)
   head = createnode(x,y);
 else 
 {
  struct node* temp = createnode(x,y);
  temp->next = head;
  head = temp;
 }
}

void DelFirst()
{
 if(head ==NULL)
  cout<<"-1";   //when node is not deleted due to underflow -1 is returned
 else 
 {
  struct node* temp = head->next;
  struct node* temp1 = head;
  head = temp;
  temp1->next = NULL;
  free(temp1); //when node is deleted successfully 0 is returned
 }
}

int length()
{
 struct node* temp = head;
 int count = 0;
 while(temp!=NULL)
 {
  count++;
  temp = temp->next;
 }
 return count;
}

string search(int x,int y)
{
    int c = length();
    struct node* temp = head;
    int i;
    for(i=1;i<=c;i++)
    {
        if(temp->x==x && temp->y==y)
        {
        	return "TRUE";
        	break;
        }
    	temp = temp->next;
    }
    if(i==c+1)
      return "FALSE";
}
 
void search(float d)
{
 int c=0;
 int count = 0;
 struct node* temp = head;
 while(temp!=NULL)
 {
  if((temp->x)*(temp->x) + (temp->y)*(temp->y) <= d*d)
  { 
   count++;
   c=1;
  }
  temp = temp->next;
 }
 if(c!=1)
  cout<<"-1\n";
 else cout<<count<<"\n";
}

void Del(int x,int y)
{
 if(head==NULL)
 	cout<<"-1\n";
 else
 {
 	 int flag = 0;
	 struct node* temp = head;
	 while(temp!=NULL)
	 {
	  if(temp->x==x && temp->y==y)
	  {
	  	flag=1;
	  	break;
	  }
	  temp=temp->next;
	 }
	 if(temp==NULL)
	  cout<<"-1";   //when node is not deleted due to no available x,y -1 is returned
	 else
	 {
	  temp = head;
	  if(temp->x==x && temp->y ==y)
	  {
	   struct node* temp1 = head->next;
	   head = temp1;
	   temp->next = NULL;
	   free(temp);
	  }
	  else
	  {
	   struct node* temp2 = head;
	   struct node* temp1 = NULL;
	   while(temp2->x!=x && temp2->y!=y)
	   {
	    temp1=temp2;
	    temp2=temp2->next;
	   }
	  temp1->next=temp2->next;
	  temp2->next=NULL;
	  free(temp2);
	  }  //when node is deleted successfully 0 is returned
	 }
  }
}

int main()
{
 int x,y;
 int count;
 int ch;
 float d;
 cin>>count;
 initialize();
 while(count--)
 {
  cin>>ch;
  switch (ch)
  {
  case 1: cin>>x>>y; AddFirst(x,y); break;
  case 2: DelFirst(); break;
  case 3: cin>>x>>y; Del(x,y);cout<<"\n"; break;
  case 4: cin>>d; search(d); break;
  case 5: cin>>x>>y; cout<<search(x,y)<<"\n"; break;
  case 6: cout<<length()<<"\n"; break;
  }
 }
 return 0;
}



















