#include "Test.h"
#include "RGBImageStudent.h"
#include "RGBImagePrivate.h"
#include "IntensityImageStudent.h"
#include "LuminosityAlgorithm.h"
#include "Timer.h"
#include "ImageIO.h"
#include "ImageFactory.h"
#include "ConvolutionAlgorithm.h"

#include <iostream>


Test::Test()
{
}


Test::~Test()
{
}

void Test::ImageShellTest()
{
	std::cout << "Start ImageShellTest" << std::endl;

	IntensityImageStudent privateImage;
	RGBImageStudent studentImage;
	ImageIO::loadImage("..\\..\\..\\testsets\\Set A\\TestSet Images\\female-3.png", studentImage);

	privateImage.set(studentImage.getWidth(), studentImage.getHeight());
	LuminosityAlgorithm la;
	la.doAlgorithm(studentImage, privateImage);

	Timer t;
	std::cout << "setPixel();" << std::endl;
	t.Start();
	for (int i = 0; i < 10000; i++)
		privateImage.setPixel(0, Intensity(255));
	std::cout << "Private: " << t.GetTimePassed() << " ms" << std::endl;
	t.Restart();
	for (int i = 0; i < 10000; i++)
		studentImage.setPixel(0, RGB(255, 255, 255));
	std::cout << "Student: " << t.GetTimePassed() << " ms" << std::endl;

	std::cout << "getPixel();" << std::endl;
	t.Restart();
	for (int i = 0; i < 10000; i++)
		privateImage.getPixel(0);
	std::cout << "Private: " << t.GetTimePassed() << " ms" << std::endl;
	t.Restart();
	for (int i = 0; i < 10000; i++)
		studentImage.getPixel(0);
	std::cout << "Student: " << t.GetTimePassed() << " ms" << std::endl;

	std::cout << "copy constructor" << std::endl;
	t.Restart();
	for (int i = 0; i < 100; i++)
		IntensityImageStudent copy(privateImage);
	std::cout << "Private: " << t.GetTimePassed() << " ms" << std::endl;
	t.Restart();
	for (int i = 0; i < 100; i++)
		RGBImageStudent copy(studentImage);

	RGBImageStudent copy(studentImage);
	std::cout << "Student: " << t.GetTimePassed() << " ms" << std::endl;
}

void Test::ConvolutionTest()
{

	RGBImage* rgbImage = ImageFactory::newRGBImage();
	IntensityImage* intensityImage = ImageFactory::newIntensityImage();
	
	ImageIO::loadImage("..\\..\\..\\testsets\\Set A\\TestSet Images\\female-3.png", *rgbImage);
	LuminosityAlgorithm la;
	la.doAlgorithm(*rgbImage, *intensityImage);

	IntensityImage* outputImage = ImageFactory::newIntensityImage();
	outputImage->set(intensityImage->getWidth(), intensityImage->getHeight());
	ConvolutionAlgorithm meanAlgorithm(Kernel::meanKernel, 9);
	meanAlgorithm.doAlgorithm(*intensityImage, *outputImage);

	ImageIO::showImage(*intensityImage);
	ImageIO::showImage(*outputImage);
}
