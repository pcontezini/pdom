/*
 *  DomElement.h
 *  pdom
 *
 *  Created by Piero Contezini on 22/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#ifndef DOMELEMENT_H
#define DOMELEMENT_H

#include "pdom.h"
#include "DomDataHandler.h"
#include "DomAttribute.h"

#pragma GCC visibility push(default)

class DomElement : public DomDataHandler {
protected:
	std::vector<DomAttribute *> attributes;
	std::vector<DomElement *> elements;
	std::string name;
	std::string value;
	
	std::string namespaceURI;
	
public:
	DomElement(std::string name);
	void setName(std::string value);
	std::string getName();
	std::string getLocalName();
	
	void setValue(std::string value);
	std::string getValue();	
	
	std::vector<DomAttribute *>& getAttributes();
	std::vector<DomElement *>& getElements();
	std::vector<DomElement *>& getChildren(); // does the same thing
	
	void setAttributes(std::vector<DomAttribute *>value);
	void setElements(std::vector<DomElement *>value);
	
	// can create string arguments by parameter
	virtual bool setAttribute(std::string name, std::string value);
	// accepts a new attribute, then you can do newAttribute(new DomAttribute(name,NonStringData));
	void setAttribute(DomAttribute *newAttribute);
	bool setAttributeValue(std::string name, std::string value);
	std::string getAttribute(std::string name);
	bool removeAttribute(std::string name);
	
	std::string getAttributeNS(std::string name, std::string NS);
	void setAttributeNS(std::string name, std::string NS, std::string value);
	
	virtual DomElement *newElement(std::string name);
	void pushElement(DomElement *newElement);
	
	// DOM compatibility functions
	DomElement *insertBefore(DomElement *newChild, DomElement *refChild);
	DomElement *replaceChild(DomElement *newChild, DomElement *oldChild);
	DomElement *removeChild(DomElement *oldChild);
	DomElement *appendChild(DomElement *newChild);
	bool hasChildNodes();
	bool hasAttributes();
	
	std::string getNamespaceURI();
	void setNamespaceURI(std::string namespaceURI);
	
	
};

#pragma GCC visibility pop

#endif
