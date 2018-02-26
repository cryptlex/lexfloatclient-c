/* LexFloatClient.h */
#pragma once

#include <stdint.h>
#ifdef _WIN32
    /*
    Make sure you're using the MSVC or Intel compilers on Windows.
    */
    #include <windows.h>

	#ifdef LEXFLOATCLIENT_EXPORTS
		#ifdef LEXFLOATCLIENT__STATIC
            #define LEXFLOATCLIENT_API extern "C"
        #else
            #define LEXFLOATCLIENT_API extern "C" __declspec(dllexport)
        #endif
	#else
		#ifdef __cplusplus
            #ifdef LEXFLOATCLIENT_STATIC
                #define LEXFLOATCLIENT_API extern "C"
            #else
                #define LEXFLOATCLIENT_API extern "C" __declspec(dllimport)
            #endif
        #else
            #ifdef LEXFLOATCLIENT_STATIC
                #define LEXFLOATCLIENT_API
            #else
                #define LEXFLOATCLIENT_API __declspec(dllimport)
            #endif
        #endif
	#endif

    #if defined(USE_STDCALL_DLL) && !defined(LEXFLOATCLIENT_STATIC)
        #define LF_CC __stdcall
    #else
        #define LF_CC __cdecl
    #endif
    typedef const wchar_t* CSTRTYPE;
	typedef wchar_t* STRTYPE;
#else
    #define LF_CC
    typedef int32_t HRESULT;
    #if __GNUC__ >= 4
        #ifdef __cplusplus
            #define LEXFLOATCLIENT_API extern "C" __attribute__((visibility("default")))
        #else
            #define LEXFLOATCLIENT_API __attribute__((visibility("default")))
        #endif
    #else
        #ifdef __cplusplus
            #define LEXFLOATCLIENT_API extern "C"
        #else
            #define LEXFLOATCLIENT_API
        #endif
    #endif
	typedef const char* CSTRTYPE;
	typedef char* STRTYPE;
#endif
typedef void (LF_CC *CallbackType)(uint32_t);

/*
    FUNCTION: SetProductFile()

    PURPOSE: Sets the path of the Product.dat file. This should be
    used if your application and Product.dat file are in different
    folders or you have renamed the Product.dat file.

    If this function is used, it must be called on every start of
    your program before any other functions are called.

    PARAMETERS:
    * filePath - path of the product file (Product.dat)

    RETURN CODES: LF_OK, LF_E_FPATH, LF_E_PFILE

    NOTE: If this function fails to set the path of product file, none of the
    other functions will work.
*/

LEXFLOATCLIENT_API HRESULT LF_CC SetProductFile(CSTRTYPE filePath);

/*
    FUNCTION: GetHandle()

    PURPOSE: Sets the version GUID of your application and gets the new handle
    which will be used for the version GUID.

    Dropping the license invalidates the used handle, so make sure you request
    a new handle after dropping the license.

    PARAMETERS:
    * versionGUID - the unique version GUID of your application as mentioned
      on the product version page of your application in the dashboard.
    * handle - pointer to the integer that receives the value

    RETURN CODES: LF_OK, LF_E_PFILE, LF_E_GUID
*/

LEXFLOATCLIENT_API HRESULT LF_CC GetHandle(CSTRTYPE versionGUID, uint32_t *handle);

/*
    FUNCTION: SetFloatServer()

    PURPOSE: Sets the network address of the LexFloatServer.

    PARAMETERS:
    * handle - handle for the version GUID
    * hostAddress - hostname or the IP address of the LexFloatServer
    * port - port of the LexFloatServer

    RETURN CODES: LF_OK, LF_E_HANDLE, LF_E_GUID, LF_FAIL
*/

LEXFLOATCLIENT_API HRESULT LF_CC SetFloatServer(uint32_t handle, CSTRTYPE hostAddress, unsigned short port);

