#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>


int product_display(void);
int item_display(void);
int select_menu_item(void);
void hat(void);
void clothes(void);
void pants(void);
void shoes(void);
void save_file_hat(int i, int c);
void save_file_clothes(int i, int c);
void save_file_pants(int i, int c);
void save_file_shoes(int i, int c);
void load_file_hat(void);
void load_file_clothes(void);
void load_file_shoes(void);
void load_file_pants(void);
void plus_product_hat(void);
void plus_product_clothes(void);
void plus_product_pants(void);
void plus_product_shoes(void);
int select_box(void);
void see_box(int c);
int select_num(int c);
void del_hat(void);
void del_clothes(void);
void del_pants(void);
void del_shoes(void);
int del_box(void);
void add_hat(void);
void add_clothes(void);
void add_pants(void);
void add_shoes(void);
int add_box(void);
void minus_hat(void);
void minus_clothes(void);
void minus_pants(void);
void minus_shoes(void);
int minus_box(void);
void title1();

struct item                                //��ǰ ������ �Է��ϴ� ����ü
{
    char name[31];                          // ��ǰ �̸�
    char color[31];                          // ��ǰ ��
    char size[31];                             // ��ǰ ������
    int amount;                                 // ��ǰ ����
};
struct item p[100] = { 0 };

void jaeg()

{
    system("mode con cols=140 lines=40");

    for (int i = 0; i < 100; i++)
        strcpy(p[i].name, "-");
    int p = 0;
    while ((p = product_display()) != 5)
		{
        switch (p) {
        case 1: load_file_hat(); hat();
            break;
        case 2: load_file_clothes(); clothes();
            break;
        case 3: load_file_pants(); pants();
            break;
        case 4: load_file_shoes(); shoes();
        default:break;
            //      case 5: back();
            //         break;
            //      default: break;
        }
    }
    return;
}

int product_display(void)               // ǰ�� ���� ��Ÿ���� ����Ʈ
{
    int select;
    system("cls");
    printf("\n������������������������������������������������������  ǰ�� ���� ��������������������������������������������������������������\n");
    printf("��                        [1]�� ǰ1 (�� ��)                           ��\n");
    printf("��                        [2]�� ǰ2 ( �� )                            ��\n");
    printf("��                        [3]�� ǰ3 (�� ��)                           ��\n");
    printf("��                        [4]�� ǰ4 (�� ��)                           ��\n");
    printf("��                        [5]�� �� ��                                 ��\n");
    printf("��������������������������������������������������������������������������������������������������������������������������������������������\n");
    select = _getch() - 48;
    return select;
}

int item_display(void)      //ǰ�� ���п��� ��ȣ �����ϸ� ��Ÿ���� ǥ, ��� ���� ����Ʈ
{
    int j, i, g = 0;
    int red = 4;
    int white = 7;
    system("cls");                  // â �ʱ�ȭ�� ��ǰ������ ��Ÿ���� ǥ ���

    printf("����������������������������  1 ����������������������������������������������������������  6 ��������������������������������������������������������  11 ����������������������������������������������������������  16 ����������������������������\n");

    for (i = 0; i < 5; i++) {
        for (j = i + 1; j < 21; j += 5) {
            printf("��  ��ǰ�� : %-20s��", p[j - 1].name);
        }
        printf("\n");
        for (j = i + 1; j < 21; j += 5) {
            printf("��   �� �� : %-20s��", p[j - 1].color);
        }
        printf("\n");
        for (j = i + 1; j < 21; j += 5) {
            printf("��  ������ : %-20s��", p[j - 1].size);
        }
        printf("\n");
        for (j = i + 1; j < 21; j += 5) {
            if (p[j - 1].amount < 6) {          // ���� 5�� �����϶� ���� ���� ����
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), red);
                printf("��   �� �� : %-20d��", p[j - 1].amount);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
            }
            else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
                printf("��   �� �� : %-20d��", p[j - 1].amount);
            }
        }
        printf("\n");
        if (i == 0)
            printf("������������������������������ 2 ����������������������������������������������������������  7 ��������������������������������������������������������  12 ����������������������������������������������������������  17 ����������������������������\n");
        else if (i == 1)
            printf("������������������������������ 3 ����������������������������������������������������������  8 ��������������������������������������������������������  13 ����������������������������������������������������������  18 ����������������������������\n");
        else if (i == 2)
            printf("������������������������������ 4 ����������������������������������������������������������  9 ��������������������������������������������������������  14 ����������������������������������������������������������  19 ����������������������������\n");
        else if (i == 3)
            printf("������������������������������ 5 ����������������������������������������������������������  10 ��������������������������������������������������������  15 ��������������������������������������������������������  20 ����������������������������\n");

        else if (i == 4)
            printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

    }
    printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
    return 0;

}

void title1() //Ÿ��Ʋ �Լ� title ����
{
   printf("\n\n\n\n\n");
   printf("                         ���       ���          ���         ��         ��          ���         ���������     �������        \n");
   printf("                         ���      �� ��         ��  ��        ���       ��         ��  ��        ��                   ��                  \n");
   printf("                         �� ��    ��  ��        ��    ��       �� ��      ��        ��    ��       ��                   ��                  \n");
   printf("                         ��  ��  ��   ��       ��      ��      ��  ��     ��       ��      ��      ��       ������  ��                  \n");
   printf("                         ��   ���    ��      ��        ��     ��   ��    ��      ��        ��     ��               ��  �������        \n");
   printf("                         ��    ��     ��     ��������    ��    ��   ��     ��������    ��               ��  ��                  \n");
   printf("                         ��           ��    ��            ��   ��     ��  ��    ��            ��   ��������   ��  ��                  \n");
   printf("                         ��           ��   ��              ��  ��      �� ��   ��              ��                   ��  ��                  \n");
   printf("                         ��           ��  ��                �� ��       ���  ��                ��                  ��  �������        \n");
   
}

