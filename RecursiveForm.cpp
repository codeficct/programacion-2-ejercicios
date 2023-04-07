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
// 2) Escribir una función que sume los digitos de un numero
byte Addition(Cardinal x) {
	return (x < 10) ? x : (Addition(x / 10) + x % 10);
}

void __fastcall TForm1::Sumar1Click(TObject* Sender) {
	Result1->Text = Addition(StrToInt(Input->Text));
}
// ---------------------------------------------------------------------------
// 3) Escribir una función que sume los dígitos primos de un número
bool IsPrime(byte dig) {
	return !((dig == 0) || (dig == 4) ||(dig == 6) ||
		(dig == 8) || (dig == 9)); // devolvemos true si el digito es primo
}

byte AddDigitPrimes(Cardinal x) {
	if (x < 10)
		return x;
	else {
		byte lastDigit = x % 10;
		return AddDigitPrimes(x / 10) + (IsPrime(lastDigit) ? lastDigit : 0);
	}
}

void __fastcall TForm1::SumarPrimos1Click(TObject* Sender) {
	Result1->Text = AddDigitPrimes(StrToInt(Input->Text));
}
// ---------------------------------------------------------------------------
// 4) Escribir una función que devuelva el dígito mayor de un número
byte GetMajorDigit(Cardinal x) {
	if (x < 10) // caso base
		return x;
	else { // general case
		byte lastDigit = x % 10;
		byte m = GetMajorDigit(x / 10);
		return (m < lastDigit) ? lastDigit : m;
	}
}

void __fastcall TForm1::Digitomayor1Click(TObject* Sender) {
	Result1->Text = GetMajorDigit(StrToInt(Input->Text));
}
// ---------------------------------------------------------------------------
// 5) Escribir un algoritmo que pegue el digito mayor al final
void MoveDigitMajorAtEnd(Cardinal& x) {
	if (x >= 10) {
		byte major = x % 10, minor;
		x = x / 10;
		MoveDigitMajorAtEnd(x);
		minor = x % 10;
		x = (major >= minor)
			// si "major" es el dígito mayor, pegamos al final
			? x * 10 + major;
			// sino -> cortamos y intercambiamos ej) 213 54 => 213 45
			: ((x / 10) * 10 + major) * 10 + minor
	}
}

void __fastcall TForm1::Moverdigitomayoralfinal1Click(TObject* Sender) {
	Cardinal num = StrToInt(Input->Text);
	MoveDigitMajorAtEnd(num);
	Result1->Text = num;
}
// ---------------------------------------------------------------------------
// 6) Hacer un proceso para ordenar un número en sus dígitos
void SortDigits(Cardinal& x) {
	if (x >= 10) {
		MoveDigitMajorAtEnd(x);
		byte lastDigit = x % 10;
		x = x / 10;
		SortDigits(x);
		x = x * 10 + lastDigit;
	}
}

void __fastcall TForm1::OrdenarDigitos1Click(TObject* Sender) {
	Cardinal num = StrToInt(Input->Text);
	SortDigits(num);
	Result1->Text = num;
}
// ---------------------------------------------------------------------------
// 7) Algoritmo para verificar si un número está ordenado
bool CheckIfIsOrder(Cardinal x) {
	if (x < 10)
		return true;
	else {
		byte z = x % 10;
		byte y = (x / 10) % 10;
		return CheckIfIsOrder(x / 10) && (y <= z);
	}
}

void __fastcall TForm1::VerificarsiestaOrdenado1Click(TObject* Sender) {
	bool isOrder = CheckIfIsOrder(StrToInt(Input->Text));
	Result1->Text = isOrder ? "Está Ordenado." : "No está ordenado.";
}
// ---------------------------------------------------------------------------
// 8) Algoritmo para eliminar digitos impares
void DeleteOddDigits(Cardinal& x) {
	if (x < 10) { // Caso base
		if (x % 2 == 1)
			x = 0;
	}
	else { // Caso general
		byte lastDigit = x % 10;
		x = x / 10;
		DeleteOddDigits(x);
		if (lastDigit % 2 == 0)
			x = x * 10 + lastDigit;
	}
}

void __fastcall TForm1::Eliminardigitosimpares1Click(TObject* Sender) {
	Cardinal z = StrToInt(Input->Text);
	DeleteOddDigits(z);
	Result1->Text = z;
}
// ---------------------------------------------------------------------------
// 9) Algoritmo que devuelva el dígito mayor y menor de un número
void MajorAndMinorDigit(Cardinal x, byte& major, byte& minor) {
	if (x < 10) {
		major = x;
		minor = x;
	}
	else {
		byte digit = x % 10;
		MajorAndMinorDigit(x / 10, major, minor);
		minor = digit < minor ? digit : minor;
		major = digit > major ? digit : major
	}
}

