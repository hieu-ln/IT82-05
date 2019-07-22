//#include<iostream>
//using namespace std;
//struct Node 
//{
//	int info;
//	Node *link;
//};
//Node *sp;
//void init()
//{
//	sp = NULL;
//}
//int isempty()
//{
//	if(sp == NULL)
//		return 1;
//	return 0;
//}
//void push( int x)
//{
//		Node *p = new Node;
//	p->info = x;
//	p->link = sp;
//	sp = p;
//}
//int pop(int &x)
//{
//	if(sp != NULL)
//	{
//			Node *p=sp;
//		x = p->info;
//		sp=p->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//void process_stack()
//{
//	Node*p=sp;
//	do
//	{
//		cout<<p->info<<" ";
//		p=p->link;
//	}while(p != NULL);
//	cout<<endl;
//}
//int main()
//{
//	int choice = 0,x,i;
//	system("cls");
//	cout<<"\n1.Khoi tao STACK rong ";
//	cout<<"\n2.Them phan tu vao stack ";
//	cout<<"\n3.Lay phan tu ra khoi stack ";
//	cout<<"\n4.Xuat stack ";
//	cout<<"\n5.Thoat ";
//	do
//	{
//		cout<<"\nChon so thuc hien: ";
//		cin>>choice;
//		switch(choice)
//		{
//			case 1:
//				init();
//				cout<<"\nKhoi tao stack rong thanh cong ! ";
//				break;
//			case 2:
//				cout<<"\nNhap x: ";
//				cin>>x;
//				push(x);
//				cout<<"\nStack sau khi  them la: ";
//				process_stack();
//				break;
//			case 3:
//				pop(x);
//				cout<<"Phan tu lay ra tu stack la x= "<<x<<endl;
//				cout<<"\nStack sau khi lay ra la: ";
//				process_stack();
//				break;
//			case 4:
//				cout<<"\nStack hien tai la: ";
//				process_stack();
//				break;
//			case 5:
//				cout<<"\nTam biet !";
//				break;
//			default:
//				break;
//		}
//	}while(choice!=5);
//	cout<<endl;
//	system("pause");
//	return 0;
//}