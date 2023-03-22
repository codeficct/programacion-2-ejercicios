#include <vcl.h>

#include <iostream>
#pragma hdrstop
#include "RecursiveForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1* Form1;

__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {}

void Recursivo(byte n) // No ejecutar porque esta vaina es infinito...
{
    ShowMessage("Hola");
    Recursivo(n + 1);
    ShowMessage("Chau");
}

void __fastcall TForm1::Button1Click(TObject* Sender)
{
    // Recursivo(5);
}
//---------------------------------------------------------------------------
/*
	1) Escribir una función que devuelva x^n
	Paso 0: E: x,n (un numero real, un numero natural)
			S: p (Un numero real)
*/
float Pot(float x, byte n)
{
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

    } catch (const char* x) {
        ShowMessage(x);
        p = 0;
    }
    return p;
}

void __fastcall TForm1::Potenciadeunnumero1Click(TObject* Sender)
{
    Result1->Text = Pot(StrToFloat(Input->Text), StrToInt(Input2->Text));
}
//---------------------------------------------------------------------------

double Addition(Cardinal x)
{
    byte s;
    if (x < 10)
        s = x;
    else
        s = Addition(x / 10) + x % 10;
    return s;
}

void __fastcall TForm1::Sumar1Click(TObject* Sender)
{
    Result1->Text = Addition(StrToInt(Input->Text));
}
//---------------------------------------------------------------------------

byte MajorDigit(Cardinal x)
{
    byte m;
    if (x < 10) // base case
        m = x;
    else { // general case
        m = MajorDigit(x / 10);
        if (m < x % 10)
            m = x % 10;
    }
    return m;
}

void __fastcall TForm1::Digitomayor1Click(TObject* Sender)
{
    Result1->Text = MajorDigit(StrToInt(Input->Text));
}
//---------------------------------------------------------------------------

void DeleteDigitOdd(Cardinal &x)
{
    if (x < 10) { // Caso base
        if (x % 2 == 1) {
            x = 0;
        }
    } else { // Caso general
        byte digit = x % 10;
        x = x / 10;
        DeleteDigitOdd(x);
        if (digit % 2 == 0) {
            x = x * 10 + digit;
        }
    }
}

void __fastcall TForm1::Eliminardigitosimpares1Click(TObject* Sender)
{
    Cardinal z = StrToInt(Input->Text);
    DeleteDigitOdd(z);
    Result1->Text = z;
}

void MajorAndMinorDigit(Cardinal x, byte &major, byte &minor)
{
    if (x < 10) {
        major = x;
        minor = x;
    } else {
        byte digit = x % 10;
        MajorAndMinorDigit(x / 10, major, minor);
        if (digit < minor)
            minor = digit;

        if (digit > major)
            major = digit;
    }
}

void __fastcall TForm1::digitomayorymenor2Click(TObject* Sender)
{
    byte a, b;
    MajorAndMinorDigit(StrToInt(Input->Text), a, b);
    Result1->Text = a;
    Result2->Text = b;
}
//---------------------------------------------------------------------------

bool IsVowel(char z)
{
    AnsiString vowels = "aeiouAEIOU������������";
    return vowels.Pos(z) > 0;
}

byte AmountVowels(AnsiString x)
{
    byte c;
    if (x == "") {
        c = 0;
    } else {
        char z = x[1];
        x.Delete(1, 1);
        c = AmountVowels(x);
        if (IsVowel(z))
            c++;
    }
    return c;
}

void __fastcall TForm1::CantidaddevocalesdeunString1Click(TObject* Sender)
{
    Result1->Text = AmountVowels(Input->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::testeandostrings1Click(TObject* Sender)
{
    String someThings = "Hola como estas?";
    Result1->Text = someThings[StrToInt(Input->Text)];
}
//---------------------------------------------------------------------------

