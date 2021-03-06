#ifndef POS_H_
#define POS_H_

class Pos {
private:
	int x;
	int y;
public:
	Pos();
	Pos(int x, int y);
	Pos(const Pos* p);
	int getX();
	int getY();
	float getNorma();
	float getDistancia(Pos p);
	Pos ySimetrico();
	virtual ~Pos();
};

#endif /* POS_H_ */
