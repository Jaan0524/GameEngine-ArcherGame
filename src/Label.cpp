#include "Label.h"

namespace Engine {
    Label* Label::get_instance(int x, int y, int width, int height, std::string text, SDL_Color color)
    {
        return new Label(x, y, width, height, text, color);
    }

    Label::~Label()
    {
        SDL_DestroyTexture(texture_m);
    }

    void Label::draw() const
    {
        SDL_RenderCopy(sys.get_renderer(), texture_m, NULL, &get_rect());
    }

    void Label::tick()
    {
    }

    void Label::set_text(std::string new_text, SDL_Color color)
    {
        text_m = new_text;
        SDL_DestroyTexture(texture_m);
        SDL_Surface* surface = TTF_RenderText_Solid(sys.get_font(), text_m.c_str(), color);
        texture_m = SDL_CreateTextureFromSurface(sys.get_renderer(), surface);
        SDL_FreeSurface(surface);
    }

    std::string Label::get_text()
    {
        return text_m;
    }

    Label::Label(int x, int y, int width, int height, std::string text, SDL_Color color) :Sprite(x, y, width, height), text_m(text) {
        set_text(text, color);
    }
}