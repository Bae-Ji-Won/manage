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

typedef struct _DATE  //掘褻羹檜葷
{
    int m_nYear;  //濠猿⑽ 詹幗檜葷
    int m_nMonth;
    int m_nDay;
    int m_nHour;
    int m_nMinute; //掘褻羹 滌蘆
}DATE;

void PrintDate(DATE date);   //Date轎溘л熱
void ModifyMonth(DATE* pDate, int nMonth); //殖 熱薑л熱
void ModifyDay(DATE* pDate, int nDay); //橾 熱薑л熱

int CompareDate(DATE target, DATE compare); //陳瞼綠掖
int CompareDateAndTime(DATE target, DATE compare); //陳瞼諦 衛除 綠掖 


DATE InputDate(void); //陳瞼殮溘
DATE GetToday(void); //螃棺殮溘
DATE current;  //⑷營

typedef struct _SCHEDULE //掘褻羹 檜葷
{
    DATE m_date;
    char m_szText[STRING_MAX];

    struct _SCHEDULE* next;
}SCHEDULE;       //掘褻羹 滌蘆

void KillAllScheduleNode(SCHEDULE* pHead);  //蝶馨還璽 雖辦朝 л熱
void AddScheduleNode(SCHEDULE* pHead, SCHEDULE schedule);
void PrintAllSchedule(SCHEDULE* pHead); //蝶馨還璽 轎溘л熱
void PrintScheduleByDate(SCHEDULE* pHead, DATE date);
void DeleteScheduleByDateAndTime(SCHEDULE* pHead, DATE date); //蝶馨還 陳瞼諦 衛除 餉薯л熱
void ChangeScheduleByDateAndTime(SCHEDULE* pHead, SCHEDULE schedule); //蝶馨還 陳瞼諦 衛除 熱薑л熱

void LoadScheduleFromFile(SCHEDULE* pHead, char szFileName[]);  //だ橾煎睡攪 蝶馨還 煎註 л熱
void SaveScheduleToFile(SCHEDULE* pHead, char szFileName[]); //蝶馨還 盪濰 だ橾 л熱

SCHEDULE* InitScheduleHead(void);
SCHEDULE* GetSchedulePointerByDate(SCHEDULE* pHead, DATE date);
SCHEDULE* GetSchedulePointerByDateAndTime(SCHEDULE* pHead, DATE date);
SCHEDULE InputSchedule(SCHEDULE* pHead);

void DrawCalendar(SCHEDULE* pHead, DATE date);  //殖溘轎溘л熱
void ShowAllScheduleByDay(SCHEDULE* pHead, DATE date);//陳瞼滌 蹺陛脹 蝶馨還 爾罹輿朝 л熱

int GetLastDayByMonthAndYear(int nYear, int nMonth);
void DrawCalendar(SCHEDULE* pHead, DATE date); //殖溘轎溘л熱









//main
enum MENU
{
    PREV_MONTH = 'q', //檜瞪殖
    NEXT_MONTH = 'w', //棻擠殖
    PREV_DAY = 'e',   //檜瞪陳
    NEXT_DAY = 'r', //棻擠陳
    ADD_SCHEDULE = '1', //蝶馨還蹺陛
    DELETE_SCHEDULE = '2', //蝶馨還餉薯
    CHANGE_SCHEDULE = '3', //蝶馨還熱薑
    QUIT = '4'  //謙猿
};

void ShowAllScheduleByDay(SCHEDULE* pHead, DATE date); //蹺陛脹 蝶馨還 爾罹輿朝 л熱
void DeleteSchedule(SCHEDULE* pHead); //蝶馨還 餉薯л熱
void AddSchedule(SCHEDULE* pHead); //蝶馨還 蹺陛л熱
void Changeschedule(SCHEDULE* pHead);  //蝶馨還 熱薑л熱


char GetSelectedMenu(void);

