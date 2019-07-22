//#include<iostream>
//using namespace std;
//const int Max = 100;
//int front, rear;
//void init(int a[], int &front, int &rear)
//{
//	front = -1;
//	rear = -1;
//}
//int isempty(int a[], int f, int r)
//{
//	if( r == 0 && f == 0)
//		return 1;
//	return 0;
//}
//int isfull(int a[],int f, int r)
//{
//	if( f == Max-1 && r == Max-1)
//		return 1;
//	return 0;
//}
//int push(int a[], int &front, int &rear, int x)
//{
//	if(rear - front == Max -1)
//		return 0;
//	else 
//	{
//		if(front == -1)
//			front = 0;
//		if(rear == Max -1)
//		{
//			for(int i=front;i<=rear;i++)
//				a[i-front] = a[i];
//			rear = Max-1-front;
//			front = 0;
//		}
//		a[++rear]=x;
//		return 1;
//	}
//	return 0;
//}
//int pop(int a[], int &front, int &rear, int &x)
//{
//	if(front=-1)
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
//	}
//void Process_queue(int a[], int f, int r)
//{
//	cout<<"f= "<<f<<"\t r= "<<r<<endl;
//	if(f<=r && f!=1)
//	{
//		cout<<"<--  ";
//		for(int i=f;i<r+1;i++)
//		{
//			cout<<a[i]<<" ";
//		}
//		cout<<"<--  "<<endl;
//	}
//}
//int main()
//{
//	int a[Max];
//	int choice=0,f,r,x,i;
//	system("cls");
//	cout<"---BT 7,CHUONG 2, QUEUE (HANG DOI)---";
//	cout<<"\n1.Khoi tao queue rong ";
//	cout<<"\n2.Them phan tu vao queue ";
//	cout<<"\n3.Lay phan tu ra khoi queue ";
//	cout<<"\n4.Kiem tra queue co rong hay khong ";
//	cout<<"\n5.Kiem tra queue co day hay khong ";
//	cout<<"\n6.Xuat queue ";
//	cout<<"\n7.Thoat ";
//	do
//	{
//		cout<<"\nChon so thuc hien: ";
//		cin>>choice;
//		switch(choice)
//		{
//			case 1:
//				init(a,f,r);
//				cout<<"Khoi tao Queue thanh cong !";
//				break;
//			case 2:
//				cout<<"Nhap x: ";
//				cin>>x;
//				i=push(a,f,r,x);
//				cout<<"Queue sau khi them la: ";
//				Process_queue(a,f,r);
//				break;
//			case 3:
//				i = pop(a,f,r,x);
//				cout<<"\nPhan tu lay ra tu Queue la x = "<<x;
//				cout<<"\nQueue sau khi lay ra: ";
//				Process_queue(a,f,r);
//				break;
//			case 4:
//				i = isfull(a,f,r);
//				if(i == 0)
//					cout<<"\nQueue chua day ! ";
//				else
//					cout<<"\nQueue da day ! ";
//				break;
//			case 5:
//				i = isempty(a,f,r);
//				if(i == 0)
//					cout<<"\nQueue khong rong ! ";
//				else
//					cout<<"\nQueue rong ! ";
//				break;
//			case 6:
//				cout<<"Queue hien tai la: ";
//				Process_queue(a,f,r);
//				break;
//			case 7:
//				cout<<"CHAO TAM BIET !!! ";
//				break;
//			default:
//				break;
//		}
//	}while(choice != 7);
//	system("pause");
//	return 0;
//}