#include "RGBImageVector.h"

#include <iterator>

RGBImageVector::RGBImageVector() : RGBImage()
{

}

RGBImageVector::RGBImageVector(const RGBImageVector &other) :
	RGBImage(other.getWidth(), other.getHeight())
{
	std::copy(other.pixels.begin(), other.pixels.end(), std::back_inserter(pixels));
}


RGBImageVector::RGBImageVector(const int width, const int height) :
	RGBImage(width, height)
{
	set(width, height);
}

RGBImageVector::~RGBImageVector()
{

}

void RGBImageVector::set(const int width, const int height)
{
	RGBImage::set(width, height);

	pixels.resize(width*height);
}

void RGBImageVector::set(const RGBImageVector &other)
{
	RGBImage::set(other.getWidth(), other.getHeight());

	set(other.getWidth(), other.getHeight());
}

void RGBImageVector::setPixel(int x, int y, RGB pixel)
{
	pixels[x + y * getWidth()] = pixel;
}

void RGBImageVector::setPixel(int i, RGB pixel)
{
	pixels[i] = pixel;
}

RGB RGBImageVector::getPixel(int x, int y) const
{
	return pixels[x + y * getWidth()];
}

RGB RGBImageVector::getPixel(int i) const
{
	return pixels[i];
}