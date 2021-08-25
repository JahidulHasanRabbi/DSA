#include <iostream>

using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

typedef struct node Tree;

Tree *inordersuccessor(Tree *root);


Tree *CreateNewNode(int data)
{
    Tree *cureentNode = new Tree();

    cureentNode->data = data;
    cureentNode->left = NULL;
    cureentNode ->right = NULL;
    
    return cureentNode;
}

Tree *InsertInTree(Tree *root, int data)
{
    if(root == NULL) {
        root = CreateNewNode(data);
    }

    if(data < root->data) {
        root->left = InsertInTree(root->left, data);
    }
    else if (data > root->data) {
        root->right = InsertInTree(root->right, data);
    }

    return root;
}

void traversalInorder(Tree *root) {

    if(root != NULL)
    {
        traversalInorder(root->left);
        
        cout << root->data << " -> ";

        traversalInorder(root->right);
    }
}

Tree *DeleteFromTree(Tree *root, int data)
{
    if(root == NULL) {
        return root;
    }

    if(data < root->data) {
        root->left = DeleteFromTree(root->left, data);
    }
    else if(data > root->data) {
        root->right = DeleteFromTree(root->right, data);
    }

    else {
        
        if(root->left == NULL) {
                Tree *CureentNode = root;
                root = root->right;
                free(CureentNode);
                return root;
        }
        else if(root->right == NULL) {
                Tree *CureentNode = root;
                root = root->left;
                free(CureentNode);
                return root;
                
        }

        Tree *Sucessor = inordersuccessor(root->right);
            
        root->data = Sucessor->data;
        root->right = DeleteFromTree(root->right, Sucessor->data);

    }
    
    return root;
}

Tree *inordersuccessor(Tree *root)
{
    Tree *CureentNode = root;

    if(CureentNode != NULL && CureentNode->left != NULL)
    {
        CureentNode = CureentNode->left;
    }

    return CureentNode;
}

int main()
{
    int n;
    cout << "Enter Size : ";
    cin >> n;

    Tree *root = NULL;

    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        root = InsertInTree(root, a);
    }

    cout << endl << "Inorder" << endl;
    traversalInorder(root);

    while(1)
    {
        cout << endl << "Select Option" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Print" << endl;
        cout << "4. exit" << endl;

        int b;
        cin >> b;
        if(b == 1) {
            int a;
            cin >> a;
            root = InsertInTree(root, a);
        }
        if(b == 2) {
            cout << "Enter Element to Delete From TRee" << endl;
            cin >> b;
            DeleteFromTree(root, b);
        }
        if(b == 3) {
            traversalInorder(root);
        }
        if(b == 4) {
            break;
        }
    }

    return 0;
}

