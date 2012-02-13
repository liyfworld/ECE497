/**************************************************************************************
Copyright � 2009 Omek Interactive Ltd. All Rights Reserved.

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

#include "Shadow/ISkeleton.h"
#include "Shadow/ShadowDefines.h" 
#include "Shadow/ISensor.h" 
#include "Shadow/IFiredEvent.h"
#include "Shadow/Platform.h"

namespace Omek {

class IGestureListener;

//a pointer to a function that receives an IFiredEvent pointer
typedef void(*OMK_eventHandlerFunc)(IFiredEvent*);

/** 
	@class IMotionSensor IMotionSensor.h "include/Shadow/IMotionSensor.h"
	@brief This class is the main interface for the Omek Beckon SDK
	
	The Omek Beckon SDK provides a robust solution for real-time, 3D motion tracking using 
	a depth camera. The thin and intuitive event-based C++ interface allows developers to quickly create 
	immersive applications, and easily change existing user interfaces with 3D interaction. The middleware 
	is fully compatible with any game engine,  and natively supports the industry-standard FBX animation 
	format for blending pre-generated content with real-time tracking.
*/
class _ShadowExport IMotionSensor
{
public:
	/**** STATIC METHODS ****/
	/** 
		@brief Use IMotionSensor with a live feed of a depth camera.
		
		Live camera mode is used for running the application with a connected depth camera.
		This method will automatically detect the camera that is currently connected.

		@note In case there are more than one cameras connected, the first one will be chosen.
		@note In case no camera is detected the creation will fail.

		@param[in] bExternalSensor flag indicating that the sensor was already activated by another process.
		@return a pointer to the created Sensor, or NULL in case of failure
	*/
	static IMotionSensor* createCameraSensor(bool bExternalSensor=false);

	/**
		@brief release the motion sensor allocation

		relaseMotionSensor destroys the sensor and releases allocated resources.
		This is the opposite function of createCameraSensor/createSequenceSensor
		@param[in] motionSensor pointer to the instance to be deleted
		@return OMK_SUCCESS if succeeded 
	*/
	static OMKStatus releaseMotionSensor(IMotionSensor* motionSensor);

	/** 
		Get an instance of an offline sequence sensor. Sequence mode is useful for development and debugging 
		of applications. It allows the developer to run the application without a camera, based on an offline 
		pre-recorded file sequence.	
	
		@param[in] sequence the directory in which the sequence resides (e.g. "C:\\data\\set1");
		@return a pointer to the created Sensor, or NULL in case of failure
	*/
	static IMotionSensor* createSequenceSensor(const char* sequence);		

	/// @return an interface to a new skeleton
	static ISkeleton* createSkeleton();

	/**
		Release the memory of the skeleton
		@param[in] skeleton the skeleton to delete
		@return OMK_SUCCESS if succeeded 
	*/
	static OMKStatus releaseSkeleton(ISkeleton* skeleton);

	/// @return the latest error value for this session
	static OMKStatus getLastError();

	/** 
		@brief Set verbosity level of the SDK
		All output will be written according to the	settings in the configuration file.
		See an example file installed in /bin.
		If the configFile is empty, the output will be written to stdout.
		
		@param[in] level 0 = none, 1 = critical, 2 = errors, 3 = warnings
		@param[in] configFile optional name of log4cxx configuration file.
	*/
	static void setVerbosityLevel(unsigned int level, const char* configFile=""); 

	/**** MOTION PROCESSING METHODS ****/

	/**
		Get a handle of the interface - ISensor
	*/
	virtual ISensor* getSensor() = 0;

	/** 
		@brief Start the loop of grabbing, tracking, gesture detection etc.
		This method start a new thread, where all the processing is performed
		
		@return OMK_SUCCESS if the new processing thread was initiated successfully
	*/
	virtual OMKStatus run() = 0;
	
	/** 
		@brief Stop the processing loop
		
		@return OMK_SUCCESS if the process was closed successfully
	*/
	virtual OMKStatus stop() = 0;

	/** 
		Pause the processing loop
		
		@return OMK_SUCCESS if the process was successfully paused
	*/
	virtual OMKStatus pause() = 0;
	
	/** Resume the processing loop
		
		@return OMK_SUCCESS if the process was successfully resumed
	*/
	virtual OMKStatus resume() = 0;

