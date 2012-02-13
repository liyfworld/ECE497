
/******************************************************************************/
/*                              Includes                                      */
/******************************************************************************/
#include <math.h>

#include <Shadow/IMotionSensor.h>

#include "GLContext.h"
#include "RenderContext.h"

/******************************************************************************/
/*                              Defines                                       */
/******************************************************************************/
#define PI 3.1415926536f
#define RAD_TO_DEG(rad) (57.295779513f*rad)
// The index of a joint in the RenderContext::joints array
// to be a camera look-at point (Torso joint).
#define LOOKAT_JOINT_IND 1

/******************************************************************************/
/*                        Static data initialization                          */
/******************************************************************************/

// Initialize array of joint info.
RenderContext::JointInfo RenderContext::joints[NUM_OF_JOINTS] =
{
	{{0.f , 0.f ,  90.f}, {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, false, false, 0.f, 8.f, JointID_head          , JointID_unknown	      },
	{{0.f , 0.f ,  90.f}, {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, true,  false, 0.f, 4.f, JointID_torso         , JointID_spine3		  },
	{{0.f , 0.f ,  90.f}, {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, true,  false, 0.f, 4.f, JointID_neck          , JointID_head 		  },
	{{0.f , 0.f , 180.f}, {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, false, false, 0.f, 4.f, JointID_rightFingerTip, JointID_unknown	      },
	{{0.f , 0.f ,   0.f}, {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, false, false, 0.f, 4.f, JointID_leftFingerTip , JointID_unknown	      },
	{{0.f , 0.f , 180.f}, {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, true,  false, 0.f, 8.f, JointID_rightShoulder , JointID_rightElbow    },
	{{0.f , 0.f ,   0.f}, {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, true,  false, 0.f, 8.f, JointID_leftShoulder  , JointID_leftElbow     },
	{{0.f , 0.f , 180.f}, {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, true,  false, 0.f, 4.f, JointID_rightElbow    , JointID_rightFingerTip},
	{{0.f , 0.f ,   0.f}, {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, true,  false, 0.f, 4.f, JointID_leftElbow     , JointID_leftFingerTip },
	{{0.f , 0.f , -90.f}, {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, true,  false, 0.f, 4.f, JointID_rightKnee	  , JointID_rightFoot     },
	{{0.f , 0.f , -90.f}, {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, true,  false, 0.f, 4.f, JointID_leftKnee      , JointID_leftFoot      },
	{{0.f , 0.f , -90.f}, {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, true,  false, 0.f, 8.f, JointID_rightHip      , JointID_rightKnee     },
	{{0.f , 0.f , -90.f}, {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, true,  false, 0.f, 8.f, JointID_leftHip       , JointID_leftKnee      },
	{{0.f , 0.f ,   0.f}, {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, true,  false, 0.f, 4.f, JointID_leftFoot      , JointID_unknown       },
	{{0.f , 0.f ,  90.f}, {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, true,  false, 0.f, 4.f, JointID_rightFoot     , JointID_unknown       },
	{{0.f , 0.f ,  90.f}, {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, true,  false, 0.f, 4.f, JointID_spine1        , JointID_spine2        },
	{{0.f , 0.f ,  90.f}, {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, true,  false, 0.f, 4.f, JointID_spine2        , JointID_torso         },
	{{0.f , 0.f ,  90.f}, {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, true,  false, 0.f, 4.f, JointID_spine3        , JointID_spine4        },
	{{0.f , 0.f ,  90.f}, {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, true,  false, 0.f, 8.f, JointID_spine4        , JointID_neck          },
	{{0.f , 0.f ,  90.f}, {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, true,  false, 0.f, 4.f, JointID_waist         , JointID_spine1        },
	{{0.f , 0.f ,  90.f}, {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, true,  false, 0.f, 8.f, JointID_hips          , JointID_waist         }
};

/******************************************************************************/
/*                           Class implementation                             */
/******************************************************************************/
RenderContext::RenderContext()
{}

RenderContext::~RenderContext()
{}

bool RenderContext::renderJoints(	const ISkeleton* skeleton,
                                    bool frontView /*= true*/)
{
	// Get joint positions and rotations (world coordinate system).
	for(int i  = 0; i < NUM_OF_JOINTS ; i++)
	{
		joints[i].isTracked = false;
		joints[i].length    = 0.f;
		if(skeleton->containsJoint(joints[i].jointID))
		{
			skeleton->getJointPosition(joints[i].jointID, joints[i].trackPos, true);
			// The Y and Z axes are reversed in the Omek coordinate system (see Developer Guide).
			joints[i].trackPos[1] = -joints[i].trackPos[1];
			joints[i].trackPos[2] = -joints[i].trackPos[2];
			// The coordinate system of rotations is the same as in OpenGL.
			GLfloat trackRotQ[4];
			skeleton->getJointRotation(joints[i].jointID, trackRotQ, true);

			// Translate quaternion to the Euler angles.
			quaternionToEuler(trackRotQ, joints[i].trackRot);

			updateLength(&joints[i], skeleton);
			joints[i].isTracked = true;
		}
	}


	//	Clears the color buffer.
	//	glClear() can also be used to clear the depth or stencil buffer
	//	(GL_DEPTH_BUFFER_BIT or GL_STENCIL_BUFFER_BIT)
	glClear(GL_COLOR_BUFFER_BIT);
	if (!GLContext::getInstance().testEGLError("glClear"))
		return false;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	GLfloat eyeX = 0.f;
	GLfloat eyeY = 0.f;
	if(frontView)
	{
		// Place the camera in front and slightly to the right and up from the LOOKAT_JOINT_IND joint.
		eyeX = 35.f ;
		eyeY = 180.f;
	}
	else
	{
		// Place the camera from the side and slightly to the right and up from the LOOKAT_JOINT_IND joint.
		eyeX = 200.f;
		eyeY = 80.f ;
	}
	
	// Fix the look-at point on the LOOKAT_JOINT_IND joint.
	GLfloat eye   [3]   = {eyeX, joints[LOOKAT_JOINT_IND].trackPos[1] + 30.f, joints[LOOKAT_JOINT_IND].trackPos[2] + eyeY};
	GLfloat center[3]	= {0.f , joints[LOOKAT_JOINT_IND].trackPos[1]       , joints[LOOKAT_JOINT_IND].trackPos[2]       };
	GLfloat up    [3]   = {0.f , 1.f                                        , 0.f                                        };
	lookAt( eye, center, up);


	drawGrid();

	glPushMatrix();
	{
		glTranslatef( -joints[LOOKAT_JOINT_IND].trackPos[0], 0, 0 );

		for(int i =0 ; i < NUM_OF_JOINTS ; i++)
		{
			if(joints[i].isTracked)
				float rot[3] = {0,0,0};
			drawJoint(	joints[i].trackPos,
			            joints[i].trackRot,
			            joints[i].tPoseRot,
			            joints[i].length  ,
			            joints[i].size    );
		}


		if (!GLContext::getInstance().testEGLError("glDrawArrays"))
		{
			return false;
		}
	}
	glPopMatrix();

	GLContext::getInstance().swapBuffers();

	if (!GLContext::getInstance().testEGLError("eglSwapBuffers"))
	{
		return false;
	}

	return true;
}

void RenderContext::drawJoint(	const GLfloat trans   [3],
                                const GLfloat trackRot[3],
                                const GLfloat tPoseRot[3],
									  GLfloat length     ,
								      GLfloat size        )
{

	GLfloat scale[3];
	GLfloat pDiffuse[4];

	glPushMatrix();
	{
		glTranslatef(trans[0], trans[1], trans[2]);

		// Apply the tracking output rotation.
		glRotatef( trackRot[2], 0.0f, 0.0f, 1.0f);
		glRotatef( trackRot[1], 0.0f, 1.0f, 0.0f);
		glRotatef( trackRot[0], 1.0f, 0.0f, 0.0f);

		// Apply the T-pose rotation.
		glRotatef( tPoseRot[2], 0.0f, 0.0f, 1.0f);
		glRotatef( tPoseRot[1], 0.0f, 1.0f, 0.0f);
		glRotatef( tPoseRot[0], 1.0f, 0.0f, 0.0f);

		// ================== Draw the bone  ==================
		scale[0] = length;
		scale[1] = 2.f;
		scale[2] = 2.f;

		// Make the "bone" color green.
		pDiffuse[0] = 0.0f;
		pDiffuse[1] = 1.0f;
		pDiffuse[2] = 0.0f;
		pDiffuse[3] = 1.0f;
		glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, pDiffuse );

		glPushMatrix();
		{
			glScalef( scale[0], scale[1], scale[2]);
			glTranslatef(0.5f, 0.0f, 0.0f);
			drawCube();
		}
		glPopMatrix();

		// ================== Draw the joint  ==================
		scale[0] = size;
		scale[1] = size;
		scale[2] = size;

		// Make the joint color red.
		pDiffuse[0] = 1.0f;
		pDiffuse[1] = 0.0f;
		pDiffuse[2] = 0.0f;
		pDiffuse[3] = 1.0f;
		glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, pDiffuse );

		glPushMatrix();
		{
			glScalef( scale[0], scale[1], scale[2]);
			drawCube();
		}
		glPopMatrix();

	}
	glPopMatrix();
}

void RenderContext::drawGrid()
{
	const static int numGridLines = 21;
	const static int numLineVerts = numGridLines*2;

	static GLfloat horizVerts[numLineVerts][3];
	static GLfloat perspVerts[numLineVerts][3];
	static GLushort vertInds[numLineVerts];

	static bool init = false;
	if(!init)
	{
		const int y = -100;
		const int border = 200;
		for(int i = 0, x_z = -border ; i < numLineVerts ; i+=2, x_z+=20)
		{
			horizVerts[i  ][0] = -border;
			horizVerts[i  ][1] = y;
			horizVerts[i  ][2] = x_z;
			horizVerts[i+1][0] = border;
			horizVerts[i+1][1] = y;
			horizVerts[i+1][2] = x_z;

			perspVerts[i  ][0] = x_z;
			perspVerts[i  ][1] = y;
			perspVerts[i  ][2] = border;
			perspVerts[i+1][0] = x_z;
			perspVerts[i+1][1] = y;
			perspVerts[i+1][2] = -border;

			vertInds[i  ] = i;
			vertInds[i+1] = i+1;
		}

		init = true;
	}

	glPushMatrix();
	{
		glTranslatef( 0, joints[LOOKAT_JOINT_IND].trackPos[1]-40, joints[LOOKAT_JOINT_IND].trackPos[2] );

		GLushort quadInds[4] = {0, numLineVerts-2, 1, numLineVerts-1};

		glEnableClientState(GL_VERTEX_ARRAY);
		float pDiffuse[4] = {1.0f, 1.0f, 1.0f, 1.0f};

		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertexPointer(3, GL_FLOAT, 0, horizVerts);

		pDiffuse[0] = 0.25;
		pDiffuse[1] = 0.25;
		pDiffuse[2] = 0.25;
		pDiffuse[3] = 1.0f;
		glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, pDiffuse );
		glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_SHORT, quadInds);

		pDiffuse[0] = 0.85;
		pDiffuse[1] = 0.85;
		pDiffuse[2] = 0.85;
		pDiffuse[3] = 1.0f;
		glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, pDiffuse );

		glLineWidth(1);
		glTranslatef( 0, .5f, 0);
		glDrawElements(GL_LINES, numLineVerts, GL_UNSIGNED_SHORT, vertInds);

		glVertexPointer(3, GL_FLOAT, 0, perspVerts);
		glLineWidth(1);
		glDrawElements(GL_LINES, numLineVerts, GL_UNSIGNED_SHORT, vertInds);
	}
	glPopMatrix();

}


void RenderContext::quaternionToEuler(	const GLfloat qtrn [4],
                                        GLfloat euler[3])
{
	float qtrn_0_0 = qtrn[0]*qtrn[0];
	float qtrn_1_1 = qtrn[1]*qtrn[1];
	float qtrn_2_2 = qtrn[2]*qtrn[2];
	float qtrn_3_3 = qtrn[3]*qtrn[3];
	
	float pitch = atan2(2.f*(qtrn[2]*qtrn[3] + qtrn[0]*qtrn[1]),
	                    qtrn_0_0 - qtrn_1_1 -
	                    qtrn_2_2 + qtrn_3_3);

	float roll = atan2(2.f*(qtrn[1]*qtrn[2] + qtrn[0]*qtrn[3]),
	                   qtrn_0_0 + qtrn_1_1 -
	                   qtrn_2_2 - qtrn_3_3);

	float yaw = asin(-2.f*(qtrn[1]*qtrn[3] - qtrn[0]*qtrn[2]));

	euler[0] = RAD_TO_DEG(pitch);
	euler[1] = RAD_TO_DEG(yaw);
	euler[2] = RAD_TO_DEG(roll);
}

void RenderContext::lookAt(	const GLfloat eye[3],
                            const GLfloat center[3],
                            const GLfloat up[3])
{
	GLfloat m[16];
	GLfloat x[3], y[3], z[3];
	float mag = 0.0f;

	/* Make rotation matrix */

	/* Z vector */
	z[0] = eye[0] - center[0];
	z[1] = eye[1] - center[1];
	z[2] = eye[2] - center[2];
	mag = sqrt( z[0] * z[0] + z[1] * z[1] + z[2] * z[2]);
	if (mag)  			/* mpichler, 19950515 */
	{
		z[0] /= mag;
		z[1] /= mag;
		z[2] /= mag;
	}

	/* Y vector */
	y[0] = up[0];
	y[1] = up[1];
	y[2] = up[2];

	/* X vector = Y cross Z */
	x[0] = y[1] * z[2] - y[2] * z[1];
	x[1] = -y[0] * z[2] + y[2] * z[0];
	x[2] = y[0] * z[1] - y[1] * z[0];

	/* Recompute Y = Z cross X */
	y[0] = z[1] * x[2] - z[2] * x[1];
	y[1] = -z[0] * x[2] + z[2] * x[0];
	y[2] = z[0] * x[1] - z[1] * x[0];

	/* mpichler, 19950515 */
	/* cross product gives area of parallelogram, which is < 1.0 for
	 * non-perpendicular unit-length vectors; so normalize x, y here
	 */

	mag = sqrt(x[0] * x[0] + x[1] * x[1] + x[2] * x[2]);
	if (mag)
	{
		x[0] /= mag;
		x[1] /= mag;
		x[2] /= mag;
	}

	mag = sqrt(y[0] * y[0] + y[1] * y[1] + y[2] * y[2]);
	if (mag)
	{
		y[0] /= mag;
		y[1] /= mag;
		y[2] /= mag;
	}

#define M(row,col)  m[col*4+row]
	M(0, 0) = x[0];
	M(0, 1) = x[1];
	M(0, 2) = x[2];
	M(0, 3) = 0.0;
	M(1, 0) = y[0];
	M(1, 1) = y[1];
	M(1, 2) = y[2];
	M(1, 3) = 0.0;
	M(2, 0) = z[0];
	M(2, 1) = z[1];
	M(2, 2) = z[2];
	M(2, 3) = 0.0;
	M(3, 0) = 0.0;
	M(3, 1) = 0.0;
	M(3, 2) = 0.0;
	M(3, 3) = 1.0;
#undef M
	glMultMatrixf(m);

	/* Translate Eye to Origin */
	glTranslatef(-eye[0], -eye[1], -eye[2]);

}

void RenderContext::drawCube()
{
	glEnableClientState(GL_NORMAL_ARRAY);
	static const GLfloat Vertices[8][3] =
	{
		//   x      y      z
		{-0.5, -0.5, -0.5},	// 0
		{-0.5, -0.5,  0.5},	// 1
		{-0.5,  0.5, -0.5}, 	// 2
		{-0.5,  0.5,  0.5}, 	// 3
		{ 0.5, -0.5, -0.5}, 	// 4
		{ 0.5, -0.5,  0.5}, 	// 5
		{ 0.5,  0.5, -0.5}, 	// 6
		{ 0.5,  0.5,  0.5} 	// 7
	};

	static const GLfloat Normals[8][3] =
	{
		//   x      y      z
		{-1.73205081, -1.73205081, -1.73205081},	// 0
		{-1.73205081, -1.73205081,  1.73205081},	// 1
		{-1.73205081,  1.73205081, -1.73205081}, 	// 2
		{-1.73205081,  1.73205081,  1.73205081}, 	// 3
		{ 1.73205081, -1.73205081, -1.73205081}, 	// 4
		{ 1.73205081, -1.73205081,  1.73205081}, 	// 5
		{ 1.73205081,  1.73205081, -1.73205081}, 	// 6
		{ 1.73205081,  1.73205081,  1.73205081} 	// 7
	};

	static const GLushort Indices[36] =
	{
		0, 1, 3, 3, 2, 0,    // left
		0, 2, 4, 4, 2, 6,    // back
		5, 4, 7, 7, 4, 6,    // right
		2, 3, 7, 7, 6, 2,    // top
		1, 5, 3, 3, 5, 7,    // front
		0, 4, 1, 1, 4, 5     // bottom
	};

	glVertexPointer(3, GL_FLOAT, 0, Vertices);
	glNormalPointer( GL_FLOAT, 0, Normals );
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, Indices);

	glDisableClientState(GL_NORMAL_ARRAY);

}

void RenderContext::updateLength(JointInfo* joint, const ISkeleton* skeleton)
{
	joint->length = 0.f;

	// Check whether the joint is a "boneless" one.
	if(!joint->drawBone)
		return;

	float posThis[3];
	float posNext[3];

	if(	skeleton->getJointPosition(joint->jointID, posThis, true) == OMK_SUCCESS &&
	        skeleton->getJointPosition(joint->nextID , posNext, true) == OMK_SUCCESS )
	{
		float dX = posThis[0] - posNext[0];
		float dY = posThis[1] - posNext[1];
		float dZ = posThis[2] - posNext[2];
		joint->length = sqrtf(dX*dX + dY*dY + dZ*dZ);
	}

}

/******************************************************************************/
/*                                EOF                                         */
/******************************************************************************/
