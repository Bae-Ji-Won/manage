#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <conio.h> 
#include <windows.h> 
#include <mmsystem.h> 
#pragma comment(lib, "winmm.lib") //�������� ��Ƽ�̵�� ���̺귯��

//Ű���� �� ����
#define UP 0
#define DOWN 1
#define ENTER 13

void gotoxy(int, int); //Ŀ�� ��ġ �̵� �Լ� gotoxy ����
int keycontrol(); //Ű���� ���� �Լ� keycontrol ����


void mu() //��ũ�ڽ� �Լ� ����
{
    int a = 45; //�޴� ���� x ��ǥ
    int b = 5; //�޴� ���� y ��ǥ

    system("cls"); //ȭ�� ��ü �����(main ȭ��)

    //��� ���� ��ư
    gotoxy(a+2, b);
    printf("����");

    //������ ����Ʈ
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

    //���� �޴��� ���� ��ư
    gotoxy(a + 2, b + 24);
    printf("����");

    while (1) //���ѷ���
    {
        int m = keycontrol();

        switch (m)
        {
        case UP: //����Ű(��)�� �Է����� ���
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

        case DOWN: //����Ű(��)�� �Է����� ���
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

        case ENTER: //���͸� �Է����� ���
        {
            if (b == 5) //����
            {
                PlaySound(NULL, 0, 0); //��� ����
            }

            //�� �Ʒ����ʹ� ������ , �⺻������ �ݺ� ����Ǹ� �ٸ� ȭ������ �̵��ص� ��� ����

            else if (b == 10) //ù��° ��
            {
                PlaySound(TEXT("Lioness"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
            }

            else if (b == 12) //�ι�° ��
            {
                PlaySound(TEXT("Diviners"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
            }

            else if (b == 14) //����° ��
            {
                PlaySound(TEXT("Inside Your Eyes"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
            }

            else if (b == 16) //�׹�° ��
            {
                PlaySound(TEXT("Friends by giulio cercato"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
            }

            else if (b == 18) //�ټ���° ��
            {
                PlaySound(TEXT("One Love"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
            }

            else if (b == 20) //������° ��
            {
                PlaySound(TEXT("Lost"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
            }

            else if (b == 22) //�ϰ���° ��
            {
                PlaySound(TEXT("Lioness DayFox"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
            }

            else if (b == 24) //������° ��
            {
                PlaySound(TEXT("Survive"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
            }
            else if (b == 29) //ESC
            {
                return; //���� �޴��� ����
            }
        }
        }
    }
}

