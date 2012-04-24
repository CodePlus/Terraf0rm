/************************************************************************
*                          Game Object Class                            *
*************************************************************************/
#pragma once
#include "assembly.h"


class GameObject
{
	#pragma message ("Game Object is included")
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

		void setBoundX(float boundx) {GameObject::boundX = x;}
		void setBoundY(float boundy) {GameObject::boundY = y;}

		int getBoundX() {return boundX;}
		int getBoundY() {return boundY;}

		void setVelX(float velX) {GameObject::velX = velX;}
		void setVelY(float velY) {GameObject::velY = velY;}

		int getVelX() {return velX;}
		int getVelY() {return velY;}

		int getID() {return mID;}
		void setID(int ID) {GameObject::mID = ID;}

		bool getAlive() {return mIsAlive;}
		void setAlive(bool alive) {GameObject::mIsAlive = alive;}

		bool getCollideable() {return mIsCollidable;}
		void setCollideable(bool collideable) {GameObject::mIsCollidable = collideable;}

		int getDirection() {return Direction;}
		void setDirection(int newDirection) {GameObject::Direction = newDirection;}

		void resetAnimation(int position);

		int getCurFrame() {return curFrame;}
		void setcurFrame(int newFrame) {curFrame = newFrame;}

		bool checkCollisions(GameObject *OtherObject);
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
		int animationRow;

		int mTotalHeight;
		int mTotalWidth;

		int Direction;

		ALLEGRO_BITMAP *image;
private:
		//ID of the Game Object
		int mID;
		//Check to see if the object is alive
		bool mIsAlive;
		//Check to see if the object is collideable
		bool mIsCollidable;

};