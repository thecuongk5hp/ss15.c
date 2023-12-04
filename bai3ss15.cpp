#include <stdio.h>
#include <stdlib.h>
struct SinhVien {
    char hoTen[50];
    int tuoi;
    char soDienThoai[20];
    char email[50];
};

void nhapThongTinSinhVien(struct SinhVien *sv) {
    printf("Nhap ho ten: ");
    fflush(stdin);
    gets(sv->hoTen);
    printf("Nhap tuoi: ");
    scanf("%d", &sv->tuoi);
    printf("Nhap so dien thoai: ");
    scanf("%s", sv->soDienThoai);
    printf("Nhap email: ");
    scanf("%s", sv->email);
}

void xuatThongTinSinhVien(struct SinhVien sv) {
    printf("Ho ten: %s\n", sv.hoTen);
    printf("Tuoi: %d\n", sv.tuoi);
    printf("So dien thoai: %s\n", sv.soDienThoai);
    printf("Email: %s\n", sv.email);
}

int main() {
    struct SinhVien sv[100];
    int n = 0;
    int choice;
    int i;
    while (1) {
        printf("1. Nhap thong tin sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua sinh vien theo vi tri\n");
        printf("4. Xoa sinh vien theo vi tri\n");
        printf("5. In danh sach sinh vien\n");
        printf("6. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                nhapThongTinSinhVien(&sv[n]);
                n++;
                break;
            case 2:
                nhapThongTinSinhVien(&sv[n]);
                n++;
                break;
            case 3:
                printf("Nhap vi tri sinh vien can sua: ");
                scanf("%d", &i);
                if (i >= 0 && i < n) {
                    nhapThongTinSinhVien(&sv[i]);
                } else {
                    printf("Vi tri khong hop le!\n");
                }
                break;
            case 4:
                printf("Nhap vi tri sinh vien can xoa: ");
                scanf("%d", &i);
                if (i >= 0 && i < n) {
                    for (int j = i; j < n - 1; j++) {
                        sv[j] = sv[j + 1];
                    }
                    n--;
                } else {
                    printf("Vi tri khong hop le!\n");
                }
                break;
            case 5:
                printf("Danh sach sinh vien:\n");
                for (int i = 0; i < n; i++) {
                    printf("Sinh vien thu %d:\n", i + 1);
                    xuatThongTinSinhVien(sv[i]);
                }
                break;
            case 6:
            exit(0);
                return 0;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    }
    return 0;
}