void calen()
{
    SCHEDULE* pHead;
    //DATE current;

    pHead = InitScheduleHead();
    LoadScheduleFromFile(pHead, FILENAME);

    current = GetToday();  //螃棺陳瞼蒂 ⑷營煎 渠殮
    system("cls");

    while (TRUE)
    {
        char ch;

        DrawCalendar(pHead, current);//⑷營陳瞼煎 殖溘轎溘
        ShowAllScheduleByDay(pHead, current);//⑷營陳瞼煎 橾薑轎溘

        ch = GetSelectedMenu();

        if (ch == QUIT)
        {
            break;
        }

        switch (ch)
        {
        case PREV_MONTH:
            ModifyMonth(&current, -1);  //⑷營 month -1
            break;

        case NEXT_MONTH:
            ModifyMonth(&current, 1);  //⑷營 month +1
            break;

        case PREV_DAY:
            ModifyDay(&current, -1);  //⑷營 day-1
            break;

        case NEXT_DAY:
            ModifyDay(&current, 1);  //⑷營 day+1
            break;

        case ADD_SCHEDULE:
            AddSchedule(pHead);  //蝶馨還 蹺陛
            break;

        case DELETE_SCHEDULE:
            DeleteSchedule(pHead);  //蝶馨還 餉薯
            break;

        case CHANGE_SCHEDULE:
            Changeschedule(pHead);  //蝶馨還 熱薑
            break;
        }

        system("cls");
    }


    SaveScheduleToFile(pHead, FILENAME); //蝶馨還だ橾 盪濰л熱
    KillAllScheduleNode(pHead);//蝶馨還璽 雖辦朝 л熱
}

