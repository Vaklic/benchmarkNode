/*
 * structures.h
 *
 *  Created on: 18 мая 2017 г.
 *      Author: root
 */

#ifndef INCLUDE_STRUCTURES_H_
#define INCLUDE_STRUCTURES_H_

/*
local JsonMesFormat = {
	"testType" = "latency"/"download"/"upload",			--string
	"messageType" = "setup"/"update"/"data"/"stop",		--string
	"timeout" = 500/2000/7000/etc,						--uint32_t
	"duration" = 3000/20000/120000/etc,					--uint32_t
	"packQuantity" = 10/333/1000/etc,					--uint64_t
	"threads" = 1/9/30/etc,								--uint16_t
	"thread" = 1/2/3/etc								--uint16_t
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

struct jsonMessage{
	std::string	testType;
	std::string	messageType;
	long long 	timeout;
	long long 	duration;
	long		packQuantity;
	int 		threads;
	int 		thread;
	long long 	mesSize;
	long long 	writeThroughput;
	long long 	readThroughput;
	std::string destEndpointAdr;
	int 		destEndpointPort;
	std::string	srcEndpointAdr;
	int 		srcEndpointPort;
	long long 	packLoss;
	long double latency;
	std::string body;

	std::vector<std::string> returnDataInString(void){
		std::vector<std::string> returnObject;

		returnObject.push_back(this->testType);
		returnObject.push_back(this->messageType);
		returnObject.push_back(std::to_string(this->timeout));
		returnObject.push_back(std::to_string(this->duration));
		returnObject.push_back(std::to_string(this->packQuantity));
		returnObject.push_back(std::to_string(this->threads));
		returnObject.push_back(std::to_string(this->thread));
		returnObject.push_back(std::to_string(this->mesSize));
		returnObject.push_back(std::to_string(this->writeThroughput));
		returnObject.push_back(std::to_string(this->readThroughput));
		returnObject.push_back(this->destEndpointAdr);
		returnObject.push_back(std::to_string(this->destEndpointPort));
		returnObject.push_back(this->srcEndpointAdr);
		returnObject.push_back(std::to_string(this->srcEndpointPort));
		returnObject.push_back(std::to_string(this->packLoss));
		returnObject.push_back(std::to_string(this->latency));
		returnObject.push_back(this->body);

		return returnObject;
	}
};

struct configObject{
	std::string	mode;
	std::string	protocol;
	std::string	testType;
	long long	timeout;
	long long 	duration;
	long long 	mesSize;
	int 		threads;
	long 		packQuantity;
	std::string	destEndpointAdr;
	int			destEndpointPort;

	std::vector<std::string> returnDataInString(void){
		std::vector<std::string> returnObject;

		returnObject.push_back(this->mode);
		returnObject.push_back(this->protocol);
		returnObject.push_back(this->testType);
		returnObject.push_back(std::to_string(this->timeout));
		returnObject.push_back(std::to_string(this->duration));
		returnObject.push_back(std::to_string(this->mesSize));
		returnObject.push_back(std::to_string(this->threads));
		returnObject.push_back(std::to_string(this->packQuantity));
		returnObject.push_back(this->destEndpointAdr);
		returnObject.push_back(std::to_string(this->destEndpointPort));

		return returnObject;
	}
};

#endif /* INCLUDE_STRUCTURES_H_ */
