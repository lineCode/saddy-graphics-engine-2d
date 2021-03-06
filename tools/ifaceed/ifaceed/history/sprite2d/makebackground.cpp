#include "makebackground.h"

// ReSharper disable once CppUnusedIncludeDirective
#include <db/save.h>

// ReSharper disable once CppUnusedIncludeDirective
#include "../../gui/resourcetreewidget/resourcetreewidget.h"

#include "../../blockedclosuremethodcall.h"
#include "../../closuremethodcall.h"

#include "../../gui/uiblocks/uiblocks.h"
#include "../../gui/uiblocks/uiscenenodeblock.h"

#include "../../gui/actions/actions.h"
#include "../../gui/actions/sceneactions.h"
#include "../../gui/actions/scenenodeactions.h"

#include "../../gui/anglewidget/anglewidget.h"

history::sprite2d::MakeBackground::MakeBackground(
        sad::SceneNode* d, 
        const sad::Rect2D& oldarea,
        float oldangle,
        unsigned int oldlayer,
        const sad::Rect2D& newarea,
        float newangle,
        unsigned int newlayer
) : m_node(d),
m_oldarea(oldarea),
m_oldangle(oldangle),
m_oldlayer(oldlayer),
m_newarea(newarea),
m_newangle(newangle),
m_newlayer(newlayer)
{
    m_node->addRef();
}

history::sprite2d::MakeBackground::~MakeBackground()
{
    m_node->delRef();
}

void history::sprite2d::MakeBackground::commit(core::Editor* e)
{
    this->update(e, m_newarea, m_newangle, m_newlayer);
}

void history::sprite2d::MakeBackground::rollback(core::Editor* e)
{
    this->update(e, m_oldarea, m_oldangle, m_oldlayer);
}

void history::sprite2d::MakeBackground::update(
        core::Editor* e, 
        const sad::Rect2D& area, 
        float angle, 
        unsigned int layer
)
{
    sad::Renderer::ref()->lockRendering();
    m_node->setProperty("area", area);
    m_node->setProperty("angle", angle);
    m_node->setProperty("layer", layer);
    sad::Renderer::ref()->unlockRendering();

    if (e)
    {
        if (e->isNodeSelected(m_node))
        {
            e->emitClosure( bind(
                e->actions()->sceneNodeActions(),
                &gui::actions::SceneNodeActions::updateRegionForNode
            ));	
            e->emitClosure( blocked_bind(
                e->uiBlocks()->uiSceneNodeBlock()->awSceneNodeAngle,
                &gui::anglewidget::AngleWidget::setValue,
                angle
            ));	
        }
        if (e->actions()->sceneActions()->currentScene() == m_node->scene())
        {
            e->emitClosure( bind(
                e->actions()->sceneNodeActions(),
                &gui::actions::SceneNodeActions::removeSceneNodeFromSceneNodeListByNode,
                m_node
            ));
            e->emitClosure( bind(
                e->actions()->sceneNodeActions(),
                &gui::actions::SceneNodeActions::insertSceneNodeToSceneNodeList,
                m_node, layer
            ));
        }
    }
}
