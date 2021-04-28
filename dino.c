#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<process.h>

char ch;
int x=50,y=6,x2=75,y2=6,px=20,py=6,score=0,sx=60,sy=3,mx=36,my=10;

void help();
void move();
void start();
void jump();
void check();
void gameover();
void printstate();

void help()
{
clrscr();
gotoxy(34,5);
printf("RULES");
gotoxy(25,8);
printf("1.Press spce bar to jump");
gotoxy(25,10);
printf("2.Jump over obstacle");
gotoxy(25,12);
printf("3.For each obstacle cross you get +1 score");
gotoxy(25,14);
printf("4.As the score increases speed of Player increases");
gotoxy(60,20);
printf("Back");
while(1)
{
ch=getch();
if(ch==13)
{
mx=34;
my=10;
start();
}

}
}

void start()
{
clrscr();
gotoxy(32,6);
printf("JUMPING JACK");
gotoxy(mx,my);
printf("PLAY");
gotoxy(mx,my+2);
printf("HELP");
gotoxy(mx,my+4);
printf("QUIT");
gotoxy(mx,my);
while(1)
{
ch=getch();
if(ch=='w'|| ch=='W'|| ch==72)
{
if(my!=10)
my-=2;
gotoxy(mx,my);
}
else if(ch=='s'|| ch=='S'||ch==80)
{
if(my!=14)
my+=2;
gotoxy(mx,my);
}
else if(ch==13)
{
if(my==10)
{
printstate();
move();
}
else if(my==12)
{
help();
}
else
{
exit(0);
}
}
}
}

void gameover()
{
clrscr();
gotoxy(34,10);
printf("GAME OVER \n");
gotoxy(32,13);
printf("Your Score: %d",score);

while(1)
{
ch=getch();
if(ch==27)
{
start();
}
else if(ch==13)
{
x=50;
y=6;
x2=75;
y2=6;
px=20;
py=6;
score=0;
printstate();
move();
}
}

}

void printstate()
{
clrscr();
gotoxy(sx,sy);
printf("score: %d",score);
gotoxy(6,6);
printf("_________________________________________________________________________");
gotoxy(px,py);
printf(" ");
gotoxy(x,y);
printf("-|");
gotoxy(x2,y2);
printf("|");
}

void check()
{
if((px==x || px==x2) && py==y)
{
gameover();
}
else
{
if(px>x)    //initial co-ordinates for obs
{
x=60;
y=6;
score++;   //score increment
}
if(px>x2)
{
x2=75;
y2=6;
score++;
}
move();
}
}

void jump()
{

py-=3;
x2-=10;
x-=10;
delay(40);
printstate();
py+=3;
move();
}

void move()
{
while(!kbhit())
{
if(score<10)
{
x--;
x2--;
}
else if(score>10 && score<30)
{
x2-=2;
x-=2;
}
else if(score>30 && score<40)
{
x2-=2;
x--;
}
else
{
x2-=2;
x-=2;
}
delay(80);
printstate();
check();
}
ch=getch();
if(ch==32)
{
jump();
}
else if(ch==27)
{
start();
}
}

int main()
{
start();
return 0;
}
