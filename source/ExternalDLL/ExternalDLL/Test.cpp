#include "Test.h"
#include "RGBImageStudent.h"
#include "RGBImagePrivate.h"
#include "RGBImageVector.h"
#include "IntensityImageStudent.h"
#include "IntensityImagePrivate.h"
#include "IntensityImageVector.h"
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

	RGBImagePrivate privateImage;
	ImageIO::loadImage("..\\..\\..\\testsets\\Set A\\TestSet Images\\female-3.png", privateImage);
	IntensityImagePrivate privateIntensityImage(privateImage.getWidth(), privateImage.getHeight());

	RGBImageStudent studentImage;
	ImageIO::loadImage("..\\..\\..\\testsets\\Set A\\TestSet Images\\female-3.png", studentImage);
	IntensityImageStudent studentIntensityImage(studentImage.getWidth(), studentImage.getHeight());

	RGBImageVector vectorImage;
	ImageIO::loadImage("..\\..\\..\\testsets\\Set A\\TestSet Images\\female-3.png", vectorImage);
	IntensityImageVector vectorIntensityImage(vectorImage.getWidth(), vectorImage.getHeight());


	//privateImage.set(studentImage.getWidth(), studentImage.getHeight());
	LuminosityAlgorithm la;
	la.doAlgorithm(privateImage, privateIntensityImage);
	la.doAlgorithm(studentImage, studentIntensityImage);
	la.doAlgorithm(vectorImage, vectorIntensityImage);

	std::ofstream file("..\\intensitytest_setpixel.csv");
	Timer t;
	file << "setPixel();" << std::endl;
	file << "Private, Student, Vector" << std::endl;
	for (int i = 0; i < 100; i++) {
		t.Start();
		for (int i = 0; i < 10000; i++)
			privateIntensityImage.setPixel(0, Intensity(255));
		t.Stop();
		file << t.GetTimePassed(std::micro()) / 10000.0 << ", ";
		t.Restart();
		for (int i = 0; i < 10000; i++)
			studentIntensityImage.setPixel(0, Intensity(255));
		t.Stop();
		file << t.GetTimePassed(std::micro()) / 10000.0 << ", ";
		t.Restart();
		for (int i = 0; i < 10000; i++)
			vectorIntensityImage.setPixel(0, Intensity(255));
		t.Stop();
		file << t.GetTimePassed(std::micro()) / 10000.0 << std::endl;
	}

	file.close();
	file.open("..\\intensitytest_getpixel.csv");
	file << "getPixel();" << std::endl;
	file << "Private, Student, Vector" << std::endl;
	for (int i = 0; i < 100; i++) {
		t.Start();
		for (int i = 0; i < 10000; i++)
			privateIntensityImage.getPixel(0);
		t.Stop();
		file << t.GetTimePassed(std::micro()) / 10000.0 << ", ";
		t.Restart();
		for (int i = 0; i < 10000; i++)
			studentIntensityImage.getPixel(0);
		t.Stop();
		file << t.GetTimePassed(std::micro()) / 10000.0 << ", ";
		t.Restart();
		for (int i = 0; i < 10000; i++)
			vectorIntensityImage.getPixel(0);
		t.Stop();
		file << t.GetTimePassed(std::micro()) / 10000.0 << std::endl;
	}

	file.close();
	file.open("..\\intensitytest_copy.csv");
	file << "copyconstructor();" << std::endl;
	file << "Private, Student, Vector" << std::endl;
	for (int i = 0; i < 100; i++) {
		t.Start();
		for (int i = 0; i < 10; i++)
			IntensityImagePrivate copy(privateIntensityImage);
		t.Stop();
		file << t.GetTimePassed(std::micro()) / 10.0 << ", ";
		t.Restart();
		for (int i = 0; i < 10; i++)
			IntensityImageStudent copy(studentIntensityImage);
		t.Stop();
		file << t.GetTimePassed(std::micro()) / 10.0 << ", ";
		t.Restart();
		for (int i = 0; i < 10; i++)
			IntensityImageVector copy(vectorIntensityImage);
		t.Stop();
		file << t.GetTimePassed(std::micro()) / 10.0 << std::endl;
	}

	file.close();
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
