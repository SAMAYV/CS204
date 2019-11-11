#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<long long>

struct node{
    int data;
    node* left;
    node* right;
};

struct node *newNode(int item) 
{ 
    struct node *temp =  new struct node; 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

void preorder(struct node*root)
{
    if(root)
    {
            printf("%d ",root->data);   
            preorder(root->left);   
            preorder(root->right);    
    }
}
void postorder(struct node*root)
{
    if(root)
    {
            postorder(root->left);    
            postorder(root->right);     
            printf("%d ",root->data);    
    }
 }
void inorder(struct node*root)
{
    if(root)
    {
            inorder(root->left);   
            printf("%d ",root->data);    
            inorder(root->right);     
    }
}
struct node* insert(struct node* root, int data)
{
    if (root == NULL)    
        return newNode(data);
    else
    {
        if (data <= root->data)
            root->left  = insert(root->left, data);
        else
            root->right = insert(root->right, data);
        return root;
    }
}

struct node * successor(struct node* node) 
{ 
    struct node* current = node; 
    while (current && current->left != NULL) 
        current = current->left; 
    return current; 
}

struct node* deleteNode(struct node* root, int key) 
{ 
    if (root == NULL) return root; 
    if (key < root->data) 
        root->left = deleteNode(root->left, key); 
    else if (key > root->data) 
        root->right = deleteNode(root->right, key); 
    else
    { 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        struct node* temp = successor(root->right); 
        root->data = temp->data; 
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
}
int main(){
    struct node *root = NULL;
    int t;
    cin>>t;
    cout<<"Enter 1 to insert:\n";
    cout<<"Enter 2 to delet: \n";
    cout<<"Enter 3 to print inorder:\n";
    while(t--)
    {
        int a;
        cin>>a;
        if(a == 1){
            int b;
            cin>>b;
            root = insert(root, b);
        }
        else if(a == 2){
            int b;
            cin>>b;
            root = deleteNode(root, b);
        }
        else{
            inorder(root);
            cout<<endl;
        }
    }
}