/*
    FUNCTION: SetLicenseCallback()

    PURPOSE: Sets refresh license error callback function.

    Whenever the lease expires, a refresh lease request is sent to the
    server. If the lease fails to refresh, refresh license callback function
    gets invoked with the following status error codes: LF_E_LICENSE_EXPIRED,
    LF_E_LICENSE_EXPIRED_INET, LF_E_SERVER_TIME, LF_E_TIME.

    PARAMETERS:
    * handle - handle for the version GUID
    * callback - name of the callback function

    RETURN CODES: LF_OK, LF_E_HANDLE, LF_E_GUID
*/

LEXFLOATCLIENT_API HRESULT LF_CC SetLicenseCallback(uint32_t handle, CallbackType callback);

/*
    FUNCTION: RequestLicense()

    PURPOSE: Sends the request to lease the license from the LexFloatServer.

    PARAMETERS:
    * handle - handle for the version GUID

    RETURN CODES: LF_OK, LF_FAIL, LF_E_HANDLE, LF_E_GUID, LF_E_SERVER_ADDRESS,
    LF_E_CALLBACK, LF_E_LICENSE_EXISTS, LF_E_INET, LF_E_NO_FREE_LICENSE, LF_E_TIME,
    LF_E_PRODUCT_VERSION, LF_E_SERVER_TIME
*/

LEXFLOATCLIENT_API HRESULT LF_CC RequestLicense(uint32_t handle);

/*
    FUNCTION: DropLicense()

    PURPOSE: Sends the request to drop the license from the LexFloatServer.

    Call this function before you exit your application to prevent zombie licenses.

    PARAMETERS:
    * handle - handle for the version GUID

    RETURN CODES: LF_OK, LF_FAIL, LF_E_HANDLE, LF_E_GUID, LF_E_SERVER_ADDRESS,
    LF_E_CALLBACK, LF_E_INET, LF_E_TIME, LF_E_SERVER_TIME
*/

LEXFLOATCLIENT_API HRESULT LF_CC DropLicense(uint32_t handle);

/*
    FUNCTION: HasLicense()

    PURPOSE: Checks whether any license has been leased or not. If yes,
    it retuns LF_OK.

    PARAMETERS:
    * handle - handle for the version GUID

    RETURN CODES: LF_OK, LF_FAIL, LF_E_HANDLE, LF_E_GUID, LF_E_SERVER_ADDRESS,
    LF_E_CALLBACK
*/

LEXFLOATCLIENT_API HRESULT LF_CC HasLicense(uint32_t handle);

/*
    FUNCTION: GetCustomLicenseField()

    PURPOSE: Get the value of the custom field associated with the float server key.

    PARAMETERS:
    * handle - handle for the version GUID
    * fieldId - id of the custom field whose value you want to get
    * fieldValue - pointer to a buffer that receives the value of the string
    * length - size of the buffer pointed to by the fieldValue parameter

    RETURN CODES: LF_OK, LF_FAIL, LF_E_HANDLE, LF_E_GUID, LF_E_SERVER_ADDRESS,
    LF_E_CALLBACK, LF_E_BUFFER_SIZE, LF_E_CUSTOM_FIELD_ID, LF_E_INET, LF_E_TIME,
    LF_E_SERVER_TIME
*/

LEXFLOATCLIENT_API HRESULT LF_CC GetCustomLicenseField(uint32_t handle, CSTRTYPE fieldId, STRTYPE fieldValue, uint32_t length);

/*
    FUNCTION: FindHandle()

    PURPOSE: Gets the handle set for the version GUID.

    Dropping the license invalidates the used handle, so make sure you request
    a new handle after dropping the license.

    PARAMETERS:
    * versionGUID - the unique version GUID of your application as mentioned
      on the product version page of your application in the dashboard.
    * handle - pointer to the integer that receives the value

    RETURN CODES: LF_OK, LF_E_PFILE, LF_E_GUID, LF_E_HANDLE
*/

LEXFLOATCLIENT_API HRESULT LF_CC FindHandle(CSTRTYPE versionGUID, uint32_t *handle);

