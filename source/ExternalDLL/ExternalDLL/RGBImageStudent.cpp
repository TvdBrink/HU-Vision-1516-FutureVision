#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() :
	RGBImage()
{

}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : 
	RGBImage(other.getWidth(), other.getHeight()),
	pixels(new RGB(*other.pixels)) // deep copy the pointer
{

}


RGBImageStudent::RGBImageStudent(const int width, const int height) :
	RGBImage(width, height),
	pixels(new RGB[width*height])
{

}

RGBImageStudent::~RGBImageStudent()
{
	if (pixels != nullptr)
		delete[] pixels;
}

void RGBImageStudent::set(const int width, const int height)
{
	RGBImage::set(width, height);

	if(pixels != nullptr)
		delete[] pixels;
	pixels = new RGB[width*height];
}

void RGBImageStudent::set(const RGBImageStudent &other)
{
	RGBImage::set(other.getWidth(), other.getHeight());

	if (pixels != nullptr)
		delete[] pixels;
	pixels = new RGB(*other.pixels);
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel)
{
	pixels[x + y * getWidth()] = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel)
{
	if (pixels != nullptr)
		pixels[i] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const
{
	// TODO: add checks
	return pixels[x + y * getWidth()];
}

RGB RGBImageStudent::getPixel(int i) const
{
	// TODO: add checks
	return pixels[i];
}