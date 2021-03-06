// Copyright (C) XFX Team
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
// 
//     * Redistributions of source code must retain the above copyright 
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright 
//       notice, this list of conditions and the following disclaimer in the 
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the copyright holder nor the names of any 
//       contributors may be used to endorse or promote products derived from 
//       this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
// POSSIBILITY OF SUCH DAMAGE.

extern "C"
{
#include <xboxkrnl/xboxkrnl.h>
}

#include <xmem.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#undef __STRICT_ANSI__
#include <string.h>

#include <Storage/StorageContainer.h>
#include <Storage/StorageDevice.h>

namespace XFX
{
	namespace Storage
	{
		typedef struct
		{
			char cDriveLetter;
			char const * const szDevice;
			int iPartition;
		}
		stDriveMapping;

		stDriveMapping driveMapping[] =
		{
			{ 'C', "Harddisk0\\Partition2", 2},
			{ 'D', "Cdrom0", -1},
			{ 'E', "Harddisk0\\Partition1", 1},
			{ 'X', "Harddisk0\\Partition3", 3},
			{ 'Y', "Harddisk0\\Partition4", 4},
			{ 'Z', "Harddisk0\\Partition5", 5},
		};
		char extendPartitionMapping[] = { 'F','G','R','S','V','W','A','B' };

#define NUM_OF_DRIVES (sizeof(driveMapping) / sizeof(driveMapping[0]))
#define EXTEND_PARTITION_BEGIN  6

		void GetDrive(const char* szPartition, char* cDriveLetter)
		{
			size_t part_str_len = strlen(szPartition);
			int part_num;

			if (part_str_len < 19)
			{
				*cDriveLetter = 0;
				return;
			}

			part_num = atoi(szPartition + 19);

			if (part_num >= EXTEND_PARTITION_BEGIN)
			{
				*cDriveLetter = extendPartitionMapping[part_num - EXTEND_PARTITION_BEGIN];
				return;
			}

			for (unsigned int i = 0; i < NUM_OF_DRIVES; i++)
			{
				if (strnicmp(driveMapping[i].szDevice, szPartition, strlen(driveMapping[i].szDevice)) == 0)
				{
					*cDriveLetter = driveMapping[i].cDriveLetter;
					return;
				}
			}

			*cDriveLetter = 0;
		}

		StorageDevice* StorageContainer::getStorageDevice() const
		{
			return device;
		}

		bool StorageContainer::IsDisposed() const
		{
			return isDisposed;
		}

		StorageContainer::~StorageContainer()
		{
			Dispose(false);
		}

		void StorageContainer::Delete()
		{
			containerFolder.Delete(true);
		}

		void StorageContainer::Dispose()
		{
			Dispose(true);
		}

		void StorageContainer::Dispose(bool disposing)
		{
			if (!isDisposed)
			{
				isDisposed = true;

				if (disposing)
				{
					Disposing(this, EventArgs::Empty);
				}
			}
		}

		const String StorageContainer::Path() const
		{
			// Calculate the path to this storage location
		}

		const String StorageContainer::TitleLocation()
		{
			// XBOX returns the XeImageFileName like \device\harddisk0\partition2\apps\default.xbe
			// we need to map the partitions, and strip the \default.xbe from this string

			// copy the XeImageFileName to tmp, and strip the \default.xbe
			//char *tmp = strncpy(tmp, XeImageFileName->Buffer, XeImageFileName->Length - 12);
	
			char* szTemp = new char[256];
			char cDriveLetter = 0;
			char* szDest;

			strncpy(szTemp, XeImageFileName->Buffer + 12, XeImageFileName->Length - 12);
			szTemp[20] = 0;
			GetDrive(szTemp, &cDriveLetter);
	
			strncpy(szTemp, XeImageFileName->Buffer + 29, XeImageFileName->Length - 29);
			szTemp[XeImageFileName->Length - 29] = 0;

			sprintf(szDest, "%c:\\%s", cDriveLetter, szTemp);

			delete szTemp;

			return szDest;
		}

		const String StorageContainer::TitleName() const
		{
			FILE* file = fopen(XeImageFileName->Buffer, "rb");
			char* titleName = new char[0x50];
			uint32_t CertAddr = 0;
			fseek(file, 0x118, SEEK_SET);
			fread(&CertAddr, 4, 1, file);

			fseek(file, CertAddr - 0x10000, SEEK_SET);
			fread(titleName, 0x50, 1, file);

			// TODO: free C-string somehow

			fclose(file);

			return titleName;
		}
	}
}
