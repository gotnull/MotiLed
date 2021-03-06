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

#ifndef LEKA_MOTI_CLASS_LED_H_
#define LEKA_MOTI_CLASS_LED_H_

/**
 * @file MotiLed.h
 * @author Ladislas de Toldi
 * @version 1.0
 */

#include <application.h>
#include "MotiColor.h"

/**
 * @class MotiLed
 * @brief MotiLed library gathers all the MotiLed functions for Moti.
 */

class MotiLed {
	public:
		MotiLed();
		MotiLed(uint8_t redPin, uint8_t greenPin, uint8_t bluePin);
		MotiLed(uint8_t redPin, uint8_t greenPin, uint8_t bluePin, MotiColor colorValue);

		void shine(void);
		void shine(MotiColor colorValue);
		void shine(uint8_t redValue, uint8_t greeValue, uint8_t blueValue);

		void turnOff(void);

		MotiColor getColor(void);
		void setColor(MotiColor colorValue);

	protected:
		uint8_t _redPin, _greenPin, _bluePin;
		MotiColor _colorValue;
};

#endif
