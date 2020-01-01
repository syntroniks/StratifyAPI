#ifndef SAPI_UX_TOGGLESWITCH_HPP
#define SAPI_UX_TOGGLESWITCH_HPP


#include "Component.hpp"

namespace ux {

class ToggleSwitch : public Component {
public:

   bool state() const {
      return m_state;
   }

   ToggleSwitch& set_state(bool value){
      m_state = value;
      return *this;
   }


   ToggleSwitch& set_primary_color(sg_color_t value){
      m_primary_color = value;
      return *this;
   }

   ToggleSwitch& set_secondary_color(sg_color_t value){
      m_secondary_color = value;
      return *this;
   }

   void draw(const DrawingAttributes & attributes);
   void handle_event(const ux::Event & event);

private:
   bool m_state;
   sg_color_t m_primary_color = 1;
   sg_color_t m_secondary_color = 0;


};

}

#endif // SAPI_UX_TOGGLESWITCH_HPP