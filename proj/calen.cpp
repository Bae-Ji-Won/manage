#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STRING_MAX 3000
#define FILENAME "schedule.txt"

typedef unsigned int BOOL;

enum
{
    FALSE,
    TRUE
};

typedef struct _DATE  //����ü�̸�
{
    int m_nYear;  //�ڷ��� ����̸�
    int m_nMonth;
    int m_nDay;
    int m_nHour;
    int m_nMinute; //����ü ��Ī
}DATE;

void PrintDate(DATE date);   //Date����Լ�
void ModifyMonth(DATE* pDate, int nMonth); //�� �����Լ�
void ModifyDay(DATE* pDate, int nDay); //�� �����Լ�

int CompareDate(DATE target, DATE compare); //��¥��
int CompareDateAndTime(DATE target, DATE compare); //��¥�� �ð� �� 


DATE InputDate(void); //��¥�Է�
DATE GetToday(void); //�����Է�
DATE current;  //����

typedef struct _SCHEDULE //����ü �̸�
{
    DATE m_date;
    char m_szText[STRING_MAX];

    struct _SCHEDULE* next;
}SCHEDULE;       //����ü ��Ī

void KillAllScheduleNode(SCHEDULE* pHead);  //������â ����� �Լ�
void AddScheduleNode(SCHEDULE* pHead, SCHEDULE schedule);
void PrintAllSchedule(SCHEDULE* pHead); //������â ����Լ�
void PrintScheduleByDate(SCHEDULE* pHead, DATE date);
void DeleteScheduleByDateAndTime(SCHEDULE* pHead, DATE date); //������ ��¥�� �ð� �����Լ�
void ChangeScheduleByDateAndTime(SCHEDULE* pHead, SCHEDULE schedule); //������ ��¥�� �ð� �����Լ�

void LoadScheduleFromFile(SCHEDULE* pHead, char szFileName[]);  //���Ϸκ��� ������ �ε� �Լ�
void SaveScheduleToFile(SCHEDULE* pHead, char szFileName[]); //������ ���� ���� �Լ�

SCHEDULE* InitScheduleHead(void);
SCHEDULE* GetSchedulePointerByDate(SCHEDULE* pHead, DATE date);
SCHEDULE* GetSchedulePointerByDateAndTime(SCHEDULE* pHead, DATE date);
SCHEDULE InputSchedule(SCHEDULE* pHead);

void DrawCalendar(SCHEDULE* pHead, DATE date);  //�޷�����Լ�
void ShowAllScheduleByDay(SCHEDULE* pHead, DATE date);//��¥�� �߰��� ������ �����ִ� �Լ�

int GetLastDayByMonthAndYear(int nYear, int nMonth);
void DrawCalendar(SCHEDULE* pHead, DATE date); //�޷�����Լ�









//main
enum MENU
{
    PREV_MONTH = 'q', //������
    NEXT_MONTH = 'w', //������
    PREV_DAY = 'e',   //������
    NEXT_DAY = 'r', //������
    ADD_SCHEDULE = '1', //�������߰�
    DELETE_SCHEDULE = '2', //�����ٻ���
    CHANGE_SCHEDULE = '3', //�����ټ���
    QUIT = '4'  //����
};

void ShowAllScheduleByDay(SCHEDULE* pHead, DATE date); //�߰��� ������ �����ִ� �Լ�
void DeleteSchedule(SCHEDULE* pHead); //������ �����Լ�
void AddSchedule(SCHEDULE* pHead); //������ �߰��Լ�
void Changeschedule(SCHEDULE* pHead);  //������ �����Լ�


char GetSelectedMenu(void);

void calen()
{
    SCHEDULE* pHead;
    //DATE current;

    pHead = InitScheduleHead();
    LoadScheduleFromFile(pHead, FILENAME);

    current = GetToday();  //���ó�¥�� ����� ����
    system("cls");

    while (TRUE)
    {
        char ch;

        DrawCalendar(pHead, current);//���糯¥�� �޷����
        ShowAllScheduleByDay(pHead, current);//���糯¥�� �������

        ch = GetSelectedMenu();

        if (ch == QUIT)
        {
            break;
        }

        switch (ch)
        {
        case PREV_MONTH:
            ModifyMonth(&current, -1);  //���� month -1
            break;

        case NEXT_MONTH:
            ModifyMonth(&current, 1);  //���� month +1
            break;

        case PREV_DAY:
            ModifyDay(&current, -1);  //���� day-1
            break;

        case NEXT_DAY:
            ModifyDay(&current, 1);  //���� day+1
            break;

        case ADD_SCHEDULE:
            AddSchedule(pHead);  //������ �߰�
            break;

        case DELETE_SCHEDULE:
            DeleteSchedule(pHead);  //������ ����
            break;

        case CHANGE_SCHEDULE:
            Changeschedule(pHead);  //������ ����
            break;
        }

        system("cls");
    }


    SaveScheduleToFile(pHead, FILENAME); //���������� �����Լ�
    KillAllScheduleNode(pHead);//������â ����� �Լ�
}

