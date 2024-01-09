#include "Grid.h"

Grid::Grid(){
	size_x = 0;
	size_y = 0;
	Matrix = NULL;
}

Grid::Grid(int x, int y){
	size_x = x;
	size_y = y;
	int i,j;
	
	Matrix = new Square**[size_x];
	for(int i = 0; i < size_x; i++)
    	Matrix[i] = new Square*[size_y];

	//each square initially is not market and is accessible
	for (i=0;i<size_x;i++){
		for (j=0;j<size_y;j++){
			Matrix[i][j] = new Square(i,j,1,0);
		}
	}
}


void Grid::setX(int c){
	size_x = c;
}
void Grid::setY(int c){
	size_y = c;
}
int Grid::getX(){
	return size_x;
}
int Grid::getY(){
	return size_y;
}
void Grid::makeMatrix(){
	int i,j;
	Matrix = new Square**[size_x];
	for(int i = 0; i < size_x; i++)
    	Matrix[i] = new Square*[size_y];
    for (i=0;i<size_x;i++){
		for (j=0;j<size_y;j++){
			Matrix[i][j] = new Square(i,j,1,0);
		}
	}
}

Square *Grid::getContent(int x, int y){
	return Matrix[x][y];
}
