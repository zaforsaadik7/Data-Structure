#include<iostream> 
#include<queue> //it'll allow us to use the queue from the standard library
using namespace std;
struct Node
{
char data;
Node* left;
Node* right;
};

void LevelOrderPrint(Node* root) //it takes the root node and prints the data in the level order
{
if(root==NULL)
return;

queue<Node*> Q; //this will create a queue whose type is a pointer to the Node structure, as we are going to store the Nodes inside the queue
Q.push(root);// enqueuing the initial address of the root node
while(!Q.empty())
{
Node* current= Q.front()// front function returns an element at the front of the queue and as the data type of the element is pointer to node, we are collecting the return of the function to a variable which is a pointer to the node. 
cout<<corrent->data<<", ";//reading the data of the node
//Pushing the addresses of the children of the node. 
if(current->left!=NULL)
Q.push(current->left);
if(current->right!=NULL)
Q.push(current->right);
Q.pop()//after the work is done, we are removing or dequeuing the address from the front of the queue
}
