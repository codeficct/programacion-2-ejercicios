object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Cadenas'
  ClientHeight = 381
  ClientWidth = 724
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = True
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 21
  object Label0: TLabel
    Left = 70
    Top = 95
    Width = 36
    Height = 21
    Caption = 'Input'
  end
  object Label1: TLabel
    Left = 344
    Top = 95
    Width = 82
    Height = 21
    Caption = 'Resultado 1'
  end
  object label2: TLabel
    Left = 344
    Top = 130
    Width = 82
    Height = 21
    Caption = 'Resultado 2'
  end
  object Label3: TLabel
    Left = 70
    Top = 130
    Width = 36
    Height = 21
    Caption = 'Input'
  end
  object Label4: TLabel
    Left = 70
    Top = 165
    Width = 36
    Height = 21
    Caption = 'Input'
  end
  object Input: TEdit
    Left = 120
    Top = 92
    Width = 190
    Height = 29
    TabOrder = 0
  end
  object Result1: TEdit
    Left = 432
    Top = 92
    Width = 222
    Height = 29
    TabOrder = 1
  end
  object Result2: TEdit
    Left = 432
    Top = 127
    Width = 222
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
    Left = 120
    Top = 127
    Width = 190
    Height = 29
    TabOrder = 4
  end
  object StringGrid1: TStringGrid
    Left = 120
    Top = 214
    Width = 534
    Height = 43
    DefaultColWidth = 40
    DefaultRowHeight = 35
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goFixedRowDefAlign]
    ScrollBars = ssHorizontal
    TabOrder = 5
  end
  object Input3: TEdit
    Left = 120
    Top = 162
    Width = 190
    Height = 29
    TabOrder = 6
  end
  object MainMenu1: TMainMenu
    object Menu1: TMenuItem
      Caption = 'Numeros'
      object Potenciadeunnumero1: TMenuItem
        Caption = 'Potencia de un numero'
        OnClick = Potenciadeunnumero1Click
      end
      object Sumar1: TMenuItem
        Caption = 'Sumar digitos'
        OnClick = Sumar1Click
      end
      object SumarPrimos1: TMenuItem
        Caption = 'Sumar Primos'
        OnClick = SumarPrimos1Click
      end
      object Digitomayor1: TMenuItem
        Caption = 'Digito mayor'
        OnClick = Digitomayor1Click
      end
      object Eliminardigitosimpares1: TMenuItem
        Caption = 'Eliminar digitos impares'
        OnClick = Eliminardigitosimpares1Click
      end
      object Moverdigitomayoralfinal1: TMenuItem
        Caption = 'Mover digito mayor al final'
        OnClick = Moverdigitomayoralfinal1Click
      end
      object OrdenarDigitos1: TMenuItem
        Caption = 'Ordenar Digitos'
        OnClick = OrdenarDigitos1Click
      end
      object VerificarsiestaOrdenado1: TMenuItem
        Caption = 'Verificar si esta Ordenado'
        OnClick = VerificarsiestaOrdenado1Click
      end
      object digitomayorymenor2: TMenuItem
        Caption = 'digito mayor y menor'
        OnClick = digitomayorymenor2Click
      end
    end
    object Menu21: TMenuItem
      Caption = 'Cadenas'
      object ContarLetras1: TMenuItem
        Caption = 'Contar Letras'
        OnClick = ContarLetras1Click
      end
      object CantidaddevocalesdeunString1: TMenuItem
        Caption = 'Cantidad de vocales de un String'
        OnClick = CantidaddevocalesdeunString1Click
      end
      object Devuelvesolonumeros1: TMenuItem
        Caption = 'Devuelve solo numeros'
        OnClick = Devuelvesolonumeros1Click
      end
      object Eliminarpalabrasqueserepitansuvocal1: TMenuItem
        Caption = 'Eliminar palabras que se repitan su vocal'
        OnClick = Eliminarpalabrasqueserepitansuvocal1Click
      end
      object Elimnarletrasnoalfabeticas1: TMenuItem
        Caption = 'Elimnar letras no alfabeticas'
        OnClick = Elimnarletrasnoalfabeticas1Click
      end
      object Inverso1: TMenuItem
        Caption = 'Inverso'
        OnClick = Inverso1Click
      end
      object est1: TMenuItem
        Caption = 'Test'
        OnClick = est1Click
      end
      object testeandostrings1: TMenuItem
        Caption = 'testeando strings'
        OnClick = testeandostrings1Click
      end
    end
    object vector1: TMenuItem
      Caption = 'vector'
      object vector2: TMenuItem
        Caption = 'tama'#241'o del vector'
        OnClick = vector2Click
      end
      object SumarElementos1: TMenuItem
        Caption = 'Sumar Elementos'
        OnClick = SumarElementos1Click
      end
      object SumarElementoskn1menoselprimero1: TMenuItem
        Caption = 'Sumar Elementos (k=n-1 menos el primero)'
        OnClick = SumarElementoskn1menoselprimero1Click
      end
      object Sumarkn2derechacorto1: TMenuItem
        Caption = 'Sumar (k=n/2) derecha corto'
        OnClick = Sumarkn2derechacorto1Click
      end
      object Busquedabinaria1: TMenuItem
        Caption = 'Busqueda binaria'
        OnClick = Busquedabinaria1Click
      end
      object BubbleSort1: TMenuItem
        Caption = 'Bubble Sort'
        OnClick = BubbleSort1Click
      end
    end
  end
end