int select_menu_item(void)      // ������� ��� ����Ʈ
{
    system("cls");
    int select = 0;
    item_display();
    printf("\n");
    printf("\n������������������������������������������������������  <���Ͻô� �޴� ��ȣ�� �����ÿ�> ��������������������������������������������������������������\n");
    printf("��                                   1.��ǰ ���� �߰�                                       ��\n");
    printf("��                                   2.��ǰ ���� ����                                       ��\n");
    printf("��                                   3.��ǰ �԰�                                            ��\n");
    printf("��                                   4.��ǰ ���                                            ��\n");
    printf("��                                   0.������                                               ��\n");
    printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    select = _getch() - 48;
    return select;
}

void hat(void)                  // ù��° ǰ�� ���� �Լ�
{
    int p;
    system("cls");
    while ((p = select_menu_item()) != 0)
    {
        switch (p)
        {
        case 1: plus_product_hat();         // 1���� �������� ��ǰ �߰� ��� ȣ��
            break;
        case 2: del_hat();                  // 2���� �������� ��ǰ ���� ��� ȣ��
            break;
        case 3:  add_hat();                 // 3���� �������� �԰� ��� ȣ��
            break;
        case 4: minus_hat();                // 4���� �������� ��� ��� ȣ��
            break;
        default: break;
        }
    }
}

void clothes(void)              // �ι�° ǰ�� ���� �Լ�
{
    int p;
    system("cls");

    while ((p = select_menu_item()) != 0)
    {
        switch (p)
        {
        case 1:plus_product_clothes();
            break;
        case 2: del_clothes();
            break;
        case 3: add_clothes();  
            break;
        case 4:  minus_clothes(); 
            break;
        default: break;
        }
    }
}

void pants(void)                        // ����° ǰ�� ���� �Լ�
{
    int p;
    system("cls");

    while ((p = select_menu_item()) != 0)
    {
        switch (p)
        {
        case 1: plus_product_pants();
            break;
        case 2: del_pants();
            break;
        case 3: add_pants();
            break;
        case 4: minus_pants();
            break;
        default: break;
        }
    }
}

void shoes(void)                    // �׹�° ǰ�� ���� �Լ�
{
    int p;
    system("cls");

    while ((p = select_menu_item()) != 0)
    {
        switch (p)
        {
        case 1: plus_product_shoes();
            break;
        case 2:  del_shoes();
            break;
        case 3: add_shoes();
            break;
        case 4: minus_shoes();
            break;
        default: break;
        }
    }
}



void plus_product_hat(void)     //��ǰ �߰� �Լ�
{
    int c, i, g = 0;

    system("cls");

    c = select_box();
    i = select_num(c);
    save_file_hat(i, c);
}
void plus_product_clothes(void)     //��ǰ �߰� �Լ�
{
    int c, i, g = 0;

    system("cls");

    c = select_box();
    i = select_num(c);
    save_file_clothes(i, c);
}
void plus_product_pants(void)     //��ǰ �߰� �Լ�
{
    int c, i, g = 0;

    system("cls");

    c = select_box();
    i = select_num(c);
    save_file_pants(i, c);
}
void plus_product_shoes(void)     //��ǰ �߰� �Լ�
{
    int c, i, g = 0;

    system("cls");

    c = select_box();
    i = select_num(c);
    save_file_shoes(i, c);
}

int select_num(int c)
{
    int select = 1;

    while (1) {
        see_box(c);
        return select;
        break;
    }

}

