/*******************************************
 * Node.cpp
 *
 * Class Definition: Node non-adt for queue implementation
 *
 * Created on: 
 * Author: 
 ********************************************/

#include <cstdio>  // Needed for NULL
#include "Node.h"

Node::Node()
{
	data = 0;
	next = NULL;
}

Node::Node(int theData)
{
	data = thedata;
	next = NULL;
}

Node::Node(int theData, Node* theNextNode)
{
	data = thedata;
	next = theNextNode;
}

Node::setNodeData(int thedata)
{
	data = thedata;
}

Node::setNodeNext(Node* theNextNode)
{
	next = theNextNode;
}

Node::getNodeData(int thedata)
{
	return(data);
}
