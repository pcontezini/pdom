/*
 *  DomDataHandler.h
 *  pdom
 *
 *  Created by Piero Contezini on 22/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#ifndef DOMDATAHANDLER_H
#define DOMDATAHANDLER_H

#include "pdom.h"

#pragma GCC visibility push(default)

class DomDataHandler {
public:
	virtual std::string getValue() = 0;
	virtual void setValue(std::string data) = 0;
	
	void setValue(int value);
	void setValue(float value);
	void setValue(double value);
	void setValue(time_t value, bool time);
	void setValue(long int value);
	void setValue(unsigned long long value);
	void setValue(in6_addr addr);
	
};

#pragma GCC visibility pop

#endif
