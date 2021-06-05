#include "duck/Duck.h"

#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h> 
#include <iostream>
#include <string>
#include<windows.h>

Duck::Duck(int w, int h, int x, int y): 
	_w(w), _h(h), _x(x), _y(y)
{
	img = { _x, _y, _w, _h };
	alive = true;
}

Duck::~Duck() {
	
}


void Duck::move() {
	if (alive) {
		
		int dir = rand() % 8 + 1;		
		int distance = rand() % 3 + 5;

		switch (dir)
		{
		case 1:
			if (_y - distance > 0)
				_y -= distance;
			break;
		case 2:
			if (_x + distance < 700 && _y - distance > 0) {
				_x += distance;
				_y -= distance;
			}
			break;
		case 3:
			if (_x + distance < 500)
				_x += distance;
			break;
		case 4:
			if (_x + distance < 700 && _y + distance < 500) {
				_x += distance;
				_y += distance;
			}
			break;
		case 5:
			if (_y + distance < 500)
				_y += distance;
			break;
		case 6:
			if (_x - distance > 0 && _y + distance < 500) {
				_x -= distance;
				_y += distance;
			}
			break;
		case 7:
			if (_x - distance > 0)
				_x -= distance;
			break;
		case 8:
			if (_x - distance > 0 && _y - distance > 0) {
				_x -= distance;
				_y -= distance;
			}
			break;
		default:
			break;
		}

		img = { _x, _y, _w, _h };
	}
	else {
		if (_y++ < 700) {
			_y+=4;
			img = { _x, _y, _w, _h };
		}
	}
}

int Duck::getX() {
	return _x;
}

int Duck::getY() {
	return _y;
}

bool Duck::isAlive(){
	return alive;
}

bool Duck::die() {

	alive = 0;
	
	return alive;
}

bool Duck::spawn() {

	alive = 1;

	return alive;
}

SDL_Rect* Duck::getRect() {
	return &img;
}