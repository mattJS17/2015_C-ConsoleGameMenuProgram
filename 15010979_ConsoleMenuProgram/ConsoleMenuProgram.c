#include "ConsoleMenuProgram.h"

int main()
{
	int nSelectedMainMenu;//선택된 메인메뉴 값을 나타내는 변수
	int bIterationFlag = TRUE;

	srand(time(NULL)); // seeds 설정

	while (bIterationFlag) {
		system("cls");//메뉴 실행후에 실행된 창을 지우는 함수
		nSelectedMainMenu = displayMainMenu(); // 함수 호출

		system("cls");

		/* if문 사용할 때
		if (nSelectedMainMenu ==1) { menu1(); }
		else if (nSelectedMainMenu == 2) { menu2(); }
		else if (nSelectedMainMenu == 3) { menu3(); }
		else if (nSelectedMainMenu == 4) { menu4(); }
		else { printf("잘못 누르셨습니다.\n"); }
		*/

		switch (nSelectedMainMenu) {
		case DIE_SIMULATION: dieSimulation(); break;                             //초기화면에서 실행되는 메뉴들이며
		case GAME_SHOW: gameShow(); break;                                  //각 메뉴를 실행할 때마다 기존의 화면을 지우고 실행한 메뉴를 화면에 나타내는 것을 반복.
		case HIGH_LOWGAME: highLowGame(); break;                               //정해진 수 이외의 수를 입력하면 default의 
		case WORD_GAME: wordGame(); break;                                  //printf문을 출력하고 0을 입력하면 반복을 중단 .
		case OX_GAME: OXGame();	break;
		case STAR_GAME: Star_Game(); break;
		case EXIT:
			printf("GOOD-BYE!!\n");
			bIterationFlag = FALSE;
			break; // escape condition
		default: printf("잘못 누르셨습니다.\n"); break;
		} // switch (정수 값일때만 가능)
		system("pause");
	} // while

	/* test
	system("cls"); //clear screen
	printf("%d번을 선택하였습니다.\n", nSelectedMainMenu);
	*/

	return 0;
}   // main()

//함수 구현부
int displayMainMenu() {

	int nMainMenu;

	printf("\n\n");
	printf("============================\n");
	printf("          MAIN MENU\n");
	printf("----------------------------\n");              //프로그램을 실행하면 나오는 초기화면으로 
	printf("    1. DIE_SIMULATION\n");                     //이 화면에서 메뉴선택을 하거나 프로그램
	printf("    2. GAME_SHOW\n");                          //종료를 할수 있다.
	printf("    3. HIGH-LOW GAME\n");
	printf("    4. WORD GAME\n");
	printf("    5. OX Game\n");
	printf("    6. STAR GAME\n");
	printf("----------------------------\n");
	printf("    0. EXIT\n");
	printf("============================\n");
	printf("    >> ");
	scanf("%d", &nMainMenu);                                //원하는 메뉴의 숫자를 입력 .

	return nMainMenu;                                      //입력한 메뉴의 숫자를 반환 .

} // displayMainMenul

void dieSimulation() {

	int nFaceValue, nSum = 0, nCount = 0;
	int i, nIteration;
	double lfAvgCount;

	printf("============================\n");
	printf("     DIE SIMULATION\n");                            //초기화면에서 dieSimulation를 선택하면 나오는 화면으로
	printf("----------------------------\n\n");                 //몇번을 반복할지 묻는 printf문을 출력 .

	printf(" 몇번 반복하시겠습니까? >> ");
	scanf("%d", &nIteration);                                   //반복횟수 입력 .

	for (i = 0; i < nIteration; i++) {                               //입력한 수만큼 while문을 반복 .
		while (nSum < 100) {
			nFaceValue = rand() % 6 + 1;     // 1~6                 //nFaceValue는 주사위의 숫자로 1~6까지의 수가 랜덤하게 나온다.
			nSum += nFaceValue;                                 //nSum이 100을 넘을때까지 랜덤으로 나온 1~6까지의 수를 더하고
			nCount++;                                           //nSum이 100을 넘으면 nCount를 +1하고 nSum의 값을 0으로 초기화 .
		} // while
		nSum = 0;
	} // for

	lfAvgCount = (double)nCount / nIteration;	// calc. average       //nCount를 nlteration으로 나누어서 lfAvgCount를 구 .
																	   //이때, 소수점까지 나타내기 위해 (double)를 붙힌다.
	system("cls");
	printf("============================\n");
	printf("     DIE SIMULATION RESULT\n");
	printf("----------------------------\n\n");
	printf("  %d번 모의실험한 결과,\n", nIteration);               //dieSimulation에서 입력받은 반복한 수인 nlteration와 
	printf("  %.2lf번을 던져야\n", lfAvgCount);                   //위에서 연산한 값인 lfAvgCount를 넣어 printf문을 출력 .
	printf("  그 누적합이 100을 넘습니다.\n\n");
	printf("============================\n");

} // dieSimulation()

