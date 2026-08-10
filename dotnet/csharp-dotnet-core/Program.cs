using System;
using Cryptlex;

namespace Sample
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                LexFloatClient.SetHostProductId("PASTE_PRODUCT_ID");
                LexFloatClient.SetHostUrl("http://localhost:8090");
                LexFloatClient.SetFloatingLicenseCallback(LicenseRenewCallback);


                LexFloatClient.RequestFloatingLicense();
                Console.WriteLine("Success! License acquired.");
                Console.WriteLine(LexFloatClient.GetHostLicenseEntitlementSetName());
                Console.WriteLine("Press any key to drop the license ...");
                Console.ReadKey();
                LexFloatClient.DropFloatingLicense();
                Console.WriteLine("Success! License dropped successfully.");
            }
            catch (LexFloatClientException ex)
            {
                Console.WriteLine("Error code: " + ex.Code.ToString() + " Error message: " + ex.Message);
            }
            Console.WriteLine("Press any key to exit");
            Console.ReadKey();
        }

        static void LicenseRenewCallback(uint status)
        {
            switch (status)
            {
                case LexFloatStatusCodes.LF_OK:
                    Console.WriteLine("The license lease has renewed successfully.");
                    break;
                case LexFloatStatusCodes.LF_E_LICENSE_NOT_FOUND:
                    Console.WriteLine("The license expired before it could be renewed.");
                    break;
                case LexFloatStatusCodes.LF_E_LICENSE_EXPIRED_INET:
                    Console.WriteLine("The license expired due to network connection failure.");
                    break;
                default:
                    Console.WriteLine("The license renewal failed due to another reason. Error code: " + status.ToString());
                    break;
            }
        }
    }
}
