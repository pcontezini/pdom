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
private:
	std::vector<DomAttribute *> attributes;
	std::vector<DomElement *> elements;
	std::string name;
	std::string value;
	
public:
	DomElement(std::string name);
	void setName(std::string value);
	std::string getName();
	
	void setValue(std::string value);
	std::string getValue();	
	
	std::vector<DomAttribute *>& getAttributes();
	std::vector<DomElement *>& getElements();
	std::vector<DomElement *>& getChildren(); // does the same thing
	
	void setAttributes(std::vector<DomAttribute *>value);
	void setElements(std::vector<DomElement *>value);
	
	// can create string arguments by parameter
	bool setAttribute(std::string name, std::string value);
	// accepts a new attribute, then you can do newAttribute(new DomAttribute(name,NonStringData));
	bool setAttribute(DomAttribute *newAttribute);
	
	bool removeAttribute(std::string name);
	
	DomElement *newElement(std::string name);
	
	// DOM compatibility functions
	DomElement *insertBefore(DomElement *newChild, DomElement *refChild);
	DomElement *replaceChild(DomElement *newChild, DomElement *oldChild);
	DomElement *removeChild(DomElement *oldChild);
	DomElement *appendChild(DomElement *newChild);
	bool hasChildNodes();
	
	
};

#pragma GCC visibility pop

#endif
