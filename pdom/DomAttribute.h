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
	DomAttribute(std::string name, std::string value, std::string namespaceURI = "");
	void setName(std::string value);
	std::string getName();

	void setValue(std::string value);
	std::string getValue();
	
	void setNamespaceURI(std::string namespaceURI);
	std::string getNamespaceURI();
	
	std::string getLocalName();
	
private:
	std::string name;
	std::string value;
	std::string namespaceURI;	
};
	
#pragma GCC visibility pop

#endif
