#include "mainpanelproxy.h"

#include "../core/editor.h"
#include "../mainpanel.h"

#include "../blockedclosuremethodcall.h"


gui::MainPanelProxy::MainPanelProxy() : m_editor(NULL)
{
    
}

void gui::MainPanelProxy::setEditor(core::Editor* editor)
{
    m_editor = editor;
}

core::Editor* gui::MainPanelProxy::editor() const
{
    return m_editor;
}

gui::MainPanelProxy::~MainPanelProxy()
{
    
}

// ReSharper disable once CppMemberFunctionMayBeConst
void gui::MainPanelProxy::lockTypesTab(bool lock)
{
    m_editor->panel()->lockTypesTab(lock);
}

QList<QList<QColor> > gui::MainPanelProxy::colorPalette() const
{
    return m_editor->panel()->colorPalette();
}

// ReSharper disable once CppMemberFunctionMayBeConst
void gui::MainPanelProxy::setColorPalette(const QList<QList<QColor> >& palette)
{
    m_editor->panel()->setColorPalette(palette);
}

// ReSharper disable once CppMemberFunctionMayBeConst
void gui::MainPanelProxy::highlightState(const sad::String & text)
{
    m_editor->panel()->highlightState(text);
}

// ReSharper disable once CppMemberFunctionMayBeConst
void gui::MainPanelProxy::toggleAnimationPropertiesEditable(bool flag)
{
    m_editor->panel()->toggleAnimationPropertiesEditable(flag);
}

gui::table::DelegateFactory* gui::MainPanelProxy::delegateFactory() const
{
    return m_editor->panel()->delegateFactory();
}

// ReSharper disable once CppMemberFunctionMayBeConst
void gui::MainPanelProxy::clearObjectSelection()
{
    m_editor->panel()->clearObjectSelection();
}

// ReSharper disable once CppMemberFunctionMayBeConst
void gui::MainPanelProxy::setCurrentTabWidgetIndex(int index)
{
    m_editor->panel()->UI()->tabTypes->setCurrentIndex(index);
}

// ReSharper disable once CppMemberFunctionMayBeConst
void gui::MainPanelProxy::setCurrentTabObjectsIndex(int index)
{
    m_editor->panel()->UI()->tabObjects->setCurrentIndex(index);
}

// ReSharper disable once CppMemberFunctionMayBeConst
bool gui::MainPanelProxy::takeDelegateByPropertyName(const QString & name)
{
    return m_editor->panel()->takeDelegateByPropertyName(name);	
}

// ReSharper disable once CppMemberFunctionMayBeConst
sad::Hash<sad::String, gui::table::Delegate*>& gui::MainPanelProxy::delegatesByName()
{
    return m_editor->panel()->delegatesByName();		
}	

// ReSharper disable once CppMemberFunctionMayBeConst
bool gui::MainPanelProxy::scriptableAddProperty(const sad::String& propertytype, const sad::String& propertyname, bool fromeditor)
{
    return m_editor->panel()->scriptableAddProperty(propertytype, propertyname, fromeditor);
}

bool gui::MainPanelProxy::isFastModeEnabled() const
{
    return m_editor->panel()->UI()->cbFastMode->isChecked();
}
 
QString gui::MainPanelProxy::getSceneNodeNameFromUI() const
{
    return m_editor->panel()->UI()->txtObjectName->text();
}

void gui::MainPanelProxy::setSceneNodeName(const QString& name) const
{
   m_editor->emitClosure(blocked_bind(
       m_editor->panel()->UI()->txtObjectName,
       &QLineEdit::setText,
       name
   ));
}