#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

//사용자의 정보를 저장하는 구조체
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
    int count = 0; //저장된 수
    system("cls");

    openFile(item, &count);

    while (z != 5)
    {
        printf("\n┌────────────────────────── 제품 위치 찾기 ──────────────────────────┐\n");
        printf("│                            [1]제품 추가                            │\n");
        printf("│                            [2]제품 제거                            │\n");
        printf("│                            [3]위치 찾기                            │\n");
        printf("│                            [4]모든 정보 확인                       │\n");
        printf("│                            [5]저장 및 종료                         │\n");
        printf("└────────────────────────────────────────────────────────────────────┘\n");
        printf("어떤 기능을 사용하시겠습니까? : ");
        if (0 < z || z < 6) {
            scanf("%d", &z);
        }
        else {
            printf("번호를 다시 입력해 주세요");      // 추후 메인과 연결시키고 나면 1~5번 숫자를 제외한 키 입력시 메인 화면으로 나가지도록 설정할 예정(일단 현재는 즉시 종료로 설정)
            return;
        }

        switch (z) {
        case 1:
            printf("\n제품 추가 기능 입니다. \n");
            insert(item, &count);
            break;
        case 2:
            printf("\n제품 제거 기능 입니다. \n");
            deleted(item, &count);
            break;
        case 3:
            printf("\n위치 찾기 기능 입니다. \n");
            find(item, &count);
            break;
        case 4:
            printf("\n입력한 모든 정보를 출력합니다. \n");
            all(item, &count);
            break;
        case 5:
            printf("\n이전화면으로 나가집니다. \n");
            saveFile(item, &count);
            break;
        default:
            printf("\n번호를 다시 입력해 주세요! \n\n");
            break;
        }
    }

    return;
}

//데이터를 파일에 저장하는 함수
int saveFile(location* ptr, int* data) {

    if (*data > 0) {
        int a, state;
        FILE* fp = fopen("test.txt", "wt");
        /* fopen함수는 오류발생시 NULL을 리턴하므로
           파일 개방 중 오류발생시 프로그램을 종료 */
        if (fp == NULL) {
            printf("파일을 여는데 오류가 발생했습니다!\n");
            return 1;
        }



        //구조체 배열에 저장된 데이터를 파일에 저장
        //줄바꿈으로 구분하여 저장
        for (a = 0; a < *data; a++) {
            fprintf(fp, "%s %s %s", ptr[a].product, ptr[a].address, ptr[a].kind);
            fputc('\n', fp);
        }



        /* fclose함수는 종료시 오류가 발생하면
        0이 아닌 다른값을 리턴하므로 비정상 종료로 판단되면
        안내후 프로그램을 종료 */
        state = fclose(fp);
        if (state != 0) {
            printf("파일을 닫는데 오류가 발생했습니다!\n");
            return 1;
        }
        printf("\n  정보를 저장합니다 \n");
        return 0;
    }

    else {
        printf("\n 종료합니다 \n");
        return 0;
    }
}



//파일로부터 데이터를 불러오는 함수
int openFile(location* ptr, int* data) {
    int state;
    char temp;
    FILE* fp = fopen("test.txt", "rt");

    if (fp == NULL) {
        printf("파일을 여는데 오류가 발생했습니다!\n");
        return 1;
    }

    //파일에 저장된 데이터를 구조체 배열에 저장
    while (1) {
        fscanf(fp, "%s %s %s", ptr[*data].product, ptr[*data].address, ptr[*data].kind);
        if (feof(fp) != 0)                                              // 파일에 끝에 도달하면 탈출
            break;
        (*data)++;
    }



    /* fclose함수는 종료시 오류가 발생하면
    0이 아닌 다른값을 리턴하므로 비정상 종료로 판단되면
    안내후 프로그램을 종료 */
    state = fclose(fp);
    if (state != 0) {
        printf("오류가 발생했습니다!\n");
        return 1;
    }

    return 0;
}



