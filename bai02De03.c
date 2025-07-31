#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct Node
{
    char title[MAX];
    char author[MAX];
    int year;
    struct Node *left;
    struct Node *right;
} Node;

int main(void)
{
    int answer;
    do
    {
        printf("—————————— LIBRARY MANAGER ————————\n");
        printf("1. THÊM MỚI SÁCH\n");
        printf("2. HIỂN THỊ DANH SÁCH SÁCH THEO TIÊU ĐỀ\n");
        printf("3. TÌM SÁCH THEO TIÊU ĐỀ\n");
        printf("4. XÓA SÁCH THEO TIÊU ĐỀ\n");
        printf("5. THỐNG KÊ TỔNG SỐ SÁCH\n");
        printf("6. THOÁT CHƯƠNG TRÌNH\n");
        printf("LỰA CHỌN CỦA BẠN: \n");
        scanf("%d", &answer);

        switch (answer)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:
            printf("Đang thoát chương trình...");
            break;
        default:
            printf("Sai cu phap.\n");
            break;
        }
    } while (answer != 6);
}