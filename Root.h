//#pragma once
//#include <iostream>
//#include <SFML/Graphics.hpp>
//using namespace sf;
//using namespace std;
//
//class Root
//{
//private:
//	string color;
//	int degree = 0;
//	Vector2f origin;
//public:
//	virtual void drawShape(RenderWindow& w) = 0;
//	virtual void move(string) { }
//	virtual void rotate(string) { }
//	virtual void scale(string) { }
//};
//class Primitive : public Root
//{
//protected:
//	int xCord;
//	int yCord;
//public:
//	virtual void drawShape(RenderWindow& w) { }
//	virtual void move(string) { }
//	virtual void rotate(string) { }
//	virtual void scale(string) { }
//};
//
//class Arrow : public Root
//{
//private:
//	ConvexShape cc1, cc2;
//public:
//	Arrow()
//	{
//		cc1.setPointCount(3);
//		cc2.setPointCount(4);
//		cc1.setPoint(0, (Vector2f(200, 85)));
//		cc1.setPoint(1, (Vector2f(220, 115)));
//		cc1.setPoint(2, (Vector2f(200, 145)));
//		cc2.setPoint(0, (Vector2f(200, 105)));
//		cc2.setPoint(1, (Vector2f(200, 125)));
//		cc2.setPoint(2, (Vector2f(100, 125)));
//		cc2.setPoint(3, (Vector2f(100, 105)));
//	}
//	void drawShape(RenderWindow& w)
//	{
//		w.draw(cc1);
//		w.draw(cc2);
//	}
//};
//
//class UserDefined : public Root
//{
//private:
//	int pointCount;
//	vector<Vector2f> pointArray;
//public:
//	void takeInput()
//	{
//		cout << "Enter number of points :";
//		cin >> pointCount;
//		cout << "Enter points " << pointCount << " separated by space : ";
//		for (int i = 0; i < pointCount; i++)
//		{
//			int a, b;
//			cin >> a >> b;
//			pointArray.push_back(Vector2f(a, b));
//		}
//	}
//};
//
//
//class Line : public Primitive
//{
//private:
//	int length;
//public:
//	Line() :length(10) {}
//	Line(int l) :length(l) {}
//	void drawShape(RenderWindow& w)
//	{
//		RectangleShape rr;
//		rr.setSize(Vector2f(length, 5));
//		rr.setOrigin(Vector2f(xCord, yCord));
//		w.draw(rr);
//	}
//};
//
//class Circle : public Primitive, public CircleShape
//{
//private:
//public:
//};
//class Rectangle : public Primitive, public RectangleShape
//{
//private:
//public:
//};
//class Triangle : public Primitive, public CircleShape
//{
//private:
//public:
//};
//class Convex : public Primitive, public ConvexShape
//{
//private:
//public:
//};
//
//
//
//class Screen
//{
//private:
//public:
//};
//class Viewport : public Screen
//{
//private:
//public:
//};
//class Textbox : public Screen
//{
//private:
//public:
//};
//class Icons : public Screen
//{
//private:
//public:
//};
//void dd(RenderTarget& w)
//{
//	cout << "ss" << endl;
//	RectangleShape base(Vector2f(40, 60));
//	base.setFillColor(Color(68, 68, 68));
//	base.setPosition(1500, 0);
//	CircleShape cc(60);
//	cc.setPosition(1510, 10);
//	cc.setFillColor(Color(91, 204, 286, 0));
//	cc.setOutlineColor(Color::Blue);
//	cc.setOutlineThickness(-5);
//	CircleShape tt(60, 3);
//	tt.setPosition(164, 20);
//	tt.setFillColor(Color(91, 204, 246, 0));
//	tt.setOutlineColor(Color::White);
//	tt.setOutlineThickness(-5);
//	RectangleShape ss(Vector2f(100, 100));
//	ss.setFillColor(Color(91, 204, 246, 0));
//	ss.setOutlineColor(Color::Black);
//	ss.setOutlineThickness(-5);
//	ss.setPosition(170, 10);
//	RectangleShape console(Vector2f(380, 407));
//	console.setPosition(510, 583);
//	console.setFillColor(Color(193, 199, 126, 165));
//	w.draw(base);
//	w.draw(cc);
//	w.draw(tt);
//	w.draw(ss);
//	w.draw(console);
//	cout << "gggg" << endl;
//}
#pragma once
#include <iostream>
#include <sfml/graphics.hpp>
using namespace sf;
using namespace std;

