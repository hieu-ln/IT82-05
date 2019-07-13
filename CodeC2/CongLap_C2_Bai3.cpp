#include <stdlib.h>
#include <iostream>
using namespace std;
//3.1 Khai bao cau truc danh sach
struct Node
{
	int info;
	Node *link;
};
Node *first;
//3.2 khoi tao danh sach rong
void init()
{
	first = NULL;
}
//3.3 Xuat cac phan tu trong danh sach
void process_list()
{
	Node *p;
	p=first;
	while(p!=NULL)
	{
		cout<<p->info<<"\t";
		p=p->link;
	}
	cout<<endl;
}
//3.4 Tim 1 phan tu trong danh sach
Node *search(int x)
{
	Node *p=first;
	while((p!=NULL) && (p->info!=x))
		p=p->link;
	return p;
}
//3.5 Them phan tu vao dau danh sach
void insert_first(int x)
{
	Node *p;
	p = new Node;
	p->info=x;
	p->link=first;
	first = p;
}
//3.6 Xoa phan tu dau danh sach
int delete_first()
{
	if(first != NULL)
	{
		Node *p=first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}
//3.7 Them phan tu vao cuoi danh sach
void insert_last(int x)
{
	Node *p;
	p= new Node;
	p->info=x;
	p->link=NULL;
	if(first == NULL)
	{
		first = p;
	}
	else
	{
		Node *q=first;
		while(q ->link !=NULL)
		{
			q= q ->link;
		}
		q->link=p;
	}
}
//3.8 Xoa phan tu vao cuoi danh sach
int delete_last()
{
	if(first!=NULL)
	{
		Node *p,*q;
		p = first;
		q = first;
		if(p!=NULL)
			while(p->link!=NULL)
			{
				q=p;p=p->link;
			}
		if(p!=first)
			q->link=NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//3.9 Tim va xoa phan tu
int search_And_delete(int x)
{
	if(first !=NULL)
	{
		Node *p, *q;
		p=first;
		q=first;
		while(p->info != x && p->link!=NULL)
		{
			q = p;
			p = p->link;
		}
		if(p!=first && p->link!=NULL)
		{
			if(p->link != NULL)
				q->link=p->link;
			else
				q->link=NULL;
			delete p;
			return 1;
		}
		else if(p == first)
		{
			first = p->link;
			delete p;
			return 1;
		}
		else if(p->link==NULL && p->info== x)
		{
			q->link=NULL;
			delete p;
			return 1;
		}
		else
			return 0;
	}
	return 0;
}
//3.10 Sap xep danh sach
void swap(Node *a, Node *b)
{
	int t=a->info;
	a->info = b->info;
	b->info=t;
}
void Sort()
{
	Node *p,*q,*min;
	p=first;
	while(p!=NULL)
	{
		min=p;
		q=p->link;
		while(q!=NULL)
		{
			if(q->info<min->info)
				min=q;
			q=q->link;
		}
		swap(min,p);
		p=p->link;
	}
}
void SortDesc()
{
	Node *p, *q,*min;
	p=first;
	while(p!=NULL)
	{
		min=p;
		q=p->link;
		while(q!=NULL)
		{
			if(q->info>min->info)
				min=q;
			q=q->link;
		}
		swap(min,p);
		p=p->link;
	}
}
int main()
{
	int choice = 0;
	int x, i;
	Node *p;
	system("cls");
	cout<<"---------------- BAI TAP 3, CHUONG 2, DANH SACH LIEN KET DON -----------"<<endl;
	cout<<"1. Khoi tao DSLK don rong"<<endl;
	cout<<"2.Them phan tu vao dau DSLK DON "<<endl;
	cout<<"3.Them phan tu vao cuoi DSLK DON"<<endl;
	cout<<"4.Xoa phan tu dau DSLK DON"<<endl;
	cout<<"5.Xoa phan tu cuoi DSLK DON"<<endl;
	cout<<"6.Xuat DSLK DON"<<endl;
	cout<<"7.Tim mot phan tu gia tri x trong DSLK DON"<<endl;
	cout<<"8.Tim phan tu voi gia tri x va xoa neu co"<<endl;
	cout<<"9.Sap xep DSLK don tang dan"<<endl;
	cout<<"10.Sap xep DSLK DON giam dan"<<endl;
	cout<<"11.Thoat"<<endl;
	do
	{
		cout<<"\nChon de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				init();
				cout<<"Ban khoi tao danh sach lien ket don thanh cong!";
				break;
			case 2:
				cout<<"Nhap gia tri x: ";
				cin>>x;
				insert_first(x);
				cout<<"Danh sach sau khi them la: ";
				process_list();
				break;
			case 3:
				cout<<"Nhap gia tri x: ";
				cin>>x;
				insert_last(x);
				cout<<"danh sach sau khi them la: ";
				process_list();
				break;
			case 4:
				i = delete_first();
				if(i==0)
					cout<<"Danh sach rong khong the xoa"<<x<<endl;
				else
				{
					cout<<"danh sach sau khi xoa phan tu dau la: ";
					process_list();
				}
				break;
			case 5:
				i = delete_last();
				if(i==0)
					cout<<"Danh sach rong khong the xoa!"<<x<<endl;
				else
				{
					cout<<"Danh sach sau khi xoa phan tu cuoi la: ";
					process_list();
				}
				break;
			case 6:
				cout<<"Danh sach hien tai la: ";
				process_list();
				break;
			case 7:
				cout<<"Nhap phan tu x can tim: ";
				cin>> x;
				p = search(x);
				if(p!=NULL)
				{
					cout<<"Tim thay phan tu co gia tri x= "<<x<<endl;
		
				}
				else
					cout<<"Khong tim thay gia tri x= "<<x<<endl;
				break;
			case 8:
				cout<<"Nhap phan tu x: ";
				cin>>x;
				i = search_And_delete(x);
				if(i==1)
				{
					cout<<"Tim thay x= "<<x<<" va xoa thanh cong"<<endl;
					cout<<"danh sach sau khi xoa la: ";
					process_list();
				}
				else
					cout<<"Khong tim thay phan tu x = "<<x;
				break;
			case 9:
				Sort();
				cout<<"Danh sach sau khi xep tang la: ";
				process_list();
				break;
			case 10:
				SortDesc();
				cout<<"Danh sach sau khi xep giam la: ";
				process_list();
				break;
			case 11:
				cout<<"\nGoodbye!"<<endl;
				break;
			default:
				break;

		}
	}while(choice!=11);
	system("pause");
	return 0;
}