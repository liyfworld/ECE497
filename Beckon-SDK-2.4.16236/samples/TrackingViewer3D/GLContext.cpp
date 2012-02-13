/******************************************************************************/
/*                               Includes                                     */
/******************************************************************************/
#include <stdio.h>

#include "GLContext.h"

/******************************************************************************/
/*                               Defines                                      */
/******************************************************************************/
#define DEFAULT_LIGHT_AMBIENT_R 0.2f
#define DEFAULT_LIGHT_AMBIENT_G 0.2f
#define DEFAULT_LIGHT_AMBIENT_B 0.2f

#define DEFAULT_LIGHT_DIFFUSE_R 0.8f
#define DEFAULT_LIGHT_DIFFUSE_G 0.8f
#define DEFAULT_LIGHT_DIFFUSE_B 0.8f

#define DEFAULT_LIGHT_SPECULAR_R 0.7f
#define DEFAULT_LIGHT_SPECULAR_G 0.7f
#define DEFAULT_LIGHT_SPECULAR_B 0.7f

/******************************************************************************/
/*                      Class implementation                                  */
/******************************************************************************/
GLContext::GLContext()
{
	// EGL variables
	eglDisplay	= 0;
	eglConfig	= 0;
	eglSurface	= 0;
	eglContext	= 0;

	// Vertex buffer object handle
	ui32Vbo = 0; 
	
	kOGLDefaultLightAmbient [0] = DEFAULT_LIGHT_AMBIENT_R;
	kOGLDefaultLightAmbient [1] = DEFAULT_LIGHT_AMBIENT_G;
	kOGLDefaultLightAmbient [2] = DEFAULT_LIGHT_AMBIENT_B;
	kOGLDefaultLightAmbient [3] = 0.0f;

	kOGLDefaultLightDiffuse [0] = DEFAULT_LIGHT_DIFFUSE_R;
	kOGLDefaultLightDiffuse [1] = DEFAULT_LIGHT_DIFFUSE_G;
	kOGLDefaultLightDiffuse [2] = DEFAULT_LIGHT_DIFFUSE_B;
	kOGLDefaultLightDiffuse [3] = 0.0f;

	
	kOGLDefaultLightSpecular[0] = DEFAULT_LIGHT_SPECULAR_R;
	kOGLDefaultLightSpecular[1] = DEFAULT_LIGHT_SPECULAR_G;
	kOGLDefaultLightSpecular[2] = DEFAULT_LIGHT_SPECULAR_B;
	kOGLDefaultLightSpecular[3] = 0.0f;

}

GLContext& GLContext::getInstance()
{
	static GLContext glc;
	return glc;
}

bool GLContext::initialize()
{
	/*
		Step 1 - Get the default display.
		EGL uses the concept of a "display" which in most environments
		corresponds to a single physical screen. Since we usually want
		to draw to the main screen or only have a single screen to begin
		with, we let EGL pick the default display.
		Querying other displays is platform specific.
	*/
	eglDisplay = eglGetDisplay((NativeDisplayType)0);

	/*
		Step 2 - Initialize EGL.
		EGL has to be initialized with the display obtained in the
		previous step. We cannot use other EGL functions except
		eglGetDisplay and eglGetError before eglInitialize has been
		called.
		If we're not interested in the EGL version number we can just
		pass NULL for the second and third parameters.
	*/
	EGLint iMajorVersion, iMinorVersion;
	if (!eglInitialize(eglDisplay, &iMajorVersion, &iMinorVersion))
	{
		printf("Error: eglInitialize() failed.\n");
		return false;
	}

	/*
		Step 3 - Specify the required configuration attributes.
		An EGL "configuration" describes the pixel format and type of
		surfaces that can be used for drawing.
		For now we just want to use a 16 bit RGB surface that is a
		Window surface, i.e. it will be visible on screen. The list
		has to contain key/value pairs, terminated with EGL_NONE.
	 */
	EGLint pi32ConfigAttribs[] = 
	{
		EGL_DEPTH_SIZE  , 16							,
		EGL_SURFACE_TYPE, EGL_WINDOW_BIT|EGL_PBUFFER_BIT,
		EGL_NONE
	};

	/*
		Step 4 - Find a config that matches all requirements.
		eglChooseConfig provides a list of all available configurations
		that meet or exceed the requirements given as the second
		argument. In most cases we just want the first config that meets
		all criteria, so we can limit the number of configs returned to 1.
	*/
	EGLint iConfigs;
	if (!eglChooseConfig(eglDisplay, pi32ConfigAttribs, &eglConfig, 1, &iConfigs) || (iConfigs != 1))
	{
		printf("Error: eglChooseConfig() failed.\n");
		return false;
	}

	/*
		Step 5 - Create a surface to draw to.
		Use the config picked in the previous step and the native window
		handle when available to create a window surface. A window surface
		is one that will be visible on screen inside the native display (or
		fullscreen if there is no windowing system).
		Pixmaps and pbuffers are surfaces which only exist in off-screen
		memory.
	*/
	eglSurface = eglCreateWindowSurface(eglDisplay, eglConfig, (NativeWindowType)0, NULL);
	if (!testEGLError("eglCreateWindowSurface"))
	{
		return false;
	}

	/*
		Step 6 - Create a context.
		EGL has to create a context for OpenGL ES. Our OpenGL ES resources
		like textures will only be valid inside this context
		(or shared contexts)
	*/
	eglContext = eglCreateContext(eglDisplay, eglConfig, NULL, NULL);
	if (!testEGLError("eglCreateContext"))
	{
		return false;
	}

	/*
		Step 7 - Bind the context to the current thread and use our
		window surface for drawing and reading.
		Contexts are bound to a thread. This means you don't have to
		worry about other threads and processes interfering with your
		OpenGL ES application.
		We need to specify a surface that will be the target of all
		subsequent drawing operations, and one that will be the source
		of read operations. They can be the same surface.
	*/
	eglMakeCurrent(eglDisplay, eglSurface, eglSurface, eglContext);
	if (!testEGLError("eglMakeCurrent"))
	{
		return false;
	}

	/*
		Step 8 - Draw something with OpenGL ES.
		At this point everything is initialized and we're ready to use
		OpenGL ES to draw something on the screen.
	*/

	GLSetDefaultLight();

	// Sets the clear color.
	// The colours are passed per channel (red,green,blue,alpha) as float values from 0.0 to 1.0
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // black

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glEnable(GL_LIGHTING);


	glEnable(GL_DEPTH_TEST); /* enable depth testing; required for z-buffer */
	//glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE); /* enable polygon face culling */

	glFrustumf(-10,10,-10,10,10,800);
	
	return true;
}

