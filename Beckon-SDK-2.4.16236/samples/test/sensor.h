#include "Shadow/IMotionSensor.h"
#include "Tracking.h"

static ISensor* sensor = NULL;
static IMotionSensor *pSensor = IMotionSensor::createCameraSensor();