char GetSelectedMenu(void)
{
    char ch;

    printf("                                       忙式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("                                       弛          MENU         弛\n");
    printf("                                       弛  q : 檜瞪 殖煎 剩晦晦 弛\n");
    printf("                                       弛  w : 棻擠 殖煎 剩晦晦 弛\n");
    printf("                                       弛  e : 檜瞪 陳煎 剩晦晦 弛\n");
    printf("                                       弛  r : 棻擠 陳煎 剩晦晦 弛\n");
    printf("                                       弛  1 : 蝶馨鍰 蹺陛 ж晦 弛\n");
    printf("                                       弛  2 : 蝶馨鍰 餉薯 ж晦 弛\n");
    printf("                                       弛  3 : 蝶馨鍰 熱薑 ж晦 弛\n");
    printf("                                       弛  4 : Щ煎斜極 謙猿    弛\n");
    printf("                                       戌式式式式式式式式式式式式式式式式式式式式式式式戎\n");
    printf("                     詭景蒂 殮溘ж衛螃 >> ");
    ch = getchar();
    return ch;
}

void ShowAllScheduleByDay(SCHEDULE* pHead, DATE date) // 摹鷗и 陳 橾薑 衛除 塽 頂辨
{
    SCHEDULE* pFind = pHead->next;

    printf("\n");
    printf("                                         *  %d/%d/%d曖 橾薑 *\n", date.m_nYear,
        date.m_nMonth,
        date.m_nDay);

    printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n");

    while (pFind != NULL)
    {
        if (CompareDate(pFind->m_date, date) == 0)//瓊朝陳婁 盪濰脹陳檜 偽戲賊 
        {
            printf("%d衛 %d碟 : %s\n",
                pFind->m_date.m_nHour,//盪濰脹 衛除轎溘
                pFind->m_date.m_nMinute, //盪濰脹 碟轎溘
                pFind->m_szText); //盪濰脹 頂辨轎溘

        }

        pFind = pFind->next;
    }

    printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n\n");
}

void DeleteSchedule(SCHEDULE* pHead)  //蝶馨還 餉薯
{
    DATE date;
    DATE current;
    current = GetToday();

    system("cls");
    DrawCalendar(pHead, current); //⑷營晦遽戲煎 殖溘轎溘
    ShowAllScheduleByDay(pHead, current); //⑷營晦遽戲煎 蝶馨還 轎溘
    printf("                                       忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("                                       弛                                      弛\n");
    printf("                                       弛  喇, 錯, 橾, 衛除, 碟 牖戲煎 殮溘    弛\n");
    printf("                                       弛  (蕨衛)2021 6 7 13 55                弛\n");
    printf("                                       弛                                      弛\n");
    printf("                                       戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n\n");
    printf("                                       >> ");

    scanf("%d %d %d %d",
        &date.m_nYear,
        &date.m_nMonth,
        &date.m_nDay,
        &date.m_nHour,
        &date.m_nMinute); //喇,錯,橾,衛除 殮溘

    DeleteScheduleByDateAndTime(pHead, date);  //蝶馨還 陳瞼諦 衛除 餉薯л熱 
    system("cls");
}

void AddSchedule(SCHEDULE* pHead)  //蝶馨還 蹺陛
{
    SCHEDULE schedule;

    schedule = InputSchedule(pHead);

    AddScheduleNode(pHead, schedule);
}

void Changeschedule(SCHEDULE* pHead)   //蝶馨還 熱薑
{
    SCHEDULE ret;
    DATE current;
    current = GetToday();

    system("cls");
    DrawCalendar(pHead, current);
    ShowAllScheduleByDay(pHead, current);

    printf("                                       忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("                                       弛                                      弛\n");
    printf("                                       弛  喇, 錯, 橾, 衛除, 碟 牖戲煎 殮溘    弛\n");
    printf("                                       弛  (蕨衛)2021 6 7 13 55                弛\n");
    printf("                                       弛                                      弛\n");
    printf("                                       戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n\n");
    printf("                                       >> ");
    scanf("%d %d %d %d %d", &ret.m_date.m_nYear, &ret.m_date.m_nMonth, &ret.m_date.m_nDay, &ret.m_date.m_nHour, &ret.m_date.m_nMinute);
    printf("                          熱薑й 橾薑 殮溘\n           >>");

    ChangeScheduleByDateAndTime(pHead, ret); //陳瞼諦 衛除 蝶馨還滲唳
    system("cls");

}


//calendar
int GetLastDayByMonthAndYear(int nYear, int nMonth)
{
    int nLastDay;

    if (nMonth == 1 || //葆雖虞陳檜 31橾檣 殖
        nMonth == 3 ||
        nMonth == 5 ||
        nMonth == 7 ||
        nMonth == 8 ||
        nMonth == 10 ||
        nMonth == 12)
    {
        nLastDay = 31;
    }
    else if (nMonth == 4 ||  //葆雖虞陳檜 30橾檣 殖
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

    if (nMonth == 2 &&   //彌喇っ滌
        (nYear % 4) == 0 &&
        (nYear % 100 != 0) || (nYear % 400 == 0)) //4煎 雲橫雖賊憮 100戲煎 釭散雖雖 彊剪釭 400戲煎 雲橫韓陽 彌喇檜棻 

    {
        nLastDay = 29;
    }

    return nLastDay;
}

void DrawCalendar(SCHEDULE* pHead, DATE date)   //殖溘轎溘л熱
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
        printf("                               忙式式式式式式式式式式式式式式式式 %d喇  %d錯 式式式式式式式式式式式式式式式式式式忖\n", nYear, nMonth);
    else
        printf("                               忙式式式式式式式式式式式式式式式式 %d喇  %d錯  式式式式式式式式式式式式式式式式式忖\n", nYear, nMonth);
    printf("                               弛%6s%6s%6s%6s%6s%6s%6s     弛\n", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat");

    nDate = 1, nX = 0, nZ = 0;

    while (nX <= 6)
    {
        nX = nX + 1;
        nTh = nYear / 100;
        nYear = nYear % 100;
        nDay = ((21 * nTh / 4) +
            (5 * nYear / 4) + (26 * (nMonth + 1) / 10) + nDate - 1) % 7;
        printf("                               弛");
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
            printf("弛\n");
        else if (nZ == 1)
            printf("弛 \n");
        else if (nZ == 2)
            printf("弛\n");
        else if (nZ == 3)
            printf("                       弛\n");
        else if (nZ == 4)
            printf("                       弛 \n");
        else if (nZ == 5)
            printf("                                                                      弛\n");
        else
            printf("     弛\n");

        if (nDate >= nLastDay)
        {
            break;
        }

        nZ = 0;
    }
    printf("                               弛                                               弛\n");
    printf("                               戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n\n");

}


//date.c
int CompareDate(DATE target, DATE compare) //陳瞼綠掖塽 陳瞼撲薑 囀萄
{
    int nTargetSum = 0;
    int nCompareSum = 0;

    if (target.m_nYear > compare.m_nYear) //⑷營 п陛 錳ж朝 п爾棻 觼棻賊 -1喇 奩��
    {
        return -1;
    }
    else if (target.m_nYear < compare.m_nYear) //⑷營 п陛 錳ж朝 п爾棻 濛棻賊 +1喇 奩��
    {
        return 1;
    }

    if (target.m_nMonth > compare.m_nMonth) //⑷營 殖檜 錳ж朝 殖爾棻 觼棻賊 -1殖 奩��
    {
        return -1;
    }
    else if (target.m_nMonth < compare.m_nMonth) //⑷營 殖檜 錳ж朝 殖爾棻 濛棻賊 +1殖 奩��
    {
        return 1;
    }

    if (target.m_nDay > compare.m_nDay) //⑷營 陳檜 錳ж朝 陳爾棻 觼棻賊 -1橾 奩��
    {
        return -1;
    }
    else if (target.m_nDay < compare.m_nDay) //⑷營 陳檜 錳ж朝 陳爾棻 濛棻賊 +1橾 奩��
    {
        return 1;
    }

    return 0;
}

int CompareDateAndTime(DATE target, DATE compare)  //衛除 綠掖
{
    if (target.m_nYear > compare.m_nYear) //⑷營 п陛 錳ж朝 п爾棻 觼棻賊 -1喇 奩��
    {
        return -1;
    }
    else if (target.m_nYear < compare.m_nYear) //⑷營 п陛 錳ж朝 п爾棻 濛棻賊 +1喇 奩��
    {
        return 1;
    }

    if (target.m_nMonth > compare.m_nMonth) //⑷營 殖檜 錳ж朝 殖爾棻 觼棻賊 -1殖 奩��
    {
        return -1;
    }
    else if (target.m_nMonth < compare.m_nMonth) //⑷營 殖檜 錳ж朝 殖爾棻 濛棻賊 +1殖 奩��
    {
        return 1;
    }

    if (target.m_nDay > compare.m_nDay) //⑷營 陳檜 錳ж朝 陳爾棻 觼棻賊 -1橾 奩��
    {
        return -1;
    }
    else if (target.m_nDay < compare.m_nDay) //⑷營 陳檜 錳ж朝 陳爾棻 濛棻賊 +1橾 奩��
    {
        return 1;
    }

    if (target.m_nHour > compare.m_nHour)  //⑷營 衛除檜 錳ж朝 衛除爾棻 觼棻賊 -1衛除
    {
        return -1;
    }
    else if (target.m_nHour < compare.m_nHour) //⑷營 衛除檜 錳ж朝 衛除爾棻 濛棻賊 -1衛除
    {
        return 1;
    }
    else if (target.m_nMinute < compare.m_nMinute)
    {
        return -1;
    }

    return 0;
}

void PrintDate(DATE date) //陳瞼轎溘л熱

{
    printf("%d喇 %d錯 %d橾 %d衛 %d碟\n", date.m_nYear, date.m_nMonth, date.m_nDay, date.m_nHour, date.m_nMinute);
}

DATE InputDate(void)  //陳瞼殮溘
{
    DATE ret;

    printf("喇 : ");
    scanf("%d", &ret.m_nYear); //喇

    printf("錯 : ");
    scanf("%d", &ret.m_nMonth); //錯

    printf("橾 : ");
    scanf("%d", &ret.m_nDay);  //橾

    printf("衛 : ");
    scanf("%d", &ret.m_nHour); //衛

    printf("碟 : ");
    scanf("%d", &ret.m_nMinute); //碟

    return ret;
}

DATE GetToday(void)
{
    DATE ret;
    time_t ltime;
    struct tm* today;

    time(&ltime);
    today = localtime(&ltime);

    ret.m_nYear = today->tm_year + 1900; //⑷營 陳瞼 囀萄
    ret.m_nMonth = today->tm_mon + 1;
    ret.m_nDay = today->tm_mday;

    ret.m_nHour = today->tm_hour;

    return ret;
}

void ModifyMonth(DATE* pDate, int nMonth) //殖 熱薑л熱
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

void ModifyDay(DATE* pDate, int nDay) //橾 熱薑л熱
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
SCHEDULE* InitScheduleHead(void)   //蝶馨還 蟾晦��
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

SCHEDULE* GetSchedulePointerByDateAndTime(SCHEDULE* pHead, DATE date) //陳瞼滌煎 蝶馨還ん檣攪 渠殮
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

void AddScheduleNode(SCHEDULE* pHead, SCHEDULE schedule) //蝶馨還 蹺陛л熱
{
    SCHEDULE* pPrev = pHead;
    SCHEDULE* pFind = pHead->next;
    SCHEDULE* pNew;

    pNew = (SCHEDULE*)malloc(sizeof(SCHEDULE));  //翕瞳戲煎 詭賅葬 й渡
    *pNew = schedule;

    while (pFind != NULL)  //ん檣攪陛 NULL檜 嬴棍陽 啗樓 奩犒
    {
        if (CompareDateAndTime(schedule.m_date, pFind->m_date) == -1) //瓊朝 陳婁 蝶馨還 殮溘脹 陳檜 偽戲賊 褒ч
        {
            pPrev = pPrev->next; //檜瞪陳縑 棻擠 輿模 盪濰
            pFind = pFind->next; //瓊朝陳縑 棻擠 輿模 盪濰
        }
        else
        {
            break;
        }
    }

    pPrev->next = pNew; //檜瞪 喻萄曖 棻擠 喻萄蒂 億 喻萄縑 雖薑
    pNew->next = pFind; //億 喻萄縑 棻擠 喻萄蒂 瓊朝 喻萄縑 雖薑
}

void DeleteScheduleByDateAndTime(SCHEDULE* pHead, DATE date) //蝶馨還 餉薯л熱
{
    SCHEDULE* pPrev = pHead;
    SCHEDULE* pFind = pHead->next;
    SCHEDULE* pTemp;

    while (pFind != NULL) //ん檣攪陛 NULL檜 嬴棍陽 啗樓 奩犒
    {
        if (CompareDateAndTime(pFind->m_date, date) == 0) //瓊朝 陳婁 蝶馨還 殮溘脹 陳檜 偽戲賊 褒ч
        {
            pTemp = pFind;
            pPrev->next = pFind->next; // 檜瞪 喻萄曖 棻擠 喻萄縑 瓊朝 喻萄曖 棻擠 喻萄蒂 雖薑
            free(pTemp); //й渡脹 詭賅葬 餉薯
            break;
        }

        pFind = pFind->next;  //瓊朝陳縑 棻擠 輿模 盪濰
        pPrev = pPrev->next; //檜瞪陳縑 棻擠 輿模 盪濰
    }
}

void ChangeScheduleByDateAndTime(SCHEDULE* pHead, SCHEDULE schedule) //蝶馨還 熱薑л熱
{
    SCHEDULE* pFind = pHead->next;
    SCHEDULE* pTemp;

    while (pFind != NULL)
    {
        if (CompareDateAndTime(pFind->m_date, schedule.m_date) == 0) //瓊朝 陳婁 蝶馨還 殮溘脹 陳檜 偽戲賊 褒ч
        {
            pTemp = pFind;
            scanf("%s", pTemp->m_szText); // 殮溘嫡嬴 m_szText縑 盪濰
            break;
        }
    }

}

void KillAllScheduleNode(SCHEDULE* pHead) //蝶馨還璽 雖辦朝 л熱
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

void PrintAllSchedule(SCHEDULE* pHead) //蝶馨還 轎溘л熱
{
    SCHEDULE* pFind = pHead->next;

    while (pFind != NULL)
    {
        printf("%s\n", pFind->m_szText);
        PrintDate(pFind->m_date);

        pFind = pFind->next;
    }
}

void LoadScheduleFromFile(SCHEDULE* pHead, char szFileName[]) //蝶馨還だ橾 螃Ъл熱
{
    SCHEDULE news;
    FILE* fp;
    int nCnt = 0;
    char szBuf[STRING_MAX];

    fp = fopen(szFileName, "r"); //檗晦瞪辨戲煎 だ橾翮晦

    if (fp == NULL) //だ橾檜 翮葬雖 彊戲賊 霤
    {
        fp = fopen(szFileName, "w"); //噙晦瞪辨戲煎 だ橾翮晦 
        fclose(fp);

        return;
    }

    while (!feof(fp)) //だ橾檜 部陳陽梱雖 while僥擊 給萼棻 
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

void SaveScheduleToFile(SCHEDULE* pHead, char szFileName[]) //だ橾 盪濰л熱
{
    FILE* fp;
    SCHEDULE* pFind = pHead->next;

    fp = fopen(szFileName, "w"); //FileName擊 噙晦 賅萄(w)煎 翮晦

    while (pFind != NULL)
    {
        fprintf(fp, "%d %d %d %d %d %s\n", // 憮衝擊 雖薑ж罹 薑熱諦 僥濠翮擊 だ橾縑 盪濰

            pFind->m_date.m_nYear, //�香嚂� 翱骯濠煎 掘褻羹 詹幗縑 蕾斬ж罹 高 й渡
            pFind->m_date.m_nMonth,
            pFind->m_date.m_nDay,
            pFind->m_date.m_nHour,
            pFind->m_date.m_nMinute,
            pFind->m_szText
        );

        pFind = pFind->next;
    }

    fclose(fp); // だ橾 ん檣攪 殘晦
}

SCHEDULE InputSchedule(SCHEDULE* pHead) //蝶馨還殮溘
{
    SCHEDULE ret;
    //DATE current;
    current = GetToday();

    system("cls");
    DrawCalendar(pHead, current);
    ShowAllScheduleByDay(pHead, current);

    while (TRUE)
    {
        printf("                                   忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("                                   弛                                       弛\n");
        printf("                                   弛 喇, 錯, 橾, 衛除, 碟, 橾薑 牖戲煎 殮溘弛\n");
        printf("                                   弛  (蕨衛)2021 6 7 13 55 嫦ル            弛\n");
        printf("                                   弛                                       弛\n");
        printf("                                   戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n\n");
        printf("                                    >> ");

        scanf("%d %d %d %d %d %s",
            &ret.m_date.m_nYear,
            &ret.m_date.m_nMonth,
            &ret.m_date.m_nDay,
            &ret.m_date.m_nHour,
            &ret.m_date.m_nMinute,
            ret.m_szText);  //喇, 錯, 橾, 衛除, 橾薑 殮溘

        if (GetSchedulePointerByDateAndTime(pHead, ret.m_date) == NULL) //盪濰脹 衛除縑 偽擎 衛除渠 殮溘衛 break
        {
            break;
        }

        printf("                                    忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("                                    弛                                      弛\n");
        printf("                                    弛  檜嘐 偽擎 衛除縑 盪濰腎橫 氈蝗棲棻  弛\n");
        printf("                                    弛                                      弛\n");
        printf("                                    戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n\n");

    }
    system("cls");
    return ret;
}