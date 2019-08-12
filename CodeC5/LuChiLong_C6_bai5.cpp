#include<iostream>
#include<stdio.h>
#include <fstream>
#include <sstream>
using namespace std;

#define MAX 20
//DSLK su dung cho STACK va QUEUE, VA DANH SACH KE
struct Node 
{
	int info;
	Node *link;
};
Node *first[MAX]; //*mang danh sach*//
int n; //*so dinh tren do thi*//
char verter[MAX]; //*ten dinh*//

//Su dung cho STACK va QUEUE
Node *sp;
Node* front, *rear;

/// STACK
void InitStack() 
{
	sp= NULL;
}

int isEmptyStack() 
{
	if (sp==NULL)
		return 1;
	return 0;
}

void PushStack(int x) 
{
	Node *p = new Node;
	p->info =x;
	p->link = sp;
	sp=p;

}

int PopStack( int &x) 
{
	if (sp!=NULL)
	{
		Node *p = sp;
		x= p->info ;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
/// end STACK

/// QUEUE 
void InitQueue() 
{
	front = NULL;
	rear = NULL;
}

int isEmptyQueue() 
{
	if ( front== NULL)
		return 1;
	return 0;
}

void PushQueue(int x) 
{
	Node *p = new Node;
	p->info =x;
	p->link = NULL;
	if ( rear==NULL)
		front =p;
	else
		rear ->link =p;
	rear =p;
}

int PopQueue( int &x) 
{
	if (front!=NULL) 
	{
		Node *p = front;
		x= p->info ;
		front = p->link;
		if (front== NULL) 
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}
///end QUEUE

//5.1
//Ham them mot phan tu vao DS
void InitGraph()
{
	n=0;
}
void InsertLast (Node *&first , Node *p)
{
	if (first== NULL)
		first =p;
	else
	{
		Node *q = first;
		while (q->link!= NULL)
		{
			q=q->link;
		}
		q->link= p;

	}
}
void inputGraphFromText()
{
	string line;
	ifstream myfile ("danhsachke1.txt");
	if (myfile.is_open())
	{
		myfile >>n;
		for ( int i=0;i<n;i++)
			myfile >> verter[i];
		string str;
		int i=0;
		while (getline(myfile,str))
		{
			istringstream ss (str);
			int u;
			while (ss>>u)
			{
				// dinh u
				Node *p = new Node;
				p->info =u;
				p->link= NULL;
				InsertLast (first[i-1],p);
			}
			i++;
		}
	}
}
// Ham nhap mang gom n DS
void inputGraph() 
{
	cout << "\nNhap so dinh do thi n: ";
	cin >> n;
	cout << " Nhap ten dinh: ";
	for(int i = 0; i < n; i++) 
		cin >> verter[i];
	for (int i=0; i<n+1;i++)
	{
		if(i>0)
		cout << "\nNhap DSK cua dinh thu " << i - 1 << " ("<<verter[i-1]<<"): ";
		int u;
		string str;
		while ( getline (cin, str))
		{
			istringstream ss (str) ;
			while (ss>>u)
			{
				Node *p= new Node;
				p->info = u;
				p->link = NULL;
				InsertLast (first[i-1],p);
				// cout << u << "-";
			}
			// cout << "i=" << i-1 << endl;
			break;
		}
	}
}
		
// 5.2
void outputGraph()
{
	for ( int i=0;i<n; i++)
	{
		cout << "Dinh " <<i<< " ("<<verter[i]<<"): ";
		Node *p = first[i];
		while (p!= NULL)
		{
			cout << p->info << " ";
			p = p->link;
		}
		cout << endl;
	}
}

// Ham xuat ra mot mang danh sah 
void output( int a[], int n ) 
{
		for(int i = 0; i < n; i++) 
			cout <<verter[a[i]] << " ";
}
 
//5.3
int C[100], bfs[100];
int nbfs =0;
void InitC()
{
	for ( int  i=0; i<n ; i++) // n la so dinh cua do thi
		C[i] =1;
}
void BFS (int v ) // v la dinh bat dau
{
	int p;
	Node *w;
	PushQueue(v);
	C[v]=0;
	while (front != NULL)
	{
		PopQueue(p);
		bfs[nbfs]= p;
		w= first[p];
		nbfs++;
		while (w!=NULL)
		{
			if (C[w->info])
			{
				PushQueue(w->info);
				C[w->info]=0;
			}
			w=w->link;
		}
	}
				
}
//5.4
int dfs[100];
int ndfs=0;
void DFS (int s)
{
	PushStack(s);
	dfs[ndfs]=s;
	ndfs++;
	C[s] =0;
	int u=s;
	Node *v = NULL;
	while (isEmptyStack()==0)
	{
		if (v==NULL)
			PopStack(u);
		v= first[u];
		while (v!=NULL)
		{
			if ( C[v->info]==1)
			{
				PushStack(u);
				PushStack(v->info);
				dfs[ndfs]=v->info;
				ndfs++;
				C[v->info]=0;
				u=v->info;
				break;
			}
			v=v->link;
		}

	}

}
//5.5
void Search_by_BFS (int x, int v) // v la dinh bat dau
{
	int p;
	Node *w;
	PushQueue(v);
	C[v]=0;
	while ( front !=NULL)
	{
		PopQueue(p);
		if (x==p)
		{
		cout << " Tim thay x= " << x<< endl;
		return;
		}
		w = first [p];
		while (w!= NULL)
		{
			if (C[w->info])
			{
				PushQueue(w->info);
				C[w->info]=0;
			}
		w=w->link;
		}
	}
}
int main() 
{
	int a[MAX];
	int b[MAX];
	int choice, x, i;
	system("cls");
	cout<< "-------------------BAI TAP 5 , CHUONG 5 , DANH SACH KE---------------------"<< endl;
	cout<< "1. Khoi tao danh sach ke rong" << endl;
	cout<< "2. Nhap vao danh sach ke tu file text " << endl;
	cout<< "3. Nhap danh sach ke " << endl;
	cout<< "4. Xuat danh sach ke " << endl;
	cout<< "5. Duyet do thi theo chieu rong BFS - QUEUE " << endl;
	cout<< "6. Duyet do thi theo chieu sau DFS - STACK " << endl;
	cout<< "7. Tim dinh X co gia tri x theo BFS " << endl;
	cout<< "8. Thoat" << endl;
	do {
		cout << "\nNhap vao so ban muon thuc hien: ";
		cin >> choice;

		switch(choice) 
		{
		case 1:
			InitGraph();
			cout << "Da khoi tao  danh sach ke rong thanh cong! " << endl;
			break;
		case 2: 
			inputGraphFromText();
			cout << "Ban vua nhap danh sach ke tu file : " << endl;
			outputGraph();
			break;
		case 3:
			inputGraph ();
			break;
		case 4: 
			outputGraph();
			break;
		case 5:
			InitQueue();
			InitC();
			cout << "Nhap dinh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << " Thu tu dinh sau khi duyet BFS: " <<endl;
			output(bfs,n);
			break;
		case 6:
			InitStack();
			InitC();
			cout << "Nhap dinh xuat phat: ";
			cin >>x;
			nbfs =0;
			DFS(x);
			cout << " Thu tu dinh sau khi duyet DFS: " <<endl;
			output(dfs,n);
			break;
		case 7:
			InitQueue();
			InitC();
			nbfs=0;
			cout << "Nhap gia tri x can tim: "; 
			cin >> x;
			Search_by_BFS(x,0);
			break;
		case 8:
			cout << "\nGOODBYE!" << endl;
			break;
		default:
			break;
		}
	} while(choice != 8);
	system("pause");
	return 0;
}