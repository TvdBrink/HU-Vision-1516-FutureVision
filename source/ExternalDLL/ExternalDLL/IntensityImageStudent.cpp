#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() :
	IntensityImage()
{

}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) :
	IntensityImage(other.getWidth(), other.getHeight()),
	pixels(new Intensity(*other.pixels)) // deep copy
{

}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) :
	IntensityImage(width, height),
	pixels(new Intensity[width*height])
{

}

IntensityImageStudent::~IntensityImageStudent()
{
	if (pixels != nullptr)
		delete[] pixels;
}

void IntensityImageStudent::set(const int width, const int height)
{
	if (this->getWidth() == width && this->getHeight() == height)
		return; // Width and height are the same. No need for resizing.

	IntensityImage::set(width, height);
	
	if(pixels != nullptr)
		delete[] pixels;
	pixels = new Intensity[width*height];
}

void IntensityImageStudent::set(const IntensityImageStudent &other)
{
	if (this->getWidth() == other.getWidth() && this->getHeight() == other.getHeight())
		return; // Width and height are the same. No need for resizing.

	IntensityImage::set(other.getWidth(), other.getHeight());

	if (pixels != nullptr)
		delete[] pixels;
	pixels = new Intensity(*other.pixels); // deep copy
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel)
{
	if(pixels != nullptr)
		pixels[x + y * getWidth()] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel)
{
	if (pixels != nullptr)
		pixels[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const
{
	if (pixels != nullptr)
		return pixels[x + y * getWidth()];
	return -1;
}

Intensity IntensityImageStudent::getPixel(int i) const
{
	if (pixels != nullptr)
		return pixels[i];
	return -1;
}