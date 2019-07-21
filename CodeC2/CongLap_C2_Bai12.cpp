#include <iostream>
#include <stdio.h>
using namespace std;
//12.1 Khai bao cau truc danh sach
struct Node
{
	int info;
	Node *next, *previous;
};
Node *first, *last;
//12.2 Khoi tao danh sach rong
void init()
{
	first=NULL;
	last=NULL;
}
//12.3 Xuat cac phan tu trong danh sach
void process_list()
{
	Node *p;
	p=first;
	while(p!=NULL)
	{
		cout<<p->info<<"\t";
		p=p->next;
	}
}
//12.4 Them phan tu vao dau danh sach
void insert_first(int x)
{
	Node *p;
	p=new Node;
	p->info=x;
	p->next=first;
	p->previous=NULL;
	if(first!=NULL)
		first->previous=p;
	else
		last=p;
	first=p;
}
//12.5 Them phan tu vao cuoi danh sach
void insert_last(int x)
{
	Node *p;
	p=new Node;
	p->info=x;
	p->next=NULL;
	p->previous=last;
	if(last!=NULL)
		last->next=p;
	else
		first=p;
	last=p;
}
//12.6 Xoa dau danh sach
int Delete_first()
{
	if(first!=NULL)
	{
		Node *p=first;
		first=first->next;
		delete p;
		if(first!=NULL)
			first->previous=NULL;
		else
			last=NULL;
		return 1;
	}
	return 0;
}
//12.7 Xoa cuoi danh sach
int Delete_last()
{
	if(last!=NULL)
	{
		Node *p =last;
		last = last->previous;
		if(last!=NULL)
			last->next=NULL;
		else
			first=NULL;
		delete p;
		return 1;
	}
	return 0;
}
//12.8 tim va xoa
int Search_And_Delete(int x)
{
	if(first != NULL)
	{
		Node* p, *q, *e;
		e = first;
		p = first;
		q = first;
		while(p->info != x && p->next != NULL)
		{
			q = p;
			p = p->next ;
		}
		e = p->next ;
		if(p != first && p!= NULL)
		{
			if(p->next != NULL)
			{
				q->next = p->next;
				e->previous = q;
			}
			else
			{
				q->next = NULL;
				last = q;
			}
			delete p;
			return 1;
		}
		else
			if(p == first)
			{
				first = p->next;
				last = p->next;
				delete p;
				return 1;
			}
			else
				return 0;
	}
	return 0;
}
void insert_before_q(int x, int y)
{
	Node* p, *q, *e;
		e = new Node ;
		p = first;
		q = first;
		e->info = x;
	if(first != NULL)
	{
		while(p->info != y && p->next != NULL)
		{
			q = p;
			p = p->next ;
		}

		if(p != first && p!= NULL)
		{
			
			e->previous = p->previous;
			e->next = q->next;
			q->next = e;
			p->previous = e;
		}
		else
		{
			p->previous = e;
			e->next = p;
			first = e;
		}
	}
	else{
				cout <<"ko ton tai y\n";
	}
}
int main()
{
	int choice,x,y;
	system("cls");
	cout<<"-------------------------------BAI 12, CHUONG 2, DSLK KEP----------------------------------\n";
	cout<<"1.Khoi tao danh sach rong\n";
	cout<<"2.Them vao dau danh sach\n";
	cout<<"3.Them vao cuoi danh sach\n";
	cout<<"4.Xoa 1 phan tu dau danh sach\n";
	cout<<"5.Xoa 1 phan tu cuoi danh sach\n";
	cout<<"6.Xuat danh sach lien ket doi\n";
	cout<<"7.Tim va xoa 1 Node bat ki\n";
	cout<<"8.Them 1 gia tri sau Node ";
	cout<<"9.Thoat!\n";
	do
	{
		cout<<"\nCHon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				init();
				cout<<"Khoi tao danh sach rong thanh cong! ";
				break;
			case 2:
				cout<<"Nhap phan tu x muon them: ";
				cin>>x;
				insert_first(x);
				cout<<"Danh sach sau khi them la: ";
				process_list();
				break;
			case 3:
				cout<<"Nhap phan tu x muon them: ";
				cin>>x;
				insert_last(x);
				cout<<"Danh sach sau khi them la: ";
				process_list();
				break;
			case 4:
				if(Delete_first()==1)
				{
					cout<<"Xoa thanh cong: ";
					cout<<"Danh sach sau khi xoa la: ";
					process_list();
				}
				else
					cout<<"Danh sach rong";
				break;
			case 5:
				if(Delete_last()==1)
				{
					cout<<"Xoa thanh cong! ";
					cout<<"Danh sach sau khi xoa cuoi la: ";
					process_list();
				}
				else
					cout<<"Danh sach rong! ";
				break;
			case 6:
				cout<<"Danh sach hien tai la: ";
				process_list();
				break;
			case 7:
				cout<<"Nhap gia tri x muon xoa: ";
				cin>>x;
				if(Search_And_Delete(x)==1)
				{
					cout<<"Xoa thanh cong";
					cout<<"\nDanh sach sau khi xoa la: ";
					process_list();
				}
				else
					cout<<"Khong co gia tri x de xoa";
				break;
			case 8:
				cout<<"Nhap gia tri muon them x = ";
				cin>>x;
				cout<<"Nhap gia tri sau x,y = ";
				cin>>y;
				insert_before_q(x,y);
				cout<<"Danh sach sau khi them la: ";
				process_list();
				break;
			case 9:
				cout<<"Goodbye!.................\n";
				break;
			default:
				break;
		}
	}while(choice!=9);
	system("pause");
	return 0;
}
