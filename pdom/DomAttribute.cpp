/*
 *  DomAttribute.cpp
 *  pdom
 *
 *  Created by Piero Contezini on 22/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#include "DomAttribute.h"


void DomAttribute::setName(const std::string& name) { 
	this->name = name;
}

std::string DomAttribute::getName() const {
	if(namespaceURI.size()) { // se temos namespace, o elemento precisa ter o prefixo
		return(this->namespaceURI + ":" + this->name);
	}
	
	return(this->name);	
}

const std::string& DomAttribute::getLocalName() const {
	return(this->name);	
}

void DomAttribute::setValue(const std::string& value) {
	this->value = value;
}

const std::string& DomAttribute::getValue() const {
	return(this->value);
}

const std::string& DomAttribute::getNamespaceURI() const {
	return(namespaceURI);
}

void DomAttribute::setNamespaceURI(const std::string& namespaceURI) {
	this->namespaceURI = namespaceURI;
}

DomAttribute::DomAttribute(const std::string& name, const std::string& value, const std::string& namespaceURI) {
	setName(name);
	setValue(value);
	setNamespaceURI(namespaceURI);
}
