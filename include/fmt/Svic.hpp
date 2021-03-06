/*! \file */ // Copyright 2011-2020 Tyler Gilbert and Stratify Labs, Inc; see LICENSE.md for rights.
#ifndef SAPI_FMT_SVIC_HPP_
#define SAPI_FMT_SVIC_HPP_

#include "../fs/File.hpp"
#include "../api/FmtObject.hpp"
#include "../sgfx/Vector.hpp"
#include "../var/Vector.hpp"

namespace fmt {

/*! \brief Svc (Stratify Vector Collection) Class
 * \details The Svc class manages files that
 * contain collections of Stratify Vector icons.
 *
 */
class Svic : public fs::File {
public:

	Svic(const var::String & path = var::String());

	u32 count() const { return m_icons.count(); }

	var::String name_at(u32 i) const;

	int append(
			const var::String & name,
			const var::Vector<sg_vector_path_description_t> & list
			);

	sgfx::VectorPath get(const var::String & name) const;
	sgfx::VectorPath at(u32 i) const;

private:
	int parse_icons();
	var::Vector<sg_vector_icon_header_t> m_icons;

	//these track internal state used for caching
	mutable u32 m_current_icon_at;
	mutable var::Vector<sg_vector_path_description_t> m_current_icon;

};

}

#endif // SAPI_FMT_SVIC_HPP_