char GetSelectedMenu(void)
{
    char ch;

    printf("                                       ��������������������������������������������������\n");
    printf("                                       ��          MENU         ��\n");
    printf("                                       ��  q : ���� �޷� �ѱ�� ��\n");
    printf("                                       ��  w : ���� �޷� �ѱ�� ��\n");
    printf("                                       ��  e : ���� ���� �ѱ�� ��\n");
    printf("                                       ��  r : ���� ���� �ѱ�� ��\n");
    printf("                                       ��  1 : ������ �߰� �ϱ� ��\n");
    printf("                                       ��  2 : ������ ���� �ϱ� ��\n");
    printf("                                       ��  3 : ������ ���� �ϱ� ��\n");
    printf("                                       ��  4 : ���α׷� ����    ��\n");
    printf("                                       ��������������������������������������������������\n");
    printf("                     �޴��� �Է��Ͻÿ� >> ");
    ch = getchar();
    return ch;
}

void ShowAllScheduleByDay(SCHEDULE* pHead, DATE date) // ������ �� ���� �ð� �� ����
{
    SCHEDULE* pFind = pHead->next;

    printf("\n");
    printf("                                         *  %d/%d/%d�� ���� *\n", date.m_nYear,
        date.m_nMonth,
        date.m_nDay);

    printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

    while (pFind != NULL)
    {
        if (CompareDate(pFind->m_date, date) == 0)//ã�³��� ����ȳ��� ������ 
        {
            printf("%d�� %d�� : %s\n",
                pFind->m_date.m_nHour,//����� �ð����
                pFind->m_date.m_nMinute, //����� �����
                pFind->m_szText); //����� �������

        }

        pFind = pFind->next;
    }

    printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n\n");
}

void DeleteSchedule(SCHEDULE* pHead)  //������ ����
{
    DATE date;
    DATE current;
    current = GetToday();

    system("cls");
    DrawCalendar(pHead, current); //����������� �޷����
    ShowAllScheduleByDay(pHead, current); //����������� ������ ���
    printf("                                       ��������������������������������������������������������������������������������\n");
    printf("                                       ��                                      ��\n");
    printf("                                       ��  ��, ��, ��, �ð�, �� ������ �Է�    ��\n");
    printf("                                       ��  (����)2021 6 7 13 55                ��\n");
    printf("                                       ��                                      ��\n");
    printf("                                       ��������������������������������������������������������������������������������\n\n");
    printf("                                       >> ");

    scanf("%d %d %d %d",
        &date.m_nYear,
        &date.m_nMonth,
        &date.m_nDay,
        &date.m_nHour,
        &date.m_nMinute); //��,��,��,�ð� �Է�

    DeleteScheduleByDateAndTime(pHead, date);  //������ ��¥�� �ð� �����Լ� 
    system("cls");
}

void AddSchedule(SCHEDULE* pHead)  //������ �߰�
{
    SCHEDULE schedule;

    schedule = InputSchedule(pHead);

    AddScheduleNode(pHead, schedule);
}

void Changeschedule(SCHEDULE* pHead)   //������ ����
{
    SCHEDULE ret;
    DATE current;
    current = GetToday();

    system("cls");
    DrawCalendar(pHead, current);
    ShowAllScheduleByDay(pHead, current);

    printf("                                       ��������������������������������������������������������������������������������\n");
    printf("                                       ��                                      ��\n");
    printf("                                       ��  ��, ��, ��, �ð�, �� ������ �Է�    ��\n");
    printf("                                       ��  (����)2021 6 7 13 55                ��\n");
    printf("                                       ��                                      ��\n");
    printf("                                       ��������������������������������������������������������������������������������\n\n");
    printf("                                       >> ");
    scanf("%d %d %d %d %d", &ret.m_date.m_nYear, &ret.m_date.m_nMonth, &ret.m_date.m_nDay, &ret.m_date.m_nHour, &ret.m_date.m_nMinute);
    printf("                          ������ ���� �Է�\n           >>");

    ChangeScheduleByDateAndTime(pHead, ret); //��¥�� �ð� �����ٺ���
    system("cls");

}