int select_box(void)      //��� ĭ���� ���� �Է��ϴ� �Լ�.
{
    system("cls");
    int select = 0;
    while (1) {
        item_display();
        printf("\n");
        printf("\t               ��������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("\t               ��                   �߰��� ��ġ�� ������.[1~20]                    ��\n");
        printf("\t               ��       ��ġ1:[1~5] ��ġ2:[6~10] ��ġ3:[11~15] ��ġ4:[16~20]       ��\n");
        printf("\t               ����������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("\t                ĭ ��ȣ>>");
        scanf("%d", &select);

        if (select < 1 || select > 20) {
            printf("\n\n�Է� �� �� ���� ���Դϴ�.");
            system("cls");
        }
        else {
            return select;
            break;
        }
    }
}

void see_box(int c)
{
    system("cls");
    int i;
}

int del_box(void)      //��� ĭ���� ���� �Է��ϴ� �Լ�.
{
    system("cls");
    int select = 0;
    while (1) {
        item_display();
        printf("\n");
        printf("\t               ��������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("\t               ��                   ������ ��ġ�� ������.[1~20]                    ��\n");
        printf("\t               ��       ��ġ1:[1~5] ��ġ2:[6~10] ��ġ3:[11~15] ��ġ4:[16~20]       ��\n");
        printf("\t               ����������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("\t                ĭ ��ȣ>>");
        scanf("%d", &select);

        if (select < 1 || select > 20) {
            printf("\n\n�Է� �� �� ���� ���Դϴ�.");
            system("cls");
        }
        else {
            return select;
            break;
        }
    }
}


int add_box(void)      //��� ĭ���� ���� �Է��ϴ� �Լ�.
{
    system("cls");
    int select = 0;
    while (1) {
        item_display();
        printf("\n");
        printf("\t               ��������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("\t               ��                   �԰��� ��ġ�� ������.[1~20]                    ��\n");
        printf("\t               ��       ��ġ1:[1~5] ��ġ2:[6~10] ��ġ3:[11~15] ��ġ4:[16~20]       ��\n");
        printf("\t               ����������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("\t                ĭ ��ȣ>>");
        scanf("%d", &select);

        if (select < 1 || select > 20) {
            printf("\n\n�Է� �� �� ���� ���Դϴ�.");
            system("cls");
        }
        else {
            return select;
            break;
        }
    }
}


int minus_box(void)      //��� ĭ���� ���� �Է��ϴ� �Լ�.
{
    system("cls");
    int select = 0;
    while (1) {
        item_display();
        printf("\n");
        printf("\t               ��������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("\t               ��                   ����� ��ġ�� ������.[1~20]                    ��\n");
        printf("\t               ��       ��ġ1:[1~5] ��ġ2:[6~10] ��ġ3:[11~15] ��ġ4:[16~20]       ��\n");
        printf("\t               ����������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("\t                ĭ ��ȣ>>");
        scanf("%d", &select);

        if (select < 1 || select > 20) {
            printf("\n\n�Է� �� �� ���� ���Դϴ�.");
            system("cls");
        }
        else {
            return select;
            break;
        }
    }
}

void save_file_hat(int i, int c)            // ��ǰ�߰� �� ���� ���� �Լ�
{
    system("cls");
    int g = 0;
    g = 5 * (i - 1) + (c - 1);     //ĭ=4(16~20��) ��ȣ=4 �ϋ�, g= 5*3+3 = 18 -> 18�� �迭�� ����

    FILE* fp = NULL;
    char fname[100] = { 0 };

    printf("\n\n\t\t\t    ��ǰ���� �Է��ϼ���:");
    scanf("%s", fname);

    fp = fopen("hat.txt", "w");     //hat.txt �̸����� ����"����"���� ����.
    if (fp == NULL)
        printf("���� ���⿡ �����߽��ϴ�.");

    strcpy(p[g].name, fname);
    printf("\n\t\t\t    ������ �Է��ϼ���:");
    scanf("%s", &p[g].color);

    printf("\n\t\t\t    ����� �Է��ϼ���:");
    scanf("%s", &p[g].size);
    printf("\n\t\t\t    ������ �Է��ϼ���:");
    scanf("%d", &p[g].amount);

    for (int k = 0; k < 100; k++) {
        fprintf(fp, "%s %s %s %d ", p[k].name, p[k].color, p[k].size, p[k].amount); //hat.txt���Ͽ� p[0]~p[99] ����ü ����
        fputc('\n', fp);
    }
    fclose(fp);

    printf("\n\n\n\t\t\t        �̸�:%s, ����:%s, ������:%s, ����:%d\n", p[g].name, p[g].color, p[g].size, p[g].amount); //����ü�� ���� �Ǿ� �ִ��� Ȯ��
    printf("\n\t\t\t            ��ǰ �߰��� �Ϸ�Ǿ����ϴ�.");

    _getch();
}

void save_file_clothes(int i, int c)            // ��ǰ�߰� �� ���� ���� �Լ�
{
    system("cls");
    int g = 0;
    g = 5 * (i - 1) + (c - 1);     //ĭ=4(16~20��) ��ȣ=4 �ϋ�, g= 5*3+3 = 18 -> 18�� �迭�� ����

    FILE* fp = NULL;
    char fname[100] = { 0 };

    printf("\n\n\t\t\t    ��ǰ���� �Է��ϼ���:");
    scanf("%s", fname);

    fp = fopen("clothes.txt", "w");     //clothes.txt �̸����� ����"����"���� ����.
    if (fp == NULL)
        printf("���� ���⿡ �����߽��ϴ�.");

    strcpy(p[g].name, fname);
    printf("\n\t\t\t    ������ �Է��ϼ���:");
    scanf("%s", &p[g].color);

    printf("\n\t\t\t    ����� �Է��ϼ���:");
    scanf("%s", &p[g].size);
    printf("\n\t\t\t    ������ �Է��ϼ���:");
    scanf("%d", &p[g].amount);

    for (int k = 0; k < 100; k++) {
        fprintf(fp, "%s %s %s %d ", p[k].name, p[k].color, p[k].size, p[k].amount); //clothes.txt���Ͽ� p[0]~p[99] ����ü ����
        fputc('\n', fp);
    }
    fclose(fp);

    printf("\n\n\n\t\t\t        �̸�:%s, ����:%s, ������:%s, ����:%d\n", p[g].name, p[g].color, p[g].size, p[g].amount); //����ü�� ���� �Ǿ� �ִ��� Ȯ��
    printf("\n\t\t\t            ��ǰ �߰��� �Ϸ�Ǿ����ϴ�.");

    _getch();
}

void save_file_pants(int i, int c)            // ��ǰ�߰� �� ���� ���� �Լ�
{
    system("cls");
    int g = 0;
    g = 5 * (i - 1) + (c - 1);     //ĭ=4(16~20��) ��ȣ=4 �ϋ�, g= 5*3+3 = 18 -> 18�� �迭�� ����

    FILE* fp = NULL;
    char fname[100] = { 0 };

    printf("\n\n\t\t\t    ��ǰ���� �Է��ϼ���:");
    scanf("%s", fname);

    fp = fopen("pants.txt", "w");     //pants.txt �̸����� ����"����"���� ����.
    if (fp == NULL)
        printf("���� ���⿡ �����߽��ϴ�.");

    strcpy(p[g].name, fname);
    printf("\n\t\t\t    ������ �Է��ϼ���:");
    scanf("%s", &p[g].color);

    printf("\n\t\t\t    ����� �Է��ϼ���:");
    scanf("%s", &p[g].size);
    printf("\n\t\t\t    ������ �Է��ϼ���:");
    scanf("%d", &p[g].amount);

    for (int k = 0; k < 100; k++) {
        fprintf(fp, "%s %s %s %d ", p[k].name, p[k].color, p[k].size, p[k].amount); //pants.txt���Ͽ� p[0]~p[99] ����ü ����
        fputc('\n', fp);
    }
    fclose(fp);

    printf("\n\n\n\t\t\t        �̸�:%s, ����:%s, ������:%s, ����:%d\n", p[g].name, p[g].color, p[g].size, p[g].amount); //����ü�� ���� �Ǿ� �ִ��� Ȯ��
    printf("\n\t\t\t            ��ǰ �߰��� �Ϸ�Ǿ����ϴ�.");

    _getch();
}

void save_file_shoes(int i, int c)            // ��ǰ�߰� �� ���� ���� �Լ�
{
    system("cls");
    int g = 0;
    g = 5 * (i - 1) + (c - 1);     //ĭ=4(16~20��) ��ȣ=4 �ϋ�, g= 5*3+3 = 18 -> 18�� �迭�� ����

    FILE* fp = NULL;
    char fname[100] = { 0 };

    printf("\n\n\t\t\t    ��ǰ���� �Է��ϼ���:");
    scanf("%s", fname);

    fp = fopen("shoes.txt", "w");     //shoes.txt �̸����� ����"����"���� ����.
    if (fp == NULL)
        printf("���� ���⿡ �����߽��ϴ�.");

    strcpy(p[g].name, fname);
    printf("\n\t\t\t    ������ �Է��ϼ���:");
    scanf("%s", &p[g].color);

    printf("\n\t\t\t    ����� �Է��ϼ���:");
    scanf("%s", &p[g].size);
    printf("\n\t\t\t    ������ �Է��ϼ���:");
    scanf("%d", &p[g].amount);

    for (int k = 0; k < 100; k++) {
        fprintf(fp, "%s %s %s %d ", p[k].name, p[k].color, p[k].size, p[k].amount); //shoes.txt���Ͽ� p[0]~p[99] ����ü ����
        fputc('\n', fp);
    }
    fclose(fp);

    printf("\n\n\n\t\t\t        �̸�:%s, ����:%s, ������:%s, ����:%d\n", p[g].name, p[g].color, p[g].size, p[g].amount); //����ü�� ���� �Ǿ� �ִ��� Ȯ��
    printf("\n\t\t\t            ��ǰ �߰��� �Ϸ�Ǿ����ϴ�.");

    _getch();
}

void load_file_hat(void)
{
    int i;
    FILE* fp;
    fp = fopen("hat.txt", "r");     //hat.txt�� ���� �б� ���� ����.
    if (fp == NULL)
    {
        printf("���� ���⿡ �����߽��ϴ�.");
    }
    for (i = 0; i < 100; i++) {
        fscanf(fp, "%s %s %s %d  ", p[i].name, &p[i].color, &p[i].size, &p[i].amount);  //hat.txt�� �ִ� �������� ����ü�� ����
    }
    fclose(fp);
}

void load_file_clothes(void)
{
    int i;
    FILE* fp;
    fp = fopen("clothes.txt", "r");     //clothes.txt�� ���� �б� ���� ����.
    if (fp == NULL)
    {
        printf("���� ���⿡ �����߽��ϴ�.");
    }
    for (i = 0; i < 100; i++) {
        fscanf(fp, "%s %s %s %d  ", p[i].name, &p[i].color, &p[i].size, &p[i].amount);  //clothes.txt�� �ִ� �������� ����ü�� ����
    }
    fclose(fp);
}

void load_file_pants(void)
{
    int i;
    FILE* fp;
    fp = fopen("pants.txt", "r");     //pants.txt�� ���� �б� ���� ����.
    if (fp == NULL)
    {
        printf("���� ���⿡ �����߽��ϴ�.");
    }
    for (i = 0; i < 100; i++) {
        fscanf(fp, "%s %s %s %d  ", p[i].name, &p[i].color, &p[i].size, &p[i].amount);  //pants.txt�� �ִ� �������� ����ü�� ����
    }
    fclose(fp);
}

void load_file_shoes(void)
{
    int i;
    FILE* fp;
    fp = fopen("shoes.txt", "r");     //shoes.txt�� ���� �б� ���� ����.
    if (fp == NULL)
    {
        printf("���� ���⿡ �����߽��ϴ�.");
    }
    for (i = 0; i < 100; i++) {
        fscanf(fp, "%s %s %s %d  ", p[i].name, &p[i].color, &p[i].size, &p[i].amount);  //shoes.txt�� �ִ� �������� ����ü�� ����
    }
    fclose(fp);
}

void del_hat(void)              // ��ǰ ���� �Լ�
{
    int c, i, g = 0;
    int m = 0;
    //c -> ĭ ��ȣ i -> ĭ �ȿ� ��ǰ ��ȣ
    char z[20] = { 0 };             //������ ���� z�� ����
    char w[20] = { 0 };             //������ ���� w�� ����
    char x[20] = { 0 };
    char name12[20] = { '-' };
    char color12[20] = { '-' };//�׳� �ʱ�ȭ�ϸ� �̸� �ɹ��� ������ ���ܼ� ���� ������ ��ĭ�� ����� �׷��� -����
    char size12[20] = { '-' };
    system("cls");

    c = del_box();
    i = select_num(c);
    g = 5 * (i - 1) + (c - 1);
    m = p[g].amount;
    strcpy(w, p[g].color);
    strcpy(z, p[g].name);
    strcpy(x, p[g].size);
    FILE* fp = NULL;
    fp = fopen("hat.txt", "w");     //hat.txt �̸����� ����"����"���� ����.
    if (fp == NULL)
    {
        printf("���� ���⿡ �����߽��ϴ�.");

    }
    system("cls");
    printf("\n\t\t\t            %dĭ (��)�� �����ϰڽ��ϴ�....\n", c);
    strcpy(p[g].name, name12);
    strcpy(p[g].color, color12);
    strcpy(p[g].size, size12);
    p[g].amount = 0;

    for (int k = 0; k < 100; k++) {   //�߰�
        fprintf(fp, " %s %s %s %d ", p[k].name, p[k].color, p[k].size, p[k].amount);
    }
    fclose(fp);

    printf("\n\t\t\t            �̸�:%s......���� �Ϸ�", z, p[g].name);
    printf("\n\t\t\t            ����:%s.......�����Ϸ�", w, p[g].color);
    printf("\n\t\t\t            ������:%d......�����Ϸ�", x, p[g].size);
    printf("\n\t\t\t            ����:%d.......�����Ϸ�", m, p[g].amount);
    printf("\n\t\t\t            ĭ:%d,��ȣ:%d, �̸�:%s, color:%s, size:%s, amount:%d", c, i, p[g].name, p[g].color, p[g].size, p[g].amount);
    printf("\n\t\t\t            .....������ �Ϸ�Ǿ����ϴ�!!!");
    _getch();
}


void del_pants(void)              // ��ǰ ���� �Լ�
{
    int c, i, g = 0;
    int m = 0;
    //c -> ĭ ��ȣ i -> ĭ �ȿ� ��ǰ ��ȣ
    char z[20] = { 0 };             //������ ���� z�� ����
    char w[20] = { 0 };             //������ ���� w�� ����
    char x[20] = { 0 };
    char name12[20] = { '-' };
    char color12[20] = { '-' };//�׳� �ʱ�ȭ�ϸ� �̸� �ɹ��� ������ ���ܼ� ���� ������ ��ĭ�� ����� �׷��� -����
    char size12[20] = { '-' };
    system("cls");

    c = del_box();
    i = select_num(c);
    g = 5 * (i - 1) + (c - 1);
    m = p[g].amount;
    strcpy(w, p[g].color);
    strcpy(z, p[g].name);
    strcpy(x, p[g].size);
    FILE* fp = NULL;
    fp = fopen("pants.txt", "w");     //pants.txt �̸����� ����"����"���� ����.
    if (fp == NULL)
    {
        printf("���� ���⿡ �����߽��ϴ�.");

    }
    system("cls");
    printf("\n\t\t\t            %dĭ (��)�� �����ϰڽ��ϴ�....\n", c);
    strcpy(p[g].name, name12);
    strcpy(p[g].color, color12);
    strcpy(p[g].size, size12);
    p[g].amount = 0;

    for (int k = 0; k < 100; k++) {   //�߰�
        fprintf(fp, " %s %s %s %d ", p[k].name, p[k].color, p[k].size, p[k].amount);
    }
    fclose(fp);

    printf("\n\t\t\t            �̸�:%s......���� �Ϸ�", z, p[g].name);
    printf("\n\t\t\t            ����:%s.......�����Ϸ�", w, p[g].color);
    printf("\n\t\t\t            ������:%d......�����Ϸ�", x, p[g].size);
    printf("\n\t\t\t            ����:%d.......�����Ϸ�", m, p[g].amount);
    printf("\n\t\t\t            ĭ:%d,��ȣ:%d, �̸�:%s, color:%s, size:%s, amount:%d", c, i, p[g].name, p[g].color, p[g].size, p[g].amount);
    printf("\n\t\t\t            .....������ �Ϸ�Ǿ����ϴ�!!!");
    _getch();
}

void del_clothes(void)              // ��ǰ ���� �Լ�
{
    int c, i, g = 0;
    int m = 0;
    //c -> ĭ ��ȣ i -> ĭ �ȿ� ��ǰ ��ȣ
    char z[20] = { 0 };             //������ ���� z�� ����
    char w[20] = { 0 };             //������ ���� w�� ����
    char x[20] = { 0 };
    char name12[20] = { '-' };
    char color12[20] = { '-' };//�׳� �ʱ�ȭ�ϸ� �̸� �ɹ��� ������ ���ܼ� ���� ������ ��ĭ�� ����� �׷��� -����
    char size12[20] = { '-' };
    system("cls");

    c = del_box();
    i = select_num(c);
    g = 5 * (i - 1) + (c - 1);
    m = p[g].amount;
    strcpy(w, p[g].color);
    strcpy(z, p[g].name);
    strcpy(x, p[g].size);
    FILE* fp = NULL;
    fp = fopen("clothes.txt", "w");     //clothes.txt �̸����� ����"����"���� ����.
    if (fp == NULL)
    {
        printf("���� ���⿡ �����߽��ϴ�.");

    }
    system("cls");
    printf("\n\t\t\t            %dĭ (��)�� �����ϰڽ��ϴ�....\n", c);
    strcpy(p[g].name, name12);
    strcpy(p[g].color, color12);
    strcpy(p[g].size, size12);
    p[g].amount = 0;

    for (int k = 0; k < 100; k++) {   //�߰�
        fprintf(fp, " %s %s %s %d", p[k].name, p[k].color, p[k].size, p[k].amount);
    }
    fclose(fp);

    printf("\n\t\t\t            �̸�:%s......���� �Ϸ�", z, p[g].name);
    printf("\n\t\t\t            ����:%s.......�����Ϸ�", w, p[g].color);
    printf("\n\t\t\t            ������:%d......�����Ϸ�", x, p[g].size);
    printf("\n\t\t\t            ����:%d.......�����Ϸ�", m, p[g].amount);
    printf("\n\t\t\t            ĭ:%d,��ȣ:%d, �̸�:%s, color:%s, size:%s, amount:%d", c, i, p[g].name, p[g].color, p[g].size, p[g].amount);
    printf("\n\t\t\t            .....������ �Ϸ�Ǿ����ϴ�!!!");
    _getch();
}

void del_shoes(void)              // ��ǰ ���� �Լ�
{
    int c, i, g = 0;
    int m = 0;
    //c -> ĭ ��ȣ i -> ĭ �ȿ� ��ǰ ��ȣ
    char z[20] = { 0 };             //������ ���� z�� ����
    char w[20] = { 0 };             //������ ���� w�� ����
    char x[20] = { 0 };
    char name12[20] = { '-' };
    char color12[20] = { '-' };//�׳� �ʱ�ȭ�ϸ� �̸� �ɹ��� ������ ���ܼ� ���� ������ ��ĭ�� ����� �׷��� -����
    char size12[20] = { '-' };
    system("cls");

    c = del_box();
    i = select_num(c);
    g = 5 * (i - 1) + (c - 1);
    m = p[g].amount;
    strcpy(w, p[g].color);
    strcpy(z, p[g].name);
    strcpy(x, p[g].size);
    FILE* fp = NULL;
    fp = fopen("shoes.txt", "w");     //shoes.txt �̸����� ����"����"���� ����.
    if (fp == NULL)
    {
        printf("���� ���⿡ �����߽��ϴ�.");

    }
    system("cls");
    printf("\n\t\t\t            %dĭ (��)�� �����ϰڽ��ϴ�....\n", c);
    strcpy(p[g].name, name12);
    strcpy(p[g].color, color12);
    strcpy(p[g].size, size12);
    p[g].amount = 0;

    for (int k = 0; k < 100; k++) {   //�߰�
        fprintf(fp, " %s %s %s %d", p[k].name, p[k].color, p[k].size, p[k].amount);
    }
    fclose(fp);

    printf("\n\t\t\t            �̸�:%s......���� �Ϸ�", z, p[g].name);
    printf("\n\t\t\t            ����:%s.......�����Ϸ�", w, p[g].color);
    printf("\n\t\t\t            ������:%d......�����Ϸ�", x, p[g].size);
    printf("\n\t\t\t            ����:%d.......�����Ϸ�", m, p[g].amount);
    printf("\n\t\t\t            ĭ:%d,��ȣ:%d, �̸�:%s, color:%s, size:%s, amount:%d", c, i, p[g].name, p[g].color, p[g].size, p[g].amount);
    printf("\n\t\t\t            .....������ �Ϸ�Ǿ����ϴ�!!!");
    _getch();
}

void add_hat(void)              //�԰� �Լ�
{
    int  m = 0;
    int c, i, g = 0;//c -> ĭ ��ȣ i -> ĭ �ȿ� ��ǰ ��ȣ
    int aaa; //add����

    system("cls");

    c = add_box();
    i = select_num(c);
    g = 5 * (i - 1) + (c - 1);
    m = p[g].amount;

    FILE* fp = NULL;
    fp = fopen("hat.txt", "w");     //�Էµ� �̸����� ����"����"���� ����.(���� �ϱ� ���ؼ�)
    if (fp == NULL)
    {
        printf("���� ���⿡ �����߽��ϴ�.");
    }
    system("cls");
    printf("\n\t\t\t       ��%dĭ %s(��)�� �԰��ϰڽ��ϴ�....", c, p[g].name);

    printf("\n\t\t\t       ���԰��� ������ �Է��ϼ���.>>");                                           //���� ����
    scanf("%d", &aaa);
    p[g].amount += aaa;

    for (int k = 0; k < 100; k++) {             //�߰�
        fprintf(fp, " %d ", p[k].amount);      // ���� �� ���� ���Ͽ� ����
    }
    fclose(fp);
    printf("\n\n\t\t\t       �԰� ��// ĭ:%d ����:%d\n", c, m); //���� �� ���� ���
    printf("\n\t\t\t       �԰� ��// ĭ:%d ����:%d\n", c, p[g].amount);//���� �� ���� ���
    printf("\n\t\t\t       �԰� �Ϸ��߽��ϴ�!!!");

    _getch();
}

void add_clothes(void)              //�԰� �Լ�
{
    int  m = 0;
    int c, i, g = 0;//c -> ĭ ��ȣ i -> ĭ �ȿ� ��ǰ ��ȣ
    int aaa; //aaa����

    system("cls");

    c = add_box();
    i = select_num(c);
    g = 5 * (i - 1) + (c - 1);
    m = p[g].amount;

    FILE* fp = NULL;
    fp = fopen("clothes.txt", "w");     //�Էµ� �̸����� ����"����"���� ����.(���� �ϱ� ���ؼ�)
    if (fp == NULL)
    {
        printf("���� ���⿡ �����߽��ϴ�.");
    }
    system("cls");
    printf("\n\t\t\t       ��%dĭ %s(��)�� �԰��ϰڽ��ϴ�....", c, p[g].name);

    printf("\n\t\t\t       ���԰��� ������ �Է��ϼ���.>>");                                           //���� ����
    scanf("%d", &aaa);
    p[g].amount += aaa;

    for (int k = 0; k < 100; k++) {             //�߰�
        fprintf(fp, " %d ", p[k].amount);      // ���� �� ���� ���Ͽ� ����
    }
    fclose(fp);
    printf("\n\n\t\t\t       �԰� ��// ĭ:%d ����:%d\n", c, m); //���� �� ���� ���
    printf("\n\t\t\t       �԰� ��// ĭ:%d ����:%d\n", c, p[g].amount);//���� �� ���� ���
    printf("\n\t\t\t       �԰� �Ϸ��߽��ϴ�!!!");

    _getch();
}

void add_pants(void)              //�԰� �Լ�
{
    int  m = 0;
    int c, i, g = 0;//c -> ĭ ��ȣ i -> ĭ �ȿ� ��ǰ ��ȣ
    int aaa; //aaa����

    system("cls");

    c = add_box();
    i = select_num(c);
    g = 5 * (i - 1) + (c - 1);
    m = p[g].amount;

    FILE* fp = NULL;
    fp = fopen("pants.txt", "w");     //�Էµ� �̸����� ����"����"���� ����.(���� �ϱ� ���ؼ�)
    if (fp == NULL)
    {
        printf("���� ���⿡ �����߽��ϴ�.");
    }
    system("cls");
    printf("\n\t\t\t       ��%dĭ %s(��)�� �԰��ϰڽ��ϴ�....", c, p[g].name);

    printf("\n\t\t\t       ���԰��� ������ �Է��ϼ���.>>");                                           //���� ����
    scanf("%d", &aaa);
    p[g].amount += aaa;

    for (int k = 0; k < 100; k++) {             //�߰�
        fprintf(fp, " %d ", p[k].amount);      // ���� �� ���� ���Ͽ� ����
    }
    fclose(fp);
    printf("\n\n\t\t\t       �԰� ��// ĭ:%d ����:%d\n", c, m); //���� �� ���� ���
    printf("\n\t\t\t       �԰� ��// ĭ:%d ����:%d\n", c, p[g].amount);//���� �� ���� ���
    printf("\n\t\t\t       �԰� �Ϸ��߽��ϴ�!!!");

    _getch();
}

void add_shoes(void)              //�԰� �Լ�
{
    int  m = 0;
    int c, i, g = 0;//c -> ĭ ��ȣ i -> ĭ �ȿ� ��ǰ ��ȣ
    int aaa; //aaa����

    system("cls");

    c = add_box();
    i = select_num(c);
    g = 5 * (i - 1) + (c - 1);
    m = p[g].amount;

    FILE* fp = NULL;
    fp = fopen("shoes.txt", "w");     //�Էµ� �̸����� ����"����"���� ����.(���� �ϱ� ���ؼ�)
    if (fp == NULL)
    {
        printf("���� ���⿡ �����߽��ϴ�.");
    }
    system("cls");
    printf("\n\t\t\t       ��%dĭ %s(��)�� �԰��ϰڽ��ϴ�....", c, p[g].name);

    printf("\n\t\t\t       ���԰��� ������ �Է��ϼ���.>>");                                           //���� ����
    scanf("%d", &aaa);
    p[g].amount += aaa;

    for (int k = 0; k < 100; k++) {             //�߰�
        fprintf(fp, " %d ", p[k].amount);      // ���� �� ���� ���Ͽ� ����
    }
    fclose(fp);
    printf("\n\n\t\t\t       �԰� ��// ĭ:%d ����:%d\n", c, m); //���� �� ���� ���
    printf("\n\t\t\t       �԰� ��// ĭ:%d ����:%d\n", c, p[g].amount);//���� �� ���� ���
    printf("\n\t\t\t       �԰� �Ϸ��߽��ϴ�!!!");

    _getch();
}

void minus_hat(void)                //��� �Լ�
{
    int  m = 0;
    int c, i, g = 0;//c -> ĭ ��ȣ i -> ĭ �ȿ� ��ǰ ��ȣ
    int bbb; //bbb����

    system("cls");

    c = minus_box();
    i = select_num(c);
    g = 5 * (i - 1) + (c - 1);        //''
    m = p[g].amount;              //''

    FILE* fp = NULL;
    fp = fopen("hat.txt", "w");     //�Էµ� �̸����� ����"����"���� ����.(���� �ϱ� ���ؼ�)
    if (fp == NULL)
    {
        printf("���� ���⿡ �����߽��ϴ�.");
    }
    system("cls");
    printf("\n\t\t\t       ��%dĭ %s(��)�� ����ϰڽ��ϴ�....", c, p[g].name);

    printf("\n\t\t\t       ������� ������ �Է��ϼ���.>>");                                           //���� ����
    scanf("%d", &bbb);
    p[g].amount -= bbb;

    for (int k = 0; k < 100; k++) {             //�߰�
        fprintf(fp, " %d ", p[k].amount);      // ���� �� ���� ���Ͽ� ����
    }
    fclose(fp);
    printf("\n\n\t\t\t       ��� ��// ĭ:%d,����:%d\n", c, m); //���� �� ���� ���
    printf("\n\t\t\t       ��� ��// ĭ:%d, ����:%d\n", c, p[g].amount);//���� �� ���� ���
    printf("\n\t\t\t       ��� �Ϸ��߽��ϴ�!!!");

    _getch();
}

void minus_clothes(void)                //��� �Լ�
{
    int  m = 0;
    int c, i, g = 0;//c -> ĭ ��ȣ i -> ĭ �ȿ� ��ǰ ��ȣ
    int bbb; //bbb����

    system("cls");

    c = minus_box();
    i = select_num(c);
    g = 5 * (i - 1) + (c - 1);        //''
    m = p[g].amount;              //''

    FILE* fp = NULL;
    fp = fopen("clothes.txt", "w");     //�Էµ� �̸����� ����"����"���� ����.(���� �ϱ� ���ؼ�)
    if (fp == NULL)
    {
        printf("���� ���⿡ �����߽��ϴ�.");
    }
    system("cls");
    printf("\n\t\t\t       ��%dĭ %s(��)�� ����ϰڽ��ϴ�....", c, p[g].name);

    printf("\n\t\t\t       ������� ������ �Է��ϼ���.>>");                                           //���� ����
    scanf("%d", &bbb);
    p[g].amount -= bbb;

    for (int k = 0; k < 100; k++) {             //�߰�
        fprintf(fp, " %d ", p[k].amount);      // ���� �� ���� ���Ͽ� ����
    }
    fclose(fp);
    printf("\n\n\t\t\t       ��� ��// ĭ:%d,����:%d\n", c, m); //���� �� ���� ���
    printf("\n\t\t\t       ��� ��// ĭ:%d, ����:%d\n", c, p[g].amount);//���� �� ���� ���
    printf("\n\t\t\t       ��� �Ϸ��߽��ϴ�!!!");

    _getch();
}

void minus_pants(void)                //��� �Լ�
{
    int  m = 0;
    int c, i, g = 0;//c -> ĭ ��ȣ i -> ĭ �ȿ� ��ǰ ��ȣ
    int bbb; //bbb����

    system("cls");

    c = minus_box();
    i = select_num(c);
    g = 5 * (i - 1) + (c - 1);        //''
    m = p[g].amount;              //''

    FILE* fp = NULL;
    fp = fopen("pants.txt", "w");     //�Էµ� �̸����� ����"����"���� ����.(���� �ϱ� ���ؼ�)
    if (fp == NULL)
    {
        printf("���� ���⿡ �����߽��ϴ�.");
    }
    system("cls");
    printf("\n\t\t\t       ��%dĭ %s(��)�� ����ϰڽ��ϴ�....", c, p[g].name);

    printf("\n\t\t\t       ������� ������ �Է��ϼ���.>>");                                           //���� ����
    scanf("%d", &bbb);
    p[g].amount -= bbb;

    for (int k = 0; k < 100; k++) {             //�߰�
        fprintf(fp, " %d ", p[k].amount);      // ���� �� ���� ���Ͽ� ����
    }
    fclose(fp);
    printf("\n\n\t\t\t       ��� ��// ĭ:%d,����:%d\n", c, m); //���� �� ���� ���
    printf("\n\t\t\t       ��� ��// ĭ:%d, ����:%d\n", c, p[g].amount);//���� �� ���� ���
    printf("\n\t\t\t       ��� �Ϸ��߽��ϴ�!!!");

    _getch();
}

void minus_shoes(void)                //��� �Լ�
{
    int  m = 0;
    int c, i, g = 0;//c -> ĭ ��ȣ i -> ĭ �ȿ� ��ǰ ��ȣ
    int bbb; //bbb����

    system("cls");

    c = minus_box();
    i = select_num(c);
    g = 5 * (i - 1) + (c - 1);        //''
    m = p[g].amount;              //''

    FILE* fp = NULL;
    fp = fopen("shoes.txt", "w");     //�Էµ� �̸����� ����"����"���� ����.(���� �ϱ� ���ؼ�)
    if (fp == NULL)
    {
        printf("���� ���⿡ �����߽��ϴ�.");
    }
    system("cls");
    printf("\n\t\t\t       ��%dĭ %s(��)�� ����ϰڽ��ϴ�....", c, p[g].name);

    printf("\n\t\t\t       ������� ������ �Է��ϼ���.>>");                                           //���� ����
    scanf("%d", &bbb);
    p[g].amount -= bbb;

    for (int k = 0; k < 100; k++) {             //�߰�
        fprintf(fp, " %d ", p[k].amount);      // ���� �� ���� ���Ͽ� ����
    }
    fclose(fp);
    printf("\n\n\t\t\t       ��� ��// ĭ:%d,����:%d\n", c, m); //���� �� ���� ���
    printf("\n\t\t\t       ��� ��// ĭ:%d, ����:%d\n", c, p[g].amount);//���� �� ���� ���
    printf("\n\t\t\t       ��� �Ϸ��߽��ϴ�!!!");

    _getch();
}

void hat_check(void) {

}