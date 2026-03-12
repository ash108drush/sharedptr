#pragma once
#include "texture.h"
#include <iostream>

#include <memory>

// Поддерживаемые виды фигур: прямоугольник и эллипс
enum class ShapeType { RECTANGLE, ELLIPSE};

class Shape {
public:
    // Фигура после создания имеет нулевые координаты и размер,
    // а также не имеет текстуры
    explicit Shape(ShapeType type):
        shape_type_(type),
        pos_({0, 0}),
        size_({0, 0}),
        texture_ptr_(nullptr)
    {}

    void SetPosition(Point pos) {
        pos_.x = pos.x;
        pos_.y = pos.y;
    }

    void SetSize(Size size) {
        size_.width = size.width;
        size_.height = size.height;
    }

    void SetTexture(std::shared_ptr<Texture> texture) {
        texture_ptr_ = texture;
    }

    // Рисует фигуру на указанном изображении
	// В зависимости от типа фигуры должен рисоваться либо эллипс, либо прямоугольник
    // Пиксели фигуры, выходящие за пределы текстуры, а также в случае, когда текстура не задана,
    // должны отображаться с помощью символа точка '.'
    // Части фигуры, выходящие за границы объекта image, должны отбрасываться.
   void Draw(Image& image) const {
    
    for (int y = 0; y < size_.height; ++y) {
        for (int x = 0; x < size_.width; ++x) {
            Point local_point{x, y};
            Point image_point{x + pos_.x, y + pos_.y};
            if(IsPointInShape(local_point)){
                char color = GetTextureColor(local_point);
                
                SetPixelColor(image, image_point, color);

                }     
                     
            }
        }
    }
private:
void SetPixelColor (Image& image, Point image_point, char color)const{
    image[image_point.y][image_point.x] = color;
}
char GetTextureColor(Point local_point)const {
    if(texture_ptr_ && local_point.y < texture_ptr_->GetSize().height && local_point.x < texture_ptr_->GetSize().width ){
        
            return texture_ptr_->GetPixelColor(local_point);
        }    
    return '.';

}

bool IsPointInShape(Point local_point) const {
    switch (shape_type_) {
        case ShapeType::RECTANGLE:
            return IsPointInSize(local_point, size_);
        case ShapeType::ELLIPSE:
            return IsPointInEllipse(local_point, size_);
        default:
            return false;
    }
}
bool IsPointInSize(Point local_point, Size size)const{
    return ((local_point.x >= 0 && local_point.x < size.width) && (local_point.y >= 0 && local_point.y < size.height));
}



    private:     


        ShapeType shape_type_;
        Point pos_;
        Size size_;
        std::shared_ptr<Texture> texture_ptr_;
};

/*
  такие тесты советую написать для отладки:

 фигуры выходящие за границу холста (в том числе фигуры с отрицательными координатами у фигур, и фигуры выходящие за правую или нижнюю границу полотна)
 то же самое если размер текстуры заведомо меньше выводимой части фигуры
*/
