#include <iostream>

using namespace std;
int n = 0;

typedef struct NODE {
	NODE* pNext;
	int data;
}Node;

typedef struct LIST {
	Node* pHead;
	Node* pTail;
}List;

void tao_List(List& l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

Node* tao_Node(int x) {
	Node* p = new Node;
	p->data = x;
	p->pNext = NULL;
	return p;
}

void xuat_DSLK(List l) {
	cout << "Danh sach lien ket la: ";
	for (Node* k = l.pHead; k != NULL; k = k->pNext) {
		cout << k->data << " ";
	}
	cout << "\n";
}

void them_Node_Vao_Dau(List& l, Node* p) {
	if (l.pHead == NULL) l.pHead = l.pTail = p;
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void them_Node_Vao_Cuoi(List& l, Node* p) {
	if (l.pHead == NULL) l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}


void them_NodeP_Vao_Sau_NodeQ(List& l, Node* p) {
	int y;
	cout << "Nhap node Q: ";
	cin >> y;
	Node* q = tao_Node(y);
	if (l.pHead == NULL) return;
	else if (l.pHead->pNext == NULL && l.pHead->data == q->data) them_Node_Vao_Cuoi(l, p);
	else {
		Node* g = new Node;
		for (Node* k = l.pHead; k != NULL; k = k->pNext) {
			if (k->data == q->data) {
				Node* h = tao_Node(p->data);
				g = k->pNext;
				k->pNext = h;
				h->pNext = g;
				n++;
			}
		}
	}
}

void them_NodeP_Vao_Truoc_NodeQ(List& l, Node* p) {
	int y;
	cout << "Nhap node Q: ";
	cin >> y;
	Node* q = tao_Node(y);
	if (l.pHead == NULL) return;
	else if (l.pHead->pNext == NULL && l.pHead->data == q->data) them_Node_Vao_Dau(l, p);
	else {
		Node* g = new Node;
		for (Node* k = l.pHead; k != NULL; k = k->pNext) {
			if (q->data == k->data) {
				Node* h = tao_Node(p->data);
				g->pNext = h;
				h->pNext = k;
				n++;
			}
			g = k;
		}
	}
}

void them_Node_Vao_Giua(List& l, Node* p) {
	if (l.pHead == NULL || l.pHead->pNext == NULL) return;
	else {
		Node* g = new Node;
		int dem = 0;
		for (Node* k = l.pHead; k != NULL; k = k->pNext) {
			dem++;
			if (dem == n / 2) {
				g = k->pNext;
				k->pNext = p;
				p->pNext = g;
				break;
			}
		}
	}
}

void them_Node_Vao_Vitri_BatKy(List& l, Node* p, int vitri) {
	if (vitri == 1) them_Node_Vao_Dau(l, p);
	else if (vitri == n + 1) them_Node_Vao_Cuoi(l, p);
	else {
		Node* g = new Node;
		int dem = 0;
		for (Node* k = l.pHead; k != NULL; k = k->pNext) {
			dem++;
			if (dem == vitri) {
				g->pNext = p;
				p->pNext = k;
				break;
			}
			g = k;
		}
	}
}

void xoa_Node_Dau_DS(List& l) {
	if (l.pHead == NULL) return;
	else {
		Node* tick = l.pHead;
		l.pHead = l.pHead->pNext;
		delete tick;
	}
}

void xoa_Node_Cuoi_DS(List& l) {
	if (l.pHead == NULL) return;
	else if (l.pHead->pNext == NULL) xoa_Node_Dau_DS(l);
	else {
		for (Node* k = l.pHead; k != NULL; k = k->pNext) {
			if (k->pNext == l.pTail) {
				delete l.pTail;
				k->pNext = NULL;
				l.pTail = k;
				break;
			}
		}
	}
}

void xoa_Node_Nam_Sau_NodeQ(List& l, Node* q) {
	if (l.pHead == NULL || l.pHead->pNext == NULL) return;
	else {
		for (Node* k = l.pHead; k != NULL; k = k->pNext) {
			if (q->data == k->data) {
				Node* g = k->pNext;
				k->pNext = g->pNext;
				delete g;
				n--;
			}
		}
	}
}

void xoa_Node_Co_Khoa_K_Batky(List& l, int x) {
	if (l.pHead == NULL) return;
	bool tick = true;
	for (Node* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->data != x) {
			tick = false;
			break;
		}
	}
	Node* g = new Node;
	if (tick) {
		while (l.pHead != NULL) {
			g = l.pHead;
			l.pHead = l.pHead->pNext;
			delete g;
		}
		l.pTail = NULL;
	}
	else {
		while (l.pHead->data == x) {
			if (l.pHead->data == x) xoa_Node_Dau_DS(l);
			n--;
		}
		for (Node* k = l.pHead; k != NULL; k = k->pNext) {
			if (k->data == x) {
				g->pNext = k->pNext;
				delete k;
				k = g;
				n--;
			}
			g = k;
		}
	}
}

void xoa_Node_Vitri_Batky(List& l, int vitri) {
	if (vitri == 1) xoa_Node_Dau_DS(l);
	else if (vitri == n) xoa_Node_Cuoi_DS(l);
	else {
		Node* g = new Node;
		int dem = 0;
		for (Node* k = l.pHead; k != NULL; k = k->pNext) {
			dem++;
			if (dem == vitri) {
				g->pNext = k->pNext;
				delete k;
				break;
			}
			g = k;
		}
	}
}

void Menu(List& l) {
	int luachon;
	while (1) {
		system("cls");
		cout << "\t\t\t================ Nhap lua chon ================";
		cout << "\n\t\t\t1. Them node vao dau danh sach.";
		cout << "\n\t\t\t2. Them node vao cuoi danh sach.";
		cout << "\n\t\t\t3. Them node p vao sau node q.";
		cout << "\n\t\t\t4. Them node p vao truoc node q.";
		cout << "\n\t\t\t5. Them node vao vi tri bat ky.";
		cout << "\n\t\t\t6. Xoa node dau danh sach.";
		cout << "\n\t\t\t7. Xoa node cuoi danh sach.";
		cout << "\n\t\t\t8. Xoa node o vi tri bat ky.";
		cout << "\n\t\t\t9. Xoa node nam sau node q.";
		cout << "\n\t\t\t10. Xuat danh sach.";
		cout << "\n\t\t\t11. Xoa node co khoa k bat ki.";
		cout << "\n\t\t\t12. Them node vao vi tri giua.";
		cout << "\n\t\t\t0. Thoat.";
		cout << "\n\t\t\t===================== END =====================";
		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon == 0) break;
		switch (luachon) {
		case 1: {
			int x;
			cout << "Nhap so nguyen can them: ";
			cin >> x;
			Node* p = tao_Node(x);
			them_Node_Vao_Dau(l, p);
			n++;
			break;
		}
		case 2: {
			int x;
			cout << "Nhap so nguyen can them: ";
			cin >> x;
			Node* p = tao_Node(x);
			them_Node_Vao_Cuoi(l, p);
			n++;
			break;
		}
		case 3: {
			int x;
			cout << "Nhap so nguyen can them: ";
			cin >> x;
			Node* p = tao_Node(x);
			them_NodeP_Vao_Sau_NodeQ(l, p);
			break;
		}
		case 4: {
			int x;
			cout << "Nhap so nguyen can them: ";
			cin >> x;
			Node* p = tao_Node(x);
			them_NodeP_Vao_Truoc_NodeQ(l, p);
			break;
		}
		case 5: {
			int x, vitri;
			cout << "Nhap so nguyen can them: ";
			cin >> x;
			Node* p = tao_Node(x);
			do {
				cout << "Nhap vi tri can them node [1, " << n + 1 << "]: ";
				cin >> vitri;
				if (vitri < 1 || vitri > n + 1) cout << "Moi nhap lai!";
			} while (vitri < 1 || vitri > n + 1);
			them_Node_Vao_Vitri_BatKy(l, p, vitri);
			n++;
			break;
		}
		case 6: {
			xoa_Node_Dau_DS(l);
			n--;
			break;
		}
		case 7: {
			xoa_Node_Cuoi_DS(l);
			n--;
			break;
		}
		case 8: {
			int vitri;
			do {
				cout << "\nNhap vi tri can xoa [1, " << n << "]: ";
				cin >> vitri;
				if (vitri < 1 || vitri > n) cout << "Moi nhap lai!";
			} while (vitri < 1 || vitri > n);
			xoa_Node_Vitri_Batky(l, vitri);
			n--;
			break;
		}
		case 9: {
			int y;
			cout << "Nhap node Q: ";
			cin >> y;
			Node* q = tao_Node(y);
			xoa_Node_Nam_Sau_NodeQ(l, q);
			break;
		}
		case 10: {
			xuat_DSLK(l);
			system("pause");
			break;
		}
		case 11: {
			int x;
			cout << "Nhap khoa x can xoa: ";
			cin >> x;
			xoa_Node_Co_Khoa_K_Batky(l, x);
			break;
		}
		case 12: {
			int x;
			cout << "Nhap so nguyen can them: ";
			cin >> x;
			Node* p = tao_Node(x);
			them_Node_Vao_Giua(l, p);
			n++;
			break;
		}
		default: {
			cout << "Lua chon khong hop le! moi nhap lai!";
			system("pause");
			break;
		}
		}
	}
}

void giai_Phong_Vung_Nho(List& l) {
	Node* k = l.pHead;
	while (k != NULL) {
		k = l.pHead;
		l.pHead = l.pHead->pNext;
		delete k;
	}
}

int main() {
	List l;
	tao_List(l);
	Menu(l);
	cout << n;
	giai_Phong_Vung_Nho(l);
	return 0;
}