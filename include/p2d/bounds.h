/*! \file bounds.h
	\author HiddenSeeker

	Defines a bounds, useful for representing a solid walls
 */
#include "collisionshape.h"
#include "point.h"
#pragma once

namespace p2d
{

/*! Bound type defines how bound behaves
 */
enum BoundType
{
	BT_LEFT,  //!<  A left bound reacts on objects from left
	BT_RIGHT, //!<  A right bound reacts on objects from right
	BT_DOWN,  //!<  A down bound reacts on object from below
	BT_UP     //!<  An up bound reacts on objects upper than specified
};

class Bound: public p2d::CollisionShape
{
 SAD_OBJECT;
 protected:
	 BoundType m_type; //!< Type of bound
	 double    m_p;    //!< Coordinate of bound
 public:
	 /*! As a default bound of zero as down
	  */
	 inline Bound() { m_type = p2d::BT_DOWN; m_p = 0; }
	 /*! Defines a type 
		 \return type
	  */
	 inline p2d::BoundType type() const { return m_type; }
	 /*! Returns position of bound
		 \return position of bound
	  */
	 inline double position() const { return m_p; }
	 /*! Sets new type for bound
		 \param[in] b type
	  */
	 inline void setType(p2d::BoundType b) { m_type = b;}
	 /*! Sets a position for position
		 \param[in] p position
	  */
	 inline void setPosition(double p) { m_p = p;}
	 /*! Returns new identical bound
		\return rectangle
	 */
	p2d::CollisionShape * clone() const;
	/*! Returns a center of rectangle
		\return center of rectangle
	 */
	p2d::Point center() const;
	/*! Does absolutely nothing
		\param[in] angle angle to rotate
	 */
	void rotate(double angle);
	/*! Does nothing
		\param[in] d distance to move
	 */
	void move(const p2d::Vector & d);
	/*! Returns nothing
	 */
	p2d::ConvexHull toHull() const;
	/*! Returns nothing
		\param[in] a axle
		\return cutter
	 */
	p2d::Cutter1D project(const p2d::Axle & a) const;
	/*! Whether two bounds are orthogonal
		\param[in] b2 other bound
	 */
	inline bool isOrthogonal(Bound * b2)
	{
		p2d::BoundType bt1 = this->type();
		p2d::BoundType bt2 = b2->type();
		return ((bt1 == BT_LEFT || bt1 == BT_RIGHT) && (bt2  == BT_UP || bt2 == BT_DOWN))  ||
			   ((bt1 == BT_UP || bt1 == BT_DOWN) && (bt2  == BT_LEFT || bt2 == BT_RIGHT));		
	}
};


}

