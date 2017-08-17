/*
 * controlTest.cpp
 *
 *  Created on: 27 апр. 2017 г.
 *      Author: root
 */

#include "../include/controlTest.h";

namespace benchLoadNode {

long long controlTest::readRWindowSize(void){
	std::fstream file;
	std::string text[3];

	file.open("/proc/sys/net/ipv4/tcp_rmem", std::ios::in);
	file >> text[0] >> text[1] >> text[2];
	file.close();

	return (long long)std::stoi(text[2]);
}

long long controlTest::readWWindowSize(void){
	std::fstream file;
	std::string text[3];

	file.open("/proc/sys/net/ipv4/tcp_wmem", std::ios::in);
	file >> text[0] >> text[1] >> text[2];

	file.close();

	return (long long)std::stoi(text[2]);
}

void controlTest::setReadWindowMaxSize(long long _var){
	this->readWindowMaxSize = _var;
}

void controlTest::setWriteWindowMaxSize(long long _var){
	this->writeWindowMaxSize = _var;
}

std::string controlTest::getProtocol(void){
	return this->protocol;
}

long long controlTest::getReadWindowMaxSize(void){
	return this->readWindowMaxSize;
}

long long controlTest::getWriteWindowMaxSize(void){
	return this->writeWindowMaxSize;
}

int controlTest::getWorkMode(void){
	return this->workMode;
}

std::string controlTest::getTestType(void){
	return this->testType;
}

std::string controlTest::getDestIp(void){
	return this->destIp;
}

int controlTest::getDestPort(void){
	return this->destPort;
}

long long controlTest::getTestTime(void){
	return this->testTime;
}

long long controlTest::getMessageSize(void){
	return this->messageSize;
}

int controlTest::getThreadsQuantity(void){
	return this->threadsQuantity;
}

std::string controlTest::getDestUrl(void){
	return this->destUrl;
}

long long controlTest::getTimeout(void){
	return this->timeout;
}

void controlTest::setProtocol(std::string _var){
	this->protocol = _var;
}

void controlTest::setWorkMode(int _var){
	this->workMode = _var;
}

void controlTest::setTestType(std::string _var){
	this->testType = _var;
}

void controlTest::setDestIp(std::string _var){
	this->destIp = _var;
}

void controlTest::setDestPort(int _var){
	this->destPort = _var;
}

void controlTest::setTestTime(long long _var){
	this->testTime = _var;
}

void controlTest::setMessageSize(long long _var){
	this->messageSize = _var;
}

void controlTest::setThreadsQuantity(int _var){
	this->threadsQuantity = _var;
}

void controlTest::setDestUrl(std::string _var){
	this->destUrl = _var;
}

void controlTest::setTimeout(long long _var){
	this->timeout = _var;
}

std::string controlTest::formUrl(std::string _protocol, std::string _ip, int _port){
	return _protocol + "://" + _ip + ":" + std::to_string(_port) + "/";
}

std::string controlTest::formMessage(long long _size){
	std::string retMessage = "";
	std::srand(std::time(NULL));
	for(long long ix = 0; ix < _size; ++ix){
		retMessage += std::rand()%10;
	}
	return retMessage;
}
/*
void controlTest::runThreads(void){
	if(this->workMode == 1){ 												//if client
		for(uint16_t ix = 0; ix < this->threads.size(); ++ix){
			this->endThreadFlag[ix] = 0;
			this->threads[ix].append(std::thread(clientThread, ix));
			this->threads[ix].detach();
		}
	}else if(this->workMode == 2){ 											//if server

	}else{

	}
}
*/

jsonMessage controlTest::parseJsonString(std::string _jsonStr){
	rapidjson::Document dom;
	dom.Parse(_jsonStr.c_str());

	jsonMessage jsonObject;
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

std::string controlTest::formJsonString(std::vector<std::string> _keys, std::vector<std::string> _value){
	rapidjson::StringBuffer jsonString;
	rapidjson::Writer<rapidjson::StringBuffer> writeJson(jsonString);

	writeJson.StartObject();
	for(int ix = 0; ix < _keys.size(); ++ix){
		writeJson.Key(_keys[ix].c_str());
		writeJson.String(_value[ix].c_str());
	}
	writeJson.EndObject();

	return jsonString.GetString();
}

std::string controlTest::getJsonString(	std::string _messageType, long long _packQuantity, std::string _srcIp,
										int _srcPort, int _threadNum, long long _packLoose, long double _latency, std::string _body){
	std::vector<std::string> keys;
	std::vector<std::string> value;

	keys.push_back("testType"); 		value.push_back(this->getTestType().c_str());
	keys.push_back("messageType"); 		value.push_back(_messageType.c_str());
	keys.push_back("timeout"); 			value.push_back(std::to_string(this->getTimeout()).c_str());
	keys.push_back("duration"); 		value.push_back(std::to_string(this->getTestTime()).c_str());
	keys.push_back("packQuantity"); 	value.push_back(std::to_string(_packQuantity).c_str());
	keys.push_back("threads"); 			value.push_back(std::to_string(this->getThreadsQuantity()).c_str());
	keys.push_back("thread"); 			value.push_back(std::to_string(_threadNum).c_str());
	keys.push_back("mesSize"); 			value.push_back(std::to_string(this->getMessageSize()).c_str());
	keys.push_back("writeThroughput"); 	value.push_back(std::to_string(this->getWriteWindowMaxSize()).c_str());
	keys.push_back("readThroughput"); 	value.push_back(std::to_string(this->getReadWindowMaxSize()).c_str());
	keys.push_back("destEndpointAdr"); 	value.push_back(this->getDestIp().c_str());
	keys.push_back("destEndpointPort");	value.push_back(std::to_string(this->getDestPort()).c_str());
	keys.push_back("srcEndpointAdr"); 	value.push_back(_srcIp.c_str());
	keys.push_back("srcEndpointPort");	value.push_back(std::to_string(_srcPort).c_str());
	keys.push_back("packLoss"); 		value.push_back(std::to_string(_packLoose).c_str());
	keys.push_back("latency"); 			value.push_back(std::to_string(_latency).c_str());
	keys.push_back("body"); 			value.push_back(_body.c_str());

	return this->formJsonString(keys, value);;
}

controlTest::controlTest(void) {
	this->protocol = "http";
	this->readWindowMaxSize = this->readRWindowSize();
	this->writeWindowMaxSize = this->readWWindowSize();
	this->workMode = 1;
	this->testType = "latency";
	this->destIp = "127.0.0.1";
	this->destPort = 8484;
	this->testTime = 7000;
	this->messageSize = 4096;
	this->threadsQuantity = 3;
	this->timeout = 5000;

	this->destUrl = this->formUrl(this->protocol, this->destIp, this->destPort);
	//this->threads.reserve(this->threadsQuantity);
}

/*
	std::string	mode;
	std::string	protocol;
	std::string	testType;
	long long	timeout;
	long long 	duration;
	long long 	mesSize;
	int 		threads;
	std::string	destEndpointAdr;
	int			destEndpointPort;
 */

controlTest::controlTest(configObject _jsonConfig){
	if(_jsonConfig.mode == "client") this->workMode = 1;
	else if(_jsonConfig.mode == "server") this->workMode = 2;
	else this->workMode = 0;
	this->protocol = _jsonConfig.protocol;
	this->testType = _jsonConfig.testType;
	this->timeout = _jsonConfig.timeout;
	this->testTime = _jsonConfig.duration;
	this->messageSize = _jsonConfig.mesSize;
	this->threadsQuantity = _jsonConfig.threads;
	this->destIp = _jsonConfig.destEndpointAdr;
	this->destPort = _jsonConfig.destEndpointPort;
	this->readWindowMaxSize = this->readRWindowSize();
	this->writeWindowMaxSize = this->readWWindowSize();

	this->destUrl = this->formUrl(this->protocol, this->destIp, this->destPort);
}

controlTest::controlTest(std::string _protocol = "http", int _workMode = 1, std::string _testType = "latency", long long _messageSize = 4096,
						int _threadsQuantity = 3, long long _testTime = 7000, long long _timeout = 5000, std::string _destIp = "127.0.0.1",
						int _destPort = 8484):protocol(_protocol),workMode(_workMode), destIp(_destIp), destPort(_destPort), testTime(_testTime),
						messageSize(_messageSize),threadsQuantity(_threadsQuantity),timeout(_timeout), testType(_testType){
	this->readWindowMaxSize = this->readRWindowSize();
	this->writeWindowMaxSize = this->readWWindowSize();

	this->destUrl = this->formUrl(this->protocol, this->destIp, this->destPort);
	//this->threads.reserve(this->threadsQuantity);
}

controlTest::~controlTest(void) {
/*	for(uint16_t ix = 0; ix < this->threads.size(); ++ix){
		delete(this->threads[ix]);
	}
*/
}

} /* namespace benchLoadNode */
