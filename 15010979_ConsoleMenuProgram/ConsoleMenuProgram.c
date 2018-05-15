#include "ConsoleMenuProgram.h"

int main()
{
	int nSelectedMainMenu;//���õ� ���θ޴� ���� ��Ÿ���� ����
	int bIterationFlag = TRUE;

	srand(time(NULL)); // seeds ����

	while (bIterationFlag) {
		system("cls");//�޴� �����Ŀ� ����� â�� ����� �Լ�
		nSelectedMainMenu = displayMainMenu(); // �Լ� ȣ��

		system("cls");

		/* if�� ����� ��
		if (nSelectedMainMenu ==1) { menu1(); }
		else if (nSelectedMainMenu == 2) { menu2(); }
		else if (nSelectedMainMenu == 3) { menu3(); }
		else if (nSelectedMainMenu == 4) { menu4(); }
		else { printf("�߸� �����̽��ϴ�.\n"); }
		*/

		switch (nSelectedMainMenu) {
		case DIE_SIMULATION: dieSimulation(); break;                             //�ʱ�ȭ�鿡�� ����Ǵ� �޴����̸�
		case GAME_SHOW: gameShow(); break;                                  //�� �޴��� ������ ������ ������ ȭ���� ����� ������ �޴��� ȭ�鿡 ��Ÿ���� ���� �ݺ�.
		case HIGH_LOWGAME: highLowGame(); break;                               //������ �� �̿��� ���� �Է��ϸ� default�� 
		case WORD_GAME: wordGame(); break;                                  //printf���� ����ϰ� 0�� �Է��ϸ� �ݺ��� �ߴ� .
		case OX_GAME: OXGame();	break;
		case STAR_GAME: Star_Game(); break;
		case EXIT:
			printf("GOOD-BYE!!\n");
			bIterationFlag = FALSE;
			break; // escape condition
		default: printf("�߸� �����̽��ϴ�.\n"); break;
		} // switch (���� ���϶��� ����)
		system("pause");
	} // while

	/* test
	system("cls"); //clear screen
	printf("%d���� �����Ͽ����ϴ�.\n", nSelectedMainMenu);
	*/

	return 0;
}   // main()

//�Լ� ������
int displayMainMenu() {

	int nMainMenu;

	printf("\n\n");
	printf("============================\n");
	printf("          MAIN MENU\n");
	printf("----------------------------\n");              //���α׷��� �����ϸ� ������ �ʱ�ȭ������ 
	printf("    1. DIE_SIMULATION\n");                     //�� ȭ�鿡�� �޴������� �ϰų� ���α׷�
	printf("    2. GAME_SHOW\n");                          //���Ḧ �Ҽ� �ִ�.
	printf("    3. HIGH-LOW GAME\n");
	printf("    4. WORD GAME\n");
	printf("    5. OX Game\n");
	printf("    6. STAR GAME\n");
	printf("----------------------------\n");
	printf("    0. EXIT\n");
	printf("============================\n");
	printf("    >> ");
	scanf("%d", &nMainMenu);                                //���ϴ� �޴��� ���ڸ� �Է� .

	return nMainMenu;                                      //�Է��� �޴��� ���ڸ� ��ȯ .

} // displayMainMenul

void dieSimulation() {

	int nFaceValue, nSum = 0, nCount = 0;
	int i, nIteration;
	double lfAvgCount;

	printf("============================\n");
	printf("     DIE SIMULATION\n");                            //�ʱ�ȭ�鿡�� dieSimulation�� �����ϸ� ������ ȭ������
	printf("----------------------------\n\n");                 //����� �ݺ����� ���� printf���� ��� .

	printf(" ��� �ݺ��Ͻðڽ��ϱ�? >> ");
	scanf("%d", &nIteration);                                   //�ݺ�Ƚ�� �Է� .

	for (i = 0; i < nIteration; i++) {                               //�Է��� ����ŭ while���� �ݺ� .
		while (nSum < 100) {
			nFaceValue = rand() % 6 + 1;     // 1~6                 //nFaceValue�� �ֻ����� ���ڷ� 1~6������ ���� �����ϰ� ���´�.
			nSum += nFaceValue;                                 //nSum�� 100�� ���������� �������� ���� 1~6������ ���� ���ϰ�
			nCount++;                                           //nSum�� 100�� ������ nCount�� +1�ϰ� nSum�� ���� 0���� �ʱ�ȭ .
		} // while
		nSum = 0;
	} // for

	lfAvgCount = (double)nCount / nIteration;	// calc. average       //nCount�� nlteration���� ����� lfAvgCount�� �� .
																	   //�̶�, �Ҽ������� ��Ÿ���� ���� (double)�� ������.
	system("cls");
	printf("============================\n");
	printf("     DIE SIMULATION RESULT\n");
	printf("----------------------------\n\n");
	printf("  %d�� ���ǽ����� ���,\n", nIteration);               //dieSimulation���� �Է¹��� �ݺ��� ���� nlteration�� 
	printf("  %.2lf���� ������\n", lfAvgCount);                   //������ ������ ���� lfAvgCount�� �־� printf���� ��� .
	printf("  �� �������� 100�� �ѽ��ϴ�.\n\n");
	printf("============================\n");

} // dieSimulation()