void gameShow() {

	int nPrizeDoor, nChoiceDoor, nRevealDoor, nSwitchDoor;
	int nChoiceCount = 0, nSwitchCount = 0;
	double lfChoice, lfSwitch;
	int i;

	printf("\n");
	printf("=================================================\n");          //gameShow 메뉴를 선택하면 해당 printf문을 출력 .
	printf("           The Money Hall Game Show\n");
	printf("-------------------------------------------------\n\n");

	for (i = 0; i < MAX; i++) {                                                  //for반복문을 MAX번 반복 .
		nPrizeDoor = rand() % 3;  // 0-2                                      //nPrizeDoor는 0~2의 숫자 중 하나가 랜덤으로 골라지고
		nChoiceDoor = rand() % 3; // 0-2                                      //nChoiceDoor도 0~2의 숫자 중 하나가 랜덤으로 골라진다.
		if (nPrizeDoor == nChoiceDoor) { nChoiceCount++; }                    //만약 nPrizeDoor와 nChoiceDoor의 수가 같으면 nChoiceCount를 +1 .
	} // for


	lfChoice = (double)nChoiceCount / MAX * 100;                               //nChoiceCount를 MAX으로 나눈 수에 100을 곱해 lfchoice의 확률을 구 .
																			 //이때, 소수점까지 계산하기위해 (double)을 붙힌다.
	printf("  선택한 문이 당첨될 확률은 %.2lf%% 입니다.\n\n", lfChoice);        //위의 연산에서 나온 lfchoice의 값을 넣어 printf문을 출력 .


	for (i = 0; i < MAX; i++) {                                                                    //for반복문을 MAX번 반복 .
		nPrizeDoor = rand() % 3; // 0-2                                                          //nPrizeDoor는 0~2의 숫자 중 하나가 랜덤으로 골라지고
		nChoiceDoor = rand() % 3;                                                                //nChoiceDoor도 0~2의 숫자 중 하나가 랜덤으로 골라진다.

		nRevealDoor = 0;                                                                       //nRevealDoor=0부터 시작해서 nRevealDoor와 nPrizeDoor가 같거나
		while (nRevealDoor == nPrizeDoor || nRevealDoor == nChoiceDoor) { nRevealDoor++; }          //nRevealDoor와 nChoiceDoor가 같으면 nRevealDoor를 +1 .

		nSwitchDoor = 0;                                                                       //nSwitchDoor=0부터 시작해서 nSwitchDoor와 nChoiceDoor가 같거나
		while (nSwitchDoor == nChoiceDoor || nSwitchDoor == nRevealDoor) { nSwitchDoor++; }     //nSwitchDoor와 nRevealDoor가 같으면 nSwitchDoor를 +1 .

		if (nSwitchDoor == nPrizeDoor) { nSwitchCount++; }                                     //만약 nSwitchDoor와 nPrizeDoor의 값이 같다면 nSwitchCount를 +1 .
	} // for

	lfSwitch = (double)nSwitchCount / MAX * 100;                                 //nSwitchCount를 MAX(10000)으로 나눈 수에 100을 곱해 lfSwitch의 확률을 구 .
																			   //이때, 소수점까지 계산하기위해 (double)을 붙힌다
	printf("  변경한 문이 당첨될 확률은 %.2lf%% 입니다.\n\n", lfSwitch);          //위의 연산에서 나온 lfSwitch의 값을 넣어 printf문을 출력 .
	printf("=================================================\n");

} // gameShow()

