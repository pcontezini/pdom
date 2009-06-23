/*
 *  DomAttribute.cpp
 *  pdom
 *
 *  Created by Piero Contezini on 22/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#include "DomAttribute.h"


void DomAttribute::setName(std::string name){ 
	this->name = name;
}

std::string DomAttribute::getName() {
	return(this->name);
}

void DomAttribute::setValue(std::string value) {
	this->value = value;
}

std::string DomAttribute::getValue() {
	return(this->value);
}

DomAttribute::DomAttribute(std::string name, std::string value) {
	setName(name);
	setValue(value);
}
