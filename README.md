# lexfloatclient-examples

Sample integrations showing how to lease **on-premise floating licenses** from a
LexFloatServer using **LexFloatClient**, across a range of languages and platforms.

## What is LexFloatClient?

LexFloatClient is Cryptlex's client library for consuming floating licenses served by a
**LexFloatServer** running on-premise within the local network. Instead of each machine
contacting the Cryptlex cloud, your application leases a floating seat from a LexFloatServer
instance on the LAN and releases it when it's done. This is designed for environments where
end-user machines have no internet access but you still want a shared pool of concurrent
licenses within the network.

How the pieces fit together:

- **LexFloatServer** runs on-premise and holds the pool of floating licenses. Its own
  license is activated against Cryptlex using **LexActivator**.
- **LexFloatClient** (this library) runs inside your application and requests, holds, and
  releases a seat from that LexFloatServer.

LexFloatClient is **not** standalone. It needs a reachable LexFloatServer on the network.

> Want licenses that activate directly against the Cryptlex cloud or an on-premise Cryptlex
> server (node-locked, hosted floating, or trials)? Use **LexActivator** instead. See
> `lexactivator-examples`.

## What's in this directory

Each subdirectory is a self-contained example for one language or platform and includes
its own README with setup, build, and run instructions.

| Language / Platform | Directory |
| --- | --- |
| C / C++ | [c](c/) |
| .NET (C# and VB.NET) | [dotnet](dotnet/) |
| Java | [java](java/) |
| Node.js | [js](js/) |
| Python | [python](python/) |
| Go | [go](go/) |
| Android | [android](android/) |
| iOS | [ios](ios/) |

## Getting started

1. Make sure a **LexFloatServer** is running and reachable on your network.
2. Open the subdirectory for your language or platform.
3. Follow that directory's README for build and run steps, pointing the client at your
   LexFloatServer's host and port.

## Learn more

- Documentation: https://cryptlex.com/docs
- LexFloatClient reference: https://cryptlex.com/docs/sdks-and-apis/lexfloatclient