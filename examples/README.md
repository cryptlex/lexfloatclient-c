# LexFloatClient iOS Example

Example demonstrating floating license acquisition with the LexFloatClient iOS
library.

## Setup

This project links against `LexFloatClient.xcframework`, which is not bundled here.
Build it from the LexFloatClient native source and place it at:

```
examples/sample/LexFloatClient.xcframework
```

## Running

Open `examples/sample/sample.xcodeproj` in Xcode, select your signing team, and
run the `sample` target.

Set your product ID and float server URL in
[ViewController.m](sample/sample/ViewController.m) before running.

## Documentation

Refer to the following for documentation:

https://docs.cryptlex.com/floating-licenses/on-premise-floating-licenses/using-lexfloatclient
