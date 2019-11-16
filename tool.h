#ifndef TOOL_H
#define TOOL_H

#include <QString>
#include <QIcon>

class Tool
{
public:
    Tool(QString name, QIcon icon);
    QIcon icon();
    QString name();

private:
    QString m_name;
    QIcon m_icon;
};

#endif // TOOL_H
