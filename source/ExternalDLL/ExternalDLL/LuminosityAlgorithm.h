#pragma once
#include "Algorithm.h"
#include "RGBImage.h"
#include "IntensityImage.h"

class LuminosityAlgorithm : public Algorithm<RGBImage, IntensityImage>
{
public:
	LuminosityAlgorithm();
	~LuminosityAlgorithm();

	void doAlgorithm(const RGBImage& input, IntensityImage& output);
};

