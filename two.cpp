#include<bits/stdc++.h>
using namespace std;

struct Node 
{
	int data; 
	Node* left;
	Node* right;
};

Node* GetNewNode(int data) 
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root,int data) 
{
	if(root == NULL)                                      // empty tree
    {                                           
		root = GetNewNode(data);
	}
	
	else if(data <= root->data)                         // if data to be inserted start lesser, insert inorder left subtree. 
    {
		root->left = Insert(root->left,data);
	}
	
	else                                                // else, insert inorder right subtree. 
    {
		root->right = Insert(root->right,data);
	}
	return root;
}

bool pair_sum_exist(Node* root,int sum, unordered_set<int> &s)
{
	if(root==NULL)
	return false;

	if(pair_sum_exist(root->left,sum,s)==true)
	return true;

	if(s.find(sum-(root->data))!=s.end())
	return true;
	else
	s.insert(root->data);

	return pair_sum_exist(root->right,sum,s);

}

int main() 
{
	Node* root = NULL;  			// Creating an empty tree
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,8);
	root = Insert(root,12);
	root = Insert(root,17);
	root = Insert(root,25);

	unordered_set<int>s;
	int sum=33;
	cout<<pair_sum_exist(root,sum,s);

}