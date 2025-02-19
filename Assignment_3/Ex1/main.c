#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *Address;
    int Size;
    int Capacity;
} Array;

void InitArray(Array *arr);
void AddElement(Array *arr, int num);
void DelElement(Array *arr, int num);
void Sort(Array *arr);
int Search(Array *arr, int num);

void Print(Array *arr);
void FreeArray(Array *arr);
void ClearScreen();
void Pause();
int InputPositiveInt();

void InitArray(Array *arr)
{
    int capacity;
    printf("Nhập số lượng phần tử ban đầu: ");
    capacity = InputPositiveInt();

    if (arr->Address != NULL)
    {
        FreeArray(arr);
    }

    arr->Address = (int *)malloc(sizeof(int) * capacity);
    if (arr->Address == NULL)
    {
        printf("Lỗi cấp phát bộ nhớ!\n");
        return;
    }

    arr->Capacity = capacity;
    arr->Size = capacity;

    printf("Nhập giá trị cho %d phần tử:\n", capacity);
    for (int i = 0; i < capacity; i++)
    {
        printf("Phần tử [%d]: ", i);
        arr->Address[i] = InputPositiveInt();
    }

    printf("Đã khởi tạo mảng thành công!\n");
    Print(arr);
}

void AddElement(Array *arr, int num)
{
    if (arr->Size == arr->Capacity)
    {
        arr->Capacity *= 2;
        arr->Address = (int *)realloc(arr->Address, arr->Capacity * sizeof(int));
        if (arr->Address == NULL)
        {
            printf("Lỗi cấp phát bộ nhớ khi mở rộng mảng!\n");
            return;
        }
    }
    arr->Address[arr->Size++] = num;
}

void DelElement(Array *arr, int num)
{
    int index = Search(arr, num);
    if (index == -1)
    {
        printf("%d không tồn tại trong mảng. Không thể thực hiện xóa!\n", num);
        return;
    }
    for (int i = index; i < arr->Size - 1; i++)
    {
        arr->Address[i] = arr->Address[i + 1];
    }
    arr->Size--;
}

void Sort(Array *arr)
{
    for (int i = 0; i < arr->Size - 1; i++)
    {
        for (int j = i + 1; j < arr->Size; j++)
        {
            if (arr->Address[i] > arr->Address[j])
            {
                int temp = arr->Address[i];
                arr->Address[i] = arr->Address[j];
                arr->Address[j] = temp;
            }
        }
    }
}

int Search(Array *arr, int num)
{
    for (int i = 0; i < arr->Size; i++)
    {
        if (arr->Address[i] == num)
        {
            return i;
        }
    }
    return -1;
}

void Print(Array *arr)
{
    if (arr->Size == 0)
    {
        printf("Mảng trống.\n");
        return;
    }
    printf("Mảng hiện tại: ");
    for (int i = 0; i < arr->Size; i++)
    {
        printf("%d ", arr->Address[i]);
    }
    printf("\n");
}

void FreeArray(Array *arr)
{
    free(arr->Address);
    arr->Address = NULL;
    arr->Size = 0;
    arr->Capacity = 0;
}

void ClearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Pause()
{
    printf("\nNhấn Enter để tiếp tục...");
    getchar();
}

int InputPositiveInt()
{
    int num;
    char c;

    while (1)
    {
        if (scanf("%d", &num) != 1)
        {
            printf("Lỗi: Bạn phải nhập một số nguyên!\n");
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            continue;
        }

        if (num < 0)
        {
            printf("Lỗi: Số phải lớn hơn hoặc bằng 0!\n");
            continue;
        }

        while ((c = getchar()) != '\n' && c != EOF)
            ;

        return num;
    }
}

int main()
{
    Array arr = {NULL, 0, 0};
    int choice, num;

    while (1)
    {
        ClearScreen();
        printf("\n===== QUẢN LÝ MẢNG =====\n");
        printf("1. Khởi tạo mảng\n");
        printf("2. Thêm phần tử\n");
        printf("3. Xóa phần tử\n");
        printf("4. Tìm kiếm phần tử\n");
        printf("5. Sắp xếp mảng\n");
        printf("6. Hiển thị mảng\n");
        printf("7. Thoát\n");
        printf("========================\n");
        printf("Nhập lựa chọn: ");

        while (scanf("%d", &choice) != 1 || getchar() != '\n')
        {
            printf("Lỗi: Bạn phải nhập một số nguyên hợp lệ!\n");
            while (getchar() != '\n')
                ; // Xóa bộ đệm
            printf("Nhập lại lựa chọn: ");
        }

        switch (choice)
        {
        case 1:
            InitArray(&arr);
            Pause();
            break;

        case 2:
            if (arr.Address == NULL)
            {
                printf("Mảng chưa được khởi tạo! Hãy chọn '1' để khởi tạo mảng.\n");
                Pause();
                break;
            }
            printf("Nhập số cần thêm: ");
            num = InputPositiveInt();
            AddElement(&arr, num);
            printf("%d đã được thêm vào mảng.\n", num);
            Pause();
            break;

        case 3:
            if (arr.Address == NULL)
            {
                printf("Mảng chưa được khởi tạo!\n");
                Pause();
                break;
            }
            Print(&arr);
            printf("Nhập số cần xóa: ");
            num = InputPositiveInt();
            DelElement(&arr, num);
            Pause();
            break;

        case 4:
            if (arr.Address == NULL)
            {
                printf("Mảng chưa được khởi tạo!\n");
                Pause();
                break;
            }
            printf("Nhập số cần tìm: ");
            num = InputPositiveInt();
            int index = Search(&arr, num);
            if (index != -1)
            {
                printf("%d được tìm thấy tại vị trí %d.\n", num, index);
            }
            else
            {
                printf("%d không có trong mảng.\n", num);
            }
            Pause();
            break;

        case 5:
            if (arr.Address == NULL)
            {
                printf("Mảng chưa được khởi tạo!\n");
                Pause();
                break;
            }
            Sort(&arr);
            printf("Mảng đã được sắp xếp.\n");
            Pause();
            break;

        case 6:
            if (arr.Address == NULL)
            {
                printf("Mảng chưa được khởi tạo!\n");
                Pause();
                break;
            }
            Print(&arr);
            Pause();
            break;

        case 7:
            FreeArray(&arr);
            printf("Thoát chương trình.\n");
            return 0;

        default:
            printf(" Lựa chọn không hợp lệ! Vui lòng nhập lại.\n");
            Pause();
        }
    }
}
