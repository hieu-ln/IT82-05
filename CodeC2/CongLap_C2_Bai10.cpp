//#include <iostream>
//#include <stdio.h>
//using namespace std;
////10.1 khai bao cau truc Stack
//struct Node
//{
//	int info;
//	Node *link;
//};
//Node *sp;
////10.2 Khoi tao stack rong
//void init()
//{
//	sp=NULL;
//}
////10.3 Kiem tra Stack rong
//int isEmpty()
//{
//	if(sp==NULL)
//		return 1;
//	return 0;
//}
////10.4 Them phan tu vao Stack
//void Push(int x)
//{
//	Node *p = new Node;
//	p->info=x;
//	p->link=sp;
//	sp=p;
//}
////10.5 Lay phan tu ra khoi Stack
//int Pop(int &x)
//{
//	if(sp!=NULL)
//	{
//		Node *p=sp;
//		x=p->info;
//		sp=p->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
////10.6 Xuat Stack
//void Process_stack()
//{
//	Node *p=sp;
//	do
//	{
//		cout<<p->info<<"\t";
//		p=p->link;
//	}while(p!=NULL);
//	cout<<endl;
//}
//int main()
//{
//	int choice, x, i;
//	system("cls");
//	cout<<"-----------------------BAI TAP 10, CHUONG 2, STACK(NGAN XEP - DSLK)----------------------------"<<endl;
//	cout<<"1.Khoi tao stack rong"<<endl;
//	cout<<"2.Them phan tu vao stack"<<endl;
//	cout<<"3.Lay phan tu ra khoi stack"<<endl;
//	cout<<"4.Xuat stack"<<endl;
//	cout<<"5.Thoat"<<endl;
//	do
//	{
//		cout<<"Chon so de thuc hien: ";
//		cin>>choice;
//		switch(choice)
//		{
//			case 1:
//				init();
//				cout<<"Khoi tao stack rong thanh cong"<<endl;
//				break;
//			case 2:
//				cout<<"Nhap gia tri x muon them vao: ";
//				cin>>x;
//				Push(x);
//				cout<<"Stack sau khi them la: ";
//				Process_stack();
//				break;
//			case 3:
//				Pop(x);
//				cout<<"Phan tu lay ra khoi stack la x = "<<x<<endl;
//				cout<<"Stack sau khi lay ra la: ";
//				Process_stack();
//				break;
//			case 4:
//				cout<<"Stack hien tai la: ";
//				Process_stack();
//				break;
//			case 5:
//				cout<<"Good bye!........."<<endl;
//				break;
//			default:
//				break;
//		}
//	}while(choice!=5);
//	system("pasue");
//	return 0;
//}