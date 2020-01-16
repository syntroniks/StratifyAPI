#include "ux/Label.hpp"
#include "ux/Rectangle.hpp"
#include "ux/Text.hpp"
#include "ux/Scene.hpp"

using namespace sgfx;
using namespace ux;

void Label::draw_to_scale(const DrawingScaledAttributes & attributes){
   sg_size_t border_size = attributes.height()/2 * m_border_size / 100;
   if( m_border_size && !border_size ){
      border_size = 1; //at least 1 pixel if non-zero
   }

   const Area icon_area = Area(
            attributes.height() *3/4,
            attributes.height() *3/4
            );

   const Point icon_padding(
            attributes.width()/2 - icon_area.width()/2,
            attributes.height()/2 - icon_area.height()/2
            );

   //draw the Border
   attributes.bitmap() << Pen().set_color(color_border);
   attributes.bitmap().draw_rectangle(
            attributes.region()
            );

   attributes.bitmap() << Pen().set_color(color_default);
   attributes.bitmap().draw_rectangle(
            attributes.point() + Point(border_size, border_size),
            attributes.area() - Area(border_size*2, border_size*2)
            );


   //if the icon is available, draw it
   if( m_icon_name.is_empty() == false ){
      Icon().set_icon(m_icon_name)
            .set_color(color_text)
            .set_align_center()
            .set_align_middle()
            .draw_to_scale(
               attributes + icon_padding + icon_area
               );
   } else if( m_label.is_empty() == false ){
      //if the label is available, draw it
      Text().set_string(m_label)
            .set_font_name(m_font_name)
            .set_alignment(alignment())
            .set_color(color_text)
            .set_align_center()
            .set_align_middle()
            .draw_to_scale(
               attributes
               );
   }

   apply_antialias_filter(attributes);

}
