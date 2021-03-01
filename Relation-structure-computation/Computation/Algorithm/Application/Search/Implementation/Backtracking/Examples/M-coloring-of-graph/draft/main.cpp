 #include "Connected_Graph.h"
#include "Connected_Graph.cpp"
#include<iostream>
using namespace std;


void main()
{
	Connected_Graph<5> mygraph;
	mygraph.read();
	mygraph.write();
	int m = 4;
	mygraph.mColoring(m);
}