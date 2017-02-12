class Composition {
public: 
	Composition(Compositor*);
	void Repair();
private:
	Compositor* _compositor;
	Component* _components; 
	int _componentCount;
	int _lineWidth; //Ширина строки в композиции Composition
	int _lineBreaks; // позиции точек разрыва строки (измеренные в компонентах)
	int _lineCount; // число строк
};

void Composition::Repair() {
	Coord* natrual;
	Coord* stretchAbility;
	Coort* shrinkAbility;
	int componentCount;
	int* breaks;
	// Подготовка массивов...

	int breakCount;
	breakCount = _compositor->Compose(natural, stretchAbility, shrinkAbility, componentCount, _lineWidth, breaks);

	// Разместить компоненты с учетом точек разрыва
	// ...
}

class Compositor {
public:
	virtual int Compose(
		Coord natural[], Coord stretch[], Coord shrink[],
		int componentCount, int lineWidth, int breaks[]) = 0;
protected:
	Compositor();
};

class SimpleCompositor : public Compositor {
public:
	SimpleCompositor();

	virtual int Compose(
		Coord natural[], Coord stretch[], Coord shrink[],
		int componentCount, int lineWidth, int breaks[]
		);
};

class TeXCompositor : public Compositor {
public:
	TeXCompositor();

	virtual int Compose(
		Coord natural[], Coord stretch[], Coord shrink[],
		int componentCount, int lineWidth, int breaks[]
		);
};

class ArrayCompositor : public Compositor {
public:
	ArrayCompositor();

	virtual int Compose(
		Coord natural[], Coord stretch[], Coord shrink[],
		int componentCount, int lineWidth, int breaks[]
		);
};


int main() {
	Composition* quick = new Composition(new SimpleCompositor);
	Composition* slick = new Composition(new TeXCompositor);
	Composition* iconic = new Composition(new ArrayCompositor);
return 0;
}



