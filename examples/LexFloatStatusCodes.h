#ifndef LEX_FLOAT_STATUS_CODES_H
#define LEX_FLOAT_STATUS_CODES_H

enum LexFloatStatusCodes
{
    /*
        CODE: LF_OK

        MESSAGE: Success code.
    */
    LF_OK = 0,

    /*
        CODE: LF_FAIL

        MESSAGE: Failure code.
    */
    LF_FAIL = 1,

    /*
        CODE: LF_E_PRODUCT_ID

        MESSAGE: The product id is incorrect.
    */
    LF_E_PRODUCT_ID = 40,

    /*
        CODE: LF_E_CALLBACK

        MESSAGE: Invalid or missing callback function.
    */
    LF_E_CALLBACK = 41,

    /*
        CODE: LF_E_HANDLE

        MESSAGE: Invalid handle.
    */
    LF_E_HANDLE = 42,

    /*
        CODE: LF_E_SERVER_ADDRESS

        MESSAGE: Missing or invalid server address.
    */
    LF_E_SERVER_ADDRESS = 43,

    /*
        CODE: LF_E_SERVER_TIME

        MESSAGE: System time on Server Machine has been tampered with. Ensure
        your date and time settings are correct on the server machine.
    */

    LF_E_SERVER_TIME = 44,

    /*
        CODE: LF_E_TIME

        MESSAGE: The system time has been tampered with. Ensure your date
        and time settings are correct.
    */
    LF_E_TIME = 45,

    /*
        CODE: LF_E_INET

        MESSAGE: Failed to connect to the server due to network error.
    */
    LF_E_INET = 46,

    /*
        CODE: LF_E_NO_FREE_LICENSE

        MESSAGE: No free license is available.
    */

    LF_E_NO_FREE_LICENSE = 47,

    /*
        CODE: LF_E_LICENSE_EXISTS

        MESSAGE: License has already been leased.
    */

    LF_E_LICENSE_EXISTS = 48,

    /*
        CODE: LF_E_LICENSE_EXPIRED

        MESSAGE: License lease has expired. This happens when the
        request to refresh the license fails due to license been taken
        up by some other client.
    */

    LF_E_LICENSE_EXPIRED = 49,

    /*
        CODE: LF_E_LICENSE_EXPIRED_INET

        MESSAGE: License lease has expired due to network error. This
        happens when the request to refresh the license fails due to
        network error.
    */

    LF_E_LICENSE_EXPIRED_INET = 50,

    /*
        CODE: LF_E_BUFFER_SIZE

        MESSAGE: The buffer size was smaller than required.
    */
    LF_E_BUFFER_SIZE = 51,

    /*
        CODE: LF_E_METADATA_KEY_NOT_FOUND

        MESSAGE: The metadata key does not exist.
    */
    LF_E_METADATA_KEY_NOT_FOUND = 52,

    /*
        CODE: LF_E_SERVER

        MESSAGE: Server error.
    */
    LF_E_SERVER = 70,

    /*
        CODE: LF_E_CLIENT

        MESSAGE: Client error.
    */
    LF_E_CLIENT = 71
};

#endif // LEX_FLOAT_STATUS_CODES_H
