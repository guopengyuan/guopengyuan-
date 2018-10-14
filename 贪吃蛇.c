#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

	  int i, j;					//ѭ������ 
	  char biankuang[20][20]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					   	      {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						   	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						   	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						  	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
	int x,y;					//xy�������� 
	enum {to_east = 2,to_west=-2,to_north=-1,to_south=1};//���巽�� 
	int snake[350][3];
	int direction=to_east;

	void entrance()			//�������
	{
	
		
		char chinput;
		printf("��ӭ����̰���ߣ����ո����ʼ��Ϸ��,\n");
		while(1)
		{
			chinput=getch();
			if(' '==chinput)
			{
			system("cls");
			break;
			} 
		}
	}
	  
	void snakeposition()	//��������ߵ�λ��
	{
		
		srand((unsigned int)time(NULL));
		x=rand()%18+1;				//�� 
		y=rand()%15+3;  			//�� 
		
	
		//x��ʾ�У�y��ʾ�� ,��ʼ���ߵ�λ�� 
		snake[0][0]=x;
		snake[0][1]=y+1;
		snake[0][2]=to_east; 
		
		snake[1][0]=x;
		snake[1][1]=y+2;
		snake[1][2]=to_east;
		
		snake[2][0]=x;
		snake[2][1]=y;
		snake[2][2]=to_east;
	}
		
	void printfsnake()	//��ʼ���ߣ�ʹ�߳�Ϊ�߿��һ���� 
	{
		int i;
		for(i=0;snake[i][0]!=0;i++)
		 {
			biankuang[snake[i][0]][snake[i][1]]=1; 
		 } 
		
	}
   
	void bianjie()		//��ӡ�߽� ���� 
	{
		for(i=0;i<20;i++)
		{
		  for(j=0;j<20;j++)
			if(biankuang[i][j]==1)
			{
				printf("��");
			}
			else
			{
				printf("  ");
		    } 
				
		printf("\n");
		}
	}	
	void cleansnake()		//������			
	{	
		int i;
		for(i=0;snake[i][0]!=0;i++)
		 {
			biankuang[snake[i][0]][snake[i][1]]=0; 
		 } 
	} 
	void snakemove()	//�߶����� 
    { 
		
		for(i=349;i>=1;i--)
		{
			if(snake[i][0]==0)
			{
				continue;		//���˵�δ������� 
			}
		snake[i][0]=snake[i-1][0];
		snake[i][1]=snake[i-1][1];
		snake[i][2]=snake[i-1][2];
	
		}
		//������ͷ 
		snake[0][2]=direction;
		if(snake[0][2]==to_west||snake[0][2]==to_east) 
		{
			snake[0][1]+=snake[0][2];
		}
		else
		{
			snake[0][0]+=snake[0][2];
		}
		
	}
			
	void changedirection()	//�ı䷽��	
	{
		int dir;
		if(_kbhit())
		{
			dir=_getch();
		}
		switch(dir)
		{
			case 'w' :
			direction=to_north;
			break;
			case 's' :
			direction=to_south;
			break;
			case 'a' :
			direction=to_west;
			break;
			case 'd' :
			direction=to_east;
			break;
	 	}
	}




int main()
{ 
	
	//������� 
	 entrance();
	//��������ߵ�λ�� 
	 snakeposition(); 
	
	while(1)
	{
	system("cls");
	//�ı䷽�� 
	changedirection();
	//������ 
	cleansnake();
  
	
	//�߶����� 
    snakemove();
	//��ӡ�߽缰�� 
    printfsnake();
    bianjie(); 
    
  
    
	Sleep(100);
 	}       
 


}
 
