#include "Test.h"
#include "RGBImageStudent.h"
#include "RGBImagePrivate.h"
#include "IntensityImageStudent.h"
#include "Timer.h"
#include "ImageIO.h"

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

	RGBImagePrivate privateImage;
	RGBImageStudent studentImage;
	ImageIO::loadImage("C:\\Users\\Jeroen\\Documents\\GitHub\\HU-Vision-1516-FutureVision\\testsets\\Set A\\TestSet Images\\female-3.png", privateImage);
	ImageIO::loadImage("C:\\Users\\Jeroen\\Documents\\GitHub\\HU-Vision-1516-FutureVision\\testsets\\Set A\\TestSet Images\\female-3.png", studentImage);

	Timer t;
	std::cout << "setPixel();" << std::endl;
	t.Start();
	for (int i = 0; i < 10000; i++)
		privateImage.setPixel(0, RGB(255, 255, 255));
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
		RGBImagePrivate copy(privateImage);
	std::cout << "Private: " << t.GetTimePassed() << " ms" << std::endl;
	t.Restart();
	for (int i = 0; i < 100; i++)
		RGBImageStudent copy(studentImage);

	RGBImageStudent copy(studentImage);
	std::cout << "Student: " << t.GetTimePassed() << " ms" << std::endl;
}
