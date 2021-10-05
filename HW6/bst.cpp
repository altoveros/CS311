#include <iostream>
#include "bst.h"

using namespace std;

BST::BST() 
{
    root = NULL;
}
BST::~BST() 
{
    root = NULL;
}
        
void BST::insert(int data) {
	root = insert(root,data);
}  
Node* BST::insert(Node* node, int data) {
    if(node == NULL)
    {
        node = new Node(data);
    }
  else if(node ->key > data)
  {
      node -> left = insert(node->left,data);
  }
    else if(data > node->key)
    {
      node -> right = insert(node ->right, data);
    }
  return node;
  }


Node* BST::search(int key) {
	return search(root,key);
}
Node* BST::search(Node* node, int key) 
{
    if(root == NULL || root->key == key)
    {
      return root;
    }
    if(root-> key < key)
    {
      return search(root->right,key);
      return search(root->left,key);
    }
 }


void BST::inorder() {
   inorder(root);
}
void BST::inorder(Node* root) {
    if (root != NULL)
    {
        inorder(root ->left);
        cout << root->key << " ";
        inorder(root ->right);
    }
    }

		
void BST::remove(int key)
{
	root = remove(root,key);
}
Node* BST::remove(Node* node, int key)
{
    if(node == NULL)
    {
      return node;
    }
    if(node -> key > key)
    {
      node -> left = remove(node->left,key);
    }
  else if(key > node-> key)
  {
    node ->right = remove(node->right,key);
  }
   else{
     if(node -> left == NULL)
     {
       Node *temp = node -> right;
       delete node;
       return temp;
     }
      else if(node ->right == NULL)
      {
        Node *temp = node -> left;
        delete node;
        return temp;
      }
     //Node *temp = leftmostNode(node -> left);
   // node -> key = temp -> key;
    //node -> left = delete(node->left,temp->key);
   }
  return node;
  
  
    }

Node* BST::leftmostNode(Node* node)
{
	Node* current  = node;
  while(current -> right != NULL)
  {
      current = current->right;
      return current;
  }
 }


