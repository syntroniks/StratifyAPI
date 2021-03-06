/*! \file */ // Copyright 2011-2020 Tyler Gilbert and Stratify Labs, Inc; see LICENSE.md for rights.
#include "sys/YamlPrinter.hpp"

using namespace sys;

YamlPrinter::YamlPrinter(){
	container_list().push_back(
				Container(level_fatal, container_array)
				);
}

void YamlPrinter::print(
		enum levels level,
		const char * key,
		const char * value,
		bool is_newline
		){

	if(level > verbose_level()){
		return;
	}

	for(auto const & c: container_list() ){
		if(c.verbose_level() > verbose_level()){
			return;
		}
	}

	for(size_t i=0; i < container_list().count() - 1; i++){
		print_final("   ");
	}

	if( container().type() == container_array ){
		print_final("- ");
	}


	Printer::print(level, key, value, value != nullptr);
}

void YamlPrinter::print_open_object(
		enum levels level,
		const char * key
		){

	if( verbose_level() >= level ){
		if( o_flags() & print_bold_objects ){ set_format_code(format_bold); }
		print(level, key, " ");
		if( o_flags() & print_bold_objects ){ clear_format_code(format_bold); }
	}

	container_list().push_back(
				Container(level, container_object)
				);
}

void YamlPrinter::print_open_array(
		enum levels level,
		const char * key
		){
	if( verbose_level() >= level ){
		if( o_flags() & print_bold_objects ){ set_format_code(format_bold); }
		print(level, key, " ");
		if( o_flags() & print_bold_objects ){ clear_format_code(format_bold); }
	}
	container_list().push_back(
				Container(level, container_array)
				);
}

void YamlPrinter::print_close_object(){
	if( container_list().count() > 1 ){
		container_list().pop_back();
	}
}


