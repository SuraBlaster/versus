#pragma once

class BG
{
public:
	BG();
	~BG();

	//������
	void init();

	//�X�V
	void update();
	
	//�`��
	void drawBack();
	void drawTitBack();

private:
	void drawTit1(int texNo);
	void drawTit2(int texNo);
};