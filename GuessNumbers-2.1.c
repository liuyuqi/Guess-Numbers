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
    printf("*          ������V2.1        by ������                *\n"); 
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");  /*��������*/ 
    printf("    ��Ϸ˵��������һ��������Ϸ�����������4�������λ��������˳�����кá�");
    printf("�����Ҫ����4�� ��ͬ�� ���֣����������������������ȫ��ͬ���ʾ�²�ɹ�������ͬ��������������ʾ��");
    printf("�磺1A2B��ʾ�²���ĸ������У���1�����ֲ¶���λ����ȷ����2�����ֲ¶Ե�λ�ô���");
    printf("���ǣ���Щ�¶����ֵ�λ�ò�����������Ҫ��ȥ�²Ⲣ���ԡ�\n    ף��ɹ���\n"); 
    /*��ʼ������Ϸ����*/ 
    while(1)
    {
        create_number(pc);
        x=0; 
        times=input();
        printf("\n�㹲�� %d �λ��ᣡ",times);   
        printf("\n=======================��--��--��--ʼ====================\n�������ĸ����֣�\n"); 
        for ( i=1; i<=times && x==0 ; i++)  
        {  
            while(1)
            {  guess(i,pd);
               if (*pd==*(pd+1) || *pd==*(pd+2) || *pd==*(pd+3) || *(pd+1)==*(pd+2) || *(pd+1)==*(pd+3) || *(pd+2)==*(pd+3))
                   printf("\n    ��ร�����������ͬ�����֣�����һ��ɣ�\n");
               else   
               {  x=result(i,times,pc,pd);  break; }
            }
        }
	    printf("\n����һ�Σ�(y/n)��");
	    again=getche();
	    if(again=='y'||again=='Y') 
            printf("\n\n***************************************************************\n");
        else if(again=='n'||again=='N')   {
             printf("\nллʹ�ã��ټ�������������˳�����\n"); 
             getch(); break; 
        } 
    }
    return (0);
}   

int input()   /*����²����*/ 
{
    int times,i,deltime; char c[3],esc;
    printf("\n������²��������Χ1~20��Ĭ�ϰ��س��������x���س�����");
    while(1)  {
         for (i=0 ; i<=2 ; i++)
         {  
             while(1)  
             {
                 c[i]=getche();
                 if (c[i]==32)  
                     {printf("\b \b"); continue;}/*�����ǿո�*/ 
                 if (i>0 && (c[i]>='a'&&c[i]<='z' || c[i]>='A'&&c[i]<='Z')) 
                     {printf("\b \b"); continue;} /*��������ĸ�Ŀ��ƣ�ֻ���ڵ�һ��λ��������X��x*/    
                 if (i==0 && (c[i]>='a'&&c[i]<='w' || c[i]>='y'&&c[i]<='z' || c[i]>='A'&&c[i]<='W' || c[i]>='Y'&&c[i]<='Z'))
                     {printf("\b \b"); continue;}
                 if (c[i]==9)
                     {printf("\b\b\b\b\b\b\b"); continue;}/*������Tab*/ 
                 if (c[i]==27)                    /*��esc�����˳�ѡ��*/ 
                 { printf("�Ƿ��˳�(Y/N)?");
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
                 { printf("\n���������䣺"); continue;}             
                 else break;
             }   
             if (c[i]=='\r')  break;
         }
         if (c[0]=='1' && c[1]>='0' && c[1]<='9' && c[2]=='\r') /* ��������ַ�ת��Ϊ����*/ 
             {times=(c[0]-'0')*10+(c[1]-'0'); break;}
         else if  (c[0]>='1' && c[0]<='9' && c[1]=='\r')
             {times=c[0]-'0';  break;}
         else if  (c[0]=='2' && c[1]=='0' && c[2]=='\r')
             {times=20;  break;}
         else if  ((c[0]=='x' || c[0]=='X') && c[1]=='\r') /*��x������������*/ 
         {
              srand(time(NULL));
              do
              {  times=rand()%20;  }
              while (times<=0 || times>20);
              break;
         }
         else if  (c[0]=='\r')
             { times=20;  break; }
         else printf("\n���������䣺"); 
         } 
    return times;
}

void create_number(int *pc)   /*������������浽������*/ 
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

void guess(int i, int *pd)  /*�²�ʱ���������*/ 
{
    char input;  int pose,deltime;
    while(1)
    {   
        A:printf("  ��%d�� ", i);
        for (pose=0 ; pose<4 ; pose++)
        {
            while(1)
            {  input=getche();
               if (input>'9' || input<'0' ) /*����������ַ����ͱ���Ϊ���֣���ֹ����*/ 
                  { printf("\b \b");}
               else{
                  *(pd+pose)=input-'0';
                  printf(" ");
                  break;
               }  /*�ڴ˲���ո����ָ���*/ 
            }
        }
        printf("  ȷ���𣿣�<Enter>/Retry��"); /*������Ϻ�����Ҿ�������������������*/ 
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
                    printf("\b \b");/*����46���˸񣬲��������ַ��滻�ɿո񣬼����ɾ������*/ 
                goto A;   /*ɾ����ϣ�����ִ�д˴�ѭ��*/ 
            }
        }
        break;
    }       
}

int result(int now, int times, int *pc, int *pd) /*����²�������ɱ��β²����*/ 
{
    int a=0, b=0, i,j,x;
	char c;
    for (i=0 ; i<4 ; i++)   /*�����µ������������������бȽϣ����������ƶ�A��B��ֵ*/ 
    {   
        if ( *(pc+i)==*(pd+i) )   a++;
		for (j=0 ; j<4 ; j++)
		    if ( *(pc+i)==*(pd+j) && i!=j)  b++;
	}

    if (a<4) 
        if (now>=times)  {
            printf("\n��û�л����ˣ���ȷ���ǣ�%d %d %d %d\n",*pc,*(pc+1),*(pc+2),*(pc+3));
            return(1);
        } 
        else  {
            printf("    ��ʾ��%dA%dB\n",a,b); 
            return(0);
        }
    else if (now <= times)   {    /*������Ϸ�������������Ҹ�������*/ 
         switch(now)  
         {
         case 1: printf("\n��̫�в��ˣ�" ); break;
         case 2:
         case 3:
         case 4:
         case 5:
         case 6: printf("\n��ô��Ͳ³����ˣ��ܴ����"); break;
         case 7: case 8: case 9: case 10: case 11: case 12: case 13: 
         case 14: case 15: case 16: case 17: case 18: case 19: 
         case 20: printf("\n���˰���Ų³�����Сͬ־������Ŭ����������"); break;
         }
         return(1);
    }	
}
