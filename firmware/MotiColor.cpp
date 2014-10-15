/*
   Copyright (C) 2013-2014 Ladislas de Toldi <ladislas at weareleka dot com> and Leka <http://weareleka.com>

   This file is part of Moti, a spherical robotic smart toy for autistic children.

   Moti is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Moti is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Moti. If not, see <http://www.gnu.org/licenses/>.
   */

/**
 * @file MotiColor.cpp
 * @author Ladislas de Toldi
 * @version 1.0
 */

#include "MotiColor.h"
#include <math.h>
 
/*
 * @brief Default constructor, sets R, G, B to be equal to 0
 */
MotiColor::MotiColor() {
	_r = _g = _b = 0;
}

/*
 * @brief R, G, B constructor (0-255)
 * @param r the red intensity of the color
 * @param g the green intensity of the color
 * @param b the blue intensity of the color
 */
MotiColor::MotiColor(uint8_t r, uint8_t g, uint8_t b) {
	_r = r;
	_g = g;
	_b = b;
}


/**
 * @brief Reads the RGB values (0-255)
 * @param r pointer that will receive the content of the red intensity
 * @param g pointer that will receive the content of the green intensity
 * @param b pointer that will receive the content of the blue intensity
 */
void MotiColor::getRGB(uint8_t* r, uint8_t* g, uint8_t* b) {
	*r = _r;
	*g = _g;
	*b = _b;
}

/**
 * @brief Getter method to get the red intensity of the color (0-255)
 * @return the red intensity
 */
uint8_t MotiColor::getR(void) {
	return _r;
}

/**
 * @brief Getter method to get the green intensity of the color (0-255)
 * @return the green intensity
 */
uint8_t MotiColor::getG(void) {
	return _g;
}

/**
 * @brief Getter method to get the blue intensity of the color (0-255)
 * @return the blue intensity
 */
uint8_t MotiColor::getB(void) {
	return _b;
}

/**
 * @brief Reads the HSV values
 * @param hue pointer that will receive the content of the hue
 * @param saturation pointer that will receive the content of the saturation
 * @param value pointer that will receive the content of the value
 */
void MotiColor::getHSV(uint16_t* hue, float* saturation, float* value) {
	*hue = _hue;
	*saturation = _saturation;
	*value = _value;
}

/**
 * @brief Getter method to get the hue of the color
 * @return the hue
 */
uint16_t MotiColor::getHue(void) {
	return _hue;
}

/**
 * @brief Getter method to get the saturation of the color
 * @return the saturation
 */
float MotiColor::getSaturation(void) {
	return _saturation;
}

/**
 * @brief Getter method to get the value of the color
 * @return the value
 */
float MotiColor::getValue(void) {
	return _value;
}


double __mod(double a, double b) {
	double r = fmod(a, b);

	return r < 0.f ? r + b : r;
}

/**
 * @brief Setter method to set the red, green and blue intensities of the color (0-255)
 * @param r the new red intensity of the color
 * @param g the new green intensity of the color
 * @param b the new blue intensity of the color
 */
void MotiColor::setRGB(uint8_t r, uint8_t g, uint8_t b) {
	float new_r = (float)r / 255.f;
	float new_g = (float)g / 255.f;
	float new_b = (float)b / 255.f;

	float c_max = max(new_r, max(new_g, new_b));
	float c_min = min(new_r, min(new_g, new_b));

	float delta = c_max - c_min;

	if (c_max == new_r)
		_hue = (uint16_t)(60.f * __mod((new_g - new_b) / delta, 6.f));
	else if (c_max == new_g)
		_hue = (uint16_t)(60.f * (((new_b - new_r) / delta) + 2.f));
	else
		_hue = (uint16_t)(60.f * (((new_r - new_g) / delta) + 4.f));

	if (c_max == c_min)
		_saturation = 0.f;
	else
		_saturation = delta / c_max;

	_value = c_max;

	_r = r;
	_g = g;
	_b = b;
}

/**
 * @brief Setter method to set the hue, saturation and value of the color (See http://en.wikipedia.org/wiki/HSL_and_HSV#Converting_to_RGB)
 * @param hue the new hue of the color
 * @param b the new saturation of the color
 * @param g the new value of the color
 */
void MotiColor::setHSV(uint16_t hue, float saturation, float value) {
	float c = value * saturation;

	uint16_t h = hue / 60;

	float x = c * (1.f - abs((float)(h % 2) - 1.f));
	float int_c = c;

	float r = 0.f;
	float g = 0.f;
	float b = 0.f;

	switch (h) {
		case 0:
			r = int_c;
			g = x;
			break;

		case 1:
			r = x;
			g = int_c;
			break;

		case 2:
			g = c;
			b = x;
			break;

		case 3:
			g = x;
			b = c;
			break;

		case 4:
			r = x;
			b = c;
			break;

		case 5:
			r = c;
			b = x;
			break;
	}

	float m = value - c;

	_r = (uint8_t)(r + m);
	_g = (uint8_t)(g + m);
	_b = (uint8_t)(b + m);

	_hue = hue;
	_saturation = saturation;
	_value = value;
}

/**
 * @brief Returns a random color
 * @return the color
 */
MotiColor MotiColor::randomColor(void) {
	return MotiColor(random(0, 255), random(0, 255), random(0, 255));
}

/**
 * @brief Set basic color values
 */
const MotiColor MotiColor::Black = MotiColor(0, 0, 0);
const MotiColor MotiColor::White = MotiColor(255, 255, 255);
const MotiColor MotiColor::RedPure = MotiColor(255, 0, 0);
const MotiColor MotiColor::GreenPure = MotiColor(0, 255, 0);
const MotiColor MotiColor::BluePure = MotiColor(0, 0, 255);
const MotiColor MotiColor::DarkRed = MotiColor(186, 48, 42);
const MotiColor MotiColor::LightRed = MotiColor(222, 63, 89);
const MotiColor MotiColor::Purple = MotiColor(165, 67, 188);
const MotiColor MotiColor::LightBlue = MotiColor(95, 184, 224);
const MotiColor MotiColor::LightPink = MotiColor(255, 232, 225);
const MotiColor MotiColor::Yellow = MotiColor(250, 211, 51);
const MotiColor MotiColor::DarkYellow = MotiColor(244, 174, 51);
const MotiColor MotiColor::Orange = MotiColor(240, 143, 51);
const MotiColor MotiColor::DarkOrange = MotiColor(239, 134, 59);
const MotiColor MotiColor::LightGreen = MotiColor(216, 255, 56);
