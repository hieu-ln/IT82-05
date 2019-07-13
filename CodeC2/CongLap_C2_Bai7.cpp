//#include <iostream>
//#include <stdio.h>
//using namespace std;
//#define MAX 100
//void init(int a[],int &front, int &rear)
//{
//	front=-1;
//	rear=-1;
//}
//int isEmpty(int a[], int &front, int &rear)
//{
//	if(front==rear)
//		return 1;
//	else 
//		return 0;
//}
//int isFull(int a[], int &front, int &rear)
//{
//	if((front == 0 && rear == MAX-1)||(front-rear == 1))
//		return 1;
//	else 
//		return 0;
//}
//int Push(int a[], int &front, int &rear, int x)
//{
//	if(rear-front == MAX-1)
//		return 0;
//	else
//	{
//		if(front==-1)
//			front=0;
//		if(rear==MAX-1)
//		{
//			for(int i=front;i<=rear;i++)
//			{
//				a[i-front]=a[i];
//			}
//			rear=MAX-1-front;
//			front=0;
//		}
//		a[++rear]=x;
//		return 1;
//	}
//	return 0;
//}
//int Pop(int a[], int &front, int &rear, int &x)
//{
//	if(front==-1)
//		return 0;
//	else
//	{
//		x=a[front++];
//		if(front>rear)
//		{
//			front=-1;
//			rear=-1;
//		}
//		return 1;
//	}
//	return 0;
//}
//void Process_queue(int a[],int f, int r)
//{
//	cout<<"f= "<<f<<"\t r="<<r<<endl;
//	if(f<=r && f!=-1)
//	{
//		cout<<"<---   ";
//		for(int i=f;i<r+1;i++)
//		{
//			cout<<a[i]<<"    ";
//		}
//		cout<<"<----"<<endl;
//	}
//}
//int main()
//{
//	int a[MAX];
//	int choice, f, r, x, i;
//	system("cls");
//	cout<<"----------------------------BAI TAP 7 CHUONG 2, QUEUE(HANG DOI)-----------------------------"<<endl;
//	cout<<"1. Khoi tao queue rong"<<endl;
//	cout<<"2. Them phan tu vao Queue"<<endl;
//	cout<<"3. Lay phan tu ra khoi Queue"<<endl;
//	cout<<"4. Kiem tra Queue co rong khong"<<endl;
//	cout<<"5. Kiem tra Queue co day hay khong"<<endl;
//	cout<<"6. Xuat Queue "<<endl;
//	cout<<"7. Thoat"<<endl;
//	do
//	{
//		cout<<"\nChon so de thuc hien: ";
//		cin>>choice;
//		switch(choice)
//		{
//			case 1:
//				init(a, f ,r);
//				cout<<"Khoi tao queue rong thanh cong";
//				break;
//			case 2:
//				cout<<"Nhap gia tri x = ";
//				cin>>x;
//				i=Push(a,f,r,x);
//				cout<<"Queue sau khi them la: ";
//				Process_queue(a,f,r);
//				break;
//			case 3:
//				i=Pop(a,f,r,x);
//				cout<<"Phan tu lay ra khoi queue la x = "<<x<<endl;
//				cout<<"Queue sau khi lay ra la: ";
//				Process_queue(a,f,r);
//				break;
//			case 4:
//				i=isEmpty(a,f,r);
//				if(i==0)
//					cout<<"Queue khong rong! "<<endl;
//				else
//					cout<<"Queue rong! "<<endl;
//				break;
//			case 5:
//				i=isFull(a,f,r);
//				if(i==0)
//					cout<<"Queue chua day! "<<endl;
//				else
//					cout<<"Queue da day! "<<endl;
//				break;
//			case 6:
//				cout<<"Queue hien tai la: ";
//				Process_queue(a,f,r);
//				break;
//			case 7:
//				cout<<"Goodbye......!"<<endl;
//				break;
//			default:
//				break;
//
//
//
//		}
//	}while(choice!=7);
//	system("pause");
//	return 0;
//
//}