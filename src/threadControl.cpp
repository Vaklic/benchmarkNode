/*
 * threadControl.c
 *
 *  Created on: 21 мая 2017 г.
 *      Author: root
 */

#include "../include/threadControl.h"

namespace threadControl{

static void clientEvent_handler(struct mg_connection *_c, int _ev, void *_p){
  struct http_message *hm = (struct http_message *) _p;
  jsonMessage obj;
  if (_ev == MG_EV_HTTP_REPLY) {
    _c->flags |= MG_F_CLOSE_IMMEDIATELY;
    fwrite(hm->message.p, 1, hm->message.len, stdout);
    obj = staticfunction::parseJsonString(hm->message.p);
    putchar('\n');
    httpThreads[obj.thread].setStopLabel(1);
    if(obj.messageType == "stop") threadStop[obj.thread] = 0;
  } else if (_ev == MG_EV_CLOSE) {
	fwrite(hm->message.p, 1, hm->message.len, stdout);
	obj = staticfunction::parseJsonString(hm->message.p);
	httpThreads[obj.thread].setStopLabel(1);
  };
}

static void serverEvent_handler(struct mg_connection *_c, int _ev, void *_p){
	if (_ev == MG_EV_HTTP_REQUEST) {
		struct http_message *hm = (struct http_message *) _p;
		mg_send_head(_c, 200, hm->message.len, "Content-Type: application/json");
		mg_printf(_c, "%.*s", hm->message.len, hm->message.p);
	}
}

void httpThread::setStopLabel(int _var){
	this->stopLabel = _var;
}

void httpThread::runClient(int _threadNum, std::string _url, std::string _data){
	struct mg_mgr mgr;

	mg_mgr_init(&mgr, NULL);
	mg_connect_http(&mgr, clientEvent_handler, _url.c_str(), "Content-Type: application/json", _data.c_str());

	while(this->stopLabel == 0){
		mg_mgr_poll(&mgr, 100);
	}
	mg_mgr_free(&mgr);
}

void httpThread::runServer(int _threadNum, int _destPort){
	struct mg_mgr mgr;
	struct mg_connection *c;

	mg_mgr_init(&mgr, NULL);
	c = mg_bind(&mgr, std::to_string(_destPort).c_str(), serverEvent_handler);
	mg_set_protocol_http_websocket(c);

	for(;;){
		mg_mgr_poll(&mgr, 100);
	}

	mg_mgr_free(&mgr);
}

httpThread::httpThread(){
	this->threadNum = 1;
	this->threadType = 1;
	this->url = "http://127.0.0.1:8484/";
	this->stopLabel = 1;
}

httpThread::httpThread(int _threadNum, int _threadType, std::string _url):threadNum(_threadNum), threadType(_threadType), url(_url){
	this->stopLabel = 1;
}

}