void insert(location* ptr, int* data) {         //상품 정보를 삽입하는 함수
    if (*data < 200) {              //상품 정보가 꽉 차지 않으면
        printf("\n추가할 제품 이름을 입력해 주세요(스페이스바 대신 - 사용): ");
        scanf("%s", ptr[*data].product);
        printf("\n%s의 제품 종류를 입력해 주세요(스페이스바 대신 - 사용): ", ptr[*data].product);
        scanf("%s", ptr[*data].kind);
        printf("\n%s의 제품 위치를 입력해 주세요(스페이스바 대신 - 사용, ex.1층,2층-3번째칸): ", ptr[*data].product);
        scanf("%s", ptr[*data].address);


        (*data)++;
        printf(" \n제품이 추가되었습니다....");
    }
    //상품 정보가 꽉 차면
    else
        printf(" \n저장량이 초과되었습니다. 제품을 삭제한 후 추가해주세요");
    Sleep(2000);
    system("cls");
}



//상품의 정보를 삭제하는 함수
int deleted(location* ptr, int* data) {
    char product[200];
    int a, b;
    system("cls");
    //상품 정보가 한개라도 남아있으면
    if (*data > 0) {
        printf("\n삭제할 제품 이름을 입력해주세요: ");
        scanf("%s", product);

        for (a = 0; a < 200; a++) {
            //문자열이므로 비교하기위해 strcmp사용
            if (strcmp(product, ptr[a].product) == 0) {

                (*data)--;
                printf("\n제품의 정보가 삭제되었습니다....");

                //데이터가 가득 차지 않았다면
                if (a != 200 - 1) {
                    for (b = a; b < 200; b++) {
                        //문자열이므로 strcpy를 사용하여 데이터 복사
                        strcpy(ptr[b].product, ptr[b + 1].product);
                        strcpy(ptr[b].kind, ptr[b + 1].kind);
                        strcpy(ptr[b].address, ptr[b + 1].address);
                    }


                    //구조체 배열의 마지막을 NULL로 바꿈
                    *ptr[200 - 1].product = NULL;
                    *ptr[200 - 1].kind = NULL;
                    *ptr[200 - 1].address = NULL;
                }


                //데이터가 가득 찼다면
                else {
                    //구조체 배열의 마지막을 NULL로 바꿈
                    *ptr[200 - 1].product = NULL;
                    *ptr[200 - 1].kind = NULL;
                    *ptr[200 - 1].address = NULL;
                }
                return 0;
            }
        }

    }
    //저장된 상품 정보가 없다면

    else 
        printf("\n입력한 제품의 정보가 없습니다.");

    
    Sleep(2000);
    system("cls");
}



//상품의 정보를 검색하는 함수
int find(location* ptr, int* data) {
    char product[200];
    char kind[200];
    int a;
    int c=0;
    system("cls");

    printf("┌──────────┐\n");
    printf("│1번 : 이름│\n");
    printf("│2번 : 종류│\n");
    printf("└──────────┘\n");
    printf("어떤 정보를 통해 위치를 검색하시겠습니까?(숫자만 입력) : "); 
    c = _getch() - 48;

    switch (c)                  // 번호 입력시 기능 출력
    {
    case 1:
        //저장된 데이터가 있다면
        if (*data > 0) {
            printf("\n 제품 이름을 입력해 주세요: ");
            scanf("%s", product);



            for (a = 0; a < 200; a++) {
                //strstr를 통해 한 문자만 입력해도 검색 가능하도록 설정
                if (strstr(ptr[a].product, product) != NULL) {

                        printf("\n제품명 %s의 위치는 %s 입니다.\n ", ptr[a].product, ptr[a].address);

                    }
                
            }

        }
        else {
            printf("\n저장된 제품의 정보가 없습니다.");
            return 0;
        }
        Sleep(2000);
        break;
    case 2:
        //저장된 데이터가 있다면
        if (*data > 0) {
            printf("\n 종류를 입력해 주세요: ");
            scanf("%s", kind);



            for (a = 0; a < 200; a++) {
                //strstr를 통해 한 문자만 입력해도 검색 가능하도록 설정
                if (strstr(ptr[a].kind, kind) != NULL) {

                        printf("\n %s 종류의 %s 제품의 위치는 %s 입니다.\n ", ptr[a].kind, ptr[a].product,ptr[a].address);

                    }
                }
            

        }
        else {
            printf("\n저장된 제품의 정보가 없습니다.");
            return 0;
        }
        Sleep(2000);
        break;
    }
}

