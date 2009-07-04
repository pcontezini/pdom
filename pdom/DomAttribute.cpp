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
	if(namespaceURI.size()) { // se temos namespace, o elemento precisa ter o prefixo
		return(this->namespaceURI + ":" + this->name);
	}
	
	return(this->name);	
}

std::string DomAttribute::getLocalName() {
	return(this->name);	
}

void DomAttribute::setValue(std::string value) {
	this->value = value;
}

std::string DomAttribute::getValue() {
	return(this->value);
}

std::string DomAttribute::getNamespaceURI() {
	return(namespaceURI);
}

void DomAttribute::setNamespaceURI(std::string namespaceURI) {
	this->namespaceURI = namespaceURI;
}

DomAttribute::DomAttribute(std::string name, std::string value, std::string namespaceURI) {
	setName(name);
	setValue(value);
	setNamespaceURI(namespaceURI);
}
