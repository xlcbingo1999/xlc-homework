---
layout: default
title: 贪吃蛇实验报告
---

# 实验名称：贪吃蛇实验报告

专业：软件工程

学号：18342105

姓名：肖霖畅

日期：2018年12月5日





# 目录

## 一、	实验目标	

## 二、	实验步骤与结果

## 三、	实验小结	
	

# 一、实验目标

1、了解贪吃蛇的实验原理；

2、趣味生活。

# 二、实验步骤及结果

1、伪代码框架

输出字符矩阵

	WHILE not 游戏结束 DO

		ch＝等待输入

		CASE ch DO

		‘A’:左前进一步，break 

		‘D’:右前进一步，break   

		‘W’:上前进一步，break 

		‘S’:下前进一步，break  

		END CASE

		输出字符矩阵

	END WHILE

	输出 Game Over!!! 

2、snake_move 程序代码实现

![](http://5b0988e595225.cdn.sohucs.com/images/20181018/1ee7024979114e5d82ac8913f6788872.jpeg)

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#define SNAKE_MAX_LENGTH 20

#define SNAKE_HEAD 'H'

#define SNAKE_BOOY 'X'

#define BLANK_CELL ' '

#define SNAKE_FOOD '$'

#define WALL_CELL '*'

#define ture 1 


char map[12][12] = 

{"************",

"*X         *",

"*X         *",

"*X         *",

"*X         *",

"*H         *",

"*          *",

"*          *",

"*          *",

"*          *",

"*          *",

"************"};// I change the way of snake.


int snake_length = 5;

int snake_location_y[10] = {5, 4, 3, 2, 1};

int snake_location_x[10] = {1, 1, 1, 1, 1};

void snake_move(){

	int i;

	map[snake_location_y[snake_length - 1]][snake_location_x[snake_length - 1]] = ' ';

	for(i = snake_length - 1 ; i > 0 ;  --i ){

		snake_location_x[i] = snake_location_x[i-1];

		snake_location_y[i] = snake_location_y[i-1];

		map[snake_location_y[i]][snake_location_x[i]] = 'X';

	}

}// You can diverse four "X"s and a "H".For every "X", it will do the same thing, just going rightaway.

void output(){

	int i,j; 

	for( i = 0 ; i < 12 ; ++ i){

		for( j = 0 ; j < 12 ; ++ j){

			printf("%c",map[i][j]);

		}

		printf("\n");

	}

}// In this step, you can print the map.

int gameover(){

	if(snake_location_x[0] == 11 || snake_location_x[0] == 0){

		return 0;

	}

	if(snake_location_y[0] == 11 || snake_location_y[0] == 0){

		return 0;

	}

	int i;

	for( i = 1 ; i < snake_length ; ++ i){

		if((snake_location_x[0] == snake_location_x[i] ) &&
        (snake_location_y[0] == snake_location_y[i])) 

			return 0;

	}

	return 1;

} // In this funtion, if the snake hits the wall, the funtion will return "0".

int main(){

	output();// To let player know the first location of the snake.

	while(ture){

	char putin;// You can put in w/a/s/d .

	scanf(" %c",&putin);

	snake_move();

		if(putin == 'd'){

			snake_location_x[0] += 1;

			map[snake_location_y[0]][snake_location_x[0]] = 'H';

		} 
    
		if(putin == 'a'){

			snake_location_x[0] -= 1;

			map[snake_location_y[0]][snake_location_x[0]] = 'H';

		} 

		if(putin == 'w'){

			snake_location_y[0] -= 1;

			map[snake_location_y[0]][snake_location_x[0]] = 'H';

		} 

		if(putin == 's'){

			snake_location_y[0] += 1;

			map[snake_location_y[0]][snake_location_x[0]] = 'H';

		} 

		if(!gameover()){

			printf("Gameover!!!");

			return 0;

		}

		else 

			output();

	} 

}

![](http://5b0988e595225.cdn.sohucs.com/images/20181018/44e2a2011518496cb60485fb256f2843.jpeg)

3、snake_eat 程序代码实现


#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#define SNAKE_MAX_LENGTH 30

#define SNAKE_HEAD 'H'

#define SNAKE_BOOY 'X'

#define BLANK_CELL ' '

#define SNAKE_FOOD '$'

#define WALL_CELL '*'

#define ture 1 


char map[12][12] = 

{"************",

"*X         *",

"*X         *",

"*X         *",

"*X         *",

"*H         *",

"*          *",

"*          *",

"*          *",

"*          *",

"*          *",

"************"};


int snake_length = 5;

int snake_location_y[20] = {5, 4, 3, 2, 1};

int snake_location_x[20] = {1, 1, 1, 1, 1};

int money_x;

int money_y;

void snake_move(){

	int i;

	map[snake_location_y[snake_length - 1]][snake_location_x[snake_length - 1]] = ' ';

	for(i = snake_length - 1 ; i > 0 ;  --i ){

		snake_location_x[i] = snake_location_x[i-1];

		snake_location_y[i] = snake_location_y[i-1];

		map[snake_location_y[i]][snake_location_x[i]] = 'X';

	}

}// In thie funtion, you can move the "x"s.

void output(){

	int i,j; 

	for( i = 0 ; i < 12 ; ++ i){

		for( j = 0 ; j < 12 ; ++ j){

			printf("%c",map[i][j]);

		}

		printf("\n");

	}

}// Output the map.

int gameover(){

	if(snake_location_x[0] == 11 || snake_location_x[0] == 0){

		return 0;

	}

	if(snake_location_y[0] == 11 || snake_location_y[0] == 0){

		return 0;

	}

	int i;

	for( i = 1 ; i < snake_length ; ++ i){

		if((snake_location_x[0] == snake_location_x[i] ) && (snake_location_y[0] == snake_location_y[i])) 

			return 0;

	}

	return 1;

}//When the snake hits the wall or it hits itself, it will die, with the game overing.

void set_money(){

	 srand((unsigned)(time(NULL)));

     money_x = rand() % 10;

     money_y = rand() % 10;

    while (map[money_y][money_x] != ' ') {

        money_x = rand() %  10 ;

        money_y = rand() %  10 ;

    }

    map[money_y][money_x] = '$';

}// To not let "&" changes the wall, we should set two random value.

int main(){

	set_money();

	output();

	while(ture){

	char putin;

	scanf(" %c",&putin);// Put in "a" or "s" or "d" or "w".

	snake_move();

		if(putin == 'd'){

			snake_location_x[0] += 1;

			map[snake_location_y[0]][snake_location_x[0]] = 'H';

		} 

		if(putin == 'a'){

			snake_location_x[0] -= 1;

			map[snake_location_y[0]][snake_location_x[0]] = 'H';

		} 

		if(putin == 'w'){

			snake_location_y[0] -= 1;

			map[snake_location_y[0]][snake_location_x[0]] = 'H';

		} 

		if(putin == 's'){

			snake_location_y[0] += 1;

			map[snake_location_y[0]][snake_location_x[0]] = 'H';

		} 

		if(snake_location_x[0] == money_x && snake_location_y[0] == money_y){

			set_money();

			++ snake_length;

		} // Just add the length of snake. 

		if(!gameover()){

			printf("Gameover!!!");

			return 0;

		}

		else 

			output();

	} 

}




# 三、实验小结

1、实现了以下功能需求：

snake 头撞到身体、障碍（边界或你在地图中定义） 游戏结束

snake 头吃到食物，snake就长一节

2、细化并完善随机放置食物的伪代码 

找一个空白位置

在该位置放置食物


