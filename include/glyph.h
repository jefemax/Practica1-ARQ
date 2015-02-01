#ifndef _GLYPH_H
#define _GLYPH_H

class Glyph
{
public:
    void setStartGlyphPos(double startGlyphPosX, double startGlyphPosY)
    { 
        this->startGlyphPosX = startGlyphPosX;
        this->startGlyphPosY = startGlyphPosY;
    
    }
    double getStartGlyphPosX(){ return startGlyphPosX; }
    double getStartGlyphPosY(){ return startGlyphPosY; }
    void setEndGlyphPos(double endGlyphPosX, double endGlyphPosY)
    { 
        this->endGlyphPosX = endGlyphPosX;
        this->endGlyphPosY = endGlyphPosY;
    }
    double getEndGlyphPosX(){ return endGlyphPosX; }
    double getEndGlyphPosY(){ return endGlyphPosY; }
    

private:
    double startGlyphPosX;
    double startGlyphPosY;
    double endGlyphPosX;
    double endGlyphPosY;
};
#endif