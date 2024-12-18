#include <stdio.h>
#include <stdlib.h>

void nhapMang(int **arr, int *n) {
    printf("Nhap so luong phan tu: ");
    scanf("%d", n);
    *arr = (int *)malloc(*n * sizeof(int));
    if (*arr == NULL) {
        printf("Khong the cap phat bo nho\n");
        exit(1); 
    }
    printf("Nhap cac phan tu trong mang:\n");
    for (int i = 0; i < *n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &(*arr)[i]);
    }
}
void hienThiMang(int *arr, int n) {
    printf("Cac phan tu trong mang:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void length(int n) {
    printf("Do dai mang la: %d\n", n);
}

void sum(int *arr, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += arr[i];
    }
    printf("Tong cac phan tu trong mang la: %d\n", tong);
}

void maxNumber(int *arr, int n) {
    if (n == 0) {
        printf("Mang rong\n");
        return;
    }
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Phan tu lon nhat la: %d\n", max);
}
int main() {
    int *arr = NULL;
    int n = 0, choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                nhapMang(&arr, &n);
                break;
            case 2:
                hienThiMang(arr, n);
                break;
            case 3:
                length(n);
                break;
            case 4:
                sum(arr, n);
                break;
            case 5:
                maxNumber(arr, n);
                break;
            case 6:
                if (arr != NULL) {
                    free(arr);
                }
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le, chon lai.\n");
        }
    } while (choice != 6);

    return 0;
}
