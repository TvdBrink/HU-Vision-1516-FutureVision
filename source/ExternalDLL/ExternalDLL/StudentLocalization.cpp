#include "StudentLocalization.h"

#include <fstream>

bool StudentLocalization::stepFindHead(const IntensityImage &image, FeatureMap &features) const {
	Histogram AxisY(image, 50, 50, 0, 0, Axis::y);
	
	//determine top of the head

	int topHead = -1;

	for (int i = 0; i < AxisY.getSize(); ++i) {
		if (AxisY.getValue(i) > 2) {
			topHead = i;
			break;
		}
	}
	if (topHead == -1) {
		return false;
	}
	
	//determine sides

	int lastLeftX = -1;
	int lastRightX = -1;
	for (int y = topHead; y < image.getHeight(); y += 20) {
		Histogram layerX(image, 0, 0, y, (image.getHeight() - y - 20), Axis::x);
		
		//determine leftside of the head
		int leftX = -1;
		for (int i = 0; i < layerX.getSize(); ++i) {
			if (layerX.getValue(i) > 2) {
				leftX = i;
				break;
			}
		}

		//determine rightside of the head
		int rightX = -1;
		for (int i = layerX.getSize() - 1; i >= 0 ; --i) {
			if (layerX.getValue(i) > 2) {
				rightX = i;
				break;
			}
		}
		
		// if not both sides are found skip the rest of the loop
		if (leftX == -1 || rightX == -1) {
			continue;
		}

		int currentHeadWidth = rightX - leftX;
		int lastHeadWidth = lastRightX - lastLeftX;

		if (currentHeadWidth < lastHeadWidth) {
			Feature * headUpperBound = new Feature(Feature::FEATURE_HEAD_TOP, Point2D<double>(lastRightX - (currentHeadWidth / 2), topHead));
			Feature * headLeftBound = new Feature(Feature::FEATURE_HEAD_LEFT_SIDE, Point2D<double>(lastLeftX, y));
			Feature * headRightBound = new Feature(Feature::FEATURE_HEAD_RIGHT_SIDE, Point2D<double>(lastRightX, y));

			features.putFeature(*headUpperBound);
			features.putFeature(*headLeftBound);
			features.putFeature(*headRightBound);
					
			return true;
		}

		lastLeftX = leftX;
		lastRightX = rightX;
	}
	
	return false;
}

bool StudentLocalization::stepFindNoseMouthAndChin(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindChinContours(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindNoseEndsAndEyes(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindExactEyes(const IntensityImage &image, FeatureMap &features) const {
	return false;
}