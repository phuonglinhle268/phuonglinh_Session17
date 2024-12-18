#include <stdio.h>
#include <string.h>
#include <ctype.h>

void nhapChuoi(char **str) {
    printf("Nhap vao chuoi: ");
    fgets(*str, 1000, stdin);
    (*str)[strcspn(*str, "\n")] = '\0'; 
}
void opposite(char *str) {
    int len = strlen(str);
    printf("Chuoi dao nguoc la: ");
    for (int i = len - 1; i >= 0; i--) {
        putchar(str[i]);
    }
    printf("\n");
}
void compare(char *str1) {
    char str2[1000];
    printf("Nhap chuoi thu hai: ");
    fgets(str2, 1000, stdin);
    str2[strcspn(str2, "\n")] = '\0'; 
    if (strlen(str2) < strlen(str1)) {
        printf("Chuoi thu hai ngan hon chuoi dau.\n");
    } else if (strlen(str2) > strlen(str1)) {
        printf("Chuoi thu hai dai hon.\n");
    } else {
        printf("Hai chuoi bang nhau\n");
    }
}
void inHoa(char *str) {
    printf("Chuoi khi in hoa: ");
    while (*str) {
        putchar(toupper(*str));
        str++;
    }
    printf("\n");
}
void add(char **str) {
    char str2[1000];
    printf("Nhap chuoi muon them: ");
    fgets(str2, 1000, stdin);
    str2[strcspn(str2, "\n")] = '\0'; 
    strcat(*str, str2); 
    printf("Chuoi sau khi them la: %s\n", *str);
}
int main() {
    char chuoi[1000];
    char *str = chuoi;
    int choice;

    do {
        printf("MENU\n");
        printf("1. Nhap chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Ðem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh do dai voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban la: ") 
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                nhapChuoi(&str);
                break;
            case 2:
                opposite(str);
                break;
            case 4:
                compare(str);
                break;
            case 5:
                inHoa(str);
                break;
            case 6:
                add(&str);
                break;
            case 7:
                printf("Thoat\n");
                break;
            default:
                printf("Lua chon khong hop li. Hay chon lai\n");
        }
    } while (choice != 7); 
    return 0;
}
