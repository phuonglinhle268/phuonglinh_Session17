#include <stdio.h>
#include <string.h>
#include <ctype.h>

void nhapChuoi(char **str) {
    printf("Nhap vao chuoi: ");
    fgets(*str, 1000, stdin);
    (*str)[strcspn(*str, "\n")] = '\0'; 
}
void inChuoi(char *str) {
    printf("Chuoi ban da nhap la: %s\n", str);
}

void Alpa(char *str) {
    int count = 0;
    while (*str) {
        if (isalpha(*str)) {
            count++;
        }
        str++;
    }
    printf("So chu cai co trong chuoi la: %d\n", count);
}

void Number(char *str) {
    int count = 0;
    while (*str) {
        if (isdigit(*str)) {
            count++;
        }
        str++;
    }
    printf("So chu so trong chuoi la: %d\n", count);
}

void Special(char *str) {
    int count = 0;
    while (*str) {
        if (!isalnum(*str) && !isspace(*str)) {
            count++;
        }
        str++;
    }
    printf("So ki tu dac biet trong chuoi la: %d\n", count);
}
int main() {
    char chuoi[1000];
    char *str = chuoi;
    int choice;

    do {
        printf("MENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Ðem so luong chu cai trong chuoi va in ra\n");
        printf("4. Ðem so luong chu so trong chuoi va in ra\n");
        printf("5. Ðem so luong ki tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban la: ") 
        getchar(); 
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                nhapChuoi(&str);
                break;
            case 2:
                inChuoi(str);
                break;
            case 3:
                Alpha(str);
                break;
            case 4:
                Number(str);
                break;
            case 5:
                Special(str);
                break;
            case 6:
                printf("Thoát\n");
                break;
            default:
                printf("Lua chon khong hop li. Chon lai\n");
        }
    } while (choice != 6); 
    return 0;
}
