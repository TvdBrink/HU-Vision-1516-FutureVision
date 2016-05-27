#include "IntensityImageVector.h"

#include <iterator>

IntensityImageVector::IntensityImageVector() : IntensityImage()
{

}

IntensityImageVector::IntensityImageVector(const IntensityImageVector &other) :
	IntensityImage(other.getWidth(), other.getHeight())
{
	std::copy(other.pixels.begin(), other.pixels.end(), std::back_inserter(pixels));
}

IntensityImageVector::IntensityImageVector(const int width, const int height) :
	IntensityImage(width, height)
{
	set(width, height);
}

IntensityImageVector::~IntensityImageVector()
{

}

void IntensityImageVector::set(const int width, const int height)
{
	IntensityImage::set(width, height);

	pixels.resize(width*height);
}

void IntensityImageVector::set(const IntensityImageVector &other)
{
	IntensityImage::set(other.getWidth(), other.getHeight());
	
	set(other.getWidth(), other.getHeight());
}

void IntensityImageVector::setPixel(int x, int y, Intensity pixel)
{
	pixels[x + y * getWidth()] = pixel;
}

void IntensityImageVector::setPixel(int i, Intensity pixel)
{
	pixels[i] = pixel;
}

Intensity IntensityImageVector::getPixel(int x, int y) const
{
	return pixels[x + y * getWidth()];
}

Intensity IntensityImageVector::getPixel(int i) const
{
	return pixels[i];
}