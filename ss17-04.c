#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    if (n <= 1) {
    	return 0; 
	}  
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
        	return 0; 
		}  
    }
    return 1;  
}
void reverse(int *arr, int n) {
    int temp;
    for (int i = 0; i < n / 2; i++) {
        temp = *(arr + i);
        *(arr + i) = *(arr + n - i - 1);
        *(arr + n - i - 1) = temp;
    }
}
void sortUp(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(arr + i) > *(arr + j)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}
void sortDown(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(arr + i) < *(arr + j)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}
int found(int *arr, int n, int value) {
    for (int i = 0; i < n; i++) {
        if (*(arr + i) == value) {
            return i;  
        }
    }
    return -1; 
}
int main() {
    int n, choice;
    int *arr;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("   1. Tang dan\n");
        printf("   2. Giam dan\n");
        printf("6. Nhap vao mot phan tu va tim kiem phan tu trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban la: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Nhap so phan tu: ");
                scanf("%d", &n);
                arr = (int*)malloc(n * sizeof(int));

                printf("Nhap cac phan tu:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                break;
            case 2:
                printf("Cac phan tu la so chan: ");
                for (int i = 0; i < n; i++) {
                    if (*(arr + i) % 2 == 0) {
                        printf("%d ", *(arr + i));
                    }
                }
                printf("\n");
                break;
            case 3:
                printf("Cac phan tu la so nguyen to: ");
                for (int i = 0; i < n; i++) {
                    if (isPrime(*(arr + i))) {
                        printf("%d ", *(arr + i));
                    }
                }
                printf("\n");
                break;
            case 4:
                reverse(arr, n);
                printf("Mang sau khi dao nguoc: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", *(arr + i));
                }
                printf("\n");
                break;
            case 5:
                printf("1. Tang dan\n2. Giam dan\n");
                int sortChoice;
                printf("Nhap lua chon sap xep: ");
                scanf("%d", &sortChoice);
                if (sortChoice == 1) {
                    sortUp(arr, n);
                    printf("Mang sau khi sap xep tang dan: ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", *(arr + i));
                    }
                    printf("\n");
                } else if (sortChoice == 2) {
                    sortDown(arr, n);
                    printf("Mang sau khi sap xep giam dan: ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", *(arr + i));
                    }
                    printf("\n");
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            case 6:
                {
                    int found;
                    printf("Nhap phan tu can tim: ");
                    scanf("%d", &found);
                    int index = searchElement(arr, n, found);
                    if (index != -1) {
                        printf("Phan tu %d duoc tim thay tai vi tri %d.\n", found, index);
                    } else {
                        printf("Phan tu %d khong ton tai trong mang.\n", found);
                    }
                }
                break;
            case 7:
                printf("Thoat\n");
                free(arr);  
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 7);

    return 0;
}
