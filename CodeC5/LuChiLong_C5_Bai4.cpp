#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
#define MAX 20
int A[MAX][MAX];
int n;
char veterx[MAX];
struct Node
{
	int info;
	Node *link;
};
Node *sp;
Node *front,*rear;
//STACK
void initStack()
{
	sp=NULL;
}
int isEmptyStack()
{
	if(sp==NULL)
		return 1;
	return 0;
}
void PushStack(int x)
{
	Node *p =new Node;
	p->info=x;
	p->link=sp;
	sp=p;
}
int PopStack(int &x)
{
	if(sp!=NULL)
	{
		Node *p =sp;
		x=p->info;
		sp=p->link;
		delete p;
		return 1;
	}
}
//QUEUE
void initQueue()
{
	front=NULL;
	rear=NULL;
}
int isEmptyQueue()
{
	if(front==NULL)
		return 1;
	return 0;
}
void PushQueue(int x)
{
	Node *p =new Node;
	p->info=x;
	p->link=NULL;
	if(rear==NULL)
		front=p;
	else
		rear->link=p;
	rear = p;
}
int PopQueue(int &x)
{
	if(front!=NULL)
	{
		Node *p =front;
		front = p ->link;
		x = p->info;
		if(front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}
void initG()
{
	n=0;
}
//4.1 
void inputText()
{
	string line;
	ifstream myfile("D:\matranke1.txt");
	if(myfile.is_open())
	{
		myfile>>n;
		for(int  i = 0;i<n;i++)
			myfile>>veterx[i];
		for(int i=0;i<n;i++)
		{
			for(int j = 0;j<n;j++)
				myfile>>A[i][j];
		}
	}
}
void input()
{
	cout<<"Nhap dinh cua do thi n: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap ten dinh: ";
		cin>>veterx[i];
		cout<<"Nhap vao dong thu "<<i+1<<": ";
		for(int j=0;j<n;j++)
			cin>>A[i][j];
	}
}
//4.2 
void outputG()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<A[i][j]<<"\t";
		cout<<endl;
	}
}
void output(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<veterx[a[i]]<<"\t";
}
//4.3 
int C[100],bfs[100];
int nbfs=0;
void initC()
{
	for(int i=0;i<n;i++)
		C[i]=1;
}
void BFS(int v)
{
	int w,p;
	PushQueue(v);
	C[v]=0;
	while(front!=NULL)	
	{
		PopQueue(p);
		bfs[nbfs]=p;
		nbfs++;
		for(w=0;w<n;w++)
			if(C[w] && A[p][w] ==1)
			{
				PushQueue(w);
				C[w]=0;
			}
	}
}
//4.4 
int dfs[100];
int ndfs=0;
void DFS(int s)
{
	PushStack(s);
	dfs[ndfs];
	ndfs++;
	C[s]=0;
	int v=-1,u=s;
	while(isEmptyStack==0)
	{
		if(v==n)
			PopStack(u);
		for(v=0;v<n;v++)
			if(A[u][v]!=0 && C[v]==1)
			{
				PushStack(u);
				PopStack(v);
				dfs[ndfs]=v;
				ndfs++;
				C[v]=0;
				u=v;
				break;
			}
	}
}
//4.5 
void search_BFS(int x, int v)
{
	int w,p;
	PushQueue(v);
	C[v]=0;
	while(front!=NULL)
	{
		PopQueue(p);
		if(x==p)
		{
			cout<<"Tim thay x = "<<x<<endl;
			return;
		}
		for(w=0;w<n;w++)
			if(C[w]&& A[p][w]==1)
			{
				PushQueue(w);
				C[w]=0;
			}
	}
}
int main()
{
	int a[MAX];
	int b[MAX];
	int choice, p, sp, sp_b, x, i;
	system("cls");
	cout<<"---------------BAI TAP 4 , CHUONG 5 , Do thi----------------------\n";
	cout<<"1.Khoi tao ma tran ke rong\n";
	cout<<"2.Nhap ma tran ke tu file text\n";
	cout<<"3.Nhap ma  tran ke\n";
	cout<<"4.Xuat ma tran ke\n";
	cout<<"5.Duyet do thi theo chieu rong BFS - DSLK\n";
	cout<<"6.Duyet do thi theo chieu sau DFS - DSLK\n";
	cout<<"7.Tim dinh co gia tri x theo BFS\n";
	cout<<"8.Thoat\n";
	do
	{
		cout<<"\nVui long chon so de thuc hien ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				initG();
				cout<<"Da khoi tao ma tran ke rong thanh cong\n";
				break;
			case 2:
				inputText();
				cout<<"Ban vua nhap ma tran ke tu file: \n";
				outputG();
				break;
			case 3:
				input();
				break;
			case 4:
				outputG();
				break;
			case 5:
				initQueue();
				initC();
				cout<<"Nhap dinh xuat phat: ";
				cin>>x;
				nbfs=0;
				BFS(x);
				cout<<"Thu tu dinh sau khi duyet BFS la: \n";
				output(bfs,n);
				break;
			case 6:
				initStack();
				initC();
				cout<<"Nhap  dinh xuat phat: ";
				cin>>x;
				ndfs=0;
				DFS(x);
				cout<<"Thu tu sau khi duyet DFS la: \n";
				output(dfs,n);
				break;
			case 7:
				cout<<"Nhap gia tri x can tim: ";
				cin >> x;
				search_BFS(x,0);
				break;
			case 8:
				cout<<"GOODBYE!!";
				break;
			default:
				break;
		}
	}while(choice !=8);
	system("pause");
	return 0;
}

