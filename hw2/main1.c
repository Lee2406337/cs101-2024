#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int unique_random(int min, int max, int* used, int count) {
    int num;
    do {
        num = rand() % (max - min + 1) + min;
        int unique = 1;
        for (int i = 0; i < count; i++) {
            if (num == used[i]) {
                unique = 0;
                break;
            }
        }
        if (unique) {
            used[count] = num;
            return num;
        }
    } while (1);
}

void fill_remaining(int remaining, FILE *file, int* used, int start) {
    for (int i = start; i < start + remaining; i++) {
        fprintf(file, "[%d]: ", i);
        for (int j = 0; j < 7; j++) {
            fprintf(file, "-- ");
        }
        fprintf(file, "\n");
    }
}

int main() {
    int num;
    printf("歡迎光臨長庚樂透彩購買機台\n請問您要買幾組樂透彩:");
    scanf("%d", &num);
    printf("以為您購買的%d組樂透組合輸出至 lotto.txt\n", num);

    FILE *file = fopen("lotto.txt", "w");
    if (file == NULL) {
        printf("無法打開文件");
        return 1;
    }

    time_t curr_time;
    curr_time = time(NULL);

    char* time_str = ctime(&curr_time);
    time_str[24] = '\0';

    fprintf(file, "======== lotto649 =========\n=%s=\n", time_str);

    srand(time(NULL));

    int used_nums[7];

    int i;
    int ticket_count = 0;
    for (i = 0; i < num; i++) {
        ticket_count++;
        fprintf(file, "[%d]: ", ticket_count);
        for (int j = 0; j < 7; j++) {
            int random_num = unique_random(1, 69, used_nums, j);
            fprintf(file, "%02d ", random_num);
        }
        fprintf(file, "\n");
    }

    int remaining_tickets = 5 - ticket_count;
    if (remaining_tickets > 0) {
        fill_remaining(remaining_tickets, file, used_nums, ticket_count + 1);
    }

    fprintf(file, "======== csie@CGU =========\n");

    fclose(file);

    return 0;
}
