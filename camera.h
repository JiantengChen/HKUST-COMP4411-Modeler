// This camera stuff mostly by ehsu

#ifndef CAMERA_H
#define CAMERA_H

#include "vec.h"
#include "mat.h"

//==========[ class Camera ]===================================================

typedef enum
{
    kActionNone,
    kActionTranslate,
    kActionRotate,
    kActionZoom,
    kActionTwist,
} MouseAction_t;

class Camera
{

protected:
    float mElevation;
    float mAzimuth;
    float mDolly;
    float mTwist; // Not implemented yet

    Vec3f mLookAt;

    Vec3f mPosition;
    Vec3f mUpVector;
    bool mDirtyTransform;

    void calculateViewingTransformParameters();

    Vec3f mLastMousePosition;
    MouseAction_t mCurrentMouseAction;

public:
    //---[ Constructors ]----------------------------------

    // defaults to (0,0,0) facing down negative z axis
    Camera();

    //---[ Settings ]--------------------------------------

    inline void setElevation(float elevation)
    {
        // don't want elevation to be negative
        if (elevation < 0)
            elevation += 6.28318530717f;
        mElevation = elevation;
        mDirtyTransform = true;
    }
    inline float getElevation() const
    {
        return mElevation;
    }

    inline void setAzimuth(float azimuth)
    {
        mAzimuth = azimuth;
        mDirtyTransform = true;
    }
    inline float getAzimuth() const
    {
        return mAzimuth;
    }

    inline void setDolly(float dolly)
    {
        mDolly = dolly;
        mDirtyTransform = true;
    }
    inline float getDolly() const
    {
        return mDolly;
    }

    inline void setTwist(float twist)
    {
        mTwist = twist;
        mDirtyTransform = true;
    }
    inline float getTwist() const
    {
        return mTwist;
    }

    inline void setLookAt(const Vec3f &lookAt)
    {
        mLookAt = lookAt;
        mDirtyTransform = true;
    }
    inline Vec3f getLookAt() const
    {
        return mLookAt;
    }

    inline void frameAll(const float dx, const float dy, const float dz)
    {
        // mPosition = Vec3f(2.0f + dx, 10.0f + dy, 20.0f + dz);
        // mLookAt = Vec3f(1.400000f + dx, -2.700000f + dy, -5.000000f + dz);
        // mUpVector = Vec3f(0.0f, 1.0f, 0.0f);
        // mAzimuth = 3.086036f;
        // mElevation = 6.316516f;
        // mDolly = -20.000000f;
        // mTwist = 0.000000f;
        // mDirtyTransform = false;

        // 		mElevation	6.24985266	float
        // 		mAzimuth	2.98603535	float
        // 		mDolly	-24.4799957	float
        // 		mTwist	0.00000000	float
        // +		mLookAt	{n=0x007cf510 {2.09999895, 0.529236019, -0.107281998} }	Vec3<float>
        // +		mPosition	{n=0x007cf51c {-1.69059706, -0.286596000, 24.0636921} }	Vec3<float>
        // +		mUpVector	{n=0x007cf528 {0.00000000, 1.00000000, 0.00000000} }	Vec3<float>

        mPosition = Vec3f(-1.69059706f + dx, -0.286596000f + dy, 24.0636921f + dz);
        mLookAt = Vec3f(2.09999895f + dx, 0.529236019f + dy, -0.107281998f + dz);
        mUpVector = Vec3f(0.0f, 1.0f, 0.0f);
        mAzimuth = 2.98603535f;
        mElevation = 6.24985266f;
        mDolly = -24.4799957f;
        mTwist = 0.00000000f;
        mDirtyTransform = false;

        double _position[3] = {mPosition[0], mPosition[1], mPosition[2]};
        double _lookAt[3] = {mLookAt[0], mLookAt[1], mLookAt[2]};
        double _up[3] = {mUpVector[0], mUpVector[1], mUpVector[2]};

        lookAt(_position, _lookAt, _up);
    }

    //---[ Interactive Adjustment ]------------------------
    // these should be used from a mouse event handling routine that calls
    // the startX method on a mouse down, updateX on mouse move and finally
    // endX on mouse up.
    //-----------------------------------------------------
    void clickMouse(MouseAction_t action, int x, int y);
    void dragMouse(int x, int y);
    void releaseMouse(int x, int y);

    //---[ Viewing Transform ]--------------------------------
    void applyViewingTransform();

    // gluLookAt equivalent
    void Camera::lookAt(double *eye, double *at, double *up);
};

#endif