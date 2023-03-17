//#include<sfml/graphics.hpp>

#include <SFML/Graphics.hpp>
#include "root.h"
#include<iostream>
using namespace std;
using namespace sf;
int main() {

	RenderWindow bara(VideoMode(960, 720), "poor cad", Style::Default);

	Root root(bara.getSize().x, bara.getSize().y);
	RectangleShape backgond;
	backgond.setSize(Vector2f(960, 720));
	Texture maintext;
	maintext.loadFromFile("texture/backgroundsmflow.jpg");
	backgond.setTexture(&maintext);
	RectangleShape pbackground;
	pbackground.setSize(Vector2f(960, 720));
	Texture back_text;
	back_text.loadFromFile("texture/backgroundsmflow.jpg");
	pbackground.setTexture(&back_text);

	RectangleShape obackground;
	obackground.setSize(Vector2f(960, 720));
	Texture oback_text;
	oback_text.loadFromFile("texture/madarr.jpg");
	obackground.setTexture(&oback_text);

	RectangleShape abackground;
	abackground.setSize(Vector2f(960, 720));
	Texture aback_text;
	aback_text.loadFromFile("texture/bgg.jpg");
	abackground.setTexture(&aback_text);




	while (bara.isOpen())
	{
		Event e;

		while (bara.pollEvent(e))
		{

			if (e.type == Event::Closed) {
				bara.close();
			}
			if (e.type == Event::KeyReleased) {
				if (e.key.code ==Keyboard::Up) {
					root.moveup();
					break;
				}

				if (e.key.code == Keyboard::Down) {
					root.movedown();
					break;
				}
				if (e.key.code == Keyboard::Return) {
					ContextSettings settings;
	                settings.antialiasingLevel = 8;

	     RenderWindow play(VideoMode(1000, 700), "Poor CAD", Style::Default,settings);
				//	RenderWindow play(VideoMode(1000, 700), "BaraVokto");
					RenderWindow options(VideoMode(960, 720), "Options");
					RenderWindow about(VideoMode(960, 720), "About");
					int x = root.menupress();
					if (x == 0)
					{
						while (play.isOpen())
						{
							Event ee;

							while (play.pollEvent(ee))
							{

								if (ee.type == Event::Closed) {
									play.close();
								}
								if (ee.type == Event::KeyPressed) {
									if (ee.key.code == Keyboard::Escape) {
										play.close();
									}
								}
							}
						
							options.close();
							about.close();
							play.clear();
							
							//play.dd();
						//	play.draw(pbackground);
							root.dd(play);
							play.display();
						}
					}if (x == 1) {
						while (options.isOpen())
						{
							Event ee;

							while (options.pollEvent(ee))
							{

								if (ee.type == Event::Closed) {
									options.close();
								}
								if (ee.type == Event::KeyPressed) {
									if (ee.key.code == Keyboard::Escape) {
										options.close();
									}
								}
							}play.close();
							
							options.clear();
							options.draw(obackground);
							about.close();
							options.display();
						}
					}
					if (x == 2) {

						while (about.isOpen())
						{
							Event ee;

							while (about.pollEvent(ee))
							{

								if (ee.type == Event::Closed) {
									about.close();
								}
								if (ee.type == Event::KeyPressed) {
									if (ee.key.code == Keyboard::Escape) {
										about.close();
									}
								}
							}play.close();
						
							options.clear();
							about.clear();
							about.draw(abackground);
							about.display();
						}
					}
				}
			}
		}
		bara.clear();
		bara.draw(backgond);
		
		root.draw(bara);
		bara.display();


			}
		}


//#include <iostream>
//#include <SFML/Graphics.hpp>
//using namespace sf;
//using namespace std;
//#include "Root.h"

//
//int main()
//{
	/*ContextSettings settings;
	settings.antialiasingLevel = 8;

	RenderWindow window(VideoMode(1000, 700), "Poor CAD", Style::Default,settings);
	while (window.isOpen())
	{
		Event e;

		while (window.pollEvent(e))
		{
			switch (e.type) {
			case Event::Closed:
				window.close();
				break;
			}
		}
*/

