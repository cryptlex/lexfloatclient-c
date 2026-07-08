using System;
using System.Windows.Forms;
using Cryptlex;

namespace FloatSample
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void LicenceRenewCallback(uint status)
        {
            switch (status)
            {
                case LexFloatStatusCodes.LF_OK:
                    this.statusLabel.Text = "The license lease has renewed successfully.";
                    break;
                case LexFloatStatusCodes.LF_E_LICENSE_NOT_FOUND:
                    this.statusLabel.Text = "The license expired before it could be renewed.";
                    break;
                case LexFloatStatusCodes.LF_E_LICENSE_EXPIRED_INET:
                    this.statusLabel.Text = "The license expired due to network connection failure.";
                    break;
                default:
                    this.statusLabel.Text = "The license renew failed due to other reason. Error code: " + status.ToString();
                    break;
            }
        }

        private void leaseBtn_Click(object sender, EventArgs e)
        {
            try
            {
                LexFloatClient.SetHostProductId("PASTE_YOUR_PRODUCT_ID");
                LexFloatClient.SetHostUrl("http://localhost:8090");
                LexFloatClient.SetFloatingLicenseCallback(LicenceRenewCallback);

                LexFloatClient.RequestFloatingLicense();
                this.statusLabel.Text = "License leased successfully!";
            }
            catch (LexFloatClientException ex)
            {
                this.statusLabel.Text = "Error code: " + ex.Code.ToString() + " Error message: " + ex.Message;
            }
        }

        private void dropBtn_Click(object sender, EventArgs e)
        {
            try
            {
                if (!LexFloatClient.HasFloatingLicense())
                {
                    return;
                }
                LexFloatClient.DropFloatingLicense();
                this.statusLabel.Text = "License dropped successfully!";
            }
            catch (LexFloatClientException ex)
            {
                this.statusLabel.Text = "Error code: " + ex.Code.ToString() + " Error message: " + ex.Message;
            }
        }
    }
}
