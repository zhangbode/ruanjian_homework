#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define NULL 0
#define LEN sizeof(struct Node)
//�ܹ�ʵ���Ƚ���������ʽ��ָ����ͬ����ϲ��������ٽ���������ʽ���мӼ�
//����֧���������룬���һ���ĸ�ʽ����������
typedef struct Node
{
    int zhishu;//�洢ָ��
    int xishu;//�洢ϵ��
    struct Node* next;
}Node, * LinkList;
void printdxs(Node* head)
{
    //����׼�������ʽ
    int j = 0;
    struct Node* p1;
    p1 = head;
    if (head != NULL)
    {
        do
        {
            if (p1 == head && p1->xishu != 0)//˵��ʽ��һ����
            {
                if (p1->zhishu == 0)
                {
                    printf("%d", p1->xishu);
                    j++;
                }
                else
                {
                    printf("%dX^%d", p1->xishu, p1->zhishu);
                    j++;
                }
            }
            else//��������ʽ�ж�ϵ���������
            {
                if (p1->zhishu == 0)
                {
                    if (p1->xishu > 0)
                    {
                        printf("+%d", p1->xishu);
                        j++;
                    }
                    else
                    {
                        if (p1->xishu < 0)
                        {
                            printf("%d", p1->xishu);
                            j++;
                        }
                    }
                }
                else
                {
                    if (p1->xishu > 0)
                    {
                        printf("+%dX^%d", p1->xishu, p1->zhishu);
                        j++;
                    }
                    else
                    {
                        if (p1->xishu < 0)
                        {
                            printf("%dX^%d", p1->xishu, p1->zhishu);
                            j++;
                        }
                    }
                }
            }
            p1 = p1->next;
        } while (p1 != NULL);
    }
    if (j == 0)//��ʽ���
    {
        printf("0");
    }
}
Node* clean(Node* a)
{
    //ͨ��������ʹ��ָͬ��������ϲ�
    struct Node* p1, * p2, * p3;
    //�൱���Ѿ���������Ĳ����������У���ʼ����
    p1 = p2 = p3 = a;//����ָ��ͷ
    p2 = p3->next;//��p2ָ����һ�����
    while (1)//��ָ��û��ָ����������
    {
        while (p1->next != NULL)
        {
            if (p2->zhishu == p3->zhishu)

            {
                p3->xishu = p3->xishu + p2->xishu;
                p1->next = p2->next;//ɾ��p2��ָ�Ľ��
                free(p2);
                p2 = p1->next;
            }
            else
            {
                p1 = p2;
                p2 = p1->next;
            }
        }
        if (p3->next == NULL)
            break;
        p3 = p3->next;//��ѯ��һ���������ͬϵ���ķ�����һ���ڵ�
        p1 = p3;
        p2 = p3->next;//p2��������һ����㹤��
    }
    return a;
};
Node* create(int n)//ʵ��������齨
{
    struct Node* head, * p1, * p2;
    int i = 1;//������
    head = p1 = p2 = (struct Node*)malloc(LEN);
    p2->next = NULL;
    while (i <= n)//��û����ɶ���ʽ��ȫ������ʱ
    {
        if (n == 0)//������ʽΪ����
        {
            printf("error!");
            break;
        }
        p1 = (struct Node*)malloc(LEN);//����һ���¿ռ�
        printf("Please enter the %dth polynomial coefficient:", i);
        scanf_s("%d", &p1->xishu);

        printf("Please enter the %dth polynomial exponent:", i);
        scanf_s("%d", &p1->zhishu);
        i++;
        p2->next = p1;
        p2 = p1;
    }
    p2->next = NULL;
    p1 = head->next;//��p1ָ��head����һ�����
    p1 = clean(p1);
    printdxs(p1);

    return(head);
};
Node* paixu(struct Node* head)
{
    //ʵ�ֽ�������
    struct Node* p1, * p2, * p3;//
    int flag;
    p1 = head->next;
    p2 = p1->next;
    p3 = p1;
    while (p1->next != NULL)//ѡ�����򣬰���ָ��ʵ�ֽ�������
    {
        while (p2 != NULL)
        {
            if (p2->zhishu > p3->zhishu)
                p3 = p2;
            p2 = p2->next;
        }
        //������һ�ֺ��ҵ���ǰ����ָ������ʼ����
        flag = p3->zhishu;
        p3->zhishu = p1->zhishu;
        p1->zhishu = flag;
        flag = p3->xishu;
        p3->xishu = p1->xishu;
        p1->xishu = flag;
        p1 = p1->next;
        p2 = p1->next;
        p3 = p1;
    }
    return head;
}
Node* jiajian(Node* a, Node* b, int m, int d)//
{
    //ʵ�ּӼ���
    Node* a1, * b1, * b2;
    b1 = b;
    b2 = b->next;
    a1 = a->next;
    if (d == 2)//Ϊ�ڶ�������ʽϵ����ֵΪ�����ﵽ�����Ĺ���
    {
        while (b2 != NULL)
        {
            b2->xishu = -b2->xishu;
            b2 = b2->next;
        }
        b2 = b->next;
    }
    while (a1 != NULL)
    {
        while (b2 != NULL)
        {
            if (b2->zhishu == a1->zhishu)//ָ�����
            {
                a1->xishu = a1->xishu + b2->xishu;//֮�󽫵ڶ��������еĸýڵ�ɾ��
                b1->next = b2->next;
                free(b2);
                b2 = b1->next;
            }
            else
            {
                b1 = b2;
                b2 = b2->next;//������
            }
        }
        a1 = a1->next;
        b1 = b;
        b2 = b->next;
    }
    //���������һ������Ľ��󣬲鿴�ڶ����������Ƿ���ʣ��Ľ�㣬��ʣ������뵽A������
    b1 = b->next;//��ָ��ָ��ͷ��
    while (b1 != NULL)//������Ϊ��
    {
        b2 = b1->next;
        b1->next = a->next;
        a->next = b1;
        b1 = b2;
    }
    printf("The calculation result is:\n");
    printdxs(a->next);
    a = paixu(a);
    printf("\nThe sorted results are:\n");
    printdxs(a->next);
    return a;
};
void txt(Node* head)
{

    int j = 0;
    struct Node* p1;
    p1 = head->next;
    head = head->next;
    FILE* fp;
    fopen_s(&fp,"polynomial.txt", "a");
    if (head != NULL)
    {
        do
        {
            if (p1 == head && p1->xishu != 0)//˵��ʽ��һ����
            {
                if (p1->zhishu == 0)
                {
                    fprintf(fp, "%d", p1->xishu);
                    j++;
                }
                else
                {
                    fprintf(fp, "%dX^%d", p1->xishu, p1->zhishu);
                    j++;
                }
            }
            else
            {
                if (p1->zhishu == 0)
                {
                    if (p1->xishu > 0)
                    {
                        fprintf(fp, "+%d", p1->xishu);
                        j++;
                    }
                    else
                    {
                        if (p1->xishu < 0)
                        {
                            fprintf(fp, "%d", p1->xishu);
                            j++;
                        }
                    }
                }
                else
                {
                    if (p1->xishu > 0)
                    {
                        fprintf(fp, "+%dX^%d", p1->xishu, p1->zhishu);
                        j++;
                    }
                    else
                    {
                        if (p1->xishu < 0)
                        {
                            fprintf(fp, "%dX^%d", p1->xishu, p1->zhishu);
                            j++;
                        }
                    }
                }
            }
            p1 = p1->next;
        } while (p1 != NULL);
    }
    if (j == 0)//��ʽ���
    {
        fprintf(fp, "0");
    }
    fprintf(fp, "\n");
    fclose(fp);
}
int main()
{
    
    int m, n, i;//��ʼ�������������
    printf("To clear the original data in the file, please enter: (1 for YES, 2 for NO)\n");
    scanf_s("%d", &i);
    if (i == 1)
    {
        FILE* fp;
        fopen_s(&fp, "polynomial.txt", "w");
        fclose(fp);
    }
    printf("Please enter how many terms the first polynomial consists of:\n");
    scanf_s("%d", &m);
    printf("Please enter how many terms the second polynomial consists of:\n");
    scanf_s("%d", &n);
    Node* a, * b, * c;//������������ʽ����
    printf("Please enter the information of the first polynomial:\n");
    a = (Node*)create(m);
    txt(a);
    printf("\nPlease enter the information of the second polynomial:\n");
    b = (Node*)create(n);
    txt(b);
    int d;
    printf("\nPlease enter the operation you want to perform: (1 for addition, 2 for subtraction)\n");
    scanf_s("%d", &d);
    c = (Node*)jiajian(a, b, n, d);
    txt(c);
    printf("\nIf you want to know the contents of the existing file, please enter:(1 for YES,0 for NO)\n");
    scanf_s("%d", &i);
    if (i == 1)
    {
        FILE* fp;
        fopen_s(&fp,"polynomial.txt", "w");
        fclose(fp);
    }
    return 0;
}