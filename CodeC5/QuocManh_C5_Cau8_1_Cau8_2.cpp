//#include <iostream>
//#include <fstream>
//using namespace std;
//const int MAX = 20
//int a[MAX][MAX];
//int n;
//char veterx[MAX];
//struct Node
//{
//	int info;
//	Node *link;
//};
//Node *sp;
//Node *front,*rear;
//void initQueue()
//{
//	front=NULL;
//	rear=NULL;
//}
//int isEmptyQ()
//{
//	if(front==NULL)
//		return 1;
//	return 0;
//}
//void PushQ(int x)
//{
//	Node *p =new Node;
//	p->info=x;
//	p->link=NULL;
//	if(rear==NULL)
//		front=p;
//	else
//		rear->link=p;
//	rear = p;
//}
//int PopQ(int &x)
//{
//	if(front!=NULL)
//	{
//		Node *p =front;
//		front = p ->link;
//		x = p->info;
//		if(front == NULL)
//		{
//			rear = NULL;
//		}
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//void initG()
//{
//	n=0;
//}
////4.1 Nhap vao ma tran
//void inputText()
//{
//	string line;
//	ifstream myfile("D:\matranke1.txt");
//	if(myfile.is_open())
//	{
//		myfile>>n;
//		for(int  i = 0;i<n;i++)
//			myfile>>veterx[i];
//		for(int i=0;i<n;i++)
//		{
//			for(int j = 0;j<n;j++)
//				myfile>>a[i][j];
//		}
//	}
//}
////4.2 Xuat ma tran ke
//void outputG()
//{
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//			cout<<a[i][j]<<"\t";
//		cout<<endl;
//	}
//}
//void output(int a[],int n)
//{
//	for(int i=0;i<n;i++)
//		cout<<veterx[a[i]]<<"\t";
//}
//int dfs[100];
//int ndfs=0;
//int C[100];
//void DFS(int s)
//{
//	PushQ(s);
//	dfs[ndfs];
//	ndfs++;
//	C[s]=0;
//	int v=-1,u=s;
//	while(isEmptyQ==0)
//	{
//		if(v==n)
//			PopQ(u);
//		for(v=0;v<n;v++)
//			if(a[u][v]!=0 && C[v]==1)
//			{
//				PushQ(u);
//				PopQ(v);
//				dfs[ndfs]=v;
//				ndfs++;
//				C[v]=0;
//				u=v;
//				break;
//			}
//	}
//}
//int main()
//{
//	int a[MAX];
//	int b[MAX];
//	int choice, p, sp, sp_b, x, i;
//	system("cls");
//	cout<<"------------------------Chuong 5, Bai 8,Do thi-------------------------------\n";
//	cout<<"1.Khoi tao ma tran ke rong\n";
//	cout<<"2.Nhap ma tran ke tu file text\n";
//	cout<<"3.Xuat ma tran ke\n";
//	cout<<"4.Duyet do thi theo chieu sau DFS - DSLK ( dung Queue)\n";
//	cout<<"5.Thoat\n";
//	do
//	{
//		cout<<"\nVui long chon so de thuc hien ";
//		cin>>choice;
//		switch(choice)
//		{
//			case 1:
//				initG();
//				cout<<"Khoi tao ma tran ke rong thanh cong\n";
//				break;
//			case 2:
//				inputText();
//				cout<<"Ban vua nhap ma tran ke tu file: \n";
//				outputG();
//			case 3:
//				initQueue();
//				initG();
//				cout<<"Vui long nhap dinh xuat phat: ";
//				cin>>x;
//				ndfs=0;
//				DFS(x);
//				cout<<"Thu tu dinh sau khi duyet DFS la: \n";
//				output(dfs,n);
//			case 4:
//				cout<<"Goodbye!..............";
//				break;
//			default:
//				break;
//		}
//	}while(choice !=4);
//	system("pause");
//	return 0;
//}