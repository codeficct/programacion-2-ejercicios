#include <vcl.h>
#include <iostream>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1* Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {}
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
    Cardinal z = StrToInt(Edit1->Text);
    DeleteDigitOdd(z);
    Edit2->Text = z;
}
//---------------------------------------------------------------------------
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
    MajorAndMinorDigit(StrToInt(Edit1->Text), a, b);
    Edit2->Text = a;
    Edit3->Text = b;
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
    Edit2->Text = AmountVowels(Edit1->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::testeandostrings1Click(TObject* Sender)
{
    String someThings = "Hola como estas?";
    Edit2->Text = someThings[StrToInt(Edit1->Text)];
}
//---------------------------------------------------------------------------

