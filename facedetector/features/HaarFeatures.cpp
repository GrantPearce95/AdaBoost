/*
 * HaarFeature.cpp
 *
 *  Created on: 05/apr/2016
 *      Author: lorenzocioni
 */

#include "HaarFeatures.h"

/**
 * Extracting haar like feature from an image
 * integralImage: the integral image
 * size: the detection window size
 * r: row offset
 * c: column offset
 */
vector<double> HaarFeatures::extractFeatures(Mat integralImage, int size, int r, int c) {

	vector<double> features;
	int count = 0;
	double white, black;
	int x, y, sizeX, sizeY, width, height;

	/**
	 * Extracting feature type (2 x 1)
	 */
	sizeX = 2;
	sizeY = 1;
	for (width = sizeX; width <= size; width += sizeX) {
		for (height = sizeY; height <= size; height += sizeY) {
			for (x = 0; x <= size - width; ++x) {
				for (y = 0; y <= size - height; ++y) {
					white = IntegralImage::computeArea(integralImage, Rect(x + c, y + r, width / 2, height));
					black = IntegralImage::computeArea(integralImage, Rect(x + c + width / 2, y + r, width / 2, height));
					features.push_back((double) (white - black));
					count++;
				}
			}
		}
	}
	/**
	 * Extracting feature type (1 x 2)
	 */
	sizeX = 1;
	sizeY = 2;
	for (width = sizeX; width <= size; width += sizeX) {
		for (height = sizeY; height <= size; height += sizeY) {
			for (x = 0; x <= size - width; ++x) {
				for (y = 0; y <= size - height; ++y) {
					white = IntegralImage::computeArea(integralImage, Rect(x + c, y + r, width, height / 2));
					black = IntegralImage::computeArea(integralImage, Rect(x + c, y + r + height / 2, width, height / 2));
					features.push_back((double) (white - black));
					count++;
				}
			}
		}
	}
	/**
	 * Extracting feature type (3 x 1)
	 */
	sizeX = 3;
	sizeY = 1;
	for (width = sizeX; width <= size; width += sizeX) {
		for (height = sizeY; height <= size; height += sizeY) {
			for (x = 0; x <= size - width; ++x) {
				for (y = 0; y <= size - height; ++y) {
					white = IntegralImage::computeArea(integralImage, Rect(x + c, y + r, width / 3, height));
					black = IntegralImage::computeArea(integralImage, Rect(x + c + width / 3, y + r, width / 3, height));
					white += IntegralImage::computeArea(integralImage, Rect(x + c + 2 * width / 3, y + r, width / 3, height));
					features.push_back((double) (white - black));
					count++;
				}
			}
		}
	}
	/**
	 * Extracting feature type (1 x 3)
	 */
	sizeX = 1;
	sizeY = 3;
	for (width = sizeX; width <= size; width += sizeX) {
		for (height = sizeY; height <= size; height += sizeY) {
			for (x = 0; x <= size - width; ++x) {
				for (y = 0; y <= size - height; ++y) {
					white = IntegralImage::computeArea(integralImage, Rect(x + c, y + r, width, height / 3));
					black = IntegralImage::computeArea(integralImage, Rect(x + c, y + r + height / 3, width, height / 3));
					white += IntegralImage::computeArea(integralImage, Rect(x + c, y + r + 2 * height / 3, width, height / 3));
					features.push_back((double) (white - black));
					count++;
				}
			}
		}
	}
	/**
	 * Extracting feature type (2 x 2)
	 */
	sizeX = 2;
	sizeY = 2;
	for (width = sizeX; width <= size; width += sizeX) {
		for (height = sizeY; height <= size; height += sizeY) {
			for (x = 0; x <= size - width; ++x) {
				for (y = 0; y <= size - height; ++y) {
					white = IntegralImage::computeArea(integralImage, Rect(x + c, y + r, width / 2, height / 2));
					black = IntegralImage::computeArea(integralImage, Rect(x + c + width / 2, y + r, width / 2, height / 2));
					white += IntegralImage::computeArea(integralImage, Rect(x + c + width / 2, y + r + height / 2, width / 2, height / 2));
					black += IntegralImage::computeArea(integralImage, Rect(x + c, y + r + height / 2, width / 2, height / 2));
					features.push_back((double) (white - black));
					count++;
				}
			}
		}
	}

	return features;
}