void gameShow() {

	int nPrizeDoor, nChoiceDoor, nRevealDoor, nSwitchDoor;
	int nChoiceCount = 0, nSwitchCount = 0;
	double lfChoice, lfSwitch;
	int i;

	printf("\n");
	printf("=================================================\n");          //gameShow �޴��� �����ϸ� �ش� printf���� ��� .
	printf("           The Money Hall Game Show\n");
	printf("-------------------------------------------------\n\n");

	for (i = 0; i < MAX; i++) {                                                  //for�ݺ����� MAX�� �ݺ� .
		nPrizeDoor = rand() % 3;  // 0-2                                      //nPrizeDoor�� 0~2�� ���� �� �ϳ��� �������� �������
		nChoiceDoor = rand() % 3; // 0-2                                      //nChoiceDoor�� 0~2�� ���� �� �ϳ��� �������� �������.
		if (nPrizeDoor == nChoiceDoor) { nChoiceCount++; }                    //���� nPrizeDoor�� nChoiceDoor�� ���� ������ nChoiceCount�� +1 .
	} // for


	lfChoice = (double)nChoiceCount / MAX * 100;                               //nChoiceCount�� MAX���� ���� ���� 100�� ���� lfchoice�� Ȯ���� �� .
																			 //�̶�, �Ҽ������� ����ϱ����� (double)�� ������.
	printf("  ������ ���� ��÷�� Ȯ���� %.2lf%% �Դϴ�.\n\n", lfChoice);        //���� ���꿡�� ���� lfchoice�� ���� �־� printf���� ��� .


	for (i = 0; i < MAX; i++) {                                                                    //for�ݺ����� MAX�� �ݺ� .
		nPrizeDoor = rand() % 3; // 0-2                                                          //nPrizeDoor�� 0~2�� ���� �� �ϳ��� �������� �������
		nChoiceDoor = rand() % 3;                                                                //nChoiceDoor�� 0~2�� ���� �� �ϳ��� �������� �������.

		nRevealDoor = 0;                                                                       //nRevealDoor=0���� �����ؼ� nRevealDoor�� nPrizeDoor�� ���ų�
		while (nRevealDoor == nPrizeDoor || nRevealDoor == nChoiceDoor) { nRevealDoor++; }          //nRevealDoor�� nChoiceDoor�� ������ nRevealDoor�� +1 .

		nSwitchDoor = 0;                                                                       //nSwitchDoor=0���� �����ؼ� nSwitchDoor�� nChoiceDoor�� ���ų�
		while (nSwitchDoor == nChoiceDoor || nSwitchDoor == nRevealDoor) { nSwitchDoor++; }     //nSwitchDoor�� nRevealDoor�� ������ nSwitchDoor�� +1 .

		if (nSwitchDoor == nPrizeDoor) { nSwitchCount++; }                                     //���� nSwitchDoor�� nPrizeDoor�� ���� ���ٸ� nSwitchCount�� +1 .
	} // for

	lfSwitch = (double)nSwitchCount / MAX * 100;                                 //nSwitchCount�� MAX(10000)���� ���� ���� 100�� ���� lfSwitch�� Ȯ���� �� .
																			   //�̶�, �Ҽ������� ����ϱ����� (double)�� ������
	printf("  ������ ���� ��÷�� Ȯ���� %.2lf%% �Դϴ�.\n\n", lfSwitch);          //���� ���꿡�� ���� lfSwitch�� ���� �־� printf���� ��� .
	printf("=================================================\n");

} // gameShow()

