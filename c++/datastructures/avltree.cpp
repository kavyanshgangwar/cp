#include <bits/stdc++.h>
using namespace std;
/*
  *
  * implement a class for avl tree
  * implement a insert function
  * implement a search function
  * implement a delete function
  *
*/
class Node{
  public:
    int data;
    Node* left;
    Node* right;
};
class AVLTree{
  public:
    Node* root;
    AVLTree(){
      root = NULL;
    }



    int getHeight(Node* root){
      if(root == NULL){
        return 0;
      }else{
        return max(getHeight(root->left),getHeight(root->right))+1;
      }
    }



    Node* findparent(Node* cur){
      Node* parent = root;
      while(parent!=NULL){
        if(parent->left!=NULL && parent->left->data==cur->data){
          return parent;
        }else if (parent->right!=NULL && parent->right->data==cur->data){
          return parent;
        }else{
          if(cur->data>parent->data){
            parent=parent->right;
          }else{
            parent=parent->left;
          }
        }
      }
      return parent;
    }


    Node* rightrotate(Node* root){
      Node* y = root->left;
      root->left = y->right;
      y->right = root;
      Node* k = findparent(root);
      if(k!=NULL){
        if(k->left->data==root->data){
          k->left = y;
        }else{
          k->right=y;
        }
      }
      return y;
    }


    Node* leftrotate(Node* root){
      Node* y = root->right;
      root->right = y->left;
      y->left = root;
      Node* k = findparent(root);
      if(k!=NULL){
        if(k->left->data==root->data){
          k->left=y;
        }else{
          k->right=y;
        }
      }
      return y;
    }


    Node* insert(int a,Node* root){
      if(root == NULL){
        root = new Node();
        root->data = a;
        root->left = root->right = NULL;
      }else{
        if(a<root->data){
          root->left = insert(a,root->left);
        }else if(a>root->data){
          root->right = insert(a,root->right);
        }
      }
      // cout<<root->data<<" ";
      int balance = getHeight(root->left)-getHeight(root->right);
      if(balance > 1){
        int balleft =  getHeight(root->left->left)-getHeight(root->left->right);
        if(balleft>0){
          root =  rightrotate(root);
        }else if(balleft<0){
          root->left = leftrotate(root->left);
          root = rightrotate(root);
        }
      }else if(balance<-1){
        int balright = getHeight(root->right->left)-getHeight(root->right->right);
        if(balright>0){
          if(root->data==1){
            // cout<<"balright: "<<balright<<endl;
          }
          root->right = rightrotate(root->right);
          root = leftrotate(root);
        }else{
          if(root->data==1){
            // cout<<"balright1: "<<balright<<endl;
          }
          root = leftrotate(root);
        }
      }
      return root;
    }

    bool search(int a){
      Node* cur = root;
      while(cur!=NULL){
        if(cur->data==a){
          return true;
        }else{
          if(cur->data>a){
            cur=cur->left;
          }else{
            cur=cur->right;
          }
        }
      }
      return false;
    }

    Node* Delete(int a, Node* root){
      if(!search(a)){
        return root;
      }else{
        if(root->data>a){
          root->left = Delete(a,root->left);
        }else if(root->data<a){
          root->right = Delete(a,root->right);
        }else{
          if(root->left==NULL && root->right==NULL){
            return NULL;
          }else if(root->left==NULL){
            return root->right;
          }else if(root->right==NULL){
            return root->left;
          }else{
            Node* cur = root->left;
            while(cur->right!=NULL){
              cur=cur->right;
            }
            root->data = cur->data;
            root->left = Delete(cur->data,root->left);
          }
        }
        int balance = getHeight(root->left)-getHeight(root->right);
        if(balance > 1){
          int balleft =  getHeight(root->left->left)-getHeight(root->left->right);
          if(balleft>0){
            root =  rightrotate(root);
          }else if(balleft<0){
            root->left = leftrotate(root->left);
            root = rightrotate(root);
          }
        }else if(balance<-1){
          int balright = getHeight(root->right->left)-getHeight(root->right->right);
          if(balright>0){
            root->right = rightrotate(root->right);
            root = leftrotate(root);
          }else{
            root = leftrotate(root);
          }
        }
        return root;
      }
    }

    void inorder(Node* cur){
      if(cur!=NULL){
        inorder(cur->left);
        cout<<cur->data<<" ";
        inorder(cur->right);
      }
    }
};
int main(){
  AVLTree tree = AVLTree();
  int n;
  cin>>n;
  int a;
  for(int i=0;i<n;i++){
    cin>>a;
    tree.root = tree.insert(a,tree.root);
    cout<<tree.getHeight(tree.root)<<endl;
  }
  // cout<<tree.getHeight(tree.root);
  cin>>a;
  cout<<tree.search(a)<<endl;
  cout<<tree.root->data<<endl;
  for(int i=0;i<n;i++){
    cin>>a;
    tree.root = tree.Delete(a,tree.root);
    cout<<tree.getHeight(tree.root);
    tree.inorder(tree.root);
  }
  
}