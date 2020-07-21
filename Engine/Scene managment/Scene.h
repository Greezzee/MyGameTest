#pragma once

//���� ����, ������� ����� ������� SceneManager ��������������
enum class SceneType
{
	EMPTY,
	MAIN_MENU,
	CHARACTER_CHOOSE,
	GAMEPLAY,
	EXIT_MENU,
};


/*!
* ����������� �����, �� ������� ������ ���� ����������� ��� ����� � ���������������� ����������� �������.
* 
* ���� ��������� ����������� ����� �� �������.
* �������� ����� ����� �������� ���, ��� ��� �����
* 
* ������ ��� �����: MainMenu, CharacterChoose � Gameplay, �� �������� ������� ����� ����������� ������ ������ ����.
* MainMenu �������� ������ ����� � �����������
* CharacterChoose �������� � ��������
* Gameplay �������� � Gamefield � ���� ��� � ��� �������
*/
class Scene
{
public:
	SceneType type; //! ��� ����� �������� � �������������
	bool is_end; //! ���� true, ����� ������������� ��������� �� ���������� �����
	Scene();
	//! ������������� ���������� ���� ������� (����� ��������� ����� ����� OpenScene), ���� ������������� (CreateScene)
	virtual void Init() = 0;

	//! ���������� ���������� ������������� ������ ����
	virtual void Update() = 0;

	//! ���������� ������������� ��� �������� ����� ����� SceneManager
	virtual void Destroy() = 0;

protected:
	bool is_paused; //! ���� true, ����� �� ����� ����������� (���� �� �����������)
};