void highLowGame() {

	int nRandom, nInput;
	int low = 1, high = 100, count = 0;

	nRandom = rand() % 100 + 1; // 1~100���� ���� �� �������� �ϳ��� ���ڸ� ���� .

	while (TRUE) {
		system("cls");
		printf("\n");
		printf("================================================\n");            //highLowgame �޴��� �����ϸ� ������ ȭ������
		printf("              HIGH-LOW GAME\n");                                 //low���� high���� ���� �Է��϶�� ���� ��� .
		printf("------------------------------------------------\n");            //low�� high�� ���� ���ڸ� �Է��� ������ ��������.
		printf("\n");
		printf("   ���� �ϳ�(%d ~ %d)�� �Է��ϼ��� >>  ", low, high);

		scanf("%d", &nInput); // ���� �ϳ� �Է¹ޱ�

		count++; // ���ڸ� �Է��� ������ +1�� �� .
		printf("\n");

		if (nRandom < nInput) {                                                     //  �������� ������ ������ ũ�� �ش� printf���� ����ϰ�
			printf("   �Է��� ���� %d��(��) �� Ů�ϴ�.\n", nInput);                 //�ٽ� �ݺ����� printf���� ����� �� high�� �Է��� ���ڸ� �ִ´�.
			high = nInput;
		}
		else if (nRandom > nInput) {                                               //  �������� ������ ������ ������ �ش� printf���� ����ϰ�
			printf("   �Է��� ���� %d��(��) �� �۽��ϴ�.\n", nInput);              //�ٽ� �ݺ����� printf���� ����� �� low�� �Է��� ���ڸ� �ִ´�. 
			low = nInput;
		}
		else {
			printf("   �Է��� ���� %d��(��) �½��ϴ�.\n", nInput);                 //�������� ������ ����� �ش� printf���� ����ϰ�
			printf("   ���ߴµ� �� %d ȸ �ɷȽ��ϴ�.\n", count);                   //���� �� ������ count ������ �̿��� printf���� ��� .
			printf("\n");                                                       //���� ���ڸ� ���߸� ���ѹݺ����� �۵��� �����.
			printf("================================================\n");
			break;
		}

		printf("\n");
		printf("================================================\n");             //���� �ݺ����� Ż�������� ������Ű�� highLowGame�� �۵��� ������Ų��.
		system("pause");
	}
}//highLowGame



void wordGame()
{
	char strWords[10][40] = {//�������迭 strWords�������� 40���ڱ��� 10�� ������
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

	char strAnswer[40];//�������迭 strAnswer�������� 40���ڱ��� ����, nLength�� ���� ���̿� '_'�� ������ �ϴ� ����
	int nRandom, nLength, i;//nRandom�� strWords�� �����߿��� 0~9������ ������ ���ڸ� �������� ������ �ϱ� ���� �����̸�, nLength�� nRandom���� �������� strWords���� ���� ������ ���̸� ������ �����̴�. i�� for���� �ݺ����� i�� ������ ���̴�
	char chInput;//wordGame���� �Ἥ ���� ���� ����
	char strAlphabet[27] = "abcdefghijklmnopqrstuvwxyz";//a~z���� �ִ� �������迭 strAlphabet ����.
	int count = 0;//�� �� �Է��ߴ��� ī��Ʈ�ϱ� ���� ���� ����
	char strInput[40];
	int  nInputLength;

	nRandom = rand() % 10; // 0-9

	nLength = strlen(strWords[nRandom]);//strWords �迭�ȿ� �ִ� �� �߿��� 0~9 �� ���� �������� ��� �� ���̸� nStrLength�� ������.
	for (i = 0; i < nLength; i++) {//i�� nStrLength���� ���� ������ �ݺ�
		strAnswer[i] = '_';//�ݺ��� ��ŭ strAnswer[i]�� _�� �ִ´�.
	} // for
	strAnswer[nLength] = '\0';//nStrLength�� ���̸�ŭ strAnswer�� ������ �� �ܾ �������� �뺸��.

	while (TRUE) {//TRUE = 1. ���ѹݺ��̴�.
		system("cls");
		printf("\n\n");
		printf("=====================\n");
		printf("      WORD GAME\n");
		printf("---------------------\n\n");
		printf("  ");

		for (i = 0; i < nLength; i++) {//i�� nStrLength���� ���������� �ݺ�
			printf("%c ", strAnswer[i]);//nStrLength�� ���̸�ŭ _�� ���
		} //for

		printf("\n\n  ");

		for (i = 0; i < 26; i++) {
			printf("%c  ", strAlphabet[i]);
			if ((i + 1) % 6 == 0) printf("\n  ");
		} // for

		printf("\n\n  ");
		// escape condition
		if (!strcmp(strWords[nRandom], strAnswer)) {
			printf("������ϴ�.\n\n");
			printf("=====================\n");
			break;
		} // if

		printf("���� �Է� >> ");
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
				printf("  Ʋ�Ƚ��ϴ�.\n\n");
				system("pause");
			}
		}



	} // while	

} // wordGame()

