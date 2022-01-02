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

typedef struct _DATE  //구조체이름
{
    int m_nYear;  //자료형 멤버이름
    int m_nMonth;
    int m_nDay;
    int m_nHour;
    int m_nMinute; //구조체 별칭
}DATE;

void PrintDate(DATE date);   //Date출력함수
void ModifyMonth(DATE* pDate, int nMonth); //달 수정함수
void ModifyDay(DATE* pDate, int nDay); //일 수정함수

int CompareDate(DATE target, DATE compare); //날짜비교
int CompareDateAndTime(DATE target, DATE compare); //날짜와 시간 비교 


DATE InputDate(void); //날짜입력
DATE GetToday(void); //오늘입력
DATE current;  //현재

typedef struct _SCHEDULE //구조체 이름
{
    DATE m_date;
    char m_szText[STRING_MAX];

    struct _SCHEDULE* next;
}SCHEDULE;       //구조체 별칭

void KillAllScheduleNode(SCHEDULE* pHead);  //스케줄창 지우는 함수
void AddScheduleNode(SCHEDULE* pHead, SCHEDULE schedule);
void PrintAllSchedule(SCHEDULE* pHead); //스케줄창 출력함수
void PrintScheduleByDate(SCHEDULE* pHead, DATE date);
void DeleteScheduleByDateAndTime(SCHEDULE* pHead, DATE date); //스케줄 날짜와 시간 삭제함수
void ChangeScheduleByDateAndTime(SCHEDULE* pHead, SCHEDULE schedule); //스케줄 날짜와 시간 수정함수

void LoadScheduleFromFile(SCHEDULE* pHead, char szFileName[]);  //파일로부터 스케줄 로딩 함수
void SaveScheduleToFile(SCHEDULE* pHead, char szFileName[]); //스케줄 저장 파일 함수

SCHEDULE* InitScheduleHead(void);
SCHEDULE* GetSchedulePointerByDate(SCHEDULE* pHead, DATE date);
SCHEDULE* GetSchedulePointerByDateAndTime(SCHEDULE* pHead, DATE date);
SCHEDULE InputSchedule(SCHEDULE* pHead);

void DrawCalendar(SCHEDULE* pHead, DATE date);  //달력출력함수
void ShowAllScheduleByDay(SCHEDULE* pHead, DATE date);//날짜별 추가된 스케줄 보여주는 함수

int GetLastDayByMonthAndYear(int nYear, int nMonth);
void DrawCalendar(SCHEDULE* pHead, DATE date); //달력출력함수









//main
enum MENU
{
    PREV_MONTH = 'q', //이전달
    NEXT_MONTH = 'w', //다음달
    PREV_DAY = 'e',   //이전날
    NEXT_DAY = 'r', //다음날
    ADD_SCHEDULE = '1', //스케줄추가
    DELETE_SCHEDULE = '2', //스케줄삭제
    CHANGE_SCHEDULE = '3', //스케줄수정
    QUIT = '4'  //종료
};

void ShowAllScheduleByDay(SCHEDULE* pHead, DATE date); //추가된 스케줄 보여주는 함수
void DeleteSchedule(SCHEDULE* pHead); //스케줄 삭제함수
void AddSchedule(SCHEDULE* pHead); //스케줄 추가함수
void Changeschedule(SCHEDULE* pHead);  //스케줄 수정함수


char GetSelectedMenu(void);

void calen()
{
    SCHEDULE* pHead;
    //DATE current;

    pHead = InitScheduleHead();
    LoadScheduleFromFile(pHead, FILENAME);

    current = GetToday();  //오늘날짜를 현재로 대입
    system("cls");

    while (TRUE)
    {
        char ch;

        DrawCalendar(pHead, current);//현재날짜로 달력출력
        ShowAllScheduleByDay(pHead, current);//현재날짜로 일정출력

        ch = GetSelectedMenu();

        if (ch == QUIT)
        {
            break;
        }

        switch (ch)
        {
        case PREV_MONTH:
            ModifyMonth(&current, -1);  //현재 month -1
            break;

        case NEXT_MONTH:
            ModifyMonth(&current, 1);  //현재 month +1
            break;

        case PREV_DAY:
            ModifyDay(&current, -1);  //현재 day-1
            break;

        case NEXT_DAY:
            ModifyDay(&current, 1);  //현재 day+1
            break;

        case ADD_SCHEDULE:
            AddSchedule(pHead);  //스케줄 추가
            break;

        case DELETE_SCHEDULE:
            DeleteSchedule(pHead);  //스케줄 삭제
            break;

        case CHANGE_SCHEDULE:
            Changeschedule(pHead);  //스케줄 수정
            break;
        }

        system("cls");
    }


    SaveScheduleToFile(pHead, FILENAME); //스케줄파일 저장함수
    KillAllScheduleNode(pHead);//스케줄창 지우는 함수
}

