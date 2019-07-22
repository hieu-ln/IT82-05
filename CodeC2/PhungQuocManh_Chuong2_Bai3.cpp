#include <iostream>
using namespace std;
// 3.1 Khai bao cau truc
struct Node
{
	int info;
	Node *link;
};
Node *first;
//3.2 Khoi tao danh sach rong
void init()
{
	first = NULL;
}
//3.3 Xuat cac phan tu trong danh sach
void Process_list()
{
	Node *p;
	p = first;
	while(p != NULL)
	{
		cout<< p->info<<"\t";
		p = p->link;
	}
	cout<<endl;
}
//3.4 Tim phan tu
Node *search(int x)
{
	Node *p = first;
	while(p != NULL && p ->info != x)
		p = p->link;
	return p;
}
//3.5 chen phan tu dau
void insert_first(int x)
{
	Node*p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
	
}
// 3.6 Xoa phan tu dau
int delete_first()
{
	if(first != NULL)
	{
		Node*p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}
//3.7 chen phan tu cuoi
void insert_last(int x)
{
	Node*p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if(first == NULL)
		first = p;
	else
	{
		Node*q = first;
		while(q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}
//3.8 xoa phan tu cuoi
int delete_last()
{
	if(first != NULL)
	{
		Node *p,*q;
		p = first;
		q= first;
		while(p->link != NULL)
		{
			q = p;
			p = p ->link;
		}
		if(p != first)
			q ->link = NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//3.9 Tim va xoa
int search_and_delete(int x)
{
	if(first != NULL)
	{
		Node *q,*p;
		p = first;
		q = first;
		while(p ->info != x && p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if(p != first && p != NULL)
		{
			if(p ->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
			return 1;
		}
		else
			if(p == first)
			{
				first = p->link;
				delete p;
				return 1;
			}
			return 0;
	}
	return 0;
}
//3.10.1 void Sort()
//3.10.2 void SortDest()
int main()
{
	int choice = 0;
	int x,i;
	Node *p;
	system("cls");
	cout<<"\n     ===========================================      ";
	cout<<"\n=====BAI TAP 3, CHUONG 1, DANH SACH LIEN KET DON======";
	cout<<"\n= 1.Khoi tao DS rong                                 =";
	cout<<"\n= 2.Them phan tu dau trong DSLK don                  =";
	cout<<"\n= 3.Them phan tu cuoi trong DSLK don                 =";
	cout<<"\n= 4.Xoa phan tu dau trong DSLK don                   =";
	cout<<"\n= 5.Xoa phan tu cuoi trong DSLK don                  =";
	cout<<"\n= 6.Xuat DSLK don trong DSLK don                     =";
	cout<<"\n= 7.Tim mot phan tu gia tri x trong DSLK don         =";
	cout<<"\n= 8.Tim va xoa phan tu  neu co trong DSLK don        =";
	cout<<"\n= 9.Thoat                                            =";
	cout<<"\n======================================================";
	do
	{
		cout<<"\nChon so de thuc hien menu: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				init();
				cout<<"Khoi tao thanh cong !";
				break;
			case 2:
				cout<<"Nhap x: ";
				cin>>x;
				insert_first(x);
				cout<<"Danh sach sau khi them la: ";
				Process_list();
				break;
			case 3:
				cout<<"Nhap x: ";
				cin>>x;
				insert_last(x);
				cout<<"Danh sach sau khi them la: ";
				Process_list();
				break;
			case 4:
				 i = delete_first();
				if(i == 0)
					cout<<"Danh sach rong, khong the xoa "<<x<<endl;
				else
				{
					cout<<"Xoa thanh cong ";
					cout<<"Danh sach sau khi xoa la: ";
					Process_list();
				}
				break;
			case 5:
				i = delete_last();
				if(i == 0)
					cout<<"Danh sach rong, khong the xoa "<<x<<endl;
				else
				{
					cout<<"Xoa thanh cong ";
					cout<<"Danh sach sau khi xoa la: ";
					Process_list();
				}
				break;
			case 6:
				cout<<"Danh sach hien tai la: ";
				Process_list();
				break;
			case 7:
				cout<<"Nhap x: ";
				cin>>x;
				p = search(x);
				if(p != NULL)
					cout<<"Tim thay phan tu gia tri x = "<<x<<endl;
				else
					cout<<"Khong tim thay co gia tri ";
				break;
			case 8: 
				cout<<"Nhap x: ";
				cin>>x;
				i= search_and_delete(x);
				if(i == 1)
				{
					cout<<"Tim thay x= "<<x<<" va da xoa thanh cong "<<endl;	
					cout<<"Danh sach sau khi xoa la: ";
					Process_list();
				}
				else
					cout<<"Khong tim thay phan tu co gia tri x= "<<x<<endl;
				break;
			case 9:
				cout<<"\nTAM BIET! ";
				cout<<endl;
			default:
				break;
		}
	}while(choice != 9);
	system("pause");
	return 0;
}