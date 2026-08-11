package main

import (
	"bufio"
	"fmt"
	"os"

	"github.com/cryptlex/lexfloatclient-go"
)

func licenseCallback(status int) {
	if status == lexfloatclient.LF_OK {
		fmt.Println("The license lease was renewed successfully.")
	} else if status == lexfloatclient.LF_E_LICENSE_NOT_FOUND {
		fmt.Println("The license expired before it could be renewed.")
	} else if status == lexfloatclient.LF_E_LICENSE_EXPIRED_INET {
		fmt.Println("The license expired due to network connection failure.")
	} else {
		fmt.Println("The license renewal failed due to another reason. Error code:", status)
	}
}

func main() {
	var status int
	status = lexfloatclient.SetHostProductId("PASTE_PRODUCT_ID")
	if lexfloatclient.LF_OK != status {
		fmt.Println("Error Code:", status)
		os.Exit(1)
	}
	status = lexfloatclient.SetHostUrl("http://localhost:8090")
	if lexfloatclient.LF_OK != status {
		fmt.Println("Error Code:", status)
		os.Exit(1)
	}
	lexfloatclient.SetFloatingLicenseCallback(licenseCallback)
	status = lexfloatclient.RequestFloatingLicense()
	if lexfloatclient.LF_OK != status {
		fmt.Println("Error Code:", status)
		os.Exit(1)
	}
	fmt.Println("Success! License acquired.")
	var entitlementSetName string
	status = lexfloatclient.GetHostLicenseEntitlementSetName(&entitlementSetName)
	if lexfloatclient.LF_OK != status {
		fmt.Println("Error getting license entitlement set name. Code:", status)
	} else {
		fmt.Println(entitlementSetName)
	}
	status = lexfloatclient.DropFloatingLicense()
	if lexfloatclient.LF_OK != status {
		fmt.Println("Dropping license error code:", status)
	}
	fmt.Println("Success! License dropped.")
	fmt.Println("Press Enter to exit...")
	bufio.NewReader(os.Stdin).ReadString('\n')
}
