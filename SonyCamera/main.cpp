#include <iostream>
#include <vector>

#include "stubclient.h"
#include <jsonrpccpp/client/connectors/httpclient.h>
#include <jsoncpp/json/json.h>


using namespace jsonrpc;
using namespace std;
using namespace cv;


//GSTREAMER http stream client
//gst-launch -v souphttpsrc location=http://192.168.122.1:8080/liveview/liveviewstream is-live=true ! jpegdec ! ffmpegcolorspace ! ximagesink

int main()
{
    HttpClient client("http://192.168.122.1:8080/sony/camera");
    StubClient c(client, JSONRPC_CLIENT_V1);

    Json::Value params;
    //params["params"] = "[]";
    Json::Value result;
    Json::StreamWriterBuilder swb;
    swb.settings_["indentation"] = "";

    try
    {
        //std::cout << c.guru_test("Guru");
        //c.stopLiveview();
        result = c.getAvailableApiList();
        Json::Value mjpegStreamURI = c.startLiveview();
        cout << result.toStyledString() <<endl <<endl;
        cout << mjpegStreamURI.toStyledString() <<endl;

        std::string out =Json::writeString(swb, mjpegStreamURI[0]);
        std::cout<< out.c_str()<<endl;
        std::string sourceStr = out; //something like "http://192.168.122.1:8080/liveview/liveviewstream";       
        
	}
	catch (JsonRpcException& e)
    {
        cerr << e.what() << endl;
    }
	
	return 0;
}