char GetSelectedMenu(void)
{
    char ch;

    printf("                                       ┌───────────────────────┐\n");
    printf("                                       │          MENU         │\n");
    printf("                                       │  q : 이전 달로 넘기기 │\n");
    printf("                                       │  w : 다음 달로 넘기기 │\n");
    printf("                                       │  e : 이전 날로 넘기기 │\n");
    printf("                                       │  r : 다음 날로 넘기기 │\n");
    printf("                                       │  1 : 스케쥴 추가 하기 │\n");
    printf("                                       │  2 : 스케쥴 삭제 하기 │\n");
    printf("                                       │  3 : 스케쥴 수정 하기 │\n");
    printf("                                       │  4 : 프로그램 종료    │\n");
    printf("                                       └───────────────────────┘\n");
    printf("                     메뉴를 입력하시오 >> ");
    ch = getchar();
    return ch;
}

void ShowAllScheduleByDay(SCHEDULE* pHead, DATE date) // 선택한 날 일정 시간 및 내용
{
    SCHEDULE* pFind = pHead->next;

    printf("\n");
    printf("                                         *  %d/%d/%d의 일정 *\n", date.m_nYear,
        date.m_nMonth,
        date.m_nDay);

    printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

    while (pFind != NULL)
    {
        if (CompareDate(pFind->m_date, date) == 0)//찾는날과 저장된날이 같으면 
        {
            printf("%d시 %d분 : %s\n",
                pFind->m_date.m_nHour,//저장된 시간출력
                pFind->m_date.m_nMinute, //저장된 분출력
                pFind->m_szText); //저장된 내용출력

        }

        pFind = pFind->next;
    }

    printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────\n\n");
}

void DeleteSchedule(SCHEDULE* pHead)  //스케줄 삭제
{
    DATE date;
    DATE current;
    current = GetToday();

    system("cls");
    DrawCalendar(pHead, current); //현재기준으로 달력출력
    ShowAllScheduleByDay(pHead, current); //현재기준으로 스케줄 출력
    printf("                                       ┌──────────────────────────────────────┐\n");
    printf("                                       │                                      │\n");
    printf("                                       │  년, 월, 일, 시간, 분 순으로 입력    │\n");
    printf("                                       │  (예시)2021 6 7 13 55                │\n");
    printf("                                       │                                      │\n");
    printf("                                       └──────────────────────────────────────┘\n\n");
    printf("                                       >> ");

    scanf("%d %d %d %d",
        &date.m_nYear,
        &date.m_nMonth,
        &date.m_nDay,
        &date.m_nHour,
        &date.m_nMinute); //년,월,일,시간 입력

    DeleteScheduleByDateAndTime(pHead, date);  //스케줄 날짜와 시간 삭제함수 
    system("cls");
}

void AddSchedule(SCHEDULE* pHead)  //스케줄 추가
{
    SCHEDULE schedule;

    schedule = InputSchedule(pHead);

    AddScheduleNode(pHead, schedule);
}

