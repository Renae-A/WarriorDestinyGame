#include "stdafx.h"
#include "Game.h"

void Game::ReturnHome()
{
	cout << "The journey home.." << endl; cout << endl;
	cout << "With your new-found strength you find yourself running back to your home." << endl;
	cout << "'I hope I am not too late.', you think to yourself as the glimmer of the Silver Forest fills the sky." << endl;
	cout << "Deep down you feel as though your time away may have been too long." << endl;
	cout << "Your throat chokes up as tears run down your face." << endl; cout << endl;
	cout << "'What if I am too late..?'" << endl; cout << endl;

	cout << "As you approach your house, you slow down." << endl;
	cout << "You hold your breath..." << endl;
	cout << "Holding tight on to the handle of the door, you step in." << endl; cout << endl;

	cout << character.getName() << ".. You're.. home..'" << endl;
	cout << "You breathe out a heavy sigh of relief and run over to your bedridden father." << endl;
	cout << "You let your head rest upon your father's chest." << endl;
	cout << "'Thank you for waiting, father..'" << endl; cout << endl;

	cout << "'Everything will get better soon.'" << endl; cout << endl;

	cout << "END" << endl;
	system("pause");
}