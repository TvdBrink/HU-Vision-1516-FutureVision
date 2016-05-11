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


Histogram::Histogram(const IntensityImage & intensityImage, int relativeLeftX, int relativeRightX, int relativeUpperY, int relativeLowerY, Axis axis)
{
	int actualHeight = intensityImage.getHeight();
	int actualWidth = intensityImage.getWidth();
	int calculatedHeight = (actualHeight - relativeUpperY - relativeLowerY);
	int calculatedWidth = (actualWidth  - relativeRightX - relativeLeftX);
	if (calculatedHeight > 0 && calculatedWidth > 0) {
		int totalPixels = calculatedHeight * calculatedWidth;
		if (axis == Axis::x) {
			histogram.resize(calculatedWidth);
			for (int u = 0; u <= calculatedHeight; ++u) {
				for (int i = 0; i < calculatedWidth; ++i) {
					histogram[i] += (int)intensityImage.getPixel(i + relativeLeftX + ((relativeUpperY + u) * actualWidth)) < 127 ? 1 : 0;
				}
			}
		}
		else if (axis == Axis::y) {
			histogram.resize(calculatedHeight);
			for (int i = 0; i <= calculatedHeight; ++i) {
				for (int u = 0; u < calculatedWidth; ++u) {
					histogram[i] += (int)intensityImage.getPixel(u + (i * actualWidth)) < 127 ? 1 : 0;
				}
			}
		}
	}
	else {
		std::cout << "Given image dimensions are smaller than 1." << std::endl;
	}
}

Histogram::~Histogram()
{
}

std::vector<int> Histogram::getHistogramData() {
	return histogram;
}

int Histogram::getValue(int index)
{
	return histogram[index];
}

int Histogram::getSize()
{
		return histogram.size();
}