//		/////////draw//////////
//		void dd(RenderTarget& window){
//
//		window.clear(Color(34, 139, 34));
//		RectangleShape base(Vector2f(247, 700));
//		base.setFillColor(Color::White);
//		base.setPosition(753, 0);
//		RectangleShape base1(Vector2f(241, 293));
//		base1.setFillColor(Color::Cyan);
//		base1.setPosition(756, 403);
//		RectangleShape base2(Vector2f(233, 169));
//		base2.setFillColor(Color::Green);
//		base2.setPosition(761,223);
//		/*CircleShape cc(60);
//		cc.setPosition(510, 200);
//		cc.setFillColor(Color(91, 204, 286, 0));
//		cc.setOutlineColor(Color::Blue);
//		cc.setOutlineThickness(-5);*/
//		/*CircleShape tt(32, 60);
//		tt.setPosition(766, 17);
//		tt.setFillColor(Color(91, 204, 246, 0));
//		tt.setOutlineColor(Color::White);
//		tt.setOutlineThickness(-5);
//		RectangleShape ss(Vector2f(233, 169));
//		ss.setFillColor(Color(91, 204, 246, 0));
//		ss.setOutlineColor(Color::Black);
//		ss.setOutlineThickness(-5);
//		ss.setPosition(761, 223);*/
//
//		RectangleShape console(Vector2f(53, 35));
//		console.setPosition(768, 256);
//		console.setFillColor(Color::Yellow);
//
//		RectangleShape cob(Vector2f(53, 35));
//		cob.setPosition(768, 301);
//		cob.setFillColor(Color::Magenta);
//
//		RectangleShape cob1(Vector2f(53, 35));
//		cob1.setPosition(768, 346);
//		cob1.setFillColor(Color::Cyan);
//
//		RectangleShape col1(Vector2f(55, 35));
//		cob1.setPosition(849, 256);
//		cob1.setFillColor(Color::Red);
//		RectangleShape col2(Vector2f(55, 35));
//		col1.setPosition(849, 301);
//		col1.setFillColor(Color::Red);
//		RectangleShape col3(Vector2f(55, 35));
//		col3.setPosition(849, 346);
//		col3.setFillColor(Color::Red);
//
//		RectangleShape las1(Vector2f(53, 35));
//		las1.setPosition(768, 346);
//		las1.setFillColor(Color::Cyan);
//		RectangleShape las2(Vector2f(55, 35));
//		las2.setPosition(932, 255);
//		las2.setFillColor(Color::Cyan);
//		RectangleShape las3(Vector2f(55, 35));
//		las3.setPosition(932, 301);
//		las3.setFillColor(Color::Cyan);
//		RectangleShape las4(Vector2f(55, 35));
//		las4.setPosition(932, 346);
//		las4.setFillColor(Color::Cyan);
//
//		CircleShape tri( 36, 3);
//		tri.setPosition(840, 17);
//		tri.setFillColor(Color::Yellow);
//		tri.setOutlineColor(Color::Blue);
//		tri.setOutlineThickness(-3);
//		CircleShape tri1(31);
//		tri1.setPosition(766, 17);
//		tri1.setFillColor(Color::Yellow);
//		tri1.setOutlineColor(Color::Blue);
//		tri1.setOutlineThickness(-3);
//
//		RectangleShape bo1(Vector2f(61, 61));
//		bo1.setPosition(926, 15);
//		bo1.setFillColor(Color::Yellow);
//		bo1.setOutlineColor(Color::Blue);
//		bo1.setOutlineThickness(-3);
//	    CircleShape bo2(37, 8);
//		bo2.setPosition(768, 113);
//		bo2.setFillColor(Color::Yellow);
//		bo2.setOutlineColor(Color::Blue);
//		bo2.setOutlineThickness(-3);
//		CircleShape bo3(37, 6);
//		bo3.setPosition(855, 113);
//		bo3.setFillColor(Color::Yellow);
//		bo3.setOutlineColor(Color::Blue);
//		bo3.setOutlineThickness(-3);
////button
//		CircleShape hh(17, 3);
//		hh.setPosition(853, 423);
//		hh.setFillColor(Color::Black);
//	
//		CircleShape hh1(30);
//		hh1.setPosition(840,409);
//		hh1.setFillColor(Color::Yellow);
//		hh1.setOutlineColor(Color::Blue);
//		hh1.setOutlineThickness(-3);
//		 
//		CircleShape d(17, 3);
//		d.setPosition(887, 568);
//		d.setRotation(360.f);
//		d.rotate(180.f);
//		d.setFillColor(Color::Black);
//
//		CircleShape d1(30);
//		d1.setPosition(840, 519);
//		d1.setFillColor(Color::Yellow);
//		d1.setOutlineColor(Color::Blue);
//		d1.setOutlineThickness(-3);
//
//		CircleShape dl(17, 3);
//		dl.setPosition(790, 509);
//		dl.setRotation(360.f);
//		dl.rotate(270.f);
//		dl.setFillColor(Color::Black);
//
//		CircleShape dl1(30);
//		dl1.setPosition(775, 461);
//		dl1.setFillColor(Color::Yellow);
//		dl1.setOutlineColor(Color::Blue);
//		dl1.setOutlineThickness(-3);
//
//		CircleShape dr(17, 3);
//		dr.setPosition(937, 479);
//		dr.setRotation(360.f);
//		dr.rotate(90.f);
//		dr.setFillColor(Color::Black);
//
//		CircleShape dr1(30);
//		dr1.setPosition(893, 466);
//		dr1.setFillColor(Color::Yellow);
//		dr1.setOutlineColor(Color::Blue);
//		dr1.setOutlineThickness(-3);
//
//		RectangleShape p(Vector2f(18, 4));
//		p.setPosition(788, 648);
//		//p.setRotation(360.f);
//		//p.rotate(270.f);
//		p.setFillColor(Color::Black);
//
//		CircleShape pt(8, 3);
//		pt.setPosition(777, 659);
//		pt.setRotation(360.f);
//		pt.rotate(270.f);
//		pt.setFillColor(Color::Black);
//
//		CircleShape p1(23);
//		p1.setPosition(773, 627);
//		p1.setFillColor(Color::Yellow);
//		p1.setOutlineColor(Color::Blue);
//		p1.setOutlineThickness(-3);
//		 
//
//		RectangleShape q(Vector2f(18, 4));
//		q.setPosition(847, 649);
//		//p.setRotation(360.f);
//		//p.rotate(270.f);
//		q.setFillColor(Color::Black);
//
//		CircleShape qt(8, 3);
//		qt.setPosition(876, 642);
//		qt.setRotation(360.f);
//		qt.rotate(90.f);
//		qt.setFillColor(Color::Black);
//
//		CircleShape q1(23);
//		q1.setPosition(835, 627);
//		q1.setFillColor(Color::Yellow);
//		q1.setOutlineColor(Color::Blue);
//		q1.setOutlineThickness(-3);
//
//		RectangleShape su(Vector2f(18, 4));
//		su.setPosition(948, 589);
//		//p.setRotation(360.f);
//		//p.rotate(270.f);
//		su.setFillColor(Color::Black);
//		RectangleShape sd(Vector2f(18, 4));
//		sd.setPosition(958, 582);
//		sd.setRotation(360.f);
//		sd.rotate(90.f);
//		sd.setFillColor(Color::Black);
//		CircleShape s1(21);
//		s1.setPosition(935, 569);
//		s1.setFillColor(Color::Yellow);
//		s1.setOutlineColor(Color::Blue);
//		s1.setOutlineThickness(-3);
//
//
//		RectangleShape su2(Vector2f(18, 4));
//		su2.setPosition(944,647);
//	
//		su2.setFillColor(Color::Black);
//		
//		CircleShape s2(21);
//		s2.setPosition(932, 627);
//		s2.setFillColor(Color::Yellow);
//		s2.setOutlineColor(Color::Blue);
//		s2.setOutlineThickness(-3);
//
//
//		
//		//RectangleShape bal(Vector2f(241, 293));
//		//ss.setFillColor(Color(193, 199, 126, 0.65));
//		////ss.setOutlineColor(Color::Black);
//		////ss.setOutlineThickness(-5);
//		//ss.setPosition(756, 403);
//
//		/*	RectangleShape console(Vector2f(53, 35));
//			console.setPosition(768, 256);
//			console.setFillColor(Color(193, 199, 126, 165));
//			RectangleShape console(Vector2f(53, 35));
//			console.setPosition(768, 256);
//			console.setFillColor(Color(193, 199, 126, 165));*/
//		
//
//		window.draw(base);
//		window.draw(base1);
//		window.draw(base2);
//		window.draw(console);
//		
//		window.draw(cob);
//		window.draw(cob1);
//		window.draw(col1);
//		window.draw(col3);
//		window.draw(las1);
//		window.draw(las2);
//		window.draw(las3);
//		window.draw(las4);
//		window.draw(tri);
//		window.draw(tri1);
//		window.draw(bo1);
//		window.draw(bo2);
//		window.draw(bo3);
//		window.draw(hh1);
//		window.draw(hh);
//		
//		window.draw(d1);
//		window.draw(d);
//	
//		window.draw(dl1);
//		window.draw(dl);
//		window.draw(dr1);
//		window.draw(dr);
//		
//		window.draw(p1);
//		window.draw(p);
//		window.draw(pt);
//
//
//
//
//		window.draw(q1);
//
//		window.draw(q);
//
//		window.draw(qt);
//		window.draw(s1);
//		window.draw(s2);
//		window.draw(su);
//		window.draw(sd);
//		window.draw(su2);
//
//	//window.draw(base1);
//		
//	
//		//window.draw(bal);
//		//window.draw(cc);
//		/*window.draw(tt);
//		window.draw(ss);*/
//
//	/*	window.draw(console);
//		window.draw(cob);
//		window.draw(cob1);
//		window.draw(col1);
//		window.draw(col2);
//		window.draw(col3);*/
//
//		window.display();
//	}

//}
