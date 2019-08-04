#include<iostream>
#include<windows.h>
#include<ctime>
#include<stdlib.h>
using namespace std;
define MAX 5000
int a[MAX];
int n;
void init(int a[], int& n)
{
	cout << "Nhap vao so luong phan tu cua danh sach: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10000 + 1;
	}
	cout << "Danh Sach Ngau Nhien:\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void input(int a[], int n) //Thu tuc nhap danh sach
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i + 1 << "] = ";
		cin >> a[i];
	}
		
}
void output(int a[], int n) //Thu tuc xuat danh sach
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void CopyArray(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}
void swap(int& a, int& b) //Ham hoan vi
{
	int c;
	c = a;
	a = b;
	b = c;
}
void InsertionSort(int a[], int n) //SX tang dan voi Insertion Sort
{
	int x, j;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while (0 <= j && x < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void SelectionSort(int a[], int n) //SX tang dan voi Selection Sort
{
	int min_pos;
	for (int i = 0; i < n-1; i++)
	{
		min_pos = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min_pos])
				min_pos = j;
		swap(a[min_pos], a[i]);
	}
}
void InterchangeSort(int a[], int n) //SX tang dan voi Interchange Sort
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
	}
}
void BubbleSort(int a[], int n) //SX tang dan voi Bubble Sort
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j-1] > a[j])
				swap(a[j], a[j - 1]);
}
void QuickSort(int a[], int left, int right) //SX tang dan voi Quick Sort
{
	int x = a[(left + right) / 2];
	int i = left, j = right;
	while (j > i)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++; j--;
		}
	}
	if (left < j)
		QuickSort(a, left, j);
	if (right > i)
		QuickSort(a, i, right);
}
void shift(int a[], int i, int n) //Thu tuc tao Heap
{
	int j = 2 * i + 1;
	if (j >= n)
		return;
	if (j + 1 < n)
		if (a[j] < a[j + 1])
			j++;
	if (a[i] >= a[j])
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, i, x);
	}
}
void HeapSort(int a[],int n) //SX tang dan voi Heap Sort
{
	int i = n / 2;
	while (i >= 0)
	{
		shift(a, i, n - 1);
		i--;
	}
	int right = n - 1;
	while (right > 0)
	{
		swap(a[0], a[right]);
		right--;
		if (right > 0)
			shift(a, 0, right);
	}
}
int Search(int a[], int n, int x) //Tim kiem tuan tu
{
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			return i;
	return -1;
}
int BinarySearch(int a[], int l,int r, int x) //Tim kiem nhi phan
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			return BinarySearch(a, l, mid - 1, x);
		else
			return BinarySearch(a, l, mid - 1, x);
	}
	return -1;
}
int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int x, choice, i, left, right;
		system("cls");
	cout << "====== Bai 1, Chuong 3, Sap Xep va Tim Kiem ======\n";
	cout << "0. Khoi tao DS Ngau Nhien\n";
	cout << "1. Nhap DS\n";
	cout << "2. Xuat Danh Sach\n";
	cout << "3. Sap Xep tang dan voi Insertion Sort\n";
	cout << "4. Sap Xep tang dan voi Selection Sort\n";
	cout << "5. Sap Xep tang dan voi Bubble Sort\n";
	cout << "6. Sap Xep tang dan voi Interchange Sort\n";
	cout << "7. Sap Xep tang dan voi Quick Sort\n";
	cout << "8. Sap Xep tang dan voi Heap Sort\n";
	cout << "9. Tim phan tu x bang Tim Kiem Tuan Tu\n";
	cout << "10. Tim phan tu x bang Tim Kiem Nhi Phan\n";
	cout << "11. Thoat\n";
	do
	{
		cout << "Vui Long nhap so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			init(a, n);
			break;
		case 1:
			cout << "Nhap vao so phan tu cua DS: ";
			cin >> n;
			input(a, n);
			break;
		case 2:
			cout << "DS vua tao la:\n";
			output(a, n);
			break;
		case 3:
			CopyArray(a, b, n);
			start = clock();
			InsertionSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi xep thu tu voi InsertionSort la:\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian InsertionSort: " << duration * 1000000 << " Microseconds" << endl;
			break;
		case 4:
			CopyArray(a, b, n);
			start = clock();
			SelectionSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
		if (n < 100)
			{
				cout << "DS sau khi xep thu tu voi SelectionSort la:\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian SelectionSort: " << duration * 1000000 << " Microseconds" << endl;
			break;
		case 5:
			CopyArray(a, b, n);
			start = clock();
			BubbleSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi xep thu tu voi BubbleSort la:\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian BubbleSort: " << duration * 1000000 << " Microseconds" << endl;
			break;
		case 6:
			CopyArray(a, b, n);
			start = clock();
			InterchangeSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi xep thu tu voi InterchangeSort la:\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian InterchangeSort: " << duration * 1000000 << " Microseconds" << endl;
			break;
		case 7:
			CopyArray(a, b, n);
			left = 0, right = n - 1;
			start = clock();
			QuickSort(b,left,right);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi xep thu tu voi QuickSort la:\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian QuickSort: " << duration * 1000000 << " Microseconds" << endl;
			break;
		case 8:
			CopyArray(a, b, n);
			start = clock();
			HeapSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi xep thu tu voi HeapSort la:\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian HeapSort: " << duration * 1000000 << " Microseconds" << endl;
			break;
		case 9:
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			start = clock();
			i = Search(a, n, x);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (i == -1)
				cout << "Khong Tim Thay phan tu x = " << x << endl;
			else
				cout << "Tim Thay phan tu x = " << x << " tai vi tri i = " << i << endl;
			if (duration > 0)
				cout << "Thoi gian tim kiem nhi phan la: " << duration * 100000 << " Microseconds" << endl;
			break;
		case 10:
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			start = clock();
			i = BinarySearch(b,0,n-1, x);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (i == -1)
				cout << "Khong Tim Thay phan tu x = " << x << endl;
			else
				cout << "Tim Thay phan tu x = " << x << " tai vi tri i = " << i << endl;
			if (duration > 0)
				cout << "Thoi gian tim kiem nhi phan la: " << duration * 100000 << " Microseconds" << endl;
			break;
		case 11:
			cout << "GOODBYE..........!\n";
			break;
		default:
			break;
		}
}while (choice != 11);
	system("pause");
	return 0;
}