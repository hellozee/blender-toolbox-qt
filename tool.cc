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

void Tool::addSubTool(Tool t)
{
    m_subTools.push_back(t);
}

QVector<Tool> Tool::subTools()
{
    return m_subTools;
}

void Tool::swap(int index)
{
    Tool temp = m_subTools[index];
    m_subTools.remove(index);
    Tool t(m_name, m_icon);
    m_subTools.push_front(t);
    m_icon = temp.icon();
    m_name = temp.name();
}
