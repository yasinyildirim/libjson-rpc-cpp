Connect to Sony Camera Remote API Using the framework
===================
This example shows how to use rpc-client program (main.cpp) in order to communicate with Sony Camera API. 

### Step 1: Building the library ###
Build library using the docs in library root dir.

### Step 2: Generate the stub for client ###
Call jsonrpcstub:
```sh
jsonrpcstub spec.json --cpp-client=StubClient
```

This generates a clientstub class.

### Step 3: compile the client application ###
Compile the client with:

```sh
g++ main.cpp -ljsoncpp -lcurl -ljsonrpccpp-common -ljsonrpccpp-client -o sampleclient
```

### Step 4: Addding additional api methods to the specification file ###

For example, append the following for adding getSupportedShootMode() api call to client:
```json
[
	{
		"method": "getSupportedShootMode",
		"params": [],
		"id": 1,
		"version": "1.0"
	}
]
```