void __fastcall TForm1::digitomayorymenor2Click(TObject* Sender) {
	byte major, minor;
	MajorAndMinorDigit(StrToInt(Input->Text), major, minor);
	Result1->Text = major;
	Result2->Text = minor;
}
// ---------------------------------------------------------------------------
// 10) Contar letras de una cadena
bool IsLetter(char l) { // verificar si un caracter es una letra
	AnsiString letters =
		"qwertyuiopasdfghjklzxcvbnmñQWERTYUIOPASDFGHJKLÑZXCVBNMáéíóúÁÉÍÓÚ";
	return letters.Pos(l) > 0;
}

byte AmountLetters(AnsiString x) {
	if (x == "")
		return 0;
	else {
		char firstLetter = x[1];
		x.Delete(1, 1);
		return AmountLetters(x) + (IsLetter(firstLetter) ? 1 : 0);
	}
}

void __fastcall TForm1::ContarLetras1Click(TObject* Sender) {
	Result1->Text = AmountLetters(Input->Text);
}
// ---------------------------------------------------------------------------
// 11) Contar vocales de una cadena
bool IsVowel(char l) {
	AnsiString vowels = "aeiouAEIOUáéíóúÁÉÍÓÚ";
	return vowels.Pos(l) > 0;
}

byte AmountVowels(AnsiString x) {
	if (x == "")
		return 0;
	else {
		char firstLetter = x[1];
		x.Delete(1, 1);
		return AmountVowels(x) + (IsVowel(firstLetter) ? 1 : 0);
	}
}

void __fastcall TForm1::CantidaddevocalesdeunString1Click(TObject* Sender) {
	Result1->Text = AmountVowels(Input->Text);
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::testeandostrings1Click(TObject* Sender) {
	String someThings = " Hola cómo estás? ";
	Result1->Text = someThings[StrToInt(Input->Text)];
}
// ---------------------------------------------------------------------------
// 12) Devolver solo los números de una cadena
bool isNumber(char z) {
	return (z >= '0') && (z <= '9');
}

Cardinal ReturnNumber(AnsiString x) {
	Cardinal c, c1;
	if (x == "")
		c = 0;
	else {
		byte n = x.Length();
		char lastCharacter = x[n];
		x.Delete(n, 1);
		c = ReturnNumber(x);
		if (isNumber(lastCharacter)) {
			c = c * 10 + (lastCharacter - 48);
		}
	}
	return c;
}

void __fastcall TForm1::Devuelvesolonumeros1Click(TObject* Sender) {
	Result1->Text = ReturnNumber(Input->Text);
}
// ---------------------------------------------------------------------------
// Verificar si una vocal se repite en una palabra
bool IsRepeatedVowel(AnsiString w) {
	if (w.Length() == 0)
		return false;
	else {
		char a = w[1]; // first character
		w.Delete(1, 1); // delete first character
		return IsRepeatedVowel(w) || (IsVowel(a) && w.Pos(a) > 0);
	}
}

// Eliminar palabras que contengan vocales repetidas
AnsiString DeleteRepeatVowelWord(AnsiString x) {
	x.Trim();
	if (x.Length() == 0)
		return "";
	else {
		byte pos = x.Pos(" ");
		AnsiString word = pos != 0 ? x.SubStrin
		g(1, pos - 1) : x;
		x = pos != 0 ? x.SubString(pos + 1, x.Length() - pos) : "";

		if (IsRepeatedVowel(word))
			return DeleteRepeatVowelWord(x).Trim();

		return word.Trim() + " " + DeleteRepeatVowelWord(x).Trim();
	}
}

void __fastcall TForm1::Eliminarpalabrasqueserepitansuvocal1Click
	(TObject* Sender) {
	Result1->Text = DeleteRepeatVowelWord(Input->Text);
}
// ---------------------------------------------------------------------------
// 13) Prototipos
// Invertir una cadena
// Prototipo 1 (k=n-1) - menos el primero
AnsiString reverse1(AnsiString x) {
	if (x == "")
		return "";
	else {
		char z = x[1];
		x.Delete(1, 1);
		return reverse1(x) + z;
	}
}

// Prototipo 2 (k=n-1) - menos el último
AnsiString reverse2(AnsiString x) {
	if (x == "")
		return "";
	else {
		char z = x[x.Length()];
		x.Delete(x.Length(), 1);
		return (AnsiString)z + reverse2(x);
	}
}

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
