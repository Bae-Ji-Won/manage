#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //ǥ������� ���̺귯��
#include <conio.h> //�ܼ������ ���̺귯��
#include <windows.h> //�������� C ���̺귯��

//Ű���� �� ����
#define UP 0
#define DOWN 1
#define ENTER 13


void console();//�ܼ� �Լ� console ����
void title(); //Ÿ��Ʋ �Լ� title ����
void gotoxy(int, int); //Ŀ�� ��ġ �̵� �Լ� gotoxy ����
int keycontrol(); //Ű���� ���� �Լ� keycontrol ����
int menu(); //�޴� �Լ� menu ����
void mu();
void loca();
void jaeg();

int main(void) //main �Լ� ����
{ //�ܼ� �Լ� console ȣ��
	while (1) //���ѷ���
	{
		console();
		title(); //Ÿ��Ʋ �Լ� title ȣ��
		
		int select = menu(); //�޴� ���� ���� select ����
		
		if (select == 0)
		{
			jaeg(); //���
		}

		else if (select == 1)
		{
			loca(); //��ġ
		}

		else if (select == 2)
		{
			mu(); //����
		}

		else if (select == 3)
		{
			return 0; //���α׷� ����
		}
		
		system("cls"); //�ʱ� ȭ������ ���ư��� �ڵ�
	}

	return 0; //����
}

void console() //�ܼ� �Լ� console ����
{
   system("mode con cols=110 lines=40"); //�ܼ�â ũ�� ����(����:150 , ����:40)
    //�ܼ�â ���� ����
}

void title() //Ÿ��Ʋ �Լ� title ����
{
   printf("\n\n\n\n\n");
   printf(" ��          ��          ���         ��         ��          ���         ��������       �������  \n");
   printf(" ���      ���         ��  ��        ���       ��         ��  ��        ��                   ��            \n");
   printf(" �� ��    �� ��        ��    ��       �� ��      ��        ��    ��       ��                   ��            \n");
   printf(" ��  ��  ��  ��       ��      ��      ��  ��     ��       ��      ��      ��                   ��            \n");
   printf(" ��   ���   ��      ��        ��     ��   ��    ��      ��        ��     ��      �����     �������  \n");
   printf(" ��    ��    ��     ��������    ��    ��   ��     ��������    ��            ��     ��            \n");
   printf(" ��          ��    ��            ��   ��     ��  ��    ��            ��   �������  ��     ��            \n");
   printf(" ��          ��   ��              ��  ��      �� ��   ��              ��                ��     ��            \n");
   printf(" ��          ��  ��                �� ��       ���  ��                ��               ��     �������  \n");
}
                                        
void gotoxy(int x, int y) //Ŀ�� ��ġ �̵� �Լ� gotoxy ����
{
   //�ܼ� �ڵ� ȣ��
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   COORD pos;
   pos.X = x;
   pos.Y = y;
   SetConsoleCursorPosition(consoleHandle, pos);
}

int keycontrol() //Ű���� ���� �Լ� keycontrol ����
{
	int ch = _getch();

	if (ch == 0xE0 || ch == 0x00) //Ȯ��Ű(����Ű ��) �Է����� ���
	{
		ch = _getch(); 

		if (ch == 72) //����Ű(��)
		{
			return UP; //0 ��ȯ
		}

		else if (ch == 80) //����Ű(��)
		{
			return DOWN; //1 ��ȯ
		}
	}

	else if (ch == 13) //���� = �����̽���
	{
		return ENTER; //2 ��ȯ
	}
}

int menu() //�޴� �Լ� menu ����
{
   int x = 50; //�޴� ������ ǥ�� ����
   int y = 25; //�޴� ������ ǥ�� ����

   gotoxy(x - 2, y);
   printf("> 1. ������");
   gotoxy(x, y + 1);
   printf("2. ��ġã�� ");
   gotoxy(x, y + 2);
   printf("3. �������");
   gotoxy(x, y + 3);
   printf("5. ����");
   

   while (1) //���ѷ���
   {
      int n = keycontrol();

      switch (n)
      {
      case UP: //����Ű(��)�� �Է����� ���
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

      case DOWN: //����Ű(��)�� �Է����� ���
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
	  case ENTER: //�����̽��ٸ� �Է����� ���
		{
			return y - 25;
      }
      }
   }
}