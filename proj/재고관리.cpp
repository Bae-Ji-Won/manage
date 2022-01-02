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

struct item                                //상품 정보를 입력하는 구조체
{
    char name[31];                          // 상품 이름
    char color[31];                          // 상품 색
    char size[31];                             // 상품 사이즈
    int amount;                                 // 상품 수량
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

int product_display(void)               // 품복 구분 나타내는 리스트
{
    int select;
    system("cls");
    printf("\n┌──────────────────────────  품목 구분 ──────────────────────────────┐\n");
    printf("│                        [1]제 품1 (모 자)                           │\n");
    printf("│                        [2]제 품2 ( 옷 )                            │\n");
    printf("│                        [3]제 품3 (바 지)                           │\n");
    printf("│                        [4]제 품4 (신 발)                           │\n");
    printf("│                        [5]나 가 기                                 │\n");
    printf("└────────────────────────────────────────────────────────────────────┘\n");
    select = _getch() - 48;
    return select;
}

int item_display(void)      //품목 구분에서 번호 선택하면 나타나는 표, 기능 선택 리스트
{
    int j, i, g = 0;
    int red = 4;
    int white = 7;
    system("cls");                  // 창 초기화후 제품정보를 나타내는 표 출력

    printf("┌─────────────  1 ─────────────────────────────  6 ────────────────────────────  11 ─────────────────────────────  16 ─────────────┐\n");

    for (i = 0; i < 5; i++) {
        for (j = i + 1; j < 21; j += 5) {
            printf("│  제품명 : %-20s│", p[j - 1].name);
        }
        printf("\n");
        for (j = i + 1; j < 21; j += 5) {
            printf("│   색 상 : %-20s│", p[j - 1].color);
        }
        printf("\n");
        for (j = i + 1; j < 21; j += 5) {
            printf("│  사이즈 : %-20s│", p[j - 1].size);
        }
        printf("\n");
        for (j = i + 1; j < 21; j += 5) {
            if (p[j - 1].amount < 6) {          // 수량 5개 이하일때 글자 색상 변경
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), red);
                printf("│   수 량 : %-20d│", p[j - 1].amount);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
            }
            else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
                printf("│   수 량 : %-20d│", p[j - 1].amount);
            }
        }
        printf("\n");
        if (i == 0)
            printf("├────────────── 2 ─────────────────────────────  7 ────────────────────────────  12 ─────────────────────────────  17 ─────────────┤\n");
        else if (i == 1)
            printf("├────────────── 3 ─────────────────────────────  8 ────────────────────────────  13 ─────────────────────────────  18 ─────────────┤\n");
        else if (i == 2)
            printf("├────────────── 4 ─────────────────────────────  9 ────────────────────────────  14 ─────────────────────────────  19 ─────────────┤\n");
        else if (i == 3)
            printf("├────────────── 5 ─────────────────────────────  10 ────────────────────────────  15 ────────────────────────────  20 ─────────────┤\n");

        else if (i == 4)
            printf("├──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤\n");

    }
    printf("└──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘");
    return 0;

}

void title1() //타이틀 함수 title 시작
{
   printf("\n\n\n\n\n");
   printf("                         □□       □□          □□         □         □          □□         □□□□□□□□     □□□□□□        \n");
   printf("                         □□      □ □         □  □        □□       □         □  □        □                   □                  \n");
   printf("                         □ □    □  □        □    □       □ □      □        □    □       □                   □                  \n");
   printf("                         □  □  □   □       □      □      □  □     □       □      □      □       □□□□□  □                  \n");
   printf("                         □   □□    □      □        □     □   □    □      □        □     □               □  □□□□□□        \n");
   printf("                         □    □     □     □□□□□□□    □    □   □     □□□□□□□    □               □  □                  \n");
   printf("                         □           □    □            □   □     □  □    □            □   □□□□□□□   □  □                  \n");
   printf("                         □           □   □              □  □      □ □   □              □                   □  □                  \n");
   printf("                         □           □  □                □ □       □□  □                □                  □  □□□□□□        \n");
   
}

int select_menu_item(void)      // 재고조사 기능 리스트
{
    system("cls");
    int select = 0;
    item_display();
    printf("\n");
    printf("\n┌──────────────────────────  <원하시는 메뉴 번호를 누르시오> ──────────────────────────────┐\n");
    printf("│                                   1.제품 정보 추가                                       │\n");
    printf("│                                   2.제품 정보 삭제                                       │\n");
    printf("│                                   3.제품 입고                                            │\n");
    printf("│                                   4.제품 출고                                            │\n");
    printf("│                                   0.나가기                                               │\n");
    printf("└──────────────────────────────────────────────────────────────────────────────────────────┘\n");
    select = _getch() - 48;
    return select;
}

