//#include <stdio.h>
//#include <iostream>
//using namespace std;
////5.1 khai bao cau truc stack
//#define MAX 100
//int a[MAX];
//int sp;
////5.2 khoi tao stack rong
//void init(int a[], int &sp)
//{
//	sp = -1;
//}
////5.3 kiem tra ngan xep rong
//int isEmpty(int a[], int sp)
//{
//	if(sp == -1)
//		return 1;
//	return 0;
//}
////5.4 kiem tra ngan xep day
//int isFull(int a[],int sp)
//{
//	if(sp == MAX - 1)
//		return 1;
//	return 0;
//}
////5.5 Them phan tu vao ngan xep
//int Push(int a[],int &sp,int x)
//{
//	if(sp < MAX-1)
//	{
//		a[++sp]=x;
//		return 1;
//	}
//	return 0;
//}
////5.6 Xoa 1 phan tu
//int Pop(int a[], int &sp,int &x)
//{
//	if(sp!=-1)
//	{
//		x=a[sp--];
//		return 1;
//	}
//	return 0;
//}
////Xuat Stack
//void process_stack(int a[], int sp)
//{
//	for(int i=0;i<sp+1;i++)
//	{
//		cout<<a[i]<<"\t";
//	}
//	cout<<endl;
//}
//int main()
//{
//	int a[MAX];
//	int choice, sp, x,i;
//	system("cls");
//	cout<<"------------------- BAI TAP 5, CHUONG 2, STACK (NGAN XEP - DS DAC)----------------------"<<endl;
//	cout<<"1.Khoi tao stack rong"<<endl;
//	cout<<"2.Them phan tu vao stack"<<endl;
//	cout<<"3.Lay phan tu ra khoi stack"<<endl;
//	cout<<"4.Kiem tra stack da day chua"<<endl;
//	cout<<"5.Kiem tra stack co rong khong"<<endl;
//	cout<<"6.Kiem tra stack hien tai"<<endl;
//	cout<<"7.Thoat"<<endl;
//	do
//	{
//		cout<<"Nhap lua chon: ";
//		cin>>choice;
//		switch(choice)
//		{
//			case 1:
//				init(a,sp);
//				cout<<"khoi tao stack rong thanh cong!\n";
//				break;
//			case 2:
//				cout<<"Nhap gia tri x: ";
//				cin>>x;
//				i = Push(a,sp,x);
//				cout<<"Stack sau khi them la: ";
//				process_stack(a,sp);
//				break;
//			case 3:
//				i = Pop(a, sp, x);
//				cout<<"Phan tu lay ra khoi stack la x= "<<x<<endl;
//				process_stack(a,sp);
//				break;
//			case 4:
//				i = isFull(a, sp);
//				if(i==0)
//					cout<<"Stack chua day"<<endl;
//				else
//					cout<<"Stack da day"<<endl;
//				break;
//			case 5:
//				i = isEmpty(a,sp);
//				if(i==0)
//					cout<<"Stack khong rong!"<<endl;
//				else 
//					cout<<"Stack rong!"<<endl;
//				break;
//			case 6:
//				cout<<"Stack hien tai la: ";
//				process_stack(a,sp);
//				break;
//			case 7:
//				cout<<"Goodbye!"<<endl;
//				break;
//			default:
//				break;
//		}
//
//	}while(choice != 7);
//	system("pause");
//	return 0;
//}