//calendar
int GetLastDayByMonthAndYear(int nYear, int nMonth)
{
    int nLastDay;

    if (nMonth == 1 || //���������� 31���� ��
        nMonth == 3 ||
        nMonth == 5 ||
        nMonth == 7 ||
        nMonth == 8 ||
        nMonth == 10 ||
        nMonth == 12)
    {
        nLastDay = 31;
    }
    else if (nMonth == 4 ||  //���������� 30���� ��
        nMonth == 6 ||
        nMonth == 9 ||
        nMonth == 11)
    {
        nLastDay = 30;
    }

    if (nMonth == 2)
    {
        nLastDay = 28;
    }

    if (nMonth == 2 &&   //�����Ǻ�
        (nYear % 4) == 0 &&
        (nYear % 100 != 0) || (nYear % 400 == 0)) //4�� �������鼭 100���� �������� �ʰų� 400���� �������� �����̴� 

    {
        nLastDay = 29;
    }

    return nLastDay;
}

void DrawCalendar(SCHEDULE* pHead, DATE date)   //�޷�����Լ�
{
    char szBuf[STRING_MAX];

    int nYear;
    int nMonth;
    int nLastDay;
    int nTh;
    int nDay;
    int nDate;
    int nX;
    int nZ;
    int count = 0;

    nYear = date.m_nYear;
    nMonth = date.m_nMonth;
    nLastDay = GetLastDayByMonthAndYear(nYear, nMonth);

    /*
    if ( nMonth < 3 )
    {
       nYear = nYear - 1;
       nMonth = nMonth + 12;
    }
    */
    if (nMonth > 9)
        printf("                               ���������������������������������� %d��  %d�� ��������������������������������������\n", nYear, nMonth);
    else
        printf("                               ���������������������������������� %d��  %d��  ������������������������������������\n", nYear, nMonth);
    printf("                               ��%6s%6s%6s%6s%6s%6s%6s     ��\n", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat");

    nDate = 1, nX = 0, nZ = 0;

    while (nX <= 6)
    {
        nX = nX + 1;
        nTh = nYear / 100;
        nYear = nYear % 100;
        nDay = ((21 * nTh / 4) +
            (5 * nYear / 4) + (26 * (nMonth + 1) / 10) + nDate - 1) % 7;
        printf("                               ��");
        while (nZ < 7)
        {
            if (nX = 1 && nZ < nDay)
            {
                printf("%6s", " ");
            }
            else
            {
                DATE temp;
                temp = date;

                temp.m_nDay = nDate;

                if (CompareDate(date, temp) == 0)
                {
                    sprintf(szBuf, "[%d]", nDate);
                    printf("%6s", szBuf);
                }
                else if (GetSchedulePointerByDate(pHead, temp)
                    != NULL)
                {
                    sprintf(szBuf, "*%d", nDate);
                    printf("%6s", szBuf);
                }
                else
                {
                    count++;
                    printf("%6d", nDate);
                }

                if (nDate < nLastDay)
                {
                    nDate = nDate + 1;
                }
                else if (nDate >= nLastDay)
                {
                    break;
                }
            }

            nZ = nZ + 1;
        }
        if (nZ == 0)
            printf("��\n");
        else if (nZ == 1)
            printf("�� \n");
        else if (nZ == 2)
            printf("��\n");
        else if (nZ == 3)
            printf("                       ��\n");
        else if (nZ == 4)
            printf("                       �� \n");
        else if (nZ == 5)
            printf("                                                                      ��\n");
        else
            printf("     ��\n");

        if (nDate >= nLastDay)
        {
            break;
        }

        nZ = 0;
    }
    printf("                               ��                                               ��\n");
    printf("                               ��������������������������������������������������������������������������������������������������\n\n");

}


//date.c
int CompareDate(DATE target, DATE compare) //��¥�񱳹� ��¥���� �ڵ�
{
    int nTargetSum = 0;
    int nCompareSum = 0;

    if (target.m_nYear > compare.m_nYear) //���� �ذ� ���ϴ� �غ��� ũ�ٸ� -1�� ��ȯ
    {
        return -1;
    }
    else if (target.m_nYear < compare.m_nYear) //���� �ذ� ���ϴ� �غ��� �۴ٸ� +1�� ��ȯ
    {
        return 1;
    }

    if (target.m_nMonth > compare.m_nMonth) //���� ���� ���ϴ� �޺��� ũ�ٸ� -1�� ��ȯ
    {
        return -1;
    }
    else if (target.m_nMonth < compare.m_nMonth) //���� ���� ���ϴ� �޺��� �۴ٸ� +1�� ��ȯ
    {
        return 1;
    }

    if (target.m_nDay > compare.m_nDay) //���� ���� ���ϴ� ������ ũ�ٸ� -1�� ��ȯ
    {
        return -1;
    }
    else if (target.m_nDay < compare.m_nDay) //���� ���� ���ϴ� ������ �۴ٸ� +1�� ��ȯ
    {
        return 1;
    }

    return 0;
}

int CompareDateAndTime(DATE target, DATE compare)  //�ð� ��
{
    if (target.m_nYear > compare.m_nYear) //���� �ذ� ���ϴ� �غ��� ũ�ٸ� -1�� ��ȯ
    {
        return -1;
    }
    else if (target.m_nYear < compare.m_nYear) //���� �ذ� ���ϴ� �غ��� �۴ٸ� +1�� ��ȯ
    {
        return 1;
    }

    if (target.m_nMonth > compare.m_nMonth) //���� ���� ���ϴ� �޺��� ũ�ٸ� -1�� ��ȯ
    {
        return -1;
    }
    else if (target.m_nMonth < compare.m_nMonth) //���� ���� ���ϴ� �޺��� �۴ٸ� +1�� ��ȯ
    {
        return 1;
    }

    if (target.m_nDay > compare.m_nDay) //���� ���� ���ϴ� ������ ũ�ٸ� -1�� ��ȯ
    {
        return -1;
    }
    else if (target.m_nDay < compare.m_nDay) //���� ���� ���ϴ� ������ �۴ٸ� +1�� ��ȯ
    {
        return 1;
    }

    if (target.m_nHour > compare.m_nHour)  //���� �ð��� ���ϴ� �ð����� ũ�ٸ� -1�ð�
    {
        return -1;
    }
    else if (target.m_nHour < compare.m_nHour) //���� �ð��� ���ϴ� �ð����� �۴ٸ� -1�ð�
    {
        return 1;
    }
    else if (target.m_nMinute < compare.m_nMinute)
    {
        return -1;
    }

    return 0;
}

void PrintDate(DATE date) //��¥����Լ�

{
    printf("%d�� %d�� %d�� %d�� %d��\n", date.m_nYear, date.m_nMonth, date.m_nDay, date.m_nHour, date.m_nMinute);
}

DATE InputDate(void)  //��¥�Է�
{
    DATE ret;

    printf("�� : ");
    scanf("%d", &ret.m_nYear); //��

    printf("�� : ");
    scanf("%d", &ret.m_nMonth); //��

    printf("�� : ");
    scanf("%d", &ret.m_nDay);  //��

    printf("�� : ");
    scanf("%d", &ret.m_nHour); //��

    printf("�� : ");
    scanf("%d", &ret.m_nMinute); //��

    return ret;
}

DATE GetToday(void)
{
    DATE ret;
    time_t ltime;
    struct tm* today;

    time(&ltime);
    today = localtime(&ltime);

    ret.m_nYear = today->tm_year + 1900; //���� ��¥ �ڵ�
    ret.m_nMonth = today->tm_mon + 1;
    ret.m_nDay = today->tm_mday;

    ret.m_nHour = today->tm_hour;

    return ret;
}

void ModifyMonth(DATE* pDate, int nMonth) //�� �����Լ�
{
    if (nMonth > 0)
    {
        if (pDate->m_nMonth + nMonth > 12)
        {
            pDate->m_nMonth = pDate->m_nMonth + nMonth - 12;
            pDate->m_nYear = pDate->m_nYear + 1;
            return;
        }
    }

    else if (nMonth < 0)
    {
        if (pDate->m_nMonth + nMonth < 1)
        {
            pDate->m_nMonth = 12 + (nMonth + 1);
            pDate->m_nYear = pDate->m_nYear - 1;
            return;
        }
    }

    pDate->m_nMonth = pDate->m_nMonth + nMonth;
}

void ModifyDay(DATE* pDate, int nDay) //�� �����Լ�
{
    int nMaxDay = GetLastDayByMonthAndYear(pDate->m_nYear, pDate->m_nMonth);
    int nPrevMaxDay = GetLastDayByMonthAndYear(pDate->m_nYear, pDate->m_nMonth - 1);

    if (nDay > 0)
    {
        if (pDate->m_nDay + nDay > nMaxDay)
        {
            pDate->m_nDay = 1;
            ModifyMonth(pDate, 1);
            return;
        }
    }

    else if (nDay < 0)
    {
        if (pDate->m_nDay + nDay < 1)
        {
            pDate->m_nDay = nPrevMaxDay;
            ModifyMonth(pDate, -1);
            return;
        }
    }

    pDate->m_nDay = pDate->m_nDay + nDay;
}


//schedule.c
SCHEDULE* InitScheduleHead(void)   //������ �ʱ�ȭ
{
    SCHEDULE* pRet;

    pRet = (SCHEDULE*)malloc(sizeof(SCHEDULE));
    pRet->next = NULL;

    return pRet;
}

SCHEDULE* GetSchedulePointerByDate(SCHEDULE* pHead, DATE date)
{
    SCHEDULE* pFind = pHead->next;

    while (pFind != NULL)
    {
        if (CompareDate(pFind->m_date, date) == 0)
        {
            return pFind;
        }

        pFind = pFind->next;
    }

    return NULL;
}

SCHEDULE* GetSchedulePointerByDateAndTime(SCHEDULE* pHead, DATE date) //��¥���� ������������ ����
{
    SCHEDULE* pFind = pHead->next;

    while (pFind != NULL)
    {
        if (CompareDateAndTime(pFind->m_date, date) == 0)
        {
            return pFind;
        }

        pFind = pFind->next;
    }

    return NULL;
}

void AddScheduleNode(SCHEDULE* pHead, SCHEDULE schedule) //������ �߰��Լ�
{
    SCHEDULE* pPrev = pHead;
    SCHEDULE* pFind = pHead->next;
    SCHEDULE* pNew;

    pNew = (SCHEDULE*)malloc(sizeof(SCHEDULE));  //�������� �޸� �Ҵ�
    *pNew = schedule;

    while (pFind != NULL)  //�����Ͱ� NULL�� �ƴҶ� ��� �ݺ�
    {
        if (CompareDateAndTime(schedule.m_date, pFind->m_date) == -1) //ã�� ���� ������ �Էµ� ���� ������ ����
        {
            pPrev = pPrev->next; //�������� ���� �ּ� ����
            pFind = pFind->next; //ã�³��� ���� �ּ� ����
        }
        else
        {
            break;
        }
    }

    pPrev->next = pNew; //���� ����� ���� ��带 �� ��忡 ����
    pNew->next = pFind; //�� ��忡 ���� ��带 ã�� ��忡 ����
}

void DeleteScheduleByDateAndTime(SCHEDULE* pHead, DATE date) //������ �����Լ�
{
    SCHEDULE* pPrev = pHead;
    SCHEDULE* pFind = pHead->next;
    SCHEDULE* pTemp;

    while (pFind != NULL) //�����Ͱ� NULL�� �ƴҶ� ��� �ݺ�
    {
        if (CompareDateAndTime(pFind->m_date, date) == 0) //ã�� ���� ������ �Էµ� ���� ������ ����
        {
            pTemp = pFind;
            pPrev->next = pFind->next; // ���� ����� ���� ��忡 ã�� ����� ���� ��带 ����
            free(pTemp); //�Ҵ�� �޸� ����
            break;
        }

        pFind = pFind->next;  //ã�³��� ���� �ּ� ����
        pPrev = pPrev->next; //�������� ���� �ּ� ����
    }
}

void ChangeScheduleByDateAndTime(SCHEDULE* pHead, SCHEDULE schedule) //������ �����Լ�
{
    SCHEDULE* pFind = pHead->next;
    SCHEDULE* pTemp;

    while (pFind != NULL)
    {
        if (CompareDateAndTime(pFind->m_date, schedule.m_date) == 0) //ã�� ���� ������ �Էµ� ���� ������ ����
        {
            pTemp = pFind;
            scanf("%s", pTemp->m_szText); // �Է¹޾� m_szText�� ����
            break;
        }
    }

}

void KillAllScheduleNode(SCHEDULE* pHead) //������â ����� �Լ�
{
    SCHEDULE* pFind = pHead->next;
    SCHEDULE* pPrev = pHead;

    while (pFind != NULL)
    {
        pFind = pPrev->next;

        free(pPrev);

        pPrev = pFind;
        pFind = pFind->next;
    }
}

void PrintAllSchedule(SCHEDULE* pHead) //������ ����Լ�
{
    SCHEDULE* pFind = pHead->next;

    while (pFind != NULL)
    {
        printf("%s\n", pFind->m_szText);
        PrintDate(pFind->m_date);

        pFind = pFind->next;
    }
}

void LoadScheduleFromFile(SCHEDULE* pHead, char szFileName[]) //���������� �����Լ�
{
    SCHEDULE news;
    FILE* fp;
    int nCnt = 0;
    char szBuf[STRING_MAX];

    fp = fopen(szFileName, "r"); //�б��������� ���Ͽ���

    if (fp == NULL) //������ ������ ������ ��
    {
        fp = fopen(szFileName, "w"); //������������ ���Ͽ��� 
        fclose(fp);

        return;
    }

    while (!feof(fp)) //������ ���������� while���� ������ 
    {
        fscanf(fp, "%s", szBuf);

        switch (nCnt)
        {
        case 0:
            news.m_date.m_nYear = atoi(szBuf);
            break;

        case 1:
            news.m_date.m_nMonth = atoi(szBuf);
            break;

        case 2:
            news.m_date.m_nDay = atoi(szBuf);
            break;

        case 3:
            news.m_date.m_nHour = atoi(szBuf);
            break;
        case 4:
            news.m_date.m_nMinute = atoi(szBuf);
            break;

        case 5:
            strcpy(news.m_szText, szBuf);
            break;
        }

        nCnt++;

        if (nCnt == 6)
        {
            AddScheduleNode(pHead, news);
            nCnt = 0;
        }
    }

    fclose(fp);
}

void SaveScheduleToFile(SCHEDULE* pHead, char szFileName[]) //���� �����Լ�
{
    FILE* fp;
    SCHEDULE* pFind = pHead->next;

    fp = fopen(szFileName, "w"); //FileName�� ���� ���(w)�� ����

    while (pFind != NULL)
    {
        fprintf(fp, "%d %d %d %d %d %s\n", // ������ �����Ͽ� ������ ���ڿ��� ���Ͽ� ����

            pFind->m_date.m_nYear, //ȭ��ǥ �����ڷ� ����ü ����� �����Ͽ� �� �Ҵ�
            pFind->m_date.m_nMonth,
            pFind->m_date.m_nDay,
            pFind->m_date.m_nHour,
            pFind->m_date.m_nMinute,
            pFind->m_szText
        );

        pFind = pFind->next;
    }

    fclose(fp); // ���� ������ �ݱ�
}

SCHEDULE InputSchedule(SCHEDULE* pHead) //�������Է�
{
    SCHEDULE ret;
    //DATE current;
    current = GetToday();

    system("cls");
    DrawCalendar(pHead, current);
    ShowAllScheduleByDay(pHead, current);

    while (TRUE)
    {
        printf("                                   ����������������������������������������������������������������������������������\n");
        printf("                                   ��                                       ��\n");
        printf("                                   �� ��, ��, ��, �ð�, ��, ���� ������ �Է¦�\n");
        printf("                                   ��  (����)2021 6 7 13 55 ��ǥ            ��\n");
        printf("                                   ��                                       ��\n");
        printf("                                   ����������������������������������������������������������������������������������\n\n");
        printf("                                    >> ");

        scanf("%d %d %d %d %d %s",
            &ret.m_date.m_nYear,
            &ret.m_date.m_nMonth,
            &ret.m_date.m_nDay,
            &ret.m_date.m_nHour,
            &ret.m_date.m_nMinute,
            ret.m_szText);  //��, ��, ��, �ð�, ���� �Է�

        if (GetSchedulePointerByDateAndTime(pHead, ret.m_date) == NULL) //����� �ð��� ���� �ð��� �Է½� break
        {
            break;
        }

        printf("                                    ��������������������������������������������������������������������������������\n");
        printf("                                    ��                                      ��\n");
        printf("                                    ��  �̹� ���� �ð��� ����Ǿ� �ֽ��ϴ�  ��\n");
        printf("                                    ��                                      ��\n");
        printf("                                    ��������������������������������������������������������������������������������\n\n");

    }
    system("cls");
    return ret;
}