void hat(void)                  // 첫번째 품목에 대한 함수
{
    int p;
    system("cls");
    while ((p = select_menu_item()) != 0)
    {
        switch (p)
        {
        case 1: plus_product_hat();         // 1번을 눌렀을때 제품 추가 기능 호출
            break;
        case 2: del_hat();                  // 2번을 눌렀을때 제품 삭제 기능 호출
            break;
        case 3:  add_hat();                 // 3번을 눌렀을때 입고 기능 호출
            break;
        case 4: minus_hat();                // 4번을 눌렀을때 출고 기능 호출
            break;
        default: break;
        }
    }
}

void clothes(void)              // 두번째 품목에 대한 함수
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

void pants(void)                        // 세번째 품목에 대한 함수
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

void shoes(void)                    // 네번째 품목에 대한 함수
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



void plus_product_hat(void)     //제품 추가 함수
{
    int c, i, g = 0;

    system("cls");

    c = select_box();
    i = select_num(c);
    save_file_hat(i, c);
}
void plus_product_clothes(void)     //제품 추가 함수
{
    int c, i, g = 0;

    system("cls");

    c = select_box();
    i = select_num(c);
    save_file_clothes(i, c);
}
void plus_product_pants(void)     //제품 추가 함수
{
    int c, i, g = 0;

    system("cls");

    c = select_box();
    i = select_num(c);
    save_file_pants(i, c);
}
void plus_product_shoes(void)     //제품 추가 함수
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

