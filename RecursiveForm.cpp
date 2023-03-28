#include <vcl.h>
#include <iostream>
#include "RecursiveForm.h"
#include <cmath>

#pragma hdrstop
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 * Form1;

__fastcall TForm1::TForm1(TComponent * Owner) : TForm(Owner) {
}

// No ejecutar porque esta vaina es infinito...
void Recursivo(byte n) {
	ShowMessage("Hola");
	Recursivo(n + 1);
	ShowMessage("Chau");
}

void __fastcall TForm1::Button1Click(TObject * Sender) {
	// Recursivo(5);
}
// ---------------------------------------------------------------------------

// 1) Escribir una función que devuelva x^n
float Pot(float x, byte n) {
	float p;
	try {
		if ((x == 0) && (n == 0))
			throw "Error: Indeterminación";
		else {
			if (n == 0)
				p = 1;
			else {
				p = Pot(x, n - 1);
				p = p * x;
			}
		}
	}
	catch (const char * x) {
		ShowMessage(x);
		p = 0;
	}
	return p;
}

void __fastcall TForm1::Potenciadeunnumero1Click(TObject * Sender) {
	Result1->Text = Pot(StrToFloat(Input->Text), StrToInt(Input2->Text));
}
// ---------------------------------------------------------------------------

byte Addition(Cardinal x) {
	return (x < 10) ? x : (Addition(x / 10) + x % 10);
}

void __fastcall TForm1::Sumar1Click(TObject * Sender) {
	Result1->Text = Addition(StrToInt(Input->Text));
}
// ---------------------------------------------------------------------------

byte Prime(byte d, bool aux) {
	if ((d == 0) || (d == 4) || (d == 6) || (d == 8) || (d == 9)) {
		return aux ? 0 : d;
	}
	else {
		return aux ? d : 0;
	}
}

byte AddDigitPrimes(Cardinal x) {
	return (x < 10) ? Prime(x, false) : AddDigitPrimes(x / 10) +
		Prime(x % 10, true);
}

void __fastcall TForm1::SumarPrimos1Click(TObject *Sender) {
	Result1->Text = AddDigitPrimes(StrToInt(Input->Text));
}
// ---------------------------------------------------------------------------

byte MajorDigit(Cardinal x) {
	byte m;
	if (x < 10) { // caso base
		m = x;
	}
	else { // general case
		m = MajorDigit(x / 10);
		if (m < x % 10)
			m = x % 10;
	}
	return m;
}

void __fastcall TForm1::Digitomayor1Click(TObject * Sender) {
	Result1->Text = MajorDigit(StrToInt(Input->Text));
}
// ---------------------------------------------------------------------------

void Recursivo2(byte num) {
	if (num == 0) {
	}
	else {
		ShowMessage(num);
		Recursivo2(num - 1);
	}
}

void NoRecursivo() {
	for (byte i = 0; i < 5; i++) {
		ShowMessage(i);
	}
}

void __fastcall TForm1::est1Click(TObject *Sender) {
	// NoRecursivo();
	Recursivo2(5);
}
// ---------------------------------------------------------------------------

void MayorAlFinal(Cardinal &x) {
	byte s;
	if (x >= 10) {
		// x = 0; // no hacer nada
	}
	else {
		byte z1 = x % 10;
		x = x / 10;
		MayorAlFinal(x);
		if (z1 >= x % 10) {
			x = x * 10 + z1;
		}
		else {
			byte z2 = x % 10;
			x = x / 10;
			x = x * 10 + z1;
			x = x * 10 + z2;
		}
	}
}

void __fastcall TForm1::Moverdigitomayoralfinal1Click(TObject *Sender) {
	Cardinal z = StrToInt(Input->Text);
	MayorAlFinal(z);
	Result1->Text = z;
}
// ---------------------------------------------------------------------------

// Hacer un proceso para ordenar un numero en sus digitos
void OrdenarDigitos(Cardinal &x) {
	if (x >= 10) {
		// no hacer nada
	}
	else {
		MayorAlFinal(x);
		byte z1 = x % 10;
		x = x / 10;
		OrdenarDigitos(x);
		x = x * 10 + z1;
	}
}

void __fastcall TForm1::OrdenarDigitos1Click(TObject *Sender) {
	Cardinal z = StrToInt(Input->Text);
	OrdenarDigitos(z);
	Result1->Text = z;
}
// ---------------------------------------------------------------------------

// Algoritmo para verificar si un numero esta ordenado
bool CheckIfIsOrder(Cardinal x) {
	bool e;
	if (x < 10) {
		e = true;
	}
	else {
		byte z = x % 10;
		byte y = (x / 10) % 10;
		e = CheckIfIsOrder(x / 10) && (y <= z);
	}
	return e;
}

void __fastcall TForm1::VerificarsiestaOrdenado1Click(TObject *Sender) {
	Result1->Text = CheckIfIsOrder(StrToInt(Input->Text)) ? "Esta Ordenado." :
		"No esta ordenado.";
}
// ---------------------------------------------------------------------------

void DeleteDigitOdd(Cardinal & x) {
	if (x < 10) { // Caso base
		if (x % 2 == 1) {
			x = 0;
		}
	}
	else { // Caso general
		byte digit = x % 10;
		x = x / 10;
		DeleteDigitOdd(x);
		if (digit % 2 == 0) {
			x = x * 10 + digit;
		}
	}
}

void __fastcall TForm1::Eliminardigitosimpares1Click(TObject * Sender) {
	Cardinal z = StrToInt(Input->Text);
	DeleteDigitOdd(z);
	Result1->Text = z;
}

void MajorAndMinorDigit(Cardinal x, byte & major, byte & minor) {
	if (x < 10) {
		major = x;
		minor = x;
	}
	else {
		byte digit = x % 10;
		MajorAndMinorDigit(x / 10, major, minor);
		if (digit < minor) {
			minor = digit;
		}

		if (digit > major) {
			major = digit;
		}
	}
}

void __fastcall TForm1::digitomayorymenor2Click(TObject * Sender) {
	byte a, b;
	MajorAndMinorDigit(StrToInt(Input->Text), a, b);
	Result1->Text = a;
	Result2->Text = b;
}
// ---------------------------------------------------------------------------

bool IsVowel(char z) {
	AnsiString vowels = "aeiouAEIOU������������";
	return vowels.Pos(z) > 0;
}

byte AmountVowels(AnsiString x) {
	byte c;
	if (x == "") {
		c = 0;
	}
	else {
		char z = x[1];
		x.Delete(1, 1);
		c = AmountVowels(x);
		if (IsVowel(z)) {
			c++;
		}
	}
	return c;
}

void __fastcall TForm1::CantidaddevocalesdeunString1Click(TObject * Sender) {
	Result1->Text = AmountVowels(Input->Text);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::testeandostrings1Click(TObject * Sender) {
	String someThings = "Hola como estas?";
	Result1->Text = someThings[StrToInt(Input->Text)];
}

// ---------------------------------------------------------------------------
