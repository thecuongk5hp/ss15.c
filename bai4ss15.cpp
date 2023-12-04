#include <stdio.h>
#include <string.h>
struct Book
{
    int id;
    char bookName[20];
    char authorName[50];
    int price;
    char bookCategory[50];
};
typedef struct Book bk;
void input(bk *a)
{
    printf("nhap ma sach:");
    scanf("%d", &a->id);
    printf("nhap ten sach:");
    getchar();
    gets(a->bookName);
    printf("nhap tac gia:");
    getchar();
    gets(a->authorName);
    printf("nhap gia:");
    scanf("%d", &a->price);
    printf("nhap the loai:");
    getchar();
    gets(a->bookCategory);
    getchar();
}
void output(bk *temp)
{
    printf("ma sach:%d, ten sach:%s, tac gia:%s, gia tien:%d, the loai:%s\n", temp->id, temp->bookName, temp->authorName, temp->price, temp->bookCategory);
}
void delete(bk *a, int j, int count)
{
    for (int i = j; i < count; i++)
    {
        *(a + i) = *(a + i + 1);
    }
}
void price_sort_increase(bk temp[], int index)
{
    for (int i = 0; i < index - 1; i++)
    {
        for (int j = i + 1; j < index; j++)
        {
            if ((temp + i)->price > (temp + j)->price)
            {
                bk t = *(temp + i);
                *(temp + i) = *(temp + j);
                *(temp + j) = t;
            }
        }
    }
}
void price_sort_decrease(bk temp[], int index)
{
    for (int i = 0; i < index - 1; i++)
    {
        for (int j = i + 1; j < index; j++)
        {
            if (temp[i].price < temp[j].price)
            {
                bk t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }
}
struct Book book[50];

int main()
{
    int bookNumber = 0, n;
    int index = 0;
    do
    {
        printf("1.Nhap so luong va thong tin sach\n");
        printf("2.Hien thi thong tin sach\n");
        printf("3.Them sach vao vi tri\n");
        printf("4.Xoa sach theo ma\n");
        printf("5.Cap nhap thong tin sach theo ma sach\n");
        printf("6.Sap xep sach theo gia(tang dan)\n");
        printf("7.Tim kiem sach theo ten sach\n");
        printf("8.Tim kiem sach theo khoang gia\n");
        printf("9.Thoat\n");
        int choice;
        printf("Nhap lua chon cua ban");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("nhap so luon sach can them vao ");
            scanf("%d", &n);
            printf("Nhap lan luot thong tin\n");
            for (int i = 0; i < n; i++)
            {
                input(&book[i]);
                index++;
            }
            break;
        case 2:
            for (int i = 0; i < index; i++)
            {
                printf("%d:", i + 1);
                output(&book[i]);
            }
            break;
        case 3:
            int add_index;
            printf("nhap vi tri can chen :");
            scanf("%d", &add_index);
            if (add_index > index)
            {
                input(&book[add_index]);
                index = add_index;
            }
            else
            {
                for (int i = index; i >= add_index; i--)
                {
                    book[i] = book[i - 1];
                    if (i == add_index)
                        input(&book[i]);
                }
                index++;
            }
            break;
        case 4:
            int delete_id;
            printf("nhap vao id can xoa");
            scanf("%d", &delete_id);
            for (int i = 0; i < index; i++)
            {
                if (book[i].id == delete_id)
                {
                    for (int j = i; j < index - 1; j++)
                        book[i] = book[i + 1];
                }
            }
            index--;
            break;
        case 5:
            int update_id;
            printf("Nhap vao id can thay doi");
            scanf("%d", &update_id);
            input(&book[update_id]);
            break;
        case 6:
            int sort_choice;
            printf("lua chon cach sap xep:\n");
            printf("1.tang dan\n");
            printf("2.giam dan\n");
            scanf("%d", &sort_choice);
            switch (sort_choice)
            {
            case 1:
                price_sort_increase(book, index);
                break;
            case 2:
                price_sort_decrease(book, index);
                break;
            default:
                printf("khong hop le");
                break;
            }
            break;
        case 7:
            char find_name[50];
            getchar();
            printf("nhap vao ten sach can tim:");
            getchar();
            puts(find_name);
            for (int i = 0; i < index; i++)
            {
                if (strcmp(find_name, book[i].bookName) == 0)
                {
                    output(&book[i]);
                    break;
                }
            }
            break;
        case 8:
            int first_price, last_price;
            printf("nhap vao gia tri dau tien:");
            scanf("%d", &first_price);
            printf("nhap vao gia tri dau cuoi:");
            scanf("%d", &last_price);
            for (int i = 0; i < index; i++)
            {
                if ((book[i].price > first_price) && (book[i].price < last_price))
                    output(&book[i]);
            }
            break;
        case 9:
            return 0;
        default:
            printf("Nhap tu 1 - 9");
            break;
        }
    } while (1);
}
