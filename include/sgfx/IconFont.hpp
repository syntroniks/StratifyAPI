#ifndef SAPI_SGFX_ICONFONT_HPP
#define SAPI_SGFX_ICONFONT_HPP
#include <sapi/sg_font_types.h>

#include "../fs/File.hpp"
#include "Bitmap.hpp"

namespace sgfx {

class IconFontInfo {
public:
	IconFontInfo(const sg_font_icon_t & icon){
		m_icon = icon;
	}

	Area area() const {
		return Area(m_icon.width, m_icon.height);
	}

	const var::String name() const {
		return var::String(m_icon.name);
	}

	u32 canvas_idx() const {
		return m_icon.canvas_idx;
	}

	Point canvas_point() const {
		return Point(
					m_icon.canvas_x, m_icon.canvas_y
					);
	}

private:
	sg_font_icon_t m_icon;

};

class IconFont {
public:
	IconFont();
	IconFont(const fs::File & file);

	int refresh();

	sg_size_t point_size() const {
		return m_header.max_height;
	}

	Area area() const {
		return Area(m_header.max_width, m_header.max_height);
	}

	const IconFontInfo get_info(size_t offset) const {
		return  IconFontInfo(m_list.at(offset % m_list.count()));
	}

	size_t find(const var::String name) const;

	size_t count() const {
		return m_list.count();
	}

 int draw(
		 const var::String & name,
		 Bitmap & dest,
		 const Point & point
		 ) const;

 int draw(
		 size_t offset,
		 Bitmap & dest,
		 const Point & point
		 ) const;

private:
 mutable s32 m_master_canvas_idx = -1;
 Bitmap m_master_canvas;
 sg_font_icon_header_t m_header;
 var::Vector<sg_font_icon_t> m_list;
 const fs::File & m_file;
};

}

#endif // SAPI_SGFX_ICONFONT_HPP
