#include<stdio.h>
#include<windows.h>
#include<Mmsystem.h>
#include<conio.h>
#include<stdlib.h>
#define HEIGHT 22
#define WIDTH 40
#define HEIGHTF1 28
#define WIDTHF1 30
void snake(void);
void bTicTacToe(void);
void ticTacToe(void);
void setupF1(void);
void drawF1(void);
void inputF1(void);
void logicF1(void);
struct scores{
	int score1;
	int score2;
}score;
void formulaOne(void);
void formulaOneStart(int);
void highscoresOfFormulaOne(void);
enum d {STOP=0, LEFT,RIGHT,UP,DOWN };
enum d direction;
void snakeMain(void);
void loading(int choice)
{
	system("cls");
	system("color 84");
	int count = 0;
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\tL O A D I N G...\n\n\t\t\t\t");
	while(count != 2)
	{
		printf("#######");
		sleep(1);
		count++;
	}
	printf(" ");
	system("cls");
	system("color 8e");
	if(choice == 1)
	snakeMain();
	
	else if(choice == 2)
	{
		formulaOne();
	}
	else if(choice == 3)
	{
		bTicTacToe();	
	}
}

main()
{
	srand(time(0));
	system("color 8e");
	puts("\n\n\t\t\t\tT H R E E    I N    O N E    G A M E");
	printf("\n\nControls: \tw\n\ta\t\ts\n\t\tz\n");
	puts("Select game:");
	puts("\n\t1.Snake\n\t2.Formula One\n\t3.Tic Tac Toe\n\n0. Exit");
	printf("\nYour choice: ");
	int *p = malloc(sizeof(int));
	scanf("%d",&*p);
	switch(*p)
	{
		case 1:
			loading(1);
			break;
		case 2:
			loading(2); 
			break;
		case 3:
			loading(3);
			break;
		case 0:
			system("exit");
			break;
		default:
			{
				printf("\n\nWrong choice\nPress any key to continue");
				getch();
				system("cls");
				main();
			}
	}

	free(p);

}

void highscoresOfSnake(void)
{
	system("cls");
	printf("\n\n\t\t\tH i g h s c o r e s\n\n");
	char c;
	FILE *f = fopen("scores.txt","r");
	printf("\t\t\t\t");
	while((c=getc(f))!=EOF)
	{
	if(c=='\n')
	printf("\n\t\t\t\t");
	else
	printf("%c",c);
	}
	fclose(f);
	
	printf("\nEnter any key to continue");
	getch();
	system("cls");
	snakeMain();
}

int fX,fY,x,y,gameOver=0;
int tail,tailX[100],tailY[100];

void setup (void)
{
	gameOver = 0;
	x = WIDTH / 2;
	y = HEIGHT / 2;
	fX = (rand()% ((HEIGHT-1)-1)) + 1;
	fY = (rand() % ((WIDTH-1)-1)) + 1;
	score.score1 = 0;
	tail  = 0;
	direction = STOP;
	int k;
	for(k=0;k<100;k++)
	{
		tailX[k] = 0;
		tailY[k] = 0;
	}
}

