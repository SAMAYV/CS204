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
  s.push(1);
  cout<<s.sizes()<<"\n";
  cout<<s.top()<<"\n";
  s.push(2);
  s.push(3);
  cout<<s.sizes()<<"\n";
  s.push(5);
  s.pop();
  cout<<s.sizes()<<"\n";
  s.pop();
  cout<<s.top()<<"\n";
  return 0; 	
}