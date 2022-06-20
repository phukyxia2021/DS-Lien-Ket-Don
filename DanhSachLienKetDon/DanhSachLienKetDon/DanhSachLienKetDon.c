// DanhSachLienKetDon.c

#include <stdio.h>

struct SINHVIEN {
    int mssv;
    char hoten[30];
};
struct node
{
    SINHVIEN info;
    node* next;
};
typedef node* NODEPTR;

NODEPTR GetNode() {
    NODEPTR p;
    p = (NODEPTR)malloc(sizeof(node));
    return p;
}

void FreeNode(NODEPTR p) {
    free(p);
}

void Initialize(NODEPTR* plist) {
    *plist = NULL;
}

int Empty(NODEPTR* plist) {
    return (*plist == NULL ? 1 : 0);
}

NODEPTR NodePointer(NODEPTR* plist, int i) {
    NODEPTR p;
    int pos;
    if (i < 0) {
        return NULL;
    }
    else {
        p = *plist;
        pos = 0;
        while (p != NULL && pos < i) {
            p = p->next;
            pos++;
        }
        return p;
    }
}

int Position(NODEPTR* plist, NODEPTR p) {
    NODEPTR q = *plist;
    int pos = 0;
    while(q!=NULL && q!= p)
    {
        q = q->next;
        pos++;
    }
    if (q == NULL) {
        return -1;
    }
    else {
        return pos;
    }
}


void Input1Student(SINHVIEN* sv) {
    printf("Ma so: ");
    scanf_s("%d", sv->mssv);
    printf("Ho ten: ");
    fflush(stdin);
    gets_s(sv->hoten);
}

void Output1Student(SINHVIEN sv) {
    printf("%d\t%s\n", sv.mssv, sv.hoten);
}

void Push(NODEPTR* plist, SINHVIEN x) {
    NODEPTR p;
    p = GetNode();
    p->info = x;
    p->next = *plist;
    *plist = p;
}

void InsAfter(NODEPTR p, SINHVIEN x) {
    if (p == NULL) {
        printf("Khong them nut duoc\n");
    }
    else {
        NODEPTR q;
        q = GetNode();
        q->info = x;
        q->next = p->next;
        p->next = q;
    }
}

SINHVIEN Pop(NODEPTR* plist) {
    if (Empty(plist)) {
        SINHVIEN x;
        x.mssv = -1;
        printf("Danh sach rong\n");
        return x;
    }
    else {
        NODEPTR p;
        SINHVIEN x;
        p = *plist;
        x = p->info;
        *plist = p->next;
        p->next = NULL;
        FreeNode(p);
        return x;
    }
}

SINHVIEN DelAfter(NODEPTR p) {
    if (p == NULL || p->next == NULL) {
        SINHVIEN x;
        x.mssv = -1;
        printf("Khong xoa nut duoc\n");
        return x;
    }
    else {
        NODEPTR q;
        SINHVIEN x;
        q = p->next;
        x = q->info;
        p->next = q->next;
        q->next = NULL;
        FreeNode(q);
        return x;
    }
}

void Traverse(NODEPTR* plist) {
    if (Empty(plist)) {
        printf("Danh sach rong\n");
    }
    else {
        NODEPTR p;
        int count = 0;
        p = *plist;
        while (p != NULL) {
            count++;
            printf("%d. %d\t%s\n", count, p->info.mssv, p->info.hoten);
            p = p->next;
        }
    }
}

NODEPTR Search(NODEPTR* plist, int x) {
    NODEPTR p;
    p = *plist;
    while (p != NULL && p->info.mssv != x) {
        p = p->next;
    }
    return p;
}

void Sort(NODEPTR* plist) {
    NODEPTR p, q;
    SINHVIEN temp;
    for (p = *plist; p != NULL; q = q->next) {
        for (q = p->next; q != NULL; q = q->next) {
            if (p->info.mssv > q->info.mssv) {
                temp = p->info;
                p->info = q->info;
                q->info = temp;
            }
        }    
    }
}

void Place(NODEPTR* plist, int x) {
    NODEPTR p, q;
    q = NULL;
    for (p = *plist; p != NULL && x.mssv > p->info.mssv; p = p->next) {
        q = p;
    }
    if (q == NULL) {
        Push(plist, x);
    }
    else {
        InsAfter(q, x);
    }
}

void BangChucNang() {
    printf("\nCHUONG TRINH QUAN LY SINH VIEN\n");
    printf("1. Xem danh sach sinh vien\n");
    printf("2. Them sinh vien vao danh sach\n");
    printf("3. Xoa sinh vien trong danh sach\n");
    printf("4. Sua sinh vien trong danh sach\n");
    printf("5. Sap xep danh sach theo ma sinh vien\n");
    printf("6. Tim kiem sinh vien theo ma sinh vien\n");
    prinf("7. Them sinh vien vao danh sach da sap xep\n");
    printf("8. Xoa danh sach\n");
    printf("0. Ket thuc chuong trinh");

}

//Chuong trinh chinh

int main()
{
    NODEPTR plist, p;
    SINHVIEN sv;
    int vitri, chucnang;
    char traloi;
    clrscr();
    Initialize(&plist);
    do {
        BangChucNang();
        printf("Moi chon chuc nang: ");
        scanf_s("%d", &chucnang);
        switch (chucnang)
        {
        case 1:
            printf("\nDanh sach sinh vien:\n");
            Traverse(&plist);
            break;
        }
        case 2:
            printf("Nhap vi tri them (0, 1, 2, 3,...): ");
            scanf_s("%d", &vitri);
            printf("\nNhap sinh vien muon them: ");
            Input1Student(&sv);
            if (vitri == 0) {
                Push(&plist, sv);
            }
            else {
                p = NodePointer(&plist, vitri - 1);
                if (p == NULL) {
                    printf("Vi tri khong hop le\n");
                }
                else {
                    InsAfter(p, sv);
                }
            }
            break;
        case 3:
            printf("Nhap vi tri xoa: ");
            scanf_s("%d", &vitri);
            if (vitri == 0) {
                Pop(&plist);
            }
            else {
                p = NodePointer(&plist, vitri - 1);
                DelAfter(p);
            }
            break;
        case 4:
            printf("\nVi tri can sua: ");
            scanf("%d", &vitri);
            p = NodePointer(&plist, vitri);
            if (p == NULL) {
                printf("Vi tri khong hop le\n");
            }
            else {
                printf("Nhap thong tin moi:\n");
                Input1Student(&sv);
                p->info = sv;
            }
        case 5:
            printf("Danh sach sinh vien da sap xep:\n");
            Sort(&plist);
            break;
        case 6:
            printf("Nhap ma sinh vien can tim: ");
            scanf_s("%d", &sv.mssv);
            p = Search(&plist, sv.mssv);
            if (p == NULL) {
                printf("\nKhong tim thay sinh vien\n");

            }
            else {
                vitri = Position(&plist, p);
                printf("Tim thay tai vi tri %d\n", vitri);
            }
            break;
        case 7:
            Sort(&plist);
            printf("Nhap sinh vien muon them\n");
            Input1Student(&sv);
            Place(&plist, sv);
            break;
        case 8:
            printf("Ban co muon xoa danh sach khong? (y/n)");
            traloi = getch();
            if (traloi == 'y' || traloi == 'Y') {
                ClearList(&plist);
            }
            break;
    } while (chucnang != 0);
}


