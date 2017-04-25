#include "CommandInterface.h"

using namespace am;

const QDBusArgument &operator>>(const QDBusArgument &argument, am_Availability_s &availability)
{
    argument.beginStructure();

    int value;
    argument >> value;
    availability.availability = static_cast<am_Availability_e>(value);

    argument >> availability.availabilityReason;

    argument.endStructure();

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, am_ConnectionState_e &connectionState)
{
    int value;

    argument.beginStructure();
    argument >> value;
    argument.endStructure();

    connectionState = static_cast<am_ConnectionState_e>(value);

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, am_ClassProperty_s &classProperty)
{
    argument.beginStructure();
    argument >> classProperty.classProperty;
    argument >> classProperty.value;
    argument.endStructure();

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, am_MainConnectionType_s &mainConnection)
{
    argument.beginStructure();
    argument >> mainConnection.mainConnectionID;
    argument >> mainConnection.sourceID;
    argument >> mainConnection.sinkID;
    argument >> mainConnection.delay;
    argument >> mainConnection.connectionState;
    argument.endStructure();

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, am_MainSoundProperty_s &mainSoundProperty)
{
    argument.beginStructure();
    argument >> mainSoundProperty.type;
    argument >> mainSoundProperty.value;
    argument.endStructure();

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, am_NotificationConfiguration_s &notificationConfig)
{
    argument.beginStructure();
    argument >> notificationConfig.type;
    argument >> notificationConfig.status;
    argument >> notificationConfig.parameter;
    argument.endStructure();

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, am_NotificationStatus_e &notificationStatus)
{
    int value;

    argument.beginStructure();
    argument >> value;
    argument.endStructure();

    notificationStatus = static_cast<am_NotificationStatus_e>(value);

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, am_SinkClass_s &sinkClass)
{
    argument.beginStructure();
    argument >> sinkClass.sinkClassID;
    argument >> sinkClass.name;

    argument.beginArray();

    sinkClass.listClassProperties.clear();

    while ( !argument.atEnd() )
    {
        am_ClassProperty_s element;

        argument >> element;

        sinkClass.listClassProperties.push_back(element);
    }

    argument.endArray();

    argument.endStructure();

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, am_SinkType_s &sinkType)
{
    argument.beginStructure();
    argument >> sinkType.sinkID;
    argument >> sinkType.name;
    argument >> sinkType.availability;
    argument >> sinkType.volume;

    int value;
    argument >> value;
    sinkType.muteState = static_cast<am_MuteState_e>(value);

    argument >> sinkType.sinkClassID;
    argument.endStructure();

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, am_SoundProperty_s &soundProperty)
{
    argument.beginStructure();
    argument >> soundProperty.type;
    argument >> soundProperty.value;
    argument.endStructure();

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, am_SourceClass_s &sourceClass)
{
    argument.beginStructure();
    argument >> sourceClass.sourceClassID;
    argument >> sourceClass.name;

    argument.beginArray();

    sourceClass.listClassProperties.clear();

    while ( !argument.atEnd() )
    {
        am_ClassProperty_s element;

        argument >> element;

        sourceClass.listClassProperties.push_back(element);
    }

    argument.endArray();

    argument.endStructure();

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, am_SourceType_s &sourceType)
{
    argument.beginStructure();
    argument >> sourceType.sourceID;
    argument >> sourceType.name;
    argument >> sourceType.availability;
    argument >> sourceType.sourceClassID;
    argument.endStructure();

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, am_SystemProperty_s &systemProperty)
{
    argument.beginStructure();
    argument >> systemProperty.type;
    argument >> systemProperty.value;
    argument.endStructure();

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, std::string &str)
{
    QString qStr;

    argument >> qStr;

    str = qStr.toStdString();

    return argument;
}
