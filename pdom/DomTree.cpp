/*
 *  DomTree.cpp
 *  pdom
 *
 *  Created by Piero Contezini on 22/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#include "DomTree.h"

DomTree::DomTree(const std::string& name, const std::string& encoding, const std::string& version) {
	this->name = name;
	this->encoding = encoding;
	this->version = version;
}

DomTree::~DomTree() {
	removeElements(elements);
	removeAttributes(attributes);
}

std::vector<DomElement *>& DomTree::getChildren() {
	return(elements);
}

std::vector<DomElement *>& DomTree::getElements() {
	return(elements);
}

void DomTree::setChildren(std::vector<DomElement *> value) {
	this->elements = value;
}

void DomTree::setElements(std::vector<DomElement *> value) {
	this->elements = value;
}

void DomTree::removeElements(std::vector<DomElement *> &children) {
	while(children.size()) {
		if(children[0]->getAttributes().size()) {
			removeAttributes(children[0]->getAttributes());
		}
		if(children[0]->getChildren().size())
			removeElements(children[0]->getChildren());
			delete children[0];
			children.erase(children.begin());
	}
}

DomElement *DomTree::createElement(const std::string& name) {
	return(newElement(name));
}

DomElement *DomTree::newElement(const std::string& name) {
	DomElement *new_element = new DomElement(name);
	elements.push_back(new_element);
	return(new_element);
}

std::vector<DomAttribute *>& DomTree::getAttributes() {
	return(attributes);
}

void DomTree::setAttributes(std::vector<DomAttribute *>value) {
	this->attributes = value;
}

void DomTree::removeAttributes(std::vector<DomAttribute *> &oldAttributes) {
	while(oldAttributes.size()) {
		delete oldAttributes[0];
		oldAttributes.erase(oldAttributes.begin());
	}
}

DomAttribute *DomTree::setAttribute(const std::string& name, const std::string& value) {
	DomAttribute *new_attribute;
	if(name.empty()) {
		return(new_attribute);
	}
	
	new_attribute = new DomAttribute(name,value);
	attributes.push_back(new_attribute);
	
	return(new_attribute);
}

DomAttribute *DomTree::setAttribute(DomAttribute *attribute) {
	attributes.push_back(attribute);
	return(attribute);
}

const std::string& DomTree::getName() const {
	return(this->name);
}

void DomTree::setName(const std::string& name) {
	this->name = name;
}

const std::string& DomTree::getEncoding() const {
	return(this->encoding);
}

void DomTree::setEncoding(const std::string& encoding) {
	this->encoding = encoding;
}

const std::string& DomTree::getVersion() const {
	return(this->version);
}

void DomTree::setVersion(const std::string& version) {
	this->version = version;
}

void DomTree::dumpTree() const {
	std::cout << "root: " << name << " encoding: " << encoding << " version: " << version << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;
	for(unsigned int i = 0; i < elements.size() ; i++) {
		int entrylevel = 0;
		DomElement *ptr = elements[i];
		std::cout << "element: " << ptr->getName() << " value: " << ptr->getValue() << std::endl;
		if ( ptr->getChildren().size() > 0 ) {
			for(unsigned int a = 0; a < ptr->getChildren().size() ; a++) {
				dumpChildren(ptr->getChildren()[a],entrylevel);
			}
		}
		for(unsigned int c = 0; c < ptr->getAttributes().size() ; c++ ) {
			DomAttribute *aptr = ptr->getAttributes()[c];
			std::cout << "attribute: " << aptr->getName() << " value: " << aptr->getValue() << std::endl;
		}
		std::cout << "---------------------------------------------" << std::endl;
	}
}

void DomTree::dumpChildren(DomElement *c,int entrylevel) const {
	entrylevel++;
	std::cout << "==================================" << std::endl;
	std::cout << entrylevel << "name: " << c->getName() << " value: " << c->getValue() << std::endl;
	if(c->getAttributes().size() > 0) {
		for(unsigned int a = 0; a < c->getAttributes().size() ; a++) {
			std::cout << entrylevel << " attribute: " << c->getAttributes()[a]->getName() << " value: " << c->getAttributes()[a]->getValue() << std::endl;
		}
	}
	if(c->getChildren().size() > 0) {
		for(unsigned int i = 0; i < c->getChildren().size() ; i++) {
			dumpChildren(c->getChildren()[i],entrylevel);
		}
	}
	std::cout << "==================================" << std::endl;
}

void DomTree::dumpXmlChild(xmlNodePtr parent,DomElement *c) const {
	xmlNodePtr child;
	child = xmlNewChild(parent,NULL,(const xmlChar *)c->getName().c_str(),(xmlChar *)c->getValue().c_str());
	if(c->getAttributes().size() > 0) {
		for(unsigned int a = 0; a < c->getAttributes().size() ; a++) {
			xmlSetProp(child,(const xmlChar *)c->getAttributes()[a]->getName().c_str(),(const xmlChar *)c->getAttributes()[a]->getValue().c_str());
		}
	}
	if(c->getChildren().size() > 0) {
		for(unsigned int i = 0; i < c->getChildren().size() ; i++) {
			dumpXmlChild(child,c->getChildren()[i]);
		}
	}
}

void DomTree::dumpXml() const {
	xmlDocPtr doc;
	xmlNodePtr cur;
	
	doc = xmlNewDoc((const xmlChar *)version.c_str());
	doc->children = xmlNewDocNode(doc, NULL,(const xmlChar *)name.c_str(), NULL);
	
	for(unsigned int i = 0; i < elements.size() ; i++) {
		cur = xmlNewChild(doc->children,NULL,(const xmlChar *)elements[i]->getName().c_str(),(xmlChar *)elements[i]->getValue().c_str());
		if(elements[i]->getAttributes().size() > 0) {
			for(unsigned int a = 0; a < elements[i]->getAttributes().size() ; a++) {
				xmlSetProp(cur,(const xmlChar *)elements[i]->getAttributes()[a]->getName().c_str(),(const xmlChar *)elements[i]->getAttributes()[a]->getValue().c_str());
			}
		}
		if ( elements[i]->getChildren().size() > 0 ) {	
			for(unsigned int b = 0; b < elements[i]->getChildren().size() ; b++) {
				dumpXmlChild(cur,elements[i]->getChildren()[b]);
			}
		}
	}
	
	xmlChar *output;
	int len;
	
	xmlDocDumpFormatMemory(doc, &output, &len,1);
	
	std::cout << output << std::endl;
	
	xmlFreeDoc(doc);
	xmlFree(output);
	
}

char *DomTree::dumpXmlStr() const {
	xmlDocPtr doc;
	xmlNodePtr cur;
	
	doc = xmlNewDoc((const xmlChar *)version.c_str());
	doc->children = xmlNewDocNode(doc, NULL,(const xmlChar *)name.c_str(), NULL);
	
	for(unsigned int i = 0; i < elements.size() ; i++) {
		cur = xmlNewChild(doc->children,NULL,(const xmlChar *)elements[i]->getName().c_str(),(xmlChar *)elements[i]->getValue().c_str());
		if(elements[i]->getAttributes().size() > 0) {
			for(unsigned int a = 0; a < elements[i]->getAttributes().size() ; a++) {
				xmlSetProp(cur,(const xmlChar *)elements[i]->getAttributes()[a]->getName().c_str(),(const xmlChar *)elements[i]->getAttributes()[a]->getValue().c_str());
			}
		}
		if ( elements[i]->getChildren().size() > 0 ) {	
			for(unsigned int b = 0; b < elements[i]->getChildren().size() ; b++) {
				dumpXmlChild(cur,elements[i]->getChildren()[b]);
			}
		}
	}
	
	xmlChar *output;
	int len;
	//len = sizeof(doc);
	xmlDocDumpFormatMemory(doc, &output, &len,1);
	
	xmlFreeDoc(doc);
	return((char *)output);
}

char *DomTree::xml(bool indent) {
	xmlDocPtr doc;
	xmlNodePtr cur;
	
	doc = xmlNewDoc((xmlChar *)version.c_str());

	doc->children = xmlNewDocNode(doc, NULL,(const xmlChar *)name.c_str(), NULL);
	
	for(unsigned int i = 0; i < attributes.size() ; i++) {
		xmlSetProp(doc->children,(const xmlChar *)attributes[i]->getName().c_str(),(const xmlChar *)attributes[i]->getValue().c_str());
	}
	
	for(unsigned int i = 0; i < elements.size() ; i++) {
		cur = xmlNewChild(doc->children,NULL,(const xmlChar *)elements[i]->getName().c_str(),(xmlChar *)elements[i]->getValue().c_str());
		if(elements[i]->getAttributes().size() > 0) {
			for(unsigned int a = 0; a < elements[i]->getAttributes().size() ; a++) {
				xmlSetProp(cur,(const xmlChar *)elements[i]->getAttributes()[a]->getName().c_str(),(const xmlChar *)elements[i]->getAttributes()[a]->getValue().c_str());
			}
		}
		if ( elements[i]->getChildren().size() > 0 ) {	
			for(unsigned int b = 0; b < elements[i]->getChildren().size() ; b++) {
				dumpXmlChild(cur,elements[i]->getChildren()[b]);
			}
		}
	}
	
	xmlChar *output;
	int len;
	// len =sizeof(len);
	if(indent) {
		xmlDocDumpFormatMemoryEnc(doc, &output, &len , (char *)encoding.c_str(),1);
	} else {
		xmlDocDumpFormatMemoryEnc(doc, &output, &len,(char *)encoding.c_str(),0);
	}
	
	xmlFreeDoc(doc);
	xmlCleanupParser();
	
	return((char *)output);
}

bool DomTree::write(const std::string& file, bool indent) {
	xmlDocPtr doc;
	xmlNodePtr cur;
	//xmlAttrPtr attr;
	
	doc = xmlNewDoc((const xmlChar *)version.c_str());
	doc->children = xmlNewDocNode(doc, NULL,(const xmlChar *)name.c_str(), NULL);
	
	for(unsigned int i = 0; i < attributes.size() ; i++) {
		xmlSetProp(doc->children,(const xmlChar *)attributes[i]->getName().c_str(),(const xmlChar *)attributes[i]->getValue().c_str());
	}
	
	for(unsigned int i = 0; i < elements.size() ; i++) {
		cur = xmlNewChild(doc->children,NULL,(const xmlChar *)elements[i]->getName().c_str(),(xmlChar *)elements[i]->getValue().c_str());
		if(elements[i]->getAttributes().size() > 0) {
			for(unsigned int a = 0; a < elements[i]->getAttributes().size() ; a++) {
				xmlSetProp(cur,(const xmlChar *)elements[i]->getAttributes()[a]->getName().c_str(),(const xmlChar *)elements[i]->getAttributes()[a]->getValue().c_str());
			}
		}
		if ( elements[i]->getChildren().size() > 0 ) {	
			for(unsigned int b = 0; b < elements[i]->getChildren().size() ; b++) {
				dumpXmlChild(cur,elements[i]->getChildren()[b]);
			}
		}
	}
	
	if((xmlSaveFormatFile((const char *)file.c_str(),doc,indent)) < 1) {
		
		std::cout << "Error writing to file" << std::endl;
		
		xmlFreeDoc(doc);
		xmlCleanupParser();
		return(false);
	}
		
	xmlFreeDoc(doc);
	xmlCleanupParser();
	return(true);
}	

bool DomTree::load(const std::string& file) {
	xmlDocPtr doc;
	xmlNodePtr cur;
	xmlAttrPtr attr;
	
	doc = xmlParseFile((const char *)file.c_str());
	
	if(doc == NULL) {
		return(false);
	}
	
	if(doc->version) {
		version = (char *)doc->version;
	}
	if(doc->encoding)
		encoding = (char *)doc->encoding;
	
	cur = xmlDocGetRootElement(doc);
	
	if(cur == NULL) {
		return(false);
	}
	
	name = (char *)cur->name;
	
	attr = cur->properties;
	
	std::string name,value;
	while(attr) {
		name = (char *)attr->name;
		value = (char *)attr->children->content;
		setAttribute(name,value);
		attr = attr->next;
	}

	cur = cur->children;
	
	parseChildren(doc,cur,NULL);
	
	xmlFreeDoc(doc);
	xmlCleanupParser();
	return(true);
	
}

bool DomTree::load(char *buffer, int len) {
	xmlDocPtr doc;
	xmlNodePtr cur;
	xmlAttrPtr attr;
	
	doc = xmlParseMemory(buffer,len);
	
	
	if(doc == NULL) {
		return(false);
	}
	
	if(doc->version)
		version = (char *)doc->version;
	if(doc->encoding)
		encoding = (char *)doc->encoding;
	
	
	cur = xmlDocGetRootElement(doc);
	
	if(cur == NULL) {
		return(false);
	}
	
	name = (char *)cur->name;
	
	attr = cur->properties;
	
	while(attr) {
		std::string name = (char *)attr->name;
		std::string value = (char *)attr->children->content;
		setAttribute(name,value);
		attr = attr->next;
	}
	
	cur = cur->children;
	
	parseChildren(doc,cur,NULL);
	
	xmlFreeDoc(doc);
	xmlCleanupParser();
	return(true);
	
}

void DomTree::parseChildren(xmlDocPtr doc, xmlNodePtr child, DomElement *parent) {
	xmlNode *cur_node = NULL;
	DomElement *new_element;
	xmlAttrPtr attr;
	
	
	for(cur_node = child ; cur_node ; cur_node = cur_node->next ) {
		if( cur_node->type == XML_ELEMENT_NODE) {
			if(!parent) {
				new_element = newElement((char *)cur_node->name);
			} else {
				new_element = parent->newElement((char *)cur_node->name);
			}
		} else if (cur_node->type == XML_TEXT_NODE && xmlIsBlankNode(cur_node)==0) {
			parent->setValue((char *)cur_node->content);
		}
		parseChildren(doc,cur_node->children,new_element);
		attr = cur_node->properties;
		while(attr) {
			std::string name = (char *)attr->name;
			std::string value = (char *)attr->children->content;
			new_element->setAttribute(name,value);
			attr = attr->next;
		}
	}
}

bool DomTree::elementExist(const std::string& name) const {
	for(unsigned int i = 0; i < elements.size() ; i++) {
		if(elements[i]->getName() == name ) {
			return(true);
		}
	}
	return(false);
}

void DomTree::clearChildren() {
	while(elements.size()) {
		if(elements[0]->getAttributes().size()) {
			removeAttributes(elements[0]->getAttributes());
		}
		if(elements[0]->getChildren().size())
			removeElements(elements[0]->getChildren());
		delete elements[0];
		elements.erase(elements.begin());
	}
}

bool DomTree::hasChildNodes() const {
	return (elements.size() > 0);
}

void DomTree::pushElement(DomElement *newElement) {
	elements.push_back(newElement);
}

int DomTree::getChildrenCount() const {
	return(elements.size());
}

DomElement *DomTree::getChild(int index) {
	if(index > elements.size()-1) {
		return(NULL);
	}
	return(elements[index]);
}
