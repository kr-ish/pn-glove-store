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
	~BVH_Collector() {
		myFile.close();
	};

	enum
	{
		BVHBoneCount = 59,
		CalcBoneCount = 21,
	};

	protected:
		// Receive Data
		static void __stdcall bvhFrameDataReceived(void* customedObj, SOCKET_REF sender, BvhDataHeader* header, float* data);

// Implementation
protected:
	SOCKET_REF sockTCPRef;
	SOCKET_REF sockUDPRef;

	void showBvhBoneINfo(SOCKET_REF sender, BvhDataHeader* header, float* data);
}