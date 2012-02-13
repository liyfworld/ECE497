#ifndef __GLContext_h__
#define __GLContext_h__
/******************************************************************************/
/*                              Includes                                      */
/******************************************************************************/
#include <EGL/egl.h>
#include <GLES/gl.h>

/******************************************************************************/
/*                               Class definition                             */
/******************************************************************************/

/**
 * @class GLContext
 * @brief The class encapsulates initialization and cleanup of OGLES related data.
 * 
 * The class is based on the HelloTRiangle demo provided in the OMAP35x Graphics SDK.
 */
class GLContext
{
public:
	/** 
	 *  Returns the the class singleton instance.
	 * @return reference to the class sigleton instance.
	 */ 
	static GLContext& getInstance();
	
	/** 
	 *   Initializes OGLES data.
	 * @return true if success; false otherwise.
	 */ 
	bool initialize();

	/// Cleans OGLES data up.
	void cleanup();
	
	/**
	 *  Tests for an EGL error and prints it
	 * @param pszLocation		location in the program where the error took 
	 *			 				place. ie: function name
	 * @return	true if no EGL error was detected.
	 */
	bool testEGLError(const char* pszLocation);
	
	/// Brings to the native display the current render surface.
	void swapBuffers();

private:

	/// Constructor.
	GLContext();	
	/// Destructor.
	~GLContext() { cleanup(); }

	/// Initializes the default light.
	void GLSetDefaultLight();
	
private:
	// EGL variables
	EGLDisplay eglDisplay;
	EGLConfig eglConfig;
	EGLSurface eglSurface;
	EGLContext eglContext;

	// Vertex buffer object handle
	GLuint ui32Vbo; 
	
	/// Default light parameters.
	float kOGLDefaultLightAmbient [4];
	float kOGLDefaultLightDiffuse [4];
	float kOGLDefaultLightSpecular[4];

};



#endif //__GLContext_h__
/******************************************************************************/
/*                                EOF                                         */
/******************************************************************************/
