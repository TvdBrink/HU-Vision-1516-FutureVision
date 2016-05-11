#pragma once
#include <vector>
#include "IntensityImage.h"

enum class Axis {
	x, y
};

class Histogram
{
public:
	Histogram(const IntensityImage & intensityImage);
	Histogram(const IntensityImage & intensityImage, int relativeLeftX, int relativeRightX, int relativeUpperY, int relativeLowerY, Axis axis = Axis::x);
	~Histogram();

	std::vector<int> getHistogramData();
	int getValue(int index);
	int getSize();

private:
	std::vector<int> histogram;
};
