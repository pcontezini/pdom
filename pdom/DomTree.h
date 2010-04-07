/*
 *  DomTree.h
 *  pdom
 *
 *  Created by Piero Contezini on 22/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#ifndef DOMTREE_H
#define DOMTREE_H


#include "pdom.h"
#include "DomAttribute.h"
#include "DomElement.h"

#pragma GCC visibility push(default)

class DomTree {
protected:
	std::vector<DomAttribute *> attributes;
	std::vector<DomElement *> elements;
	
	std::string name;
	std::string encoding;
	std::string version;
public:
	
	DomTree(const std::string& name, const std::string& encoding = "UTF-8", const std::string& version = "1.0");
	~DomTree();
	
	std::vector<DomElement *>& getChildren();
	std::vector<DomElement *>& getElements();
	void setChildren(std::vector<DomElement *> value);
	void setElements(std::vector<DomElement *> value);
	void removeElements(std::vector<DomElement *> &oldElements);
	DomElement *createElement(const std::string& name);
	virtual DomElement *newElement(const std::string& name);
	void pushElement(DomElement *newElement);
	
	bool hasChildNodes() const;
	int getChildrenCount() const;
	DomElement *getChild(int index);
	
	std::vector<DomAttribute *>& getAttributes();
	void setAttributes(std::vector<DomAttribute *>value);
	void removeAttributes(std::vector<DomAttribute *> &oldAttributes);

	virtual DomAttribute *setAttribute(const std::string& name, const std::string& value);
	DomAttribute *setAttribute(DomAttribute *attribute);
	
	const std::string& getName() const;
	void setName(const std::string& name);
	const std::string& getEncoding() const;
	void setEncoding(const std::string& encoding);
	const std::string& getVersion() const;
	void setVersion(const std::string& version);
	
	void dumpTree() const;
	void dumpChildren(DomElement *children, int entrylevel) const;
	void dumpXmlChild(xmlNodePtr parent, DomElement *child) const;
	void dumpXml() const;
	char *dumpXmlStr() const;
	char *xml(bool indent = false);
	bool write(const std::string& file, bool indent = true);
	bool load(const std::string& file);
	bool load(char *buffer, int len);
	virtual void parseChildren(xmlDocPtr doc, xmlNodePtr child, DomElement *parent);
	bool elementExist(const std::string& name) const;
	
	void clearChildren();
	
};

#pragma GCC visibility pop

#endif
