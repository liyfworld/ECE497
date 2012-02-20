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

namespace Omek {

 /** \defgroup TrackingOptions Tracking options
	
	Set various tracking options and modes
	@see IMotionSensor::setTrackingOptions
	@{
	\def TRACK_BASIC 
	Basic tracking mode

	\def TRACK_ALL 
	Full-body tracking mode
	@}
*/

#define TRACK_ALL			0x00000003
#define TRACK_BASIC		    0x00000004

/** 
@enum JointID
Supported joint names
*/
enum JointID { 
	JointID_unknown = 0,
	JointID_head,
	JointID_torso,
	JointID_neck,
	JointID_rightFingerTip,
	JointID_leftFingerTip,
	JointID_rightHand,
	JointID_leftHand,
	JointID_rightShoulder,
	JointID_leftShoulder,
	JointID_rightElbow,
	JointID_leftElbow,
	JointID_rightCollar,
	JointID_leftCollar,
	JointID_hips,
	JointID_rightKnee,
	JointID_leftKnee,
	JointID_rightFoot,
	JointID_leftFoot,
	JointID_rightHip,
	JointID_leftHip,
	JointID_spine1,
	JointID_spine2,
	JointID_spine3,
	JointID_spine4,
	JointID_waist,

	SHADOW_JOINTS_NUM // MUST BE THE LAST ONE !!!
};

enum ImageType {
		IMAGE_TYPE_COLOR = 0,
		IMAGE_TYPE_DEPTH,
		IMAGE_TYPE_MASK};

enum CameraStatus {
		CAMERA_CONNECTED = 0,
		CAMERA_NOT_CONNECTED,
		CAMERA_EOF};
/** 
@enum AlertEventType 
Enumeration of available events (alert types) 
*/
enum AlertEventType {		
	Alert_CloseToWall=0, /// < Player is too close to a background wall		
	Alert_GoodBackground,	/// < No background problems were detected			
	Alert_TooClose,		/// < Player is too close to the camera				
	Alert_TooFar,		/// < Player is too far from the camera				
	Alert_CloseToSide,	/// < Player is too close to edges of the frame				
	Alert_OutOfFrame,		/// < Player is not fully visible to the camera			
	Alert_GoodLocation,		/// < No problems in the player's position			
	Alert_CandidateEnters,	/// < A new Candidate was detected				
	Alert_CandidateLeaves,		/// < A Candidate went outside the camera image		
	Alert_PlayerEnters,	/// < A new player was detected				
	Alert_PlayerLeaves,		/// < A player went outside the camera image		
	Alert_LowFrameRate,		/// < The frame rate of the tracking is lower than expected			
	Alert_GoodFrameRate,	/// < The frame rate of the tracking is good			
	Alert_FrameLost,	/// < Tracking has lost a frame, according to the time-stamps				
	Alert_CalibrationBegun,	/// < calibration of player begun			
	Alert_CalibrationDone,	/// < calibration of player Done			
	Alert_SensorCamDisconnected, /// < Camera was disconnected (cannot grab images)		
	Alert_SensorSeqDisconnected, /// < Sequence was disconnected (cannot grab images)		
	Alert_SensorReConnected,	 /// < sensor was re-connected 		
	Alert_SensorMoved,           /// < sensor was moved
	Alert_SensorStable,          /// < sensor is stable (after being moved)
	Alert_SensorProblem,		 /// < General sensor problem		
	Alert_None		/// < Default value, indicating that no alert was assigned			
};

/** @enum ImageResolution
	Available image resolution values, that can be applied to the depth, IR, or color images.
	Note that the support of the different formats varies according to the imaging device
*/
enum ImageResolution
{
	IMAGE_RESOLUTION_DEFAULT = -1,
	/// QQVGA mode - 160x120
	IMAGE_RESOLUTION_QQVGA = 0,
	/// QVGA mode - 320x240
	IMAGE_RESOLUTION_QVGA,
	/// VGA mode - 640x480
	IMAGE_RESOLUTION_VGA
};

/// @enum Available modes for listing gestures
enum ListGestureMode {
	/// List all the gestures available in the SDK
	ALL_GESTURES = 0,
	/// List only the gestures that are active now
	ACTIVATED_GESTURES
};

/** Definition of possible error values */
#define OMKStatus unsigned int
enum OMK_GENERAL_STATUS
{
	OMK_SUCCESS = 0,
	OMK_MEMORY_ALLOCATION_FAILURE,
	OMK_ERROR_BAD_ARGUMENT,	
	OMK_ERROR_FILE,
	OMK_ERROR_FILE_OPEN,
	OMK_ERROR_FILE_CLOSE,
	OMK_ERROR_FILE_NOT_FOUND,	
	OMK_ERROR_ASSERTION_FAILURE,
	OMK_ERROR_PROCESS_KILLED,
	OMK_ERROR_NULL_POINTER,
	OMK_ERROR_TINY_XML,	
	OMK_ERROR_XML_MISSING_TAG,	
	OMK_ERROR_UNSAVED_DATA,
	OMK_ERROR_UNINITIALIZED_DATA,
	OMK_ERROR_UNSUPPORTED_OPERATION,
	OMK_GENERAL_FAILURE,
	OMK_ERROR_BUFFER_TOO_SHORT,
	OMK_ERROR_INDEX_OUT_OF_BOUNDS
};

enum OMK_LEARNING_STATUS
{	
	OMK_ERROR_OVERLAPPING_CATEGORIES = 0x00000100,
	OMK_ERROR_BAD_SEQUENCE_FORMAT,	
	OMK_ERROR_INVALID_DATA_FORMAT,	
	OMK_ERROR_NO_POSITIVE_SAMPLES,
	OMK_ERROR_NO_NEGATIVE_SAMPLES,
	OMK_ERROR_TRAIN_MODEL,
	OMK_ERROR_LOADING_CLASSIFIER_MODEL,
	OMK_ERROR_FPS_DONT_MATCH,
};

enum OMK_GESTURE_STATUS
{
	OMK_ERROR_CAMERA_NOT_SUPPORTED = 0x00000200,
	OMK_ERROR_GESTURE_DUPLICATED,
	OMK_ERROR_GESTURE_CLASSIFIER_DUPLICATED,
	OMK_ERROR_GESTURE_LISTENER_ALREADY_REGISTERED,
	OMK_ERROR_GESTURE_ALREADY_BEING_REGISTERED,
	OMK_ERROR_GESTURE_REGISTRATION,
	OMK_ERROR_GESTURE_NOT_FOUND,	
	OMK_ERROR_GESTURE_LISTENER_NOT_FOUND,
	OMK_ERROR_GESTURE_PARAMS,
	OMK_ERROR_GESTURE_DATA,
	OMK_ERROR_GESTURE_STATE,
	OMK_ERROR_GESTURE_PACKAGE_NOT_FOUND,
	OMK_ERROR_GESTURE_MANAGER_ALREADY_INITIALIZED,	
	OMK_ERROR_GESTURE_MANAGER_NOT_INITIALIZED,	
	OMK_GESTURE_FINISHED,	
	OMK_ERROR_GESTURE_LISTENER_NULL,
	OMK_ERROR_GESTURE_MANAGER_NULL
};

enum OMK_USER_INPUT_STATUS
{
	OMK_YES_BUTTON_CLICKED = 0x00000300,
	OMK_NO_BUTTON_CLICKED,
	OMK_CANCEL_BUTTON_CLICKED,
	OMK_OK_BUTTON_CLICKED,
	OMK_OPERATION_CANCELED_BY_USER,	
	OMK_ERROR_USER_INPUT
};

enum OMK_SENSOR_STATUS
{
	OMK_ERROR_CAMERA_LIST_UNINITIALIZED = 0x00000400,
	OMK_ERROR_CAMERA_INDEX_ILLEGAL,
	OMK_ERROR_ENUMERATING_CAMERA_DEVICES,
	OMK_ERROR_GETTING_DEVICE_PROPERTIES,
	OMK_ERROR_CAMERA_GRAB,
	OMK_ERROR_SEQUENCE_GRAB,
	OMK_ERROR_CAMERA_SET_OUTPUT_MODE,
	OMK_ERROR_UNSUPPORTED_OUTPUT_MODE,
	OMK_ERROR_SENSOR_LOAD_CONFIG,
	OMK_ERROR_SENSOR_TIMEOUT,
	OMK_ERROR_SENSOR_SET_LICENSE,
	OMK_ERROR_SENSOR_GOTO_FRAME,
	OMK_ERROR_SENSOR_SET_PARAM,
	OMK_ERROR_SENSOR_GET_PARAM,
	OMK_ERROR_SENSOR_SET_FPS,
	OMK_ERROR_SENSOR_DEVICE_OPEN,
	OMK_ERROR_SEQUENCE_EOF_REACHED,
	OMK_ERROR_SENSOR_LIBRARY_NOT_LOADED,
	OMK_ERROR_SENSOR_LIBRARY_BAD_FORMAT,
	OMK_ERROR_SENSOR_FAILED_CREATING_GRABBER,
	OMK_ERROR_SENSOR_NOT_INITIALIZED,
	OMK_ERROR_SENSOR_ENABLE_DEPTH,
	OMK_ERROR_SENSOR_ENABLE_RGB,
	OMK_ERROR_REGISTER_DEPTH_RGB_IMAGES,
	OMK_ERROR_SENSOR_GET_RGB,
	OMK_ERROR_SENSOR_REGISTER_CALLBACK,
	OMK_ERROR_SENSOR_UNREGISTER_CALLBACK,
	OMK_ERROR_SENSOR_UNMKNOWN_IMAGE_FORMAT,
	OMK_ERROR_SENSOR_GENERATE_DATA,
	OMK_SENSOR_NO_NEW_FRAME,
	OMK_ERROR_SEQUENCE_HANDLER_NULL,
	OMK_ERROR_SENSOR_DISCONNECTED,
	OMK_ERROR_CAMERA_GRABBER_GENERAL_ERROR,
	OMK_ERROR_CAMERA_BLOCKED,
	OMK_ERROR_SEQUENCE_READ_FAIL,
	OMK_ERROR_SEQUENCE_FILE_NOT_FOUND,
	OMK_ERROR_SET_PROJECTOR_DATA,
	OMK_ERROR_UNRECOGNIZED_SEQUENCE,
	OMK_ERROR_UNSUPPORTED_INPUT_PARAM,
	OMK_ERROR_CLOSING_SENSOR,
};

enum OMK_CONFIG_STATUS
{
	OMK_ERROR_CONFIG_UNINITIALIZED = 0x00000500,
	OMK_ERROR_CONFIG_INIT_FAILED
};

enum OMK_ALERT_STATUS
{
	OMK_ERROR_ALERT_NOT_FOUND = 0x00000600,
	OMK_ERROR_ALERT_MANAGER_INIT_FAILED,
	OMK_ALERT_FINISHED
};

enum OMK_RETARGET_STATUS
{
	OMK_ERROR_RETARGET_LOAD_CHARACTER_FILE_FAILED = 0x00000700,
	OMK_ERROR_RETARGET_CHARACTER_ALREADY_EXISTS,
	OMK_ERROR_RETARGET_UPDATE_PLAYERS_LOCATION,
	OMK_ERROR_RETARGET_GENERAL_FAIL
};

enum OMK_PLAYER_STATUS
{
	OMK_ERROR_PLAYER_FAILED_CREATING_TRACKER = 0x00000800,
	OMK_ERROR_PLAYER_NOT_ACTIVE,
	OMK_ERROR_PLAYER_NOT_FOUND
};

enum OMK_RUNTIME_STATUS
{
	OMK_ERROR_DATA_MANAGER_SHUTDOWN = 0x00000900,
	OMK_ERROR_DATA_MANAGER_NOT_INITIALIZED,
	OMK_ERROR_DATA_MANAGER_ALREADY_RUNNING,
	OMK_ERROR_GETTING_IMAGE_DATA,
	OMK_ERROR_DATA_MANAGER_NOT_RUNNING
};

enum OMK_SKELETON_STATUS
{
	OMK_ERROR_SKELETON_CHARACTER_NOT_FOUND = 0x00000A00,
	OMK_ERROR_SKELETON_NOT_FOUND,
	OMK_ERROR_SKELETON_NULL,
	OMK_ERROR_JOINT_NOT_FOUND,
	OMK_ERROR_JOINT_GENERAL_ERROR,
	OMK_ERROR_JOINT_ALREADY_EXISTS,
	OMK_ERROR_SKELETON_ENHANCER_FAILURE,
	OMK_ERROR_SKELETON_NOT_CALIBRATED,
	OMK_ERROR_SIZE_NOT_CALCULATED,
};

enum OMK_TRACKING_STATUS
{
	OMK_ERROR_TRACKING_GENERAL_FAILURE = 0x00000B00,
	OMK_ERROR_TRACKING_LIBRARY_NOT_FOUND,
	OMK_ERROR_TRACKING_LIBRARY_BAD_FORMAT,
	OMK_ERROR_TRACKING_INITIALIZE,
	OMK_ERROR_TRACKING_MAX_PLAYERS_EXCEEDED,
	OMK_ERROR_TRACKING_BACKGROUND_FAILURE
};

enum OMK_GRAPH_STATUS
{
	OMK_ILLIGAL_GRAPH_USE = 0x00000C00,
	OMK_ERROR_GRAPH_GENERAL_FAIL
};

enum OMK_FLOOR_PLANE_STATUS
{
	OMK_FLOOR_PLANE_PARAMS_NOT_VALID = 0x00000D00,
	OMK_ERROR_FLOOR_PLANE_EST_UNINITIALIZED,
	OMK_ERROR_FLOOR_PLANE_SET_PARAMS_FAILURE
};

} //namespace omek
