/* LexFloatClient.h */
#pragma once

#include <stdint.h>
#include "LexFloatStatusCodes.h"

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
    FUNCTION: GetHandle()

    PURPOSE: Sets the product id of your application and gets the new handle
    which will be used for the product id.

    Dropping the license invalidates the used handle, so make sure you request
    a new handle after dropping the license.

    PARAMETERS:
    * productId - the unique product id of your application as mentioned
      on the product page in the dashboard.
    * handle - pointer to the integer that receives the value

    RETURN CODES: LF_OK, LF_E_PRODUCT_ID
*/

LEXFLOATCLIENT_API HRESULT LF_CC GetHandle(CSTRTYPE productId, uint32_t *handle);

/*
    FUNCTION: SetFloatServer()

    PURPOSE: Sets the network address of the LexFloatServer.

    PARAMETERS:
    * handle - handle for the product id
    * hostAddress - hostname or the IP address of the LexFloatServer
    * port - port of the LexFloatServer

    RETURN CODES: LF_OK, LF_E_HANDLE, LF_E_PRODUCT_ID, LF_FAIL
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
    * handle - handle for the product id
    * callback - name of the callback function

    RETURN CODES: LF_OK, LF_E_HANDLE, LF_E_PRODUCT_ID
*/

LEXFLOATCLIENT_API HRESULT LF_CC SetLicenseCallback(uint32_t handle, CallbackType callback);

/*
    FUNCTION: RequestLicense()

    PURPOSE: Sends the request to lease the license from the LexFloatServer.

    PARAMETERS:
    * handle - handle for the product id

    RETURN CODES: LF_OK, LF_FAIL, LF_E_HANDLE, LF_E_PRODUCT_ID, LF_E_SERVER_ADDRESS,
    LF_E_CALLBACK, LF_E_LICENSE_EXISTS, LF_E_INET, LF_E_NO_FREE_LICENSE, LF_E_TIME,
    LF_E_SERVER_TIME
*/

LEXFLOATCLIENT_API HRESULT LF_CC RequestLicense(uint32_t handle);

/*
    FUNCTION: DropLicense()

    PURPOSE: Sends the request to drop the license from the LexFloatServer.

    Call this function before you exit your application to prevent zombie licenses.

    PARAMETERS:
    * handle - handle for the product id

    RETURN CODES: LF_OK, LF_FAIL, LF_E_HANDLE, LF_E_PRODUCT_ID, LF_E_SERVER_ADDRESS,
    LF_E_CALLBACK, LF_E_INET, LF_E_TIME, LF_E_SERVER_TIME
*/

LEXFLOATCLIENT_API HRESULT LF_CC DropLicense(uint32_t handle);

/*
    FUNCTION: HasLicense()

    PURPOSE: Checks whether any license has been leased or not. If yes,
    it retuns LF_OK.

    PARAMETERS:
    * handle - handle for the product id

    RETURN CODES: LF_OK, LF_FAIL, LF_E_HANDLE, LF_E_PRODUCT_ID, LF_E_SERVER_ADDRESS,
    LF_E_CALLBACK
*/

LEXFLOATCLIENT_API HRESULT LF_CC HasLicense(uint32_t handle);

/*
    FUNCTION: GetLicenseMetadata()

    PURPOSE: Get the value of the license metadata field associated with the float server key.

    PARAMETERS:
    * handle - handle for the product id
    * key - key of the metadata field whose value you want to get
    * value - pointer to a buffer that receives the value of the string
    * length - size of the buffer pointed to by the value parameter

    RETURN CODES: LF_OK, LF_FAIL, LF_E_HANDLE, LF_E_PRODUCT_ID, LF_E_SERVER_ADDRESS,
    LF_E_CALLBACK, LF_E_BUFFER_SIZE, LF_E_METADATA_KEY_NOT_FOUND, LF_E_INET, LF_E_TIME,
    LF_E_SERVER_TIME
*/

LEXFLOATCLIENT_API HRESULT LF_CC GetLicenseMetadata(uint32_t handle, CSTRTYPE key, STRTYPE value, uint32_t length);

/*
    FUNCTION: FindHandle()

    PURPOSE: Gets the handle set for the product id.

    Dropping the license invalidates the used handle, so make sure you request
    a new handle after dropping the license.

    PARAMETERS:
    * productId - the unique product id of your application as mentioned
      on the product page in the dashboard.
    * handle - pointer to the integer that receives the value

    RETURN CODES: LF_OK, LF_E_PRODUCT_ID, LF_E_HANDLE
*/

LEXFLOATCLIENT_API HRESULT LF_CC FindHandle(CSTRTYPE productId, uint32_t *handle);

/*
    FUNCTION: GlobalCleanUp()

    PURPOSE: Releases the resources acquired for sending network requests.

    Call this function before you exit your application.

    RETURN CODES: LF_OK

    NOTE: This function does not drop any leased license on the LexFloatServer.
*/

LEXFLOATCLIENT_API HRESULT LF_CC GlobalCleanUp();