void Changeschedule(SCHEDULE* pHead)   //스케줄 수정
{
    SCHEDULE ret;
    DATE current;
    current = GetToday();

    system("cls");
    DrawCalendar(pHead, current);
    ShowAllScheduleByDay(pHead, current);

    printf("                                       ┌──────────────────────────────────────┐\n");
    printf("                                       │                                      │\n");
    printf("                                       │  년, 월, 일, 시간, 분 순으로 입력    │\n");
    printf("                                       │  (예시)2021 6 7 13 55                │\n");
    printf("                                       │                                      │\n");
    printf("                                       └──────────────────────────────────────┘\n\n");
    printf("                                       >> ");
    scanf("%d %d %d %d %d", &ret.m_date.m_nYear, &ret.m_date.m_nMonth, &ret.m_date.m_nDay, &ret.m_date.m_nHour, &ret.m_date.m_nMinute);
    printf("                          수정할 일정 입력\n           >>");

    ChangeScheduleByDateAndTime(pHead, ret); //날짜와 시간 스케줄변경
    system("cls");

}


//calendar
int GetLastDayByMonthAndYear(int nYear, int nMonth)
{
    int nLastDay;

    if (nMonth == 1 || //마지막날이 31일인 달
        nMonth == 3 ||
        nMonth == 5 ||
        nMonth == 7 ||
        nMonth == 8 ||
        nMonth == 10 ||
        nMonth == 12)
    {
        nLastDay = 31;
    }
    else if (nMonth == 4 ||  //마지막날이 30일인 달
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

    if (nMonth == 2 &&   //윤년판별
        (nYear % 4) == 0 &&
        (nYear % 100 != 0) || (nYear % 400 == 0)) //4로 떨어지면서 100으로 나눠지지 않거나 400으로 떨어질때 윤년이다 

    {
        nLastDay = 29;
    }

    return nLastDay;
}

void DrawCalendar(SCHEDULE* pHead, DATE date)   //달력출력함수
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
        printf("                               ┌──────────────── %d년  %d월 ──────────────────┐\n", nYear, nMonth);
    else
        printf("                               ┌──────────────── %d년  %d월  ─────────────────┐\n", nYear, nMonth);
    printf("                               │%6s%6s%6s%6s%6s%6s%6s     │\n", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat");

    nDate = 1, nX = 0, nZ = 0;

    while (nX <= 6)
    {
        nX = nX + 1;
        nTh = nYear / 100;
        nYear = nYear % 100;
        nDay = ((21 * nTh / 4) +
            (5 * nYear / 4) + (26 * (nMonth + 1) / 10) + nDate - 1) % 7;
        printf("                               │");
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
            printf("│\n");
        else if (nZ == 1)
            printf("│ \n");
        else if (nZ == 2)
            printf("│\n");
        else if (nZ == 3)
            printf("                       │\n");
        else if (nZ == 4)
            printf("                       │ \n");
        else if (nZ == 5)
            printf("                                                                      │\n");
        else
            printf("     │\n");

        if (nDate >= nLastDay)
        {
            break;
        }

        nZ = 0;
    }
    printf("                               │                                               │\n");
    printf("                               └───────────────────────────────────────────────┘\n\n");

}


//date.c
int CompareDate(DATE target, DATE compare) //날짜비교및 날짜설정 코드
{
    int nTargetSum = 0;
    int nCompareSum = 0;

    if (target.m_nYear > compare.m_nYear) //현재 해가 원하는 해보다 크다면 -1년 반환
    {
        return -1;
    }
    else if (target.m_nYear < compare.m_nYear) //현재 해가 원하는 해보다 작다면 +1년 반환
    {
        return 1;
    }

    if (target.m_nMonth > compare.m_nMonth) //현재 달이 원하는 달보다 크다면 -1달 반환
    {
        return -1;
    }
    else if (target.m_nMonth < compare.m_nMonth) //현재 달이 원하는 달보다 작다면 +1달 반환
    {
        return 1;
    }

    if (target.m_nDay > compare.m_nDay) //현재 날이 원하는 날보다 크다면 -1일 반환
    {
        return -1;
    }
    else if (target.m_nDay < compare.m_nDay) //현재 날이 원하는 날보다 작다면 +1일 반환
    {
        return 1;
    }

    return 0;
}

int CompareDateAndTime(DATE target, DATE compare)  //시간 비교
{
    if (target.m_nYear > compare.m_nYear) //현재 해가 원하는 해보다 크다면 -1년 반환
    {
        return -1;
    }
    else if (target.m_nYear < compare.m_nYear) //현재 해가 원하는 해보다 작다면 +1년 반환
    {
        return 1;
    }

    if (target.m_nMonth > compare.m_nMonth) //현재 달이 원하는 달보다 크다면 -1달 반환
    {
        return -1;
    }
    else if (target.m_nMonth < compare.m_nMonth) //현재 달이 원하는 달보다 작다면 +1달 반환
    {
        return 1;
    }

    if (target.m_nDay > compare.m_nDay) //현재 날이 원하는 날보다 크다면 -1일 반환
    {
        return -1;
    }
    else if (target.m_nDay < compare.m_nDay) //현재 날이 원하는 날보다 작다면 +1일 반환
    {
        return 1;
    }

    if (target.m_nHour > compare.m_nHour)  //현재 시간이 원하는 시간보다 크다면 -1시간
    {
        return -1;
    }
    else if (target.m_nHour < compare.m_nHour) //현재 시간이 원하는 시간보다 작다면 -1시간
    {
        return 1;
    }
    else if (target.m_nMinute < compare.m_nMinute)
    {
        return -1;
    }

    return 0;
}

void PrintDate(DATE date) //날짜출력함수

{
    printf("%d년 %d월 %d일 %d시 %d분\n", date.m_nYear, date.m_nMonth, date.m_nDay, date.m_nHour, date.m_nMinute);
}

DATE InputDate(void)  //날짜입력
{
    DATE ret;

    printf("년 : ");
    scanf("%d", &ret.m_nYear); //년

    printf("월 : ");
    scanf("%d", &ret.m_nMonth); //월

    printf("일 : ");
    scanf("%d", &ret.m_nDay);  //일

    printf("시 : ");
    scanf("%d", &ret.m_nHour); //시

    printf("분 : ");
    scanf("%d", &ret.m_nMinute); //분

    return ret;
}

DATE GetToday(void)
{
    DATE ret;
    time_t ltime;
    struct tm* today;

    time(&ltime);
    today = localtime(&ltime);

    ret.m_nYear = today->tm_year + 1900; //현재 날짜 코드
    ret.m_nMonth = today->tm_mon + 1;
    ret.m_nDay = today->tm_mday;

    ret.m_nHour = today->tm_hour;

    return ret;
}

void ModifyMonth(DATE* pDate, int nMonth) //달 수정함수
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

void ModifyDay(DATE* pDate, int nDay) //일 수정함수
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
SCHEDULE* InitScheduleHead(void)   //스케줄 초기화
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

SCHEDULE* GetSchedulePointerByDateAndTime(SCHEDULE* pHead, DATE date) //날짜별로 스케줄포인터 대입
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

void AddScheduleNode(SCHEDULE* pHead, SCHEDULE schedule) //스케줄 추가함수
{
    SCHEDULE* pPrev = pHead;
    SCHEDULE* pFind = pHead->next;
    SCHEDULE* pNew;

    pNew = (SCHEDULE*)malloc(sizeof(SCHEDULE));  //동적으로 메모리 할당
    *pNew = schedule;

    while (pFind != NULL)  //포인터가 NULL이 아닐때 계속 반복
    {
        if (CompareDateAndTime(schedule.m_date, pFind->m_date) == -1) //찾는 날과 스케줄 입력된 날이 같으면 실행
        {
            pPrev = pPrev->next; //이전날에 다음 주소 저장
            pFind = pFind->next; //찾는날에 다음 주소 저장
        }
        else
        {
            break;
        }
    }

    pPrev->next = pNew; //이전 노드의 다음 노드를 새 노드에 지정
    pNew->next = pFind; //새 노드에 다음 노드를 찾는 노드에 지정
}

void DeleteScheduleByDateAndTime(SCHEDULE* pHead, DATE date) //스케줄 삭제함수
{
    SCHEDULE* pPrev = pHead;
    SCHEDULE* pFind = pHead->next;
    SCHEDULE* pTemp;

    while (pFind != NULL) //포인터가 NULL이 아닐때 계속 반복
    {
        if (CompareDateAndTime(pFind->m_date, date) == 0) //찾는 날과 스케줄 입력된 날이 같으면 실행
        {
            pTemp = pFind;
            pPrev->next = pFind->next; // 이전 노드의 다음 노드에 찾는 노드의 다음 노드를 지정
            free(pTemp); //할당된 메모리 삭제
            break;
        }

        pFind = pFind->next;  //찾는날에 다음 주소 저장
        pPrev = pPrev->next; //이전날에 다음 주소 저장
    }
}

void ChangeScheduleByDateAndTime(SCHEDULE* pHead, SCHEDULE schedule) //스케줄 수정함수
{
    SCHEDULE* pFind = pHead->next;
    SCHEDULE* pTemp;

    while (pFind != NULL)
    {
        if (CompareDateAndTime(pFind->m_date, schedule.m_date) == 0) //찾는 날과 스케줄 입력된 날이 같으면 실행
        {
            pTemp = pFind;
            scanf("%s", pTemp->m_szText); // 입력받아 m_szText에 저장
            break;
        }
    }

}

void KillAllScheduleNode(SCHEDULE* pHead) //스케줄창 지우는 함수
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

void PrintAllSchedule(SCHEDULE* pHead) //스케줄 출력함수
{
    SCHEDULE* pFind = pHead->next;

    while (pFind != NULL)
    {
        printf("%s\n", pFind->m_szText);
        PrintDate(pFind->m_date);

        pFind = pFind->next;
    }
}

void LoadScheduleFromFile(SCHEDULE* pHead, char szFileName[]) //스케줄파일 오픈함수
{
    SCHEDULE news;
    FILE* fp;
    int nCnt = 0;
    char szBuf[STRING_MAX];

    fp = fopen(szFileName, "r"); //읽기전용으로 파일열기

    if (fp == NULL) //파일이 열리지 않으면 참
    {
        fp = fopen(szFileName, "w"); //쓰기전용으로 파일열기 
        fclose(fp);

        return;
    }

    while (!feof(fp)) //파일이 끝날때까지 while문을 돌린다 
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

void SaveScheduleToFile(SCHEDULE* pHead, char szFileName[]) //파일 저장함수
{
    FILE* fp;
    SCHEDULE* pFind = pHead->next;

    fp = fopen(szFileName, "w"); //FileName을 쓰기 모드(w)로 열기

    while (pFind != NULL)
    {
        fprintf(fp, "%d %d %d %d %d %s\n", // 서식을 지정하여 정수와 문자열을 파일에 저장

            pFind->m_date.m_nYear, //화살표 연산자로 구조체 멤버에 접근하여 값 할당
            pFind->m_date.m_nMonth,
            pFind->m_date.m_nDay,
            pFind->m_date.m_nHour,
            pFind->m_date.m_nMinute,
            pFind->m_szText
        );

        pFind = pFind->next;
    }

    fclose(fp); // 파일 포인터 닫기
}

SCHEDULE InputSchedule(SCHEDULE* pHead) //스케줄입력
{
    SCHEDULE ret;
    //DATE current;
    current = GetToday();

    system("cls");
    DrawCalendar(pHead, current);
    ShowAllScheduleByDay(pHead, current);

    while (TRUE)
    {
        printf("                                   ┌───────────────────────────────────────┐\n");
        printf("                                   │                                       │\n");
        printf("                                   │ 년, 월, 일, 시간, 분, 일정 순으로 입력│\n");
        printf("                                   │  (예시)2021 6 7 13 55 발표            │\n");
        printf("                                   │                                       │\n");
        printf("                                   └───────────────────────────────────────┘\n\n");
        printf("                                    >> ");

        scanf("%d %d %d %d %d %s",
            &ret.m_date.m_nYear,
            &ret.m_date.m_nMonth,
            &ret.m_date.m_nDay,
            &ret.m_date.m_nHour,
            &ret.m_date.m_nMinute,
            ret.m_szText);  //년, 월, 일, 시간, 일정 입력

        if (GetSchedulePointerByDateAndTime(pHead, ret.m_date) == NULL) //저장된 시간에 같은 시간대 입력시 break
        {
            break;
        }

        printf("                                    ┌──────────────────────────────────────┐\n");
        printf("                                    │                                      │\n");
        printf("                                    │  이미 같은 시간에 저장되어 있습니다  │\n");
        printf("                                    │                                      │\n");
        printf("                                    └──────────────────────────────────────┘\n\n");

    }
    system("cls");
    return ret;
}