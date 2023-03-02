object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 256
  ClientWidth = 550
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  TextHeight = 21
  object Edit1: TEdit
    Left = 136
    Top = 61
    Width = 273
    Height = 29
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 136
    Top = 107
    Width = 273
    Height = 29
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 136
    Top = 153
    Width = 273
    Height = 29
    TabOrder = 2
  end
  object MainMenu1: TMainMenu
    object Menu1: TMenuItem
      Caption = 'Menu'
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
