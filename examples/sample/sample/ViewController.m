//
//  ViewController.m
//  sample
//
//  Created by Adnan Kamili on 30/06/21.
//

#import "ViewController.h"
#import <LexFloatClient/LexFloatClient.h>
@interface ViewController ()
@property (weak, nonatomic) IBOutlet UIButton *activateButton;
@property (weak, nonatomic) IBOutlet UIButton *dropLicenseButton;
@property (weak, nonatomic) IBOutlet UILabel *licenseStatusLabel;

@end

@implementation ViewController

void LF_CC licenceRenewCallback(uint32_t status)
{
    switch (status)
    {
    case LF_OK:
        printf("The license lease has renewed successfully.\n");
        break;
    case LF_E_LICENSE_NOT_FOUND:
        printf("The license expired before it could be renewed.\n");
        break;
    case LF_E_LICENSE_EXPIRED_INET:
        printf("The license expired due to network connection failure.\n");
        break;
    default:
        printf("The license renew failed due to other reason. Error code: %d\n", status);
        break;
    }
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    int status;
    status = SetHostProductId("PASTE_PRODUCT_ID");
    if(status != LF_OK)
    {
        self.licenseStatusLabel.text = [NSString stringWithFormat:@"%d",status];
        return;
    }
    
    status = SetHostUrl("http://localhost:8090");
    if(status != LF_OK)
    {
        self.licenseStatusLabel.text = [NSString stringWithFormat:@"%d",status];
        return;
    }

}
- (IBAction)onActivateClick:(id)sender {
    int status;
    status = SetFloatingLicenseCallback(licenceRenewCallback);
    if(status != LF_OK)
    {
        self.licenseStatusLabel.text = [NSString stringWithFormat:@"%d",status];
        return;
    }
    status = RequestFloatingLicense();
    self.licenseStatusLabel.text = [NSString stringWithFormat:@"%d",status];
}
- (IBAction)onDropLicenseClick:(id)sender {
    int status = DropFloatingLicense();
    self.licenseStatusLabel.text = [NSString stringWithFormat:@"%d",status];
}


@end
