# LexFloatClient C/C++ Example

Example demonstrating floating license acquisition with the LexFloatClient C/C++
library.

## Running

This directory contains a console sample:

- [FloatSample.cpp](FloatSample.cpp) — console sample

```bash
cd c
make
./FloatSample
```

Requires the LexFloatClient library for your platform
(`libLexFloatClient.dylib`/`.so`/`.dll`) in this directory. Download it from the Cryptlex dashboard.
On Windows, also place the `LexFloatClient.lib` import library in the `x86/` or `x64/` directory so the sample can link. Set your product ID and float server URL in `FloatSample.cpp` before running.

## Documentation

Refer to the following for documentation:

https://cryptlex.com/docs/sdks-and-apis/lexfloatclient
