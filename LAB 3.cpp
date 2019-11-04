#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int flag=0;
	for(int i=0;i<n;i++)
	{   
		char value; stack<char> a;
		string s; cin>>s;
		for(int j=0;j<s.size();j++)
		{   
			value=s[j];
			switch (value)
			{
				case '(': a.push('('); break;
				case '<': a.push('<'); break;
				case '[': a.push('['); break;
				case '{': a.push('{'); break;
				case '}': if(a.empty())
						  {
						  	a.push(value);
				            flag = 1;
				          }
				          else
				          {
				           if(a.top() == '{')
				             a.pop();
				           else 
				          	flag = 1;
				          }
				          break;
				case ']': if(a.empty())
						  {
						  	a.push(value);
				            flag = 1;
				          }
				          else
				          {
				           if(a.top() == '[')
				             a.pop();
				           else 
				          	flag = 1;
				          }
				          break;
				case ')': if(a.empty())
				          {
				          	a.push(value);
				            flag = 1;
				          }
				          else
				          {
				           if(a.top() == '(')
				             a.pop();
				           else 
				          	flag = 1;
				          }
				          break;
				case '>': if(a.empty())
				          {
				           	a.push(value);
				            flag = 1;
				          }
				          else
				          {
				           if(a.top() == '<')
				             a.pop();
				           else 
				          	flag = 1;
				          }
				          break;
                case '|': if(a.empty())
                            a.push(value);
                          else
                          {
                          	if(a.top() == value)
				              a.pop();
                          	else 
                          	 a.push(value);
                          	}
                          break;

			}
		}
		if(a.empty())
		  cout<< "YES\n";
		else 
		{
			while(a.size())
			a.pop();
			cout<<"NO\n";
		}
		
	}
}