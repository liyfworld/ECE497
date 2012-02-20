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

namespace Omek {
	enum eEventType {EVENTTYPE_NONE = -1, EVENTTYPE_GESTURE, EVENTTYPE_ALERT, EVENTTYPE_NEW_FRAME};

/** 
@class IFiredEvent IFiredEvent.h "include/Shadow/IFiredEvent.h"
@brief Object interface that event listeners
*/

class _ShadowExport IFiredEvent
{
public:
	virtual IFiredEvent* createIFiredEvent() const = 0;
	/** @return the type of this event 
		@see eEventType */
	virtual eEventType getType() const = 0;

	/** @return the unique ID of this event */
	virtual unsigned int getId() const = 0;
	virtual unsigned long getTimestamp() const = 0;
	virtual unsigned long getFrameNum() const = 0;

	/** @return the ID of the relevant player, or SHADOW_PLAYER_UNDEFINED, when no such player exists */
	virtual int getPlayerId() const = 0;
	virtual const char* getName() const = 0;

	/** relevant only for gesture event */
	virtual float getConfidence() const = 0;

	virtual unsigned int getNameLen()const = 0;
};
}

