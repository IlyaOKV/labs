#ifndef EXAMPLEWINDOW_H_
#define EXAMPLEWINDOW_H_

#include "Window.h"

// ���������� ������ ExampleWindow ��� ������� Window
class MyWindow: public Window
{
public:
	static constexpr int DEFAULT_WIDTH = 800;
	static constexpr int DEFAULT_HEIGHT = 600;

protected:
	double _angle; // ���� �������� ������
	double _eye_level; // ������ ������ ����
	double _len;//��� ��������� ������
	double _hei;//��� ��������� ������
	double _wid;//��� ��������� ������

public:

	// ����������� ������ MyWindow
	MyWindow(
			int width = DEFAULT_WIDTH,
			int height = DEFAULT_HEIGHT);

	// ���������� ������ MyWindow
	virtual ~MyWindow() = default;

	// ����� ��������� ��������� ����
	virtual void setup() override;

	// ����� ��������� ����
	virtual void render() override;

	// ����� ��������� ������
	virtual void handle_logic() override;

	// ����� ��������� ������
	virtual void handle_keys(const Uint8 * keys);
};




#endif /* EXAMPLEWINDOW_H_ */
