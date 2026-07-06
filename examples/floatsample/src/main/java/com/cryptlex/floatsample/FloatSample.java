package com.cryptlex.floatsample;

import com.cryptlex.lexfloatclient.LexFloatClient;
import com.cryptlex.lexfloatclient.LicenseCallbackEvent;
import com.cryptlex.lexfloatclient.LexFloatClientException;
import java.io.IOException;

class CallbackEventListener implements LicenseCallbackEvent {
    @Override
    public void LicenseCallback(int status) {
        switch (status) {
        case LexFloatClient.LF_OK:
            System.out.println("The license lease has renewed successfully.");
            break;
        case LexFloatClientException.LF_E_LICENSE_NOT_FOUND:
            System.out.println("The license expired before it could be renewed.");
            break;
        case LexFloatClientException.LF_E_LICENSE_EXPIRED_INET:
            System.out.println("The license expired due to network connection failure.");
            break;
        default:
            System.out.println("The license renew failed due to other reason. Error code: " + Integer.toString(status));
            break;
        }
    }
}

public class FloatSample {

    public static void main(String[] args) {
        try {
            CallbackEventListener eventListener = new CallbackEventListener();
            LexFloatClient.SetHostProductId("PASTE_PRODUCT_ID");
            LexFloatClient.SetHostUrl("http://localhost:8090");
            LexFloatClient.AddLicenseCallbackListener(eventListener);

            LexFloatClient.RequestFloatingLicense();
            System.out.println("Success! License acquired.");
            
            System.out.println(LexFloatClient.GetHostLicenseEntitlementSetName());

            System.out.println("Press Enter to drop the license ...");
            System.in.read();

            LexFloatClient.DropFloatingLicense();
            System.out.println("Success! License dropped successfully.");
        } catch (LexFloatClientException ex) {
            System.out.println(ex.getCode() + ": " + ex.getMessage());
        } catch (IOException ex) {
            System.out.println(ex.getMessage());
        }
    }

}

