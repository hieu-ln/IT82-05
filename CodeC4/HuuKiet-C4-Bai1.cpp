#include <iostream>
#include <stdio.h>
using namespace std;
int COUNT = 6;
//1.1 KHAI BAO CAU TRUC CAY NHI PHAN TIM KIEM
struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *root;
void print_tree(Node *p, int space)
{
	if(p==NULL)
	{
		return;
	}
	space +=COUNT;
	print_tree(p->right,space);
	cout<<endl;
	for(int i=COUNT;i<space;i++)
		cout<<" ";
	cout<<p->info<<"\n";
	print_tree(p->left,space);

}
void process_tree()
{
	print_tree(root,0);
}
//1.2 KHOI TAO CAY RONG
void tree_empty()
{
	root=NULL;
}
//1.3 THEM MOT PHAN TU VAO CAY
void insertNode(int x, Node *&p)
{
	if(p==NULL)
	{
		p =new Node;
		p->info=x;
		p->left=NULL;
		p->right=NULL;
	}
	else
	{
		if(p->info==x)
			return;
		else if(p->info>x)
			return insertNode(x,p->left);
		else
			return insertNode(x,p->right);
	}
}
//1.4 TIM PHAN TU TRONG CAY
Node *search(Node *p, int x)
{
	if(p!=NULL)
	{
		if(p->info==x)
			return p;
		else if(p->info>x)
			return search(p->left,x);
		else
			return search(p->right,x);
	}
	return NULL;
}
//1.5 XOA MOT PHAN TU TRONG CAY
void searchStandfor(Node *&p, Node *&q)
{
	if(q->left==NULL)
	{
		p->info=q->info;
		p=q;
		q=q->right;
	}
	else searchStandfor(p,q->left);
}
int Delete(Node *&T,int x)
{
	if(T==NULL)
		return 0;
	if(T->info==x)
	{
		Node *p=T;
		if(T->left==NULL)
			T=T->right;
		else if(T->right==NULL)
			T=T->left;
		else
			searchStandfor(p,T->right);
		delete p;
		return 1;
	}
	if(T->info<x)
		return Delete(T->right,x);
	if(T->info>x)
		return Delete(T->left,x);
}
//1.6 Duyet theo NLR(de quy)
void duyetNLR(Node *p)
{
	if(p!=NULL)
	{
		cout<<p->info<<"\t";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}
//1.7 Duyet theo LNR(de quy)
void duyetLNR(Node *p)
{
	if(p!=NULL)
	{
		duyetLNR(p->left);
		cout<<p->info<<"\t";
		duyetLNR(p->right);

	}
}
//1.8 duyet theo LRN(de quy)
void duyetLRN(Node *p)
{
	if(p!=NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout<<p->info<<"\t";
	}
}
int main()
{
	int choice, x, i;
	system("cls");
	cout<<"-------------------------------- BAI 1, CHUONG 4, CAY NHI PHAN TIM KIEM---------------------------------"<<endl;
	cout<<"1.Khoi tao cay rong"<<endl;
	cout<<"2.Them 1 phan tu vao cay"<<endl;
	cout<<"3.Tim 1 phan tu trong cay"<<endl;
	cout<<"4.Xoa 1 phan tu trong cay"<<endl;
	cout<<"5.Duyet cay theo thu tu NLR"<<endl;
	cout<<"6.Duyet cay theo thu tu LNR"<<endl;
	cout<<"7.Duyet cay theo thu tu LRN"<<endl;
	cout<<"8.Thoat"<<endl;
	do
	{
		cout<<"\nVui long nhap lua chon: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				tree_empty();
				cout<<"Khoi tao cay rong thanh cong! ";
				break;
			case 2:
				cout<<"Nhap phan tu muon them vao x =  ";
				cin>>x;
				insertNode(x,root);
				cout<<"Cay sau khi them la ";
				process_tree();
				break;
			case 3:
				cout<<"Nhap phan tu muon tim x = ";
				cin>>x;
				if(search(root,x)!=NULL)
					cout<<"Tim thay gia tri x = "<<x<<endl;
				else
					cout<<"Khong tim thay gia tri x = "<<x<<endl;
				break;
			case 4:
				cout<<"Nhap phan tu muon xoa x = ";
				cin>>x;
				i=Delete(root,x);
				if(i==0)
					cout<<"Khong xoa duoc! ";
				else
					cout<<"Xoa phan tu x = "<<x<<" thanh cong! ";
				cout<<"Cay sau khi xoa la: ";
				process_tree();
				break;
			case 5:
				cout<<"Cay sau khi duyet NLR la: ";
				duyetNLR(root);
				break;
			case 6:
				cout<<"Cay sau khi duyet LNR la: ";
				duyetLNR(root);
				break;
			case 7:
				cout<<"Cay sau khi duyet LRN la: ";
				duyetLRN(root);
				break;
			case 8:
				cout<<"Goodbye!..................";
				break;
			default:
				break;
		}
	}while(choice !=8);
	system("pause");
	return 0;
}

