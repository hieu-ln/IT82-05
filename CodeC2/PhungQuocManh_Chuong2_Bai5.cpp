//#include <iostream>
//using namespace std;
//const int Max = 100;
//void init(int a[], int &sp)
//{
//	sp = -1;
//}
//int isEmpty (int a[], int sp)
//{
//	if(sp == -1)
//		return 1;
//	return 0;
//}
//int isFull (int a[], int sp)
//{
//	if(sp == Max-1)
//		return -1;
//	return 0;
//}
//int push(int a[], int &sp, int x)
//{
//	if(sp < Max - 1)
//		a[++sp] = x;
//	return 1;
//}
//int pop(int a[], int &sp, int &x)
//{
//	if(sp != -1)
//	{
//		x = a[sp--];
//		return 1;
//	}
//	return 0;
//}
//void process_stack(int a[], int sp)
//{
//	for(int i=0;i<sp+1;i++)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
//}
//int main()
//{
//	int a[Max];
//	int choice = 0, sp, x, i;
//	system("cls");
//	cout<<"\n----BT 5, CHUONG 2, NGAN XEP (STACK) ";
//	cout<<"\n1.Khoi tao STACK rong ";
//	cout<<"\n2.Them phan tu vao STACK ";
//	cout<<"\n3.Lay phan tu ra khoi STACK ";
//	cout<<"\n4.Kiem tra STACK co rong hay khong ";
//	cout<<"\n5.Kiem tra STACK co day hay khong ";
//	cout<<"\n6.Xuat STACK ";
//	cout<<"\n7.Thoat ";
//	do
//	{
//		cout<<"\nChon so thuc hien: ";
//		cin>>choice;
//		switch(choice)
//		{
//			case 1:
//				init(a,sp);
//				cout<<"Ban vua khoi tao STACK thanh cong !";
//				break;
//			case 2:
//				cout<<"Nhap x: ";
//				cin>>x;
//				i = push(a,sp,x);
//				cout<<"STACK sau khi them la: ";
//				process_stack(a,sp);
//				break;
//			case 3:
//				i = pop(a,sp,x);
//				cout<<"\nPhan tu lay ra tu STACK la x = "<<x;
//				cout<<"\nSTACK sau khi lay ra: ";
//				process_stack(a,sp);
//				break;
//			case 4:
//				i = isFull(a,sp);
//				if(i == 0)
//					cout<<"\nSTACK chua day ! ";
//				else
//					cout<<"\nSTACK da day ! ";
//				break;
//			case 5:
//				i = isEmpty(a, sp);
//				if(i == 0)
//					cout<<"\nSTACK khong rong ! ";
//				else
//					cout<<"\nSTACK rong ! ";
//				break;
//			case 6:
//				cout<<"STACK hien tai la: ";
//				process_stack(a,sp);
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
//			