package main

import (
	"bufio"
	"fmt"
	"github.com/cryptlex/lexfloatclient-go"
	"os"
)

func licenseCallback(status int) {
	if status == lexfloatclient.LF_OK {
		fmt.Println("The license lease has renewed successfully.")
	} else if status == lexfloatclient.LF_E_LICENSE_NOT_FOUND {
		fmt.Println("he license expired before it could be renewed.")
	} else if status == lexfloatclient.LF_E_LICENSE_EXPIRED_INET {
		fmt.Println("The license expired due to network connection failure.")
	} else {
		fmt.Println("The license renew failed due to other reason. Error code:", status)
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
	var metadataValue string
    status = lexfloatclient.GetHostLicenseMetadata("key1", &metadataValue)
	if lexfloatclient.LF_OK != status {
		fmt.Println("Error getting license metadata. Code:", status)
	}  
	fmt.Println(metadataValue)
    status = lexfloatclient.DropFloatingLicense()
	if lexfloatclient.LF_OK != status {
		fmt.Println("Dropping license error code:", status)
	}  
    fmt.Println("Success! License dropped.")
	fmt.Println("Press any key to exit...")
	bufio.NewReader(os.Stdin).ReadByte()
}