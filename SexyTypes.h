#pragma once
#include <cstdint>
#include <string>

typedef std::string SexyString;

typedef uint8_t byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

struct SexyVector3
{
	float mX, mY, mZ;

	SexyVector3(float x, float y, float z)
	{
		mX = x;
		mY = y;
		mZ = z;
	}
};

struct Rect
{
	int mX, mY, mWidth, mHeight;
};