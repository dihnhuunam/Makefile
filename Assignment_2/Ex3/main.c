#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void absoluteValue(uint8_t *data)
{
    data[0] = (data[0] > data[1]) ? (data[0] - data[1]) : (data[1] - data[0]);
}

int main()
{

    int a, b;
    while (1)
    {
        printf("Nhập vào 2 số (0 - 255): ");
        int check = scanf("%d %d", &a, &b);

        if (check != 2 || a > 255 || b > 255 || a < 0 || b < 0)
        {
            printf("Các số nhập phải nằm trong phạm vi từ 0 đến 255.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        break;
    }

    uint8_t data[2];
    data[0] = (uint8_t)a;
    data[1] = (uint8_t)b;
    absoluteValue(data);
    printf("Giá trị tuyệt đối của hiệu 2 số %d và %d: %d\n", a, b, data[0]);

    return 0;
}