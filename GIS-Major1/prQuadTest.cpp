/*
 *  prQuadTest.cpp
 *  GIS-PRQuad
 *
 *  Created by Kevin  Denny on 10/27/05.
 *  Copyright 2005 __MyCompanyName__. All rights reserved.
 *
 */
#include <iostream>
#include <ostream>
#include "Singleton.h"
#include "prQuadTree.h"
#include "prQuadNode.h"
#include "prQuadInternal.h"
#include "prQuadLeaf.h"
#include "geoRecord.h"


int main()
{
	 
	geoRecord* rec1 = new geoRecord();
	geoRecord* rec2 = new geoRecord();
	prQuadTree<geoRecord>* tree = new prQuadTree<geoRecord>("0810000W", "0790000W", "360000N", "380000N");
	rec1->setFid("1495182");
	rec1->setOffset( 0 );
	
	rec2->setFid("1481269");
	rec2->setOffset( 215 );
	
	double x1 = (80*3600) + (16*60) + (8);
	double y1 = (37*3600) + (16*60) + (36);
	double y2 = 134456;
	double x2 = 288058;
	rec1->totalSecy(y1);
	rec1->totalSecx(x1);
	rec2->totalSecx(x2);
	rec2->totalSecy(y2);
	tree->Insert(*rec1);
	tree->Insert(*rec2);
	//ostream& Out;
	//tree->Display(cout);
	
	
}

