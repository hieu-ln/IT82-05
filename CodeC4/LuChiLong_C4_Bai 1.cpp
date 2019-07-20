//1.1
#include <iostream>
int COUNT = 6;
#include <stdio.h>
using namespace std;

struct node
{
	int info;
	node *left;
	node *right;
};

node *root;
//1.2
void init()
{
	root = NULL;
}

void insertnode(int x, node *&p)
{
	if(p == NULL)
	{
		p = new node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if(p ->info == x)
			return;
		else if(p->info > x)
			return insertnode(x,p->left);
		else
			return insertnode(x,p->right);
	}
}
//1.4
node *search(node *p, int x)
{
	if(p != NULL )
	{
		if(p->info == x)
			return p;
		else
			if(x > p->info)
				return search(p->right,x);
			else
				return search(p->left,x);
	}
	return NULL;
}
//1.5
void searchstandfor(node *&p, node *&q)
{
	if(q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		searchstandfor(p, q->left);
}
int Delete(node *&D, int x)
{
	if(D == NULL)
		return 0;
	if(D ->info == x)
	{
		node *p = D;
		if (D ->left == NULL)
			D=D ->right;
		else if(D->right == NULL)
			D=D ->left;
		else
			searchstandfor(p, D ->right);
		delete p;
		return 1;
	}
	if(D ->info < x)
		return Delete(D ->right, x);
	if(D ->info > x)
		return Delete(D ->left, x);
}
//1.6
void sortLNR(node *p)
{
	if(p != NULL)
	{
		sortLNR(p->left);
		cout<<p->info<<" ";
		sortLNR(p->right);
	}
}
//1.7
void sortNLR(node *p)
{
	if( p != NULL)
	{
		cout<<p->info<<" ";
		sortNLR(p->left);
		sortNLR(p->right);
	}
}
//1.8
void sortLRN(node *p)
{
	if( p != NULL)
	{
		sortLRN(p->left);
		sortLRN(p->right);
		cout<<p->info<<" ";
	}
}
void print2DUtil(node *p, int space)
{
	if (p == NULL)
	{
		return;
	}
	space += COUNT;

	print2DUtil(p->right, space);

	cout<<endl;
	for(int i = COUNT;i < space; i++)
		cout<<" ";
	cout<<p->info<<"\n";

	print2DUtil(p->left, space);
}
void process_Tree()
{
	print2DUtil(root, 0);
}

int main()
{
	int choice = 0 ;
	int i, x;
	node* p;
	system("cls");
	cout<<" --------- BAI TAP 1 , CHUONG 4 , CAY NPTK --------- "<<endl;
	cout<<"1. Khoi tao CAY NPTK rong"<<endl;
	cout<<"2. Them phan tu vao CAY NPTK"<<endl;
	cout<<"3. Tim phan tu co gia tri x trong CAY NPTK"<<endl;
	cout<<"4. Xoa phan tu co gia tri x trong CAY NPTK"<<endl;
	cout<<"5. Duyet CAY NPTK theo NLR"<<endl;
	cout<<"6. Duyet CAY NPTK theo LNR"<<endl;
	cout<<"7. Duyet CAY NPTK theo LRN"<<endl;
	cout<<"8. Xuat CAY NPTK"<<endl;
	cout<<"9. Thoat"<<endl;
	do
	{
		cout<<"\nChon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			init();
			cout<<"CAY NPTK da khoi tao thanh cong!"<<endl;
			break;
		case 2:
			cout<<"Nhap gia tri x can them x=";
			cin>>x;
			insertnode(x,root);
			cout<<"CAY NPTK sau khi them !"<<endl;
			process_Tree();
			break;
		case 3:
			cout<<"Nhap gia tri x can tim";
			cin>>x;
			p = search(root,x);
			if(p != NULL)
				cout<<"Tim thay x="<<x<<" trong CAY NPTK"<<endl;
			else
				cout<<"Khong tim thay x="<<x<<" trong CAY NPTK"<<endl;
		case 4:
			cout<<"Nhap gia tri x can xoa x=";
			cin>>x;
			i = Delete(root,x);
			if(i == 0)
				cout<<"Khong tim thay x="<<x<<" de xoa"<<endl;
			else
			{
				cout<<"Da xoa thanh cong phan tu x="<<x<<" trong CAY NPTK"<<endl;
				cout<<"CAY NPTK sau khi xoa !"<<endl;
				process_Tree();
			}
			break;
		case 5:
			cout<<"CAY NPTK duyet theo LNR la: ";
			sortLNR(root);
			break;
		case 6:
			cout<<"CAY NPTK duyet theo NLR la: ";
			sortNLR(root);
			break;
		case 7:
			cout<<"CAY NPTK duyet theo LRN la: ";
			sortLRN(root);
			break;
		case 8:
			cout<<"CAY NPTK luc nay!"<<endl;
			process_Tree();
			break;
		case 9:
			cout<<"GOODBYE"<<endl;
			break;
		}
	}while(choice != 9);
		system("pause");
		return 0;
}