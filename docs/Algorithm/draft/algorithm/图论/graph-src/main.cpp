#include<iostream>
#include "graph.h"
#include "graph.cpp"
using namespace std;

void main()
{
	Digraph<5,int> mygraph;
	mygraph.read();
    mygraph.write();
}