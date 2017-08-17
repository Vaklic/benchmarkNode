/*
 * controlTest.h
 *
 *  Created on: 27 апр. 2017 г.
 *      Author: root
 */

#ifndef CONTROLTEST_H_
#define CONTROLTEST_H_

#include "stdlibrary.h";
#include "extlibrary.h";
#include "structures.h";
#include "threadControl.h";
//#include "include/staticFunction.h";

namespace benchLoadNode {

class controlTest {
private:
	long long readWindowMaxSize;
	long long writeWindowMaxSize;

	std::string protocol;
	int workMode;											//1 is client, 2 is server
	std::string testType;
	std::string destIp;
	int destPort;
	long long testTime;
	long long messageSize;
	int threadsQuantity;
	long long timeout;

	std::string destUrl;
protected:
	long long readRWindowSize(void);
	long long readWWindowSize(void);

	void setDestUrl(std::string);

	std::string formUrl(std::string, std::string, int);
	std::string formMessage(long long);
public:
	std::string getProtocol(void);
	long long getReadWindowMaxSize(void);
	long long getWriteWindowMaxSize(void);
	int getWorkMode(void);
	std::string getTestType(void);
	std::string getDestIp(void);
	int getDestPort(void);
	long long getTestTime(void);
	long long getMessageSize(void);
	int getThreadsQuantity(void);
	std::string getDestUrl(void);
	long long getTimeout(void);

	void setProtocol(std::string);
	void setReadWindowMaxSize(long long);
	void setWriteWindowMaxSize(long long);
	void setWorkMode(int);
	void setTestType(std::string);
	void setDestIp(std::string);
	void setDestPort(int);
	void setTestTime(long long);
	void setMessageSize(long long);
	void setThreadsQuantity(int);
	void setTimeout(long long);

	void runThreads(void);

	jsonMessage parseJsonString(std::string);
	std::string formJsonString(std::vector<std::string>, std::vector<std::string>);
	std::string getJsonString(std::string, long long, std::string, int, int, long long, long double, std::string);

	controlTest(void);
	controlTest(configObject);
	controlTest(std::string, int, std::string, long long, int, long long, long long, std::string, int);
	virtual ~controlTest(void);
};

} /* namespace benchLoadNode */

#endif /* CONTROLTEST_H_ */
