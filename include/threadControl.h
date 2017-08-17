/*
 * threadControl.h
 *
 *  Created on: 21 мая 2017 г.
 *      Author: root
 */

#ifndef INCLUDE_THREADCONTROL_H_
#define INCLUDE_THREADCONTROL_H_

#include "stdlibrary.h"
#include "extlibrary.h"
#include "staticFunction.h"

namespace threadControl{

class httpThread{
private:
	int threadNum;
	int threadType;
	std::string url;

	int stopLabel;
protected:
	void runClient(int, std::string, std::string _data);
	void runServer(int, int);
public:
	void setStopLabel(int);

	httpThread();
	httpThread(int, int, std::string);
};

static void clientEvent_handler(struct mg_connection*, int, void*);
static void serverEvent_handler(struct mg_connection*, int, void*);

//std::vector<httpThread> httpThreads;
//std::vector<int> threadStop;

}

#endif /* INCLUDE_THREADCONTROL_H_ */
