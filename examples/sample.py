import time
import sys
from cryptlex.lexfloatclient import LexFloatClient, LexFloatStatusCodes, LexFloatClientException
# from cryptlex.lexfloatclient import *


def licence_callback_fn(status):
    if LexFloatStatusCodes.LF_OK == status:
        print("The license lease has renewed successfully.")
    elif LexFloatStatusCodes.LF_E_LICENSE_NOT_FOUND == status:
        print("The license expired before it could be renewed.")
    elif LexFloatStatusCodes.LF_E_LICENSE_EXPIRED_INET == status:
        print("The license expired due to network connection failure.")
    else:
        print("The license renew failed due to other reason. Error code: ", status)


def main():
    try:
        # Set the product id
        LexFloatClient.SetHostProductId("PASTE_PRODUCT_ID")
        # Set the float server
        LexFloatClient.SetHostUrl("http://localhost:8090")
        # Set the license callback
        LexFloatClient.SetFloatingLicenseCallback(licence_callback_fn)
        # Request license lease
        LexFloatClient.RequestFloatingLicense()
        print("Success! License acquired. Press enter to get the license metadata...")
        sys.stdin.read(1)
        # Request license metadata
        # metadata_value = LexFloatClient.GetHostLicenseMetadata("key1")
        print("Press enter to drop the license ...")
        sys.stdin.read(1)
        # Drop license lease
        LexFloatClient.DropFloatingLicense()
        print("Success! License dropped.")
    except LexFloatClientException as exception:
        print('Error code:', exception.code, exception.message)


main()
input("Press Enter to continue...")
