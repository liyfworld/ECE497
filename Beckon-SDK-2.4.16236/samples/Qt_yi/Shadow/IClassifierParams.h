/**************************************************************************************
Copyright © 2009 Omek Interactive Ltd. All Rights Reserved.

The coded instructions, statements, computer programs, and/or related material (collectively 
"Data") in these files contain unpublished information proprietary to Omek Interactive Ltd., 
("Omek") which is protected by national and international copyright laws and by international 
treaties.

The Data may not be disclosed or distributed to third parties, in whole or in part, without the 
prior written consent of Omek.

OMEK DOES NOT GUARANTEE NOR MAKE ANY REPRESENTATION REGARDING THE USE OF, OR THE RESULTS OF THE 
USE OF THE DATA OR OMEK'S SERVICES, IN TERMS OF CORRECTNESS, ACCURACY OR OTHERWISE. THE DATA IS 
LICENSED "AS IS" AND WITHOUT WARRANTY.   OMEK SPECIFICALLY DISCLAIMS ALL WARRANTIES OR CONDITIONS 
WITH RESPECT TO THE DATA OR THE USE OR OPERATION THEREOF, WHETHER EXPRESS, IMPLIED,STATUTOR, ARISING 
BY CUSTOM OR TRADE USAGE, OR OTHERWISE, INCLUDING WITHOUT LIMITATION THE IMPLIED WARRANTIES OF 
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR USE AND NONINFRINGEMENT. WITHOUT LIMITING THE 
FOREGOING, OMEK DOES NOT WARRANT THAT THE OPERATION OF THE DATA WILL BE UNINTERRUPTED OR ERROR FREE.

IN NO EVENT WILL OMEK, ITS LICENSORS OR SUPPLIERS BE LIABLE FOR ANY DIRECT OR INDIRECT DAMAGES, COSTS, 
CLAIMS OR EXPENSES (INCLUDING WITHOUT LIMITATION LOST REVENUE, PROFIT OR DATA OR OTHER SPECIAL, INDIRECT, 
CONSEQUENTIAL, INCIDENTAL OR PUNITIVE DAMAGES HOWEVER CAUSED AND REGARDLESS OF THE THEORY OF LIABILITY, 
WHETHER FOR BREACH OF CONTRACT, TORT, INFRINGEMENT OR OTHERWISE), EVEN IF OMEK HAS BEEN ADVISED OF THE 
POSSIBILITY OF SUCH DAMAGES.  
**************************************************************************************/
#pragma once

#include "Shadow/Platform.h"
#include "Shadow/ShadowDefines.h"
#include <vector>
#include <string>

using namespace std;

namespace Omek {

/** 
@brief structure containing gesture info found in classifier xml file.
*/
class _ShadowExport GestureInfo
{
public:
	
	GestureInfo():m_categoryName(""),m_gestureName(""),m_label(0){}

	GestureInfo(string categoryName, string gestureName, unsigned int label):m_categoryName(categoryName),m_gestureName(gestureName),m_label(label){}

	GestureInfo(const GestureInfo& other):m_categoryName(other.getCategoryName()),m_gestureName(other.getGestureName()),m_label(other.getLabel()){}

	string	getCategoryName() const {return m_categoryName;}

	string	getGestureName() const {return m_gestureName;}

	unsigned int getLabel() const {return m_label;}

	void setCategoryName(string categoryName) {m_categoryName = categoryName;}

	void setGestureName(string gesture) {m_gestureName = gesture;}

	void setLabel(unsigned int label) {m_label = label;}

protected:

	string m_categoryName;	
	string m_gestureName;
	unsigned int m_label;
};

/** 
@brief structure containing joint info found in classifier xml file.
*/
class _ShadowExport JointInfo
{

public:

	JointInfo(){}

	JointInfo(const JointInfo& joint);

	JointInfo(const std::string& name, bool useX, bool useY, bool useZ);

	virtual void clear();

	unsigned int getNumSelectedCoords() const {return m_numSelectedCoords;}

	const bool* getCoordFlags() const {return m_coordFlags;}

	const JointID getJointName() const {return m_jointName;}		

public:

	static const int NUM_OF_COORDINATES = 3;
	enum {COORD_X, COORD_Y, COORD_Z};

protected:

	JointID m_jointName;
	bool m_coordFlags[NUM_OF_COORDINATES];
	int m_numSelectedCoords;
};

/** 
@brief Interface for classifier parameters.
This interface gives access to a classifier XML file.
The classifier XML file defines the tracking data format, 
joints that are of interest, the number of frames, scaling options, etc.
*/
class IClassifierParams
{
public:
	virtual vector<GestureInfo> getGesturesInfo() const = 0;
	virtual vector<JointInfo> getJointsInfo() const = 0;
	virtual vector<string> getDependedGestures() const = 0;	
	virtual unsigned int getDataLength() const = 0;
	virtual unsigned int getSizePerFrame() const = 0;
	virtual string getModelFileName() const = 0;	
};

}

