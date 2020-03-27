//
// Created by romaonishuk on 10.03.20.
//

#ifndef LEXI_MENU_HPP
#define LEXI_MENU_HPP

// TODO(rmn): need to investigate how this will be implemented on another OS
#include <iostream>
#include "window.hpp"
#include "../src/lexi_linux/inc/x_window_impl.hpp"

namespace Gui
{
class Menu : public ICompositeGlyph
{
public:
    explicit Menu(const GlyphParams& p);

    void Draw(Window * w) override;

    void ProcessEvent(Window *w,const Point& p, const EventType& ev) override;

private:
    std::unique_ptr<ChildWindow> mMenuWindow = nullptr;
};
}  // namespace Gui

#endif //LEXI_MENU_HPP