#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
void main()
{
	int a,b=0,c[4],d[4],m,n,i,j,k;
    srand(time(NULL));
	do  {
		a=rand()%(10000-1000)+1000;
		c[0]=a/1000;   c[1]=a/100%10;
		c[2]=a/10%10;  c[3]=a%10;
		}
	while (c[0]==c[1] || c[0]==c[2] || c[0]==c[3] || c[1]==c[2] || c[1]==c[3] || c[2]==c[3]);
	
	printf("��������Ϸ���������ĸ����֣������ֲ�Ϊ0������֮����һ���ո������\n");
    
	for ( i=1 ; i<8 ; i++)  {
		printf("��%d�� ", i);
		scanf("%d %d %d %d", &d[0],&d[1],&d[2],&d[3]);
		
        m=0; n=0;
		for (j=0 ; j<4 ; j++)  {
			if ( c[j]==d[j] )   m++;
			for (k=0 ; k<4 ; k++)
				if ( c[j]==d[k] && j!=k)  n++;
		}

		if (m<4)  printf("%dA%dB\n",m,n);
		else {printf("��¶��ˣ���������˳���\n"); getch() ; exit(0) ;}
	}
	
	if (i>=7)  
    {printf("��û�л����ˣ����ǣ�%d",a);getch();}
}
