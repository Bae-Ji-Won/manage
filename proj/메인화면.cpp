#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //표준입출력 라이브러리
#include <conio.h> //콘솔입출력 라이브러리
#include <windows.h> //윈도우의 C 라이브러리

//키보드 값 정의
#define UP 0
#define DOWN 1
#define ENTER 13


void console();//콘솔 함수 console 선언
void title(); //타이틀 함수 title 선언
void gotoxy(int, int); //커서 위치 이동 함수 gotoxy 선언
int keycontrol(); //키보드 제어 함수 keycontrol 선언
int menu(); //메뉴 함수 menu 선언
void mu();
void loca();
void jaeg();

int main(void) //main 함수 시작
{ //콘솔 함수 console 호출
	while (1) //무한루프
	{
		console();
		title(); //타이틀 함수 title 호출
		
		int select = menu(); //메뉴 선택 변수 select 선언
		
		if (select == 0)
		{
			jaeg(); //재고
		}

		else if (select == 1)
		{
			loca(); //위치
		}

		else if (select == 2)
		{
			mu(); //음악
		}

		else if (select == 3)
		{
			return 0; //프로그램 종료
		}
		
		system("cls"); //초기 화면으로 돌아가는 코드
	}

	return 0; //종료
}

void console() //콘솔 함수 console 시작
{
   system("mode con cols=110 lines=40"); //콘솔창 크기 설정(가로:150 , 세로:40)
    //콘솔창 제목 설정
}

void title() //타이틀 함수 title 시작
{
   printf("\n\n\n\n\n");
   printf(" □          □          □□         □         □          □□         □□□□□□□       □□□□□□  \n");
   printf(" □□      □□         □  □        □□       □         □  □        □                   □            \n");
   printf(" □ □    □ □        □    □       □ □      □        □    □       □                   □            \n");
   printf(" □  □  □  □       □      □      □  □     □       □      □      □                   □            \n");
   printf(" □   □□   □      □        □     □   □    □      □        □     □      □□□□     □□□□□□  \n");
   printf(" □    □    □     □□□□□□□    □    □   □     □□□□□□□    □            □     □            \n");
   printf(" □          □    □            □   □     □  □    □            □   □□□□□□  □     □            \n");
   printf(" □          □   □              □  □      □ □   □              □                □     □            \n");
   printf(" □          □  □                □ □       □□  □                □               □     □□□□□□  \n");
}
                                        
void gotoxy(int x, int y) //커서 위치 이동 함수 gotoxy 시작
{
   //콘솔 핸들 호출
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   COORD pos;
   pos.X = x;
   pos.Y = y;
   SetConsoleCursorPosition(consoleHandle, pos);
}

int keycontrol() //키보드 제어 함수 keycontrol 시작
{
	int ch = _getch();

	if (ch == 0xE0 || ch == 0x00) //확장키(방향키 등) 입력했을 경우
	{
		ch = _getch(); 

		if (ch == 72) //방향키(↑)
		{
			return UP; //0 반환
		}

		else if (ch == 80) //방향키(↓)
		{
			return DOWN; //1 반환
		}
	}

	else if (ch == 13) //선택 = 스페이스바
	{
		return ENTER; //2 반환
	}
}

int menu() //메뉴 함수 menu 시작
{
   int x = 50; //메뉴 가로축 표시 지점
   int y = 25; //메뉴 세로축 표시 지점

   gotoxy(x - 2, y);
   printf("> 1. 재고관리");
   gotoxy(x, y + 1);
   printf("2. 위치찾기 ");
   gotoxy(x, y + 2);
   printf("3. 음악재생");
   gotoxy(x, y + 3);
   printf("5. 종료");
   

   while (1) //무한루프
   {
      int n = keycontrol();

      switch (n)
      {
      case UP: //방향키(↑)를 입력했을 경우
      {
         if (y > 25)
         {
            gotoxy(x - 2, y);
            printf(" ");
            gotoxy(x - 2, --y);
            printf(">");
         }

         break;
      }

      case DOWN: //방향키(↓)를 입력했을 경우
      {
         if (y < 30)
         {
            gotoxy(x - 2, y);
            printf(" ");
            gotoxy(x - 2, ++y);
            printf(">");
         }

         break;
      }
	  case ENTER: //스페이스바를 입력했을 경우
		{
			return y - 25;
      }
      }
   }
}