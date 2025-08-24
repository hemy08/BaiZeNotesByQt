//
// Created by zhaoj on 25-8-17.
//

#include "render.h"

#include "hemy_debug.h"
#include "latex_render.h"

namespace HemyRender
{
    QString Render::RenderText(const QString& text)
    {
        auto inst = HLatex::GetInst();
        LOG_INFO("RenderText ", inst->Render(text));
        return inst->Render(text);
    }

}
