﻿#include <vcl.h>
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
// void Recursivo(byte n) {
// ShowMessage("Hola");
// Recursivo(n + 1);
// ShowMessage("Chau");
// }

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
	return !((dig == 0) || (dig == 4) || (dig == 6) || (dig == 8) ||
			(dig == 9)); // devolvemos true si el digito es primo
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
				? x * 10 + major
				// sino -> cortamos y intercambiamos ej) 213 54 => 213 45
				: ((x / 10) * 10 + major) * 10 + minor;
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
		major = digit > major ? digit : major;
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
		AnsiString word = pos != 0 ? x.SubString(1, pos - 1) : x;
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
void __fastcall TForm1::est1Click(TObject* Sender) {
	Result1->Text = IsRepeatedVowel(Input->Text) ? "yes" : "no";
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

// Prototipo 3 (k=n-2) - menos los dos primeros
AnsiString reverse3(AnsiString x) {
	if (x.Length() < 2)
		return x;
	else {
		AnsiString z = x.SubString(1, 2);
		x.Delete(1, 2);
		return reverse3(x) + z[2] + z[1];
	}
}

// Prototipo 4 (k=n-2) - menos los dos últimos
AnsiString reverse4(AnsiString x) {
	byte n = x.Length();
	if (n < 2)
		return x;
	else {
		AnsiString z = x.SubString(n - 1, 2);
		x.Delete(n - 1, 2);
		return (AnsiString)z[2] + z[1] + reverse4(x);
	}
}

// Prototipo 5 (k=n-2) - menos el primero y el último
AnsiString reverse5(AnsiString x) {
	byte n = x.Length();
	if (n < 2)
		return x;
	else {
		char z1 = x[1];
		char z2 = x[n];
		x.Delete(n, 1);
		x.Delete(1, 1);
		return (AnsiString)z2 + reverse5(x) + z1;
	}
}

// Prototipo 6 (k=n/2) - Lado izquierdo más corto
AnsiString reverse6(AnsiString x) {
	byte n = x.Length();
	if (n < 2)
		return x;
	else {
		AnsiString z = x.SubString(n / 2 + 1, n - n / 2);
		x.Delete(n / 2 + 1, n - n / 2);
		return reverse6(z) + reverse6(x);
	}
}

// Prototipo 7 (k=n/2) - Lado derecho más corto
AnsiString reverse7(AnsiString x) {
	byte n = x.Length();
	if (n < 2)
		return x;
	else {
		AnsiString z = x.SubString(n / 2 + 1, n - n / 2);
		x.Delete(n / 2 + 1, n - n / 2);
		return reverse6(x) + reverse6(z);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Inverso1Click(TObject* Sender) {
	Result1->Text = reverse7(Input->Text);
}

// ---------------------------------------------------------------------------
// 14) Algoritmo para eliminar todos los caracteres que NO sean alfebeticos,
// excepto el espacio
void DeleteNoLetter(AnsiString& x) {
	byte n = x.Length();
	if (n < 2) {
		if (n == 1 && !(IsLetter(x[1]) || x == ' ')) {
			x = "";
		}
	}
	else {
		AnsiString z = x.SubString(n - 1, 2);
		x.Delete(n - 1, 2);
		DeleteNoLetter(x);
		x = x + (IsLetter(z[1]) || (char)z[1] == ' ' ? (AnsiString)z[1] : "");
		x = x + (IsLetter(z[2]) || (char)z[2] == ' ' ? (AnsiString)z[2] : "");
	}
}

void __fastcall TForm1::Elimnarletrasnoalfabeticas1Click(TObject* Sender) {
	AnsiString text = Input->Text;
	DeleteNoLetter(text);
	Result1->Text = text;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::vector2Click(TObject *Sender) {
	StringGrid1->ColCount = StrToInt(Input->Text);
}

// ---------------------------------------------------------------------------
// 15) Realizar una funcion que devuelva la suma de los elementos de un vector
byte GetAdditionOfVector(TStringGrid *v, byte n) {
	return n == 0
			// caso base
			? 0 : GetAdditionOfVector(v, n - 1) + StrToInt(v->Cells[n - 1][0]);
}

byte GetAdditionOfVector2(TStringGrid *v, byte n) {
	return n == 0
			// caso base
			? 0 : GetAdditionOfVector(v, n - 1) + StrToInt(v->Cells[n - n + 1][0]);
}

void __fastcall TForm1::SumarElementos1Click(TObject *Sender) {
	Result1->Text = GetAdditionOfVector2(StringGrid1, StringGrid1->ColCount);
}

// ---------------------------------------------------------------------------
byte GetAdditionOfVector3(TStringGrid *v, byte a, byte b) {
	return ((b - a + 1) == 0)
			// caso base
			? 0 : GetAdditionOfVector3(v, a + 1, b) + StrToInt(v->Cells[a][0]);
}

void __fastcall TForm1::SumarElementoskn1menoselprimero1Click(TObject *Sender) {
	Result1->Text = GetAdditionOfVector3(StringGrid1, 0,
			StringGrid1->ColCount - 1);
}

// ---------------------------------------------------------------------------
// Sumar Elementos desde a hasta la cantidad (k=n/2)
byte GetAdditionToRange(TStringGrid *v, byte a, byte n) {
	byte halfLong = (n + 1) / 2;
	if (n == 0) {
		return 0;
	}
	else if (n < 2) {
		return StrToInt(v->Cells[a][0]);
	}
	else {
		return GetAdditionToRange(v, a, halfLong) + GetAdditionToRange(v,
				a + halfLong, n / 2);
	}
}

void __fastcall TForm1::Sumarkn2derechacorto1Click(TObject * Sender) {
	byte posInit = StrToInt(Input->Text);
	byte amount = StrToInt(Input2->Text);
	Result1->Text = GetAdditionToRange(StringGrid1, posInit, amount);
}

// ---------------------------------------------------------------------------
// Algoritmo de busqueda binaria
// v[2,4,6,8,10,12,15], x=12
int FindElement(TStringGrid *v, int x, byte a, byte b) {
	int p;
	byte n = b - a + 1;
	if (n == 0) {
		p = -1;
	}
	else if (n == 1) {
		if (x == StrToInt(v->Cells[n][0])) {
			p = a;
		}
	}
	else {
		byte c = (a + b) / 2;
		if (x == StrToInt(v->Cells[c][0])) {
			p = c;
		}
		else {
			p = x < StrToInt(v->Cells[c][0]) //
					? FindElement(v, x, a, c - 1) //
					: FindElement(v, x, c + 1, b);
		}
	}
	return p;
}

void __fastcall TForm1::Busquedabinaria1Click(TObject *Sender) {
	Result1->Text = FindElement(StringGrid1, StrToInt(Input->Text), 0,
			StringGrid1->ColCount - 1);
}

// ---------------------------------------------------------------------------
void burbujear(TStringGrid *v, byte n) {
	if (n > 1) {
		burbujear(v, n - 1);
		if (v->Cells[n - 2][0] > v->Cells[n - 1][0]) {
			int a = StrToInt(v->Cells[n - 2][0]);
			v->Cells[n - 2][0] = v->Cells[n - 1][0];
			v->Cells[n - 1][0] = a;
		}
	}
}

void BubbleSort(TStringGrid *v, byte n) {
	if (n > 1) {
		burbujear(v, n);
		BubbleSort(v, n - 1);
	}

}

void __fastcall TForm1::BubbleSort1Click(TObject *Sender) {
	BubbleSort(StringGrid1, StringGrid1->ColCount);
}

// ---------------------------------------------------------------------------
// ALGORITMOS CON MATRICES
// Dimensionar StringGrid para matrices
void __fastcall TForm1::Button2Click(TObject *Sender) {
	StringGrid1->ColCount = StrToInt(Input->Text);
	StringGrid1->RowCount = StrToInt(Input2->Text);
}

// ---------------------------------------------------------------------------
// Solucion 1 para cargar una matriz randómicamente por filas
void LlenarFilas(TStringGrid *A, byte f, byte n) {
	if (n > 0) {
		LlenarFilas(A, f, n - 1);
		A->Cells[n - 1][f] = Random(25);
	}
}

void Cargar1(TStringGrid *A, byte m, byte n) {
	if (m > 0) {
		Cargar1(A, m - 1, n); // hipótesis
		LlenarFilas(A, m - 1, n);
	}
}

void __fastcall TForm1::Matriz2Click(TObject *Sender) {
	Cargar1(StringGrid1, StringGrid1->RowCount, StringGrid1->ColCount);
}

// ---------------------------------------------------------------------------
// Solucion 2 para cargar una matriz randómicamente por columnas
void LlenarColumnas(TStringGrid *A, byte c, byte n) {
	if (n > 0) {
		LlenarColumnas(A, c, n - 1);
		A->Cells[c][n - 1] = Random(25);
	}
}

void Cargar2(TStringGrid *A, byte m, byte n) {
	if (n > 0) {
		Cargar2(A, m, n - 1);
		LlenarColumnas(A, n - 1, m);
	}
}

void __fastcall TForm1::Cargarporcolumnas1Click(TObject *Sender) {
	Cargar2(StringGrid1, StringGrid1->RowCount, StringGrid1->ColCount);
}

// ---------------------------------------------------------------------------
// Solucion 3 por filas y columnas
void Cargar3(TStringGrid *A, byte m, byte n) {
	if ((m > 0) && (n > 0)) {
		Cargar3(A, m - 1, n - 1);
		LlenarFilas(A, m - 1, n);
		LlenarColumnas(A, n - 1, m);
	}
}

void __fastcall TForm1::CargarporFilasyColumnas1Click(TObject *Sender) {
	Cargar3(StringGrid1, StringGrid1->RowCount, StringGrid1->ColCount);
}

// ---------------------------------------------------------------------------
// Cargar por casillas o datos
void Cargar4(TStringGrid *A, Word k, byte f, byte c) {
	if (k > 0) {
		A->Cells[c][f] = k;
		if (f == 0) {
			c--;
			f = A->RowCount - 1;
		}
		else
			f = f - 1;
		Cargar4(A, k - 1, f, c);
	}
}

void __fastcall TForm1::Cargarporcantidaddecasillas1Click(TObject *Sender) {
	Word m = StringGrid1->RowCount;
	Word n = StringGrid1->ColCount;
	Cargar4(StringGrid1, m*n, m - 1, n - 1);
}

// ---------------------------------------------------------------------------
// Cargar matriz por el metodo de la vibora xd
void Cargar5(TStringGrid *A, Word k, byte f, byte c, bool a) {
	if (k > 0) {
		A->Cells[c][f] = k;
		if ((a && c == 0) || (!a && c == A->ColCount - 1)) {
			f--;
			a = !a;
		}
		else
			c = a ? c - 1 : c + 1;
		Cargar5(A, k - 1, f, c, a);
	}
}

void __fastcall TForm1::Cargarporvibora1Click(TObject *Sender) {
	Word m = StringGrid1->RowCount;
	Word n = StringGrid1->ColCount;
	Cargar5(StringGrid1, m*n, m - 1, n - 1, true);
}

// ---------------------------------------------------------------------------
void Rellenar(TCanvas *A, int x, int y, TColor anterior, TColor nuevo) {
	if (A->Pixels[x][y] == anterior) {
		A->Pixels[x][y] = nuevo;
		Rellenar(A, x, y - 1, anterior, nuevo);
		Rellenar(A, x, y + 1, anterior, nuevo);
		Rellenar(A, x - 1, y, anterior, nuevo);
		Rellenar(A, x + 1, y, anterior, nuevo);
	}
}

void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
		TShiftState Shift, int X, int Y) {
	if (RadioButton1->Checked) {
		Canvas->Pen->Width = 2;
		Canvas->Ellipse(X - 50, Y - 50, X + 50, Y + 50);
	}
	if (RadioButton2->Checked) {
		Rellenar(Canvas, X, Y, Canvas->Pixels[X][Y], clRed);
	}
}

// ---------------------------------------------------------------------------
void LlenarF(TStringGrid *A, byte f, byte d, byte a, byte b) {
	byte n = b - a + 1;
	if (n > 0) {
		LlenarF(A, f, d, a + 1, b);
		A->Cells[a][f] = d;
	}
}

void LlenarC(TStringGrid *A, byte c, byte d, byte a, byte b) {
	byte n = b - a + 1;
	if (n > 0) {
		LlenarC(A, c, d, a + 1, b);
		A->Cells[c][a] = d;
	}
}

void Expancion(TStringGrid * A, byte fa, byte fb, byte ca, byte cb) {
	byte m = fb - fa + 1, n = cb - ca + 1;
	if (m == 1) {
		A->Cells[ca][fa] = 1;
	}
	else if (m > 0) {
		Expancion(A, fa + 1, fb - 1, ca + 1, cb - 1);

		byte d = (m + 1) / 2;

		LlenarF(A, fa, d, ca, cb);
		LlenarF(A, fb, d, ca, cb);

		LlenarC(A, ca, d, fa, fb);
		LlenarC(A, cb, d, fa, fb);
	}
}

void __fastcall TForm1::Cargarexpansion1Click(TObject *Sender) {
	byte m = StringGrid1->RowCount;
	StringGrid1->ColCount = m;
	Expancion(StringGrid1, 0, m - 1, 0, m - 1);
}

// ---------------------------------------------------------------------------
// Algoritmo de vector para cargar una matriz
void CargarV(TStringGrid *V, byte n) {
	if (n > 0) {
		byte m = V->RowCount;
		CargarV(V, n - 1);
		V->Cells[(n - 1) / m][(n - 1) % m] = Random(25);
	}
}

void __fastcall TForm1::Cargarconalgoritmodevector1Click(TObject *Sender) {
	CargarV(StringGrid1, StringGrid1->RowCount*StringGrid1->ColCount);
}

// ---------------------------------------------------------------------------
byte FrecuencyOfElement(TStringGrid *A, byte n, int x) {
	// byte m = A->RowCount;
	byte c;
	if (n == 0) {
		c = 0;
	}
	else {
		byte m = A->RowCount;
		c = FrecuencyOfElement(A, n - 1, x);
		if (x == A->Cells[(n - 1) / m][(n - 1) % m]) {
			c++;
		}
	}
	return c;
	// return n == 0 ? 0 // caso base
	// : FrecuencyOfElement(A, n - 1, x) +
	// (x == A->Cells[(n - 1) / m][(n - 1) % m] ? 1 : 0);
}

void __fastcall TForm1::Frecuenciadeunnumero1Click(TObject *Sender) {
	Input2->Text = FrecuencyOfElement(StringGrid1,
			StringGrid1->RowCount * StringGrid1->ColCount, StrToInt(Input->Text));
}

// ---------------------------------------------------------------------------
// busqueda binaria para una matriz
bool BusquedaBinariaMatriz(TStringGrid *v, byte x, byte a, byte b) {
	int p;
	byte m = v->RowCount;
	byte n = b - a + 1;
	if (n == 0) {
		p = false;
	}
	else if (n == 1) {
		if (x == StrToInt(v->Cells[b / m][b % m])) {
			p = true;
		}
	}
	else {
		byte c = (a + b) / 2;
		if (x == StrToInt(v->Cells[c / m][c % m])) {
			p = true;
		}
		else {
			p = x < StrToInt(v->Cells[c / m][c % m]) //
					? BusquedaBinariaMatriz(v, x, a, c - 1) //
					: BusquedaBinariaMatriz(v, x, c + 1, b);
		}
	}
	return p;
}

void __fastcall TForm1::Busquedabinaria2Click(TObject *Sender) {
	Input2->Text = BusquedaBinariaMatriz(StringGrid1, StrToInt(Input->Text), 0,
			StringGrid1->RowCount * StringGrid1->ColCount - 1) ? "Encontrado" :
			"No hay";
}

// ---------------------------------------------------------------------------
// Invertir los datos de la matriz
void InvertirUnaMatriz() {
	if (x > 1) {
    InvertirUnaMatriz();
	}
}
