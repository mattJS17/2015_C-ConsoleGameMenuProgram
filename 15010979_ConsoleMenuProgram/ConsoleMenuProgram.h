#include <stdio.h>
#include <stdlib.h> //system() 사용하기 위해서, srand(), rand()
#include <time.h>   //for time()
#include <string.h> //for strlen(),strcmp()



// 상수 선언부

#define DIE_SIMULATION   1    //DIE_SIMULATION=1로 정의한다.
#define GAME_SHOW        2    //GAME_SHOW=2로 정의한다.
#define HIGH_LOWGAME     3    //HIGH_LOWGAME=3로 정의한다.
#define WORD_GAME		4   //WORD_GAME=4로 정의한다.
#define OX_GAME			5// OX_GAME=5로 정의한다
#define STAR_GAME		6//STAR_GAME=6으로 정의한다
#define EXIT    0             //EXIT=0로 정의한다.

#define TRUE    1             //TRUE=1로 정의한다.C언어에는 boolean함수가 없기 때문
#define FALSE   0             //FALSE=0로 정의한다.

#define MAX     10000         //MAX=10000로 정의한다.

//함수 선언부
/*----------------------------------
displayMainMenu()함수는 화면에 메인
메뉴를 출력하고, 입력된 메인메뉴값(정수)를
리턴한다.
----------------------------------*/
int displayMainMenu();

/*---------------------------------
//메뉴별 사용자 정의 함수들
----------------------------------*/
void dieSimulation();
void gameShow();
void highLowGame();
void wordGame();//menu들 정의되었음.

//----------------------------
//  5번 oXGame() 관련 함수들
//----------------------------
void OXGame();//본 게임
void displayOX(char strArray[]);//OX게임 화면
void playOX(char strArray[], char player);//플레이 제어
char winCheck(char strArray[]);//승패 결정
void inputOX(char strArray[], char Player, int num);
//6번 메뉴 추가된 헤더
#include <conio.h>//getch, putch 용
#include <windows.h>//system, sleep, setConsoleCursorPosition 용
#include <stdio.h> // printf,scanf용
#include <time.h>//time 용
#include <stdlib.h>//rand, srand용

#define STAR "★"//특수 문자열 "★"의 매크로 상수
#define INTERVAL 300//별 반짝임의 주기(ms)
#define STARMIN 5//최소 별 반짝임 횟수 
#define STARMAX 12//최대 별 반짝임 횟수 - 위의 MAX와 차이를 두어 중복을 피한다.
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