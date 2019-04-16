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

void LF_CC LicenceRenewCallback(uint32_t status)
{
	switch (status)
	{
	case LF_OK:
		printf("The license lease has renewed successfully.\n");
		break;
	case LF_E_LICENSE_NOT_FOUND:
		printf("The license expired before it could be renewed.\n");
		break;
	case LF_E_LICENSE_EXPIRED_INET:
		printf("The license expired due to network connection failure.\n");
		break;
	default:
		printf("The license renew failed due to other reason. Error code: %d\n", status);
		break;
	}
}

int main(int argc, char *argv[])
{
	int status;
#if _WIN32
	status = SetHostProductId(L"PASTE_PRODUCT_ID");
#else
	status = SetHostProductId("PASTE_PRODUCT_ID");
#endif
	if (LF_OK != status)
	{
		printf("Error code: %d", status);
		getchar();
		return status;
	}

#if _WIN32
	status = SetHostUrl(L"http://localhost:8090");
#else
	status = SetHostUrl("http://localhost:8090");
#endif
	if (LF_OK != status)
	{
		printf("Error code: %d", status);
		getchar();
		return status;
	}

	status = SetFloatingLicenseCallback(LicenceRenewCallback);
	if (LF_OK != status)
	{
		printf("Error code: %d", status);
		getchar();
		return status;
	}

	status = RequestFloatingLicense();
	if (LF_OK != status)
	{
		printf("Request license error code: %d", status);
		getchar();
		return status;
	}
	printf("Success! License acquired.\n");

	printf("Press enter to get license metadata ...\n");
	getchar();

#if _WIN32
	wchar_t buffer[256];
	status = GetHostLicenseMetadata(handle, L"key1", buffer, 256);
#else
	char buffer[256];
	status = GetHostLicenseMetadata("key1", buffer, 256);
#endif

	if (LF_OK == status)
	{
		printf("Metadata: %s\n", buffer);
	}
	else
	{
		printf("Error getting metadata: %d\n", status);
	}

	printf("Press enter to drop the license ...\n");
	getchar();

	status = DropFloatingLicense();
	if (LF_OK != status)
	{
		printf("Dropping license error code: %d", status);
		getchar();
		return status;
	}
	printf("Success! License dropped.\n");
	getchar();
	return 0;
}
