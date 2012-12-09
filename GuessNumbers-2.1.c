#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int input(void);
void create_number(int *);
void guess(int, int *);
int result(int, int, int *, int *);
int main()
{
	int i, times, c[4], *pc=c, d[4], *pd=d, x;      char again;
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("*          猜数字V2.1        by 刘雨齐                *\n"); 
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");  /*美化界面*/ 
    printf("    游戏说明：这是一个益智游戏。计算机产生4个随机个位数，并按顺序排列好。");
    printf("玩家需要输入4个 不同的 数字，若与计算机产生的随机数完全相同则表示猜测成功。若不同，计算机会给出提示。");
    printf("如：1A2B表示猜测的四个数字中，有1个数字猜对且位置正确，有2个数字猜对但位置错误。");
    printf("但是，这些猜对数字的位置并不给出，需要你去猜测并尝试。\n    祝你成功！\n"); 
    /*开始整个游戏过程*/ 
    while(1)
    {
        create_number(pc);
        x=0; 
        times=input();
        printf("\n你共有 %d 次机会！",times);   
        printf("\n=======================现--在--开--始====================\n请输入四个数字：\n"); 
        for ( i=1; i<=times && x==0 ; i++)  
        {  
            while(1)
            {  guess(i,pd);
               if (*pd==*(pd+1) || *pd==*(pd+2) || *pd==*(pd+3) || *(pd+1)==*(pd+2) || *(pd+1)==*(pd+3) || *(pd+2)==*(pd+3))
                   printf("\n    啊喔，不能输入相同的数字！再来一遍吧！\n");
               else   
               {  x=result(i,times,pc,pd);  break; }
            }
        }
	    printf("\n再玩一次？(y/n)：");
	    again=getche();
	    if(again=='y'||again=='Y') 
            printf("\n\n***************************************************************\n");
        else if(again=='n'||again=='N')   {
             printf("\n谢谢使用，再见！（按任意键退出程序）\n"); 
             getch(); break; 
        } 
    }
    return (0);
}   

int input()   /*输入猜测次数*/ 
{
    int times,i,deltime; char c[3],esc;
    printf("\n请输入猜测次数（范围1~20，默认按回车，随机输x并回车）：");
    while(1)  {
         for (i=0 ; i<=2 ; i++)
         {  
             while(1)  
             {
                 c[i]=getche();
                 if (c[i]==32)  
                     {printf("\b \b"); continue;}/*不能是空格*/ 
                 if (i>0 && (c[i]>='a'&&c[i]<='z' || c[i]>='A'&&c[i]<='Z')) 
                     {printf("\b \b"); continue;} /*对输入字母的控制，只能在第一个位置上输入X或x*/    
                 if (i==0 && (c[i]>='a'&&c[i]<='w' || c[i]>='y'&&c[i]<='z' || c[i]>='A'&&c[i]<='W' || c[i]>='Y'&&c[i]<='Z'))
                     {printf("\b \b"); continue;}
                 if (c[i]==9)
                     {printf("\b\b\b\b\b\b\b"); continue;}/*不能是Tab*/ 
                 if (c[i]==27)                    /*按esc弹出退出选项*/ 
                 { printf("是否退出(Y/N)?");
                   while(1)
                   {
                       esc=getche();
                       if (esc=='y'||esc=='Y')  exit(0);
                       if (esc=='n'||esc=='N')  
                       {
                           for(deltime=0 ; deltime<16 ; deltime++)    
                               {printf("\b \b"); }
                           break;
                       }
                       else printf("\b \b");
                   }
                 }  
                 if (c[i]==8 || c[i]>=33&&c[i]<=40 || c[i]==45||c[i]==46)
                 { printf("\n错误！请重输："); continue;}             
                 else break;
             }   
             if (c[i]=='\r')  break;
         }
         if (c[0]=='1' && c[1]>='0' && c[1]<='9' && c[2]=='\r') /* 将输入的字符转换为数字*/ 
             {times=(c[0]-'0')*10+(c[1]-'0'); break;}
         else if  (c[0]>='1' && c[0]<='9' && c[1]=='\r')
             {times=c[0]-'0';  break;}
         else if  (c[0]=='2' && c[1]=='0' && c[2]=='\r')
             {times=20;  break;}
         else if  ((c[0]=='x' || c[0]=='X') && c[1]=='\r') /*按x则产生随机次数*/ 
         {
              srand(time(NULL));
              do
              {  times=rand()%20;  }
              while (times<=0 || times>20);
              break;
         }
         else if  (c[0]=='\r')
             { times=20;  break; }
         else printf("\n错误！请重输："); 
         } 
    return times;
}

