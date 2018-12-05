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
int food_x;
int food_y;

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
		if((snake_location_x[0] == snake_location_x[i] ) && (snake_location_y[0] == snake_location_y[i])) 
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



