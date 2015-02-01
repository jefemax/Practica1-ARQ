#include "../include/config.h"

Config* Config::Instance()
{
    static Config instance;
    return &instance;
}

Config::~Config()
{

}