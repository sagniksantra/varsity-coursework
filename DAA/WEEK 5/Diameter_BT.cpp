#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//structure for tree node
struct Node{
  int data;
  Node* left;
  Node* right;
};
//function to create node
Node* create(int x){
  Node* temp=(Node*)malloc(sizeof(Node));
  temp->data=x;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}
//function to find height from given node
int height(Node* root){
  if(root==NULL)return 0;
  int lh=height(root->left);
  int rh=height(root->right);
  return max(lh,rh)+1;
}
//funtion to find the diameter of the tree
int findDiameter(Node* root){
  if(root==NULL)return 0;
  int lh=height(root->left);
  int rh=height(root->right);
  int ld=findDiameter(root->left);
  int rd=findDiameter(root->right);
  return max(lh+rh+1,max(ld,rd));
}
//main function
int main(){
  Node* root=create(1);
  root->left=create(2);
  root->left->right=create(3);
  root->left->right->left=create(4);
  root->left->right->right=create(5);
  root->right=create(6);
  root->right->left=create(7);
  root->right->left->right=create(8);
  root->right->right=create(9);
  root->right->right->right=create(10);
  root->right->right->right->right=create(11);
  //d is stored the return value of function findDiameter
  int d=findDiameter(root);
  cout<<"Diameter of the given binary tree is : "<<d<<endl;
}