	/** @brief Fully process the next image, using the existing grabber and managers
	This method works in two ways: 
	- If the "waitForImage" is turned on, the method will return only when a new image was processed
	- If the "waitForImage" is turned off, the method will return immediately (check the hasNewImage flag in this case)
	NOTE: You must not mix calls to "processNextImage" with calls to "run".
	@param[in] waitForImage decides if the method will wait for a new image, or return immediately
	@param[out] hasNewImage (output) indicates if a new image was processed
	@return OMK_SUCCESS if a new image was fully processed, or an error if a problem occurred 
	*/
	virtual OMKStatus processNextImage(bool waitForImage, bool & hasNewImage) = 0;

	/**** GESTURES ****/

	/**
	get the number of activated gestures / all available gestures
	@param[in] isActivated what is the wanted gestures type
	@param[out] numOfGestures the amount of gestures.
	*/
	virtual OMKStatus getNumOfGestures(unsigned int& numOfGestures, ListGestureMode isActivated) const = 0;

	/** get the gesture name in the wanted index.
	if isActivated == ACTIVATED: 
	get the activated gesture name.
	When tracking is used, returns the gesture that was enabled,
	otherwise returns the gesture that was activated in the file
	if isActivated == NOT_ACTIVATED:
	get the gesture name
	@param gestureIndex (input) the index of the wanted gesture
	@param gestureName (output) the gesture name in the wanted index
	@param bufferSize (input) size of allocated buffer for the gesture name
	@param isActived (input) does the wanted gesture is from the activated gestures list
	@return OMK_SUCCESS for success, an error if failed
	*/
	virtual OMKStatus getGestureName(unsigned int gestureIndex, char* gestureName, unsigned int bufferSize, ListGestureMode isActived) const = 0;
	
	/** 
		Enable the report of specific gesture using hasMoreGestures/popNextGesture
		@param[in] gestureName the name of the gesture to enable
		@return OMK_SUCCESS if registration to the gesture succeeded
	*/
	virtual OMKStatus enableGesture(const char* gestureName) = 0;

	/** 
		Disable the report of specific gesture (unregister)
		@param[in] gestureName the name of the gesture to disable
		@return OMK_SUCCESS if unregistering to the gesture succeeded
	*/
	virtual OMKStatus disableGesture(const char* gestureName) = 0;

	/** 
		Disable report of all gestures
		
		@return OMK_SUCCESS if unregistering all of the gestures succeeded
	*/
	virtual OMKStatus disableAllGestures() = 0;

	/// @return true if there are more gesture in the queue
	virtual bool hasMoreGestures() const = 0;
	
	/** 
		Get the next gesture and call releaseGesture to release the memory of this gesture
		
		@see IMotionSensor::releaseGesture
		@return the next gesture in the queue, or NULL in case of failure
	*/
	virtual const IFiredEvent* popNextGesture() = 0;
	
	/** 
		Release the memory allocated for the gesture
	 
		@param[in] pGesture pointer to the gesture event that should be released
		@see IMotionSensor::popNextGesture
		@return OMK_SUCCESS if the memory was correctly released
	*/
	virtual OMKStatus releaseGesture(const IFiredEvent* pGesture) = 0; 

	/** 
		@brief Register an event listener for a gesture
		The gesture-listener should inherit from IGestureListener
		The onGesture method will be called each time the gesture is recognized

		@param[in] gestureName The name of the gesture
		@param[in] gestureListener Pointer to the event listener
		@see IGestureListener::onGesture
		@return OMK_SUCCESS if the listener was successfully registered to the given gesture
	*/
	virtual OMKStatus addGestureListener(const char* gestureName, IGestureListener* gestureListener) = 0;

	/** 
		Unregister an event listener for a gesture

		@param[in] gestureName the name of the gesture
		@param[in] gestureListener the event listener to be removed
		@return OMK_SUCCESS if the listener was successfully unregistered to the given gesture
	*/
	virtual OMKStatus removeGestureListener(const char* gestureName, IGestureListener* gestureListener) = 0;

	/**** ALERTS ****/
	
	/** 
		Enable the report of a specific alert
		
		@param[in] alertEvent contains data on the event: name, id 
		@return OMK_SUCCESS if registration to the alert succeeded
	*/
	virtual OMKStatus enableAlert(const AlertEventType& alertEvent) = 0;
	
	/** 
		Disable the report of a specific alert
		@param[in] alertEvent contains data on the event: name, id 
		@return OMK_SUCCESS if unregistering to the alert succeeded
	*/
	virtual OMKStatus disableAlert(const AlertEventType& alertEvent) = 0;
	
	/** 
		Disable report of all alerts
		
		@return OMK_SUCCESS if  unregistering to all alerts succeeded
	*/
	virtual OMKStatus disableAllAlerts() = 0;
	
	/// @return true if there are more alerts in the queue
	virtual bool hasMoreAlerts() const  = 0;
	
