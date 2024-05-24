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
	void drawBack();
	void drawTitBack();

private:
	void drawTit1(int texNo);
	void drawTit2(int texNo);
};