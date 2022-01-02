#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <conio.h> 
#include <windows.h> 
#include <mmsystem.h> 
#pragma comment(lib, "winmm.lib") //윈도우의 멀티미디어 라이브러리

//키보드 값 정의
#define UP 0
#define DOWN 1
#define ENTER 13

void gotoxy(int, int); //커서 위치 이동 함수 gotoxy 선언
int keycontrol(); //키보드 제어 함수 keycontrol 선언


void mu() //주크박스 함수 시작
{
    int a = 45; //메뉴 시작 x 좌표
    int b = 5; //메뉴 시작 y 좌표

    system("cls"); //화면 전체 지우기(main 화면)

    //재생 중지 버튼
    gotoxy(a+2, b);
    printf("정지");

    //재생목록 리스트
    gotoxy(a + 2, b + 5);
    printf("Lioness");

    gotoxy(a + 2, b + 7);
    printf("Diviners");

    gotoxy(a + 2, b + 9);
    printf("Inside Your Eyes");

    gotoxy(a + 2, b + 11);
    printf("Friends by giulio cercato");

    gotoxy(a + 2, b + 13);
    printf("One Love");

    gotoxy(a + 2, b + 15);
    printf("Lost");

    gotoxy(a + 2, b + 17);
    printf("Lioness DayFox");

    gotoxy(a + 2, b + 19);
    printf("Survive");

    //메인 메뉴로 리턴 버튼
    gotoxy(a + 2, b + 24);
    printf("종료");

    while (1) //무한루프
    {
        int m = keycontrol();

        switch (m)
        {
        case UP: //방향키(↑)를 입력했을 경우
        {
            if (b > 5)
            {
                gotoxy(a, b);
                printf(" ");
                gotoxy(a, --b);
                printf(">");
            }

            break;
        }

        case DOWN: //방향키(↓)를 입력했을 경우
        {
            if (b < 34)
            {
                gotoxy(a, b);
                printf(" ");
                gotoxy(a, ++b);
                printf(">");
            }

            break;
        }

        case ENTER: //엔터를 입력했을 경우
        {
            if (b == 5) //종료
            {
                PlaySound(NULL, 0, 0); //재생 중지
            }

            //이 아래부터는 재생목록 , 기본적으로 반복 재생되며 다른 화면으로 이동해도 재생 유지

            else if (b == 10) //첫번째 곡
            {
                PlaySound(TEXT("Lioness"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
            }

            else if (b == 12) //두번째 곡
            {
                PlaySound(TEXT("Diviners"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
            }

            else if (b == 14) //세번째 곡
            {
                PlaySound(TEXT("Inside Your Eyes"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
            }

            else if (b == 16) //네번째 곡
            {
                PlaySound(TEXT("Friends by giulio cercato"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
            }

            else if (b == 18) //다섯번째 곡
            {
                PlaySound(TEXT("One Love"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
            }

            else if (b == 20) //여섯번째 곡
            {
                PlaySound(TEXT("Lost"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
            }

            else if (b == 22) //일곱번째 곡
            {
                PlaySound(TEXT("Lioness DayFox"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
            }

            else if (b == 24) //여덟번째 곡
            {
                PlaySound(TEXT("Survive"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
            }
            else if (b == 29) //ESC
            {
                return; //메인 메뉴로 리턴
            }
        }
        }
    }
}

