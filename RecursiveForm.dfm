object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Formulario de Recursion'
  ClientHeight = 459
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
  OnMouseDown = FormMouseDown
  PixelsPerInch = 96
  TextHeight = 21
  object Label0: TLabel
    Left = 67
    Top = 112
    Width = 49
    Height = 21
    Caption = 'Input 1'
  end
  object Label1: TLabel
    Left = 346
    Top = 112
    Width = 82
    Height = 21
    Caption = 'Resultado 1'
  end
  object label2: TLabel
    Left = 346
    Top = 147
    Width = 82
    Height = 21
    Caption = 'Resultado 2'
  end
  object Label3: TLabel
    Left = 67
    Top = 147
    Width = 49
    Height = 21
    Caption = 'Input 2'
  end
  object Label4: TLabel
    Left = 67
    Top = 182
    Width = 49
    Height = 21
    Caption = 'Input 3'
  end
  object Input: TEdit
    Left = 122
    Top = 109
    Width = 190
    Height = 29
    TabOrder = 0
  end
  object Result1: TEdit
    Left = 434
    Top = 109
    Width = 222
    Height = 29
    TabOrder = 1
  end
  object Result2: TEdit
    Left = 434
    Top = 144
    Width = 222
    Height = 29
    TabOrder = 2
  end
  object Button1: TButton
    Left = 122
    Top = 65
    Width = 75
    Height = 25
    Caption = 'Recursivo'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Input2: TEdit
    Left = 122
    Top = 144
    Width = 190
    Height = 29
    TabOrder = 4
  end
  object StringGrid1: TStringGrid
    Left = 122
    Top = 231
    Width = 534
    Height = 163
    DefaultColWidth = 30
    DefaultRowHeight = 30
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goFixedRowDefAlign]
    ScrollBars = ssHorizontal
    TabOrder = 5
  end
  object Input3: TEdit
    Left = 122
    Top = 179
    Width = 190
    Height = 29
    TabOrder = 6
  end
  object Button2: TButton
    Left = 203
    Top = 65
    Width = 109
    Height = 25
    Caption = 'Matriz (size)'
    TabOrder = 7
    OnClick = Button2Click
  end
  object RadioButton1: TRadioButton
    Left = 584
    Top = 16
    Width = 113
    Height = 17
    Caption = 'Circulito'
    TabOrder = 8
  end
  object RadioButton2: TRadioButton
    Left = 584
    Top = 39
    Width = 113
    Height = 17
    Caption = 'Pintar'
    TabOrder = 9
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
    object Matriz1: TMenuItem
      Caption = 'Matriz'
      object Matriz2: TMenuItem
        Caption = 'Cargar por filas'
        OnClick = Matriz2Click
      end
      object Cargarporcolumnas1: TMenuItem
        Caption = 'Cargar por columnas'
        OnClick = Cargarporcolumnas1Click
      end
      object CargarporFilasyColumnas1: TMenuItem
        Caption = 'Cargar por Filas y Columnas'
        OnClick = CargarporFilasyColumnas1Click
      end
      object Cargarporcantidaddecasillas1: TMenuItem
        Caption = 'Cargar por cantidad de casillas'
        OnClick = Cargarporcantidaddecasillas1Click
      end
      object Cargarporvibora1: TMenuItem
        Caption = 'Cargar por  vibora'
        OnClick = Cargarporvibora1Click
      end
      object Cargarexpansion1: TMenuItem
        Caption = 'Cargar (expansion)'
        OnClick = Cargarexpansion1Click
      end
      object Cargarconalgoritmodevector1: TMenuItem
        Caption = 'Cargar con algoritmo de vector'
        OnClick = Cargarconalgoritmodevector1Click
      end
      object Frecuenciadeunnumero1: TMenuItem
        Caption = 'Frecuencia de un numero'
        OnClick = Frecuenciadeunnumero1Click
      end
      object Busquedabinaria2: TMenuItem
        Caption = 'Busqueda binaria'
        OnClick = Busquedabinaria2Click
      end
    end
  end
end
