// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main()
// {
//     int *ptr = (int *)malloc(10 * sizeof(int));
//     if (ptr == NULL)
//     {
//         printf("Memory allocation failed for ptr\n");
//         return 1;
//     }
//     printf("ptr: %p\n", ptr);

//     int *ptr1 = (int *)malloc(10 * sizeof(int));
//     if (ptr1 == NULL)
//     {
//         printf("Memory allocation failed for ptr1\n");
//         free(ptr);
//         return 1;
//     }

//     memcpy(ptr1, ptr, 10 * sizeof(int));
//     printf("ptr1: %p\n", ptr1);

//     free(ptr);
//     free(ptr1);
//     return 0;
// }

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool allocate10Bytes(uint8_t *outPtr);

bool allocate10Bytes(uint8_t *outPtr)
{
    uint8_t *temp = (uint8_t *)malloc(10);
    if (temp == NULL)
    {
        printf("In function - Allocated fail\n");
        return false;
    }

    memcpy(outPtr, &temp, sizeof(temp));

    printf("\n");
    printf("In function outPtr: %p\n", (void *)outPtr);
    printf("In function temp: %p\n", temp);
    printf("In function &temp: %p\n", &temp);
    printf("\n");

    return true;
}

int main()
{
    uint8_t *ptr = NULL;
    printf("In main - Before allocate &ptr: %p\n", (void *)&ptr);
    printf("In main - Before allocate ptr: %p\n", (void *)ptr);

    if (allocate10Bytes((uint8_t *)&ptr))
    {
        printf("In main - After allocate ptr: %p\n", (void *)ptr);
    }
    else
    {
        printf("In main - Allocate Fail\n");
    }

    free(ptr);

    return 0;
}
