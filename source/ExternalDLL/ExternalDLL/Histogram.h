#pragma once
#include <vector>
#include "IntensityImage.h"
class Histogram
{
public:
	Histogram(const IntensityImage & intensityImage);
	Histogram(const IntensityImage & intensityImage, int relativeLeftX, int relativeRightX, int relativeUpperY, int relativeLowerY);
	~Histogram();

	std::vector<int> getHistogramData();

private:
	std::vector<int> histogram;
};
