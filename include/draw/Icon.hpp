/*! \file */ //Copyright 2011-2018 Tyler Gilbert; All Rights Reserved

#ifndef DRAW_ICON_HPP_
#define DRAW_ICON_HPP_


#include "Drawing.hpp"
#include "../sgfx/Vector.hpp"

namespace draw {

/*! \brief Icon Attributes Class
 * \ingroup element
 * \details This class defines the attributes of a Gfx object.
 */

class IconAttr : public api::DrawInfoObject {
public:

	enum sys_gfx {
		OK,
		CHEVRON,
		TOTAL
	};



	/*! \details Icon rotation orientations */
	enum {
		RIGHT /*! \brief Point to the right */ = 0,
		DOWN /*! \brief Point down */ = SG_TRIG_POINTS/4,
		LEFT /*! \brief Point to the left */ = SG_TRIG_POINTS/2,
		UP /*! \brief Point up */ = SG_TRIG_POINTS*3/4,
		QUARTER_CLOCKWISE /*! \brief Add/subtract to/from RIGHT, DOWN, etc */ = SG_TRIG_POINTS/4,
		QUARTER_COUNTER_CLOCKWISE /*! \brief Add/subtract to/from RIGHT, DOWN, etc */ = -SG_TRIG_POINTS/4,
		EIGHTH_CLOCKWISE /*! \brief Add/subtract to/from RIGHT, DOWN, etc */  = SG_TRIG_POINTS/8,
		EIGHTH_COUNTER_CLOCKWISE /*! \brief Add/subtract to/from RIGHT, DOWN, etc */  = -SG_TRIG_POINTS/8,
	};

	sgfx::Pen & pen(){ return m_pen; }
	const sgfx::Pen & pen_const() const { return m_pen; }

	/*! \details Set the rotation */
	void set_rotation(s16 rotation){ m_rotation = rotation; }

	/*! \details Returns the rotation */
	s16 rotation() const { return m_rotation; }

private:
	sgfx::Pen m_pen;
	s16 m_rotation;
};

/*! \brief Icon Class
 * \details This class draws icons that can be scaled and rotated on a bitmap.
 *
 * When an icon is drawn, the icon's pen attributes are used to draw on
 * the bitmap.
 *
 */

class Icon : public Drawing, public IconAttr {
public:
	/*! \details Construct an empty graphic */
	Icon();

	/*! \details Draws the graphic to scale on the specified bitmap */
	virtual void draw_to_scale(const DrawingScaledAttr & attr);

	/*! \details This returns the bounds of the icon.  It is only valid after
	 * the icon has been drawn on a bitmap.
	 *
	 * @return The bounds of the last time this icon was drawn on a bitmap using draw_to_scale()
	 */
	sg_region_t & bounds(){ return m_bounds; }

private:
	sg_region_t m_bounds;

};

}


#endif /* DRAW_ICON_HPP_ */
