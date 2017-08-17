#include "../include/staticFunction.h"

namespace staticfunction{

jsonMessage parseJsonString(std::string _jsonStr){
	rapidjson::Document dom;
	jsonMessage jsonObject;
	dom.Parse(_jsonStr.c_str());

	if(dom.HasMember("testType")) jsonObject.testType = dom["testType"].GetString();
	else jsonObject.testType = "null";
	if(dom.HasMember("messageType")) jsonObject.messageType = dom["messageType"].GetString();
	else jsonObject.messageType = "null";
	if(dom.HasMember("timeout")) jsonObject.timeout = (long long)std::stoi(dom["timeout"].GetString());
	else jsonObject.timeout = 0;
	if(dom.HasMember("duration")) jsonObject.duration = (long long)std::stoi(dom["duration"].GetString());
	else jsonObject.duration = 0;
	if(dom.HasMember("packQuantity")) jsonObject.packQuantity = (long long)std::stoi(dom["packQuantity"].GetString());
	else jsonObject.packQuantity = 0;
	if(dom.HasMember("threads")) jsonObject.threads = (int)std::stoi(dom["threads"].GetString());
	else jsonObject.threads = 0;
	if(dom.HasMember("thread")) jsonObject.threads = (int)std::stoi(dom["thread"].GetString());
	else jsonObject.thread = 0;
	if(dom.HasMember("mesSize")) jsonObject.mesSize = (long long)std::stoi(dom["mesSize"].GetString());
	else jsonObject.mesSize = 0;
	if(dom.HasMember("writeThroughput")) jsonObject.writeThroughput = (long long)std::stoi(dom["writeThroughput"].GetString());
	else jsonObject.writeThroughput = 0;
	if(dom.HasMember("readThroughput")) jsonObject.readThroughput = (long long)std::stoi(dom["readThroughput"].GetString());
	else jsonObject.readThroughput = 0;
	if(dom.HasMember("destEndpointAdr")) jsonObject.destEndpointAdr = dom["destEndpointAdr"].GetString();
	else jsonObject.destEndpointAdr = "null";
	if(dom.HasMember("destEndpointPort")) jsonObject.destEndpointPort = (int)std::stoi(dom["destEndpointPort"].GetString());
	else jsonObject.destEndpointPort = 0;
	if(dom.HasMember("srcEndpointAdr")) jsonObject.srcEndpointAdr = dom["srcEndpointAdr"].GetString();
	else jsonObject.srcEndpointAdr = "null";
	if(dom.HasMember("srcEndpointPort")) jsonObject.srcEndpointPort = (int)std::stoi(dom["srcEndpointPort"].GetString());
	else jsonObject.srcEndpointPort = 0;
	if(dom.HasMember("packLoss")) jsonObject.packLoss = (long long)std::stoi(dom["packLoss"].GetString());
	else jsonObject.packLoss = 0;
	if(dom.HasMember("latency")) jsonObject.latency = (long double)std::stod(dom["latency"].GetString());
	else jsonObject.latency = 0;
	if(dom.HasMember("body")) jsonObject.body = dom["body"].GetString();
	else jsonObject.body = "null";

	return jsonObject;
}

configObject parseConfigurationFile(std::string _jsonStr){
	rapidjson::Document dom;
	configObject jsonObject;
	dom.Parse(_jsonStr.c_str());

	if(dom.HasMember("testType")) jsonObject.testType = dom["testType"].GetString();
	else jsonObject.testType = "null";
	if(dom.HasMember("mode")) jsonObject.mode = dom["mode"].GetString();
	else jsonObject.mode = "null";
	if(dom.HasMember("protocol")) jsonObject.protocol = dom["protocol"].GetString();
	else jsonObject.protocol = "null";
	if(dom.HasMember("timeout")) jsonObject.timeout = (long long)std::stoi(dom["timeout"].GetString());
	else jsonObject.timeout = 0;
	if(dom.HasMember("duration")) jsonObject.duration = (long long)std::stoi(dom["duration"].GetString());
	else jsonObject.duration = 0;
	if(dom.HasMember("packQuantity")) jsonObject.packQuantity = (long long)std::stoi(dom["packQuantity"].GetString());
	else jsonObject.packQuantity = 0;
	if(dom.HasMember("threads")) jsonObject.threads = (int)std::stoi(dom["threads"].GetString());
	else jsonObject.threads = 0;
	if(dom.HasMember("mesSize")) jsonObject.mesSize = (long long)std::stoi(dom["mesSize"].GetString());
	else jsonObject.mesSize = 0;
	if(dom.HasMember("destEndpointAdr")) jsonObject.destEndpointAdr = dom["destEndpointAdr"].GetString();
	else jsonObject.destEndpointAdr = "null";
	if(dom.HasMember("destEndpointPort")) jsonObject.destEndpointPort = (int)std::stoi(dom["destEndpointPort"].GetString());
	else jsonObject.destEndpointPort = 0;

	return jsonObject;
}

int parseArguments(configObject* _jsonObject, int _argc, char* _argv[]){
	int retValue = 1;
	int confLabel = 0, portLabel = 0, ipLabel = 0;

	if(_argc > 1){
		int ix = 1;
		while(ix < _argc){
			if((strcmp(_argv[ix], "--configuration") == 0) || (strcmp(_argv[ix], "-c") == 0)){
				std::fstream file;

				file.open(_argv[ix+1], std::ios::in);
				std::string line;
				std::string resultStr;

				while (file >> line)
				{
				    resultStr += line;
				}
				file.close();

				*_jsonObject = parseConfigurationFile(resultStr);
				confLabel = 1;
				ix = ix + 2;
			} else if((strcmp(_argv[ix], "--destip") == 0) || (strcmp(_argv[ix], "-i") == 0)){
				ipLabel = ix;
				ix = ix + 2;
			} else if((strcmp(_argv[ix], "--destport") == 0) || (strcmp(_argv[ix], "-p") == 0)){
				portLabel = ix;
				ix = ix + 2;
			}
		}
	} else {
		std::cerr 	<< "There's no arguments! Command should be:\n"
					<< _argv[0] << " --configuration <configuration file> --destip <destanation IP> --destport <destanation port>\nor "
					<< _argv[0] << " -c <configuration file> -i <destanation IP> -p <destanation port>";
		retValue = 0;
	}

	if(ipLabel != 0)
		_jsonObject->destEndpointAdr = _argv[ipLabel];

	if(portLabel != 0)
		_jsonObject->destEndpointPort = std::stoi(_argv[portLabel]);

	if(!confLabel){
		std::cerr 	<< "There's no configuration file! Command should be:\n"
							<< _argv[0] << " --configuration <configuration file> --destip <destanation IP> --destport <destanation port>\nor "
							<< _argv[0] << " -c <configuration file> -i <destanation IP> -p <destanation port>";
		retValue = 0;
	}

	return retValue;
}

void printStringVectorArr(std::vector<std::string> _vector){
	for(long long ix = 0; ix < _vector.size(); ++ix){
		std::cout << _vector[ix] << "; ";
	}
	std::cout << "\n";
}

std::string generateRandomHexString(long long _length){
	std::stringstream sstream;
	std::srand(std::time(NULL));

	for(long long ix = 0; ix<_length; ++ix){
		sstream << std::hex << std::rand()%16;
	}

	return sstream.str();
}
}
