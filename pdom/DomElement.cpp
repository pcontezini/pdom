/*
 *  DomElement.cpp
 *  pdom
 *
 *  Created by Piero Contezini on 22/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#include "DomElement.h"

DomElement::DomElement(std::string name) {
	setName(name);
}

void DomElement::setName(std::string name){ 
	this->name = name;
}

std::string DomElement::getName() {
	return(this->name);
}

void DomElement::setValue(std::string value) {
	this->value = value;
}

std::string DomElement::getValue() {
	return(this->value);
}

std::vector<DomAttribute *>& DomElement::getAttributes() { 
	return(attributes);
}
std::vector<DomElement *>& DomElement::getElements() { 
	return(elements); 
}

std::vector<DomElement *>& DomElement::getChildren() { 
	return(elements); 
}

void DomElement::setAttributes(std::vector<DomAttribute *> value) { 
	this->attributes = value; 
}

void DomElement::setElements(std::vector<DomElement *> value) { 
	this->elements = value; 
}

bool DomElement::setAttribute(std::string name, std::string value) {
	for(unsigned int i = 0; i < attributes.size() ; i++ ) {
		if( attributes[i]->getName() == name ) {
			attributes[i]->setValue(value);
			return(false); // atributo foi reescrito
		}
	}
	DomAttribute *new_attrib = new DomAttribute(name,value);
	attributes.push_back(new_attrib);
	return(true); // atributo foi adicionado	
}

DomElement *DomElement::newElement(std::string name) {
	DomElement *new_element;
	if(name.empty()) {
		return(new_element);
	}
	
	new_element = new DomElement(name);
	elements.push_back(new_element);
	
	return(new_element);
	
}
