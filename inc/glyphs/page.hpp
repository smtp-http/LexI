//
// Created by ronyshchuk on 14.04.20.
//

#ifndef LEXI_PAGE_HPP
#define LEXI_PAGE_HPP

#include "i_composite_glyph.hpp"

class TextView;
class Row;

class Page: public ICompositeGlyph
{
public:
    explicit Page(TextView* parent, const GlyphParams& params);

    void Draw(Gui::Window* window) override;
    void ProcessEvent(Gui::Window* window, const Event& event) override;

    void DrawCursor(Gui::Window* window);

private:
    // text view indentations
    const height_t m_topIndent = 25;
    const height_t m_botIndent = 25;
    const width_t m_leftIndent = 50;
    const width_t m_rightIndent = 75;

    std::shared_ptr<Row> m_currentRow;
    TextView* m_parent;
};

// height_t Page::m_topIndent = 25;
// height_t Page::m_botIndent = 75;
// width_t Page::m_leftIndent = 50;
// width_t Page::m_rightIndent = 50;

#endif  // LEXI_PAGE_HPP