#ifndef __READ_DATA_H
#define __READ_DATA_H

#include "string.h"

class ReadData
{
private:
    bool m_valid;
    String m_filename;

public:
    ReadData(const String&);
    virtual const String& GetFilename() const { return m_filename; }
    virtual bool IsValid() const { return m_valid; }

};
#endif