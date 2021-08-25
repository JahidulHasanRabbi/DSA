#include<iostream>
using namespace std;
typedef struct node
{
    int value;
    node * pLeft;
    node * pRight;
    node(int val = 0)
    {
        value = val;
        pRight = NULL;
        pLeft = NULL;
    }
}node;
 
void insert(node ** pRoot, int val)
{
    if(*pRoot == NULL)
        *pRoot = new node(val);
    else if((*pRoot)->value <= val)
        insert(&((*pRoot)->pRight), val);
    else if((*pRoot)->value > val)
        insert(&((*pRoot)->pLeft), val);
}
 
node * getBST(int * arr, int size)
{
    node * pRoot = NULL;
    for(int i = 0; i < size; i++)
        insert(&pRoot, arr[i]);
    return pRoot;
}
 
void inOrderTraversal(node * pRoot)
{
    if(pRoot && pRoot->pLeft)
        inOrderTraversal(pRoot->pLeft);
    if(pRoot)
        std::cout<<pRoot->value<<" , ";
    if(pRoot && pRoot->pRight)
        inOrderTraversal(pRoot->pRight);
 
}
int main()
{
    int arr[] = {50, 40, 30, 60, 70, 65, 25};
    node * pRoot = getBST(arr, sizeof(arr)/sizeof(int));
    cout << "root " << pRoot->value << endl; 
    inOrderTraversal(pRoot);
    std::cout<<std::endl;
    return 0;
}