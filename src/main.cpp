#include "../include/controlTest.h";
#include "../include/staticFunction.h";
#include "../include/structures.h"

/*
local JsonMesFormat = {
	"testType" = "latency"/"download"/"upload",			--string
	"messageType" = "setup"/"update"/"data"/"stop",		--string
	"timeout" = 500/2000/7000/etc,						--uint32_t
	"duration" = 3000/20000/120000/etc,					--uint32_t
	"packQuantity" = 10/333/1000/etc,					--uint64_t
	"threads" = 1/9/30/etc,								--uint16_t
	"mesSize" = 1024/4096/etc,							--uint32_t
	"writeThroughput" = 655386/65635/etc,				--uint64_t
	"readThroughput" = 498277/39345/etc,				--uint64_t
	"destEndpointAdr" = "127.0.0.1"/"31.148.99.65"/etc,	--string
	"destEndpointPort" = 8484/9999/etc,					--uint16_t
	"srcEndpointAdr" = "127.0.0.1"/"31.148.99.65"/etc,	--string
	"srcEndpointPort" = 48732/9009/etc,					--uint16_t
	"packLoss" = 0/11/1234/etc,							--uint64_t
	"latency" = 0.5/12/1298/etc,						--double
	"body" = "REQ"/"OK"/"a00b332c67bba8fe34"/etc		--string
}
*/

int main(int argc, char* argv[]){
	configObject info;
	if(staticfunction::parseArguments(&info, argc, argv) > 0){
		//staticfunction::printStringVectorArr(info.returnDataInString());

		//benchLoadNode::controlTest testObj;

		//std::cout 	<< "\nURL is " << testObj.getDestUrl() << '\n\n'
		//			<< testObj.getJsonString("latency", 1000, "127.0.0.1", 10001, 2, 100, 30, staticfunction::generateRandomHexString(1024)) << '\n'
		//			<<'\n';
		//jsonMessage jsonObj = testObj.parseJsonString(testObj.getJsonString("latency", 1000, "127.0.0.1", 10001, 2, 100, 30, staticfunction::generateRandomHexString(1024)));

		//staticfunction::printStringVectorArr(jsonObj.returnDataInString());

	}
	return NULL;
}
