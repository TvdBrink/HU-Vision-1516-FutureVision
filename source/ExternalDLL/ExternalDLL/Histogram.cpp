#include "Histogram.h"

#include <iostream>
#include <cassert>

//Constructor which will create a intensity histogram of the whole image.
Histogram::Histogram(const IntensityImage & intensityImage)
{
	int totalPixels = intensityImage.getHeight() * intensityImage.getWidth();
	histogram.resize(256);
	for (int i = 0; i < totalPixels; ++i) {
		++histogram[intensityImage.getPixel(i)];
	}
}


Histogram::Histogram(const IntensityImage & intensityImage, int relativeLeftX, int relativeRightX, int relativeUpperY, int relativeLowerY)
{
	int actualHeight = intensityImage.getHeight();
	int actualWidth = intensityImage.getWidth();
	int calculatedHeight = (actualHeight - relativeUpperY - relativeLowerY);
	int calculatedWidth = (actualWidth  - relativeRightX - relativeLeftX);
	if (calculatedHeight > 0 && calculatedWidth > 0) {
		int totalPixels = calculatedHeight * calculatedWidth;
		histogram.resize(calculatedWidth);
		for (int u = 0; u <= calculatedHeight; ++u) {
			for (int i = 0; i < calculatedWidth; ++i) {
				histogram[i] += intensityImage.getPixel(i + relativeLeftX + (u * actualWidth));
			}
		}
	}
	else {
		std::cout << "Given image dimentions are smaller than 1." << std::endl;
	}
}

Histogram::~Histogram()
{
}

std::vector<int> & Histogram::getHistogramData() {
	return histogram;
}

/*std::vector<int> Histogram::getIntesityHistogram(const IntensityImage & intensityImage)
{
	int totalPixels = intensityImage.getHeight() * intensityImage.getWidth();
	std::vector<int> histogram;
	histogram.resize(256);
	for (int i = 0; i < totalPixels; ++i) {
		++histogram[intensityImage.getPixel(i)];
	}
	return histogram;
}

std::vector<int> Histogram::getYAxisHistogram(const IntensityImage & intensityImage, int relativeLeftX, int relativeRightX)
{
	std::vector<int> histogram;
	histogram.resize(intensityImage.getHeight());
	return std::vector<int>();
}

std::vector<int> Histogram::getXAxisHistogram(const IntensityImage & intensityImage, int relativeUpperY, int relativeLowerY)
{
	return std::vector<int>();
}*/
