import java.util.*;
import java.io.*;
class Node{
  public int value;
  public Node left;
  public Node right;
  public Node(int value){
    this.value = value;
    left = null;
    right = null;
  }
}
/*
  * implement insert delete and search functions in bst
*/
class BST{
  public Node root;
  public BST(){
    this.root = null;
  }

  // insert
  private Node insert(int data,Node root){
    if(root == null){
      root = new Node(data);
    }else{
      if(data<root.value){
        root.left = insert(data,root.left);
      }else{
        root.right = insert(data,root.right);
      }
    }
    return root;
  }
  public void insert(int data){
    this.root = insert(data,this.root);
  }


  public boolean search(int data){
    Node cur = this.root;
    if(cur==null){
      return false;
    }
    while(cur.value!=data){
      if(cur.value<data){
        cur=cur.right;
      }else{
        cur=cur.left;
      }
      if(cur==null){
        return false;
      }
    }
    return true;
  }

  // delete
  private Node delete(int data,Node root){
    if(root.value<data){
      root.right = delete(data,root.right);
    }else if(root.value>data){
      root.left = delete(data,root.left);
    }else{
      if(root.left == null && root.right == null){
        return null;
      }else if(root.left==null){
        return root.right;
      }else if(root.right==null){
        return root.left;
      }else{
        Node cur = root.left;
        while(cur.right!=null){
          cur=cur.right;
        }
        root.value = cur.value;
        root.left = delete(root.value,root.left);
      }
    }
    return root;
  }
  public void delete(int data){
    if(search(data)){
      this.root = delete(data,this.root);
    }
  }
  // inorder
  private void inorder(Node root){
    if(root!=null){
      inorder(root.left);
      System.out.printf("%d ",root.value);
      inorder(root.right);
    }
  }
  public void inorder(){
    this.inorder(this.root);
  }
}


class bst{
  public static void main(String args[]) throws IOException{
    BST b = new BST();
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    int n =  Integer.parseInt(r.readLine());
    int cnt=0;
    while(cnt<n){
      String[] s=r.readLine().split(" ");
      for(String x:s){
        if(!x.equals("")){
          b.insert(Integer.parseInt(x));
          cnt++;
          b.inorder();
          System.out.printf("\n");
        }
      }
    }
    System.out.println(b.search(5));
    b.delete(5);
    System.out.println(b.search(5));
    b.inorder();
    System.out.printf("\n");
  }
}