#ifndef SAPI_UX_COMPONENT_HPP
#define SAPI_UX_COMPONENT_HPP

#include "../api/WorkObject.hpp"
#include "../sgfx/Bitmap.hpp"
#include "../var/String.hpp"
#include "Drawing.hpp"
#include "Event.hpp"

namespace ux {

class Scene;

class Component : public Drawing {
public:

   using EventHandlerFunction = std::function<void(void * context, const Event & event)>;
   Component();
   ~Component(){}

   Component & set_event_handler(EventHandlerFunction event_handler){
      m_event_handler = event_handler;
      return *this;
   }

   Component & set_context(void * context){
      m_context = context;
      return *this;
   }

   Component & set_name(const var::String & name){
      m_name = name;
      return *this;
   }

   Component & set_drawing_area(const DrawingArea & drawing_area){
      m_drawing_attributes.set_area(drawing_area);
      return *this;
   }

   Component & set_drawing_point(const DrawingPoint & drawing_point){
      m_drawing_attributes.set_point(drawing_point);
      return *this;
   }

   Component & enable();
   Component & disable();

   //update the location of the component (allow animations)

   virtual void handle_event(const ux::Event & event){
      if( m_event_handler ){
         m_event_handler(m_context, event);
      }
   }

protected:
   void refresh_drawing();
   friend class Scene;


private:

   var::String m_name;
   void * m_context;
   u32 m_type_id;
   //needs to know where on the display it is drawn
   DrawingAttributes m_drawing_attributes;
   sgfx::Bitmap m_bitmap;

   //needs a palette to use while drawing
   sgfx::Palette * m_palette;
   Scene * m_scene;
   EventHandlerFunction m_event_handler;

   void set_scene(Scene * scene){
      m_scene = scene;
   }
};


}

#endif // SAPI_UX_COMPONENT_HPP
