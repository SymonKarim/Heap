#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/
void inOrder(BinaryTreeNode* root, vector<int>&ans){
	if(!root) return;

	inOrder(root->left, ans);
	ans.push_back(root->data);
	inOrder(root->right,ans);
}

BinaryTreeNode* minHeap(BinaryTreeNode* root,vector<int>&ans, int &i){
	if(!root) return NULL;
	
	root ->data = ans[i++];
	minHeap(root->left, ans,i);
	minHeap(root->right, ans, i);
	return root;
}
BinaryTreeNode* convertBST(BinaryTreeNode* root){

	// Write your code here.
	vector<int>ans;
	inOrder(root, ans);
	int  i = 0;
	return minHeap(root, ans, i);
	 
}
