#include <stdio.h>

typedef struct {
    char id[100];
    char title[100];
    float price;
} book_t;

void total_price(book_t books[], int num_books);

void list_books(book_t books[], int num_books);

int main() {
    book_t books[6] = {
        {"1", "All the Light We Cannot See", 1000},
        {"2", "The 38 Letters from J.D. Rockefeller to his son", 300},
        {"3", "The Ballad of Songbirds and Snakes", 1000},
        {"4", "Killers of the Flower Moon", 520},
        {"5", "Elon Musk", 870},
        {"6", "Milk and Honey 12-Month 2024", 1344}
    };

    total_price(books, 6);

    list_books(books, 6);

    return 0;
}

void total_price(book_t books[], int num_books) {
    float total = 0;
    for (int i = 0; i < num_books; ++i) {
        total += books[i].price;
    }
    printf("總共價錢: %.2f\n", total);
}

void list_books(book_t books[], int num_books) {
    printf("id\tprice\ttitle \n");
    for (int i = 0; i < num_books; ++i) {
        printf("%s\t%.2f\t%s\n", books[i].id, books[i].price, books[i].title);
    }
}
