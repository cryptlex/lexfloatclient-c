#include <stdio.h>
#include <stdlib.h>
#include "LexFloatClient.h"

#if _WIN32
	#if _WIN64
	#pragma comment(lib,"x64/LexFloatClient")
	#else
	#pragma comment(lib,"x86/LexFloatClient")
	#endif
#endif

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


int main(int argc, char* argv[])
{
	int status;
	uint32_t handle;
    status = SetProductFile(L"Product.dat");
    if(LF_OK != status)
	{
        printf("Error code: %d",status); 
		getchar();
		return status;
    }
    status = GetHandle(L"59A44CE9-5415-8CF3-BD54-EA73A64E9A1B", &handle);
	if(LF_OK != status)
	{
		printf("Error code: %d",status); 
		getchar();
		return status;
	}
    status = SetFloatServer(handle, L"localhost",8090);
	if(LF_OK != status) 
	{
		printf("Error code: %d",status); 
		getchar();
		return status;
	}
	status = SetLicenseCallback(handle, LicenceRefreshCallback);
	if(LF_OK != status)
	{
		printf("Error code: %d",status); 
		getchar();
		return status;
	}
	status = RequestLicense(handle);
	if(LF_OK != status)
	{
		printf("Error code: %d",status); 
		getchar();
		return status;
	}
	printf("Success! License Acquired. Press enter to drop the license ...\n");
	getchar();
	status = DropLicense(handle);
	if(LF_OK != status)
	{
		printf("Error code: %d",status); 
		getchar();
		return status;
	}
	printf("Success! License dropped.\n");
	getchar();
	GlobalCleanUp();
	return 0;
}

