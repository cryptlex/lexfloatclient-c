#include <stdio.h>
#include <stdlib.h>

// Uncomment following for Windows static build
/*
#if _WIN32
#define LEXFLOATCLIENT__STATIC
#pragma comment(lib, "winhttp")
#if _WIN64
#pragma comment(lib, "x64/libcurl_MD")
#pragma comment(lib, "x64/LexFloatClient")
#else
#pragma comment(lib, "x86/libcurl_MD")
#pragma comment(lib, "x86/LexFloatClient")
#endif
#endif
*/

#if _WIN32
#if _WIN64
#pragma comment(lib, "x64/LexFloatClient")
#else
#pragma comment(lib, "x86/LexFloatClient")
#endif
#endif

#include "LexFloatClient.h"

void LF_CC LicenceRefreshCallback(uint32_t status)
{
	switch (status)
	{
	case LF_E_LICENSE_EXPIRED:
		printf("The lease expired before it could be renewed.\n");
		break;
	case LF_E_LICENSE_EXPIRED_INET:
		printf("The lease expired due to network connection failure.\n");
		break;
	case LF_E_SERVER_TIME:
		printf("The lease expired because Server System time was modified.\n");
		break;
	case LF_E_TIME:
		printf("The lease expired because Client System time was modified.\n");
		break;
	default:
		printf("The lease expired due to some other reason.\n");
		break;
	}
}

int main(int argc, char *argv[])
{
	int status;
	uint32_t handle;
#if _WIN32
	status = GetHandle(L"PASTE_PRODUCT_ID", &handle);
#else
	status = GetHandle("PASTE_PRODUCT_ID", &handle);
#endif
	if (LF_OK != status)
	{
		printf("Error code: %d", status);
		getchar();
		return status;
	}
#if _WIN32
	status = SetFloatServer(handle, L"localhost", 8090);
#else
	status = SetFloatServer(handle, "localhost", 8090);
#endif
	if (LF_OK != status)
	{
		printf("Error code: %d", status);
		getchar();
		return status;
	}
	status = SetLicenseCallback(handle, LicenceRefreshCallback);
	if (LF_OK != status)
	{
		printf("Error code: %d", status);
		getchar();
		return status;
	}
	
	status = RequestLicense(handle);
	if (LF_OK != status)
	{
		printf("Request license error code: %d", status);
		getchar();
		return status;
	}
	printf("Success! License Acquired. Press enter to get the license metadata...\n");
	getchar();

#if _WIN32
	wchar_t buffer[256];
	status = GetLicenseMetadata(handle, L"key1", buffer, 256);
#else
	char buffer[256];
	status = GetLicenseMetadata(handle, "key1", buffer, 256);
#endif

	
	if (LF_OK != status)
	{
		printf("Metadata request error code: %d\n", status);
	}	
	else
	{
		printf("Metadata: %s\n", buffer);
	}

	printf("Press enter to drop the license ...\n");
	getchar();
	status = DropLicense(handle);
	if (LF_OK != status)
	{
		printf("Drop license error code: %d", status);
		getchar();
		return status;
	}
	printf("Success! License dropped.\n");
	getchar();
	GlobalCleanUp();
	return 0;
}
