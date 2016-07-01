#ifndef BR_H_
#define BR_H_
#pragma once

// Include the NeuronDataReader head file
#include "DataType.h"
#include "NeuronDataReader.h"
#include <iostream>
#include <fstream>

class BVH_Collector
{
// Construction
public:
	// contructor
	BVH_Collector();
	// destructor
	~BVH_Collector() 
	{
	//	myFile.close();
	};

/*	enum
	{
		BVHBoneCount = 59,
		CalcBoneCount = 21,
	};
	*/
	//ofstream myFile;

	protected:
		// Receive Data
		static void __stdcall bvhFrameDataReceived(void* customedObj, SOCKET_REF sender, BvhDataHeader* header, float* data);

// Implementation
//protected:
public:
	SOCKET_REF sockTCPRef;
	SOCKET_REF sockUDPRef;

	//void showBvhBoneInfo(SOCKET_REF sender, BvhDataHeader* header, float* data);
};
#endif