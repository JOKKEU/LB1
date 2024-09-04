#include <cstdio>
#include <cstdint>
#include <climits>

int main() {

    uint32_t arr[] = { 1,2,3,4,5,6,7,8,9,10,213,12355,6,21 };
#define UINT32_MIN 0
    uint32_t max = UINT32_MIN;
#undef UINT32_MIN
    uint32_t min = UINT32_MAX;

    for (size_t i = 0; i < sizeof(arr) / 4; ++i) {
        if (min > arr[i]) { min = arr[i]; }
        if (max < arr[i]) { max = arr[i]; }
    }

    printf("%d\n", max);
    printf("%d\n", min);

    return 0;
}

