#ifndef TRACKING_H
#define TRACKING_H

#include <QObject>
#include <QStringList>

#include "Shadow/ISensor.h"
#include "Shadow/IMotionSensor.h"

using namespace Omek;

class Tracking : public QObject
{
    Q_OBJECT
public:
    explicit Tracking(QObject *parent = 0);

    virtual ~Tracking();

    /**
            Initializes the Tracking object
            @param[in] sequenceFileName the name of the sequence (or NULL for camera use)
            @return 0 in case of success and 1 otherwise
    */
    int initialize(char* sequenceFileName);

    /**
            Get the width of the image
            @return the width the image
    */
    int getImageWidth();

    /**
            Get the height of the image
            @return the height the image
    */
    int getImageHeight();

signals:

    /**
            Sent to Tracking Window in order to update the Depth image
            @param[in] image depth buffer
    */
    void updateDepthImage(unsigned char * image);

    /**
            Sent to Tracking Window in order to update the Mask image
            @param[in] image mask buffer
    */
    void updateMaskImage(unsigned char * image);

    /**
            Sent to Tracking Window in order to add Joint point to the display.
            @param[in] x  the x coordinate of the Joint position in screen coordinate system.
            @param[in] y  the y ocordinate of the Joint position in screen coordinate system.
            @param[in] id the Joint ID.
    */
    void addPoint(unsigned int x, unsigned int y, JointID id);

    /**
            Sent if the sensor is not alive
    */
    void shutdown();

public slots:

    /**
            Updates the frame on every timeout event
    */
    void updateFrame();

    /**
            Start/stop recording according to the given state.
            @param[in] state    if true start recording; if false stop.
     */
    void recordOrStop(bool state);

private:
    /// holds the mask image
    unsigned char *m_maskBuffer;

    /// holds the depth image
    unsigned char *m_depthBuffer;

    /// holds the information about the motion sensor
    IMotionSensor *m_pSensor;

    /// holds the information about the skeleton
    ISkeleton *m_pSkeleton;

    /// image width
    int m_imageWidth;

    /// image height
    int m_imageHeight;

    /// used to indicate if there is an active tracking
    bool m_isTracking;
};

#endif // TRACKING_H
