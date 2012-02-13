/************************************************************************/
/*                              Includes                                */
/************************************************************************/

#include <iostream>
#include <string.h>

#include <sys/types.h>
#include <fcntl.h>
#include <termios.h>

#include "Tracking.h"
#include "GLContext.h"
#include "RenderContext.h"


using namespace std;
using namespace Omek;


/************************************************************************/
/*                         Auxiliary stuff                              */
/************************************************************************/

static struct termios oldt;

// default behavior for key input is to wait for an Enter key
// we don't want that.
void disable_waiting_for_enter(void)
{
	struct termios newt;

	/* Make terminal read 1 char at a time */
	tcgetattr(0, &oldt);  /* Save terminal settings */
	newt = oldt;  /* Init new settings */
	newt.c_lflag &= ~(ICANON | ECHO);  /* Change settings */
	tcsetattr(0, TCSANOW, &newt);  /* Apply settings */
	//atexit(restore_terminal_settings); /* Make sure settings will be restored when program ends  */
}

// restore to default behavior (wait for Enter)
void restore_terminal_settings(void)
{
	tcsetattr(0, TCSANOW, &oldt);  /* Apply saved settings */
}

/************************************************************************/
/*                                 Main                                 */
/************************************************************************/

int main(int argc, char* argv[])
{
	// Read input parameters.
	char* sequence = NULL;
	int ret = 0;
	bool keepRunning = true;
	bool frontView = true;

	for(int i=1; i < argc; i++)
	{
		if(strcmp(argv[i], "-seq") == 0)
		{
			sequence = argv[i+1];
		}
	}

	// We want to read the input without waiting... (for the exit key)
	int n, tem;
	tem = fcntl(0, F_GETFL, 0);
	fcntl (0, F_SETFL, (tem | O_NDELAY));
	disable_waiting_for_enter();

	// Initialize tracking and rendering.
	Tracking 		tracking;
	RenderContext 	renderContext;

	if(!tracking.initialize(sequence))
	{
		cerr << "Failed to initialize tracking !" << endl;
		ret = 1;
		goto end;
	}

	if(!GLContext::getInstance().initialize())
	{
		cerr << "Failed to initialize OGLES !" << endl;
		ret = 1;
		goto end;

	}

	// Render loop.
	while(tracking.updateFrame() && keepRunning)
	{
		if(!renderContext.renderJoints(tracking.getSkeleton(), frontView))
		{
			ret = 1;
			goto end;
		}

		
		// Read keyboard input.
		char c;
		n = read(0, &c, 1);
		if(n > 0)
		{
			switch(c)
			{
				case 0x1B:
					// leave the app
					keepRunning = false;
					break;
				case ' ':	
					// switch view
					frontView = !frontView;
					break;
				case 'r':	
					// start/stop recording
					tracking.toggleRecording();
					break;
				
			}//<=switch(c)
				
		}//<=if(n > 0)

	}//<=while(tracking.updateFrame() && keepRunning)

	end:
	// Restore terminal settings.
	fcntl(0, F_SETFL, tem);
	restore_terminal_settings();	
	return ret;
}



/************************************************************************/
/*                                EOF                                   */
/************************************************************************/
