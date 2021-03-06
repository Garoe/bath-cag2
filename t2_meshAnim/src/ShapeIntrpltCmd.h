#ifndef SHAPEINTRPLCMD_H
#define SHAPEINTRPLCMD_H

#include <vector>

#include <maya/MPxCommand.h>
#include <maya/MDGModifier.h>
#include <maya/MDagPath.h>
#include <maya/MFnSet.h>
#include <maya/MFnDagNode.h>

class ShapeIntrpltCmd : public MPxCommand
{
public:
	virtual MStatus	doIt(const MArgList&);
	virtual MStatus undoIt();
	virtual MStatus redoIt();
	virtual bool isUndoable() const { return true; }

	static void *creator() { return new ShapeIntrpltCmd; }
	static MSyntax newSyntax();

private:
	void duplicateMesh(MFnSet &shadingGroupFn, MDagPath &sourceShapePath,
		MDagPath &targetShapePath);

private:
	MDGModifier dgMod;

	MString newNodeName;

	MObject newMesh;
	bool doMeshUndo;
};

#endif
