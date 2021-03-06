/*! \file */ // Copyright 2011-2020 Tyler Gilbert and Stratify Labs, Inc; see LICENSE.md for rights.

#include "sgfx.hpp"
#include "draw/BarProgress.hpp"
using namespace draw;

BarProgress::BarProgress(){}

void BarProgress::draw_to_scale(const DrawingScaledAttr & attr){
	//draw the progress bar on the bitmap with x, y at the top left corner
	sg_size_t thickness;
	thickness = (border_thickness() > 100 ? 100 : border_thickness()) * (attr.area().height() / 2) / 100;

	//draw bar
	if( background_color() != color_transparent() ){
		attr.bitmap() << Pen().set_color( background_color() );
		attr.bitmap().draw_rectangle(attr.region());
	}

	//draw progress
	sg_size_t progress_width = attr.area().width() - thickness*2;

	attr.bitmap() << Pen().set_color( color() );
	attr.bitmap().draw_rectangle(
				attr.point() + Point(thickness, thickness),
				Area(progress_width * value() / maximum(), attr.area().height() - thickness*2)
				);

}
