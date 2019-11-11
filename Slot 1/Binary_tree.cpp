/*Given a binary tree which has T nodes, you need to find the diameter of that binary tree. 
The diameter of a tree is the number of nodes on the longest path between two leaves in the tree.

Input:
First line contains two integers, T and X, number of nodes in the tree and value of the root.
Next  lines contain details of nodes.
Each detail of node contains two lines. 
First lines contains a string and second line contains an integer, which denotes the path of the node 
and the value of the node respectively.

String consists of only L or R. L denotes left child and R denotes right child. */

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<long long>

struct node
{
    int val;
    struct node* left;
    struct node* right;
};

struct node * newnode(int element)
{
    struct node * temp=(node * )malloc(sizeof(node));
    temp->val=element;
    temp->left=temp->right=NULL;
    return temp;
}

void create(string s, int val, struct node* src){
    struct node *nd = newnode(val);
    int i=0;
    struct node *top = src;
    while(i< s.size()-1){
        if(s[i] == 'L'){
            top = top->left;
        }
        else if(s[i] == 'R'){
            top = top->right;
        }
        i++;
    }
    if(s[i] == 'L'){
        top->left = nd;
    }
    else if(s[i] == 'R'){
        top->right = nd;
    }
}

int height(struct node *src){
    if(src == NULL){
        return 0;
    }else{
        int ldepth = height(src->left);
        int rdepth = height(src->right);

        if(ldepth > rdepth){
            return (ldepth+1);
        }else{
            return (rdepth+1);
        }
    }
}

int diameter(struct node *src){
    if(src == NULL){
        return 0;
    }
    int rheight = height(src->right);
    int lheight = height(src->left);

    int rdia = diameter(src->left);
    int ldia = diameter(src->right);

    return max(lheight+rheight, max(rdia, ldia));
}

int main()
{
    int t, x;
    cin>>t>>x;
    struct node *cc, *top;
    top = newnode(x);

    vector<pair<string, int >> vv(0);

    for(ll i=0;i<t-1;i++){
        string st; 
        int a;
        cin>>st>>a;
        vv.pb(make_pair(st, a));
    }
    sort(vv.begin(), vv.end());

    for(ll i=0;i<t-1;i++){
        cc = top;
        create(vv[i].first, vv[i].second, cc);
    }
    cout<<diameter(top);
}
