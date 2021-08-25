#include<iostream>

using namespace std;

struct node {
  int data;
  struct node *leftChild;
  struct node *rightChild;
};

typedef struct node Node;

Node *newNode(int data)
{
  Node *temp = new Node();
  
  temp->data = data;
  temp->leftChild = temp->rightChild = NULL;
  
  return temp;
}

void inOrder(Node *root)
{
  if(root != NULL) {
    inOrder(root->leftChild);

    cout << root->data << " -> ";

    inOrder(root->rightChild);
  }
}


void preOrder(Node *root)
{
  if(root != NULL) {
    cout << root->data << " -> ";

    preOrder(root->leftChild);

    preOrder(root->rightChild);
  }

}

void postOrder(Node *root) {
  if(root != NULL) {
    postOrder(root->leftChild);

    postOrder(root->rightChild);

    cout << root->data << " -> ";
  }

}

Node *minValueNode(Node *root)
{
  Node *current = root;

  while(current && current->leftChild != NULL) {
    current = current->leftChild;
  }

  return current;
}

Node *insert(Node *root, int data)
{
  if(root == NULL) {
    return newNode(data);
  }

  if(data < root->data) {
    root->leftChild = insert(root->leftChild, data);
  }
  else {
    root->rightChild = insert(root->rightChild, data);
  }

  return root;

}

Node *Delete(Node *root, int data) {

  if(root == NULL) {
    return root;
  }

  if(data < root->data) {
    root->leftChild = Delete(root->leftChild, data);
  }
  else if(data > root->data) {12
    root->rightChild = Delete(root->rightChild, data);
  }
  else {
    // One Child
    if(root->leftChild == NULL) {
      Node *temp = root-> rightChild;
      free(root);
      return temp;
    }
    else if(root->rightChild == NULL){
      Node *temp = root -> leftChild;
      free(root);
      return temp;
    }

    Node *temp = minValueNode(root->rightChild);

    root->data = temp->data;

    root->rightChild = Delete(root->rightChild, temp->data);
  }

}

int main()
{
  Node *root = NULL;

  int n, a;
  cout << "Size = ";
  cin >> n;

  for(int i=0; i<n; i++) {
    cout << "Enter Value : ";
    cin >> a;
    root = insert(root, a);
  }

  cout << "Inorder Traversal" << endl;
  inOrder(root);
  cout << endl;

  cout << "Preorder Traversal" << endl;
  preOrder(root);
  cout << endl;

  cout << "Postorder Traversal" << endl;
  postOrder(root);
  cout << endl;

  int d;
  cout << "Item to Delete From Tree : ";
  cin >> d;
  Delete(root, d);
  
  cout << "Inorder Traversal" << endl;
  inOrder(root);
  cout << endl;

  cout << "Preorder Traversal" << endl;
  preOrder(root);
  cout << endl;

  cout << "Postorder Traversal" << endl;
  postOrder(root);
  cout << endl;

  return 0;
}