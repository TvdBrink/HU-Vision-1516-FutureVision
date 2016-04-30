#pragma once
#include <vector>
#include "IntensityImage.h"
class Histogram
{
public:
	//Histogram();
	Histogram(const IntensityImage & intensityImage);
	Histogram(const IntensityImage & intensityImage, int relativeLeftX, int relativeRightX, int relativeUpperY, int relativeLowerY);
	//Histogram(const IntensityImage & intensityImage, int relativeUpperY, int relativeLowerY);
	~Histogram();

	std::vector<int> & getHistogramData();

	//std::vector<int> getIntesityHistogram(const IntensityImage & intensityImage);
	//std::vector<int> getYAxisHistogram(const IntensityImage & intensityImage, int relativeLeftX, int relativeRightX);
	//std::vector<int> getXAxisHistogram(const IntensityImage & intensityImage, int relativeUpperY, int relativeLowerY);
	
private:
	std::vector<int> histogram;
};
