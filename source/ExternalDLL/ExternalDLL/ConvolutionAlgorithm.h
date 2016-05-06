#pragma once
#include "Algorithm.h"
#include "IntensityImage.h"
#include "Kernel.h"

class ConvolutionAlgorithm : public Algorithm<IntensityImage, IntensityImage>
{
private:
	Kernel kernel;
	int divisionFactor;
public:
	ConvolutionAlgorithm(const Kernel& kernal, const int divisionFactor);
	~ConvolutionAlgorithm();

	void doAlgorithm(const IntensityImage& input, IntensityImage& output);
};

