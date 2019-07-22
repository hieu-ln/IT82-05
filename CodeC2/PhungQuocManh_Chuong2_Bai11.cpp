//#include<iostream>
//using namespace std;
//struct Node
//{
//	int info;
//	Node*link;
//};
//Node *front, *rear;
//void init()
//{
//	front=NULL;
//	rear=NULL;
//}
//int isempty()
//{
//	if(front == NULL)
//		return 1;
//	return 0;
//}
//void push(int x)
//{
//	Node*p=new Node;
//	p->info=x;
//	p->link=NULL;
//	if(rear == NULL)
//		front = p;
//	else
//		rear->link=p;
//	rear=p;
//}
//int pop(int &x)
//{
//	if(front != NULL)
//	{
//			Node*p=front;
//		front=p->link;
//		if(front == NULL)
//		{
//			rear=NULL;
//		}
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//void process_queue()
//{
//	if(front != NULL)
//	{
//		Node*p=front;
//		cout<<"<--  ";
//		do
//		{
//			cout<<p->info<<" ";
//			p=p->link;
//		}while(p!=NULL);
//		cout<<"<--"<<endl;
//	}
//}
//int main()
//{
//	int choice=0, x,i;
//	cout<<"\n1.Khoi tao queue rong ";
//	cout<<"\n2.Them phan tu vao queue";
//	cout<<"\n3.Lay phan tu ra khoi queue";
//	cout<<"\n4.Kiem tra queue co rong hay khong ";
//	cout<<"\n5.Xuat queue ";
//	cout<<"\n6.Thoat";
//	do
//	{
//		cout<<"\nChon so thuc hien: ";
//		cin>>choice;
//		switch(choice)
//		{
//			case 1:
//				init();
//				cout<<"\nKhoi tao queue thanh cong !";
//				break;
//			case 2:
//				cout<<"\nNhap x: ";
//				cin>>x;
//				push(x);
//				cout<<"\nQueue sau khi them la: ";
//				process_queue();
//				break;
//			case 3:
//				pop(x);
//				cout<<"Phan tu lay ra queue la x= "<<x<<endl;
//				cout<<"Queue sau khi lay ra la: ";
//				process_queue();
//				break;
//			case 4:
//				i = isempty();
//				if(i == 0)
//					cout<<"\nQueue khong rong ! ";
//				else
//					cout<<"Queue rong ! ";
//				break;
//			case 5:
//				cout<<"\nQueue hien tai la: ";e
//				process_queue();
//				break;
//			case 6:
//				cout<<"\nTam biet !";
//				break;
//			default:
//				break;
//		}
//	}while(choice != 6);
//	cout<<endl;
//	system("pause");
//	return 0;
//}