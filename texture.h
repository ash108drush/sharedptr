#pragma once
#include "common.h"

class Texture {
public:
    explicit Texture(Image image)
        : image_(std::move(image)) {
    }

    // Возвращает размер изображения
    Size GetSize() const {
        const int width = image_.empty() ? 0 : static_cast<int>(image_[0].size());
        const int height = static_cast<int>(image_.size());
        return {width, height};

    }

    // Возвращает цвет пикселя.
    // Если координаты выходят за границы изображения, возвращается пробел
    char GetPixelColor(Point p) const {
        if(!image_.empty() && p.y < static_cast<int>(image_.size()) && p.x < static_cast<int>(image_[0].size())){
            return image_[p.y][p.x];
        }
        return ' ';
    }

private:
    Image image_;
};
