/*
 * STARE_Covers_test.cpp
 *
 *  Created on: Feb 20, 2020
 *      Author: mrilee
 *
 *  Copyright (C) 2020 Rilee Systems Technologies LLC
 */


#include <iostream>
#include "Test.h"

#include "SpatialInterface.h"



using namespace std;


double lons_lats1[] = {  0.01389, 0.01056 ,0.00278, 0.00278 ,0.01333, 0.01111 ,0.00333, 0.0025 ,0.01222, 0.00083 ,0.00472, 0.01084,
                            0.00417, 0.01167 ,0.00972, 0.00028 ,0.00166, 0.00389 ,0.00333, 0.00278 ,0.00361, 0.00222 ,0.00055, 0.00806, 
                            0.01056, 0.00028 ,0.01528, 0.00778 ,0.01416, 0.00333 ,0.00222, 0.00306 ,0.00472, 0.00167 ,0.00472, 0.00195, 
                            0.00444, 0.01 ,0.01555, 0.00556 ,0.01416, 0.01028 ,0.01389, 0.0025 ,0.015, 0.00445 ,0.00278, 0.00306 ,
                            0.01444, 0.00333 ,0.01528, 0.005 ,0.00194, 0.00889 ,0.01361, 0.0025, 0.01472, 0.00361 ,0.00139, 0.00389,
                            0.00055, 0.00556 ,0.0025, 0.00917 ,0.00528, 0.00139 ,0.01583, 0.00583 ,0.00917, 0.00056 ,0.00833, 0.00056 ,0.0025, 0.00945,
                            0.01056, 0.0 ,0.01305, 0.01111 ,0.01278, 0.00139 ,0.01111, 0.00056 ,0.01528, 0.00861 ,0.01528, 0.00445 ,
                            0.01583, 0.00667 ,0.01139, 0.00056 ,0.00417, 0.01195 ,0.00917, 0.00028 ,0.00111, 0.00861 ,0.01361, 0.01084 , 
                            0.00389, 0.01111 ,0.01472, 0.00417 ,0.01333, 0.00167 ,0.00333, 0.00972,0.00528, 0.00167 ,0.01611, 0.00667,
                            0.00083, 0.00806,0.00194, 0.00917 ,0.00444, 0.00972 ,0.01444, 0.00945 ,0.00027, 0.00778,0.01389, 0.01028, 0.015, 0.00917,
                            0.01416, 0.00306 ,0.00333, 0.00945 ,0.01278, 0.01167 ,0.01361, 0.01056 ,0.01472, 0.00945 ,0.00833, 0.00084 ,
                            0.01278, 0.01222 ,0.00055, 0.005,0.00566, 0.00139,0.01444, 0.00972,0.00694, 0.00083,0.01278, 0.00111,0.00444, 0.01084,
                            0.00083, 0.00472,0.01583, 0.00556 ,0.01305, 0.01167 ,0.01555, 0.00778,0.00389, 0.01167,0.00111, 0.00833,0.015, 0.00861,
                            0.015, 0.00417,0.00583, 0.00111,0.00083, 0.005,0.00583, 0.00139,0.00472, 0.01,0.01611, 0.00583,0.01333, 0.00139,
                            0.00166, 0.00889,0.00166, 0.00861,0.01416, 0.00972,0.00055, 0.00778,0.00166, 0.00333,0.01444, 0.00361,
                            0.01555, 0.0075 ,0.00361, 0.0025,0.00972, 0.0,0.0, 0.0075,0.00083, 0.00833,0.00444, 0.01111,0.00027, 0.0075,
                            0.01583, 0.0075,0.00222, 0.00333,0.01139, 0.00084,0.0, 0.00583,0.00027, 0.00583,0.01222, 0.00111,0.01361, 0.00167,
                            0.00139, 0.00472,0.00417, 0.00222,0.00694, 0.00111,0.01333, 0.01084,0.01555, 0.005,0.01389, 0.00306,0.0125, 0.01222,
                            0.00027, 0.00556,0.01111, 0.00028,0.00417, 0.00195,0.01472, 0.00917 };
                            


LatLonDegrees64ValueVector makeCornerVector(double lons_lats[]){
	LatLonDegrees64ValueVector cornerVector;
    for( int i = 0; i < sizeof(lons_lats); i +=2 ) {
	  double lon = lons_lats[i];
	  double lat = lons_lats[i+1];
	  cornerVector.push_back(LatLonDegrees64(lat,lon));
    }
	return cornerVector;
}


void STARE_Covers_test() {
    LatLonDegrees64ValueVector points = makeCornerVector(lons_lats1);    
    int n_test = 80;
    STARE index;
    int   level = 16;
    STARE_SpatialIntervals cover = index.ConvexHull(points, level);
    
    // REGRESSION TEST - NOT YET VALIDATED
   	 long long int cover_[ 45 ] = {
   			  0x3d7e69d220000010
			 ,0x3d7e69d228000010
			 ,0x3d7e69d238000010
			 ,0x3d7e69d288000010
			 ,0x3d7e69d2a0000010
			 ,0x3d7e69d2a8000010
			 ,0x3d7e69d2b0000010
			 ,0x3d7e69d2b8000010
			 ,0x3d7e69d2c0000010
			 ,0x3d7e69d2d0000010
			 ,0x3d7e69d2d8000010
			 ,0x3d7e69d2e0000010
			 ,0x3d7e69d2f0000010
			 ,0x3d7e69d2f8000010
			 ,0x3d7e69d380000010
			 ,0x3d7e69d388000010
			 ,0x3d7e69d390000010
			 ,0x3d7e69d398000010
			 ,0x3d7e69d3c0000010
			 ,0x3d7e69d3c8000010
			 ,0x3d7e69d3d0000010
			 ,0x3d7e69d3d8000010
			 ,0x3d7e69d3e0000010
			 ,0x3d7e69d3e8000010
			 ,0x3d7e69d3f0000010
			 ,0x3d7e69d3f8000010
			 ,0x3d7e69d540000010
			 ,0x3d7e69d548000010
			 ,0x3d7e69d558000010
			 ,0x3d7e69d580000010
			 ,0x3d7e69d590000010
			 ,0x3d7e69d598000010
			 ,0x3d7e69d610000010
			 ,0x3d7e69d620000010
			 ,0x3d7e69d628000010
			 ,0x3d7e69d630000010
			 ,0x3d7e69d638000010
			 ,0x3d7e69d640000010
			 ,0x3d7e69d648000010
			 ,0x3d7e69d650000010
			 ,0x3d7e69d658000010
			 ,0x3d7e69d660000010
			 ,0x3d7e69d668000010
			 ,0x3d7e69d670000010
			 ,0x3d7e69d678000010
   	 };

   	 // cout << "long long int cover_[ " << cover.size() << " ] = {" << endl;
   	 for( int i = 0; i < cover.size(); ++i ) {
   		 // cout << ",0x" << hex << cover[i] << dec << endl;
   		 ASSERT_EQUAL(cover_[i],cover[i]);
   	 }
   	 // cout << "};" << endl;



	// FAIL();
}