/*
    FUNCTION: GlobalCleanUp()

    PURPOSE: Releases the resources acquired for sending network requests.

    Call this function before you exit your application.

    RETURN CODES: LF_OK

    NOTE: This function does not drop any leased license on the LexFloatServer.
*/

LEXFLOATCLIENT_API HRESULT LF_CC GlobalCleanUp();

/*** Return Codes ***/

#define LF_OK           ((HRESULT)0x00000000L)

#define LF_FAIL         ((HRESULT)0x00000001L)

/*
    CODE: LF_E_INET

    MESSAGE: Failed to connect to the server due to network error.
*/

#define LF_E_INET	    ((HRESULT)0x00000002L)

/*
    CODE: LF_E_CALLBACK

    MESSAGE: Invalid or missing callback function.
*/

#define LF_E_CALLBACK             ((HRESULT)0x00000003L)  

/*
    CODE: LF_E_NO_FREE_LICENSE

    MESSAGE: No free license is available
*/

#define LF_E_NO_FREE_LICENSE      ((HRESULT)0x00000004L)

/*
    CODE: LF_E_LICENSE_EXISTS

    MESSAGE: License has already been leased.
*/

#define LF_E_LICENSE_EXISTS		  ((HRESULT)0x00000005L)	

/*
    CODE: LF_E_HANDLE

    MESSAGE: Invalid handle.
*/

#define LF_E_HANDLE               ((HRESULT)0x00000006L)

/*
    CODE: LF_E_LICENSE_EXPIRED

    MESSAGE: License lease has expired. This happens when the
    request to refresh the license fails due to license been taken
    up by some other client.
*/

#define LF_E_LICENSE_EXPIRED      ((HRESULT)0x00000007L)

/*
    CODE: LF_E_LICENSE_EXPIRED_INET

    MESSAGE: License lease has expired due to network error. This 
    happens when the request to refresh the license fails due to
    network error.
*/

#define LF_E_LICENSE_EXPIRED_INET ((HRESULT)0x00000008L)

/*
    CODE: LF_E_SERVER_ADDRESS

    MESSAGE: Missing server address.
*/

#define LF_E_SERVER_ADDRESS		  ((HRESULT)0x00000009L)

/*
    CODE: LF_E_PFILE

    MESSAGE: Invalid or corrupted product file.
*/

#define LF_E_PFILE		          ((HRESULT)0x0000000AL)

/*
    CODE: LF_E_FPATH

    MESSAGE: Invalid product file path.
*/

#define LF_E_FPATH		          ((HRESULT)0x0000000BL)

/*
    CODE: LF_E_PRODUCT_VERSION

    MESSAGE: The version GUID of the client and server don't match.
*/

#define LF_E_PRODUCT_VERSION	  ((HRESULT)0x0000000CL)	

/*
    CODE: LF_E_GUID

    MESSAGE: The version GUID doesn't match that of the product file.
*/

#define LF_E_GUID                 ((HRESULT)0x0000000DL)

/*
    CODE: LF_E_SERVER_TIME

    MESSAGE: System time on Server Machine has been tampered with. Ensure 
    your date and time settings are correct on the server machine.
*/	

#define LF_E_SERVER_TIME          ((HRESULT)0x0000000EL)	

/*
    CODE: LF_E_TIME

    MESSAGE: The system time has been tampered with. Ensure your date
    and time settings are correct.
*/

#define LF_E_TIME                 ((HRESULT)0x00000010L)	

/*
    CODE: LF_E_CUSTOM_FIELD_ID

    MESSAGE: Invalid custom field id.
*/	

#define LF_E_CUSTOM_FIELD_ID      ((HRESULT)0x00000011L)	

/*
    CODE: LF_E_BUFFER_SIZE

    MESSAGE: The buffer size was smaller than required.
*/

#define LF_E_BUFFER_SIZE          ((HRESULT)0x00000012L)  

