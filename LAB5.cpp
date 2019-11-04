#include<bits/stdc++.h>
using namespace std;
map<string,int> chart;

struct node 
{ 
    string value; 
    node* left, *right; 
}; 

int prec(string c) 
{ 
    if(c == "^") 
    return 3; 
    else if(c == "*" || c == "/") 
    return 2; 
    else if(c == "+" || c == "-") 
    return 1; 
    else
    return -1; 
} 

string removeSpaces(string str) 
{ 
    int i = 0, j = 0; 
    while (str[i]) 
    { 
        if (str[i] != ' ') 
           str[j++] = str[i]; 
        i++; 
    } 
    str[j] = '\0'; 
    return str; 
} 
bool isOperator(string c) 
{ 
    if (c.length()==1 && (c == "+" || c == "-" || c == "*" || c == "/" || c == "^") )
        return true; 
    return false; 
} 

node* newNode(string v) 
{ 
    node *temp = new node; 
    temp->left = temp->right = NULL; 
    temp->value = v; 
    return temp; 
}; 
  

vector<string> infixToPostfix(vector<string> s) 
{ 
    std::stack<string> st; 
    st.push("N"); 
    int l = s.size(); 
    vector<string> ns; 
    for(int i = 0; i < l; i++) 
    { 
        // If the scanned character is an operand, add it to output string. 
        if(!isOperator(s[i]) && s[i]!="" && s[i]!="(" && s[i]!=")") 
         ns.push_back(s[i]); 
        // If the scanned character is an ‘(‘, push it to the stack. 
        else if(s[i] == "(")   
        st.push("(");     
        // If the scanned character is an ‘)’, pop and to output string from the stack 
        // until an ‘(‘ is encountered. 
        else if(s[i] == ")") 
        { 
            while(st.top() != "N" && st.top() != "(") 
            { 
                string c = st.top(); 
                st.pop(); 
              if(c!="" && c!="(" && c!=")")
                ns.push_back(c);   
            } 
            if(st.top() == "(") 
            { 
                //string c = st.top(); 
                st.pop();  
            } 
        } 
        //if an operator is scanned 
        else
        { 
            while(st.top() != "N" && prec(s[i]) <= prec(st.top())) 
            { 
                if(s[i]=="^" && st.top()=="^") break;
                //if(s[i]=="$" && st.top()=="$") break;
                string c = st.top(); 
                st.pop(); 
                if(c!="" && c!="(" && c!=")")
                  ns.push_back(c); 
            } 
            st.push(s[i]); 
        } 
    } 
    //pop all the remaining elements from the stack 
    while(st.top() != "N") 
    { 
        string c = st.top(); 
        st.pop();       
        if(c!="" && c!="(" && c!=")")
          ns.push_back(c);  
    } 
    return ns;
} 
// returns root of constructed tree for given 
// postfix expression 
node* constructTree(vector<string> postfix) 
{ 
    stack<node*> st; 
    node *t, *t1, *t2; 
    // Traverse through every character of 
    // input expression 
    for (int i=0; i<postfix.size(); i++) 
    { 
        // If operand, simply push into stack 
        if (!isOperator(postfix[i])) 
        { 
            t = newNode(postfix[i]); 
            st.push(t); 
        } 
        else // operator 
        { 
            t = newNode(postfix[i]); 
            // Pop two top nodes 
            t1 = st.top(); // Store top 
            st.pop();      // Remove top 
            t2 = st.top(); 
            st.pop(); 
            //  make them children 
            t->right = t1; 
            t->left = t2; 
            // Add this subexpression to stack 
            st.push(t); 
        } 
    } 
    //  only element will be root of expression 
    // tree 
    t = st.top(); 
    st.pop(); 
    return t; 
} 
int eval(node * root)
{
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL)
    {
        try 
        { 
          return stoi(root->value);
        }
       catch(...)
       {
        if(chart.find(root->value)!=chart.end()) return chart[root->value];
        else 
        { 
          return INT_MAX;
        }
        
     }
    }
    int l=eval(root->left);
    int r=eval(root->right);
    if(l==INT_MAX || r==INT_MAX) return INT_MAX;
    if(root->value=="+") return l+r;
    else if(root->value=="-") return l-r;
    else if(root->value=="*") return l*r;
    else if(root->value=="/") return l/r;
    else return pow(l,r);
}
vector<string> gdstring(string s)
{
    int flag=0;
    int mark=0;
    string temp="";
    vector<string> str;
    for(int i=0; i<s.length();i++)
    {
        //string temp="";
        if( (s[i]>=48 && s[i]<=57) || (s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) )
        {
            temp+=s[i];
        }    
        else
        {
          if((temp=="" && s[i]=='-' && i==0) || (temp=="" && s[i]=='-' && s[i-1]!=')' ) ) //check if unary minus is thee
          {
            str.push_back("("); 
            str.push_back("0"); 
            str.push_back("-"); 
            if(s[i+1]=='(') flag+=1; //expression has minus on it
            else mark+=1; //just a number has minus on it
          }
          else
          {
            if(temp!="") str.push_back(temp);  //to push number or variablke formed  
            while(mark>0) 
            { 
              str.push_back(")"); // close as many unary minus were opened
              mark--;
            }
            temp=""; temp+=s[i]; //to convert the operator or bracket  to string 
            if(temp!="") str.push_back(temp); // then push to vstring      
            if(temp==")") 
            { //as exp ends put the bracket close
              if(flag--)
              str.push_back(")"); 
            }
         }
        temp=""; //renew tmp
        }
    }
    str.push_back(temp);
    if(mark>0) str.push_back(")");
    return str;
}

int main()
{
    int t;
    cin>>t;
    for(int j=0;j<t;j++)
    {
        int lines;
        cin>>lines;
        chart.clear();
        for(int k=0;k<lines;k++)
        {
         string s;
         cin>>s;
         vector<string> str;
         string temp=""; 
         if(s.find("=") == std::string::npos )
         {
          vector<string> str= gdstring(s);
          vector<string> postexp=infixToPostfix(str);
          struct node* root=constructTree(postexp);
          int ans = eval(root);
          if(ans != INT_MAX)
            cout<<ans<<endl;
          else cout<<"CANT BE EVALUATED"<<endl;
         }

         else
         {
             int k= s.find("=");
             string s1=s.substr(0,k);
             string s2=s.substr(k+1);
             vector<string> str= gdstring(s2);
             vector<string> postexp=infixToPostfix(str);
             struct node* root=constructTree(postexp);
             int ans = eval(root);
             if(chart.find(s1)!= chart.end() )
             {
              if(ans != INT_MAX)
                chart[s1]=ans;
              else 
                cout<<"CANT BE EVALUATED"<<endl;
             }
             else
             {
               if(ans != INT_MAX)
                  chart.insert(make_pair(s1,ans));
               else 
                  cout<<"CANT BE EVALUATED"<<endl;
             }
          }
         }
    }
}