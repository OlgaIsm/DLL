#pragma once

#ifdef DLLLibrary_EXPORTS
#define DLLLibrary_API __declspec(dllexport)
#else
#define DLLLibrary_API __declspec(dllimport)
#endif

#include <iostream>
#include <windows.h>
#include <Winioctl.h>
#include <wchar.h>
#include <algorithm>
#include <stdio.h>

#pragma pack(1)
typedef struct
{
	BYTE jumpCode[3];
	BYTE oemID[8];
	WORD bytesPerSector;
	BYTE sectorPerCluster;
	WORD reservedSectors;
	BYTE always0[3];
	WORD notUsed;
	BYTE mediaDiscr;
	WORD always02;
	WORD sectorperTrack;
	WORD numOfHeaders;
	DWORD hiddenSectors;
	DWORD notUsed2;
	DWORD notused3;
	ULONGLONG totalSectors;
	ULONGLONG lcnForSMFT;
	ULONGLONG lcnForSMFTMirr;
	DWORD clusterPerFileRecordSegm;
	BYTE clusterPerIndexBuff;
	BYTE notUsed4[3];
	ULONGLONG volumeSerialNumber;
	DWORD checksum;
	BYTE bootstrap[426];
	WORD endMarker;
} NTFS_BootRecord;
#pragma pack()

extern "C++" DLLLibrary_API void PrintBootSectInfo(NTFS_BootRecord _bpb);
extern "C++" DLLLibrary_API std::string FindFSName(std::string diskName);
extern "C++" DLLLibrary_API bool fsIsSupported(std::string SysName);
extern "C++" DLLLibrary_API bool getFsInfo(std::string diskNameFormated, NTFS_BootRecord* _bpb);