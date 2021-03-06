//
// Created by romaonishuk on 14.12.19.
//
#ifndef LEXI_TEXT_LABEL_HPP
#define LEXI_TEXT_LABEL_HPP

#include "i_glyph.hpp"

#include <cassert>

#include "logger.hpp"
#include "types.hpp"
#include "window.hpp"

class TextLabel: public IGlyph
{
public:
    explicit TextLabel(const GlyphParams& params, const std::string& text = "TextLabel"): IGlyph(params), m_text(text)
    {}

    void Draw(Gui::Window*) override;
    void ProcessEvent(Gui::Window* w, const Event& event) override {}
    void ChangeText(const std::string& text, Gui::Window* w)
    {
        m_text = text;
        //        ClearGlyph(w);
//        Draw(w);
    }

private:
    std::string m_text;
};

// ---- Text Label ----

void TextLabel::Draw(Gui::Window* w)
{
    w->DrawText({m_params.x, m_params.y}, m_text);
}

#endif  // LEXI_TEXT_LABEL_HPP
