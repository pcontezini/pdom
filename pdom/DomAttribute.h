/*
 *  DomAttribute.h
 *  pdom
 *
 *  Created by Piero Contezini on 22/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */
#ifndef DOMATTRIBUTE_H
#define DOMATTRIBUTE_H

#include "pdom.h"
#include "DomDataHandler.h"

#pragma GCC visibility push(default)

class DomAttribute : public DomDataHandler {
public:
	DomAttribute(std::string name, std::string value);
	void setName(std::string value);
	std::string getName();

	void setValue(std::string value);
	std::string getValue();
	
private:
	std::string name;
	std::string value;
};
	
#pragma GCC visibility pop

#endif
