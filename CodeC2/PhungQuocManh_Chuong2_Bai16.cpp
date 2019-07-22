//
//#include "iostream"
//using namespace std;
//
//
//typedef struct tagNode// định nghĩa một cấu trúc node
//{
//int info;// thông tin của node
//struct tagNode *pNext;//liên kết trỏ đến phần tử phía sau
//}NODE;
//
//// Cấu trúc node phải định nghĩa trước vì phần tử của danh sách là node
//
//typedef struct tagList // định nghĩa một cấu trúc danh sách, gồm hai phần tử: đầu và cuôi( đủ để quản lý ds)
//{
//NODE *pHead;// phần tử đầu
//NODE *pTail;// phần tử cuối
//}LIST;
//
//// khởi tạo cho dslk (bước này rất quan trọng)
//void INIT(LIST &k)
//{
//k.pHead = k.pTail = NULL;
//
//}
//
//
////Muốn tạo được danh sách trước tiên phải có node-> nên tạo node trước:
//NODE *GetNode(int x)// Tạo node (có thể thay bằng NODE* CreateNode(int x) cũng được, chẳng qua là cách đặt tên thôi)
//{ 
//NODE *p;// Khai báo một node tên là p
//p = new NODE;// xin cấp phát cho p
//if(p == NULL)// Nếu không đủ bộ nhớ
//{
//cout<<"Khong du bo nho: ";
//exit(1);// thoát khỏi lệnh hàm
//}
//// Ngược lại:
//p->info = x;// gán giá trị của x cho info của node
//p->pNext = NULL;// và p vì mới tạo nên pNext sẽ trỏ đến null, vì không có gì đằng sau nó
//return p;// trả về p
//}
//
//void AddFirst(LIST &l,NODE *new_ele)//chèn một phần tử vào đầu danh sách, lưu ý &l vì muốn lưu lại sự thay đổi của danh sách
//{//new_ele là node mới cần thêm vào đầu
//if(l.pHead == NULL)// nếu dslk rổng(chưa có phần tử nào)
//{
//l.pHead = new_ele;// gán phần tử đâu danh sách bằng new_ele
//l.pTail = l.pHead;// lúc này dslk mới có 1 phần tử nên pTail chính là pHead
//}
//else//Danh sách không rổng
//{
//new_ele->pNext = l.pHead;//node mới trỏ đến phần tử tiếp theo chính là phần tử đầu tiên của dslk
//l.pHead = new_ele;//khi đó phần tử mới đưa vào chính là pHead của ds
//}
//}
//
//NODE *InsertHeap(LIST &l , int x)//Chèn một node có giá trị(info) là x vào trong dslk
//{
//// Muốn chèn node có info là x thì mình phải tạo node có giá trị là x trước đã
//NODE *new_ele = GetNode(x);// Nên dòng này dùng để tạo node có info là x, không cân kiểm tra là có tạo được
//// hay không, vì trong hàm GetNode(int ) đã kiểm tra rồi
//if(l.pHead == NULL)//Nếu danh sách rổng: 
//{
//l.pHead = new_ele;//lúc này pHead chính là node vừa tạo ra
//l.pTail = l.pHead;// và pTail cũng chính là pHead
//}
//else // dslk không rổng
//{
//new_ele ->pNext = l.pHead;//Lúc này người ta chọn cách insert vào đầu danh sách, nên node vừa tạo trỏ đên pNext
//// chính là pHead
//l.pHead = new_ele;// Khi đó thì phần tử new_ele trở thành pHead của dslk
//}
//return new_ele;// trả về một node muốn insert vào
//}
//void PrintList(LIST k)
//{
//NODE *pNode;
//pNode = k.pHead;
//
//while(pNode!=NULL)
//{
//cout<<"\t"<<pNode->info;
//pNode = pNode->pNext;
//}
//}
//
//
//
//int main()
//{
//LIST l;//Tạo một dslk tên là l
//INIT(l);
//int n = 0;// số lượng phần tử muốn tạo cho dslk
//int a = 0;
//NODE *p = NULL;
//cout<<"\nNhap so luong node muon tao cho ds: ";
//cout<<n;
//for(int i=0;i<n;i++)
//{
//cout<<"\nNhap: ";
//cout<<a;
//p = GetNode(a);
//AddFirst(l,p);
//}
//cout<<"\nNoi dung danh sach: \n";
//PrintList(l);
//return 1;
//}