void create_number(int *pc)   /*产生随机数并存到数组中*/ 
{
    int num;
    srand(time(NULL));
	do  {
		num=rand()%10000;
		*pc=num/1000;       *(pc+1)=num/100%10;
		*(pc+2)=num/10%10;  *(pc+3)=num%10;
		}
	while (*pc==*(pc+1) || *pc==*(pc+2) || *pc==*(pc+3) || *(pc+1)==*(pc+2) || *(pc+1)==*(pc+3) || *(pc+2)==*(pc+3)); 
}

void guess(int i, int *pd)  /*猜测时的输入过程*/ 
{
    char input;  int pose,deltime;
    while(1)
    {   
        A:printf("  第%d次 ", i);
        for (pose=0 ; pose<4 ; pose++)
        {
            while(1)
            {  input=getche();
               if (input>'9' || input<'0' ) /*控制输入的字符类型必须为数字，防止出错*/ 
                  { printf("\b \b");}
               else{
                  *(pd+pose)=input-'0';
                  printf(" ");
                  break;
               }  /*在此插入空格将数字隔开*/ 
            }
        }
        printf("  确认吗？（<Enter>/Retry）"); /*输入完毕后，由玩家决定重新输入或结束输入*/ 
        while(1)
        {
            if ( (input=getch() )=='\r') {
                 for(deltime=0 ; deltime<25 ; deltime++)
                     printf("\b \b");
                 break;
            }
            else if (input=='R'||input=='r')
            {
                for (deltime=0 ; deltime<46 ; deltime++)    
                    printf("\b \b");/*输入46个退格，并将所有字符替换成空格，即完成删除操作*/ 
                goto A;   /*删除完毕，重新执行此次循环*/ 
            }
        }
        break;
    }       
}

int result(int now, int times, int *pc, int *pd) /*检验猜测结果并完成本次猜测过程*/ 
{
    int a=0, b=0, i,j,x;
	char c;
    for (i=0 ; i<4 ; i++)   /*将所猜的数与产生的随机数进行比较，并计算相似度A和B的值*/ 
    {   
        if ( *(pc+i)==*(pd+i) )   a++;
		for (j=0 ; j<4 ; j++)
		    if ( *(pc+i)==*(pd+j) && i!=j)  b++;
	}

    if (a<4) 
        if (now>=times)  {
            printf("\n你没有机会了！正确答案是：%d %d %d %d\n",*pc,*(pc+1),*(pc+2),*(pc+3));
            return(1);
        } 
        else  {
            printf("    提示：%dA%dB\n",a,b); 
            return(0);
        }
    else if (now <= times)   {    /*本局游戏结束，程序对玩家给出评价*/ 
         switch(now)  
         {
         case 1: printf("\n你太有才了！" ); break;
         case 2:
         case 3:
         case 4:
         case 5:
         case 6: printf("\n这么快就猜出来了，很聪明嘛！"); break;
         case 7: case 8: case 9: case 10: case 11: case 12: case 13: 
         case 14: case 15: case 16: case 17: case 18: case 19: 
         case 20: printf("\n猜了半天才猜出来，小同志，仍需努力啊！！！"); break;
         }
         return(1);
    }	
}
