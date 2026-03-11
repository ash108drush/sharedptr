#pragma once
#include "texture.h"

#include <memory>

// Поддерживаемые виды фигур: прямоугольник и эллипс
enum class ShapeType { RECTANGLE, ELLIPSE};

class Shape {
public:
    // Фигура после создания имеет нулевые координаты и размер,
    // а также не имеет текстуры
    explicit Shape(ShapeType type):shape_type_(type)
        ,pos_({0,0})
        ,size_({0,0})
        ,texture_ptr_(nullptr) {

    }

    void SetPosition(Point pos) {
        pos_=pos;
    }

    void SetSize(Size size) {
        size_=size;
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
        for(std::string str : image){
            for(char ch: str){

            }

        }

    }
private:
    ShapeType shape_type_;
    Point pos_;
    Size size_;
    std::shared_ptr<Texture> texture_ptr_;
};
