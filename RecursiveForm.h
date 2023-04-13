// ---------------------------------------------------------------------------

#ifndef RecursiveFormH
#define RecursiveFormH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Grids.hpp>

// ---------------------------------------------------------------------------
class TForm1 : public TForm {
__published: // IDE-managed Components
	TEdit* Input;
	TEdit* Result1;
	TEdit* Result2;
	TLabel* Label0;
	TLabel* Label1;
	TLabel* label2;
	TButton* Button1;
	TEdit* Input2;
	TLabel* Label3;
	TMainMenu *MainMenu1;
	TMenuItem *Menu1;
	TMenuItem *Potenciadeunnumero1;
	TMenuItem *Sumar1;
	TMenuItem *SumarPrimos1;
	TMenuItem *Digitomayor1;
	TMenuItem *Eliminardigitosimpares1;
	TMenuItem *Moverdigitomayoralfinal1;
	TMenuItem *OrdenarDigitos1;
	TMenuItem *VerificarsiestaOrdenado1;
	TMenuItem *digitomayorymenor2;
	TMenuItem *Menu21;
	TMenuItem *ContarLetras1;
	TMenuItem *CantidaddevocalesdeunString1;
	TMenuItem *Devuelvesolonumeros1;
	TMenuItem *Eliminarpalabrasqueserepitansuvocal1;
	TMenuItem *Elimnarletrasnoalfabeticas1;
	TMenuItem *Inverso1;
	TMenuItem *est1;
	TMenuItem *testeandostrings1;
	TStringGrid *StringGrid1;
	TMenuItem *vector1;
	TMenuItem *vector2;
	TMenuItem *SumarElementos1;
	TMenuItem *SumarElementoskn1menoselprimero1;
	TLabel *Label4;
	TEdit *Input3;
	TMenuItem *Sumarkn2derechacorto1;
	TMenuItem *Busquedabinaria1;
	TMenuItem *BubbleSort1;

	void __fastcall Eliminardigitosimpares1Click(TObject* Sender);
	void __fastcall digitomayorymenor2Click(TObject* Sender);
	void __fastcall CantidaddevocalesdeunString1Click(TObject* Sender);
	void __fastcall testeandostrings1Click(TObject* Sender);
	void __fastcall Sumar1Click(TObject* Sender);
	void __fastcall Digitomayor1Click(TObject* Sender);
	void __fastcall Button1Click(TObject* Sender);
	void __fastcall Potenciadeunnumero1Click(TObject* Sender);
	void __fastcall SumarPrimos1Click(TObject *Sender);
	void __fastcall Moverdigitomayoralfinal1Click(TObject *Sender);
	void __fastcall OrdenarDigitos1Click(TObject *Sender);
	void __fastcall VerificarsiestaOrdenado1Click(TObject *Sender);
	void __fastcall est1Click(TObject *Sender);
	void __fastcall ContarLetras1Click(TObject *Sender);
	void __fastcall Devuelvesolonumeros1Click(TObject *Sender);
	void __fastcall Eliminarpalabrasqueserepitansuvocal1Click(TObject *Sender);
	void __fastcall Inverso1Click(TObject *Sender);
	void __fastcall Elimnarletrasnoalfabeticas1Click(TObject *Sender);
	void __fastcall vector2Click(TObject *Sender);
	void __fastcall SumarElementos1Click(TObject *Sender);
	void __fastcall SumarElementoskn1menoselprimero1Click(TObject *Sender);
	void __fastcall Sumarkn2derechacorto1Click(TObject *Sender);
	void __fastcall Busquedabinaria1Click(TObject *Sender);
	void __fastcall BubbleSort1Click(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TForm1(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1* Form1;
// ---------------------------------------------------------------------------
#endif
