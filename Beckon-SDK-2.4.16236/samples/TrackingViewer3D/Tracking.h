#ifndef TRACKING_H
#define TRACKING_H

/******************************************************************************/
/*                              Includes                                      */
/******************************************************************************/
#include <vector>
#include <string>

#include "Shadow/ISensor.h"
#include "Shadow/IMotionSensor.h"

/******************************************************************************/
/*                               Class definition                             */
/******************************************************************************/
using namespace Omek;

/**
 * @class Trackings
 * @brief The class encapsulates the SDK tracking functionality.
 */
class Tracking
{
    
public:

	/// Constructor.
 	Tracking();	
	/// Destructor.
    ~Tracking();	

	/**
	 * Initializes the SDK tracking functionality.
	 * @param sequenceFileName  the full path to a folder containing camera sequences;
	 * 							if the path empty (NULL) an input from camera will be used.
	 * @return true if success; false if failed.
	 */ 
    bool initialize(char* sequenceFileName);

	/**
	 * Grabs new frame from camera/sequence(if available) and computes skeleton
	 * for the current frame.
	 * @return true if camera is alive/sequence has more frames; false otherwise.
	 */ 
    bool updateFrame(); 

	/// Returns skeleton computed from the last frame.
    ISkeleton* getSkeleton();
	
	/// Starts/stops recording.
	void toggleRecording();

private:
	// Holds the information about the motion sensor
    IMotionSensor *m_pSensor;
	
	// Holds the information about the skeleton 
    ISkeleton *m_pSkeleton; 
	
	// Indicates whether recording in process.
	bool m_isRecording;
};

#endif // TRACKING_H
/******************************************************************************/
/*                                EOF                                         */
/******************************************************************************/
