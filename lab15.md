---
layout: default
title: 只能蛇实验报告
---

# 实验名称：智能蛇实验报告

专业：软件工程

学号：18342105

姓名：肖霖畅

日期：2018年12月12日





# 目录

## 一、	实验目标	

## 二、	实验步骤与结果

## 三、	控制输入/输出设备	

## 四、 编写智能算法
	

# 一、实验目标

 1.了解 算法 与 “智能” 的关系 

 2.通过算法赋予蛇智能 

 3.了解 Linux IO 设计的控制

# 二、实验步骤及结果

1、实验环境架构

1) Linux Only. 我选择了最新的Ubantu 18.04.1 

下载网址：https://www.ubuntu.com/download/desktop

![]()

2) Oracle VM VirtualBox 下载

下载网址：https://www.virtualbox.org/wiki/Downloads

![]()

3) 编译环境调整

在虚拟机中安装Ubantu后，我设置了编译环境：

安装gcc：

![]()

打开终端，输入 sudo apt-get update 后 输入 sudo apt-get install gcc 输入密码后即可安装GCC。

4) 编码拷贝

为了实现虚拟机和主机的相互拷贝，我使用了VirtualBox中的“共享粘贴板”（位置：设备-共享粘贴板-双向），从主机中将代码复制粘贴。

# 三、控制输入/输出设备

1、VT 100 终端标准 

