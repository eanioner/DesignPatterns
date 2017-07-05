class Window {
public: 
	Window(View* contents);

	virtual void DraContents();

	virtual void Open();
	virtual void Close();
	virtual void Inonify();
	virtual void Deiconify();

	virtual void SetOrigin(const Point& at);
	virtual void SetExtent(const Point& extent);
	virtual void Raise();
	virtual void Lower();

	virtual void DrawLine(const Point&, const Point&);
	virtual void DrawRect(const Point&, const Point&);
	virtual void DrawPolygon(const Point[], int n);
	virtual void DrawText(const char*, const Point&);

protected:
	WindowImp* GetWindowImp();
	View* GetView();

private:
	WindowImp* _imp;
	View* _contents;
};