#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
    Node* root;
public:
    BST() {
        root = nullptr;
    }

    // 🌱 Recursive Insertion
    Node* insert(Node* node, int value)
     {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);

        return node;
    }

    void insert(int value) 
    {
        root = insert(root, value);
    }

 
    

    // Helper to find minimum node (used in deletion)
    

    // 🔁 Traversals
    void inorder(Node* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void print() {
        inorder(root);
    }
    int height(Node*root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
   
   int getheight()
   {
    return height(root);
   }
    void leveldisplay(Node*root,int k)
    {
        if(root==nullptr)
        {
            return ;
        }
        if(k==1)
        {
            cout<<root->data<<" ";
            return ;
        }
        leveldisplay(root->left,k-1);
        leveldisplay(root->right,k-1);
    }
   void levelorder()
   {
       int total=height(root);
       for(int i=1;i<=total;i++)
       {
          leveldisplay(root,i);
          cout<<endl;
       }
   }
};

int main() {
    BST tree;

    // Insert some data
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "BST Inorder Traversal (Sorted): ";
    tree.print();
    cout << endl;
   // cout<<"h"<<tree.getheight();
   cout<<"BSt level order is : "<<endl;
   tree.levelorder();
    
}
