#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _m malloc
struct Product {
    char name[11];
    int quantity;
    char size[4];
    float price;
};

//a
// ham chon size
void choose_size(char* size) {
    printf("Chon size: \n");
    printf("1. S\n");
    printf("2. M\n");
    printf("3. L\n");
    printf("4. XL\n");
    printf("5. 2XL\n");

    int choice;
    do {
        printf("Nhap vao lua chon cua ban (1-5): ");
        scanf("%d", &choice);
        getchar(); // doc newline

        switch (choice) {
        case 1: strcpy(size, "S"); break;
        case 2: strcpy(size, "M"); break;
        case 3: strcpy(size, "L"); break;
        case 4: strcpy(size, "XL"); break;
        case 5: strcpy(size, "2XL"); break;
        default: printf("Lua chon khong hop le!\n"); continue;
        }
        break;
    } while (1);
}

int input_products(struct Product* products, int n) {
    int i, len;
    len = strlen(products[i].name);
    for (i = 0; i < n; i++) {
        printf("Nhap thong tin san pham thu %d:\n", i + 1);

        printf("Nhap ten san pham (toi da 10 ky tu): ");
        // fgets(products[i].name, 11, stdin);
        fflush(stdin); gets(products[i].name);
        // if (products[i].name[len - 1] == '\n') {
        //     products[i].name[len - 1] = '\0';
        // }

        do {
            printf("Nhap so luong (so nguyen duong): ");
            scanf("%d", &products[i].quantity);
            getchar();
            if (products[i].quantity <= 0) {
                printf("So luong phai la so nguyen duong!\n");
            }
            else {
                break;
            }
        } while (1);

        choose_size(products[i].size);

        do {
            printf("Nhap gia ban (so thuc): ");
            scanf("%f", &products[i].price);
            getchar();
            if (products[i].price <= 0) {
                printf("Gia ban phai la so thuc duong!\n");
            }
            else {
                break;
            }
        } while (1);
    }
    return n;
}
char* GeLi(int* x, int l) {
    int i, k, j, _l = 100;
    char* _x = _m(_l);
    // x = [1,24,5,63]
    for (i = j = 0; i < l;i++) {
        int a = abs(x[i]) + 2;
        _x[j++] = '+';
        for (k = 0; k < a;k++) _x[j++] = '-';
        if (strlen(_x) + x[i + 1] < _l || i >= l) continue;
        _l *= 2;
        _x = realloc(_x, _l);
    }
    _x[j++] = '+'; _x[j++] = '\0';
    return realloc(_x, j);
}
//b
void print_products(struct Product* products, int n) {
    int _i[] = { -11,-7,-4,-8 };
    char* x = GeLi(_i, 4);
    printf("| %-11s | %-7s | %-4s | %-8s |\n", "Ten san pham", "So luong", "Size", "Gia ban");
    printf("%s\n", x);
    int i;
    for (i = 0; i < n; i++) {
        printf("| %-11s | %7d | %-4s | %8.2f |\n",
            products[i].name, products[i].quantity, products[i].size, products[i].price);
    }
}

//c
float sort_products(struct Product* products, int n) {
    // sap xep theo thu tu giam dan cua so luong ton kho 
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (products[i].quantity < products[j].quantity) {
                struct Product tmp = products[i];
                products[i] = products[j];
                products[j] = tmp;
            }
        }
    }
    // tinh tong luong tien cua cac san pham ton kho
    float total_value = 0;
    for (i = 0; i < n; i++) {
        if (products[i].quantity > 0) {
            total_value += products[i].quantity * products[i].price;
        }
    }
    return total_value;
}

//d
void search_products(struct Product* products, int n, char* size, float g1, float g2) {
    int x[] = { -11,-7,-4,-8 };
    char* _x = GeLi(x, 4);
    printf("| %*s | %*s | %*s | %*s |\n", x[0], "Ten san pham", x[1], "So luong", x[2], "Size", x[3], "Gia ban");
    printf("%s\n", _x);

    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(products[i].size, size) == 0 && products[i].price >= g1 && products[i].price <= g2) {
            printf("| %-11s | %7d | %-4s | %8.2f |\n",
                products[i].name, products[i].quantity, products[i].size, products[i].price);
        }
    }
}

//e
int main() {
    int n;
    do {
        printf("Nhap so luong san pham (so nguyen duong): ");
        scanf("%d", &n);
        getchar();
        if (n <= 0) {
            printf("So luong san pham phai la so nguyen duong!\n");
        }
        else {
            break;
        }
    } while (1);

    // nhap thong tin cac san pham
    struct Product* products = (struct Product*)malloc(n * sizeof(struct Product));
    printf("\n");
    input_products(products, n);

    // in danh sach cac san pham vua nhap
    printf("\nDanh sach san pham:\n");
    print_products(products, n);

    // // sap xep + tinh tong tien
    // printf("\nDanh sach san pham sau khi sap xep theo so luong ton kho giam dan:\n");
    // float total_value = sort_products(products, n);
    // printf("Tong gia tri cua cac san pham ton kho: %.2f\n", total_value);

    // // tim kiem v� in danh sach san pham theo yeu cau
    // char size[4];
    // choose_size(size);
    // float g1, g2;
    // do {
    //     printf("Nhap gia tu G1 den G2 (G1 < G2): ");
    //     scanf("%f%f", &g1, &g2);
    //     getchar();
    //     if (g1 >= g2) {
    //         printf("Gia G1 phai nho hon G2!\n");
    //     }
    //     else {
    //         break;
    //     }
    // } while (1);

    // printf("\nDanh sach san pham co size %s va gia trong khoang tu %.2f den %.2f:\n", size, g1, g2);
    // search_products(products, n, size, g1, g2);
    // free(products); // giai phong bo nho da cap phat
    return 0;
}