在字符终端上完成“清屏”“修改光标位置”“设置字符前景和背景色”等操作，是通过输出 esc序列实现的。对于 VT100 终端, printf(“\033[2J”) 就实现了清屏。 

in-demo.c 的代码如下：

	/******************************************************************
 	*                        sinDemo
 	*
 	*   1. 本Demo主要目标是为了实现在终端下实现sin函数的动态效果;
 	*   2. 本Demo之前是使用shell tput和C语言实现的,这次将其改为
 	*       C语言+VT100控制码的形式;
 	*
 	*
 	***************************************************************	**/
 	#include <stdio.h>
 	#include <math.h>
 	#include <unistd.h>

 	/**
  	* 定义圆周率的值
  	*/
 	#define PI  3.14
	/**
  	* 本Demo中假设sin曲线周期为20,幅值也是20,幅值分正负幅值,
  	* 所以后面的很多地方有SIN_AMPLITUDE*2,也就是Y轴方向上的值.
  	*/
 	#define SIN_AMPLITUDE  20      
 	/**
  	* 定义每次刷新图形时间间隔为100ms
  	*/
 	#define DELAY_TIME  100000  
 	/**
  	* 定义圆的一周角度为360度
  	*/
 	#define TRIANGLE  360.0   
 	/**
  	* 输出的时候,数字行放在哪一行,也就是输出图形中的这行数字:
  	*   0123456789012345678901234567890123456789
  	* 本Demo中把上面这行数字放在界面的第3行
  	*/
 	#define Y_NUMBER_BEGIN_LINE  3
 	/**
  	* 在本Demo中,图形就在上面数字行的下一行,也就是输出图形中如下面的内容:
  	*     0000    --------------------@--------------------> Y
  	*     0001                        |-----*             
  	*     0002                        |----------*        
  	*     0003                        |---------------*   
  	*     0004                        |------------------*
  	*     0005                        |------------------*
  	*     0006                        |------------------*
 	*     0007                        |---------------*   
  	*     0008                        |----------*        
  	*     0009                        |-----*             
	*     0010                        *                   
  	*     0011                  *-----|                   
  	*     0012             *----------|                   
  	*     0013        *---------------|                   
  	*     0014     *------------------|                   
	*     0015     *------------------|                   
  	*     0016     *------------------|                   
  	*     0017        *---------------|                   
  	*     0018             *----------|                   
  	*     0019                  *-----|                   
  	*     0020                        V X  
  	*/
 	#define SIN_GRAPH_BEGIN_LINE (Y_NUMBER_BEGIN_LINE+1)

 	int main(int argc, char* argv[]){

     /**
      * 局部变量说明:
      *     1. i                 : 主要用于循环计算;
      *     2. lineNumber        : 用于保存行号;
      *     3. offsetCenter      : 用于保存sin曲线上的点的相对于中心轴的偏移;
      *     4. nextInitAngle     : 保存下一屏要输出图形的初始角度制角度(如30度);
      *     5. currentInitAngle  : 当前一屏要输出的图形的初始角度制角度(如30度);
      *     6. currentInitradian : 当前一屏要输出的图形的初始弧度制弧度(如PI/6)
      *                            根据currentInitAngle换算而来,因为sin函数需要
      *                            角度制进行求值;
      *
      */
     int    i                   = 0;    
     int    lineNumber          = 0;    
     int    offsetCenter        = 0;    
     int    nextInitAngle       = 0;
     double currentInitAngle    = 0;    
     double currentInitradian   = 0;    

     //软件开始运行,清一次屏,保证屏幕上没有无关内容
     printf("\033[2J");

     //输出标题,因为这个软件名字叫: SinDemo
     printf("\033[1;1H                       | SinDemo |\t");

     /**
      * 这里主要是完成那一行重复的0-9,SIN_AMPLITUDE*2是因为sin曲线的
      * 最高点和最低点是2倍的幅值
      */
     printf("\033[%d;1H\t", Y_NUMBER_BEGIN_LINE);
     for (i = 0; i < SIN_AMPLITUDE*2; i++) 
         printf("%d", i%10);
     printf("\n");

     /**
      * while循环主要完成内容:
      *     1. 每次循环对局部变量重新初始化;
      *     2. 将下一屏图形的初始角度赋值给当前的图形初始角;              
      *     3. 将下一屏图形的初始角度加上间隔角度(TRIANGLE/SIN_AMPLITUDE),
      *        TRIANGLE/SIN_AMPLITUDE在本Demo中是360/20=18度,就相当于X轴 
      *        每格代表18度 
      *     2. 调整光标到固定的位置;
      *     3. 重新绘制整屏图形;
      */
     while(1){

         //重新初始化局部变量,因为每一屏图形都像一个新的开始
         i                  = 0;        
         offsetCenter       = 0;       
         lineNumber         = 0;      
         currentInitradian  = 0;     

         //从nextInitAngle中获取当前的初始化角度
         currentInitAngle   =  nextInitAngle;

         //为下一次循环提供下一次的初始化角度
         nextInitAngle     += TRIANGLE/SIN_AMPLITUDE;  

         //将光标移动到开始绘图的位置去
         printf("\033[%d;1H", SIN_GRAPH_BEGIN_LINE);

         /**
          * 根据不同的情况绘制图形, 每一次循环,就是绘制了图形中的一行
          */
         while(1){
             //判断是不是最后一行,lineNumber起始行是从0开始
             if(lineNumber == SIN_AMPLITUDE){
                 //打印最后一行前面的数字行号
                 printf("\033[%d;1H%04d\t", lineNumber+SIN_GRAPH_BEGIN_LINE, lineNumber);
                 for (i = 0; i < SIN_AMPLITUDE*2; i++)
                     /**
                      * 判断是否到达中间位置,因为中间位置要放V的箭头,同时在旁边输出一个X,
                      * 代表这是X轴方向.
                      */
                     i == SIN_AMPLITUDE ? printf("V X") : printf(" ");    
                 break;
             }


             /**
              * 对currentInitAngle角度进行修整,比如370度和10度是对应相同的sin值
              * 其实这一步可以不用,但是这里保留了,后面是将currentInitAngle角度制的值
              * 换算成对应的弧度制的值,便于sin求值.
              */
             currentInitAngle = ((int)currentInitAngle)%((int)TRIANGLE);
             currentInitradian = currentInitAngle/(TRIANGLE/2)*PI;    

             /**
              * 算出当前次currentInitradian对应的sin值,并乘以幅值SIN_AMPLITUDE,获取sin曲线
              * 在Y轴上相对于中心轴的偏移offsetCenter,offsetCenter可能是正值,也可能是负值,
              * 因为中心轴在中间.
              */
             offsetCenter = (int)(sin(currentInitradian)*SIN_AMPLITUDE);                

             /**
              * 在正确的地方输出正确的行号   :)
              */
             printf("\033[%d;1H%04d", lineNumber+SIN_GRAPH_BEGIN_LINE, lineNumber);

             //用一个制表符,给出行号与图形的空间距离
             printf("\t");

             /**
              * 第一行,和其他的行不一样,有区别,输出结果如下:
              * 0000    ------------@-------+--------------------> Y
              */
             if(lineNumber == 0){
                 for (i = 0; i < SIN_AMPLITUDE*2; i++){
                     /**
                      * 判断当前输出的字符位置是否是X,Y轴交叉的位置,如果是就输出'+',
                      * 不是就输出'-'
                      */
                     i == SIN_AMPLITUDE ? printf("+") : printf("-");
                     /**
                      * 判断当前输出的字符位置是否是sin曲线上的点对应的位置,
                      * 如果是就输出'@'
                      */
                     if(i == offsetCenter+SIN_AMPLITUDE)
                         printf("@");
                 }
                 //代表这个方向是Y轴
                 printf("-> Y\n");
             } else { 
                 for (i = 0; i < SIN_AMPLITUDE*2; i++){
                     //判断当前输出的字符位置是否是sin曲线上的点对应的位置,如果是就输出'*'
                     if(i == (offsetCenter+SIN_AMPLITUDE)){
                         printf("*");
                     //判断当前输出的字符位置是否是X轴上对应的位置,如果是就输出'|'
                     }else if(i == SIN_AMPLITUDE){
                         printf("|");
                     }else{
                         /**
                          * 这里主要是要处理一行里面除了画'*'、'|'、之外的'-'、' '
                          * 其中的SIN_AMPLITUDE到SIN_AMPLITUDE+offsetCenter正好就是需要输出'-'的地方
                          * 其他的地方输出' '
                          */
                         (((i > SIN_AMPLITUDE) && (i < SIN_AMPLITUDE+offsetCenter)) || \
                             ((i < SIN_AMPLITUDE) && (i > SIN_AMPLITUDE+offsetCenter))) \
                                 ? printf("-") : printf(" ");
                     }
                     //行尾,输出换行符
                     if(i == (SIN_AMPLITUDE*2-1)) 
                         printf("\n");
                 }
             }

             /**
              * 一行输出完成,为下一行输出作准备,下一行比上一行在角度上多加TRIANGLE/SIN_AMPLITUDE,
              * 在本Demo中相当于360/20=18,也就是加18度.
              */
             currentInitAngle += TRIANGLE/SIN_AMPLITUDE;      

             //行号加1
             lineNumber++;                                    
         }
         /**
          * 一屏图像输出完毕,最后输出一个换行符,并且延时一段时间再开始绘制下一屏图形
          */
         printf("\n");
         usleep(DELAY_TIME);
     }

     return 0;
 	}


![]()

2、实现 kbhit() 

	#include <stdio.h>
	#include <string.h>
	#include <sys/time.h>
	#include <sys/types.h>
	#include <unistd.h>
	#include <termios.h>
	#include <unistd.h>

	static struct termios ori_attr, cur_attr;

	static __inline 
	int tty_reset(void)
	{
        if (tcsetattr(STDIN_FILENO, TCSANOW, &ori_attr) != 0)
                return -1;

			return 0;
	}


	static __inline
	int tty_set(void)
	{
        
        if ( tcgetattr(STDIN_FILENO, &ori_attr) )
                return -1;
        
        memcpy(&cur_attr, &ori_attr, sizeof(cur_attr) );
        cur_attr.c_lflag &= ~ICANON;
	//        cur_attr.c_lflag |= ECHO;
        cur_attr.c_lflag &= ~ECHO;
        cur_attr.c_cc[VMIN] = 1;
        cur_attr.c_cc[VTIME] = 0;

        if (tcsetattr(STDIN_FILENO, TCSANOW, &cur_attr) != 0)
                return -1;

        return 0;
	}

	static __inline
	int kbhit(void) 
	{
                   
        fd_set rfds;
        struct timeval tv;
        int retval;

        /* Watch stdin (fd 0) to see when it has input. */
        FD_ZERO(&rfds);
        FD_SET(0, &rfds);
        /* Wait up to five seconds. */
        tv.tv_sec  = 0;
        tv.tv_usec = 0;

        retval = select(1, &rfds, NULL, NULL, &tv);
        /* Don't rely on the value of tv now! */

        if (retval == -1) {
                perror("select()");
                return 0;
        } else if (retval)
                return 1;
        /* FD_ISSET(0, &rfds) will be true. */
        else
                return 0;
        return 0;
	}

	//将你的 snake 代码放在这里

	int main()
	{
        //设置终端进入非缓冲状态
        int tty_set_flag;
        tty_set_flag = tty_set();

        //将你的 snake 代码放在这里
        printf("pressed `q` to quit!\n");
        while(1) {

                if( kbhit() ) {
                        const int key = getchar();
                        printf("%c pressed\n", key);
                        if(key == 'q')
                                break;
                } else {
                       ;// fprintf(stderr, "<no key detected>\n");
                }
        }

        //恢复终端设置
        if(tty_set_flag == 0) 
                tty_reset();
        return 0;
	}


# 四、编写智能算法

我的人工智能程序，使得 snake 每秒自动走一步。



1、程序要求

1)实现如下算法决定蛇行走的方向： 

	#include<stdio.h>
	#include<stdlib.h>
	#include<time.h>
	#include<conio.h>
	#include<math.h>
	#include<windows.h>//linux使用unistd.h

	#define SNAKE_MAX_LENGTH 20
	#define SNAKE_HEAD 'H'
	#define SNAKE_BODY 'X'
	#define BLANK_CELL ' '
	#define SNAKE_FOOD '$'
	#define WALL_CELL '*'

	void snakeMove(int,int);
	void put_money(void);

	int snakeX[SNAKE_MAX_LENGTH]={5,4,3,2,1};//5代表蛇的头部
	int snakeY[SNAKE_MAX_LENGTH]={1,1,1,1,1};
	int snakeLength=5;
	char map[12][13]=//随机生成食物
	{
    "************",
    "*XXXXH  $  *",
    "*          *",
    "*       $  *",
    "*          *",
    "*          *",
    "*    $     *",
    "*          *",
    "*          *",
    "*   $      *",
    "*          *",
    "************"
	};

	void output()
	{
    int i;
    for(i=0;i<12;i++)
    {
            printf("%s\n",map[i]);

    }
	}

	void gameover()
	{
    printf("Game Over!!!");
	}

	char movable[4]={'W','A','S','D'};//按键
	 int distance[4]={0,0,0,0};//可走方向距离食物的距离
	 char whereGoNext(int Hx,int Hy,int Fx,int Fy)
	 {

    //判断A方向距离
    if(map[Hx-1][Hy]=='X')
        distance[0]=9999;//判断是否是身体
    else
    {
        distance[0]=abs(Fx-Hx+1)+abs(Fy-Hy);
    }


    //判断W方向有没有食物，食物的距离
    if(map[Hx][Hy-1]=='X')
    {
        distance[1]=9999;
    }else
    {
        distance[1]=abs(Fx-Hx)+abs(Fy-Hy+1);
    }

    //判断D方向有没有食物，食物的距离
    if(map[Hx+1][Hy]=='X')
    {
        distance[2]=9999;
    }else
    {
        distance[2]=abs(Fx-Hx-1)+abs(Fy-Hy);
    }


    //判断S方向有没有食物，食物的距离
    if(map[Hx][Hy+1]=='X')
    {
        distance[3]=9999;
    }else
    {
        distance[3]=abs(Fx-Hx)+abs(Fy-Hy-1);
    }

    //判断方向和输出
    int min=9999;
    int i;
    for(i=0;i<4;i++)
    {
        min=(min<distance[i])?min:distance[i];
    }
    if(min==9999)
        return 'Q';
    for(i=0;i<4;i++)
    {
        if(min==distance[i])
            break;
    }
    return movable[i];
 	}
 	int main()
 	{
    output();
    while(1)
    {
    int i,j;
    int Hx,Hy,Fx,Fy;
    for(i=1;i<11;i++)
    {
        for(j=1;j<11;j++)
        {
            if(map[i][j]=='H')
            {
               Hx=i;
               Hy=j;
               break;
            }
        }
    }

    //顺序查找，找到第一个食物
    int flag=0;
    for(i=1;i<11;i++)
    {
        if(flag==1)
            break;
        for(j=1;j<11;j++)
        {
            if(flag==1)
                break;
            if(map[i][j]=='$')
            {
               Fx=i;
               Fy=j;
               flag=1;
            }
        }
    }

       Sleep(1000);//linux下sleep()
        char ch;

        ch=whereGoNext(Hx,Hy,Fx,Fy);
        //我们的游戏条件：必须是大写的asdw控制方向，否则退出！

        //如果没有食物就退出，否则陷入死循环
        int flag1=0;
        for(i=1;i<11;i++)
        {
        for(j=1;j<11;j++)
        {
            if(map[i][j]=='$')
            {
               flag1++;
            }
        }
        }
        if(flag1==0)
        {ch='Q';}
        if(ch!='A'&&ch!='S'&&ch!='W'&&ch!='D')
            break;
        map[snakeY[snakeLength-1]][snakeX[snakeLength-1]]=' ';
        switch(ch)
        {
        case 'A':
            for(i=snakeLength-1;i>0;i--)
            {
                snakeX[i]=snakeX[i-1];
                snakeY[i]=snakeY[i-1];
            }
            snakeX[0]--;
            break;
        case 'D':
            for(i=snakeLength-1;i>0;i--)
            {
                snakeX[i]=snakeX[i-1];
                snakeY[i]=snakeY[i-1];
            }
            snakeX[0]++;
            break;
        case 'W':
            for(i=snakeLength-1;i>0;i--)
            {
                snakeX[i]=snakeX[i-1];
                snakeY[i]=snakeY[i-1];
            }
            snakeY[0]--;
            break;
        case 'S':
            for(i=snakeLength-1;i>0;i--)
            {
                snakeX[i]=snakeX[i-1];
                snakeY[i]=snakeY[i-1];
            }
            snakeY[0]++;
            break;
        }
        //判断有没有撞到障碍
        if(snakeX[0]<1||snakeX[0]>10||snakeY[0]<1||snakeY[0]>10)
            break;
        //吃食物长一节
        if(map[snakeY[0]][snakeX[0]]=='$')
        {
            snakeLength++;
            if(snakeX[snakeLength-2]==snakeX[snakeLength-3])
            {
                snakeX[snakeLength-1]=snakeX[snakeLength-2];
                snakeY[snakeLength-1]=2*snakeY[snakeLength-2]-snakeY[snakeLength-3];
            }else
            {
                snakeY[snakeLength-1]=snakeY[snakeLength-2];
                snakeX[snakeLength-1]=2*snakeX[snakeLength-2]-snakeX[snakeLength-3];

            }

        }
        for(i=1;i<snakeLength;i++)
        {
        map[snakeY[i]][snakeX[i]]='X';//先行后列
        }
        //判断有没有撞到身体
        if(map[snakeY[0]][snakeX[0]]=='X')
            break;

        //判断食物，如果遇到食物就长一节身体

        map[snakeY[0]][snakeX[0]]='H';

        output();

    }
    gameover();
    return 0;
	}


一个长度为5的障碍物不能困死该自动跑的蛇。


