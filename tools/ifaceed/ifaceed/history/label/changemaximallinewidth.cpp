#include "changemaximallinewidth.h"

// ReSharper disable once CppUnusedIncludeDirective
#include <db/save.h>

// ReSharper disable once CppUnusedIncludeDirective
#include <QSpinBox>

#include "../../core/editor.h"

#include "../../gui/uiblocks/uiblocks.h"
#include "../../gui/uiblocks/uilabelblock.h"

#include "../../gui/actions/actions.h"
#include "../../gui/actions/scenenodeactions.h"

#include "../../blockedclosuremethodcall.h"
#include "../../closuremethodcall.h"

history::label::ChangeMaximalLineWidth::ChangeMaximalLineWidth(
    sad::SceneNode* d,
    unsigned int oldvalue,
    unsigned int newvalue

)
: history::scenenodes::ChangeProperty<unsigned int>(
    d,
    "maximallinewidth",
    oldvalue,
    newvalue
)
{
    m_affects_parent_grid = true;
}

history::label::ChangeMaximalLineWidth::~ChangeMaximalLineWidth()
{

}

void history::label::ChangeMaximalLineWidth::updateUI(
    core::Editor* e,
    const unsigned int& value)
{
    e->emitClosure( blocked_bind(
            e->uiBlocks()->uiLabelBlock()->spbMaximalLineWidth,
            &QSpinBox::setValue,
            value
        )
    );
    e->actions()->sceneNodeActions()->updateRegionForNode();
}
