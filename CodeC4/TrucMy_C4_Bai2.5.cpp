// bai 2 chuong 4 
#include <iostream>
#include <stack >

using namespace std ;

//2.1 khia bao cau truc cay nhi phan 
struct Node
{
	int info ;
	Node *left ;
	Node*right;
};
Node*CreateNode (int x )
{
	Node *p = new Node();
	p->info= x;
	p->left= p->right = NULL;
	return p ;
}
// 2.4 viet thu tuc tim mot phan tu trong cay 

Node *Find ( Node *root , int x )
{
	if ( root == NULL)
	{
		return NULL;	
	}
	Node *p = root ;
	while (p != NULL)
	{
		if ( p -> info > x)
		{
			p = p ->left;
		}
		else 
		{
			p=p ->right;
		}
	}
	return p ;
}
// 2.3 viet thu tuc them mot phan tu vao cay 
void InsertNode( Node*& root , int x )
{
	Node *n = CreateNode (x);
	if ( root == NULL)
	{
		root = n ;
		return ;  
	}
	else 
	{
		Node *f = Find ( root ,x);
		if ( f != NULL )
		{
			if ( f ->info > x)
			{
				f ->left = n ;
			}
			else
			{
				f ->right = n ;
			}
		}

	}

}

int Leftof ( const int value , const Node *root )
{
	return value < root ->info;

}
int Rightof ( const int value , const Node *root )
{
	return value > root ->info;
}
int LeftMostvalue ( const Node *root )
{
	while ( root ->left!= NULL)
		root = root ->left;
	return root ->info;
}
// 2.5 viet thu tuc xoa mot nut trong cay
Node *Delete ( Node *root , int value)
{
	if ( root == NULL)
		return root ;
	if ( Leftof ( value , root ))
		root->left = Delete ( root ->left, value);
	else if ( Rightof( value , root))
		root ->right=Delete( root->right, value);
	else 
	{
		if ( root -> left == NULL)
		{
			Node *newRoot = root->right;
			free ( root);
			return newRoot;
		}
		if ( root ->right==NULL)
		{
			Node*newRoot = root -> left ;
			free ( root);
			return newRoot;
		}
		root ->info = LeftMostvalue( root ->right);
		root ->right = Delete ( root ->right, root ->info);
	}
	return root ;
}
void Createtree( Node *&root , int a[], int n )
{
	for ( int i = 0 ; i < n ; i++)
	{
		InsertNode( root , a[i]);
	}
}
// 2.7 viet thu tuc duyet cay theo thu tu
void inOder ( struct Node*root)
{
	stack < Node *>s;
	Node* curr = root ;
	while ( curr != NULL || s.empty () == false)
	{
		while ( curr != NULL)
		{
			s.push( curr);
			curr = curr ->left;
		}
		curr = s.top();
		s. pop();
		cout << curr->info<<" ";
		curr = curr ->right;
	}
}
//2.6 viet thu tuc duyet cay theo thu tu 
void preoder ( struct Node *root )
{
	if ( root == NULL)
		return ;
	stack < Node*> NodeStack;
	NodeStack.push ( root);
	while ( NodeStack.empty()== false)
	{
		struct Node* temp_Node = NodeStack.top();
		cout << temp_Node ->info << " ";
		NodeStack.pop();
		if ( temp_Node -> right)
			NodeStack.push ( temp_Node ->right);
		if ( temp_Node -> left)
			NodeStack.push ( temp_Node ->left);
	}
}
// 2.6 viet thu tuc duyet cay theo thu tu NLR
void preorder( struct Node *root)
{
	if ( root == NULL)
		return ;
	stack <Node*> NodeStack ;
	NodeStack.push( root);
	while (NodeStack.empty()== false )
	{
		struct Node*temp_Node = NodeStack.top();
		cout << temp_Node ->info<<" ";
		NodeStack.pop();
		if( temp_Node->right)
			NodeStack.push(temp_Node->right);
		if( temp_Node->left)
			NodeStack.push(temp_Node->left);
	}
}
void postorderIterative (Node*root)
{
	stack<Node*>stk;
	stk.push(root);
	stack < int > out ;
	while (!stk.empty())
	{
		Node*curr = stk.top();
		stk.pop();
		out.push(curr->info);
		if ( curr-> left)
			stk.push( curr -> left);
		if( curr -> right)
			stk.push( curr -> right);
	}
	while ( !out.empty())
	{
		cout << out.top()<< " ";
		out.pop();
	}
}
 
int main ()
{
	Node *root = NULL;
	int a[] = {41, 6, 36 , 46, 16, 54, 47, 11, 14, 49, 47 };
	int n = 11 ;
	Createtree( root ,a , n);
	InsertNode(root,24);
	printf( " Duyet LNR :");
	inOder( root);
	printf( " \nDuyet NLR :");
	preorder(root);
	printf( " \nDuyet LRN :");
	postorderIterative( root);
	printf( " \nXoa node : 24 ");
	root = Delete ( root , 24);
	printf( " Duyet LNR :");
	inOder( root);
	printf( " \nDuyet NLR :");
	preorder(root);
	printf( " \nDuyet LRN :");
	postorderIterative( root);
	return 0 ;



} 