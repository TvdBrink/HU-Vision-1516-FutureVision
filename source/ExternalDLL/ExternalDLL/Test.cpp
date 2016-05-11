#include "Test.h"
#include "RGBImageStudent.h"
#include "RGBImagePrivate.h"
#include "IntensityImageStudent.h"
#include "LuminosityAlgorithm.h"
#include "Timer.h"
#include "ImageIO.h"
#include "ImageFactory.h"
#include "LuminosityAlgorithm.h"
#include "Histogram.h"
#include "ConvolutionAlgorithm.h"

#include <iostream>
#include <vector>
#include <fstream>


Test::Test()
{
}


Test::~Test()
{
}

void Test::HistogramTest()
{
	RGBImageStudent input;
	if (!ImageIO::loadImage("..\\..\\..\\testsets\\Set A\\TestSet Images\\female-1.png", input)) {
		std::cout << "Image could not be loaded!" << std::endl;
		system("pause");
	}
	LuminosityAlgorithm la;
	IntensityImageStudent intesityImage(input.getWidth(), input.getHeight());
	la.doAlgorithm(input, intesityImage);

	Histogram hi(intesityImage);
	
	std::ofstream myfile;
	myfile.open("..\\..\\histogram-female_1.csv");	

	std::vector<int> hiData = hi.getHistogramData();
	for (unsigned int i = 0; i < hiData.size(); ++i) {
		myfile << i << ", " << hiData[i] << std::endl;
		std::cout << i << ", " << hiData[i] << std::endl;
	}

	myfile.close();

	///

	if (!ImageIO::loadImage("..\\..\\..\\testsets\\Set A\\TestSet Images\\female-2.png", input)) {
		std::cout << "Image could not be loaded!" << std::endl;
		system("pause");
	}

	IntensityImageStudent intesityImage1(input.getWidth(), input.getHeight());
	la.doAlgorithm(input, intesityImage1);

	Histogram hi1(intesityImage1);

	myfile.open("..\\..\\histogram-female_2.csv");

	hiData = hi1.getHistogramData();
	for (unsigned int i = 0; i < hiData.size(); ++i) {
		myfile << i << ", " << hiData[i] << std::endl;
		std::cout << i << ", " << hiData[i] << std::endl;
	}

	myfile.close();

	///

	if (!ImageIO::loadImage("..\\..\\..\\debug\\Pre-processing-4.png", input)) {
		std::cout << "Image could not be loaded!" << std::endl;
		system("pause");
	}

	IntensityImageStudent intesityImage2(input.getWidth(), input.getHeight());
	la.doAlgorithm(input, intesityImage2);

	Histogram hi2(intesityImage2, 50, 50, 95, intesityImage.getHeight() - 135);

	myfile.open("..\\..\\histogram-female_3.csv");

	hiData = hi2.getHistogramData();
	for (unsigned int i = 0; i < hiData.size(); ++i) {
		myfile << i << ", " << hiData[i] << std::endl;
		std::cout << i << ", " << hiData[i] << std::endl;
	}

	myfile.close();
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