	/** 		
		Get the next alert in the queue and call releaseAlert to release the memory of this alert
		
		@see IMotionSensor::releaseAlert
		@return the next alert in the queue	
	*/
	virtual const IFiredEvent* popNextAlert() = 0;
	
	/** 
		Release the memory allocated for this alert
		
		@param[in] pAlert pointer to the alert event that should be released
		@see IMotionSensor::popNextAlert
		@return OMK_SUCCESS if the memory was correctly released
	*/
	virtual OMKStatus releaseAlert(const IFiredEvent* pAlert) = 0;

			
	/**** TRACKING ****/

	
	/// @return the tracker flags
	virtual unsigned int getTrackingOptions() = 0;

	/** 
		Set tracking options on the fly. 
			
		@param[in] trackingOptions the flags of the tracking to be set
		@see ShadowDefines.h
		@return OMK_SUCCESS if the new flags were successfully set
	*/
	virtual OMKStatus setTrackingOptions(unsigned int trackingOptions) = 0;

	/** 
		Set the strength of smoothing for a specific joint		
		
		@param[in] label player index
		@param[in] jointId id of joint
		@param[in] smoothStrength smooth value (0 means no smooth --> higher values means stronger smoothing)
	*/
	virtual OMKStatus setSmoothStrength(unsigned int label, const JointID &jointId, unsigned int smoothStrength) = 0;

	/** 
		Get the strength of smoothing for a specific joint		
		
		@param[in] label player index
		@param[in] jointId id of joint
	*/
	virtual unsigned int getSmoothStrength(unsigned int label, const JointID &jointId) const = 0;

	/** 
		@brief Set the maximum number of players, to be tracked in the scene.
		
		Note that the number of tracked players highly depends on the field of view 
		of the camera. In general, tracking more players works better as the field 
		of view of the camera is wider.
		The upper limit of supported players is 5.
		
		@param[in] nPlayers the new number of players to be tracked
		@return OMK_SUCCESS if the maximal number of tracked players was successfully set
	*/
	virtual OMKStatus setMaxPlayers(unsigned int nPlayers) = 0;

	/// @return the maximal number of players that can be tracked
	virtual unsigned int getMaxPlayers() const = 0;

	/** 
		@brief Set the maximum number of blobs, to restricts the number of tracked 
		blobs in the scene. 
		
		Note that the number of tracked blobs highly depends on the field of view 
		of the camera. In general, tracking more blobs works better as the field 
		of view of the camera is wider.
		The upper limit of supported players is 5.
		
		@param[in] nBlobs the new number of blobs to restricts.
		@return OMKStatus if the maximal number of blobs was successfully set
	*/
	virtual OMKStatus setMaxCandidates(unsigned int nBlobs) = 0;
	
	/// @return the maximal number of blobs that can be tracked in the scene
	virtual unsigned int getMaxCandidates() const = 0;
	
	/** Start tracking a specific blob of interest.
	@param[in] label the index of blob to be track
	*/
	virtual OMKStatus startTracking(unsigned int label) = 0;

	/** Stop tracking a specific player of interest.
	@param[in] label the index of player to be untracked
	*/
	virtual OMKStatus stopTracking(unsigned int label) = 0;

	/** 
		Fill the given skeleton object with the current full-body tracking data of a player
		
		@param[out] skeleton pointer to an instantiated skeleton interface, which will be filled by the method
		@param[in] label the ID of the player that should be retrieved
		@return OMK_SUCCESS if a legal player was found and the skeleton successfully filled
	*/
	virtual OMKStatus getSkeleton(ISkeleton *skeleton, unsigned int label=0) const = 0;

	/** 
		Get raw skeleton (no smoothing, etc.) for a given player
		
		@param[out] skeleton pointer to a preallocated Skeleton, will hold the retrieved player's skeleton
		@param[in] label the label of the player, who's skeleton should be returned
		@return OMK_SUCCESS if a legal skeleton was retrieved
	*/
	virtual OMKStatus getRawSkeleton(ISkeleton *skeleton, unsigned int label=0) const = 0;

	/**
		@brief Get the number of active players
	
		This method returns the number of active players.
		The number of tracked players is not the necessarily equal to the number of player we are trying to
		track!

		@return the number of active players
	*/
	virtual unsigned int getNumOfPlayers() const = 0;

