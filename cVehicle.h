#ifndef cVehicle_h
#define cVehicle_h
class cVehicle {
private:
	int mX, mY;
public:
	virtual void move(int x, int y);
 };
class cTruck : public cVehicle {
public:
	void move(int x, int y);
};
class cCar : public cVehicle {
public:
	void move(int x, int y);
};
#endif // !cVehicle_H
