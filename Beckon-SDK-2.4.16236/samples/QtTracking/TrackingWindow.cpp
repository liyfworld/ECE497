#include <iostream>

#include <qevent.h>
#include "TrackingWindow.h"

using namespace std;
using namespace Omek;

unsigned short	colorMapDepthConversionLUT[256] = {
0xf820, 0xf840, 0xf860, 0xf880, 0xf8c0, 0xf8e0, 0xf900, 0xf920,
0xf940, 0xf960, 0xf980, 0xf980, 0xf9a0, 0xf9e0, 0xf9e0, 0xfa00,
0xfa20, 0xfa40, 0xfa60, 0xfa80, 0xfaa0, 0xfae0, 0xfb20, 0xfb40,
0xfb80, 0xfbc0, 0xfc00, 0xfc20, 0xfc60, 0xfca0, 0xfcc0, 0xfd00,
0xfd40, 0xfd80, 0xfda0, 0xfde0, 0xfe20, 0xfe40, 0xfe40, 0xfe80,
0xfec0, 0xff00, 0xff20, 0xff60, 0xffa0, 0xffc0, 0xffe0, 0xefe0,
0xe7e0, 0xdfe0, 0xcfe0, 0xc7e0, 0xbfe0, 0xafe0, 0xa7e0, 0x9fe0,
0x97e0, 0x87e0, 0x7fe0, 0x77a1, 0x77a1, 0x7781, 0x6f42, 0x6723,
0x66e3, 0x5ec4, 0x56a5, 0x4e66, 0x4e46, 0x4607, 0x3de8, 0x3dc8,
0x3589, 0x2d6a, 0x2d2a, 0x250b, 0x1cec, 0x14ad, 0x148d, 0x0c6e,
0x042f, 0x040f, 0x03f0, 0x03f0, 0x03f0, 0x03d1, 0x03d1, 0x03b1,
0x03b2, 0x0392, 0x0372, 0x0b73, 0x0b53, 0x0b54, 0x0b34, 0x0b34,
0x0b15, 0x0b15, 0x0af5, 0x0af6, 0x0ad6, 0x12d6, 0x12b7, 0x12b7,
0x1298, 0x1298, 0x1278, 0x1278, 0x1259, 0x1259, 0x123a, 0x1a3a,
0x1a1a, 0x1a1b, 0x19fb, 0x19fb, 0x19dc, 0x19dc, 0x19bd, 0x21bd,
0x219d, 0x217e, 0x217e, 0x215e, 0x215f, 0x213f, 0x213f, 0x213f,
0x213f, 0x213f, 0x213f, 0x213f, 0x213f, 0x213f, 0x211f, 0x211f,
0x211f, 0x211f, 0x211f, 0x211f, 0x211f, 0x211f, 0x211f, 0x211f,
0x211f, 0x211f, 0x211f, 0x18ff, 0x18ff, 0x18ff, 0x18ff, 0x18ff,
0x18ff, 0x18ff, 0x18ff, 0x18ff, 0x18ff, 0x18ff, 0x18ff, 0x18ff,
0x18ff, 0x18ff, 0x18df, 0x18df, 0x18df, 0x18df, 0x18df, 0x18df,
0x18df, 0x18df, 0x18df, 0x18df, 0x18df, 0x18df, 0x18df, 0x18df,
0x10bf, 0x10bf, 0x10bf, 0x10bf, 0x10bf, 0x10bf, 0x10bf, 0x10bf,
0x10bf, 0x10bf, 0x10bf, 0x10bf, 0x10bf, 0x109f, 0x109f, 0x109f,
0x109f, 0x109f, 0x109f, 0x109f, 0x109f, 0x109f, 0x109f, 0x109f,
0x109f, 0x109f, 0x109f, 0x087f, 0x087f, 0x087f, 0x087f, 0x087f,
0x087f, 0x087f, 0x087f, 0x087f, 0x087f, 0x087f, 0x087f, 0x087f,
0x085f, 0x085f, 0x085f, 0x085f, 0x085f, 0x085f, 0x085f, 0x085f,
0x085f, 0x085f, 0x085f, 0x085f, 0x085f, 0x085f, 0x003f, 0x003f,
0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f,
0x003f, 0x003f, 0x003f, 0x003f, 0x001f, 0x001f, 0x001f, 0x001f,
0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f};

TrackingWindow::TrackingWindow(unsigned int width, unsigned int height, QWidget *parent) :
    QLabel(parent),
    m_width(width),
    m_height(height),
    m_numberOfPoints(0),
    m_palmColorIndex(1),
    m_elbowColorIndex(2),
    m_shoulderColorIndex(3),
    m_defaultJointColorIndex(4)
{
}

void TrackingWindow::updateDepthImage(unsigned char * image)
{
    short * shortImage = (short*)image;
    unsigned long	tempDepth;

    // find the color for each pixel
    for(unsigned int i=0; i < m_width*m_height; i++)
    {
        tempDepth = (unsigned short)shortImage[i];
        tempDepth = (tempDepth)>>2;
        if(tempDepth > 255)
                tempDepth = 255;
        shortImage[i] = colorMapDepthConversionLUT[tempDepth];
    }

    QImage qimage((uchar*)image, m_width, m_height, QImage::Format_RGB16);
    setPixmap(QPixmap::fromImage(qimage));
}

