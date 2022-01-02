#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

//������� ������ �����ϴ� ����ü
struct location {
    char product[200];
    char address[200];
    char kind[200];
};
struct location item[200];


void insert(location* ptr, int* data);
int deleted(location* ptr, int* data);
int find(location* ptr, int* data);
void all(location* ptr, int* data);
int saveFile(location* ptr, int* data);
int openFile(location* ptr, int* data);


void loca() {
    system("mode con cols=110 lines=500");
    int z = 0;
    int count = 0; //����� ��
    system("cls");

    openFile(item, &count);

    while (z != 5)
    {
        printf("\n������������������������������������������������������ ��ǰ ��ġ ã�� ������������������������������������������������������\n");
        printf("��                            [1]��ǰ �߰�                            ��\n");
        printf("��                            [2]��ǰ ����                            ��\n");
        printf("��                            [3]��ġ ã��                            ��\n");
        printf("��                            [4]��� ���� Ȯ��                       ��\n");
        printf("��                            [5]���� �� ����                         ��\n");
        printf("��������������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("� ����� ����Ͻðڽ��ϱ�? : ");
        if (0 < z || z < 6) {
            scanf("%d", &z);
        }
        else {
            printf("��ȣ�� �ٽ� �Է��� �ּ���");      // ���� ���ΰ� �����Ű�� ���� 1~5�� ���ڸ� ������ Ű �Է½� ���� ȭ������ ���������� ������ ����(�ϴ� ����� ��� ����� ����)
            return;
        }

        switch (z) {
        case 1:
            printf("\n��ǰ �߰� ��� �Դϴ�. \n");
            insert(item, &count);
            break;
        case 2:
            printf("\n��ǰ ���� ��� �Դϴ�. \n");
            deleted(item, &count);
            break;
        case 3:
            printf("\n��ġ ã�� ��� �Դϴ�. \n");
            find(item, &count);
            break;
        case 4:
            printf("\n�Է��� ��� ������ ����մϴ�. \n");
            all(item, &count);
            break;
        case 5:
            printf("\n����ȭ������ �������ϴ�. \n");
            saveFile(item, &count);
            break;
        default:
            printf("\n��ȣ�� �ٽ� �Է��� �ּ���! \n\n");
            break;
        }
    }

    return;
}

//�����͸� ���Ͽ� �����ϴ� �Լ�
int saveFile(location* ptr, int* data) {

    if (*data > 0) {
        int a, state;
        FILE* fp = fopen("test.txt", "wt");
        /* fopen�Լ��� �����߻��� NULL�� �����ϹǷ�
           ���� ���� �� �����߻��� ���α׷��� ���� */
        if (fp == NULL) {
            printf("������ ���µ� ������ �߻��߽��ϴ�!\n");
            return 1;
        }



        //����ü �迭�� ����� �����͸� ���Ͽ� ����
        //�ٹٲ����� �����Ͽ� ����
        for (a = 0; a < *data; a++) {
            fprintf(fp, "%s %s %s", ptr[a].product, ptr[a].address, ptr[a].kind);
            fputc('\n', fp);
        }



        /* fclose�Լ��� ����� ������ �߻��ϸ�
        0�� �ƴ� �ٸ����� �����ϹǷ� ������ ����� �ǴܵǸ�
        �ȳ��� ���α׷��� ���� */
        state = fclose(fp);
        if (state != 0) {
            printf("������ �ݴµ� ������ �߻��߽��ϴ�!\n");
            return 1;
        }
        printf("\n  ������ �����մϴ� \n");
        return 0;
    }

    else {
        printf("\n �����մϴ� \n");
        return 0;
    }
}



//���Ϸκ��� �����͸� �ҷ����� �Լ�
int openFile(location* ptr, int* data) {
    int state;
    char temp;
    FILE* fp = fopen("test.txt", "rt");

    if (fp == NULL) {
        printf("������ ���µ� ������ �߻��߽��ϴ�!\n");
        return 1;
    }

    //���Ͽ� ����� �����͸� ����ü �迭�� ����
    while (1) {
        fscanf(fp, "%s %s %s", ptr[*data].product, ptr[*data].address, ptr[*data].kind);
        if (feof(fp) != 0)                                              // ���Ͽ� ���� �����ϸ� Ż��
            break;
        (*data)++;
    }



    /* fclose�Լ��� ����� ������ �߻��ϸ�
    0�� �ƴ� �ٸ����� �����ϹǷ� ������ ����� �ǴܵǸ�
    �ȳ��� ���α׷��� ���� */
    state = fclose(fp);
    if (state != 0) {
        printf("������ �߻��߽��ϴ�!\n");
        return 1;
    }

    return 0;
}



void insert(location* ptr, int* data) {         //��ǰ ������ �����ϴ� �Լ�
    if (*data < 200) {              //��ǰ ������ �� ���� ������
        printf("\n�߰��� ��ǰ �̸��� �Է��� �ּ���(�����̽��� ��� - ���): ");
        scanf("%s", ptr[*data].product);
        printf("\n%s�� ��ǰ ������ �Է��� �ּ���(�����̽��� ��� - ���): ", ptr[*data].product);
        scanf("%s", ptr[*data].kind);
        printf("\n%s�� ��ǰ ��ġ�� �Է��� �ּ���(�����̽��� ��� - ���, ex.1��,2��-3��°ĭ): ", ptr[*data].product);
        scanf("%s", ptr[*data].address);


        (*data)++;
        printf(" \n��ǰ�� �߰��Ǿ����ϴ�....");
    }
    //��ǰ ������ �� ����
    else
        printf(" \n���差�� �ʰ��Ǿ����ϴ�. ��ǰ�� ������ �� �߰����ּ���");
    Sleep(2000);
    system("cls");
}



//��ǰ�� ������ �����ϴ� �Լ�
int deleted(location* ptr, int* data) {
    char product[200];
    int a, b;
    system("cls");
    //��ǰ ������ �Ѱ��� ����������
    if (*data > 0) {
        printf("\n������ ��ǰ �̸��� �Է����ּ���: ");
        scanf("%s", product);

        for (a = 0; a < 200; a++) {
            //���ڿ��̹Ƿ� ���ϱ����� strcmp���
            if (strcmp(product, ptr[a].product) == 0) {

                (*data)--;
                printf("\n��ǰ�� ������ �����Ǿ����ϴ�....");

                //�����Ͱ� ���� ���� �ʾҴٸ�
                if (a != 200 - 1) {
                    for (b = a; b < 200; b++) {
                        //���ڿ��̹Ƿ� strcpy�� ����Ͽ� ������ ����
                        strcpy(ptr[b].product, ptr[b + 1].product);
                        strcpy(ptr[b].kind, ptr[b + 1].kind);
                        strcpy(ptr[b].address, ptr[b + 1].address);
                    }


                    //����ü �迭�� �������� NULL�� �ٲ�
                    *ptr[200 - 1].product = NULL;
                    *ptr[200 - 1].kind = NULL;
                    *ptr[200 - 1].address = NULL;
                }


                //�����Ͱ� ���� á�ٸ�
                else {
                    //����ü �迭�� �������� NULL�� �ٲ�
                    *ptr[200 - 1].product = NULL;
                    *ptr[200 - 1].kind = NULL;
                    *ptr[200 - 1].address = NULL;
                }
                return 0;
            }
        }

    }
    //����� ��ǰ ������ ���ٸ�

    else 
        printf("\n�Է��� ��ǰ�� ������ �����ϴ�.");

    
    Sleep(2000);
    system("cls");
}



//��ǰ�� ������ �˻��ϴ� �Լ�
int find(location* ptr, int* data) {
    char product[200];
    char kind[200];
    int a;
    int c=0;
    system("cls");

    printf("������������������������\n");
    printf("��1�� : �̸���\n");
    printf("��2�� : ������\n");
    printf("������������������������\n");
    printf("� ������ ���� ��ġ�� �˻��Ͻðڽ��ϱ�?(���ڸ� �Է�) : "); 
    c = _getch() - 48;

    switch (c)                  // ��ȣ �Է½� ��� ���
    {
    case 1:
        //����� �����Ͱ� �ִٸ�
        if (*data > 0) {
            printf("\n ��ǰ �̸��� �Է��� �ּ���: ");
            scanf("%s", product);



            for (a = 0; a < 200; a++) {
                //strstr�� ���� �� ���ڸ� �Է��ص� �˻� �����ϵ��� ����
                if (strstr(ptr[a].product, product) != NULL) {

                        printf("\n��ǰ�� %s�� ��ġ�� %s �Դϴ�.\n ", ptr[a].product, ptr[a].address);

                    }
                
            }

        }
        else {
            printf("\n����� ��ǰ�� ������ �����ϴ�.");
            return 0;
        }
        Sleep(2000);
        break;
    case 2:
        //����� �����Ͱ� �ִٸ�
        if (*data > 0) {
            printf("\n ������ �Է��� �ּ���: ");
            scanf("%s", kind);



            for (a = 0; a < 200; a++) {
                //strstr�� ���� �� ���ڸ� �Է��ص� �˻� �����ϵ��� ����
                if (strstr(ptr[a].kind, kind) != NULL) {

                        printf("\n %s ������ %s ��ǰ�� ��ġ�� %s �Դϴ�.\n ", ptr[a].kind, ptr[a].product,ptr[a].address);

                    }
                }
            

        }
        else {
            printf("\n����� ��ǰ�� ������ �����ϴ�.");
            return 0;
        }
        Sleep(2000);
        break;
    }
}

// ��� ��ǰ ��� �Լ�
void all(location* ptr, int* data) {
    int a, j = 0;
    int white = 7;          // ���ڻ� ������ ���� ��ȣ ����
    int red = 4;            // ���ڻ� ������ ���� ��ȣ ����
    system("cls");
    if (*data > 0) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), red);          // ���ڻ��� ���������� ����
        printf("\n��� ��ǰ�� ��ġ\n");
        printf("\n1�� ��ǰ�� ��ġ\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);        // ���ڻ� �ٽ� ȭ��Ʈ�� ����
        printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("��              ��ǰ �̸�                      ����                             ��ǰ ��ġ                 ��\n");
        printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
        for (a = 0; a < *data; a++) {
            if (strncmp(ptr[a].address, "1", 1) == NULL) {              // strncmp�� ���� �ּ������� ù��°ĭ�� 1�϶� ���
                printf("��             %-20s            %-20s               %-20s    ��\n", ptr[a].product, ptr[a].kind, ptr[a].address);
            }
        }

        printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), red);
        printf("\n2�� ��ǰ�� ��ġ\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
        printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("��              ��ǰ �̸�                      ����                             ��ǰ ��ġ                 ��\n");
        printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
        for (a = 0; a < *data; a++) {
            if (strncmp(ptr[a].address, "2", 1) == NULL) {              // strncmp�� ���� �ּ������� ù��°ĭ�� 2�϶� ���          
                printf("��             %-20s            %-20s               %-20s    ��\n", ptr[a].product, ptr[a].kind, ptr[a].address);
            }
        }

        printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), red);
        printf("\n3�� ��ǰ�� ��ġ\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
        printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("��              ��ǰ �̸�                      ����                             ��ǰ ��ġ                 ��\n");
        printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
        for (a = 0; a < *data; a++) {
            if (strncmp(ptr[a].address, "3", 1) == NULL) {              // strncmp�� ���� �ּ������� ù��°ĭ�� 3�϶� ���
                printf("��             %-20s            %-20s               %-20s    ��\n", ptr[a].product, ptr[a].kind, ptr[a].address);
            }
        }

        printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), red);
        printf("\n4�� ��ǰ�� ��ġ\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
        printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("��              ��ǰ �̸�                      ����                             ��ǰ ��ġ                 ��\n");
        printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
        for (a = 0; a < *data; a++) {
            if (strncmp(ptr[a].address, "4", 1) == NULL) {              // strncmp�� ���� �ּ������� ù��°ĭ�� 4�϶� ���
                printf("��             %-20s            %-20s               %-20s    ��\n", ptr[a].product, ptr[a].kind, ptr[a].address);
            }
        }

        printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), red);
        printf("\n5�� ��ǰ�� ��ġ\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
        printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("��              ��ǰ �̸�                      ����                             ��ǰ ��ġ                 ��\n");
        printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
        for (a = 0; a < *data; a++) {
            if (strncmp(ptr[a].address, "5", 1) == NULL) {              // strncmp�� ���� �ּ������� ù��°ĭ�� 5�϶� ���
                printf("��             %-20s            %-20s               %-20s    ��\n", ptr[a].product, ptr[a].kind, ptr[a].address);
            }
        }

        printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    }


    else
        printf("�����͸� �ҷ��� �� �����ϴ�. �ٽ� ������ �ּ��� \n\n");
    Sleep(2000);
}