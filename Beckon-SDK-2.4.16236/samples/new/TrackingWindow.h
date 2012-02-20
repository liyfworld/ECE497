#ifndef TRACKING_WINDOW_H
#define TRACKING_WINDOW_H

#include <QLabel>
#include <Shadow/ShadowDefines.h>

using namespace Omek;

class TrackingWindow : public QLabel
{
    Q_OBJECT
public:
    explicit TrackingWindow(unsigned int width, unsigned int height, QWidget *parent = 0);

public slots:

    /**
            Updates the depth image
            @param[in] image depth buffer
    */
    void updateDepthImage(unsigned char * image);

    /**
            Updates the mask image
            @param[in] image mask buffer
    */
    void updateMaskImage(unsigned char * image);

    /**
            Adds Joint points to the mask image
            @param[in] x
            @param[in] y
            @param[in] id the ID of the Joint point
    */
    void addPoint(unsigned int x, unsigned int y, JointID id);

private:

    /// Holds the point and the color mask
    struct JointPoint
    {
        unsigned int maskColorIndex;
        QPoint point;
    };

private:

    /// The height and the width of the window
    unsigned int m_width, m_height;

    /// Array of joint points
    JointPoint m_pointsArray[SHADOW_JOINTS_NUM];

    /// Number of points in the array
    unsigned int m_numberOfPoints;

    /// Color indexes of the joint points
    unsigned int m_palmColorIndex;
    unsigned int m_elbowColorIndex;
    unsigned int m_shoulderColorIndex;
    unsigned int m_defaultJointColorIndex;
};

#endif // TRACKING_WINDOW_H
