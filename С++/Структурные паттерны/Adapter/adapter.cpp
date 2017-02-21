class Shape {
public:
	Shape();
	virtual void BoundingBox(Point& bottomLeft, Point& topRight) const;
	virtual Manipulator* CreateManipulator() const;
};

class TextView {
public:
	TextView();
	void GetOrigin(Coord& x, Coord& y) const;
	void GetExtent(Coord& width, Coord& height) const;
	virtual bool IsEmpty() const;
};

// Используется множественное наследование
// интерфейс наследуется открыто, реализация - закрыто
class TextShape : public Shape, private TextView {
	TextShape(); 

	virtual void BoundingBox(Point& bottomLeft, Point& topRight) const;
	virtual bool IsEmpty() const;
	virtual Manipulator* CreateManipulator() const;
};

void TextShape::BoundingBox(Point& bottomLeft, Point& topRight) const {
	Coord bottom, left, width, height;

	GetOrigin(bottom, left);
	GetExtent(width, height);

	bottomLeft = Point(bottom, left);
	topRight = Point(bottom+height,left+width);
}

bool TextShape::IsEmpty() const {
	return TextView::IsEmpty();
}

Manipulator* TextShape::CreateManipulator() const {
	return new TextManipulator(this);
}


class TextShape2 : public Shape {
public:
	TextShape2(TextView*);

	virtual void BoundingBox(Point& bottomLeft, Point& topRight) const;
	virtual bool IsEmpty() const;
	virtual Manipulator* CreateManipulator() const;
private:
	TextView* _text;
}

TextShape2::TextShape2 (TextView* t) {
	_text = t;
}
void TextShape2::BoundingBox(Point& bottomLeft, Point& topRight) const {
	Coord bottom, left, width, height;

	_text->GetOrigin(bottom, left);
	_text->GetExtent(width, height);

	bottomLeft = Point(bottom, left);
	topRight = Point(bottom + height, left + width);
}

bool TextShape2::IsEmpty() const {
	return _text->IsEmpty();
}

Manipulator* TextShape2::CreateManipulator() contt {
	return new TextManipulator(this);
}

