#include <cstdio>
#include <cstdint>
#include <climits>
#include <ctime>
#include <cstdlib>

int main() {

    uint32_t arr[10][10];
    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            arr[i][j] = rand() % 250;
            printf("%u\t", arr[i][j]);

        }
        printf("\n");
    }
    printf("\n\n\n");


    uint32_t row_sum[10] = { 0 };
    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j)
            row_sum[i] += arr[i][j];
    }

    for (size_t i = 0; i < 10; ++i) {
        printf("%d\n", row_sum[i]);
    }


    return 0;
}