void draw(void)
{
	system("cls");
	int i,j;
	printf("\t\t\t\tScore: %d\n",score.score1);
	printf("\t\t\t");
	for(i=0;i<WIDTH;i++)
	printf("#");
	puts("");
	for(i=0;i<HEIGHT;i++)
	{
		printf("\t\t\t");
		for(j=0;j<WIDTH;j++)
		{
			if(j == 0 ||  j == WIDTH-1)
			printf("#");
			
			else if(i==x && j==y)
			printf("%c",235);
			
			else if(i==fX && j == fY)
			printf("%c",220);
			
			else 
			{
			int k,is=0;
			for(k=0;k<tail;k++)
			{
				if(tailX[k] == i && tailY[k] == j)
				printf("%c",236),is=1;
			}
			if(is==0)
			printf(" ");
			}
		}
		puts("");
	}
	printf("\t\t\t");
	for(i=0;i<WIDTH;i++)
	{
	printf("#");
	}
	puts("");
}
void input()
{
	if(kbhit())
	{
		getch();
		switch(getch())
		{
			case 72:
				direction = UP;
				break;
			case 75:
				direction = LEFT;
				break;
			case 77:
				direction = RIGHT;
				break;
			case 80: 
				direction = DOWN;
				break;
			case 'k':
				gameOver = 1;
				break;
		}
	}
}
void process(void)
{
	int i,px=tailX[0],py=tailY[0],p2x,p2y;
	tailX[0] = x;
	tailY[0] = y;
	for(i=1;i<tail;i++)
	{
		p2x = tailX[i];
		p2y = tailY[i];
		tailX[i] = px;
		tailY[i] = py;
		px = p2x;
		py = p2y;
	}
	switch(direction)
	{
		case LEFT:
			y--;
			break;
		case RIGHT:
			y++;
			break;
		case UP:
			x--;
			break;
		case DOWN:
			x++;
			break;
	}
	if(x>HEIGHT || y > WIDTH || x < 0 || y < 0)
	gameOver = 1;
	for(i=0;i<tail;i++)
	{
	if(tailX[i]==x && tailY[i]==y)
	{
		gameOver=1;
	}
	}
	if(x==fX && y==fY)
	{
		score.score1++;
		fX = (rand()% ((HEIGHT-1)-1)) + 1;
		fY = (rand() % ((WIDTH-1)-1)) + 1;
		tail++;
	}
}
void snakeMain(void)
{
	system("color 0a");
	puts("\n\n\n\t\t\t\t\tS n a k e     G a m e");
	printf("\n\n\t\t\t\t\t1.\tPlay Game\n\t\t\t\t\t2.\tHighscores\n\t\t\t\t\t3.\tMain Menu\n\n\tYour Choice:\t");
	int choice;
	scanf("%d",&choice);
	if(choice == 1)
	snake();
	else if(choice == 2)
	highscoresOfSnake();
	else if(choice == 3)
	{
		system("cls");
		main();
	}
	else
	{
		printf("\n\tWrong choice\nPress any key to continue");
		getch();
		system("cls");
		snakeMain();
	}
}
void snake(void)
{
	system("color 8e");
	setup();
	while(gameOver==0)
	{
		draw();
		input();
		process();
		 int c, d;
   
   for (c = 1; c <= 32767; c++)
       for (d = 1; d <= 1000; d++)
       {}
	}
	char c;
	
	if(score.score1>=10)
	{
	PlaySound(TEXT("Cheering 3-SoundBible.com-1680253418.wav"),NULL,SND_ASYNC);
	}
	else
	{
		PlaySound("fail-trombone-02.wav",NULL,SND_ASYNC);
	}
	
	FILE *f = fopen("scores.txt","a");
	if(score.score1>0)
	fprintf(f,"%d\n",score.score1);
	fclose(f);
	printf("\nPress anykey TWICE to go back");
	getch();
	getch();
	system("cls");
	snakeMain();
}
/* 
formula one starts from here
*/
int gameOverF1=0,hell=0,xF1,yF1,arr[100][2],nF1=0;
void formulaOne(void)
{
	system("color 47");
	int choice;
	puts("\n\n\n\t\t\tF O R M U L A     O N E (F A S T    V E R S I O N)");
	printf("\n\n\n\t\t\t\t\t1. Play Game\n\t\t\t\t\t2. High Scores\n\t\t\t\t\t3. Main Menu\n\nYour choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			formulaOneStart(2);
			break;
		case 2:
			highscoresOfFormulaOne();
			break;
		case 3:
			system("cls");
			main();
			break;
		default:
			{
				printf("Wrong choice\nPress anykey to continue");
				getch();
				system("cls");
				formulaOne();
			}
	}
}
void highscoresOfFormulaOne(void)
{
	system("cls");
	printf("\n\n\t\t\tH i g h s c o r e s\n\n");
	char c;
	FILE *f = fopen("scoresF1.txt","r");
	printf("\t\t\t\t");
	while((c=fgetc(f))!=EOF)
	{
	if(c=='\n')
	printf("\n\t\t\t\t");
	else
	printf("%c",c);
	}
	fclose(f);
	
	printf("\nEnter any key to continue");
	getch();
	system("cls");
	formulaOne();
}
void formulaOneStart(int a)
{
	system("color 1e");
	srand(time(0));
	if(!(a==1))
	setupF1();
	
	while(gameOverF1==0)
	{
		system("cls");
		drawF1();
		inputF1();
		logicF1();
		int i,j;
		for(i=0;i<32766;i++)
		{
			for(j=0;j<1000;j++)
			{}
		}
		hell++;
		
	}
	PlaySound("Car Screech And Crash-SoundBible.com-1414562045.wav",0,SND_ASYNC);
	if(score.score2>0)
	{
	FILE *f = fopen("scoresF1.txt","a");
	fprintf(f,"%d\n",score.score2);
	fclose(f);
	}
	printf("\n\t\t\t\t\tYour score is %d",score.score2);
	printf("\nPress anykey twice to go back");
	getch();
	getch();
	system("cls");
	formulaOne();
}
void setupF1()
{

	score.score2=0;
	gameOverF1=0;
	hell=0;
	arr[100][2];
	nF1=0;
	xF1 = HEIGHTF1/2;
	yF1 = WIDTHF1/2;
}

