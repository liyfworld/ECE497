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

namespace Omek {
					
/**
	@class ISkeleton ISkeleton.h "include/Shadow/ISkeleton.h"

	@brief The ISkeleton class serves as an interface to the Skeleton class which is a data structure containing
	the tracked rotation and translation data, as well as the bounding region for each joint.  
	
	Once the MotionSensor object has been instantiated and initialized, you can get the full body skeleton.  
	The SDK keeps a Skeleton object in memory and updates it per frame based on changes in the scene. 

	The 3D positions and rotations for the following joints can be queried per frame:
	•	Head
	•	Torso
	•	Center of hips
	•	Tips of both hands
	•	Elbows
	•	Shoulders
	•	Knees
	•	Neck
	•	Collar bones
	•	Waist
	•	Left and right hips
	•	Spine joints
	•	Left and right feet

	@note The Skeleton class contains both accessors and mutators. Use mutators only when creating your own skeleton,
	of for overriding certain data, as they will overwrite data read from the sensor/sequence.
*/

class _ShadowExport ISkeleton
{
public:

	/** Clone another skeleton instance
	@param[in] skeleton pointer to the skeleton to be copied
	@return OMK_SUCCESS for success, an error code otherwise
	*/
	virtual OMKStatus clone(const ISkeleton* skeleton) = 0;

	/** @brief Add a joint to the skeleton's tracked joints 
		@param[in] name The joint id to be added
		@return true if this joint was added, error if this joint already exist
	*/
	virtual bool addJoint(JointID name) = 0;
	
	/**
		@brief Set the world space and image space joint position
		@param[in] id The id of this joint
		@param[in] worldCoordinates The world position of this joint
		@param[in] imageCoordinates The image position of this joint
		@return OMK_SUCCESS for success, an error code otherwise
	*/
	virtual OMKStatus setJointPosition(JointID id, const float worldCoordinates[3], const float imageCoordinates[3]) = 0;

	/**
		@brief Set the image space  joint position
		@param[in] id The id of this joint
		@param[in] imageCoordinates The image position of this joint
		@return OMK_SUCCESS for success, an error code otherwise
	*/ 
	virtual OMKStatus setJointImagePosition(JointID id, float imageCoordinates[3]) = 0;

	/**
		@brief Get the world/image joint position
		@param[in] id The id of this joint
		@param[out] results The world/image position of this joint
		@param[in] worldPosition Is world position, else – image position
		@return OMK_SUCCESS for success, an error code otherwise
	*/ 
	virtual OMKStatus getJointPosition(JointID id, float results[3], bool worldPosition) const = 0;

	/** 
		Set local rotation for specified joint
		@param[in] name The name of this joint
		@param[in] quaternion The quaternion representing the local/global 3D rotation
		@param[in] globalRotation Is global rotation, else – local rotation
		@return OMK_SUCCESS for success, an error code otherwise
	*/
	virtual OMKStatus setJointRotation(JointID name, const float quaternion[4], bool globalRotation) = 0;

	/** 
		Get global/local rotation for specified joint

		@param[in] id The id of this joint
		@param[out] quaternion The quaternion representing the global/local 3D rotation
		@param[in] globalRotation Is global rotation, else – local rotation
		@return OMK_SUCCESS for success, an error code otherwise

	*/ 
	virtual OMKStatus getJointRotation(JointID id, float quaternion[4], bool globalRotation) const = 0;


	/**
		Set confidence for specified joint 
		@return OMK_SUCCESS for success, an error code otherwise
	*/
	virtual OMKStatus setJointConfidence(JointID id, unsigned int confidence) = 0;

	/** 
		@brief Get confidence measure for specific joint.
		
		The confidence of a joint is a percentage measure of how confident the tracking algorithm
		is of a result of tracking that specific joint. For example, when a joint is occluded, its
		confidence drops to a lower value. Similarly, confidence drops to a low value when a joint 
		is outside of the sensor's field of view.

		@param[in] id The id of this joint
		@param[out] confidence Resultant confidence measure (0-100)
		@return OMK_SUCCESS for success, an error code otherwise
	*/ 
	virtual OMKStatus getJointConfidence(JointID id, unsigned int &confidence) const = 0;

