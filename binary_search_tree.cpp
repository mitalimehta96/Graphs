/*Implementation of Binary Search Tree. 
Develop a Menu Drive Program for Binary Search Tree with following menu options: 
1. Create 
2. Insert 
3. Delete 
4. Search 
5. Print 
6. Exit. */

#include<iostream>
#include<stdlib.h>
#include<windows.h>
using namespace std;

struct node
{
    int data;
    node *right;
    node *left;
};

// insertion of node in the BST
node* insertNode(node *root,int n)
{

    if(root == NULL)
    {
        root = new node;
        root->data = n;
        root->left = root->right = NULL;
    }
    else if(n <= root->data)
       root->left = insertNode(root->left,n);
    else if(n > root->data)
        root->right = insertNode(root->right,n);
        return root;
}


// searching an element from the tree 
node* searchNode(node* root)
{
    int k;
    if(root == NULL)
    {
       cout<<"\nTree is empty. \n";
    }
    else
    {
        cout<<"Enter node to be searched: " ;
        cin>>k ;
        node  *p ;
        p=root ;
        while(p != NULL)
            {
                if(p->data == k)
                break ;
                if(k < p->data)
                p=p->left ;
                else
                p=p->right ;
            }

        if(p == NULL)
        cout<<"\nRequired node not found. \n";
        else
        cout<<"\nNode found : "<<p->data<<endl ;
    return root;
    }
}

node* minright(node* root)
{
    while(root->left != NULL)
       root->left = minright(root->left);
    return root;
}

// deleting a node from the tree
node* deleteNode(node* root,int n)
{

    if(root == NULL)
       return root;


    else if (n < root->data)
        root->left = deleteNode(root->left, n);


    else if (n > root->data)
        root->right = deleteNode(root->right, n);
     else
     {
         if(root->left == NULL)
     {
         node *temp = new node;
         temp = root->right;
         delete root;
         return temp;
     }
     else if(root->right == NULL)
     {
         node *temp = new node;
         temp = root->left;
         delete root;
         return temp;
     }

     {
        node* temp = minright(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
     }
     }
     return root;
}

// inorder traversal of the tree-(left-root-right)
 void inorder(node* root)
{
        if(root != NULL)
        {
        inorder(root->left);
        cout<<root->data<< " ";
        inorder(root->right);
        }

}

//preorder traversal of the tree- (root-left-right)
 void preorder(node* root)
{

    if(root != NULL)
    {
    cout<<root->data<< " ";
    preorder(root->left);
    preorder(root->right);
    }

}

// postorder traversal-(left-right-root)
 void postorder(node* root) 
{
    if(root != NULL)
    {
     postorder(root->left);
     postorder(root->right);
     cout<<root->data<< " ";
    }

}

//Main function defines the menu options for the Binary Tree
int main()
{
    node *root;
    node *temp;
    root=NULL;
      int  x , k , ch ;
  do
  {

    cout<<"1.Insert new node. \n";
    cout<<"2.Preorder Traversal. \n";
    cout<<"3.Inorder Traversal. \n";
    cout<<"4.Postorder Traversal. \n";
    cout<<"5.Delete Node. \n";
    cout<<"6.Search Node\n";
    cout<<"7.Quit\n" ;

    cout<<"Enter your choice: " ;
    cin>>ch ;

    switch(ch)
    {

      case 1:
      cout<<"Enter value of new node: " ;
      cin>>x ; // to store value of node to be inserted
      root=insertNode(root,x) ;
      break ;

      case 2:
      preorder(root) ;
      cout<<"\n" ;
      break ;

      case 3:
      inorder(root) ;
      cout<<"\n" ;
      break ;

      case 4:
      postorder(root) ;
      cout<<"\n" ;
      break ;

      case 5:
      cout<<"Enter node to be deleted: " ;
      cin>>k ;
      root=deleteNode(root,k) ;
      break ;

      case 6:
      temp=searchNode(root) ;
      break ;
    }
    Sleep(3000);
    system("cls"); // to clear the screen as per menu driven program
  }  while(ch!=7) ;

 return 0;
} 
