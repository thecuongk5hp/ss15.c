#include <stdio.h>
struct SinhVien {
    char hoTen[50];
    int tuoi;
    char soDienThoai[20];
    char email[50];
};

void nhapThongTinSinhVien(struct SinhVien *sv) {
    printf("Nhap ho ten: ");
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
    struct SinhVien sv;
    nhapThongTinSinhVien(&sv);
    xuatThongTinSinhVien(sv);
    return 0;
}
