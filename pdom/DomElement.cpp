/*
 *  DomElement.cpp
 *  pdom
 *
 *  Created by Piero Contezini on 22/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#include "DomElement.h"

DomElement::DomElement(const std::string& name) {
//	printf("criando element\n");
	setName(name);
	namespaceURI = "";
}

void DomElement::setName(const std::string& name){ 
	this->name = name;
}

std::string DomElement::getName() const {
	if(namespaceURI.size()) { // se temos namespace, o elemento precisa ter o prefixo
		return(this->namespaceURI + ":" + this->name);
	}
	return(this->name);
}

const std::string& DomElement::getLocalName() const {
	return(this->name);
}

void DomElement::setValue(const std::string& value) {
	this->value = value;
}

const std::string& DomElement::getValue() const {
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

bool DomElement::setAttribute(const std::string& name, const std::string& value) {
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

bool DomElement::setAttributeValue(const std::string& name, const std::string& value) {
	for(unsigned int i = 0; i < attributes.size() ; i++ ) {
		if( attributes[i]->getName() == name ) {
			attributes[i]->setValue(value);
			return(true); // atributo foi reescrito
		}
	}
	return(false);
}
	

void DomElement::setAttribute(DomAttribute *newAttribute) {
	attributes.push_back(newAttribute);
}

DomElement *DomElement::newElement(const std::string& name) {
	DomElement *new_element;
	if(name.empty()) {
		return(new_element);
	}
	
	new_element = new DomElement(name);
	elements.push_back(new_element);
	
	return(new_element);
	
}

std::string DomElement::getAttribute(const std::string& name) const {
	for(unsigned int i = 0; i < attributes.size() ; i++ ) {
		if( attributes[i]->getName() == name ) {
			return(attributes[i]->getValue()); // atributo foi reescrito
		}
	}
	return(""); // attributo nao existe = string vazia
}

const std::string& DomElement::getNamespaceURI() const {
	return(namespaceURI);
}

void DomElement::setNamespaceURI(const std::string& namespaceURI) {
	this->namespaceURI = namespaceURI;
}

std::string DomElement::getAttributeNS(const std::string& name, const std::string& NS) const {
	for(unsigned int i = 0; i < attributes.size() ; i++ ) {
		if( attributes[i]->getName() == name && attributes[i]->getNamespaceURI() == NS) {
			return(attributes[i]->getValue()); // atributo foi reescrito
		}
	}
	return(""); // attributo nao existe = string vazia
}

void DomElement::setAttributeNS(const std::string& name, const std::string& NS, const std::string& value) {
	for(unsigned int i = 0; i < attributes.size() ; i++ ) {
		if( attributes[i]->getName() == name && attributes[i]->getNamespaceURI() == NS) {
			attributes[i]->setValue(value); // atributo foi reescrito
		}
	}
	DomAttribute *newAttribute = new DomAttribute(name,NS,value);
	attributes.push_back(newAttribute);
}
	
bool DomElement::removeAttribute(const std::string& name) {
	for(unsigned int i = 0; i < attributes.size() ; i++ ) {
		if( attributes[i]->getName() == name ) {
			attributes.erase(attributes.begin() + i);
			return(true);
		}
	}
	return(false); // attributo nao existe = string vazia
}

void DomElement::pushElement(DomElement *newElement) {
	elements.push_back(newElement);
}
