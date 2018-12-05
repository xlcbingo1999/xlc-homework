
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
     money_x = rand() % 10 ;
     money_y = rand() % 10 ;
    while (map[money_y][money_x] != ' ') {
        money_x = rand() %  10  ;
        money_y = rand() %  10  ;
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
			++ snake_length;// Just add the length of snake. 
		} 
		if(!gameover()){
			printf("Gameover!!!");
			return 0;
		}
		else 
			output();
	} 
}



