#include <vcl.h>
#include <iostream>
#include "RecursiveForm.h"
#include <cmath>
#include <string>

#pragma hdrstop
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1* Form1;

__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ¡No ejecutar! porque esta vaina es infinito...
void Recursivo(byte n) {
	ShowMessage("Hola");
	Recursivo(n + 1);
	ShowMessage("Chau");
}

void __fastcall TForm1::Button1Click(TObject* Sender) {
	// Recursivo(5);
}
// ---------------------------------------------------------------------------
// 1) Escribir una función que devuelva la potencia de un numero x^n
float PowerOfANumber(float x, byte n) {
	if ((x == 0) && (n == 0)) {
		throw "Error: Indeterminación";
	}
	else {
		return (n == 0) ? 1 : PowerOfANumber(x, n - 1) * x;
	}
}

void __fastcall TForm1::Potenciadeunnumero1Click(TObject* Sender) {
	try {
		if (Input->Text == "" || Input2->Text == "") {
			throw "Debe ingresar un número";
		}

		float num = StrToFloat(Input->Text);
		byte exp = StrToInt(Input2->Text);

		Result1->Text = PowerOfANumber(num, exp);
	}
	catch (const char* x) {
		ShowMessage(x);
		Result1->Text = "";
	}
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::Sumar1Click(TObject* Sender) {
	// Result1->Text = Addition(StrToInt(Input->Text));
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::SumarPrimos1Click(TObject* Sender) {
	//          Result1->Text = AddDigitPrimes(StrToInt(Input->Text));
	// Result1->Text = SumarDigitosPrimos(StrToInt(Input->Text));
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::Digitomayor1Click(TObject* Sender) {
	// Result1->Text = MajorDigit(StrToInt(Input->Text));
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::Moverdigitomayoralfinal1Click(TObject* Sender) {
	// Cardinal z = StrToInt(Input->Text);
	// MajorAtEnd(z);
	// Result1->Text = z;
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::OrdenarDigitos1Click(TObject* Sender) {
	// Cardinal z = StrToInt(Input->Text);
	// OrdenarDigitos(z);
	// Result1->Text = z;
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::VerificarsiestaOrdenado1Click(TObject* Sender) {
	// Result1->Text = CheckIfIsOrder(StrToInt(Input->Text)) ? "Está Ordenado." :
		// "No está ordenado.";
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::Eliminardigitosimpares1Click(TObject* Sender) {
	// Cardinal z = StrToInt(Input->Text);
	// DeleteDigitOdd(z);
	// Result1->Text = z;
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::digitomayorymenor2Click(TObject* Sender) {
	// byte a, b;
	// MajorAndMinorDigit(StrToInt(Input->Text), a, b);
	// Result1->Text = a;
	// Result2->Text = b;
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::ContarLetras1Click(TObject* Sender) {
	// Result1->Text = AmountLetters(Input->Text);
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::CantidaddevocalesdeunString1Click(TObject* Sender) {
	// Result1->Text = AmountVowels(Input->Text);
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::testeandostrings1Click(TObject* Sender) {
	String someThings = " Hola cómo estás? ";
	Result1->Text = someThings[StrToInt(Input->Text)];
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::Devuelvesolonumeros1Click(TObject* Sender) {
	// Result1->Text = ReturnNumber(Input->Text);
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::Eliminarpalabrasqueserepitansuvocal1Click
	(TObject* Sender) {
	// Result1->Text = DeleteRepeatVowelWord(Input->Text);
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::est1Click(TObject* Sender) {
	// Result1->Text = VocalRepetida(Input->Text) ? "yes" : "no";
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::Inverso1Click(TObject* Sender) {
	// Result1->Text = inverso5(Input->Text);
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::Elimnarletrasnoalfabeticas1Click(TObject* Sender) {
	// AnsiString x = Input->Text;
	// DeleteNoLetter(x);
	// Result1->Text = x;
}
// ---------------------------------------------------------------------------
