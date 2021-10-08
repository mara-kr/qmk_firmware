/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// #define USE_I2C
#define EE_HANDS
#define MOUSEKEY_WHEEL_TIME_TO_MAX 0 // Time until maximum scroll speed is reached
#define MOUSEKEY_WHEEL_DELAY 100     // Delay between pressing a wheel key and wheel movement
#define MOUSEKEY_WHEEL_INTERVAL 50   // Time between wheel movements
#define MOUSEKEY_WHEEL_MAX_SPEED 8   // Maximum number of scroll steps per action

#define RGBLIGHT_SLEEP // Turn off lights when host sleeps
#define RGBLIGHT_SPLIT // Enable split board lighting
