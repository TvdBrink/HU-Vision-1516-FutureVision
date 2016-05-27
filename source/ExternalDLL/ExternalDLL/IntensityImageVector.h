#pragma once
#include <vector>

#include "IntensityImage.h"

class IntensityImageVector : public IntensityImage {
public:
	IntensityImageVector();
	IntensityImageVector(const IntensityImageVector &other);
	IntensityImageVector(const int width, const int height);
	~IntensityImageVector();

	void set(const int width, const int height);
	void set(const IntensityImageVector &other);

	void setPixel(int x, int y, Intensity pixel);
	void setPixel(int i, Intensity pixel);

	Intensity getPixel(int x, int y) const;
	Intensity getPixel(int i) const;
private:
	std::vector<Intensity> pixels;
};