	/** @brief Obtain the parameters defining the floor-plane in 3D Euclidean space in 
		world-coordinates.
	
		The 3D floor-plane parameters are defined using a point within the plane, 
		and a vector normal to the plane: 
			n * ( v - v0 ) = 0,
		where v0 is a 3D point within (on) the plane, n is the 3D vector normal 
		to the plane, v is any point within (on) the plane (infinitely many), 
		and "*" is the dot-product (non-normalized inner-product).
	
		@param[out] point corresponds to v0 in the definition above.
		@param[out] normal corresponds to n in the definition above.

		@return OMK_SUCCESS if succeeded , or an error code othherwise. 
		If the floor-plane not valid for (i.e., real and visible), then ignore the other outputs.
	*/
	virtual OMKStatus getFloorPlaneParams(float point[3], float normal[3]) = 0;

	/** @brief Re-initialize the floor plane object with known true floor plane parameter 
		values, over-writing any previous estimation and re-initializing the internal 
		state.
	
		@note Call this function only after checking that ISensor::isAlive() is true
		@note Calling this function will prevent any future estimation of floor plane parameters. Therefore, call it only if you are certain of the high 
		        accuracy of the input arguments.	
		@note Following a call to this function, the human user must let the floor be fully visible to the camera (un-occluded) for a few seconds, exactly 
		        as during start-up of the application.
	
		@param[in] cameraHeightCm the perpendicular height of the camera from the floor plane > 0, in cm.
		@param[in] cameraLookdownAngleDegrees  the camera's look-down inclination angle > 0, in degrees, where 0 deg corresponds to no look-down.
		@return OMK_SUCCESS if succeeded , or an error code othherwise.
	*/
	virtual OMKStatus setFloorPlaneKnownTrueParams(float cameraHeightCm, float cameraLookdownAngleDegrees) = 0;

	/**
		@brief Check if a specific player is active

		@param[in] label The id of the player we want to check
		@return true If player is active (i.e. being tracked)
	*/
	virtual bool isPlayerActive( const unsigned int label ) const = 0;

	/** 
		Fill the given image with the last captured image		
		
		@param[in] copyImage a preallocated image buffer of appropriate dimensions and channels
		@param[in] bufferSize the buffer size of the a preallocated image buffer
		@param[out] widthStep size of an aligned image row in bytes
		@param[in] bColor if true (default), this image will be either and IR or RGB image depending on the camera; if false, the image will contain the depth data
		@return OMK_SUCCESS if a current image exists and could be copied
	*/
	virtual OMKStatus copyRawImage(char* copyImage, unsigned int bufferSize, int& widthStep, bool bColor=true) = 0;

	/**
		Get the needed buffer size for getting the last captured image,
		in case of image mode = mask - get the size of the player's bounding rectangle
		@param[out] bufferSize the buffer size of the raw image
		@param[in] imageType the wanted imageType
		@return OMK_SUCCESS if a current image exists
	*/
	virtual OMKStatus getRawImageSize(unsigned int& bufferSize, ImageType imageType) = 0;

	/** 
		@brief Get a copy of the 2D binary mask of the requested player
	 
		In the output mask each pixel occupied by the player
		is white (value of 255) and all other pixels are black (value of 0)	
		when calling copyPlayerMask with size=0 the center of mass should be returned without copy of the mask.
	 
		@param[in] copyMask the buffer to copy to
		@param[in] bufferSize the size of the buffer, should be big enough @see getRawImageSize
				   if bufferSize==0, we don't return copy the mask to copyMask.
		@param[in] label the ID of the player who's mask should be retrieved
		@param[out] width the width of the player's bounding rectangle
		@param[out] height the height of the player's bounding rectangle
		@param[out] center3D the player blob's 3D center of mass in world space (cm)
		@param[out] center2D the player blob's 2D center of mass in local image space (pixels)
		
		@return OMK_SUCCESS if a current image exists and could be copied
	*/
	virtual OMKStatus copyPlayerMask(char* copyMask, unsigned int bufferSize, unsigned int label, int& width, int& height, float center3D[3], float center2D[2]) const = 0;


	/** 
		Candidates are observers that are typically behind the active players in the game.
		This function is useful in determining the number of people in the scene.
		
		@return the number of player candidates in the scene
	*/
	virtual unsigned int getNumOfCandidates() const = 0;

