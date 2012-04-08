/************************************************************************
*                          Game Object Class                            *
*************************************************************************/

#pragma once

#include "assembly.h"
#include <iostream>

class GameObject
{
public:
		GameObject();
		void virtual Destroy();

		void init(float x, float y, float velX, float velY, int dirx, int diry, int boundX, int boundY);
		void virtual Update();
		void virtual Render();

		float getX() {return x;}
		float getY() {return y;}

		void setX(float x) {GameObject::x = x;}
		void setY(float y) {GameObject::y = y;}

		int getBoundX() {return boundX;}
		int getBoundY() {return boundY;}

		int getID() {return mID;}
		void setID(int ID) {GameObject::mID = ID;}

		bool getAlive() {return mIsAlive;}
		void setAlive(bool alive) {GameObject::mIsAlive = alive;}

		bool getCollideable() {return mIsCollidable;}
		void setCollideable(bool collideable) {GameObject::mIsCollidable = collideable;}

		bool checkCollisions(GameObject *otherObject);
		void virtual Collided(int objectID);
		bool Collidable();

		
protected:
		float x;
		float y;

		float velX;
		float velY;

		int dirX;
		int dirY;

		int boundX;
		int boundY;

		int maxFrame;
		int curFrame;
		int frameCount;
		int frameDelay;
		int frameWidth;
		int frameHeight;
		int animationColumns;
		int animationDirection;

		ALLEGRO_BITMAP *image;
private:
		//ID of the Game Object
		int mID;
		//Check to see if the object is alive
		bool mIsAlive;
		//Check to see if the object is collideable
		bool mIsCollidable;
};