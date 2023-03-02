//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
  __published: // IDE-managed Components
    TEdit* Edit1;
    TEdit* Edit2;
    TMainMenu* MainMenu1;
    TMenuItem* Eliminardigitosimpares1;
    TMenuItem* digitomayorymenor2;
    TEdit* Edit3;
    TMenuItem* CantidaddevocalesdeunString1;
    TMenuItem* testeandostrings1;
    void __fastcall Eliminardigitosimpares1Click(TObject* Sender);
    void __fastcall digitomayorymenor2Click(TObject* Sender);
    void __fastcall CantidaddevocalesdeunString1Click(TObject* Sender);
    void __fastcall testeandostrings1Click(TObject* Sender);
  private: // User declarations
  public: // User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1* Form1;
//---------------------------------------------------------------------------
#endif

