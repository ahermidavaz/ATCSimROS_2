/*
 * Common.h
 *
 *  Created on: 04/2022
 *
 *
 *  Copyright 2022 Alberto Hermida
 *
 *  This file is part of ATCSimROS_2.
 *
 *  ATCSimROS_2 is free software based on the ATCsim project , created for a
 *	final project of the Aerospace Engineering at URJC (Madrid).
 *	Author: Alberto Hermida Vazquez (ahermidavazquez@gmail.com)
 *	Tutor: Jose Miguel Guerrero
 *  Author of ATCsim project: Francisco Martin
 * 
 *  ATCSim is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 */


#ifndef SRC_LIB_COMMON_H_
#define SRC_LIB_COMMON_H_

#include <stdlib.h>
#include <cmath>
#include <cstdlib>
#include <string>

#define DIMENSION_FACTOR 0.2288f

#define COLLISION_DISTANCE 200.0f
#define CRASH_Z 20.0f
#define CRASH_INC 45.0f//[TODO]
#define CRASH_SPEED_MAX 300.0f  // Approx. 950 km/h
#define CRASH_SPEED 50.0f
#define INIT_MAX_FLIGHTS 1

#define MAX_FLIFGT_W  0.2f  // 12 grados/sec
#define DIST_POINT 200.0  // 15 grados/sec
#define MAX_ACELERATION 100.0  // 3 m/sec2


#define AIRPORT_DISTANCE_MAX 7500.0f
#define FLIGHT_HEIGHT 1500.0f
#define LANDING_STRIP_L 750.0f
#define LANDING_STRIP_W 80.0f

#define STORM_MAX_RAD 5000.0f
#define STORM_MIN_RAD 2000.0f
#define STORM_MAX_HEIGHT 2000.0f
#define STORM_MIN_HEIGHT 500.0f
#define STORM_MAX_ELEVATION 2000.0f
#define STORM_MIN_ELEVATION 500.0f
#define STORM_MAX_SPEED 500.0f
#define STORM_MIN_SPEED 30.0f


// Conditions for landing	

#define LANDING_POS_X 0.0f
#define LANDING_POS_Y 0.0f
#define LANDING_POS_Z 25.0f

// Lowest airport in the word is at -1240 ft
// and lowest land zone in Earth is -3904 ft
#define MIN_AIRPORT_ALT -4000.0f
#define MAINTAIN_ALT MIN_AIRPORT_ALT


#define LANDING_SPEED 100.0f
#define LANDING_BEAR -180.0f
#define LANDING_BEAR_MAX_ERROR 20.0f
#define LANDING_DIST 50.0f

#define INIT_FLIGHT_POINTS 2000
#define INIT_POINTS 0
#define LANDING_POINTS (10)
#define COLLISION_POINTS (-50)
#define CRASH_HEIGHT_POINTS (-25)
#define CRASH_INC_POINTS (-25)
#define CRASH_SPEED_POINTS (-25)

#define INC_DIFF 30000000  // 30 sec
#define INC_PEN 1  // fligts/inc

#define INC_SIMTIME 0.1
#define HANDLING_TIME 20  //20 sec

#define dimension_factor 1.58
#define A320_size 34.1*dimension_factor
#define A380_size 80*dimension_factor


inline double sec(const double a) {return 1/cos(a);}

inline double cosec(const double a) {return 1/sin(a);}

/** @name constants for some often used angles */
///@{
/** constant for a half circle*/
const double pi = M_PI;
/** constant for a full circle*/
const double pi2 = 2.0 * pi;
/** constant for three quater circle*/
const double pi3_2 = 1.5 * pi;
/** constant for a quarter circle*/
const double pi_2 = 0.5 * pi;
/** constant for a 1 degree*/
const double pi_180 = pi / 180;
/** constant for a 1/8 circle*/
const double pi_4 = pi * 0.25;
/** constant for a 3/8 circle*/
const double pi3_4 = pi * 0.75;
/** constant for an expression used by the gaussian function*/
const double sqrt2pi = sqrt(2.0*pi);
/** constant to convert from m/s to knots*/
const double ms2kt = 1.94384;
/** constant to convert from knots to m/s*/
const double kt2ms = 1 / ms2kt;     // 0.51444
/** constant to convert from meters to feet*/
const double m2ft = 3.28084;
/** constant to convert from feet to meters*/
const double ft2m = 1 / m2ft;       // 0.3048
/** constant to convert from meters to nautical miles*/
const double m2nm = 0.000539957;
/** constant to convert from nautical miles to meters*/
const double nm2m = 1852;
///@}


/**
 * Converts angle from rad to degrees.
 * \param angle code in rad
 * \return angle coded in degrees
 */
inline double toDegrees(double angle) {return angle * (180.0 / pi);}

/** Converts angle from degrees to rad.
 * \param degrees angle coded in degrees
 * \return angle coded in rad
 */

inline double toRadians(double degrees) {return degrees * pi_180;}

/**
* reduce angle to [-pi..+pi[
* \param data angle coded in rad
* \return normalized angle coded in rad
*/

inline double normalizePi(double data) {
  if (data < pi && data >= -pi) return data;
  double ndata = data - ((int )(data / pi2))*pi2;
  while (ndata >= pi) {
  	//std::cerr<<"1";
    ndata -= pi2;
  }

  while (ndata < -pi) {
  	//std::cerr<<"2";
    ndata += pi2;
  }

  return ndata;
}

/**
* The function returns a random number in the range of [0..1].
* @return The random number.
*/
inline double randomDouble() {return static_cast<double>(rand())/RAND_MAX;}

/**
* The function returns a random integer number in the range of [0..n-1].
* @param n the number of possible return values (0 ... n-1)
* @return The random number.
*/
inline int random(int n) {return static_cast<int>(randomDouble()*n*0.999999);}

/** constant, cast before execution*/
const double RAND_MAX_DOUBLE = static_cast<double>(RAND_MAX);

/**
* The function returns a random integer number in the range of [0..n].
* @param n the number of possible return values (0 ... n)
* @return The random number.
*/
inline int randomFast(int n) {
  return static_cast<int>((rand() * n) / RAND_MAX_DOUBLE);
}

/**
* Round to the next integer
* @param d A number
* @return The number as integer
*/
inline int roundNumberToInt(double d) {return static_cast<int> (round(d));}

/**
* Round to the next integer but keep type
* @param d A number
* @return The number
*/
inline double roundNumber(double d) {return round(d);}

inline float normalAng(float x, float mu, float st) {
  float diff = normalizePi(x-mu);
  float d1 = st*sqrt(2.0*pi);
  float d2 = 2*st*st;

  if (d1 == 0.0) d1 = 0.00001;
  if (d2 == 0.0) d2 = 0.00001;

	return (1.0/d1) * exp(-(diff * diff)/d2);
}

inline float normalDist(float x, float mu, float st) {
	float diff = x-mu;
	float d1 = st*sqrt(2.0*pi);
	float d2 = 2*st*st;

  if (d1 == 0.0) d1 = 0.00001;
	if (d2 == 0.0) d2 = 0.00001;

	return (1.0/d1)*exp(-(diff*diff)/d2);
}

/*
// you can write i.e.  3.5km is equal to 3500 m
constexpr long double operator"" km ( long double km )
{
    return km*1000;
}

// you can write i.e.  3.5mi is equal to 56327 m
constexpr long double operator"" mi ( long double mi )
{
    return mi*1609.34;
}
*/

#endif // __Math_Common_h__

//#endif  // SRC_LIB_COMMON_H_
