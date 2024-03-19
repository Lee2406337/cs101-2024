#include <stdio.h>

typedef struct Books {
    int id;
    int price;
    char title[100];
} book_t;

void total_price(book_t books[], int num_books);
void list_books(book_t books[], int num_books, int id);

int main() {
    book_t books[] = {
        {1, 1000, "All the Light We Cannot See"},
        {2, 300, "The 38 Letters from J.D. Rockefeller to his son"},
        {3, 1000, "The Ballad of Songbirds and Snakes"},
        {4, 550, "Killers of the Flower Moon"},
        {5, 870, "Elon Musk"},
        {6, 1344, "Milk and Honey 12-Month 2024"}
    };
    int num_books = sizeof(books) / sizeof(books[0]);

    int N;
    scanf("%d", &N);

    if (N == 0) {
        total_price(books, num_books);
    } else if (N >= 1 && N <= 6) {
        list_books(books, num_books, N);
    } else {
        printf("無效的輸入。\n");
    }

    return 0;
}

void total_price(book_t books[], int num_books) {
    int total = 0;
    for (int i = 0; i < num_books; ++i) {
        total += books[i].price;
    }
    printf("%d", total);
}

void list_books(book_t books[], int num_books, int id) {
    for (int i = 0; i < num_books; ++i) {
        if (books[i].id == id) {
            printf("%d ", books[i].price);
            printf("%s", books[i].title);
            return;
        }
    }
}
