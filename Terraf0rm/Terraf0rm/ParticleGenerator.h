#pragma once

/***************************************
* Particle Generator for all Particles *
***************************************/

#include "GameObject.h"

class ParticleGenerator : public GameObject
{
public:
		ParticleGenerator();

		int getSize() {return mSize;}
		void setSize(int newSize) {mSize = newSize;}
		int getWidth() {return mWidth;}
		void setWidth(int newWidth) {mWidth = newWidth;}
		int getLength() {return mLength;}
		void setLength(int newLength) {mLength = newLength;}
		int getSpeed() {return mSpeed;}
		void setSpeed(int newSpeed) {mSpeed = newSpeed;}
		int getNumParticles() {return mNumParticles;}
		void setNumParticles(int newNumParticles) {mNumParticles = newNumParticles;}
		
		int getRed() {return mRed;}
		void setRed(int newRed) {mRed = newRed;}
		int getGreen() {return mGreen;}
		void setGreen(int newGreen) {mGreen = newGreen;}
		int getBlue() {return mBlue;}
		void setBlue(int newBlue) {mBlue = newBlue;}

		void Update();
		void Render();
		void Collided(int objectID);

		~ParticleGenerator();

protected:
		int mSize;
		int mLength;
		int mWidth;
		int mSpeed;
		int mNumParticles;

		int mRed;
		int mGreen;
		int mBlue;
		int mFrameSmoother;
};
