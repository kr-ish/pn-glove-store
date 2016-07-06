// br.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "br.h"
#include <conio.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Load required libraries
#ifdef _WIN64
#pragma comment(lib, "C:/Users/KR/Documents/Visual Studio 2015/Projects/RM/br/br/x64/NeuronDataReader.lib")//Add Lib
#elif defined _WIN32 
#pragma comment(lib, "C:/Users/KR/Documents/Visual Studio 2015/Projects/RM/br/br/x86/NeuronDataReader.lib")//Add Lib
#pragma comment(lib,"ws2_32.lib")
#endif

#pragma comment(lib, "dynamixel.lib")

using namespace std;

static const std::string SERVER_ADDRESS = "localhost"; //should use 'localhost' since Axis Neuron has to be run first
static const int SERVER_PORT = 7001; //default port for TCP Axis Neuron server and again should use this as default.

static void frameDataReceived(void * customObject, SOCKET_REF sockRef, BvhDataHeader * header, float * data)
{
	BVH_Collector *self = reinterpret_cast<BVH_Collector*>(customObject);
	self->showBvhBoneInfo(sockRef, header, data);
}

// ????
BVH_Collector::BVH_Collector(){
	//sockTCPRef = NULL;
	//sockUDPRef = NULL;
	BRRegisterFrameDataCallback(this, FrameDataReceived(frameDataReceived));
}

BVH_Collector::~BVH_Collector() {
	BRCloseSocket(mSocketRef);
}

void BVH_Collector::testConnection()
{

	BRCloseSocket(mSocketRef);

	mSocketRef = BRConnectTo((char*)SERVER_ADDRESS.c_str(), SERVER_PORT);

	if (mSocketRef) {
		cout << "connected";
	}
	else {
		cout << "disconnected";
	}

	SocketStatus status = BRGetSocketStatus(mSocketRef);
	cout << "status" << status;
}

void BVH_Collector::showBvhBoneInfo(SOCKET_REF sender, BvhDataHeader* header, float* data)
{
	cout << "showBVHBoneInfo";
	int dataIndex = 0;
    /** The number 15 is right fore arm // Ref:: Appendix A: Skeleton Data Sequence in Array From "Neuron Data Reader Runtime API Documentation" */
    int currentBoneNumber = 15;
    if (header->WithDisp)
    {
        dataIndex = currentBoneNumber * 6;
        if (header->WithReference)
        {
            dataIndex += 6;
        }

        float angleX = data[dataIndex + 4];
        float angleY = data[dataIndex + 3];
        float angleZ = data[dataIndex + 5];

        cout << "Angle X" << angleX << ", Angle Y" << angleY << ", Angle Z" << angleZ;
    }
}

int main() {
	cout << "start";
	//BVH_Collector* b = new BVH_Collector();
	//new BVH_Collector b;
	//b.testConnection();
	//delete b;
	//cin.get();

	BVH_Collector b;

	//while (!_kbhit()) {
		b.testConnection();
		cout << "testing";
		cout << "\n";
		cin.get();
	//}

	BRCloseSocket(b.mSocketRef);
	return 0;
}

/*int main()
{
	ofstream myFile;
	myFile.open("example.csv");
	BVH_Collector b;
	// connect TCP
	b.mSocketRef = BRConnectTo("127.0.0.1", 7005);

	if (b.mSocketRef) {
		//		//print("Successfully connected via TCP");
		cout << "Successfully connected via TCP";
	}
	else {
		//print("TCP connection failed");
		cout << "TCP connection failed";
	}

	/*	// connect UDP
		b.sockUDPRef = BRStartUDPServiceAt(7001);

		if (b.sockUDPRef) {
			//print("Successfully connected via UDP");
			cout << "Successfully connected via UDP";
		}
		else {
			//print("UDP connection failed");
			cout << "UDP connection failed";
		}
	*/


	// close TCP socket
//	BRCloseSocket(b.sockTCPRef);

	// close UDP socket
//	BRCloseSocket(b.sockUDPRef);

/*	while (!_kbhit()) {
	SocketStatus status = BRGetSocketStatus(b.mSocketRef);
	cout << "status" << status << "\n";
	
	}
	//cin.get();
	BRCloseSocket(b.mSocketRef);
	myFile.close();
	//return 0;
}*/

/*void __stdcall BVH_Collector::bvhFrameDataReceived(void* customedObj, SOCKET_REF sender, BvhDataHeader* header, float* data) {
	BVH_Collector* pthis = (BVH_Collector*)customedObj;
	//pthis->showBvhBoneInfo(sender, header, data);
}*/

//void __stdcall BVH_Collector::showBvhBoneInfo(SOCKET_REF sender, BvhDataHeader* header, float* data) {
	//myFile << data[37 + 4];
//	myFile << ",";

	/*
	char strBvhData[64];
	sprintf_s(strBvhData, "%0.3f\t", dispX);
	sprintf_s(strBvhData, "%0.3f\t", dispY);
	sprintf_s(strBvhData, "%0.3f\t", dispZ);

	sprintf_s(strBvhData, "%0.3f\t", angX);
	sprintf_s(strBvhData, "%0.3f\t", angY);
	sprintf_s(strBvhData, "%0.3f\t", angZ);
	*/

//}