void OXGame()

{

	char strArray[11] = "0123456789";//�Է°����� ���ڴ� 0���� 9����

	char Player = 'O';//���� �� �÷��̾ �Է��� ����

	char chWin = '\0';//�¸� ����

	int turn = 0;//�� Ƚ��

	//9���� ������ ������ �ڵ����� �����ϴ�.
	while (TRUE) {
		displayOX(strArray);

		playOX(strArray, Player);

		turn++;//�� �ϸ��� 1�� �ö󰩴ϴ�.

		Player = (Player == 'O') ? 'X' : 'O';

		chWin = winCheck(strArray);

		if (chWin == 'O' || chWin == 'X') break;

		if (turn == 9) break;//9���� ������ �����µ�, 9������ �� ���� ����� ���� �ְ�, ���а� ���� ���� �ִ�.
	}//while
	displayOX(strArray);


	if (chWin != '\0')//
	{
		printf(" %c�� �¸� \n\n", chWin);//winCheck�� ������ ���ڿ��� �¸� ������ ������.
	}
	else
	{
		printf("���\n");//����,����,�밢������ �´� ��찡 ���� ��, ������� �����ϰ� ������.
	}
} // OXGame()



char winCheck(char strArray[])

{

	char chReturn = '\0';



	if (strArray[1] == strArray[2] && strArray[2] == strArray[3])//ù��° ������

		chReturn = strArray[1];

	else if (strArray[4] == strArray[5] && strArray[5] == strArray[6])//�ι�° ������

		chReturn = strArray[4];

	else if (strArray[7] == strArray[8] && strArray[8] == strArray[9])//����° ������

		chReturn = strArray[7];

	else if (strArray[1] == strArray[4] && strArray[4] == strArray[7])//ù��° ������

		chReturn = strArray[1];

	else if (strArray[2] == strArray[5] && strArray[5] == strArray[8])//�ι�° ������

		chReturn = strArray[2];

	else if (strArray[3] == strArray[6] && strArray[6] == strArray[9])//����° ������

		chReturn = strArray[3];

	else if (strArray[1] == strArray[5] && strArray[5] == strArray[9])//�»�-���� �밢��

		chReturn = strArray[1];

	else if (strArray[3] == strArray[5] && strArray[5] == strArray[7])//���-���� �밢��

		chReturn = strArray[3];



	return chReturn;//�� ��쿡 \0�� ��� �Ѵ�.

} //winCheck()
void playOX(char strArray[], char Player)
{
	/*
static int num=1;//static���� ����Ǹ� ���α׷� ���� �� ���� ���� ������ �� ����.
static int x=MIN_X,y=MIN_Y;
*/
	int flag = TRUE;
	int num;
	//ȭ��ǥ�� ���� �Է��ϱ�
	int x, y;
	char chInput;
	printf("\tPlayer : %c", Player);
	x = MIN_X;
	y = MIN_Y;
	gotoxy(x, y);
	num = 1;

	while (flag) {
		chInput = getch();//��ĵ������ �� ��, Ŀ���� �̵��Ϸ���, ������ + ���Ͷ�� ��������, Ʈ���� �Է��� �����.
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
	}//while�� ����
}
/*
int i;
printf(" %c's turn >> ", Player);
while(1){
scanf("%d", &num);
if(strArray[num]=='O'||strArray[num]=='X')//�Է��� ���ڰ� O�� X�� �Ǿ����� ���,
{
printf("�ߺ��Դϴ�");//�� ����ϰ� ���� �ٸ� ������ �ٽ� �Է��ϰ� �Ѵ�.
}else break;
}
strArray[num] = Player;

 }// playOXGame()
 */
void inputOX(char strArray[], char Player, int num)
{
	strArray[num] = Player;
}//inputOX
void displayOX(char strArray[])//5���޴��� OX������ �����ϸ� ������ â
{
	int i;
	system("cls");
	printf("\n");

	printf("==================================\n");

	printf(" OX Game\n");

	printf("==================================\n");

	printf("\n");



	for (i = 1; i < 10; i++) {

		printf("   %c\t", strArray[i]);//���� �ѹ�, ���ڸ� �ѹ��� ��Ÿ���ش�.


		if (i % 3 == 0) printf("\n\n\n");//3���� ������ ��������(3,6,9) �ٿ����� ���͸� �ι�

	} //for
	printf("==================================\n\n");
}// displayOXGame()


