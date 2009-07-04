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
private:
	std::vector<DomAttribute *> attributes;
	std::vector<DomElement *> elements;
	std::string name;
	std::string encoding;
	std::string version;
public:
	DomTree(std::string name, std::string encoding = "UTF-8" , std::string version = "1.0" );
	~DomTree();
	
	std::vector<DomElement *>& getChildren();
	std::vector<DomElement *>& getElements();
	void setChildren(std::vector<DomElement *> value);
	void setElements(std::vector<DomElement *> value);
	void removeElements(std::vector<DomElement *> &oldElements);
	DomElement *createElement(std::string name);
	DomElement *newElement(std::string name);
	
	bool hasChildNodes();
	
	std::vector<DomAttribute *>& getAttributes();
	void setAttributes(std::vector<DomAttribute *>value);
	void removeAttributes(std::vector<DomAttribute *> &oldAttributes);
//	DomAttribute *setAttribute(std::string name);
	DomAttribute *setAttribute(std::string name, std::string value);
	DomAttribute *setAttribute(DomAttribute *attribute);
	
	std::string getName();
	void setName(std::string name);
	std::string getEncoding();
	void setEncoding(std::string encoding);
	std::string getVersion();
	void setVersion(std::string version);
	
	void dumpTree();
	void dumpChildren(DomElement *children, int entrylevel);
	void dumpXmlChild(xmlNodePtr parent, DomElement *child);
	void dumpXml();
	char *dumpXmlStr();
	char *xml(bool indent = false);
	bool write(std::string file, bool indent = true);
	bool load(std::string file);
	bool load(char *buffer, int len);
	void parseChildren(xmlDocPtr doc, xmlNodePtr child, DomElement *parent);
	bool elementExist(std::string name);
	
	void clearChildren();
	
};

#pragma GCC visibility pop

#endif
