#pragma once
#include "common.h"

class Texture {
public:
    explicit Texture(Image image)
        : image_(std::move(image)) {
    }

    // Возвращает размер изображения
    Size GetSize() const {
        if(image_.empty()){
            return {0,0};
        }
        int y_max = image_.size();
        int x_max = image_[0].length();
        return {x_max, y_max};
    }

    // Возвращает цвет пикселя.
    // Если координаты выходят за границы изображения, возвращается пробел
    char GetPixelColor(Point p) const {
        Size sz= GetSize();
        if (p.x > sz.width || p.y > sz.height){
            return ' ';
        }
       return image_[p.y][p.x];

        // Заглушка. Реализуйте метод самостоятельно

    }

private:
    Image image_;
};
