//---------------------------------------------------------------------------

#ifndef RecursiveFormH
#define RecursiveFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
  __published: // IDE-managed Components
    TEdit* Input;
    TEdit* Result1;
    TMainMenu* MainMenu1;
    TMenuItem* Eliminardigitosimpares1;
    TMenuItem* digitomayorymenor2;
    TEdit* Result2;
    TMenuItem* CantidaddevocalesdeunString1;
    TMenuItem* testeandostrings1;
    TLabel* Label0;
    TLabel* Label1;
    TLabel* label2;
    TMenuItem* Sumar1;
    TMenuItem* Digitomayor1;
    TButton* Button1;
    TMenuItem* Potenciadeunnumero1;
    TEdit* Input2;
    TLabel* Label3;
    void __fastcall Eliminardigitosimpares1Click(TObject* Sender);
    void __fastcall digitomayorymenor2Click(TObject* Sender);
    void __fastcall CantidaddevocalesdeunString1Click(TObject* Sender);
    void __fastcall testeandostrings1Click(TObject* Sender);
    void __fastcall Sumar1Click(TObject* Sender);
    void __fastcall Digitomayor1Click(TObject* Sender);
    void __fastcall Button1Click(TObject* Sender);
    void __fastcall Potenciadeunnumero1Click(TObject* Sender);
  private: // User declarations
  public: // User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1* Form1;
//---------------------------------------------------------------------------
#endif

