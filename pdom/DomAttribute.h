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
	DomAttribute(const std::string& name, const std::string& value, const std::string& namespaceURI = "");
	void setName(const std::string& value);
	std::string getName() const;

	void setValue(const std::string& value);
	const std::string& getValue() const;
	
	void setNamespaceURI(const std::string& namespaceURI);
	const std::string& getNamespaceURI() const;
	
	const std::string& getLocalName() const;
	
private:
	std::string name;
	std::string value;
	std::string namespaceURI;	
};
	
#pragma GCC visibility pop

#endif
