#ifndef SHAPEINTRPLNODE_H
#define SHAPEINTRPLNODE_H

#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MTypeId.h> 

class ShapeIntrpltNode : public MPxNode
{
public:
	virtual MStatus compute(const MPlug& plug, MDataBlock& data);

	static  void *creator();
	static  MStatus initialize();

	static const MTypeId id;

public:
	static MObject sourceSurface;
	static MObject targetSurface;
	static MObject outputSurface;
	static MObject interpolateValue;
};

#endif
