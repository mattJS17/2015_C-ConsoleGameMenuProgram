#include <stdio.h>
#include <stdlib.h> //system() ����ϱ� ���ؼ�, srand(), rand()
#include <time.h>   //for time()
#include <string.h> //for strlen(),strcmp()



// ��� �����

#define DIE_SIMULATION   1    //DIE_SIMULATION=1�� �����Ѵ�.
#define GAME_SHOW        2    //GAME_SHOW=2�� �����Ѵ�.
#define HIGH_LOWGAME     3    //HIGH_LOWGAME=3�� �����Ѵ�.
#define WORD_GAME		4   //WORD_GAME=4�� �����Ѵ�.
#define OX_GAME			5// OX_GAME=5�� �����Ѵ�
#define STAR_GAME		6//STAR_GAME=6���� �����Ѵ�
#define EXIT    0             //EXIT=0�� �����Ѵ�.

#define TRUE    1             //TRUE=1�� �����Ѵ�.C���� boolean�Լ��� ���� ����
#define FALSE   0             //FALSE=0�� �����Ѵ�.

#define MAX     10000         //MAX=10000�� �����Ѵ�.

//�Լ� �����
/*----------------------------------
displayMainMenu()�Լ��� ȭ�鿡 ����
�޴��� ����ϰ�, �Էµ� ���θ޴���(����)��
�����Ѵ�.
----------------------------------*/
int displayMainMenu();

/*---------------------------------
//�޴��� ����� ���� �Լ���
----------------------------------*/
void dieSimulation();
void gameShow();
void highLowGame();
void wordGame();//menu�� ���ǵǾ���.

//----------------------------
//  5�� oXGame() ���� �Լ���
//----------------------------
void OXGame();//�� ����
void displayOX(char strArray[]);//OX���� ȭ��
void playOX(char strArray[], char player);//�÷��� ����
char winCheck(char strArray[]);//���� ����
void inputOX(char strArray[], char Player, int num);
//6�� �޴� �߰��� ���
#include <conio.h>//getch, putch ��
#include <windows.h>//system, sleep, setConsoleCursorPosition ��
#include <stdio.h> // printf,scanf��
#include <time.h>//time ��
#include <stdlib.h>//rand, srand��

#define STAR "��"//Ư�� ���ڿ� "��"�� ��ũ�� ���
#define INTERVAL 300//�� ��¦���� �ֱ�(ms)
#define STARMIN 5//�ּ� �� ��¦�� Ƚ�� 
#define STARMAX 12//�ִ� �� ��¦�� Ƚ�� - ���� MAX�� ���̸� �ξ� �ߺ��� ���Ѵ�.
void Star_Game();
void draw_rectangle(int start_x, int start_y, int width, int height);
void gotoxy(int, int);

#define LEFT	75
#define RIGHT	77
#define UP		72
#define DOWN	80
#define ENTER	13

#define MIN_X	3
#define MIN_Y	5
#define MAX_X	21
#define MAX_Y	12
#define TAB_X	8
#define TAB_Y	3