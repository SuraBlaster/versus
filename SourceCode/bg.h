#pragma once


class BG
{
public:
	BG();
	~BG();

	//‰Šú‰»
	void init();

	//XV
	void update();

	//•`‰æ
	void drawOpBack();
	void drawTitBack();
	void drawStageSelectBack();
	void drawGameBack();
	void drawGameOver();
	void drawGameClear();

	bool hitCheck(OBJ2D*rc1, object rc2);

	float checkDown(OBJ2D*, object);
	float checkUp(OBJ2D*, object);
	float checkRight(OBJ2D*, object);
	float checkLeft(OBJ2D*, object);

	void changePos(OBJ2D* obj, OBJ2D* obj2);
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