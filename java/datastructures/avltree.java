import java.util.*;
import java.io.*;
class Node{
  public int value;
  public Node left;
  public Node right;
  public Node(int data){
    this.value = data;
    this.left = null;
    this.right = null;
  }
}
class AVLTree{
  public Node root;
  AVLTree(){
    root = null;
  }

  //find parent
  private Node findparent(Node y){
    Node cur = this.root;
    Node parent = null;
    while(cur!=y){
      parent=cur;
      if(cur.value<y.value){
        cur=cur.right;
      }else{
        cur=cur.left;
      }
    }
    return parent;
  }
  //left rotate
  private Node leftrotate(Node z){
    Node y = z.right;
    z.right = y.left;
    y.left = z;
    Node k = this.findparent(z);
    if(k!=null){
      if(k.right==z){
        k.right = y;
      }else{
        k.left = y;
      }
    }
    return y;
  }

  // right rotate
  private Node rightrotate(Node z){
    Node y = z.left;
    z.left = y.right;
    y.right = z;
    Node k = this.findparent(z);
    if(k!=null){
      if(k.right==z){
        k.right = y;
      }else{
        k.left = y;
      }
    }
    return y;
  }

  // height
  public int getHeight(Node root){
    if(root == null){
      return 0;
    }else{
      return (Math.max(getHeight(root.left),getHeight(root.right))+1);
    }
  }

  public int getHeight(){
    return getHeight(this.root);
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
    int balance = this.getHeight(root.left)-this.getHeight(root.right);
    if(balance>1){
      int balleft = this.getHeight(root.left.left)-this.getHeight(root.left.right);
      if(balleft<0){
        root.left = leftrotate(root.left);
      }
      root = rightrotate(root);
    }else if(balance<-1){
      int balright = this.getHeight(root.right.left)-this.getHeight(root.right.right);
      if(balright>0){
        root.right = rightrotate(root.right);
      }
      root = leftrotate(root);
    }
    return root;
  }
  public void insert(int data){
    this.root = insert(data,this.root);
  }


  // inorder
  public void inorder(){
    inorder(this.root);
  }
  private void inorder(Node root){
    if(root!=null){
      inorder(root.left);
      System.out.printf("%d ",root.value);
      inorder(root.right);
    }
  }

  // search
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


  //delete
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
    int balance = this.getHeight(root.left)-this.getHeight(root.right);
    if(balance>1){
      int balleft = this.getHeight(root.left.left)-this.getHeight(root.left.right);
      if(balleft<0){
        root.left = leftrotate(root.left);
      }
      root = rightrotate(root);
    }else if(balance<-1){
      int balright = this.getHeight(root.right.left)-this.getHeight(root.right.right);
      if(balright>0){
        root.right = rightrotate(root.right);
      }
      root = leftrotate(root);
    }
    return root;
  }
  public void delete(int data){
    if(search(data)){
      this.root = delete(data,this.root);
    }
  }
}

class avltree{
  public static void main(String args[]) throws IOException{
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    AVLTree tree = new AVLTree();
    int n = Integer.parseInt(r.readLine());
    int cnt = 0;
    while(cnt!=n){
      String[] s = r.readLine().split(" ");
      for(String x:s){
        if(!x.equals("")){
          tree.insert(Integer.parseInt(x));
          cnt++;
          System.out.println(tree.getHeight());
        }
      }
    }
    cnt = 0;
    while(cnt!=n){
      String[] s = r.readLine().split(" ");
      for(String x:s){
        if(!x.equals("")){
          tree.delete(Integer.parseInt(x));
          cnt++;
          System.out.println(tree.getHeight());
          tree.inorder();
          System.out.printf("\n");
        }
      }
    }
  }
}