void highLowGame() {

	int nRandom, nInput;
	int low = 1, high = 100, count = 0;

	nRandom = rand() % 100 + 1; // 1~100까지 숫자 중 랜덤으로 하나의 숫자를 선택 .

	while (TRUE) {
		system("cls");
		printf("\n");
		printf("================================================\n");            //highLowgame 메뉴를 선택하면 나오는 화면으로
		printf("              HIGH-LOW GAME\n");                                 //low에서 high까지 숫자 입력하라는 말을 출력 .
		printf("------------------------------------------------\n");            //low와 high에 의해 숫자를 입력할 때마다 범위변경.
		printf("\n");
		printf("   숫자 하나(%d ~ %d)를 입력하세요 >>  ", low, high);

		scanf("%d", &nInput); // 숫자 하나 입력받기

		count++; // 숫자를 입력할 때마다 +1을 더 .
		printf("\n");

		if (nRandom < nInput) {                                                     //  랜덤으로 정해진 수보다 크면 해당 printf문을 출력하고
			printf("   입력한 숫자 %d이(가) 더 큽니다.\n", nInput);                 //다시 반복문의 printf문을 출력할 때 high에 입력한 숫자를 넣는다.
			high = nInput;
		}
		else if (nRandom > nInput) {                                               //  랜덤으로 정해진 수보다 작으면 해당 printf문을 출력하고
			printf("   입력한 숫자 %d이(가) 더 작습니다.\n", nInput);              //다시 반복문의 printf문을 출력할 때 low에 입력한 숫자를 넣는다. 
			low = nInput;
		}
		else {
			printf("   입력한 숫자 %d이(가) 맞습니다.\n", nInput);                 //랜덤으로 정해진 수라면 해당 printf문을 출력하고
			printf("   맞추는데 총 %d 회 걸렸습니다.\n", count);                   //맞출 때 까지의 count 변수를 이용해 printf문을 출력 .
			printf("\n");                                                       //또한 숫자를 맞추면 무한반복문의 작동을 멈춘다.
			printf("================================================\n");
			break;
		}

		printf("\n");
		printf("================================================\n");             //무한 반복문의 탈출조건을 만족시키면 highLowGame의 작동을 중지시킨다.
		system("pause");
	}
}//highLowGame



void wordGame()
{
	char strWords[10][40] = {//이차원배열 strWords선언으로 40글자까지 10개 가능함
		"boyfriend",
		"girlfriend",
		"doctor",
		"student",
		"computer",
		"information",
		"university",
		"monitor",
		"mouse",
		"software" };

	char strAnswer[40];//일차원배열 strAnswer선언으로 40글자까지 가능, nLength의 글자 길이에 '_'를 나오게 하는 변수
	int nRandom, nLength, i;//nRandom은 strWords의 글자중에서 0~9사이의 길이의 글자를 무작위로 나오게 하기 위한 변수이며, nLength는 nRandom에서 무작위로 strWords에서 나올 글자의 길이를 대입할 변수이다. i는 for문의 반복변수 i를 선언한 것이다
	char chInput;//wordGame에서 써서 넣을 변수 선언
	char strAlphabet[27] = "abcdefghijklmnopqrstuvwxyz";//a~z까지 있는 일차원배열 strAlphabet 선언.
	int count = 0;//몇 번 입력했는지 카운트하기 위한 변수 선언
	char strInput[40];
	int  nInputLength;

	nRandom = rand() % 10; // 0-9

	nLength = strlen(strWords[nRandom]);//strWords 배열안에 있는 것 중에서 0~9 한 개를 랜덤으로 골라서 그 길이를 nStrLength에 대입함.
	for (i = 0; i < nLength; i++) {//i가 nStrLength보다 작을 때까지 반복
		strAnswer[i] = '_';//반복된 만큼 strAnswer[i]에 _를 넣는다.
	} // for
	strAnswer[nLength] = '\0';//nStrLength읠 길이만큼 strAnswer에 넣으면 그 단어가 끝났음을 통보함.

	while (TRUE) {//TRUE = 1. 무한반복이다.
		system("cls");
		printf("\n\n");
		printf("=====================\n");
		printf("      WORD GAME\n");
		printf("---------------------\n\n");
		printf("  ");

		for (i = 0; i < nLength; i++) {//i가 nStrLength보다 작을떄까지 반복
			printf("%c ", strAnswer[i]);//nStrLength의 길이만큼 _를 출력
		} //for

		printf("\n\n  ");

		for (i = 0; i < 26; i++) {
			printf("%c  ", strAlphabet[i]);
			if ((i + 1) % 6 == 0) printf("\n  ");
		} // for

		printf("\n\n  ");
		// escape condition
		if (!strcmp(strWords[nRandom], strAnswer)) {
			printf("맞췄습니다.\n\n");
			printf("=====================\n");
			break;
		} // if

		printf("문자 입력 >> ");
		fflush(stdin); // keyboard buffer clear
		//scanf("%c",&chInput);
		scanf("%s", strInput);
		count++;

		nInputLength = strlen(strInput);

		if (nInputLength == 1) {	// character
			chInput = strInput[0];

			for (i = 0; i < nLength; i++) {
				if (chInput == strWords[nRandom][i]) {
					strAnswer[i] = chInput;
				} // if
			} // for

		}
		else {			// string
			if (!strcmp(strWords[nRandom], strInput)) {
				strcpy(strAnswer, strInput);
			}
			else {
				printf("  틀렸습니다.\n\n");
				system("pause");
			}
		}



	} // while	

} // wordGame()

