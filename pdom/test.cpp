#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#include <time.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

#include <DomTree.h>

using namespace std;

int main(int argc, char *argv[]) {
	DomTree *newTree = new DomTree("testeidasdasda","UTF-8","1.0");

	printf("tree: %s\n", newTree->getName().c_str());

	DomElement *element = newTree->newElement("blah");
	element->setNamespaceURI("prefixo");
	element->setAttributeNS("superteste","ativar","atributoprefixo");
	element->setAttribute("outroteste","blah");
	DomElement *childElement = element->newElement("childblah");

	childElement->setValue("blahblah");
	newTree->dumpTree();
	newTree->write("teste.xml",true);
}
