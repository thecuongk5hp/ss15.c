#include <stdio.h>
struct student{
    char name[100];
    int age;
    int phone;
    char email[100];
};

int main() {
	int n;
	printf("nhap so luong sinh vien:");
	scanf("%d", &n);
    struct student id[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap ten sinh vien: ");
        fflush(stdin);
        gets(id[i].name);
        printf("Nhap tuoi: ");
        scanf("%d", &id[i].age);
        printf("Nhap so dien thoai: ");
        scanf("%d", &id[i].phone);
        printf("Nhap email: ");
        fflush(stdin);
        gets(id[i].email);
    }
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < n; i++) {
        printf("ten sinh vien:%s, tuoi: %d, so dien thoai: %d, email:%s \n",
               id[i].name, id[i].age, id[i].phone,id[i].email );
    }

    return 0;
}
