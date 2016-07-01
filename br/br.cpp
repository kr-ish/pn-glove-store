// br.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "br.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Load required libraries
#ifdef _WIN64
#pragma comment(lib, "/x64/NeuronDataReader.lib")//Add Lib
#elif defined _WIN32 
#pragma comment(lib, "C:/Users/KR/Documents/Visual Studio 2015/Projects/RM/br/br/x86")//Add Lib
#pragma comment(lib,"ws2_32.lib")
#endif

#pragma comment(lib, "dynamixel.lib")

using namespace std;

// ????
BVH_Collector::BVH_Collector(){
	sockTCPRef = NULL;
	sockUDPRef = NULL;
}



int main()
{	
	ofstream myFile;
	myFile.open("example.csv");
	BVH_Collector b;
	// connect TCP
	b.sockTCPRef = BRConnectTo("127.0.0.1", 7005);

	if (b.sockTCPRef) {
		//print("Successfully connected via TCP");
		cout << "Successfully connected via TCP";
	}
	else {
		//print("TCP connection failed");
		cout << "TCP connection failed";
	}

	// connect UDP
	b.sockUDPRef = BRStartUDPServiceAt(7001);

	if (b.sockUDPRef) {
		//print("Successfully connected via UDP");
		cout << "Successfully connected via UDP";
	}
	else {
		//print("UDP connection failed");
		cout << "UDP connection failed";
	}

	BRRegisterFrameDataCallback(this, b.bvhFrameDataReceived);

	// close TCP socket
	BRCloseSocket(b.sockTCPRef);

	// close UDP socket
	BRCloseSocket(b.sockUDPRef);
	myFile.close();
	//return 0;
}

void __stdcall BVH_Collector::bvhFrameDataReceived(void* customedObj, SOCKET_REF sender, BvhDataHeader* header, float* data) {
	//BVH_Collector* pthis = (BVHCollect*)customedObj;
	//pthis->showBvhBoneInfo(sender, header, data);
}

/*void __stdcall BVH_Collector::showBvhBoneInfo(SOCKET_REF sender, BvhDataHeader* header, float* data) {
	myFile << data[37 + 4];
	myFile << ",";
*/
	/*
	char strBvhData[64];
	sprintf_s(strBvhData, "%0.3f\t", dispX);
	sprintf_s(strBvhData, "%0.3f\t", dispY);
	sprintf_s(strBvhData, "%0.3f\t", dispZ);

	sprintf_s(strBvhData, "%0.3f\t", angX);
	sprintf_s(strBvhData, "%0.3f\t", angY);
	sprintf_s(strBvhData, "%0.3f\t", angZ);
	*/

/*}*/
