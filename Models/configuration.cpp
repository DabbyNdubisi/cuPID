#include "configuration.h"

Configuration::Configuration(ConfigurationType type, int value) :
    configType(type), value(value)
{

}

ConfigurationType Configuration::getType()
{
    return type;
}


int Configuration::getValue()
{
    return value;
}


void Configuration::setValue(int newValue)
{
    value = newValue;
}


Configuration* Configuration::DefaultConfigurations()
{
    Configuration *configs = new Configuration[NUMBER_OF_CONFIGURATIONS];

    for (int i = 0; i < NUMBER_OF_CONFIGURATIONS; i++)
        configs[i] = Configuration();

    return configs;
}

Configuration::Configuration() {}

Configuration::~Configuration() {}

ConfigurationType Configuration::getType()
{
    return configType;
}

int Configuration::getValue()
{
    return value;
}

void Configuration::setType(ConfigurationType type)
{
    configType = type;
}