// 모든 제품 출력 함수
void all(location* ptr, int* data) {
    int a, j = 0;
    int white = 7;          // 글자색 변경을 위한 번호 설정
    int red = 4;            // 글자색 변경을 위한 번호 설정
    system("cls");
    if (*data > 0) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), red);          // 글자색을 빨간색으로 변경
        printf("\n모든 제품의 위치\n");
        printf("\n1층 제품의 위치\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);        // 글자색 다시 화이트로 변경
        printf("┌────────────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
        printf("│              제품 이름                      종류                             제품 위치                 │\n");
        printf("├────────────────────────────────────────────────────────────────────────────────────────────────────────┤\n");
        for (a = 0; a < *data; a++) {
            if (strncmp(ptr[a].address, "1", 1) == NULL) {              // strncmp를 통해 주소정보의 첫번째칸이 1일때 출력
                printf("│             %-20s            %-20s               %-20s    │\n", ptr[a].product, ptr[a].kind, ptr[a].address);
            }
        }

        printf("└────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), red);
        printf("\n2층 제품의 위치\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
        printf("┌────────────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
        printf("│              제품 이름                      종류                             제품 위치                 │\n");
        printf("├────────────────────────────────────────────────────────────────────────────────────────────────────────┤\n");
        for (a = 0; a < *data; a++) {
            if (strncmp(ptr[a].address, "2", 1) == NULL) {              // strncmp를 통해 주소정보의 첫번째칸이 2일때 출력          
                printf("│             %-20s            %-20s               %-20s    │\n", ptr[a].product, ptr[a].kind, ptr[a].address);
            }
        }

        printf("└────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), red);
        printf("\n3층 제품의 위치\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
        printf("┌────────────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
        printf("│              제품 이름                      종류                             제품 위치                 │\n");
        printf("├────────────────────────────────────────────────────────────────────────────────────────────────────────┤\n");
        for (a = 0; a < *data; a++) {
            if (strncmp(ptr[a].address, "3", 1) == NULL) {              // strncmp를 통해 주소정보의 첫번째칸이 3일때 출력
                printf("│             %-20s            %-20s               %-20s    │\n", ptr[a].product, ptr[a].kind, ptr[a].address);
            }
        }

        printf("└────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), red);
        printf("\n4층 제품의 위치\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
        printf("┌────────────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
        printf("│              제품 이름                      종류                             제품 위치                 │\n");
        printf("├────────────────────────────────────────────────────────────────────────────────────────────────────────┤\n");
        for (a = 0; a < *data; a++) {
            if (strncmp(ptr[a].address, "4", 1) == NULL) {              // strncmp를 통해 주소정보의 첫번째칸이 4일때 출력
                printf("│             %-20s            %-20s               %-20s    │\n", ptr[a].product, ptr[a].kind, ptr[a].address);
            }
        }

        printf("└────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), red);
        printf("\n5층 제품의 위치\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
        printf("┌────────────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
        printf("│              제품 이름                      종류                             제품 위치                 │\n");
        printf("├────────────────────────────────────────────────────────────────────────────────────────────────────────┤\n");
        for (a = 0; a < *data; a++) {
            if (strncmp(ptr[a].address, "5", 1) == NULL) {              // strncmp를 통해 주소정보의 첫번째칸이 5일때 출력
                printf("│             %-20s            %-20s               %-20s    │\n", ptr[a].product, ptr[a].kind, ptr[a].address);
            }
        }

        printf("└────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
    }


    else
        printf("데이터를 불러올 수 없습니다. 다시 실행해 주세요 \n\n");
    Sleep(2000);
}