#include "../include/readdata.h"
#include "../lib/rapidxml.hpp"
#include "../include/string.h"
#include "../include/config.h"

using namespace rapidxml;

ReadData::ReadData(const String &filename)
{
    this->m_filename = filename;
    m_valid = false;
    String fileContent(String::Read(filename));
    if (fileContent != "")
    {
        xml_document<> doc;
        doc.parse<0>((char*)fileContent.ToCString());
        xml_node<>* dataNode = doc.first_node("data");
        if (dataNode)
        {
            xml_node<>* elemNode = dataNode->first_node("elem");
            if (elemNode)
            {
                while (elemNode)
                {
                    xml_node<>* keyNode = elemNode->first_node("key");
                    if (keyNode)
                    {
                       // char *c = keyNode->value();
                        if (String(keyNode->value()) == String("NUM_ENEM"))
                        {
                            xml_node<>* valueNode = elemNode->first_node("value");
                            if (valueNode)
                            {
                                Config::Instance()->setNumEnemigos(String(valueNode->value()).ToInt());
                            }
                        }
                        else if (String(keyNode->value()) == String("MAX_LIFE"))
                        {
                            xml_node<>* valueNode = elemNode->first_node("value");
                            if (valueNode)
                            {
                                Config::Instance()->setMaxLife(String(valueNode->value()).ToInt());
                                printf("");
                            }
                        }
                        else if (String(keyNode->value()) == String("ENEMY_SPEED"))
                        {
                            xml_node<>* valueNode = elemNode->first_node("value");
                            if (valueNode)
                            {
                               Config::Instance()->setEnemySpeed(String(valueNode->value()).ToInt());
                            }
                        }
                        else if (String(keyNode->value()) == String("SCORE_PER_HIT"))
                        {
                            xml_node<>* valueNode = elemNode->first_node("value");
                            if (valueNode)
                            {
                                Config::Instance()->setScorePerHit(String(valueNode->value()).ToInt());
                            }
                        }
                    }
                    elemNode = elemNode->next_sibling("elem");
                }
            
            }
        }
    }
}