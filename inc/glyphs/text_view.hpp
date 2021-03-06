//
// Created by romaonishuk on 14.12.19.
//

#ifndef LEXI_TEXT_VIEW_HPP
#define LEXI_TEXT_VIEW_HPP

#include "window.hpp"

#include <functional>

class Page;

const auto pageHeight = 1000;
const auto pageDelimer = 20;

class TextView: public Gui::Window
{
public:
    enum class SwitchDirection
    {
        kPrev,
        kNext
    };

    explicit TextView(const GlyphParams&, Window*);

    void Draw(Gui::Window* window) override;
    void ProcessEvent(Gui::Window* w, const Event& event) override;

    void FillRectangle(const GlyphParams& params, const Color color) override;
    void DrawRectangle(const GlyphParams& params) const override;
    void DrawText(const Point& text_position, std::string text) const override;
    void DrawLine(const Point& start_point, const Point& end_point) const override;

    [[nodiscard]] std::string GetWindowName() const override { return "Text View"; }

    void SetCurrentPage(std::shared_ptr<Page> page) {m_currentPage = std::move(page);}
    [[nodiscard]] uint32_t GetPageCount() const { return m_components.size(); }
    [[nodiscard]] uint32_t GetPageHeight() const { return pageHeight; }
    [[nodiscard]] GlyphParams GetVisibleArea() const { return m_visibleArea; }
    [[nodiscard]] uint32_t GetOverallHeight() const { return m_components.size() * (pageHeight + pageSeparator); }

    void SetOnPageAddedAction(std::function<void()>&& action) { m_onPageAdded = std::move(action); }
    void SetOnVisibleAreaUpdateAction(std::function<void()>&& action) { m_onVisibleAreaUpdate = std::move(action); }
    void SetOnScrollAction(std::function<void(const Lexi::Event&)>&& action) { m_onScroll = std::move(action); }

    std::shared_ptr<Page> SwitchPage(Gui::Window*, SwitchDirection, bool);
    std::shared_ptr<Page> AddPage(Gui::Window* window, const GlyphPtr& currentPage);
    std::shared_ptr<Page> AddPage(Gui::Window* window, const Page* page);
    std::shared_ptr<Page> GetNextPage(const Page* page);

    void UpdateVisibleArea(height_t h);
    void UpdateVisibleArea(Gui::Window* window);

private:
    void UpdateVisiblePages();

    // Relative square currently shown on display.
    GlyphParams m_visibleArea;

    std::shared_ptr<Page> m_currentPage;
    std::list<GlyphPtr> m_visiblePages;

    std::function<void()> m_onPageAdded;
    std::function<void()> m_onVisibleAreaUpdate;
    std::function<void(const Lexi::Event&)> m_onScroll;
    //    std::function<void> m_onPageRemoved;
};

#endif  // LEXI_TEXT_VIEW_HPP
