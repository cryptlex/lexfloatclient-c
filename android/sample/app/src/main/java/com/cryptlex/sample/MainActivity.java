package com.cryptlex.sample;
import com.cryptlex.android.lexfloatclient.LexFloatClient;
import com.cryptlex.android.lexfloatclient.LexFloatClientException;
import com.cryptlex.android.lexfloatclient.LicenseCallbackEvent;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private TextView statusTextView;

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

    public void requestLicense(View view) {
        try {
            CallbackEventListener eventListener = new CallbackEventListener();
            LexFloatClient.SetHostProductId("PASTE_PRODUCT_ID");
            LexFloatClient.SetHostUrl("http://localhost:8090");
            LexFloatClient.AddLicenseCallbackListener(eventListener);

            LexFloatClient.RequestFloatingLicense();
            statusTextView.setText("Success! License acquired. Entitlement set: " + LexFloatClient.GetHostLicenseEntitlementSetName());
        } catch (LexFloatClientException ex) {
            statusTextView.setText(ex.getCode() + ": " + ex.getMessage());
        }
    }

    public void dropLicense(View view) {
        try {
            LexFloatClient.DropFloatingLicense();
            statusTextView.setText("Success! License dropped successfully.");
        } catch (LexFloatClientException ex) {
            statusTextView.setText(ex.getCode() + ": " + ex.getMessage());
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        statusTextView = (TextView) findViewById(R.id.statusTextView);
    }
}
