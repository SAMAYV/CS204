#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vll vector<long long>

class STACK
{
    private:
    int* arr;
    int size;

    public:
    STACK(){
      this->arr = new int [10000];
      this->size=0;
    }
    int sizes(){
        return size;
    }
    int top(){
        if(size!=0)
          return arr[size-1];
        return -1;
    }
    void push(int x){
        size++;
        arr[size-1]=x;
    }
    void pop(){
        if(size==0)
          return;
        size--;
    }
    bool isempty(){
      return size==0;
    }
};


int main() 
{ 
  STACK s;
  char u;
  int ch;
  do
  {
    cout<<"Enter your preference: 1 for push, 2 for pop, 3 for size, 4 for top element, 5 for empty stack checking"<<endl;
    cin>>ch;
    int x,y;
    switch (ch)
    {
      case 1 : cin>>x; 
               s.push(x);
               break;
      case 2 : cin>>y;
               s.pop(y);
               break;
      case 3 : cout<<s.sizes()<<endl;
               break;
      case 4 : cout<<s.top()<<endl;
               break;
      case 5 : cout<<s.isempty()<<endl;
               break;
      default : cout<<"Wrong case entered"<<endl;
                break;
    }  
    cout<<"Do you want to continue?(Y/y for Yes and N/n for No"<<endl;
    cin>>u;
  } while(u=='Y' || u=='y');
  return 0; 	
}