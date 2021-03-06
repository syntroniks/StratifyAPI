/*! \file */ // Copyright 2011-2020 Tyler Gilbert and Stratify Labs, Inc; see LICENSE.md for rights.
#include "ux/Scene.hpp"
#include "ux/Rectangle.hpp"
#include "var/Data.hpp"

using namespace ux;
using namespace sgfx;

Scene::~Scene(){
	for(auto component_pointer: m_component_list){
		//pass events to each component
		delete component_pointer;
	}
}

Scene& Scene::enable(){
	for(auto component: m_component_list){
		component->set_visible(scene_collection()->display());
	}
	return *this;
}

Scene& Scene::disable(){
	for(auto component: m_component_list){
		component->set_invisible();
	}
	return *this;
}

void Scene::handle_event(const Event & event){

	if( event.type() == SystemEvent::event_type() ){
		if( event.id() == SystemEvent::id_enter ){

			//clear the background
			scene_collection()->theme().set_display_palette(
								scene_collection()->display(),
								Theme::style_brand_primary,
								Theme::state_default
								);
			scene_collection()->display().set_window(
						scene_collection()->display().region()
						);
			scene_collection()->display().clear();

			//enable the components
			for(auto component_pointer: m_component_list){
				component_pointer->set_visible(scene_collection()->display());
			}
		}
	}

	for(auto component_pointer: m_component_list){
		//pass events to each component
		if( component_pointer->is_visible() ){
			component_pointer->handle_event(event);
		}
	}

	if( event.type() == SystemEvent::event_type() ){
		if( event.id() == SystemEvent::id_exit ){
			for(auto component_pointer: m_component_list){
				component_pointer->set_invisible();
			}
			var::Data::reclaim_heap_space();
		}
	}

	for(auto component_pointer: m_component_list){
		if( component_pointer->is_refresh_drawing_pending() ){
			component_pointer->refresh_drawing();
		}
	}

}

void Scene::trigger_event(const Event & event){
	//send the event to the scene collection
	handle_event(event);
}



Component * Scene::find_generic_component(
		const var::String & name
		){
	for(auto component_pointer: m_component_list){
		//pass events to each component
		if( component_pointer->name() == name ){
			return component_pointer;
		}
	}
	return nullptr;
}


SceneCollection::~SceneCollection(){
	for(auto scene_pointer: m_scene_list){
		delete scene_pointer;
	}
}

Scene * SceneCollection::find_scene(const var::String & name){
	for(auto scene_pointer: m_scene_list){
		if( scene_pointer->name() == name ){
			return scene_pointer;
		}
	}
	return nullptr;
}

void SceneCollection::trigger_event(const Event & event){
	//allow the application to catch the event
}


