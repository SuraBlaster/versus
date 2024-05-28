#pragma once

class BG
{
public:
	BG();
	~BG();

	//初期化
	void init();

	//更新
	void update();
	
	//描画
	void drawOpBack();
	void drawTitBack();
	void drawStageSelectBack();
	void drawGameBack();
	void drawGameOver();
	void drawGameClear();

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