int select_box(void)      //몇번 칸인지 값을 입력하는 함수.
{
    system("cls");
    int select = 0;
    while (1) {
        item_display();
        printf("\n");
        printf("\t               ┌─────────────────────────────────────────────────────────────────┐\n");
        printf("\t               │                   추가할 위치를 고르세요.[1~20]                    │\n");
        printf("\t               │       위치1:[1~5] 위치2:[6~10] 위치3:[11~15] 위치4:[16~20]       │\n");
        printf("\t               └──────────────────────────────────────────────────────────────────┘\n");
        printf("\t                칸 번호>>");
        scanf("%d", &select);

        if (select < 1 || select > 20) {
            printf("\n\n입력 할 수 없는 값입니다.");
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

int del_box(void)      //몇번 칸인지 값을 입력하는 함수.
{
    system("cls");
    int select = 0;
    while (1) {
        item_display();
        printf("\n");
        printf("\t               ┌─────────────────────────────────────────────────────────────────┐\n");
        printf("\t               │                   삭제할 위치를 고르세요.[1~20]                    │\n");
        printf("\t               │       위치1:[1~5] 위치2:[6~10] 위치3:[11~15] 위치4:[16~20]       │\n");
        printf("\t               └──────────────────────────────────────────────────────────────────┘\n");
        printf("\t                칸 번호>>");
        scanf("%d", &select);

        if (select < 1 || select > 20) {
            printf("\n\n입력 할 수 없는 값입니다.");
            system("cls");
        }
        else {
            return select;
            break;
        }
    }
}


int add_box(void)      //몇번 칸인지 값을 입력하는 함수.
{
    system("cls");
    int select = 0;
    while (1) {
        item_display();
        printf("\n");
        printf("\t               ┌─────────────────────────────────────────────────────────────────┐\n");
        printf("\t               │                   입고할 위치를 고르세요.[1~20]                    │\n");
        printf("\t               │       위치1:[1~5] 위치2:[6~10] 위치3:[11~15] 위치4:[16~20]       │\n");
        printf("\t               └──────────────────────────────────────────────────────────────────┘\n");
        printf("\t                칸 번호>>");
        scanf("%d", &select);

        if (select < 1 || select > 20) {
            printf("\n\n입력 할 수 없는 값입니다.");
            system("cls");
        }
        else {
            return select;
            break;
        }
    }
}


int minus_box(void)      //몇번 칸인지 값을 입력하는 함수.
{
    system("cls");
    int select = 0;
    while (1) {
        item_display();
        printf("\n");
        printf("\t               ┌─────────────────────────────────────────────────────────────────┐\n");
        printf("\t               │                   출고할 위치를 고르세요.[1~20]                    │\n");
        printf("\t               │       위치1:[1~5] 위치2:[6~10] 위치3:[11~15] 위치4:[16~20]       │\n");
        printf("\t               └──────────────────────────────────────────────────────────────────┘\n");
        printf("\t                칸 번호>>");
        scanf("%d", &select);

        if (select < 1 || select > 20) {
            printf("\n\n입력 할 수 없는 값입니다.");
            system("cls");
        }
        else {
            return select;
            break;
        }
    }
}

void save_file_hat(int i, int c)            // 제품추가 및 파일 저장 함수
{
    system("cls");
    int g = 0;
    g = 5 * (i - 1) + (c - 1);     //칸=4(16~20번) 번호=4 일떄, g= 5*3+3 = 18 -> 18번 배열에 저장

    FILE* fp = NULL;
    char fname[100] = { 0 };

    printf("\n\n\t\t\t    제품명을 입력하세요:");
    scanf("%s", fname);

    fp = fopen("hat.txt", "w");     //hat.txt 이름으로 파일"쓰기"모드로 연다.
    if (fp == NULL)
        printf("파일 열기에 실패했습니다.");

    strcpy(p[g].name, fname);
    printf("\n\t\t\t    색상을 입력하세요:");
    scanf("%s", &p[g].color);

    printf("\n\t\t\t    사이즈를 입력하세요:");
    scanf("%s", &p[g].size);
    printf("\n\t\t\t    수량을 입력하세요:");
    scanf("%d", &p[g].amount);

    for (int k = 0; k < 100; k++) {
        fprintf(fp, "%s %s %s %d ", p[k].name, p[k].color, p[k].size, p[k].amount); //hat.txt파일에 p[0]~p[99] 구조체 저장
        fputc('\n', fp);
    }
    fclose(fp);

    printf("\n\n\n\t\t\t        이름:%s, 색상:%s, 사이즈:%s, 수량:%d\n", p[g].name, p[g].color, p[g].size, p[g].amount); //구조체에 저장 되어 있는지 확인
    printf("\n\t\t\t            제품 추가가 완료되었습니다.");

    _getch();
}

void save_file_clothes(int i, int c)            // 제품추가 및 파일 저장 함수
{
    system("cls");
    int g = 0;
    g = 5 * (i - 1) + (c - 1);     //칸=4(16~20번) 번호=4 일떄, g= 5*3+3 = 18 -> 18번 배열에 저장

    FILE* fp = NULL;
    char fname[100] = { 0 };

    printf("\n\n\t\t\t    제품명을 입력하세요:");
    scanf("%s", fname);

    fp = fopen("clothes.txt", "w");     //clothes.txt 이름으로 파일"쓰기"모드로 연다.
    if (fp == NULL)
        printf("파일 열기에 실패했습니다.");

    strcpy(p[g].name, fname);
    printf("\n\t\t\t    색상을 입력하세요:");
    scanf("%s", &p[g].color);

    printf("\n\t\t\t    사이즈를 입력하세요:");
    scanf("%s", &p[g].size);
    printf("\n\t\t\t    수량을 입력하세요:");
    scanf("%d", &p[g].amount);

    for (int k = 0; k < 100; k++) {
        fprintf(fp, "%s %s %s %d ", p[k].name, p[k].color, p[k].size, p[k].amount); //clothes.txt파일에 p[0]~p[99] 구조체 저장
        fputc('\n', fp);
    }
    fclose(fp);

    printf("\n\n\n\t\t\t        이름:%s, 색상:%s, 사이즈:%s, 수량:%d\n", p[g].name, p[g].color, p[g].size, p[g].amount); //구조체에 저장 되어 있는지 확인
    printf("\n\t\t\t            제품 추가가 완료되었습니다.");

    _getch();
}

void save_file_pants(int i, int c)            // 제품추가 및 파일 저장 함수
{
    system("cls");
    int g = 0;
    g = 5 * (i - 1) + (c - 1);     //칸=4(16~20번) 번호=4 일떄, g= 5*3+3 = 18 -> 18번 배열에 저장

    FILE* fp = NULL;
    char fname[100] = { 0 };

    printf("\n\n\t\t\t    제품명을 입력하세요:");
    scanf("%s", fname);

    fp = fopen("pants.txt", "w");     //pants.txt 이름으로 파일"쓰기"모드로 연다.
    if (fp == NULL)
        printf("파일 열기에 실패했습니다.");

    strcpy(p[g].name, fname);
    printf("\n\t\t\t    색상을 입력하세요:");
    scanf("%s", &p[g].color);

    printf("\n\t\t\t    사이즈를 입력하세요:");
    scanf("%s", &p[g].size);
    printf("\n\t\t\t    수량을 입력하세요:");
    scanf("%d", &p[g].amount);

    for (int k = 0; k < 100; k++) {
        fprintf(fp, "%s %s %s %d ", p[k].name, p[k].color, p[k].size, p[k].amount); //pants.txt파일에 p[0]~p[99] 구조체 저장
        fputc('\n', fp);
    }
    fclose(fp);

    printf("\n\n\n\t\t\t        이름:%s, 색상:%s, 사이즈:%s, 수량:%d\n", p[g].name, p[g].color, p[g].size, p[g].amount); //구조체에 저장 되어 있는지 확인
    printf("\n\t\t\t            제품 추가가 완료되었습니다.");

    _getch();
}

void save_file_shoes(int i, int c)            // 제품추가 및 파일 저장 함수
{
    system("cls");
    int g = 0;
    g = 5 * (i - 1) + (c - 1);     //칸=4(16~20번) 번호=4 일떄, g= 5*3+3 = 18 -> 18번 배열에 저장

    FILE* fp = NULL;
    char fname[100] = { 0 };

    printf("\n\n\t\t\t    제품명을 입력하세요:");
    scanf("%s", fname);

    fp = fopen("shoes.txt", "w");     //shoes.txt 이름으로 파일"쓰기"모드로 연다.
    if (fp == NULL)
        printf("파일 열기에 실패했습니다.");

    strcpy(p[g].name, fname);
    printf("\n\t\t\t    색상을 입력하세요:");
    scanf("%s", &p[g].color);

    printf("\n\t\t\t    사이즈를 입력하세요:");
    scanf("%s", &p[g].size);
    printf("\n\t\t\t    수량을 입력하세요:");
    scanf("%d", &p[g].amount);

    for (int k = 0; k < 100; k++) {
        fprintf(fp, "%s %s %s %d ", p[k].name, p[k].color, p[k].size, p[k].amount); //shoes.txt파일에 p[0]~p[99] 구조체 저장
        fputc('\n', fp);
    }
    fclose(fp);

    printf("\n\n\n\t\t\t        이름:%s, 색상:%s, 사이즈:%s, 수량:%d\n", p[g].name, p[g].color, p[g].size, p[g].amount); //구조체에 저장 되어 있는지 확인
    printf("\n\t\t\t            제품 추가가 완료되었습니다.");

    _getch();
}

void load_file_hat(void)
{
    int i;
    FILE* fp;
    fp = fopen("hat.txt", "r");     //hat.txt를 파일 읽기 모드로 연다.
    if (fp == NULL)
    {
        printf("파일 열기에 실패했습니다.");
    }
    for (i = 0; i < 100; i++) {
        fscanf(fp, "%s %s %s %d  ", p[i].name, &p[i].color, &p[i].size, &p[i].amount);  //hat.txt에 있는 정보들을 구조체에 저장
    }
    fclose(fp);
}

void load_file_clothes(void)
{
    int i;
    FILE* fp;
    fp = fopen("clothes.txt", "r");     //clothes.txt를 파일 읽기 모드로 연다.
    if (fp == NULL)
    {
        printf("파일 열기에 실패했습니다.");
    }
    for (i = 0; i < 100; i++) {
        fscanf(fp, "%s %s %s %d  ", p[i].name, &p[i].color, &p[i].size, &p[i].amount);  //clothes.txt에 있는 정보들을 구조체에 저장
    }
    fclose(fp);
}

void load_file_pants(void)
{
    int i;
    FILE* fp;
    fp = fopen("pants.txt", "r");     //pants.txt를 파일 읽기 모드로 연다.
    if (fp == NULL)
    {
        printf("파일 열기에 실패했습니다.");
    }
    for (i = 0; i < 100; i++) {
        fscanf(fp, "%s %s %s %d  ", p[i].name, &p[i].color, &p[i].size, &p[i].amount);  //pants.txt에 있는 정보들을 구조체에 저장
    }
    fclose(fp);
}

void load_file_shoes(void)
{
    int i;
    FILE* fp;
    fp = fopen("shoes.txt", "r");     //shoes.txt를 파일 읽기 모드로 연다.
    if (fp == NULL)
    {
        printf("파일 열기에 실패했습니다.");
    }
    for (i = 0; i < 100; i++) {
        fscanf(fp, "%s %s %s %d  ", p[i].name, &p[i].color, &p[i].size, &p[i].amount);  //shoes.txt에 있는 정보들을 구조체에 저장
    }
    fclose(fp);
}

void del_hat(void)              // 제품 삭제 함수
{
    int c, i, g = 0;
    int m = 0;
    //c -> 칸 번호 i -> 칸 안에 제품 번호
    char z[20] = { 0 };             //삭제전 정보 z에 저장
    char w[20] = { 0 };             //삭제전 정보 w에 저장
    char x[20] = { 0 };
    char name12[20] = { '-' };
    char color12[20] = { '-' };//그냥 초기화하면 이름 맴버에 공백이 생겨서 파일 내용이 한칸씩 당겨짐 그래서 -삽입
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
    fp = fopen("hat.txt", "w");     //hat.txt 이름으로 파일"쓰기"모드로 연다.
    if (fp == NULL)
    {
        printf("파일 열기에 실패했습니다.");

    }
    system("cls");
    printf("\n\t\t\t            %d칸 (을)를 삭제하겠습니다....\n", c);
    strcpy(p[g].name, name12);
    strcpy(p[g].color, color12);
    strcpy(p[g].size, size12);
    p[g].amount = 0;

    for (int k = 0; k < 100; k++) {   //추가
        fprintf(fp, " %s %s %s %d ", p[k].name, p[k].color, p[k].size, p[k].amount);
    }
    fclose(fp);

    printf("\n\t\t\t            이름:%s......삭제 완료", z, p[g].name);
    printf("\n\t\t\t            색상:%s.......삭제완료", w, p[g].color);
    printf("\n\t\t\t            사이즈:%d......삭제완료", x, p[g].size);
    printf("\n\t\t\t            수량:%d.......삭제완료", m, p[g].amount);
    printf("\n\t\t\t            칸:%d,번호:%d, 이름:%s, color:%s, size:%s, amount:%d", c, i, p[g].name, p[g].color, p[g].size, p[g].amount);
    printf("\n\t\t\t            .....삭제가 완료되었습니다!!!");
    _getch();
}


void del_pants(void)              // 제품 삭제 함수
{
    int c, i, g = 0;
    int m = 0;
    //c -> 칸 번호 i -> 칸 안에 제품 번호
    char z[20] = { 0 };             //삭제전 정보 z에 저장
    char w[20] = { 0 };             //삭제전 정보 w에 저장
    char x[20] = { 0 };
    char name12[20] = { '-' };
    char color12[20] = { '-' };//그냥 초기화하면 이름 맴버에 공백이 생겨서 파일 내용이 한칸씩 당겨짐 그래서 -삽입
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
    fp = fopen("pants.txt", "w");     //pants.txt 이름으로 파일"쓰기"모드로 연다.
    if (fp == NULL)
    {
        printf("파일 열기에 실패했습니다.");

    }
    system("cls");
    printf("\n\t\t\t            %d칸 (을)를 삭제하겠습니다....\n", c);
    strcpy(p[g].name, name12);
    strcpy(p[g].color, color12);
    strcpy(p[g].size, size12);
    p[g].amount = 0;

    for (int k = 0; k < 100; k++) {   //추가
        fprintf(fp, " %s %s %s %d ", p[k].name, p[k].color, p[k].size, p[k].amount);
    }
    fclose(fp);

    printf("\n\t\t\t            이름:%s......삭제 완료", z, p[g].name);
    printf("\n\t\t\t            색상:%s.......삭제완료", w, p[g].color);
    printf("\n\t\t\t            사이즈:%d......삭제완료", x, p[g].size);
    printf("\n\t\t\t            수량:%d.......삭제완료", m, p[g].amount);
    printf("\n\t\t\t            칸:%d,번호:%d, 이름:%s, color:%s, size:%s, amount:%d", c, i, p[g].name, p[g].color, p[g].size, p[g].amount);
    printf("\n\t\t\t            .....삭제가 완료되었습니다!!!");
    _getch();
}

void del_clothes(void)              // 제품 삭제 함수
{
    int c, i, g = 0;
    int m = 0;
    //c -> 칸 번호 i -> 칸 안에 제품 번호
    char z[20] = { 0 };             //삭제전 정보 z에 저장
    char w[20] = { 0 };             //삭제전 정보 w에 저장
    char x[20] = { 0 };
    char name12[20] = { '-' };
    char color12[20] = { '-' };//그냥 초기화하면 이름 맴버에 공백이 생겨서 파일 내용이 한칸씩 당겨짐 그래서 -삽입
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
    fp = fopen("clothes.txt", "w");     //clothes.txt 이름으로 파일"쓰기"모드로 연다.
    if (fp == NULL)
    {
        printf("파일 열기에 실패했습니다.");

    }
    system("cls");
    printf("\n\t\t\t            %d칸 (을)를 삭제하겠습니다....\n", c);
    strcpy(p[g].name, name12);
    strcpy(p[g].color, color12);
    strcpy(p[g].size, size12);
    p[g].amount = 0;

    for (int k = 0; k < 100; k++) {   //추가
        fprintf(fp, " %s %s %s %d", p[k].name, p[k].color, p[k].size, p[k].amount);
    }
    fclose(fp);

    printf("\n\t\t\t            이름:%s......삭제 완료", z, p[g].name);
    printf("\n\t\t\t            색상:%s.......삭제완료", w, p[g].color);
    printf("\n\t\t\t            사이즈:%d......삭제완료", x, p[g].size);
    printf("\n\t\t\t            수량:%d.......삭제완료", m, p[g].amount);
    printf("\n\t\t\t            칸:%d,번호:%d, 이름:%s, color:%s, size:%s, amount:%d", c, i, p[g].name, p[g].color, p[g].size, p[g].amount);
    printf("\n\t\t\t            .....삭제가 완료되었습니다!!!");
    _getch();
}

void del_shoes(void)              // 제품 삭제 함수
{
    int c, i, g = 0;
    int m = 0;
    //c -> 칸 번호 i -> 칸 안에 제품 번호
    char z[20] = { 0 };             //삭제전 정보 z에 저장
    char w[20] = { 0 };             //삭제전 정보 w에 저장
    char x[20] = { 0 };
    char name12[20] = { '-' };
    char color12[20] = { '-' };//그냥 초기화하면 이름 맴버에 공백이 생겨서 파일 내용이 한칸씩 당겨짐 그래서 -삽입
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
    fp = fopen("shoes.txt", "w");     //shoes.txt 이름으로 파일"쓰기"모드로 연다.
    if (fp == NULL)
    {
        printf("파일 열기에 실패했습니다.");

    }
    system("cls");
    printf("\n\t\t\t            %d칸 (을)를 삭제하겠습니다....\n", c);
    strcpy(p[g].name, name12);
    strcpy(p[g].color, color12);
    strcpy(p[g].size, size12);
    p[g].amount = 0;

    for (int k = 0; k < 100; k++) {   //추가
        fprintf(fp, " %s %s %s %d", p[k].name, p[k].color, p[k].size, p[k].amount);
    }
    fclose(fp);

    printf("\n\t\t\t            이름:%s......삭제 완료", z, p[g].name);
    printf("\n\t\t\t            색상:%s.......삭제완료", w, p[g].color);
    printf("\n\t\t\t            사이즈:%d......삭제완료", x, p[g].size);
    printf("\n\t\t\t            수량:%d.......삭제완료", m, p[g].amount);
    printf("\n\t\t\t            칸:%d,번호:%d, 이름:%s, color:%s, size:%s, amount:%d", c, i, p[g].name, p[g].color, p[g].size, p[g].amount);
    printf("\n\t\t\t            .....삭제가 완료되었습니다!!!");
    _getch();
}

void add_hat(void)              //입고 함수
{
    int  m = 0;
    int c, i, g = 0;//c -> 칸 번호 i -> 칸 안에 제품 번호
    int aaa; //add개수

    system("cls");

    c = add_box();
    i = select_num(c);
    g = 5 * (i - 1) + (c - 1);
    m = p[g].amount;

    FILE* fp = NULL;
    fp = fopen("hat.txt", "w");     //입력된 이름으로 파일"쓰기"모드로 연다.(수정 하기 위해서)
    if (fp == NULL)
    {
        printf("파일 열기에 실패했습니다.");
    }
    system("cls");
    printf("\n\t\t\t       ★%d칸 %s(을)를 입고하겠습니다....", c, p[g].name);

    printf("\n\t\t\t       ★입고할 개수를 입력하세요.>>");                                           //개수 수정
    scanf("%d", &aaa);
    p[g].amount += aaa;

    for (int k = 0; k < 100; k++) {             //추가
        fprintf(fp, " %d ", p[k].amount);      // 수정 후 정보 파일에 저장
    }
    fclose(fp);
    printf("\n\n\t\t\t       입고 전// 칸:%d 개수:%d\n", c, m); //수정 전 정보 출력
    printf("\n\t\t\t       입고 후// 칸:%d 개수:%d\n", c, p[g].amount);//수정 후 정보 출력
    printf("\n\t\t\t       입고를 완료했습니다!!!");

    _getch();
}

void add_clothes(void)              //입고 함수
{
    int  m = 0;
    int c, i, g = 0;//c -> 칸 번호 i -> 칸 안에 제품 번호
    int aaa; //aaa개수

    system("cls");

    c = add_box();
    i = select_num(c);
    g = 5 * (i - 1) + (c - 1);
    m = p[g].amount;

    FILE* fp = NULL;
    fp = fopen("clothes.txt", "w");     //입력된 이름으로 파일"쓰기"모드로 연다.(수정 하기 위해서)
    if (fp == NULL)
    {
        printf("파일 열기에 실패했습니다.");
    }
    system("cls");
    printf("\n\t\t\t       ★%d칸 %s(을)를 입고하겠습니다....", c, p[g].name);

    printf("\n\t\t\t       ★입고할 개수를 입력하세요.>>");                                           //개수 수정
    scanf("%d", &aaa);
    p[g].amount += aaa;

    for (int k = 0; k < 100; k++) {             //추가
        fprintf(fp, " %d ", p[k].amount);      // 수정 후 정보 파일에 저장
    }
    fclose(fp);
    printf("\n\n\t\t\t       입고 전// 칸:%d 개수:%d\n", c, m); //수정 전 정보 출력
    printf("\n\t\t\t       입고 후// 칸:%d 개수:%d\n", c, p[g].amount);//수정 후 정보 출력
    printf("\n\t\t\t       입고를 완료했습니다!!!");

    _getch();
}

void add_pants(void)              //입고 함수
{
    int  m = 0;
    int c, i, g = 0;//c -> 칸 번호 i -> 칸 안에 제품 번호
    int aaa; //aaa개수

    system("cls");

    c = add_box();
    i = select_num(c);
    g = 5 * (i - 1) + (c - 1);
    m = p[g].amount;

    FILE* fp = NULL;
    fp = fopen("pants.txt", "w");     //입력된 이름으로 파일"쓰기"모드로 연다.(수정 하기 위해서)
    if (fp == NULL)
    {
        printf("파일 열기에 실패했습니다.");
    }
    system("cls");
    printf("\n\t\t\t       ★%d칸 %s(을)를 입고하겠습니다....", c, p[g].name);

    printf("\n\t\t\t       ★입고할 개수를 입력하세요.>>");                                           //개수 수정
    scanf("%d", &aaa);
    p[g].amount += aaa;

    for (int k = 0; k < 100; k++) {             //추가
        fprintf(fp, " %d ", p[k].amount);      // 수정 후 정보 파일에 저장
    }
    fclose(fp);
    printf("\n\n\t\t\t       입고 전// 칸:%d 개수:%d\n", c, m); //수정 전 정보 출력
    printf("\n\t\t\t       입고 후// 칸:%d 개수:%d\n", c, p[g].amount);//수정 후 정보 출력
    printf("\n\t\t\t       입고를 완료했습니다!!!");

    _getch();
}

void add_shoes(void)              //입고 함수
{
    int  m = 0;
    int c, i, g = 0;//c -> 칸 번호 i -> 칸 안에 제품 번호
    int aaa; //aaa개수

    system("cls");

    c = add_box();
    i = select_num(c);
    g = 5 * (i - 1) + (c - 1);
    m = p[g].amount;

    FILE* fp = NULL;
    fp = fopen("shoes.txt", "w");     //입력된 이름으로 파일"쓰기"모드로 연다.(수정 하기 위해서)
    if (fp == NULL)
    {
        printf("파일 열기에 실패했습니다.");
    }
    system("cls");
    printf("\n\t\t\t       ★%d칸 %s(을)를 입고하겠습니다....", c, p[g].name);

    printf("\n\t\t\t       ★입고할 개수를 입력하세요.>>");                                           //개수 수정
    scanf("%d", &aaa);
    p[g].amount += aaa;

    for (int k = 0; k < 100; k++) {             //추가
        fprintf(fp, " %d ", p[k].amount);      // 수정 후 정보 파일에 저장
    }
    fclose(fp);
    printf("\n\n\t\t\t       입고 전// 칸:%d 개수:%d\n", c, m); //수정 전 정보 출력
    printf("\n\t\t\t       입고 후// 칸:%d 개수:%d\n", c, p[g].amount);//수정 후 정보 출력
    printf("\n\t\t\t       입고를 완료했습니다!!!");

    _getch();
}

void minus_hat(void)                //출고 함수
{
    int  m = 0;
    int c, i, g = 0;//c -> 칸 번호 i -> 칸 안에 제품 번호
    int bbb; //bbb개수

    system("cls");

    c = minus_box();
    i = select_num(c);
    g = 5 * (i - 1) + (c - 1);        //''
    m = p[g].amount;              //''

    FILE* fp = NULL;
    fp = fopen("hat.txt", "w");     //입력된 이름으로 파일"쓰기"모드로 연다.(수정 하기 위해서)
    if (fp == NULL)
    {
        printf("파일 열기에 실패했습니다.");
    }
    system("cls");
    printf("\n\t\t\t       ★%d칸 %s(을)를 출고하겠습니다....", c, p[g].name);

    printf("\n\t\t\t       ★출고할 개수를 입력하세요.>>");                                           //개수 수정
    scanf("%d", &bbb);
    p[g].amount -= bbb;

    for (int k = 0; k < 100; k++) {             //추가
        fprintf(fp, " %d ", p[k].amount);      // 수정 후 정보 파일에 저장
    }
    fclose(fp);
    printf("\n\n\t\t\t       출고 전// 칸:%d,개수:%d\n", c, m); //수정 전 정보 출력
    printf("\n\t\t\t       출고 후// 칸:%d, 개수:%d\n", c, p[g].amount);//수정 후 정보 출력
    printf("\n\t\t\t       출고를 완료했습니다!!!");

    _getch();
}

void minus_clothes(void)                //출고 함수
{
    int  m = 0;
    int c, i, g = 0;//c -> 칸 번호 i -> 칸 안에 제품 번호
    int bbb; //bbb개수

    system("cls");

    c = minus_box();
    i = select_num(c);
    g = 5 * (i - 1) + (c - 1);        //''
    m = p[g].amount;              //''

    FILE* fp = NULL;
    fp = fopen("clothes.txt", "w");     //입력된 이름으로 파일"쓰기"모드로 연다.(수정 하기 위해서)
    if (fp == NULL)
    {
        printf("파일 열기에 실패했습니다.");
    }
    system("cls");
    printf("\n\t\t\t       ★%d칸 %s(을)를 출고하겠습니다....", c, p[g].name);

    printf("\n\t\t\t       ★출고할 개수를 입력하세요.>>");                                           //개수 수정
    scanf("%d", &bbb);
    p[g].amount -= bbb;

    for (int k = 0; k < 100; k++) {             //추가
        fprintf(fp, " %d ", p[k].amount);      // 수정 후 정보 파일에 저장
    }
    fclose(fp);
    printf("\n\n\t\t\t       출고 전// 칸:%d,개수:%d\n", c, m); //수정 전 정보 출력
    printf("\n\t\t\t       출고 후// 칸:%d, 개수:%d\n", c, p[g].amount);//수정 후 정보 출력
    printf("\n\t\t\t       출고를 완료했습니다!!!");

    _getch();
}

void minus_pants(void)                //출고 함수
{
    int  m = 0;
    int c, i, g = 0;//c -> 칸 번호 i -> 칸 안에 제품 번호
    int bbb; //bbb개수

    system("cls");

    c = minus_box();
    i = select_num(c);
    g = 5 * (i - 1) + (c - 1);        //''
    m = p[g].amount;              //''

    FILE* fp = NULL;
    fp = fopen("pants.txt", "w");     //입력된 이름으로 파일"쓰기"모드로 연다.(수정 하기 위해서)
    if (fp == NULL)
    {
        printf("파일 열기에 실패했습니다.");
    }
    system("cls");
    printf("\n\t\t\t       ★%d칸 %s(을)를 출고하겠습니다....", c, p[g].name);

    printf("\n\t\t\t       ★출고할 개수를 입력하세요.>>");                                           //개수 수정
    scanf("%d", &bbb);
    p[g].amount -= bbb;

    for (int k = 0; k < 100; k++) {             //추가
        fprintf(fp, " %d ", p[k].amount);      // 수정 후 정보 파일에 저장
    }
    fclose(fp);
    printf("\n\n\t\t\t       출고 전// 칸:%d,개수:%d\n", c, m); //수정 전 정보 출력
    printf("\n\t\t\t       출고 후// 칸:%d, 개수:%d\n", c, p[g].amount);//수정 후 정보 출력
    printf("\n\t\t\t       출고를 완료했습니다!!!");

    _getch();
}

void minus_shoes(void)                //출고 함수
{
    int  m = 0;
    int c, i, g = 0;//c -> 칸 번호 i -> 칸 안에 제품 번호
    int bbb; //bbb개수

    system("cls");

    c = minus_box();
    i = select_num(c);
    g = 5 * (i - 1) + (c - 1);        //''
    m = p[g].amount;              //''

    FILE* fp = NULL;
    fp = fopen("shoes.txt", "w");     //입력된 이름으로 파일"쓰기"모드로 연다.(수정 하기 위해서)
    if (fp == NULL)
    {
        printf("파일 열기에 실패했습니다.");
    }
    system("cls");
    printf("\n\t\t\t       ★%d칸 %s(을)를 출고하겠습니다....", c, p[g].name);

    printf("\n\t\t\t       ★출고할 개수를 입력하세요.>>");                                           //개수 수정
    scanf("%d", &bbb);
    p[g].amount -= bbb;

    for (int k = 0; k < 100; k++) {             //추가
        fprintf(fp, " %d ", p[k].amount);      // 수정 후 정보 파일에 저장
    }
    fclose(fp);
    printf("\n\n\t\t\t       출고 전// 칸:%d,개수:%d\n", c, m); //수정 전 정보 출력
    printf("\n\t\t\t       출고 후// 칸:%d, 개수:%d\n", c, p[g].amount);//수정 후 정보 출력
    printf("\n\t\t\t       출고를 완료했습니다!!!");

    _getch();
}

void hat_check(void) {

}