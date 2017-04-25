#ifndef COMMANDINTERFACE_H
#define COMMANDINTERFACE_H

#include <QtDBus>
#include <audiomanager/audiomanagertypes.h>

Q_DECLARE_METATYPE(am::am_MainConnectionType_s)
Q_DECLARE_METATYPE(am::am_MainSoundProperty_s)
Q_DECLARE_METATYPE(am::am_NotificationConfiguration_s)
Q_DECLARE_METATYPE(am::am_SinkClass_s)
Q_DECLARE_METATYPE(am::am_SinkType_s)
Q_DECLARE_METATYPE(am::am_SoundProperty_s)
Q_DECLARE_METATYPE(am::am_SourceClass_s)
Q_DECLARE_METATYPE(am::am_SourceType_s)
Q_DECLARE_METATYPE(am::am_SystemProperty_s)

const QDBusArgument &operator>>(const QDBusArgument &argument, am::am_Availability_s &availability);
const QDBusArgument &operator>>(const QDBusArgument &argument, am::am_ConnectionState_e &connectionState);
const QDBusArgument &operator>>(const QDBusArgument &argument, am::am_ClassProperty_s &classProperty);
const QDBusArgument &operator>>(const QDBusArgument &argument, am::am_MainConnectionType_s &mainConnection);
const QDBusArgument &operator>>(const QDBusArgument &argument, am::am_MainSoundProperty_s &mainSoundProperty);
const QDBusArgument &operator>>(const QDBusArgument &argument, am::am_NotificationConfiguration_s &notificationConfig);
const QDBusArgument &operator>>(const QDBusArgument &argument, am::am_NotificationStatus_e &notificationStatus);
const QDBusArgument &operator>>(const QDBusArgument &argument, am::am_SinkClass_s &sourceClass);
const QDBusArgument &operator>>(const QDBusArgument &argument, am::am_SinkType_s &sinkType);
const QDBusArgument &operator>>(const QDBusArgument &argument, am::am_SoundProperty_s &soundProperty);
const QDBusArgument &operator>>(const QDBusArgument &argument, am::am_SourceClass_s &sourceClass);
const QDBusArgument &operator>>(const QDBusArgument &argument, am::am_SourceType_s &sourceType);
const QDBusArgument &operator>>(const QDBusArgument &argument, am::am_SystemProperty_s &systemProperty);

const QDBusArgument &operator>>(const QDBusArgument &argument, std::string &str);

/*
 * Command to generate proxy file:
 * qdbusxml2cpp  CommandInterface.xml -p CommandInterfaceProxy -i CommandInterface.h -N -c CommandInterface
 *
 */

#endif // COMMANDINTERFACE_H
