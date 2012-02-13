#ifndef __RenderContext_h__
#define __RenderContext_h__

/******************************************************************************/
/*                              Includes                                      */
/******************************************************************************/
#include <EGL/egl.h>
#include <GLES/gl.h>

#include <Shadow/ShadowDefines.h>


/******************************************************************************/
/*                            Forward declaration.                             */
/******************************************************************************/
namespace Omek
{
	class ISkeleton;
}


/******************************************************************************/
/*                               Class definition                             */
/******************************************************************************/
using namespace Omek;

/**
 * @class RenderContext
 * @brief Encapsulates rendering of the skeleton joints.
 */
class RenderContext
{
public:

	/// Constructor.
	RenderContext();
	/// Destructor.
	~RenderContext();
	
	/**
	 * Renders the predefined tracked joints in the given skeleton.
	 * The joints to be rendered are: 
	 *  figer tips, elbows, shoulders, knees, feet and hips(left/right); 
	 *  head, torso, neck, spine(1-4), waist.
	 * (For the list of all available joints see ShadowDefines.h)
	 * @param skeleton 		a pointer to the skeleton to be rendered.
	 * @param frontView		if true renders the front view of the sceleton; 
	 * 						if false - the side view.
	 * @return true if success; false if an error occurred.
	 */ 
	bool renderJoints(const ISkeleton* skeleton, bool frontView=true);

private:
	/**
	 * @struct JointInfo
	 * @brief  Holds all the necessary information to render a joint.
	 * @note   All rotations/translations are in the world coordinate system.
	 */
	struct JointInfo
	{
		/**
		 * Defines the initial rotations of the joints in the T-pose.
		 * In our case we define the main joint axis to be X.
		 */
		const GLfloat tPoseRot[3];
		/// The tracking output rotation.
		GLfloat trackRot[3];
		/// The tracking output joint position.
		GLfloat trackPos[3];
		/**
		 * Indicates whether a bone should be drawn for this joint.
		 * @note We are going to use terms "bone" and "joint" interchangeably.
		 * In the SDK there are no two separate entities - joint has both the
		 * point position in space and a rotation, describing the orientation
		 * of the skeleton section ("bone") connecting two ajacent joints in the
		 * skeleon's hierarchy. For more details please see Developer Guide.
		 */
		const bool drawBone;
		/// Indicates whether the joint is being tracked in the current frame.
		bool isTracked;
		/**
		 * The length of the joint's bone (if it's to be drawn),
		 * computed as a distance between this and the next joint.
		 */
		GLfloat length;
		/// Size of the joint (scale of unit cube).
		GLfloat size;
		/// The id of this joint.
		const JointID jointID;
		/// The id of the next joint in the hierarchy( for length comp.).
		const JointID nextID;
	};

	/** 
	 * Draws one joint with the given world translation, rotation and a t-pose rotation. 
	 * @param trans 	the joint tracked position in the world coordinates.
	 * @param trackRot 	the joint tracked rotation in the world coordinates. 
	 * @param tPoseRot 	the joint initial t-pose rotation in the world coordinates. 
	 * @param length 	the joint(/bone) length.
	 * @param size		the joint size (scale of the unit cube).
	 */ 
	void drawJoint(	const GLfloat trans   [3], 
					const GLfloat trackRot[3], 
					const GLfloat tPoseRot[3],
						  GLfloat length,
						  GLfloat size);
	
	/// Draws the floor grid.
	void drawGrid();

	/** 
	 * Translates quaternion to the Euler angles(rad).
	 * @param [in]  quaternion	the quaternion to be translated.
	 * @param [out] euler		the result Euler angles (deg).
	 */ 
	void quaternionToEuler(const GLfloat quaternion[4], GLfloat euler[3]);
	
	/** 
	 * Places camera at the given eye position to look at the
	 * given center position with the given up vector.
	 * @param eye 		the camera position.
	 * @param center	the camera look-at point.
	 * @param up		the camera up vector.
	 */ 
	void lookAt( const GLfloat eye[3], const GLfloat center[3], const GLfloat up[3]);

	/// Draws unit cube with center at the origin.
	void drawCube();
	
	/**
	 * Updates length of the given joint(/bone).
	 * @param joint		pointer to the JointInfo, which associated joint's length is to be computed.	
	 * @param skeleton 	pointer to the Skeleton containing the joint.
	 * @see JointInfo.
	 */
	void updateLength(JointInfo* joint, const ISkeleton* skeleton);
	
private:	
		
	/// Number of joints to be rendered.
	enum { NUM_OF_JOINTS=21 };
	
	/// The array of the JointInfo's (note the t-pose rotations and joints hierarchy).
	static JointInfo joints[NUM_OF_JOINTS];

};



#endif //__RenderContext_h__
/******************************************************************************/
/*                                EOF                                         */
/******************************************************************************/