#define chudi 3
class Root {
public:
	Root(float width, float height) {
		if (!f.loadFromFile("font/drift.ttf")){
			cout << "no font" << endl;
	}
		root[0].setFont(f);
		root[0].setFillColor(Color::Black);
		root[0].setString("enter");
		root[0].setCharacterSize(70);
		root[0].setPosition(400, 200);
		root[01].setFont(f);
		root[01].setFillColor(Color::Black);
		root[01].setString("Help");
		root[01].setCharacterSize(70);
		root[01].setPosition(400, 300);
		root[02].setFont(f);
		root[02].setFillColor(Color::Black);
		root[02].setString("about");
		root[02].setCharacterSize(70);
		root[02].setPosition(400, 400);
	/*	det[0].setfont(f);
		det[0].setfillcolor(color::black);
		det[0].setstring("enter the key to take care of your fucking ashole");
		det[0].setcharactersize(50);
		det[0].setposition(0, 0);*/
		menuselected = -1;

	}
	void draw(RenderWindow& window) {

		for (int i = 0; i < chudi; i++)
			window.draw(root[i]);

	}

	void moveup() {
		if (menuselected - 1 >= 0)
		{
			root[menuselected].setFillColor(Color::Red);
			menuselected--;
			if (menuselected == -1)
				menuselected = 2;
			root[menuselected].setFillColor(Color::Blue);
		
		
		}


	}
	void movedown() {

		if (menuselected +1 <= chudi)
		{
			root[menuselected].setFillColor(Color::White);
			menuselected++;
			if (menuselected == 3)
				menuselected = 0;
			root[menuselected].setFillColor(Color::Blue);


		}


	}
	int menupress() {

		return menuselected;
	}
	~Root(){};

