#include "Image.h"
namespace Engine {
    Image* Image::get_instance(int x, int y, int width, int height, std::string path)
    {
        return new Image(x,y,width,height,path);
    }
    Image::~Image() {

    }
    void Image::draw() const
    {
        SDL_RenderCopy(sys.get_renderer(), texture_m, NULL, &get_rect());
    }
    void Image::tick()
    {
    }
    Engine::Image::Image(int x, int y, int width, int height, std::string path) :Sprite(x, y, width, height)
    {
        SDL_Surface* surface = IMG_Load((constants::gResPath + path).c_str());
        texture_m = SDL_CreateTextureFromSurface(sys.get_renderer(), surface);
    }
}
