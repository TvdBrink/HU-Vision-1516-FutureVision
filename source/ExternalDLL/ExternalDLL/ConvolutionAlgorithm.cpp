#include "ConvolutionAlgorithm.h"

#include "IntensityImage.h"
#include "ImageFactory.h"


ConvolutionAlgorithm::ConvolutionAlgorithm(const Kernel& kernel, const int divisionFactor) :
	kernel(kernel),
	divisionFactor(divisionFactor)
{
}


ConvolutionAlgorithm::~ConvolutionAlgorithm()
{
}

void ConvolutionAlgorithm::doAlgorithm(const IntensityImage& input, IntensityImage& output)
{
	// Check image size
	if (input.getWidth() != output.getWidth() || input.getHeight() != output.getHeight()) {
		output.set(input.getWidth(), input.getHeight());
	}

	int kernelPadding = (int)(kernel.getWidth() / 2.0);

	// Set border to black
	for (int x = 0; x < output.getWidth(); x++) {
		if (x == 0 || x == output.getWidth() - 1) {
			for (int y = 0; y < output.getHeight(); y++) {
				output.setPixel(x, y, 0);
			}
		}
		else {
			output.setPixel(x, 0, 0);
			output.setPixel(x, output.getHeight()-1, 0);
		}
	}

	// Convolve kernel
	for (int x = kernelPadding; x < (input.getWidth() - (kernelPadding)); x++) {
		for (int y = kernelPadding; y < (input.getHeight() - (kernelPadding)); y++) {
			int tmp = 0;
			for (int kx = 0; kx < kernel.getWidth(); kx++) {
				for (int ky = 0; ky < kernel.getHeight(); ky++) {
					int add = (input.getPixel(x + kx - kernelPadding, y + ky - kernelPadding) * kernel.get(kx, ky));
					tmp += add;
				}
			}
			tmp /= divisionFactor;
			tmp = tmp < 0 ? 0 : tmp;
			tmp = tmp > 255 ? 255 : tmp;
			output.setPixel(x, y, tmp);
		}
	}
}