void drawF1(void)
{
	int i,j,k;
	printf("\t\t\t\t\tScore: %d\n",score.score2);
	for(i=0;i<HEIGHTF1;i++)
	{
		printf("\t\t\t\t\t");
		for(j=0;j<WIDTHF1;j++)
		{
			int c=0;
			if(i==0 || j == 0 || i == HEIGHTF1-1 || j == WIDTHF1-1)
			printf("#");
			
			else if(i==1 && j == 2)
			printf("A");
			else if(i==1 && j == 3)
			printf("H");
			else if(i==1 && j == 4)
			printf("M");
			else if(i==1 && j == 5)
			printf("E");
			else if(i==1 && j == 6)
			printf("D");
			
			else if(i==1 && j == 12)
			printf("I");
			else if(i==1 && j == 13)
			printf("S");
			
			else if(i==1 && j == 21)
			printf("B");
			else if(i==1 && j == 22)
			printf("E");
			else if(i==1 && j == 23)
			printf("A");
			else if(i==1 && j == 24)
			printf("S");
			else if(i==1 && j == 25)
			printf("T");
						
			else if(i==xF1 && j == yF1)
			printf("%c",177);
			else if(i==xF1 && j == yF1-1)
			printf("%c",219);
			else if(i==xF1 && j == yF1+1)
			printf("%c",219);
			else if(i==xF1+1 && j == yF1)
			printf("%c",219);
			else if(i==xF1-1 && j == yF1)
			printf("%c",219);
			
			else if(j>0 && j%10==0)
			printf("|");
			else
			{
			int is=0;
			for(k=0;k<nF1;k++)
			{
			if(i==arr[k][0] && j == arr[k][1])
			{
			printf("%c",178);
			is++;
			}
			}
			if(is==0)
			printf(" ");
			}
		}
		printf("\n");
			
		}
	
}
void inputF1(void)
{
	if(kbhit())
	{
		getch();
		switch(getch())
		{
			case 75: // left
				yF1-=3;
				break;
			case 77: // right
				yF1+=3;
				break;
			case 72: // up
				xF1-=3;
				break;
			case 80: // down
				xF1+=3;
				break;
			
		}
	}
}
void logicF1(void)
{
	if((xF1>=HEIGHTF1-1 || xF1<=0 || yF1 >= WIDTHF1-1 || yF1<=0 )|| (xF1-1>=HEIGHTF1-1 || xF1-1<=0 || yF1-1 >= WIDTHF1-1 || yF1-1<=0 ) || (xF1+1>=HEIGHTF1-1 || xF1+1<=0 || yF1+1 >= WIDTHF1-1 || yF1+1<=0 ) )
	gameOverF1++;
	int i,j;
	
	arr[nF1][1] = (rand()%((WIDTHF1-1)-2)) +1;
	arr[nF1][0] = 0;
	for(i=0;i<nF1;i++)
	{
		arr[i][0] += 1;
	}

	if(hell%3==0)
	nF1++;
		
	if(hell%20==0)
	score.score2 += 1;
	if(hell%4==0)
	xF1++;
	for(i=0;i<nF1;i++)
	{
		if((xF1==arr[i][0] && yF1 == arr[i][1] )|| (arr[i][0]==xF1 && arr[i][1] == yF1-1 )||( arr[i][0]==xF1 && arr[i][1] == yF1+1 )|| (arr[i][0]==xF1-1 && arr[i][1] == yF1 )|| (arr[i][0]==xF1+1 && arr[i][1] == yF1))
		gameOverF1++;
	}
	if (nF1==100)
	{
		int temp = score.score2;
		setupF1();
		system("cls");
		score.score2 += temp + 50;
		printf("\n\n\n\n\n\n\n\t\t\t\t\t\tCongratulations! Level Up");
		sleep(3);
		
		formulaOneStart(1);
		score.score2 += temp + 50;
	}
	
}
char b='1', c='2', d='3', e='4', f='5', g='6', h='7', i='8', j='9';
int WinOrLose();
void board();

