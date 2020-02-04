#ifndef SAPI_UX_SLIDER_HPP
#define SAPI_UX_SLIDER_HPP

#include "Component.hpp"
#include "TouchGesture.hpp"

namespace ux {

class SliderEvent : public EventObject<EVENT_TYPE('_','s','l','d')> {
   public:

   SliderEvent(
            const var::String name,
            u16 value,
            u16 maximum) :
      EventObject<EVENT_TYPE('_','s','l','d')>(0),
      m_name(name),
      m_value(value),
      m_maximum(maximum){

   }

   const var::String & name() const {
      return m_name;
   }

   const u16 value() const {
      return m_value;
   }

   const u16 maximum() const {
      return m_maximum;
   }

   private:
   const var::String & m_name;
   u16 m_value;
   u16 m_maximum;

};

class Slider : public Component {
public:
   Slider();

   void draw(const DrawingAttributes & attributes);
   void handle_event(const ux::Event & event);

   u16 value(){ return m_value; }
   u16 maximum(){ return m_maximum; }

   Slider & set_value(u16 value){
      m_value = value;
      return *this;
   }

   Slider & set_maximum(u16 value){
      m_maximum = value;
      return *this;
   }

private:
   u16 m_value;
   u16 m_maximum;

};

}

#endif // SLIDER_HPP