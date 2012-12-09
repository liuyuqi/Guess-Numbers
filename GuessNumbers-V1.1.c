#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
void main()
{
	int a,b=0,c[4],d[4],m,n,i,j,k,times;
	/*i为当前猜想次数，m为猜对且位置正确的个数，n为猜对但位置不正确的个数，j为m所需的循环次数变量，k为n所需的循环次数变量。*/ 
    /*times为用户设置的猜想次数*/
     
    srand(time(NULL));
	do  {
		a=rand()%(10000-1000)+1000;
		c[0]=a/1000;   c[1]=a/100%10;
		c[2]=a/10%10;  c[3]=a%10;
		}
	while (c[0]==c[1] || c[0]==c[2] || c[0]==c[3] || c[1]==c[2] || c[1]==c[3] || c[2]==c[3]);
	
	printf("    游戏说明：这是猜数字游戏。用户需要输入4个数字，确认后系统给出形如“1A2B”这样的提示。这代表，猜对了1个并且位置正确，另外还猜对了2个但位置不正确。\n");
    printf("\n请输入您希望猜测的次数（当然次数越多猜中的可能性越大哦！）：");
    while(1)  {
         scanf("%d",&times);
         if (times>0) break;
         else printf("输入错误，请重新输入:"); 
         }
     
    printf("***************************************************\n请输入四个数字，首数字不为0，数字之间用一个空格隔开：\n"); 
     
	for ( i=1 ; i<=times ; i++)
    {
		printf("第%2d次 ", i);
		scanf("%d %d %d %d", &d[0],&d[1],&d[2],&d[3]);
		
        m=0; n=0;
		for (j=0 ; j<4 ; j++)
        {
			if ( c[j]==d[j] )   m++;
			for (k=0 ; k<4 ; k++)
				if ( c[j]==d[k] && j!=k)  n++;
		}

		if (m<4)  printf("%dA%dB\n",m,n);
		else {printf("你猜对了！按任意键退出！\n"); getch() ; exit(0) ;}
	}
	
	if (i>=times)
    {
         printf("你没有机会了！答案是：%d",a);getch();
    }
}
