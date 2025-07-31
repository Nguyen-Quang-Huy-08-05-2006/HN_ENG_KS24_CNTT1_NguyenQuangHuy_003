#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

typedef struct Node
{
    char url[MAX_LEN];
    struct Node *next;
} Node;

Node *backstack = NULL;
Node *forwardstack = NULL;
char currentPage[MAX_LEN] = "";

Node *createNode(const char *url)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Không thể cấp phát bộ nhớ. ");
        exit(1);
    }
    strcpy(newNode->url, url);
    newNode->next = NULL;
    return newNode;
}

void push(Node **stack, const char *url)
{
    Node *newNode = createNode(url);
    newNode->next = *stack;
    *stack = newNode;
}

char *pop(Node **Stack)
{
    if (*Stack == NULL)
        return NULL;
    Node *temp = *Stack;
    char *url = (char *)malloc(MAX_LEN * sizeof(char));
    strcpy(url, temp->url);
    *Stack = temp->next;
    free(temp);
    return url;
}

void clearStack(Node **Stack)
{
    while (*Stack != NULL)
    {
        Node *temp = *Stack;
        *Stack = (*Stack)->next;
        free(temp);
    }
}

void printStack(Node *Stack)
{
    Node *temp = Stack;
    while (temp != NULL)
    {
        printf("%s\n", temp->url);
        temp = temp->next;
    }
}

void visitWeb()
{
    char newUrl[MAX_LEN];
    printf("NHập địa chỉ mới: ");
    scanf(" %[^\n]", newUrl);

    if (strlen(currentPage) > 0)
    {
        push(&backstack, currentPage);
    }

    strcpy(currentPage, newUrl);
    clearStack(&forwardstack);

    printf("Truy cập web có url %s thành công\n", currentPage);
}

void back()
{
    if (backstack == NULL)
    {
        printf("Không có trang để quay lại.\n");
        return;
    }

    push(&forwardstack, currentPage);
    char *prev = pop(&backstack);
    strcpy(currentPage, prev);
    printf("%s", currentPage);
    free(prev);
    printf("\nĐã Quay lại\n");
}

void forward()
{
    if (forwardstack == NULL)
    {
        printf("Không có trang tiếp theo. \n");
        return;
    }
    push(&backstack, currentPage);
    char *next = pop(&forwardstack);
    strcpy(currentPage, next);
    printf("%s", currentPage);
    free(next);
    printf("\nTiến tới trang tiếp theo thành công. \n");
}

void viewCurrent()
{
    if (strlen(currentPage) == 0)
    {
        printf("Bạn đang không ở trang nào. \n");
        return;
    }
    else
    {
        printf("%s\n", currentPage);
    }
}

void history()
{
    if (backstack == NULL)
    {
        printf("Lịch sử Trống\n");
        return;
    }
    else
    {
        printf("Lịch sử truy cập của bạn: \n");
        printStack(backstack);
    }
}

void deleteHistory()
{
    if (backstack == NULL)
    {
        printf("Lịch sử Trống\n");
        return;
    }
    clearStack(&backstack);
    clearStack(&forwardstack);
    printf("Xóa lịch sử thành công\n");
}

int main(void)
{
    int answer;
    int url[MAX_LEN];

    do
    {
        printf("—————————— HISTORY BROWSER ————————\n");
        printf("1. TRUY CẬP WEBSITE: \n");
        printf("2. QUAY LẠI (BACK): \n");
        printf("3. TIẾN TỚI (FORWARD): \n");
        printf("4. XEM TRANG HIỆN TẠI: \n");
        printf("5. LỊCH SỬ TRUY CẬP: \n");
        printf("6. LÀM TRỐNG LỊCH SỬ TRUY CẬP.\n");
        printf("7. THOÁT CHƯƠNG TRÌNH.\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &answer);

        switch (answer)
        {
        case 1:
            visitWeb();
            break;
        case 2:
            back();
            break;
        case 3:
            forward();
            break;
        case 4:
            viewCurrent();
            break;
        case 5:
            history();
            break;
        case 6:
            deleteHistory();
            break;
        case 7:
            printf("Đang thoát chương trình...");
            break;
        default:
            printf("Sai cu phap!");
            break;
        }
    } while (answer != 7);

    return 0;
}