	void dd(RenderWindow& window) {

		window.clear(Color(34, 139, 34));
		RectangleShape base(Vector2f(247, 700));
		base.setFillColor(Color::White);
		base.setPosition(753, 0);
		RectangleShape base1(Vector2f(241, 293));
		base1.setFillColor(Color::Cyan);
		base1.setPosition(756, 403);
		RectangleShape base2(Vector2f(233, 169));
		base2.setFillColor(Color::Green);
		base2.setPosition(761, 223);
		/*CircleShape cc(60);
		cc.setPosition(510, 200);
		cc.setFillColor(Color(91, 204, 286, 0));
		cc.setOutlineColor(Color::Blue);
		cc.setOutlineThickness(-5);*/
		/*CircleShape tt(32, 60);
		tt.setPosition(766, 17);
		tt.setFillColor(Color(91, 204, 246, 0));
		tt.setOutlineColor(Color::White);
		tt.setOutlineThickness(-5);
		RectangleShape ss(Vector2f(233, 169));
		ss.setFillColor(Color(91, 204, 246, 0));
		ss.setOutlineColor(Color::Black);
		ss.setOutlineThickness(-5);
		ss.setPosition(761, 223);*/

		RectangleShape console(Vector2f(53, 35));
		console.setPosition(768, 256);
		console.setFillColor(Color::Yellow);

		RectangleShape cob(Vector2f(53, 35));
		cob.setPosition(768, 301);
		cob.setFillColor(Color::Magenta);

		RectangleShape cob1(Vector2f(53, 35));
		cob1.setPosition(768, 346);
		cob1.setFillColor(Color::Cyan);

		RectangleShape col1(Vector2f(55, 35));
		cob1.setPosition(849, 256);
		cob1.setFillColor(Color::Red);
		RectangleShape col2(Vector2f(55, 35));
		col1.setPosition(849, 301);
		col1.setFillColor(Color::Red);
		RectangleShape col3(Vector2f(55, 35));
		col3.setPosition(849, 346);
		col3.setFillColor(Color::Red);

		RectangleShape las1(Vector2f(53, 35));
		las1.setPosition(768, 346);
		las1.setFillColor(Color::Cyan);
		RectangleShape las2(Vector2f(55, 35));
		las2.setPosition(932, 255);
		las2.setFillColor(Color::Cyan);
		RectangleShape las3(Vector2f(55, 35));
		las3.setPosition(932, 301);
		las3.setFillColor(Color::Cyan);
		RectangleShape las4(Vector2f(55, 35));
		las4.setPosition(932, 346);
		las4.setFillColor(Color::Cyan);

		CircleShape tri(36, 3);
		tri.setPosition(840, 17);
		tri.setFillColor(Color::Yellow);
		tri.setOutlineColor(Color::Blue);
		tri.setOutlineThickness(-3);
		CircleShape tri1(31);
		tri1.setPosition(766, 17);
		tri1.setFillColor(Color::Yellow);
		tri1.setOutlineColor(Color::Blue);
		tri1.setOutlineThickness(-3);

		RectangleShape bo1(Vector2f(61, 61));
		bo1.setPosition(926, 15);
		bo1.setFillColor(Color::Yellow);
		bo1.setOutlineColor(Color::Blue);
		bo1.setOutlineThickness(-3);
		CircleShape bo2(37, 8);
		bo2.setPosition(768, 113);
		bo2.setFillColor(Color::Yellow);
		bo2.setOutlineColor(Color::Blue);
		bo2.setOutlineThickness(-3);
		CircleShape bo3(37, 6);
		bo3.setPosition(855, 113);
		bo3.setFillColor(Color::Yellow);
		bo3.setOutlineColor(Color::Blue);
		bo3.setOutlineThickness(-3);
		//button
		CircleShape hh(17, 3);
		hh.setPosition(853, 423);
		hh.setFillColor(Color::Black);

		CircleShape hh1(30);
		hh1.setPosition(840, 409);
		hh1.setFillColor(Color::Yellow);
		hh1.setOutlineColor(Color::Blue);
		hh1.setOutlineThickness(-3);

		CircleShape d(17, 3);
		d.setPosition(887, 568);
		d.setRotation(360.f);
		d.rotate(180.f);
		d.setFillColor(Color::Black);

		CircleShape d1(30);
		d1.setPosition(840, 519);
		d1.setFillColor(Color::Yellow);
		d1.setOutlineColor(Color::Blue);
		d1.setOutlineThickness(-3);

		CircleShape dl(17, 3);
		dl.setPosition(790, 509);
		dl.setRotation(360.f);
		dl.rotate(270.f);
		dl.setFillColor(Color::Black);

		CircleShape dl1(30);
		dl1.setPosition(775, 461);
		dl1.setFillColor(Color::Yellow);
		dl1.setOutlineColor(Color::Blue);
		dl1.setOutlineThickness(-3);

		CircleShape dr(17, 3);
		dr.setPosition(937, 479);
		dr.setRotation(360.f);
		dr.rotate(90.f);
		dr.setFillColor(Color::Black);

		CircleShape dr1(30);
		dr1.setPosition(893, 466);
		dr1.setFillColor(Color::Yellow);
		dr1.setOutlineColor(Color::Blue);
		dr1.setOutlineThickness(-3);

		RectangleShape p(Vector2f(18, 4));
		p.setPosition(788, 648);
		//p.setRotation(360.f);
		//p.rotate(270.f);
		p.setFillColor(Color::Black);

		CircleShape pt(8, 3);
		pt.setPosition(777, 659);
		pt.setRotation(360.f);
		pt.rotate(270.f);
		pt.setFillColor(Color::Black);

		CircleShape p1(23);
		p1.setPosition(773, 627);
		p1.setFillColor(Color::Yellow);
		p1.setOutlineColor(Color::Blue);
		p1.setOutlineThickness(-3);


		RectangleShape q(Vector2f(18, 4));
		q.setPosition(847, 649);
		//p.setRotation(360.f);
		//p.rotate(270.f);
		q.setFillColor(Color::Black);

		CircleShape qt(8, 3);
		qt.setPosition(876, 642);
		qt.setRotation(360.f);
		qt.rotate(90.f);
		qt.setFillColor(Color::Black);

		CircleShape q1(23);
		q1.setPosition(835, 627);
		q1.setFillColor(Color::Yellow);
		q1.setOutlineColor(Color::Blue);
		q1.setOutlineThickness(-3);

		RectangleShape su(Vector2f(18, 4));
		su.setPosition(948, 589);
		//p.setRotation(360.f);
		//p.rotate(270.f);
		su.setFillColor(Color::Black);
		RectangleShape sd(Vector2f(18, 4));
		sd.setPosition(958, 582);
		sd.setRotation(360.f);
		sd.rotate(90.f);
		sd.setFillColor(Color::Black);
		CircleShape s1(21);
		s1.setPosition(935, 569);
		s1.setFillColor(Color::Yellow);
		s1.setOutlineColor(Color::Blue);
		s1.setOutlineThickness(-3);


		RectangleShape su2(Vector2f(18, 4));
		su2.setPosition(944, 647);

		su2.setFillColor(Color::Black);

		CircleShape s2(21);
		s2.setPosition(932, 627);
		s2.setFillColor(Color::Yellow);
		s2.setOutlineColor(Color::Blue);
		s2.setOutlineThickness(-3);



		//RectangleShape bal(Vector2f(241, 293));
		//ss.setFillColor(Color(193, 199, 126, 0.65));
		////ss.setOutlineColor(Color::Black);
		////ss.setOutlineThickness(-5);
		//ss.setPosition(756, 403);

		/*	RectangleShape console(Vector2f(53, 35));
			console.setPosition(768, 256);
			console.setFillColor(Color(193, 199, 126, 165));
			RectangleShape console(Vector2f(53, 35));
			console.setPosition(768, 256);
			console.setFillColor(Color(193, 199, 126, 165));*/


		window.draw(base);
		window.draw(base1);
		window.draw(base2);
		window.draw(console);

		window.draw(cob);
		window.draw(cob1);
		window.draw(col1);
		window.draw(col3);
		window.draw(las1);
		window.draw(las2);
		window.draw(las3);
		window.draw(las4);
		window.draw(tri);
		window.draw(tri1);
		window.draw(bo1);
		window.draw(bo2);
		window.draw(bo3);
		window.draw(hh1);
		window.draw(hh);

		window.draw(d1);
		window.draw(d);

		window.draw(dl1);
		window.draw(dl);
		window.draw(dr1);
		window.draw(dr);

		window.draw(p1);
		window.draw(p);
		window.draw(pt);




		window.draw(q1);

		window.draw(q);

		window.draw(qt);
		window.draw(s1);
		window.draw(s2);
		window.draw(su);
		window.draw(sd);
		window.draw(su2);

		//window.draw(base1);


			//window.draw(bal);
			//window.draw(cc);
			/*window.draw(tt);
			window.draw(ss);*/

			/*	window.draw(console);
				window.draw(cob);
				window.draw(cob1);
				window.draw(col1);
				window.draw(col2);
				window.draw(col3);*/

		//window.display();
	}

private:
	int menuselected;
	Font f;
	Text root[chudi];
	//text det[1];
};