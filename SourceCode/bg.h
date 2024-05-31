#pragma once

class BG
{
public:
	BG();
	~BG();

	//èâä˙âª
	void init();

	//çXêV
	void update();

	//ï`âÊ
	void drawOpBack();
	void drawTitBack();
	void drawStageSelectBack();
	void drawGameBack();
	void drawGameOver();
	void drawGameClear();

	bool hitCheck(object,OBJ2D*);

	float checkDown(object, OBJ2D*);
	float checkUp(object, OBJ2D*);
	float checkRight(object, OBJ2D*);
	float checkLeft(object, OBJ2D*);

	void atarihantei(object, OBJ2D* obj);
private:
	void drawOpBack1(int texNo);
	void drawOpBack2(int texNo);

	void drawTit1(int texNo);
	void drawTit2(int texNo);

	void drawStageSelect1(int texNo);
	void drawStageSelect2(int texNo);

	void drawGame1(int texNo);
	void drawGame2(int texNo);

	void drawGameOver1(int texNo);
	void drawGameOver2(int texNo);

	void drawGameClear1(int texNo);
	void drawGameClear2(int texNo);

	
};