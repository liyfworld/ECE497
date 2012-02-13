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

#include <string>
#include "Shadow/Platform.h"
#include "Shadow/ShadowDefines.h"

namespace Omek {

	class CameraImpl;

	/** 
		@class ISensor ISensor.h "include/Shadow/ISensor.h"

		@brief The ISensor class serves as both an interface to a connected 3D depth sensor, as well as a 
		virtual camera simulating a real camera by using a specified sequence.
	*/

	class _ShadowExport ISensor
	{
	public:
		/// @return the current frame number
		virtual unsigned long getFramenum() const = 0;

		/** 
			@brief Set the current frame number
			
			@param[in] frameNum the new frame-number to go to
			@return true if a valid frame was entered, and the sequence was advanced successfully
		*/
		virtual bool goToFramenum(unsigned long frameNum) = 0;

		/// @return the time stamp for the current frame (in milliseconds)
		virtual unsigned long getFrameTimestamp() const = 0;

		/// @return the total number of frames in a sequence, or 0 for error
		virtual int getNumOfFrames() const = 0;

		/**
			@return the current camera status - connected, not-connected, EOF, etc.
		*/
		virtual CameraStatus getStatus() const  = 0;

		/**
			@brief In sequence mode this will return false when reached the end of the sequence/or when there are no more frames to show 
			In camera mode this will return true unless an error occurred, or the camera was not connected
		
			@return true if more frames are available, false otherwise
		*/
		virtual bool isAlive() const = 0;

		/**
			@brief Set specific sensor parameters 
		
			@param[in] name can be one of the following values, depending on specific sensor: \n
						"flipped" - set to 1 to flip raw data input horizontally (mirror), 0 for default \n
						"enableRGB" - set to 1 to grab RGB or IR data (depending on camera), or 0 to grab depth only \n
						"matchRGB" - set to 1 for a 1-to-1 pixel match of RGB and depth data, or 0 to disable. This is
									 typically a CPU heavy operation, and thus it is turned off by default. \n
						"outDepthRes" - set to higher depth resolutions IMAGE_RESOLUTION_QQVGA, IMAGE_RESOLUTION_QVGA, or IMAGE_RESOLUTION_VGA \n
						"outImageRes" - set to higher RGB resolutions IMAGE_RESOLUTION_QQVGA, IMAGE_RESOLUTION_QVGA, or IMAGE_RESOLUTION_VGA \n
						"frequency" - change the operating frequency of the sensor (if supported by sensor)
			@param[in] value the new value to set parameter to 

			@return OMK_SUCCESS for success, an error code otherwise
		*/
		virtual OMKStatus setCameraParameter(const char* name, int value) = 0;


		/**
			@brief Get specific sensor parameters 
		
			@param[in] name can be one of the following values, depending on specific sensor: \n
						"flipped" - 1 if raw data input is flipped horizontally (mirror), 0 otherwise \n
						"enableRGB" - 1 sensor is grabbing RGB/IR, 0 otherwise \n
						"frequency" - get the operating frequency of the sensor, if supported \n
						"serial" - get the serial number for connected sensor, if supported \n
			@param[out] value the return value for the requested parameter

			@return OMK_SUCCESS for success, an error code otherwise
		*/
		virtual OMKStatus getCameraParameter(const char* name, int& value) const = 0;

		/**
			@brief Get the image width.
			@param[in] imageType the imageType (color/ depth/ mask)
			@return the color/depth/mask width of a frame.
		*/
		virtual int getImageWidth(ImageType imageType) const = 0;
		
		/**
			@brief Get the image height.
			@param[in] imageType the imageType (color/ depth / mask).
			@return the color/depth/mask height of a frame
		*/
		virtual int getImageHeight(ImageType imageType) const = 0;
		
		/**
			@brief Get the image channels number.
			@param[in] imageType the imageType (color/ depth/ mask)
			@return the color/depth/mask channels of a frame
		*/
		virtual int getImageChannels(ImageType imageType) const = 0;
		
		/**
			@brief Get the image bit per pixel
			@param[in] imageType the imageType (color/ depth/ mask)
			@return the depth of a pixel in the color/depth/mask image (bit per pixel).
		*/
		virtual int getImageBpp(ImageType imageType) const = 0;
					
		/// @return the frames per second
		virtual int getFps() const = 0;

		/**
			@param[in] bShortName "true" (default) will return the short (single word) version,
				   while "false" returns the full name
			@return the name of the current camera 
		*/
		virtual const char* getCameraName(bool bShortName=true) const = 0;

	};
}
