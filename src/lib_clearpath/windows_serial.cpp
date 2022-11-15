 /**
 *      _____
 *     /  _  \
 *    / _/ \  \
 *   / / \_/   \
 *  /  \_/  _   \  ___  _    ___   ___   ____   ____   ___   _____  _   _
 *  \  / \_/ \  / /  _\| |  | __| / _ \ | ++ \ | ++ \ / _ \ |_   _|| | | |
 *   \ \_/ \_/ /  | |  | |  | ++ | |_| || ++ / | ++_/| |_| |  | |  | +-+ |
 *    \  \_/  /   | |_ | |_ | ++ |  _  || |\ \ | |   |  _  |  | |  | +-+ |
 *     \_____/    \___/|___||___||_| |_||_| \_\|_|   |_| |_|  |_|  |_| |_|
 *             ROBOTICS™ 
 *
 *  File: windows_serial.cpp
 *  Desc: Windows-compatible serial commands for linking with generic functions
 *        defined in serial.h 
 *  Auth: R. Gariepy
 *
 *  Copyright (c) 2010, Clearpath Robotics, Inc. 
 *  All Rights Reserved
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Clearpath Robotics, Inc. nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL CLEARPATH ROBOTICS, INC. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * Please send comments, questions, or patches to skynet@clearpathrobotics.com 
 *
 */

#if !defined(WINDOWS_SERIAL_H) && defined(win_x86)
#define WINDOWS_SERIAL_H

#include "serial.h"
#include <windows.h>

#include "stdio.h"

int OpenSerial(void** handle, const char* port_name)
{
	*handle = (HANDLE*)malloc(sizeof(HANDLE));
	if (NULL == *handle) {
		printf("Handle cannot be allocated\r\n");
		return -1;
	}
	**(HANDLE**)handle = CreateFile(port_name, GENERIC_READ | GENERIC_WRITE, 0, 0,
				OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	if (INVALID_HANDLE_VALUE == **(HANDLE**)handle) {
		if (GetLastError() == ERROR_FILE_NOT_FOUND) {
			printf("Serial port not found\r\n");
			return -2;
		}
		printf("Other error in port opening\r\n");
		return -3;
	}
	return 0;
}

int SetupSerial(void* handle)
{
	/* Set serial port parameters */
	DCB dcbSerialParams = {0};
	dcbSerialParams.DCBlength=sizeof(dcbSerialParams);
	if (!GetCommState(*(HANDLE*)handle, &dcbSerialParams)) {
		printf("Error getting port state\r\n");
		return -1;
	}
	dcbSerialParams.BaudRate=CBR_115200;
	dcbSerialParams.ByteSize=8;
	dcbSerialParams.StopBits=ONESTOPBIT;
	dcbSerialParams.Parity=NOPARITY;
	if(!SetCommState(*(HANDLE*)handle, &dcbSerialParams)){
		printf("Error setting port state\r\n");
		return -2;
	}

	/* Set timeouts */
	COMMTIMEOUTS timeouts={0};
	timeouts.ReadIntervalTimeout=0;
	timeouts.ReadTotalTimeoutConstant=5;
	timeouts.ReadTotalTimeoutMultiplier=0;
	timeouts.WriteTotalTimeoutConstant=00;
	timeouts.WriteTotalTimeoutMultiplier=10;
	if(!SetCommTimeouts(*(HANDLE*)handle, &timeouts)){
		printf("Error setting port timeouts\r\n");
		return -3;
	}
	return 0;
}

int WriteData(void* handle, const char* buffer, int length)
{
	DWORD bytesWritten = 0;
	if(!WriteFile(*(HANDLE*)handle, buffer, length, &bytesWritten, NULL)){
		printf("Error in serial write\r\n");
		return -1;
	}

	// serial port output monitor
#ifdef TX_DEBUG
	printf("TX: ");
	int i;
	for (i=0; i<length; ++i) {
        printf("%X ", (unsigned char)buffer[i]);
    }
    printf("\n\r");
#endif

	return bytesWritten;
}

int ReadData(void* handle, char* buffer, int length)
{
	DWORD bytesRead = 0;
	if(!ReadFile(*(HANDLE*)handle, buffer, length, &bytesRead, NULL)){
		printf("Error in serial read\r\n");
		return -1;
	}

    if (bytesRead <= 0)
        return 0;

	// serial port input monitor
#ifdef RX_DEBUG
	printf("RX: ");
	unsigned int i;
	for (i=0; i<bytesRead; ++i) {
        printf("%X ", (unsigned char)buffer[i]);
    }
	printf("\n\r");
#endif

	return bytesRead;
}

int CloseSerial(void* handle)
{
	if (NULL == handle)
		return 0;
	CloseHandle(*(HANDLE*)handle);
	free(handle);
	return 0;
}


#endif // WINDOWS_SERIAL

