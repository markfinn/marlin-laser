/*
  temperature.h - temperature controller
  Part of Marlin

  Copyright (c) 2011 Erik van der Zalm

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef temperature_h
#define temperature_h 

#include "Marlin.h"
#include "planner.h"
#ifdef PID_ADD_EXTRUSION_RATE
  #include "stepper.h"
#endif

// public functions
void tp_init();  //initialise the heating
void manage_heater(); //it is critical that this is called periodically.

// low level conversion routines
// do not use these routines and variables outside of temperature.cpp
extern int target_temperature[EXTRUDERS];  
extern float current_temperature[EXTRUDERS];
extern int target_temperature_bed;
extern float current_temperature_bed;

//high level conversion routines, for use outside of temperature.cpp
//inline so that there is no performance decrease.
//deg=degreeCelsius

FORCE_INLINE float degHotend(uint8_t extruder) {  
  return current_temperature[extruder];
};

FORCE_INLINE float degBed() {
  return current_temperature_bed;
};

FORCE_INLINE float degTargetHotend(uint8_t extruder) {  
  return target_temperature[extruder];
};

FORCE_INLINE float degTargetBed() {   
  return target_temperature_bed;
};

FORCE_INLINE void setTargetHotend(const float &celsius, uint8_t extruder) {  
  target_temperature[extruder] = celsius;
};

FORCE_INLINE void setTargetBed(const float &celsius) {  
  target_temperature_bed = celsius;
};

FORCE_INLINE bool isHeatingHotend(uint8_t extruder){  
  return target_temperature[extruder] > current_temperature[extruder];
};

FORCE_INLINE bool isHeatingBed() {
  return target_temperature_bed > current_temperature_bed;
};

FORCE_INLINE bool isCoolingHotend(uint8_t extruder) {  
  return target_temperature[extruder] < current_temperature[extruder];
};

FORCE_INLINE bool isCoolingBed() {
  return target_temperature_bed < current_temperature_bed;
};

#define degHotend0() degHotend(0)
#define degTargetHotend0() degTargetHotend(0)
#define setTargetHotend0(_celsius) setTargetHotend((_celsius), 0)
#define isHeatingHotend0() isHeatingHotend(0)
#define isCoolingHotend0() isCoolingHotend(0)
#define setTargetHotend1(_celsius) do{}while(0)
#define setTargetHotend2(_celsius) do{}while(0)



int getHeaterPower(int heater);
void disable_heater();
void setWatch();
void updatePID();

void PID_autotune(float temp, int extruder, int ncycles);

#endif

