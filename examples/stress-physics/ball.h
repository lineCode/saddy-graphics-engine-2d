/*! \file ball.h
	\author HiddenSeeker

	Describes a ball
 */
#pragma once
#include <p2d/app/object.h>
#include <p2d/app/constants.h>
#include <log/log.h>
#include <log/filetarget.h>

/*! As a default, grid node is a node
 */
class Ball: public sad::p2d::app::Object
{
SAD_OBJECT
public:
	 Ball();

	 ~Ball();
	 virtual void render();

	 inline sad::log::Log * log() 
	 {
		return m_log;
	 }
protected:
	sad::log::Log * m_log;
};