void OXGame()

{

	char strArray[11] = "0123456789";//입력가능한 숫자는 0부터 9까지

	char Player = 'O';//턴이 된 플레이어가 입력할 숫자

	char chWin = '\0';//승리 판정

	int turn = 0;//턴 횟수

	//9턴이 지나면 게임이 자동으로 끝납니다.
	while (TRUE) {
		displayOX(strArray);

		playOX(strArray, Player);

		turn++;//매 턴마다 1씩 올라갑니다.

		Player = (Player == 'O') ? 'X' : 'O';

		chWin = winCheck(strArray);

		if (chWin == 'O' || chWin == 'X') break;

		if (turn == 9) break;//9턴이 지나면 끝내는데, 9번까지 갈 경우는 비김일 수도 있고, 승패가 갈릴 수도 있다.
	}//while
	displayOX(strArray);


	if (chWin != '\0')//
	{
		printf(" %c가 승리 \n\n", chWin);//winCheck로 갈려진 승자에게 승리 판정을 내린다.
	}
	else
	{
		printf("비김\n");//가로,세로,대각선으로 맞는 경우가 없을 때, 비김으로 판정하고 끝낸다.
	}
} // OXGame()



char winCheck(char strArray[])

{

	char chReturn = '\0';



	if (strArray[1] == strArray[2] && strArray[2] == strArray[3])//첫번째 가로줄

		chReturn = strArray[1];

	else if (strArray[4] == strArray[5] && strArray[5] == strArray[6])//두번째 가로줄

		chReturn = strArray[4];

	else if (strArray[7] == strArray[8] && strArray[8] == strArray[9])//세번째 가로줄

		chReturn = strArray[7];

	else if (strArray[1] == strArray[4] && strArray[4] == strArray[7])//첫번째 세로줄

		chReturn = strArray[1];

	else if (strArray[2] == strArray[5] && strArray[5] == strArray[8])//두번째 세로줄

		chReturn = strArray[2];

	else if (strArray[3] == strArray[6] && strArray[6] == strArray[9])//세번째 세로줄

		chReturn = strArray[3];

	else if (strArray[1] == strArray[5] && strArray[5] == strArray[9])//좌상-우하 대각선

		chReturn = strArray[1];

	else if (strArray[3] == strArray[5] && strArray[5] == strArray[7])//우상-좌하 대각선

		chReturn = strArray[3];



	return chReturn;//일 경우에 \0을 출력 한다.

} //winCheck()
void playOX(char strArray[], char Player)
{
	/*
static int num=1;//static으로 선언되면 프로그램 끝날 때 까지 값을 유지할 수 있음.
static int x=MIN_X,y=MIN_Y;
*/
	int flag = TRUE;
	int num;
	//화살표랑 엔터 입력하기
	int x, y;
	char chInput;
	printf("\tPlayer : %c", Player);
	x = MIN_X;
	y = MIN_Y;
	gotoxy(x, y);
	num = 1;

	while (flag) {
		chInput = getch();//스캔에프로 할 시, 커서를 이동하려면, 오른쪽 + 엔터라는 형식으로, 트리거 입력이 힘들다.
		switch (chInput) {
		case ENTER:
			inputOX(strArray, Player, num);
			flag = FALSE;
			break;
		case LEFT:
			x = x - TAB_X;
			if (x < MIN_X) x = MIN_X;
			else	num--;
			break;
		case RIGHT:
			x = x + TAB_X;
			if (x > MAX_X) x = MAX_X;
			else	num++;
			break;
		case UP:
			y = y - TAB_Y;
			if (y < MIN_Y) y = MIN_Y;
			else	num = num - 3;
			break;
		case DOWN:
			y = y + TAB_Y;
			if (y > MAX_Y) y = MAX_Y;
			else	num = num + 3;
			break;
		}//switch-case
		gotoxy(x, y);
	}//while문 엔드
}
/*
int i;
printf(" %c's turn >> ", Player);
while(1){
scanf("%d", &num);
if(strArray[num]=='O'||strArray[num]=='X')//입력한 숫자가 O나 X로 되어있을 경우,
{
printf("중복입니다");//를 출력하고 값이 다를 떄까지 다시 입력하게 한다.
}else break;
}
strArray[num] = Player;

 }// playOXGame()
 */
