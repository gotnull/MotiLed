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
 * @file MotiLed.cpp
 * @author Ladislas de Toldi
 * @version 1.0
 */

#include <Arduino.h>
#include "MotiLed.h"

/**
 * @brief Default constructor
 */
MotiLed::MotiLed() {
	_colorValue = Color(0, 0, 0);
}

/**
 * @brief Instantiates a new MotiLed, given its red, green and blue pins
 * @param redPin the red pin
 * @param greenPin the green pin
 * @param bluePin the blue pin
 */
MotiLed::MotiLed(uint8_t redPin, uint8_t greenPin, uint8_t bluePin) {
	_redPin = redPin;
	_greenPin = greenPin;
	_bluePin = bluePin;

	_colorValue = Color(0, 0, 0);
}

/**
 * @brief Instantiates a new MotiLed, given its red, green and blue pins and a starting color
 * @param redPin the red pin
 * @param greenPin the green pin
 * @param bluePin the blue pin
 * @param color the start color
 */
MotiLed::MotiLed(uint8_t redPin, uint8_t greenPin, uint8_t bluePin, Color colorValue) {
	MotiLed(redPin, greenPin, bluePin);
	_colorValue = colorValue;
}

/**
 * @brief Tells the MotiLed to shine with its color
 */
void MotiLed::shine(void) {
	analogWrite(_redPin, _colorValue.getR());
	analogWrite(_greenPin, _colorValue.getG());
	analogWrite(_bluePin, _colorValue.getB());
}

/**
 * @brief Tells the MotiLed to shine with a given color
 * @param color the color the MotiLed will shine
 */
void MotiLed::shine(Color colorValue) {
	setColor(colorValue);
	shine();
}

/**
 * @brief Tells the MotiLed to shine with a given color
 * @param color the color the MotiLed will shine
 */
void MotiLed::shine(uint8_t redValue, uint8_t greeValue, uint8_t blueValue) {
	setColor(Color(redValue, greeValue, blueValue));
	shine();
}

/**
 * @brief Tells the MotiLed to stop shining
 */
void MotiLed::turnOff(void) {
	setColor(Color(0, 0, 0));
	shine();
}

/**
 * @brief Getter method to get the color of the MotiLed
 */
Color MotiLed::getColor(void) {
	return _colorValue;
}

/**
 * @brief Setter method to set the color of the MotiLed
 * @param color the new color of the MotiLed
 */
void MotiLed::setColor(Color colorValue) {
	_colorValue = colorValue;
}