void GLContext::cleanup()
{
	// Delete the VBO as it is no longer needed
	glDeleteBuffers(1, &ui32Vbo);
	eglMakeCurrent(eglDisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT) ;
	eglTerminate(eglDisplay);
}

void GLContext::GLSetDefaultLight( )
{
	glShadeModel( GL_SMOOTH );
	glLightModelf( GL_LIGHT_MODEL_TWO_SIDE, 0 );

	glLightfv ( GL_LIGHT0,GL_AMBIENT, kOGLDefaultLightAmbient );
	glLightfv ( GL_LIGHT0,GL_SPECULAR, kOGLDefaultLightSpecular );
	glLightfv ( GL_LIGHT0,GL_DIFFUSE, kOGLDefaultLightDiffuse );

	const float FVector0[] = { -0.2f, 0.2f, 0.6f, 0.0f };

	glLightfv( GL_LIGHT0, GL_POSITION, FVector0 );
	glLightf ( GL_LIGHT0, GL_SPOT_CUTOFF, 180.0f );
	glLightf ( GL_LIGHT0, GL_SPOT_EXPONENT, 0.0f);
	glLightf ( GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0f );
	glLightf ( GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.0f );
	glLightf ( GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0f );

	glEnable(GL_LIGHT0);

	// Light two
	glLightfv ( GL_LIGHT1,GL_AMBIENT, kOGLDefaultLightAmbient );
	glLightfv ( GL_LIGHT1,GL_SPECULAR, kOGLDefaultLightSpecular );
	glLightfv ( GL_LIGHT1,GL_DIFFUSE, kOGLDefaultLightDiffuse );

	const float FVector1[] = { 0.6f, 0.4f, -0.75f, 0.0f };

	glLightfv( GL_LIGHT1,GL_POSITION,FVector1 );
	glLightf ( GL_LIGHT1, GL_SPOT_CUTOFF, 180.0f );
	glLightf ( GL_LIGHT1, GL_SPOT_EXPONENT, 0.0f );
	glLightf ( GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.0f );
	glLightf ( GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.0f );
	glLightf ( GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0 );

	glEnable(GL_LIGHT1);
	glEnable(GL_NORMALIZE);
}

bool GLContext::testEGLError(const char* pszLocation)
{
	/*
		eglGetError returns the last error that has happened using egl,
		not the status of the last called function. The user has to
		check after every single egl call or at least once every frame.
	*/
	EGLint iErr = eglGetError();
	if (iErr != EGL_SUCCESS)
	{
		printf("%s failed (%d).\n", pszLocation, iErr);
		return false;
	}

	return true;
}

void GLContext::swapBuffers()
{
	eglSwapBuffers(eglDisplay, eglSurface);
}

/******************************************************************************/
/*                                EOF                                         */
/******************************************************************************/
