#include "tool.h"

Tool::Tool(QString name, QIcon icon):
    m_name(name), m_icon(icon)
{ }

QIcon Tool::icon()
{
    return m_icon;
}

QString Tool::name()
{
    return m_name;
}
