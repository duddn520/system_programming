#include<stdio.h>
#include<unistd.h>
#include<ncurses.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>


void* test();
void* timer();
int timecounter =0;
int score;
FILE *fp;
FILE *testp;
char str[1024];


int main(void)
{
pthread_t thread1, thread2;
int n;
printf("****************************************\n");
printf("              Capital Quiz\n");
printf("****************************************\n");
printf("            Select Continent\n");
printf("       1.ASIA\n");
printf("           2.EUROPE\n");
printf("               3.AFRICA\n");
printf("                   4.NORTH AMERICA\n");
printf("                       5.SOUTH AMERICA\n");
printf("                           6.OCEANIA\n");
scanf("%d",&n);

switch(n)
{
case 1:
fp = fopen("Asia.txt","r");
testp = fopen("Asia.txt","r");
break;
case 2:
fp = fopen("Europe.txt","r");
testp = fopen("Europe.txt","r");
break;
case 3:
fp = fopen("Africa.txt","r");
testp = fopen("Africa.txt","r");
break;
case 4:
fp = fopen("NorthAmerica.txt","r");
testp = fopen("NorthAmerica.txt","r");
break;
case 5:
fp = fopen("SouthAmerica.txt","r");
testp = fopen("SouthAmerica.txt","r");
break;
case 6:
fp = fopen("Oceania.txt","r");
testp = fopen("Oceania.txt","r");
default :
return -1;
}
  

while(str[0]!='-'){
fgets(str,1024,fp);
initscr();
scanw("%s",str);
addstr(str);
refresh();
sleep(1);
clear();
}


endwin();

sleep(3);

printf("Test will start after 5 seconds.\nTime Limit is 60seconds.\n");

sleep(5);

if(pthread_create(&thread1,NULL,test,NULL))
{
perror("Test is not started.");
return -1;
}
if(pthread_create(&thread2,NULL,timer,NULL)){
perror("timer creating error");
return -1;
}

pthread_join(thread1,NULL);

printf("Score : %d\n",score);

fclose(testp);
fclose(fp);

return 0;
}

void *test(){
char uinstr[1024];
str[0]=0;
while(str[0]!='-'&&!timecounter)
{
fgets(str,1024,testp);
printf("%s\n",str);
fgets(str,1024,testp);
fgets(uinstr,1024,stdin);
if(strcmp(str,uinstr)==0)
score = score +10;
}
}

void *timer(){
int time =60;

while(time>0)
{
sleep(1);
time--;
}
timecounter = 1;
}