void Star_Game()
{
	int input;//������ �ϴ� ����ڰ� �Է��� �� ��¦�� Ƚ��
	int repeats;//���� ���� ��¦�� Ƚ��
	int start_x = 10;//�簢�� ���� ���� ��� x ��ǥ
	int start_y = 3;//�簢�� ���� ���� ��� y ��ǥ
	int width = 50;//���� ��Ÿ�� �簢�� ������ ���� ��
	int height = 10;//���� ��Ÿ�� �簢�� ������ ���� ����
	int x, y, i;//���� ���� ��Ÿ�� ��ǥ

	//���� ���� �� �ȳ��� ��� �� ��� �����
	printf("���� ��¦�̴� Ƚ���� ���ߴ� �����Դϴ�. �ƹ�Ű�� ������ �����մϴ�.");
	getch();//������ Ű�� ������ ������ �����ϵ��� ��ٸ��� ��

	system("cls");//ȭ�� �����
	Sleep(1000);//���� getch()���� Ű�� �����ڸ��� ���ڱ� ������� �ʰ� ���α׷� ������ 1000�и��� ���� ��� �����ϱ�

	//�� ��¦�� Ƚ���� �ּ� MIN������ �ִ� MAX�� �� ������ ������ �����ϱ�
	repeats = rand() % (STARMAX - STARMIN + 1) + STARMIN;//rand �Լ��� seed�� ���� �ð����� ����

	//���� ��Ÿ�� �簢�� ���� �ٱ����� �׵θ��� �׸� �� 1�ʵ��� �����ϱ�
	draw_rectangle(start_x, start_y, width, height);
	Sleep(1000);

	//���� ��Ÿ�� ���� �ȿ��� ������ (x,y)��ǥ�� INTERVAL �������� ���� REPEAT�ϱ�
	for (i = 1; i <= repeats; i++) {
		//rand �Լ��� �̿��Ͽ� ���� ��Ÿ�� (x,y) ��ǥ ���ϱ�
		//���� �� ĭ�� �����ϹǷ� �Ϲ� ���ڸ� ����� ������ �ִ� x��ǥ�� 1 �� �۾����� �Ѵ�.
		x = start_x + rand() % (width - 2);
		y = start_y + rand() % (height - 1);

		//���� (x, y) ��ǥ�� ǥ���� �� INTERVAL �и��� ���� �����ϱ�
		gotoxy(x, y);
		printf("%s", STAR);
		Sleep(INTERVAL);

		//(x,y)��ǥ�� �ִ� �� �����
		gotoxy(x, y);
		printf("%s", " ");
		Sleep(INTERVAL);
	}

	//����ڿ��� �� ��¦���� Ƚ���� ��� ���� �Է¹ޱ�
	gotoxy(10, 21);
	printf("���� �� ��(%d~%d��) ��¦�ŷ������? >> ", STARMIN, STARMAX);
	scanf("%d", &input);

	// ����ڰ� ���� Ƚ���� ���� ������ �������� Ʋ�ȴ��� Ȯ���ϱ�.
	gotoxy(10, 22);
	if (input == repeats)	printf("�¾ҽ��ϴ�!\n");
	else						printf("Ʋ�Ƚ��ϴ�. ���� %d�� �Դϴ�!\n", repeats);

}
/* (start_x, start_y) ��ǥ���� �����ϴ� ���� ���� width�̰� ���� ���̰� height�� �簢�� �ٱ����� �׵θ��� �׸��� �Լ� */
void draw_rectangle(int start_x, int start_y, int width, int height)
{
	int col, row;

	// �簢�� ���ʿ� = �׸���
	gotoxy(start_x - 1, start_y - 1);
	for (col = 0; col <= width + 1; col++)		putch('=');

	//�簢�� �Ʒ��ʿ� = �׸���
	gotoxy(start_x - 1, start_y + height);
	for (col = 0; col <= width + 1; col++)		putch('=');

	//�簢�� ���ʿ� '|'�׸���
	for (row = 0; row < height; row++) {
		gotoxy(start_x - 1, start_y + row);
		putch('|');
	}

	//�簢�� �����ʿ� '|'�׸���
	for (row = 0; row < height; row++) {
		gotoxy(start_x + width, start_y + row);
		putch('|');
	}
}
//Ŀ���� (x,y)�� �̵��ϰ� �ϴ� �Լ�
void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}