void TrackingWindow::updateMaskImage(unsigned char * image)
{
    if(image == NULL)
        return;

    QImage qimage((uchar*)image, m_width, m_height, QImage::Format_Indexed8);

    // Joints colors
    static QRgb palm = qRgb(255, 255, 0);
    qimage.setColor(m_palmColorIndex, palm);
    static QRgb elbow = qRgb(0, 255, 255);
    qimage.setColor(m_elbowColorIndex, elbow);
    static QRgb shoulder = qRgb(100, 200, 255);
    qimage.setColor(m_shoulderColorIndex, shoulder);
    static QRgb center = qRgb(255, 100, 255);
    qimage.setColor(m_defaultJointColorIndex, center);


    // mask color
    static QRgb maskColor = qRgb(200, 64, 64);
    qimage.setColor(255, maskColor);

    // background color
    static QRgb backgroundColor = qRgb(0, 0, 0);
    qimage.setColor(0, backgroundColor);

    if(m_numberOfPoints > 0)
    {
        // display the tracked points
        for(unsigned int i=0; i < m_numberOfPoints; i++)
        {
            qimage.setPixel(m_pointsArray[i].point.x()-1,m_pointsArray[i].point.y(),
                            m_pointsArray[i].maskColorIndex);
            qimage.setPixel(m_pointsArray[i].point.x()+1, m_pointsArray[i].point.y(),
                            m_pointsArray[i].maskColorIndex);
            qimage.setPixel(m_pointsArray[i].point.x()-2, m_pointsArray[i].point.y(),
                            m_pointsArray[i].maskColorIndex);
            qimage.setPixel(m_pointsArray[i].point.x()+2, m_pointsArray[i].point.y(),
                            m_pointsArray[i].maskColorIndex);
            qimage.setPixel(m_pointsArray[i].point.x(), m_pointsArray[i].point.y()-1,
                            m_pointsArray[i].maskColorIndex);
            qimage.setPixel(m_pointsArray[i].point.x(), m_pointsArray[i].point.y()+1,
                            m_pointsArray[i].maskColorIndex);
            qimage.setPixel(m_pointsArray[i].point.x(), m_pointsArray[i].point.y()-2,
                            m_pointsArray[i].maskColorIndex);
            qimage.setPixel(m_pointsArray[i].point.x(), m_pointsArray[i].point.y()+2,
                            m_pointsArray[i].maskColorIndex);
        }
    }
    setPixmap(QPixmap::fromImage(qimage));

    m_numberOfPoints=0;
}

void TrackingWindow::addPoint(unsigned int x, unsigned int y,
                              JointID id)
{
    // set the color of each Joint according to its position

    static unsigned int id2color[SHADOW_JOINTS_NUM] =
    {
        m_defaultJointColorIndex,    // JointID_unknown = 0,
        m_defaultJointColorIndex,    // JointID_head,
        m_defaultJointColorIndex,    // JointID_torso,
        m_defaultJointColorIndex,    // JointID_neck,
        m_palmColorIndex,           // JointID_rightFingerTip,
        m_palmColorIndex,           // JointID_leftFingerTip,
        m_shoulderColorIndex,       // JointID_rightHand,
        m_shoulderColorIndex,       // JointID_leftHand,
        m_shoulderColorIndex,       // JointID_rightShoulder,
        m_shoulderColorIndex,       // JointID_leftShoulder,
        m_elbowColorIndex,          // JointID_rightElbow,
        m_elbowColorIndex,          // JointID_leftElbow,
        m_defaultJointColorIndex,    // JointID_rightCollar,
        m_defaultJointColorIndex,    // JointID_leftCollar,
        m_defaultJointColorIndex,    // JointID_hips,
        m_defaultJointColorIndex,    // JointID_rightKnee,
        m_defaultJointColorIndex,    // JointID_leftKnee,
        m_defaultJointColorIndex,    // JointID_rightFoot,
        m_defaultJointColorIndex,    // JointID_leftFoot,
        m_defaultJointColorIndex,    // JointID_rightHip,
        m_defaultJointColorIndex,    // JointID_leftHip,
        m_defaultJointColorIndex,    // JointID_spine1,
        m_defaultJointColorIndex,    // JointID_spine2,
        m_defaultJointColorIndex,    // JointID_spine3,
        m_defaultJointColorIndex,    // JointID_spine4,
        m_defaultJointColorIndex     // JointID_waist
    };


    if((x < m_width-1) && (y < m_height-1))
    {
        m_pointsArray[m_numberOfPoints].point.setX(x);
        m_pointsArray[m_numberOfPoints].point.setY(y);
        m_pointsArray[m_numberOfPoints].maskColorIndex = id2color[id];
        m_numberOfPoints++;
    }
}