	/** 
		@brief Get a copy of the 2D binary mask of a specific candidate
	
		A candidate is a person detected in the scene which is not the main player. For example, when tracking
		one person and several people in the background, all those people will appear as candidate blobs. As soon
		as a person is tracked, his status changes from candidate to player, and his blob can then be accessed
		using copyPlayerMask instead. The size of the image is as the size of the depth image.
		when calling copyCandidateMask with size=0 the center of mass should be returned without copy of the mask.
	
		@param[in] copyMask the buffer to copy to
		@param[in] bufferSize the size of the buffer, should be big enough @see getRawImageSize
				   if bufferSize==0, we don't return copy the mask to copyMask.
		@param[in] label the serial number of the candidate, who's mask was requested
		@param[out] width the width of the candidate's bounding rectangle
		@param[out] height the height of the candidate's bounding rectangle
		@param[out] center3D the player blob's 3D center of mass in world space (cm)
		@param[out] center2D the player blob's 2D center of mass in local image space (pixels)

		@return OMK_SUCCESS if candidate is valid and copy was successful
		@see IMotionSensor::copyPlayerMask
		@see IMotionSensor::getNumCandidates
	*/ 
	virtual OMKStatus copyCandidateMask(char* copyMask, unsigned int bufferSize, unsigned int label, int& width, int& height, float center3D[3], float center2D[2]) const = 0; 

	/** 
		Reset the image background information for this session (the backround around the players and candidates) of this session
		
		@return OMK_SUCCESS if reset was successful
	*/
	virtual OMKStatus resetBackground() = 0;

	/** 
		Reset all tracking information (players, etc) for this session
		
		@return OMK_SUCCESS if reset was successful
	*/
	virtual OMKStatus resetTracking() = 0;

	/** 
	Restart the session (including starting sequence from first frame) 
	@return OMK_SUCCESS if restart was successful
	*/
	virtual OMKStatus restart() = 0;

	/** 
		This method can be called by different clients at the same time,
		as long as every client uses a different id. Each client should use the same id for successive calls
		
		@param[in] id a unique identification of the caller client, typically the actual pointer of the 
				   invoking object
		@return whether there is new information since the last call with the same id
	*/
	virtual bool hasNewFrameData(void* id) = 0;

	/** 
		@brief Record a sequence directly from the camera
		@param[in] filename the output file
		@param[in] nFrames number of frames to record
		@return OMK_SUCCESS if the sequence was opened successfully, an error otherwise
	*/
	virtual OMKStatus recordSequence(const char *filename, int nFrames) = 0;

	/** 
		@brief Stop recording a sequence previously started with recordSequence
		@return OMK_SUCCESS if the sequence was opened successfully, false otherwise
		@see IMotionSensor::recordSequence
	*/
	virtual OMKStatus stopRecording() = 0;

	/**** RETARGETTING ****/

	/** 
		Creates a new animated character target, using the info of the given skeleton
		
		@param[in] characterName identifier of the new character
		@param[in] skeleton defining the new character, to be added as a target
		@param[in] label ID of the tracked player
		@return OMK_SUCCESS if a new target was successfully created and added
	*/
	virtual OMKStatus retargetMotion(const char* characterName, const ISkeleton* skeleton, const unsigned int label = 0) = 0;

	/** 
		Creates a new animated character target, reading the skeleton's info from an FBX file
	
		@param[in] characterName identifier of the new character
		@param[in] fbxCharacterFileNameFullPath path to the FBX file containing the character definition
		@param[out] usedNodesCount the number of the actually used joints
		@param[out] usedBoneNames a string containing the names of the bones used in the retargetting, each separated by \n
		@param[in, out] usedBonesBufferSize size of usedBoneNames string buffer
		@param[in] label ID of the tracked player
		@return OMK_SUCCESS if a new target was successfully created and added
	*/
	virtual OMKStatus retargetMotion(const char* characterName, const char* fbxCharacterFileNameFullPath,
int &usedNodesCount, char* usedBoneNames, int& usedBonesBufferSize, const unsigned int label = 0 ) = 0;


	/** 
		Remove the target character with the given name
		
		@param[in] characterName identifier of the character to be removed
		@return OMK_SUCCESS if the target was successfully removed
	*/
	virtual OMKStatus removeTarget( const char* characterName ) = 0;

	/** 
		Fill the given skeleton with the joints data for the retargeted skeleton.
		
		@param[out] skeleton a skeleton to fill the joints data
		@param[in] characterName the name of the retargeted character.
		@return OMK_SUCCESS if a legal skeleton was retrieved
	*/
	virtual OMKStatus getRetargetedSkeleton(ISkeleton *skeleton, const char* characterName) = 0;

	/** 
		Fill array with translation and rotation of the skeleton joints for the selected retargeted character

		@param[out] allocatedArray an array to be filled with translation rotation values per joint. This array is ordered
			in [tx, ty, tz, rx, ry, rz, rw, ...] format, where [tx, ty, tz] is the translation, and [rx ry rz rw] is the rotation 
			represented as a quaternion
		@param[in] name of the retargeted character
		@return OMK_SUCCESS if a legal character name was entered
	*/
	virtual OMKStatus getCharacterStateData(void* allocatedArray, const char* characterName) = 0;
};

}
