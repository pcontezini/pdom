/*
 *  DomDataHandler.cpp
 *  pdom
 *
 *  Created by Piero Contezini on 22/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#include "DomDataHandler.h"

DomDataHandler::~DomDataHandler() {

}

void DomDataHandler::setValue(int value) {
	char tmp[64];
	snprintf(tmp,63,"%d",value);
	std::string senddata = tmp;
	setValue(senddata);
}

void DomDataHandler::setValue(float value) {
	char tmp[64];
	snprintf(tmp,63,"%f",value);
	std::string senddata = tmp;
	setValue(senddata);
}

void DomDataHandler::setValue(double value) {
	char tmp[64];
	snprintf(tmp,63,"%f",value);
	std::string senddata = tmp;
	setValue(senddata);
}

// this is just a little "fix" to work with timestamps diferently from long its
void DomDataHandler::setValue(time_t value, bool time) {
	char tmp[64];
	struct tm *mytm;
	mytm = localtime(&value);
	strftime(tmp,63,"%d-%m-%Y %H:%M:%S",mytm);
	std::string senddata = tmp;
	setValue(senddata);
}

void DomDataHandler::setValue(long int value) {
	char tmp[64];
	snprintf(tmp,63,"%ld",value);
	std::string senddata = tmp;
	setValue(senddata);
}

void DomDataHandler::setValue(unsigned long long value) {
	char tmp[64];
	snprintf(tmp,63,"%7Ld",value);
	std::string senddata = tmp;
	setValue(senddata);
}

void DomDataHandler::setValue(in6_addr addr) {
	char tmp[128];
	char *p = tmp;
	inet_ntop(AF_INET6,&addr,p,127);
	std::string senddata = tmp;
	setValue(senddata);
}