	/** 
		Clear the values of the given joint, but does not delete the joint. 
		
		@param[in] name The name of this joint
		@return success if succeeded
	*/ 
	virtual OMKStatus clearJoint(JointID name) = 0;
	
	/**
		Get the 2D bounding region of a specific joint

		@param[in] name The name of this joint
		@param[out] width The width of this joint
		@param[out] height The height of this joint
		@return success or failure. In case were there is no meaning for the joint’s size – return an error.
	*/ 
	virtual OMKStatus getJointSize(JointID name, float& width, float& height) const = 0;

	/**
		Set the 2D bounding region of a specific joint

		@param[in] name The name of this joint
		@param[in] width The width of this joint
		@param[in] height The height of this joint
		@return success or failure. 
	*/ 
	virtual OMKStatus setJointSize(JointID name, const float width, const float height) = 0;

	/**
		Return the number of tracked joints in this skeleton
	*/ 
	virtual unsigned int getNumOfJoints() const = 0;

	/**
		Return the joint id in the specific index

		@param[in] index the index of the wanted joint, useful for iterating through all joints in this skeleton
	*/ 
	virtual JointID getJointId(unsigned int index) const = 0;

	/** 
		Check if a joint is tracked in this skeleton

		@param[in] jointId The id of this joint
		@return true if this skeleton contain a joint named jointId
	*/ 
	virtual bool containsJoint(JointID jointId) const = 0;

	/// clear values of all joints 
	virtual void clearAllJoints() = 0;

	/**
		@brief Get the center of mass in world/image space

		@param[out] pnt 3D center of mass
		@param[in] worldSpace Is world space, else – image space
		@return success if computation was successful
	*/ 
	virtual OMKStatus getCenterOfMass(float pnt[3], bool worldSpace) const = 0;

	/** 
		@brief Get the torso width
	
		Gets updated continuously at every frame, even after calibration is done. 

		@param[out] fTorsoWidth Torso width in world coordinates (cm)
		@return OMK_SUCCESS for success, an error code otherwise

	*/
	virtual OMKStatus getTorsoWidth(float &fTorsoWidth) const = 0; 

	/**
		@brief Get the height of the skeleton

		@param[out] height The calculated height of the player
		@return OMK_SUCCESS for success, an error code otherwise
	*/ 
	virtual OMKStatus getCalibratedHeight( float &height ) const = 0;

	/**
		@brief Get the distance between the shoulders

		@param[out] shoulderWidth The calculated distance from left to right shoulder
		@return OMK_SUCCESS for success, an error code otherwise
	*/ 
	virtual OMKStatus getCalibratedShouldersWidth( float &shoulderWidth ) const = 0;

	/**
		@brief Get the geodesic length of the arm

		@param[out] armLength The calculated length of the arm
		@return OMK_SUCCESS for success, an error code otherwise
	*/ 
	virtual OMKStatus getCalibratedArmLength( float &armLength ) const = 0;

	/**
		@brief Get the geodesic length of the leg

		@param[out] legLength The calculated length of the leg
		@return OMK_SUCCESS for success, an error code otherwise
	*/ 
	virtual OMKStatus getCalibratedLegLength( float &legLength ) const = 0;

	/// Torso width in world coordinates (cm). This is
	/// similar to getTorsoWidth, but does not change after
	/// calibration is done
	/// @see getTorsoWidth
	/// @return OMK_SUCCESS for success, an error code otherwise
	virtual OMKStatus getCalibratedTorsoWidth( float &torsoWidth ) const = 0;

	/* 
		@brief Convert a JointID to it's name
		@param[in] jointId the joint id
		@return the joint name
	*/
	static const char* jointIdToName(JointID jointId);
	/*
		@brief Convert a joint name to JointID
		@param[in] jointName the joint name
		@return the joint ID.
	*/
	static JointID jointNameToId(const char* jointName);
};
}

