#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <climits>

int main() {

    uint32_t size;
    scanf("%d", &size);
    uint32_t* ptr_arr = (uint32_t*)malloc(size * sizeof(uint32_t));

    for (size_t i = 0; i < size; ++i) {
        scanf("%d", &ptr_arr[i]);
    }

    printf("\n\n\n");
    for (size_t i = 0; i < size; ++i) {
        printf("%d\n", ptr_arr[i]);
    }

    free(ptr_arr);

    return 0;
}