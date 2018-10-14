#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

	  int i, j;					//循环变量 
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
	int x,y;					//xy代表坐标 
	enum {to_east = 2,to_west=-2,to_north=-1,to_south=1};//定义方向 
	int snake[350][3];
	int direction=to_east;

	void entrance()			//进入界面
	{
	
		
		char chinput;
		printf("欢迎来到贪吃蛇，按空格键开始游戏。,\n");
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
	  
	void snakeposition()	//随机产生蛇的位置
	{
		
		srand((unsigned int)time(NULL));
		x=rand()%18+1;				//行 
		y=rand()%15+3;  			//列 
		
	
		//x表示行，y表示列 ,初始化蛇的位置 
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
		
	void printfsnake()	//初始化蛇，使蛇成为边框的一部分 
	{
		int i;
		for(i=0;snake[i][0]!=0;i++)
		 {
			biankuang[snake[i][0]][snake[i][1]]=1; 
		 } 
		
	}
   
	void bianjie()		//打印边界 及蛇 
	{
		for(i=0;i<20;i++)
		{
		  for(j=0;j<20;j++)
			if(biankuang[i][j]==1)
			{
				printf("■");
			}
			else
			{
				printf("  ");
		    } 
				
		printf("\n");
		}
	}	
	void cleansnake()		//销毁蛇			
	{	
		int i;
		for(i=0;snake[i][0]!=0;i++)
		 {
			biankuang[snake[i][0]][snake[i][1]]=0; 
		 } 
	} 
	void snakemove()	//蛇动起来 
    { 
		
		for(i=349;i>=1;i--)
		{
			if(snake[i][0]==0)
			{
				continue;		//过滤掉未填的蛇身 
			}
		snake[i][0]=snake[i-1][0];
		snake[i][1]=snake[i-1][1];
		snake[i][2]=snake[i-1][2];
	
		}
		//处理蛇头 
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
			
	void changedirection()	//改变方向	
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
	
	//进入界面 
	 entrance();
	//随机产生蛇的位置 
	 snakeposition(); 
	
	while(1)
	{
	system("cls");
	//改变方向 
	changedirection();
	//清理蛇 
	cleansnake();
  
	
	//蛇动起来 
    snakemove();
	//打印边界及蛇 
    printfsnake();
    bianjie(); 
    
  
    
	Sleep(100);
 	}       
 


}
 
