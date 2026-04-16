// 设计一个进制转换程序，使用顺序栈设计一个把十进制数转换为十六进制数的接口，
// 实现当通过键盘输入一个非负的十进制数，可以在终端输出对应的十六进制数。

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100
typedef int DataType;
typedef struct dec2hex // 对栈设计结构体
{
    int top;                  // 栈最后一个元素的下标
    DataType buttom[MAXSIZE]; // 栈
} DH;

void InitStack(DH *p)
{
    // 初始化顺序栈
    p->top = -1;
}

// 出栈
int Stack_Pop(DH *stack)
{
    if (stack->top == -1)
        return 0;
    DataType p = (stack->buttom)[(stack->top)--];
    return p;
}

// 入栈
int Stack_Push(DH *stack, DataType data)
{
    if (stack->top == MAXSIZE - 1)
        return 0;

    (stack->buttom)[++(stack->top)] = data;
    return 1;
}

// 十进制转十六进制
void Stack_dec2hex(DH *stack, int dec)
{
    int remian; // 余数
    InitStack(stack);
    // 入栈
    while (dec > 0)
    {

        if (dec % 16 < 10)
        {
            remian = (dec % 16) + '0';
            if (!Stack_Push(stack, remian))
                printf("栈已经满了");
            dec = dec / 16;
        }
        else
        {
            remian = (dec % 16) + 'A' - 10;
            if (!Stack_Push(stack, remian))
                printf("栈已经满了");
            dec = dec / 16;
        }
    }

    // 出栈
    printf("0x");
    while (stack->top != -1)
    {
        DataType p = Stack_Pop(stack);
        printf("%c", p);
    }
    printf("\n");
}

int main()
{
    DH *stack = (DH *)calloc(1, sizeof(DH));
    int dec;
    printf("请输入十进制数：");
    scanf("%d", &dec);

    Stack_dec2hex(stack, dec);
    return 0;
}