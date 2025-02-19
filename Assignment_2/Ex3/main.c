#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void absoluteValue(uint8_t *data)
{
    data[0] = (data[0] > data[1]) ? (data[0] - data[1]) : (data[1] - data[0]);
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Vui lòng nhập đúng 2 số dương 8 bits!\n");
        return 1;
    }

    uint8_t a = (uint8_t)atoi(argv[1]);
    uint8_t b = (uint8_t)atoi(argv[2]);
    if (a > 255 || b > 255)
    {
        printf("Các số nhập phải nằm trong phạm vi từ 0 đến 255.\n");
        return 1;
    }

    uint8_t *data;
    data[0] = a;
    data[1] = b;

    absoluteValue(data);
    printf("Giá trị tuyệt đối của hiệu 2 số %d và %d: %d\n", a, b, data[0]);

    return 0;
}