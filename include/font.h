#ifndef _FONT_H
#define _FONT_H

#include "glyph.h"
#include "array.h"
#include "string.h"
#include "image.h"

class Font : public Image {
public:
    Font();
    ~Font();
    Font(const String& filename);
    virtual uint16 GetSize() const { return GetHeight(); }
    virtual uint32 GetTextWidth(const String& text) const;
    virtual uint32 GetTextHeight(const String& text) const;
    virtual void Render(const String& text, double x, double y) const;

private:
    Glyph **glyphArray;

};

#endif
