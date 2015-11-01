#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#define NUMBER_OF_CONFIGURATIONS 1

<<<<<<< HEAD
enum ConfigurationType
{
    TeamSize = 0,
    NoType
};

class Configuration
{
<<<<<<< HEAD
    ConfigurationType type;
    int value;

public:
    Configuration(ConfigurationType=NoType, int=0);

    static Configuration* DefaultConfigurations();

    /*!
     *       @param: none
     *        @desc: get the configuration type
     *      @return: type: ConfigurationType
=======
    ConfigurationType configType;
    int value;

public:
    Configuration();
    Configuration(ConfigurationType,int);
    ~Configuration();

    /*!
     *       @param: none
     *        @desc: get the configurations type set by the AdministratorUser on the project
     *      @return: configurationType: ConfigurationType*
>>>>>>> master
     */
    ConfigurationType getType();

    /*!
     *       @param: none
     *        @desc: get the configuration value
     *      @return: value: int
     */
    int getValue();

    /*!
     *       @param: value: int
     *        @desc: set the configurations value by the AdministratorUser on the project
     *      @return: none
     */
    void setValue(int);

    /*!
     *       @param: type: ConfigurationType
     *        @desc: set the configurations type by the AdministratorUser on the project
     *      @return: none
     */
    void setType(ConfigurationType);
};

#endif // CONFIGURATION_H
