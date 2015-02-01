#include "../include/font.h"
#include "../include/renderer.h"
#include "../include/stb_image.h"


Font::~Font()
{
   delete[] glyphArray;
}

Font::Font(const String& filename) :Image(filename, 16, 16)
{
    uint16 index = 0;
    
    glyphArray = new Glyph*[255];
    int widthT = 0;
    int heighT = 0;
    int *numComp = 0;


    stbi_uc *buffer = stbi_load(filename.ToCString(), &widthT, &heighT, numComp, 4);
    //Recorro el buffer frame a frame

            //Recorro los renglones
    uint16 rowFrame = 0;
    uint16 colFrame = 0;
    int test = GetWidth();
    int initialX = 0;
    int initialY = 0;

    int cont = 0;
    while (cont < 255){
        int offsetFramesY = rowFrame*(widthT*GetHeight());
        for (int y = 0; y < GetHeight(); y++)
        {
            int offsetFramesX = colFrame;//*GetWidth();
            for (int x = 0; x < GetWidth(); x++)
            {
                int offset = ((y*widthT + offsetFramesY) + (offsetFramesX + x)) * 4;
                //todo Comparar byte a byte y revisar el color si es el correcto
                if (buffer[offset] == 255 && buffer[offset + 1] == 255 && buffer[offset + 2] == 0)
                {
                    int xTest = offsetFramesX + x;
                    int yTest = y + (GetHeight()*rowFrame);
                    initialX = offsetFramesX + x;
                    initialY = y + rowFrame*GetHeight();

                    buffer[offset + 3] = 0;
                }
                else if (buffer[offset] == 255 && buffer[offset + 1] == 0 && buffer[offset + 2] == 0)
                {
                    if (glyphArray[index])
                    {
                        int endX = offsetFramesX + x;
                        int endY = y + (GetHeight()*rowFrame);

                        int testResta = endX - initialX;

                        if ((endX - initialX) > 1)
                        {
                            glyphArray[index] = new Glyph();
                            glyphArray[index]->setStartGlyphPos(initialX, initialY);
                            glyphArray[index]->setEndGlyphPos(endX, endY);
                        }

                        index++;
                    }
                    buffer[offset + 3] = 0;
                }
                else if (buffer[offset] == 0 && buffer[offset + 1] == 0 && buffer[offset + 2] == 0)
                {
                    buffer[offset + 3] = 0;
                }
            }
        }
        colFrame += GetWidth();
        //Termino un renglón?
        //32 pixels ancho por glifo por 16 frames en un renglon
        if (colFrame == widthT)
        {
            rowFrame += 1;
            colFrame = 0;
        }
        cont++;
    }

     Renderer::Instance().UpdateTexture(buffer, static_cast<uint16>(widthT), static_cast<uint16>(heighT), GetTexId());
     stbi_image_free(buffer);
}

void Font::Render(const String& text, double x, double y) const
{
    double inc = 0;
    for (int t = 0; t < text.Length(); t++)
    {
        char c = text[t];
        //Renderer::Instance().DrawImage(this, x + (t*GetHeight()), y, (int8)c, GetSize(), GetHeight());
        double width = glyphArray[static_cast<int>(c)]->getEndGlyphPosX() - glyphArray[static_cast<int>(c)]->getStartGlyphPosX();
        double heigth = glyphArray[static_cast<int>(c)]->getEndGlyphPosY() - glyphArray[static_cast<int>(c)]->getStartGlyphPosY();
        Renderer::Instance().DrawImage(this, x + inc, y, (int8)c, GetSize(), GetHeight());
        inc += width;
    }
}

uint32 Font::GetTextWidth(const String& text) const
{
    int16 sizeOfText = 0;
    for (int t = 0; t < text.Length(); t++)
    {
        char c = text[t];
        uint16 difference = glyphArray[static_cast<int>(c)]->getEndGlyphPosX() - glyphArray[static_cast<int>(c)]->getStartGlyphPosX();
        sizeOfText += difference;
    }

    return sizeOfText;
}

uint32 Font::GetTextHeight(const String& text) const
{
    int16 aux = 0;
    for (int t = 0; t < text.Length(); t++)
    {
        char c = text[t];
        //int test1 = glyphArray[c]->getEndGlyphPosY();
        //int test2 = glyphArray[c]->getStartGlyphPosY();

        uint16 difference = glyphArray[static_cast<int>(c)]->getEndGlyphPosY() - glyphArray[static_cast<int>(c)]->getStartGlyphPosY();
        if (difference > aux)
            aux = difference;
    }

    return aux;
}