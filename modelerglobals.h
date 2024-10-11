#ifndef _MODELER_GLOBALS_H
#define _MODELER_GLOBALS_H

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502
#endif

// This is a list of the controls for the SampleModel
// We'll use these constants to access the values
// of the controls from the user interface.
enum SampleModelControls
{
	XPOS,
	YPOS,
	ZPOS,

	LOD,

	LIGHT0_X,
	LIGHT0_Y,
	LIGHT0_Z,

	LIGHT1X,
	LIGHT1Y,
	LIGHT1Z,

	LIGHT0_R,
	LIGHT0_G,
	LIGHT0_B,

	LIGHT1R,
	LIGHT1G,
	LIGHT1B,

	NECK_ANGLE,
	HEAD_ANGLE_X,
	HEAD_ANGLE_Z,

	LEFT_FRONT_ANGLE1,
	LEFT_FRONT_ANGLE2,
	LEFT_FRONT_ANGLE3,
	RIGHT_FRONT_ANGLE1,
	RIGHT_FRONT_ANGLE2,
	RIGHT_FRONT_ANGLE3,
	LEFT_BACK_ANGLE1,
	LEFT_BACK_ANGLE2,
	LEFT_BACK_ANGLE3,
	RIGHT_BACK_ANGLE1,
	RIGHT_BACK_ANGLE2,
	RIGHT_BACK_ANGLE3,

	RIGHT_BACK_THETA,
	TAIL_ANGLE_X,
	TAIL_ANGLE_Y,
	TAIL_ANGLE_Z,

	NUMCONTROLS,

};

// Colors
#define COLOR_RED 1.0f, 0.0f, 0.0f
#define COLOR_GREEN 0.0f, 1.0f, 0.0f
#define COLOR_BLUE 0.0f, 0.0f, 1.0f

// We'll be getting the instance of the application a lot;
// might as well have it as a macro.
#define VAL(x) (ModelerApplication::Instance()->GetControlValue(x))

#endif