void bTicTacToe(void)
{
	b='1', c='2', d='3', e='4', f='5', g='6', h='7', i='8', j='9';
	system("color 2f");
	int choice;
	printf("\n\t\t\t\t\tT I C   T A C   T O E\n\n\t\t\t\t\t1.Play Game\n\t\t\t\t\t2.Main Menu\nYour choice: ");	
	scanf("%d",&choice);
	if(choice==1)
	ticTacToe();
	else if(choice == 2)
	{
		system("cls");
	main();
	}
	else
	{
	printf("Wrong choice \nPress anykey to continue");
	getch();
	system("cls");
	bTicTacToe();
	}
	
}
void ticTacToe(void) 
{
    int player = 1, a, choice;

    char mark;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number:  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 219 : 206;

        if (choice == 1 && b == '1')
            b = mark;
            
        else if (choice == 2 && c == '2')
            c = mark;
            
        else if (choice == 3 && d == '3')
            d = mark;
            
        else if (choice == 4 && e == '4')
            e = mark;
            
        else if (choice == 5 && f == '5')
            f = mark;
            
        else if (choice == 6 && g == '6')
            g = mark;
            
        else if (choice == 7 && h == '7')
            h = mark;
            
        else if (choice == 8 && i == '8')
            i = mark;
            
        else if (choice == 9 && j == '9')
            j = mark;
            
        else
        {
            printf("Incorrect input ");

            player--;
            getch();
        }
        a = WinOrLose();

        player++;
    }while (a ==  - 1);
    
    board();
    
    if (a == 1)
        printf("==>\aPlayer %d win ", --player);
    else
        printf("==>\aGame draw");
	printf("\nPress anykey TWICE to continue");
	getch();
	getch();
	system("cls");
	bTicTacToe();

}
void board()
{
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 will use %c  -  Player 2 will use %c\n\n",219,216);


    printf("\t\t     |     |     \n");
    printf("\t\t  %c  |  %c  |  %c \n", b, c, d);

    printf("\t\t_____|_____|_____\n");
    printf("\t\t     |     |     \n");

    printf("\t\t  %c  |  %c  |  %c \n", e, f, g);

    printf("\t\t_____|_____|_____\n");
    printf("\t\t     |     |     \n");

    printf("\t\t  %c  |  %c  |  %c \n", h, i, j);

    printf("\t\t     |     |     \n\n");
}
int WinOrLose()
{
    if (b == c && c == d)
        return 1;
        
    else if (e == f && f == g)
        return 1;
        
    else if (h == i && i == j)
        return 1;
        
    else if (b == e && e == h)
        return 1;
        
    else if (c == f && f == i)
        return 1;
        
    else if (d == g && g == j)
        return 1;
        
    else if (b == f && f == j)
        return 1;
        
    else if (d == f && f == h)
        return 1;
        
    else if (b != '1' && c != '2' && d != '3' &&
        e != '4' && f != '5' && g != '6' && h 
        != '7' && i != '8' && j != '9')

        return 0;
    else
        return  - 1;
}
