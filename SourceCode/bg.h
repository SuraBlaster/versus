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
	void drawBack();
	void drawTitBack();

private:
	void drawTit1(int texNo);
	void drawTit2(int texNo);
};