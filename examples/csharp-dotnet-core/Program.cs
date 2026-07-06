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
                var hostConfig = LexFloatClient.GetHostConfig();
                if (hostConfig != null)
                {
                    Console.WriteLine("Host config:");
                    Console.WriteLine("  maxOfflineLeaseDuration: " + hostConfig.maxOfflineLeaseDuration);
                }
                else
                {
                    Console.WriteLine("Host config is null.");
                }

                var hostFeatureEntitlements = LexFloatClient.GetHostFeatureEntitlements();
                if (hostFeatureEntitlements != null)
                {
                    Console.WriteLine("Host feature entitlements:");
                    foreach (var feature in hostFeatureEntitlements)
                    {
                        Console.WriteLine("  Name: " + feature.FeatureName + ", DisplayName: " + feature.FeatureDisplayName + ", Value: " + feature.Value + ", BaseValue: " + feature.BaseValue + ", ExpiresAt: " + feature.ExpiresAt);
                    }
                }
                else
                {
                    Console.WriteLine("Host feature entitlements are null.");
                }
                Console.WriteLine(LexFloatClient.GetHostLicenseEntitlementSetTier());
                Console.WriteLine("Press Enter to drop the license ...");
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
                    Console.WriteLine("The license renew failed due to other reason. Error code: " + status.ToString());
                    break;
            }
        }
    }
}
