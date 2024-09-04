#include <cstdio>
#include <cstdint>
#include <climits>
#include <ctime>
#include <cstdlib>


int main() {

    uint32_t arr[20];
    //srand(time(NULL));
    for (size_t i = 0; i < sizeof(arr) / sizeof(uint32_t); ++i) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    return 0;
}