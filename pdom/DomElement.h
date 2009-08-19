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
	DomElement(const std::string& name);
	void setName(const std::string& value);
	std::string getName() const;
	const std::string& getLocalName() const;
	
	void setValue(const std::string& value);
	const std::string& getValue() const;	
	
	std::vector<DomAttribute *>& getAttributes();
	std::vector<DomElement *>& getElements();
	std::vector<DomElement *>& getChildren(); // does the same thing
	
	void setAttributes(std::vector<DomAttribute *>value);
	void setElements(std::vector<DomElement *>value);
	
	// can create string arguments by parameter
	virtual bool setAttribute(const std::string& name, const std::string& value);
	// accepts a new attribute, then you can do newAttribute(new DomAttribute(name,NonStringData));
	void setAttribute(DomAttribute *newAttribute);
	bool setAttributeValue(const std::string& name, const std::string& value);
	std::string getAttribute(const std::string& name) const;
	bool removeAttribute(const std::string& name);
	
	std::string getAttributeNS(const std::string& name, const std::string& NS) const;
	void setAttributeNS(const std::string& name, const std::string& NS, const std::string& value);
	
	virtual DomElement *newElement(const std::string& name);
	void pushElement(DomElement *newElement);
	
	// DOM compatibility functions
	DomElement *insertBefore(DomElement *newChild, DomElement *refChild);
	DomElement *replaceChild(DomElement *newChild, DomElement *oldChild);
	DomElement *removeChild(DomElement *oldChild);
	DomElement *appendChild(DomElement *newChild);
	bool hasChildNodes() const;
	bool hasAttributes() const;
	
	const std::string& getNamespaceURI() const;
	void setNamespaceURI(const std::string& namespaceURI);
};

#pragma GCC visibility pop

#endif