void inputOX(char strArray[], char Player, int num)
{
	strArray[num] = Player;
}//inputOX
void displayOX(char strArray[])//5번메뉴인 OX게임을 선택하면 나오는 창
{
	int i;
	system("cls");
	printf("\n");

	printf("==================================\n");

	printf(" OX Game\n");

	printf("==================================\n");

	printf("\n");



	for (i = 1; i < 10; i++) {

		printf("   %c\t", strArray[i]);//탭을 한번, 숫자를 한번씩 나타내준다.


		if (i % 3 == 0) printf("\n\n\n");//3으로 나누어 떨어지는(3,6,9) 줄에서는 엔터를 두번

	} //for
	printf("==================================\n\n");
}// displayOXGame()


void Star_Game()
{
	int input;//게임을 하는 사용자가 입력한 별 반짝임 횟수
	int repeats;//실제 별의 반짝임 횟수
	int start_x = 10;//사각형 영역 왼쪽 상단 x 좌표
	int start_y = 3;//사각형 영역 왼쪽 상단 y 좌표
	int width = 50;//별이 나타날 사각형 영역의 가로 폭
	int height = 10;//별이 나타날 사각형 영역의 세로 길이
	int x, y, i;//현재 별이 나타날 좌표

	//게임 시작 전 안내문 출력 후 잠시 대기함
	printf("별이 반짝이는 횟수를 맞추는 게임입니다. 아무키나 누르면 시작합니다.");
	getch();//임의의 키를 누르면 게임을 시작하도록 기다리게 함

	system("cls");//화면 지우기
	Sleep(1000);//위의 getch()에서 키를 누르자마자 갑자기 실행되지 않게 프로그램 실행을 1000밀리초 동안 잠시 중지하기

	//별 반짝임 횟수를 최소 MIN번에서 최대 MAX번 중 임의의 값으로 설정하기
	repeats = rand() % (STARMAX - STARMIN + 1) + STARMIN;//rand 함수의 seed를 현재 시간으로 설정

	//별이 나타날 사각형 영역 바깥으로 테두리를 그린 후 1초동안 중지하기
	draw_rectangle(start_x, start_y, width, height);
	Sleep(1000);

	//별이 나타날 영역 안에서 임의의 (x,y)좌표에 INTERVAL 간격으로 별을 REPEAT하기
	for (i = 1; i <= repeats; i++) {
		//rand 함수를 이용하여 별이 나타날 (x,y) 좌표 구하기
		//★은 두 칸을 차지하므로 일반 문자를 출력할 때보다 최대 x좌표는 1 더 작아져야 한다.
		x = start_x + rand() % (width - 2);
		y = start_y + rand() % (height - 1);

		//별을 (x, y) 좌표에 표시한 후 INTERVAL 밀리초 동안 중지하기
		gotoxy(x, y);
		printf("%s", STAR);
		Sleep(INTERVAL);

		//(x,y)좌표에 있는 별 지우기
		gotoxy(x, y);
		printf("%s", " ");
		Sleep(INTERVAL);
	}

	//사용자에게 별 반짝임을 횟수를 물어서 답을 입력받기
	gotoxy(10, 21);
	printf("별은 몇 번(%d~%d번) 반짝거렸을까요? >> ", STARMIN, STARMAX);
	scanf("%d", &input);

	// 사용자가 답한 횟수에 따라 정답을 맞혔는지 틀렸는지 확인하기.
	gotoxy(10, 22);
	if (input == repeats)	printf("맞았습니다!\n");
	else						printf("틀렸습니다. 답은 %d번 입니다!\n", repeats);

}
/* (start_x, start_y) 좌표에서 시작하는 가로 폭이 width이고 세로 높이가 height인 사각형 바깥으로 테두리를 그리는 함수 */
void draw_rectangle(int start_x, int start_y, int width, int height)
{
	int col, row;

	// 사각형 윗쪽에 = 그리기
	gotoxy(start_x - 1, start_y - 1);
	for (col = 0; col <= width + 1; col++)		putch('=');

	//사각형 아래쪽에 = 그리기
	gotoxy(start_x - 1, start_y + height);
	for (col = 0; col <= width + 1; col++)		putch('=');

	//사각형 왼쪽에 '|'그리기
	for (row = 0; row < height; row++) {
		gotoxy(start_x - 1, start_y + row);
		putch('|');
	}

	//사각형 오른쪽에 '|'그리기
	for (row = 0; row < height; row++) {
		gotoxy(start_x + width, start_y + row);
		putch('|');
	}
}
//커서를 (x,y)로 이동하게 하는 함수
void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}