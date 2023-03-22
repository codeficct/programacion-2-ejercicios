object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 254
  ClientWidth = 546
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  TextHeight = 21
  object Label0: TLabel
    Left = 66
    Top = 64
    Width = 36
    Height = 21
    Caption = 'Input'
  end
  object Label1: TLabel
    Left = 66
    Top = 110
    Width = 64
    Height = 21
    Caption = 'Output-1'
  end
  object label2: TLabel
    Left = 66
    Top = 156
    Width = 64
    Height = 21
    Caption = 'Output-2'
  end
  object Label3: TLabel
    Left = 262
    Top = 64
    Width = 36
    Height = 21
    Caption = 'Input'
  end
  object Input: TEdit
    Left = 136
    Top = 61
    Width = 97
    Height = 29
    TabOrder = 0
  end
  object Result1: TEdit
    Left = 136
    Top = 107
    Width = 273
    Height = 29
    TabOrder = 1
  end
  object Result2: TEdit
    Left = 136
    Top = 153
    Width = 273
    Height = 29
    TabOrder = 2
  end
  object Button1: TButton
    Left = 463
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Recursivo'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Input2: TEdit
    Left = 304
    Top = 61
    Width = 105
    Height = 29
    TabOrder = 4
  end
  object MainMenu1: TMainMenu
    object Menu1: TMenuItem
      Caption = 'Menu'
      object Potenciadeunnumero1: TMenuItem
        Caption = 'Potencia de un numero'
        OnClick = Potenciadeunnumero1Click
      end
      object Sumar1: TMenuItem
        Caption = 'Sumar digitos'
        OnClick = Sumar1Click
      end
      object Digitomayor1: TMenuItem
        Caption = 'Digito mayor'
        OnClick = Digitomayor1Click
      end
      object Eliminardigitosimpares1: TMenuItem
        Caption = 'Eliminar digitos impares'
        OnClick = Eliminardigitosimpares1Click
      end
      object digitomayorymenor2: TMenuItem
        Caption = 'digito mayor y menor'
        OnClick = digitomayorymenor2Click
      end
      object CantidaddevocalesdeunString1: TMenuItem
        Caption = 'Cantidad de vocales de un String'
        OnClick = CantidaddevocalesdeunString1Click
      end
      object testeandostrings1: TMenuItem
        Caption = 'testeando strings'
        OnClick = testeandostrings1Click
      end
    end
  end
end
