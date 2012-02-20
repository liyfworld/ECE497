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

#include "Shadow/ShadowDefines.h"
#include "Shadow/IFiredEvent.h"
#include "Shadow/IGestureListener.h"
#include "Shadow/IClassifierParams.h"
#include <list>

using namespace std;

namespace Omek {

/** 
	@class IClassifier IClassifier.h "include/Shadow/IClassifier.h"
	
	@brief Interface for a gesture classifier functionality 

	This interface should be implemented in order to create a coded gesture.
	The "classify" method is called by the SDK at every frame, getting as input the tracking data,
	and setting as output the label of the detected class.
	The tracking data format is defined by the XML file, which describes this classifier.
	This XML determines the joint that are of interest, the number of frames, scaling options, etc.
*/
class _ShadowExport IClassifier : public IGestureListener
{
public:

	/// Default Ctor, creates an empty classifier
	IClassifier():m_classifierParams(NULL), m_isReady(false){}
	
	/// Creates a classifier, given as input the size of the  data buffer
	/// @param[in] classifierParams set of classifier parameters @see IClassifierParams
	IClassifier(const IClassifierParams* classifierParams):m_classifierParams(classifierParams), m_isReady(false){}
	
	virtual ~IClassifier();

	/// @brief Perform the classification of the given data
	/// Given a data buffer, this classifier applies the most likely class label to the data
	/// @param[in] data the input buffer, holding the tracking information that is needed for the classification
	/// @param[out] classLabel assigned according to the most likely class
	virtual OMKStatus classify(const float* data, unsigned int playerLabel, int& classLabel, float& confidence) = 0;
	
	/// @return an indication if the classifier is ready to classify
	virtual bool isReady(){return m_isReady;}
	
	/// Load the classifier from a given file
	/// @param[in] fileName the path to the file that holds all the information needed for setting up the classifier
	virtual OMKStatus init(const char *fileName){fileName; m_isReady = true; return OMK_SUCCESS;}

	/// A callback method that is called whenever a dependent gesture is fired
	/// For example in the Composite gestures, this is used to register the basic gestures,
	/// upon which the composited gesture is defined
	/// @param[in] sender object holding the information about the fired gesture
	/// @see IGestureListener::onGesture
	virtual void onGesture(const IFiredEvent* gesture);

protected:
	/// Clears the list of fired-events 
	void clearFiredEventsList(unsigned int playerLabel);

	const IClassifierParams* m_classifierParams;
	bool m_isReady;		
	list<IFiredEvent*> m_firedGestures;
};

typedef IClassifier* (*CreateClassifier)(const IClassifierParams* cLassifierParams);
typedef void (*DeleteClassifier)(IClassifier* object);

}

