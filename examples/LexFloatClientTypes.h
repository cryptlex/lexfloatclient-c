#ifndef LEX_FLOAT_CLIENT_TYPES_H
#define LEX_FLOAT_CLIENT_TYPES_H

#include <stdint.h>
#define BUFFER_SIZE_256 256

#ifdef _WIN32
    typedef wchar_t CHARTYPE;
#else
    typedef char CHARTYPE;
#endif

/*
    STRUCT: HostConfig

    MEMBERS:
    * maxOfflineLeaseDuration - Maximum offline lease duration in seconds.
*/
typedef struct
{
    int maxOfflineLeaseDuration;
} HostConfig;

/*
    STRUCT: HostFeatureEntitlement

    MEMBERS:
    * featureName         - Name of the feature.
    * featureDisplayName  - Display name of the feature.
    * value               - Value associated with the feature.
*/
typedef struct 
{
    CHARTYPE featureName[BUFFER_SIZE_256];
    CHARTYPE featureDisplayName[BUFFER_SIZE_256];
    CHARTYPE value[BUFFER_SIZE_256];
} HostFeatureEntitlement;

#endif // LEX_FLOAT_CLIENT_TYPES_H
