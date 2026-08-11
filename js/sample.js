/* eslint-disable new-cap */
const { LexFloatClient, LexFloatStatusCodes } = require('@cryptlex/lexfloatclient');

function licenseCallback(status) {
	if (LexFloatStatusCodes.LF_OK === status) {
		console.log('The license lease has renewed successfully.');
	} else if (LexFloatStatusCodes.LF_E_LICENSE_NOT_FOUND === status) {
		console.log('The license expired before it could be renewed.');
	} else if (LexFloatStatusCodes.LF_E_LICENSE_EXPIRED_INET === status) {
		console.log('The license expired due to network connection failure.');
	} else {
		console.log('The license renewal failed due to another reason. Error code: ', status);
	}
}

function main() {
	try {
		// Set the product id
		LexFloatClient.SetHostProductId('PASTE_PRODUCT_ID');

		// Set the float server
		LexFloatClient.SetHostUrl('http://localhost:8090');

		// Set the license callback
		LexFloatClient.SetFloatingLicenseCallback(licenseCallback);

		// Request license lease
		LexFloatClient.RequestFloatingLicense();
		console.log('Success! License acquired!');

		console.log('Requesting license entitlement set name...');
		const entitlementSetName = LexFloatClient.GetHostLicenseEntitlementSetName();
		console.log(entitlementSetName);

		console.log('Dropping the license ...');
		LexFloatClient.DropFloatingLicense();
		console.log('Success! License dropped.');
	} catch (error) {
		console.log(error.code, error.message);
	}
}

main();

process.stdin.setRawMode(true);
process.stdin.resume();
process.stdin.on('data', process.exit.bind(process, 0));
