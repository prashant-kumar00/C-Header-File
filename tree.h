#include<iostream>
using namespace std;


class treeNode{    //Binary tree class
public:
int  val;
treeNode*left;
treeNode*right;

treeNode(int d) //constructor
{
	val=d;
	left=NULL;
	right=NULL;
}
};

//...........................INSERT IN TREE.............................//
//															            //

void insert(treeNode*root,int data) //Inserts a Node at the last possible position(Left to Right)
{
   if(root==NULL)
   {
   	   treeNode*temp=new treeNode(data);
       root=temp;
       return;
   }
   
   queue<treeNode*> q;
   q.push(root);

   while(!q.empty())
   {
   	  treeNode*front=q.front();
   	  q.pop();
   	  if(front->left==NULL)
   	  {
   	  	treeNode*temp=new treeNode(data);
        front->left=temp;
        return;
   	  }
      if(front->right==NULL)
   	  {
   	  	treeNode*temp=new treeNode(data);
        front->right=temp;
        return;
   	  }
      
      q.push(front->left);
      q.push(front->right); 
   }

}

//.....................PREORDER TRAVERSAL..................................//
//																	       //

void preorderPrint(treeNode*root)  //Root->>Left->>Right (Order of Traversal)
{
	//cout<<"in header"<<endl;
	if(root==NULL)
		return;
    cout<<root->val<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

//.......................INORDER TRAVERSAL...................................//
//																		     //

void inorderPrint(treeNode*root)  //Left->Root->Right (Order of Traversal)
{
	if(root==NULL)
		return;
    inorderPrint(root->left);
    cout<<root->val<<" ";
    inorderPrint(root->right);
}

//........................POSTORDER TRAVERSAL.................................//
//																		      //


void postorderPrint(treeNode*root)  //Left->Right->Root (Order of Traversal)
{
	if(root==NULL)
		return;
    postorderPrint(root->left);
    postorderPrint(root->right);
    cout<<root->val<<" ";
}

//.........................BREADTH FIRST SEARCH................................//
//																		       //

void bfs(treeNode*root)    //Level Order Traversal
{
   queue<treeNode*> q;
   q.push(root);

   while(!q.empty())
   {
   	  treeNode*front=q.front();
   	  q.pop();
   	  cout<<front->val<<" ";
   	  if(front->left!=NULL)
   	  {
   	  	q.push(front->left);
   	  }
      if(front->right!=NULL)
   	  {
   	  	q.push(front->right); 
   	  }
   }

}

//........................FIND ELEMENT IN A TREE..................................//
//																			      //


bool find(treeNode*root,int val) //Returns True if Node is present in Tree else returns False
{
    if(root==NULL)				 //Recursively Checks for the nodes
    return false;

    if(root->val==val)
    return true;
    
    bool left=find(root->left,val);
    bool right=find(root->right,val);

    if(left or right)
    	return true;
    else
    	return false;
}

//...................... TOTAL NUMBER OF NODES IN TREE..............................//
//																					//

int totalNodes(treeNode*root)
{
   if(root==NULL)
   	return 0;

   int left=totalNodes(root->left);
   int right=totalNodes(root->right);
   
   return left+right+1;
}

//...........................HEIGHT OF TREE...........................................//
//																					  //

int height(treeNode*root)
{
	if(root==NULL)
    	return -1;

    int left=height(root->left);
    int right=height(root->right);

    return max(left,right)+1;
}

//......................MAXIMUM ELEMENT OF TREE..........................................//
// 																						 //

int maxElement(treeNode*root)
{
	if(root==NULL)
		return INT_MIN;
    
    int l=maxElement(root->left);
    int r=maxElement(root->right);

    return max(root->val,max(l,r));
}

//..................... MINIMUM ELEMENT OF TREE...........................................//
// 		                                                                                  //	

int minElement(treeNode*root)
{
	if(root==NULL)
		return INT_MAX;
    
    int l=minElement(root->left);
    int r=minElement(root->right);

    return min(root->val,min(l,r));
}
