#include <stdio.h>
#include <stdlib.h>
struct SinhVien
{
    int MSV;
    char hoTen[30];
    float d1, d2, dTB;
};

struct Node
{
    SinhVien data;
    Node *link;
};

struct List
{
    Node *first;
    Node *last;
};

List L;
Node *p;

Node *getNode()
{
    p = new Node;
    printf("Ma sinh vien: ");
    scanf("%d", &p->data.MSV);
    fflush(stdin);
    printf("Ho ten: ");
    gets(p->data.hoTen);
    printf("Diem mon 1: ");
    scanf("%f", &p->data.d1);
    printf("Diem mon 2: ");
    scanf("%f", &p->data.d2);
    p->data.dTB = (p->data.d1 + p->data.d2) / 2;
    p->link = NULL;
}

void initListLIFO(List &L, int n)
{
    L.first = L.last = NULL;
    for (int i = 1; i <= n; i++)
    {
        printf("Nhap thong tin sv thu %d: \n", i);
        p = getNode();
        if (L.first == NULL)
            L.last = p;
        p->link = L.first;
        L.first = p;
    }
}

void printList(List L)
{
    if (L.first == NULL)
    {
        printf("Danh sach rong !");
        return;
    }
    else
    {
        p = L.first;
        while (p != NULL)
        {
            printf("%-10d| %-30s| %-5.2f| %-5.2f| %-5.2f\n", p->data.MSV, p->data.hoTen, p->data.d1, p->data.d2, p->data.dTB);
            p = p->link;
        }
    }
}
//them node vao dau danh sach
void addFirst(List &L)
{
    p = getNode();           
    p->link = L.first;
    L.first = p;
    if (L.last == NULL)
    {
        L.last = p;
    }

}

void addLast(List &L)
{
    printf("\nNhap thong tin sv bo sung\n");
    p = getNode();
    if (L.first == NULL && L.last == NULL)
        L.first = p;
    else
        L.last->link = p;
    L.last = p;
}


void deleteFirst(List &L)
{
    if (L.first == NULL && L.last == NULL)
        return;
    p = L.first;
    if (L.first == L.last)
        L.first = L.last = NULL;
    else
        L.first = L.first->link;
    delete p;
}

void deleteLast(List &L)
{
    if (L.first == NULL && L.last == NULL)
        return;
    p = L.last;
    if (L.first == L.last)
        L.first = L.last = NULL;
    Node *q = L.first;
    for (; q != NULL; q = q->link)
    {
        if (q->link == L.last)
        {
            q->link = NULL;
            L.last = q;
            break;
        }
    }
    delete p;
}


void deleteNode(List &L, int x)
{
    if (L.first->data.MSV == x) {
        deleteFirst(L);
        return;
    }
    if (L.last->data.MSV == x) {
        deleteLast(L);
        return;
    }
    Node *q = L.first;
    Node *g = new Node();
    while (q != NULL)
    {
        if (q->data.MSV == x)
        {
            g->link = q->link;
            q->link = NULL;
            delete q;
            return;
        }
        g = q;
        q = q->link;
    }
}
int main()
{
    int n, maSV;
    int select;
    while (true)
    {
        printf("\n\n\n============== PHAN MEM QUAN LY SINH VIEN ================\n");
        printf("\n1. Tao danh sach n sinh vien theo cau truc LIFO");
        printf("\n2. Bo sung them 1 sinh vien vao cuoi danh sach");
        printf("\n3. Bo sung them 1 sinh vien vao dau danh sach");
        printf("\n4. Xoa sinh vien dau danh sach");
        printf("\n5. Xoa sinh vien cuoi danh sach");
        printf("\n6. Xoa sinh vien bat ki trong danh sach theo MSV");
        printf("\n7. Hien thi danh sach sinh vien");
        printf("\n8. Thoat phan mem");
        printf("\n\nNhap lua chon cua ban: ");
        scanf("%d", &select);

        switch (select)
        {
        case 1: //khoi tao danh sach
        {
            printf("Nhap so luong phan tu trong danh sach: ");
            scanf("%d", &n);
            initListLIFO(L, n);
            break;
        }
        case 2: //Bổ sung thêm 1 sinh viên vào cuối danh sách
        {
            addLast(L);
            break;
        }
        case 3: //Bổ sung thêm 1 sinh viên vào đầu danh sách
        {
            addFirst(L);
            break;
        }
        case 4: //Xóa sinh viên đầu danh sách
        {
            deleteFirst(L);
            break;
        }
        case 5: //Xóa sinh viên cuối danh sách
        {
            deleteLast(L);
            break;
        }
        case 6: //Xóa sinh viên bất kỳ
        {
            printf("\nNhap ma sinh vien can xoa: ");
            scanf("%d", &maSV);
            deleteNode(L, maSV);
            break;
        }
        case 7: //Hiển thị danh sách sinh viên
        {
            printf("\nDanh sach cua ban: \n\n");
            printf("%-10s| %-30s| %-5s| %-5s| %-5s\n", "MSV", "HOTEN", "D1", "D2", "DTB");
            printList(L);
            break;
        }
        case 8: //Thoát chương trình
        {
            printf("Chuong trinh ket thuc!");
            exit(0);
            break;
        }
        default:
        {
            printf("Ban da nhap 1 tuy chon khong co trong danh sach xin moi nhap lai!");
            break;
        }
        }
    }
    return 0;
}