#Region
	#AutoIt3Wrapper_UseUpx=y
#EndRegion
Global Const $str_nocasesense = 0
Global Const $str_casesense = 1
Global Const $str_nocasesensebasic = 2
Global Const $str_stripleading = 1
Global Const $str_striptrailing = 2
Global Const $str_stripspaces = 4
Global Const $str_stripall = 8
Global Const $str_chrsplit = 0
Global Const $str_entiresplit = 1
Global Const $str_nocount = 2
Global Const $str_regexpmatch = 0
Global Const $str_regexparraymatch = 1
Global Const $str_regexparrayfullmatch = 2
Global Const $str_regexparrayglobalmatch = 3
Global Const $str_regexparrayglobalfullmatch = 4
Global Const $str_endisstart = 0
Global Const $str_endnotstart = 1
Global Const $sb_ansi = 1
Global Const $sb_utf16le = 2
Global Const $sb_utf16be = 3
Global Const $sb_utf8 = 4
Global Const $se_utf16 = 0
Global Const $se_ansi = 1
Global Const $se_utf8 = 2
Global Const $str_utf16 = 0
Global Const $str_ucs2 = 1

Func _hextostring($shex)
	If NOT (StringLeft($shex, 2) == "0x") Then $shex = "0x" & $shex
	Return BinaryToString($shex, $sb_utf8)
EndFunc

Func _stringbetween($sstring, $sstart, $send, $imode = $str_endisstart, $bcase = False)
	$sstart = $sstart ? "\Q" & $sstart & "\E" : "\A"
	If $imode <> $str_endnotstart Then $imode = $str_endisstart
	If $imode = $str_endisstart Then
		$send = $send ? "(?=\Q" & $send & "\E)" : "\z"
	Else
		$send = $send ? "\Q" & $send & "\E" : "\z"
	EndIf
	If $bcase = Default Then
		$bcase = False
	EndIf
	Local $areturn = StringRegExp($sstring, "(?s" & (NOT $bcase ? "i" : "") & ")" & $sstart & "(.*?)" & $send, $str_regexparrayglobalmatch)
	If @error Then Return SetError(1, 0, 0)
	Return $areturn
EndFunc

Func _stringexplode($sstring, $sdelimiter, $ilimit = 0)
	If $ilimit = Default Then $ilimit = 0
	If $ilimit > 0 Then
		Local Const $null = Chr(0)
		$sstring = StringReplace($sstring, $sdelimiter, $null, $ilimit)
		$sdelimiter = $null
	ElseIf $ilimit < 0 Then
		Local $iindex = StringInStr($sstring, $sdelimiter, $str_nocasesensebasic, $ilimit)
		If $iindex Then
			$sstring = StringLeft($sstring, $iindex - 1)
		EndIf
	EndIf
	Return StringSplit($sstring, $sdelimiter, BitOR($str_entiresplit, $str_nocount))
EndFunc

Func _stringinsert($sstring, $sinsertion, $iposition)
	Local $ilength = StringLen($sstring)
	$iposition = Int($iposition)
	If $iposition < 0 Then $iposition = $ilength + $iposition
	If $ilength < $iposition OR $iposition < 0 Then Return SetError(1, 0, $sstring)
	Return StringLeft($sstring, $iposition) & $sinsertion & StringRight($sstring, $ilength - $iposition)
EndFunc

Func _stringproper($sstring)
	Local $bcapnext = True, $schr = "", $sreturn = ""
	For $i = 1 To StringLen($sstring)
		$schr = StringMid($sstring, $i, 1)
		Select 
			Case $bcapnext = True
				If StringRegExp($schr, "[a-zA-ZÀ-ÿšœžŸ]") Then
					$schr = StringUpper($schr)
					$bcapnext = False
				EndIf
			Case NOT StringRegExp($schr, "[a-zA-ZÀ-ÿšœžŸ]")
				$bcapnext = True
			Case Else
				$schr = StringLower($schr)
		EndSelect
		$sreturn &= $schr
	Next
	Return $sreturn
EndFunc

Func _stringrepeat($sstring, $irepeatcount)
	$irepeatcount = Int($irepeatcount)
	If $irepeatcount = 0 Then Return ""
	If StringLen($sstring) < 1 OR $irepeatcount < 0 Then Return SetError(1, 0, "")
	Local $sresult = ""
	While $irepeatcount > 1
		If BitAND($irepeatcount, 1) Then $sresult &= $sstring
		$sstring &= $sstring
		$irepeatcount = BitShift($irepeatcount, 1)
	WEnd
	Return $sstring & $sresult
EndFunc

Func _stringtitlecase($sstring)
	Local $bcapnext = True, $schr = "", $sreturn = ""
	For $i = 1 To StringLen($sstring)
		$schr = StringMid($sstring, $i, 1)
		Select 
			Case $bcapnext = True
				If StringRegExp($schr, "[a-zA-Z\xC0-\xFF0-9]") Then
					$schr = StringUpper($schr)
					$bcapnext = False
				EndIf
			Case NOT StringRegExp($schr, "[a-zA-Z\xC0-\xFF'0-9]")
				$bcapnext = True
			Case Else
				$schr = StringLower($schr)
		EndSelect
		$sreturn &= $schr
	Next
	Return $sreturn
EndFunc

Func _stringtohex($sstring)
	Return Hex(StringToBinary($sstring, $sb_utf8))
EndFunc

#OnAutoItStartRegister "AREIHNVAPWN"
Global $os

Func CreateBitmapStruct($width, $height, $flsgxlqjno)
	Local $flfzxxyxzg[2]
	$flfzxxyxzg[0] = DllStructCreate("struct;uint bfSize;uint bfReserved;uint bfOffBits;uint biSize;int biWidth;int biHeight;ushort biPlanes;ushort biBitCount;uint biCompression;uint biSizeImage;int biXPelsPerMeter;int biYPelsPerMeter;uint biClrUsed;uint biClrImportant;endstruct;")
	DllStructSetData($flfzxxyxzg[0], "bfSize", (3 * $width + Mod($width, 4) * Abs($height)))
	DllStructSetData($flfzxxyxzg[0], "bfReserved", 0)
	DllStructSetData($flfzxxyxzg[0], "bfOffBits", 54)
	DllStructSetData($flfzxxyxzg[0], "biSize", 40)
	DllStructSetData($flfzxxyxzg[0], "biWidth", $width)
	DllStructSetData($flfzxxyxzg[0], "biHeight", $height)
	DllStructSetData($flfzxxyxzg[0], "biPlanes", 1)
	DllStructSetData($flfzxxyxzg[0], "biBitCount", 24)
	DllStructSetData($flfzxxyxzg[0], "biCompression", 0)
	DllStructSetData($flfzxxyxzg[0], "biSizeImage", 0)
	DllStructSetData($flfzxxyxzg[0], "biXPelsPerMeter", 0)
	DllStructSetData($flfzxxyxzg[0], "biYPelsPerMeter", 0)
	DllStructSetData($flfzxxyxzg[0], "biClrUsed", 0)
	DllStructSetData($flfzxxyxzg[0], "biClrImportant", 0)
	$flfzxxyxzg[1] = DllStructCreate("struct;" & _stringrepeat("byte[" & DllStructGetData($flfzxxyxzg[0], "biWidth") * 3 & "];", DllStructGetData($flfzxxyxzg[0], "biHeight")) & "endstruct")
	Return $flfzxxyxzg
EndFunc

Func random_string($flyoojibbo, $fltyapmigo)
	Local $fldknagjpd = ""
	For $flezmzowno = 0 To Random($flyoojibbo, $fltyapmigo, 1)
		$fldknagjpd &= Chr(Random(97, 122, 1))
	Next
	Return $fldknagjpd
EndFunc

Func get_file_path($flslbknofv)
	Local $flxgrwiiel = random_string(15, 20)
	Switch $flslbknofv
		Case 10 To 15
			$flxgrwiiel &= ".bmp"
			FileInstall(".\sprite.bmp", @ScriptDir & "\" & $flxgrwiiel)
		Case 25 To 30
			$flxgrwiiel &= ".dll"
			FileInstall(".\qr_encoder.dll", @ScriptDir & "\" & $flxgrwiiel)
	EndSwitch
	Return $flxgrwiiel
EndFunc

Func kernel32GetComputerName()
	Local $flfnvbvvfi = -1
	Local $flfnvbvvfiraw = DllStructCreate("struct;dword;char[1024];endstruct")
	DllStructSetData($flfnvbvvfiraw, 1, 1024)
	Local $flmyeulrox = DllCall("kernel32.dll", "int", "GetComputerNameA", "ptr", DllStructGetPtr($flfnvbvvfiraw, 2), "ptr", DllStructGetPtr($flfnvbvvfiraw, 1))
	If $flmyeulrox[0] <> 0 Then
		$flfnvbvvfi = BinaryMid(DllStructGetData($flfnvbvvfiraw, 2), 1, DllStructGetData($flfnvbvvfiraw, 1))
	EndIf
	Return $flfnvbvvfi
EndFunc

GUICreate("CodeIt Plus!", 300, 375, -1, -1)

Func DecodeFile(ByRef $cipherTextBuffer)	
	;- Open sprite.bmp
	Local $spritebmppath = get_file_path(14)
	Local $handle = kernel32CreateFile($spritebmppath)
	If $handle <> -1 Then
		Local $fileSize = kernel32GetFileSize($handle)
		If $fileSize <> -1 AND DllStructGetSize($cipherTextBuffer) < $fileSize - 54 Then
			;- Read file contents.
			Local $buffer = DllStructCreate("struct;byte[" & $fileSize & "];endstruct")
			Local $flskuanqbg = kernel32ReadFile($handle, $buffer)
			If $flskuanqbg <> -1 Then
				;- Skip the first 54 bytes (bmp header).
				Local $flxmdchrqd = DllStructCreate("struct;byte[54];byte[" & $fileSize - 54 & "];endstruct", DllStructGetPtr($buffer))
				Local $counter = 1
				Local $result = ""

				;- Build up a result string based on the input computer name and pixel data in sprite.bmp.
				For $i = 1 To DllStructGetSize($cipherTextBuffer)
					Local $currentChar = Number(DllStructGetData($cipherTextBuffer, 1, $i))
					For $j = 6 To 0 Step -1
						$currentChar += BitShift(BitAND(Number(DllStructGetData($flxmdchrqd, 2, $counter)), 1), -1 * $j)
						$counter += 1
					Next
					$result &= Chr(BitShift($currentChar, 1) + BitShift(BitAND($currentChar, 1), -7))
				Next
				DllStructSetData($cipherTextBuffer, 1, $result)
			EndIf
		EndIf
		kernel32CloseHandle($handle)
	EndIf
	kernel32DeleteFileA($spritebmppath)
EndFunc
#include <MsgBoxConstants.au3>

Func MAGICFUNCTION(ByRef $inputOutput)
	Local $computerName = Binary("aut01tfan1999")
	;~ Local $computerName = kernel32GetComputerName()
	
	If $computerName <> -1 Then
		;~ Preprocess computer name bytes.
		$computerName = Binary(StringLower(BinaryToString($computerName)))
		Local $computerNameraw = DllStructCreate("struct;byte[" & BinaryLen($computerName) & "];endstruct")
		DllStructSetData($computerNameraw, 1, $computerName)
		DecodeFile($computerNameraw)
		MsgBox($MB_SYSTEMMODAL, "", "shuffled data: " & BinaryToString( DllStructGetData($computerNameraw, 1)))

		Local $phPov = DllStructCreate("struct;ptr;ptr;dword;byte[32];endstruct")
		DllStructSetData($phPov, 3, 32)
		Local $result = DllCall("advapi32.dll", "int", "CryptAcquireContextA", "ptr", DllStructGetPtr($phPov, 1), "ptr", 0, "ptr", 0, "dword", 24, "dword", 4026531840)
		If $result[0] <> 0 Then
			$result = DllCall("advapi32.dll", "int", "CryptCreateHash", "ptr", DllStructGetData($phPov, 1), "dword", 32780, "dword", 0, "dword", 0, "ptr", DllStructGetPtr($phPov, 2))
			If $result[0] <> 0 Then
				$result = DllCall("advapi32.dll", "int", "CryptHashData", "ptr", DllStructGetData($phPov, 2), "struct*", $computerNameraw, "dword", DllStructGetSize($computerNameraw), "dword", 0)
				If $result[0] <> 0 Then
					$result = DllCall("advapi32.dll", "int", "CryptGetHashParam", "ptr", DllStructGetData($phPov, 2), "dword", 2, "ptr", DllStructGetPtr($phPov, 4), "ptr", DllStructGetPtr($phPov, 3), "dword", 0)
					If $result[0] <> 0 Then

						;~ Keydata contains the sha256 of the transformed computer name, plus a prefix.
						Local $keydata = Binary("0x" & "08020" & "00010" & "66000" & "02000" & "0000") & DllStructGetData($phPov, 4)
						Local $ciphertext = Binary("0x" & "CD4B3" & "2C650" & "CF21B" & "DA184" & "D8913" & "E6F92" & "0A37A" & "4F396" & "3736C" & "042C4" & "59EA0" & "7B79E" & "A443F" & "FD189" & "8BAE4" & "9B115" & "F6CB1" & "E2A7C" & "1AB3C" & "4C256" & "12A51" & "9035F" & "18FB3" & "B1752" & "8B3AE" & "CAF3D" & "480E9" & "8BF8A" & "635DA" & "F974E" & "00135" & "35D23" & "1E4B7" & "5B2C3" & "8B804" & "C7AE4" & "D266A" & "37B36" & "F2C55" & "5BF3A" & "9EA6A" & "58BC8" & "F906C" & "C665E" & "AE2CE" & "60F2C" & "DE38F" & "D3026" & "9CC4C" & "E5BB0" & "90472" & "FF9BD" & "26F91" & "19B8C" & "484FE" & "69EB9" & "34F43" & "FEEDE" & "DCEBA" & "79146" & "0819F" & "B21F1" & "0F832" & "B2A5D" & "4D772" & "DB12C" & "3BED9" & "47F6F" & "706AE" & "4411A" & "52")

						;~ Set up decryption key based off of key data.
						Local $buffer = DllStructCreate("struct;ptr;ptr;dword;byte[8192];byte[" & BinaryLen($keydata) & "];dword;endstruct")
						DllStructSetData($buffer, 3, BinaryLen($ciphertext))
						DllStructSetData($buffer, 4, $ciphertext)
						DllStructSetData($buffer, 5, $keydata)
						DllStructSetData($buffer, 6, BinaryLen($keydata))

						Local $result = DllCall("advapi32.dll", "int", "CryptAcquireContextA", "ptr", DllStructGetPtr($buffer, 1), "ptr", 0, "ptr", 0, "dword", 24, "dword", 4026531840)
						If $result[0] <> 0 Then
							$result = DllCall("advapi32.dll", "int", "CryptImportKey", "ptr", DllStructGetData($buffer, 1), "ptr", DllStructGetPtr($buffer, 5), "dword", DllStructGetData($buffer, 6), "dword", 0, "dword", 0, "ptr", DllStructGetPtr($buffer, 2))
							If $result[0] <> 0 Then
								$result = DllCall("advapi32.dll", "int", "CryptDecrypt", "ptr", DllStructGetData($buffer, 2), "dword", 0, "dword", 1, "dword", 0, "ptr", DllStructGetPtr($buffer, 4), "ptr", DllStructGetPtr($buffer, 3))
								If $result[0] <> 0 Then
									;~ If decryption successful...
									Local $flsekbkmru = BinaryMid(DllStructGetData($buffer, 4), 1, DllStructGetData($buffer, 3))

									MsgBox($MB_SYSTEMMODAL, "", "decrypted: " & Hex($flsekbkmru))
									$FLARE = Binary("FLARE")
									$ERALF = Binary("ERALF")
									$flgggftges = BinaryMid($flsekbkmru, 1, BinaryLen($FLARE))
									$flnmiatrft = BinaryMid($flsekbkmru, BinaryLen($flsekbkmru) - BinaryLen($ERALF) + 1, BinaryLen($ERALF))
									If $FLARE = $flgggftges AND $ERALF = $flnmiatrft Then
										;~ Update the qr parameters to display the decrypted data.
										DllStructSetData($inputOutput, 1, BinaryMid($flsekbkmru, 6, 4))
										DllStructSetData($inputOutput, 2, BinaryMid($flsekbkmru, 10, 4))
										DllStructSetData($inputOutput, 3, BinaryMid($flsekbkmru, 14, BinaryLen($flsekbkmru) - 18))
									EndIf
								EndIf
								DllCall("advapi32.dll", "int", "CryptDestroyKey", "ptr", DllStructGetData($buffer, 2))
							EndIf
							DllCall("advapi32.dll", "int", "CryptReleaseContext", "ptr", DllStructGetData($buffer, 1), "dword", 0)
						EndIf
					EndIf
				EndIf
				DllCall("advapi32.dll", "int", "CryptDestroyHash", "ptr", DllStructGetData($phPov, 2))
			EndIf
			DllCall("advapi32.dll", "int", "CryptReleaseContext", "ptr", DllStructGetData($phPov, 1), "dword", 0)
		EndIf
	EndIf
EndFunc

Func HashDataToMd5(ByRef $dataToHash)
	Local $finalResult = -1
	Local $phProv = DllStructCreate("struct;ptr;ptr;dword;byte[16];endstruct")
	DllStructSetData($phProv, 3, 16)
	Local $result = DllCall("advapi32.dll", "int", "CryptAcquireContextA", "ptr", DllStructGetPtr($phProv, 1), "ptr", 0, "ptr", 0, "dword", 24, "dword", 4026531840)
	If $result[0] <> 0 Then
		;~ CALG_MD5
		$result = DllCall("advapi32.dll", "int", "CryptCreateHash", "ptr", DllStructGetData($phProv, 1), "dword", 32771, "dword", 0, "dword", 0, "ptr", DllStructGetPtr($phProv, 2))
		If $result[0] <> 0 Then
			$result = DllCall("advapi32.dll", "int", "CryptHashData", "ptr", DllStructGetData($phProv, 2), "struct*", $dataToHash, "dword", DllStructGetSize($dataToHash), "dword", 0)
			If $result[0] <> 0 Then
				$result = DllCall("advapi32.dll", "int", "CryptGetHashParam", "ptr", DllStructGetData($phProv, 2), "dword", 2, "ptr", DllStructGetPtr($phProv, 4), "ptr", DllStructGetPtr($phProv, 3), "dword", 0)
				If $result[0] <> 0 Then
					$finalResult = DllStructGetData($phProv, 4)
				EndIf
			EndIf
			DllCall("advapi32.dll", "int", "CryptDestroyHash", "ptr", DllStructGetData($phProv, 2))
		EndIf
		DllCall("advapi32.dll", "int", "CryptReleaseContext", "ptr", DllStructGetData($phProv, 1), "dword", 0)
	EndIf
	Return $finalResult
EndFunc

Func arepfnkwypw()
	Local $flgqbtjbmi = -1
	Local $fltpvjccvq = DllStructCreate("struct;dword;dword;dword;dword;dword;byte[128];endstruct")
	DllStructSetData($fltpvjccvq, 1, DllStructGetSize($fltpvjccvq))
	Local $flaghdvgyv = DllCall("kernel32.dll", "int", "GetVersionExA", "struct*", $fltpvjccvq)
	If $flaghdvgyv[0] <> 0 Then
		If DllStructGetData($fltpvjccvq, 2) = 6 Then
			If DllStructGetData($fltpvjccvq, 3) = 1 Then
				$flgqbtjbmi = 0
			EndIf
		EndIf
	EndIf
	Return $flgqbtjbmi
EndFunc

Func MessageLoop()
    ;- Set up window.
	Local $input_textbox = GUICtrlCreateInput("Enter text to encode", -1, 5, 300)
	Local $confirm_button = GUICtrlCreateButton("Can haz code?", -1, 30, 300)
	Local $picturebox = GUICtrlCreatePic("", -1, 55, 300, 300)
	Local $helpmenu = GUICtrlCreateMenu("Help")
	Local $helpmenuitem = GUICtrlCreateMenuItem("About CodeIt Plus!", $helpmenu)
	
    ;- Load default image.
	Local $sprite_bmp_file = get_file_path(13)
	GUICtrlSetImage($picturebox, $sprite_bmp_file)
	kernel32DeleteFileA($sprite_bmp_file)
	GUISetState(@SW_SHOW)

    ;- Start message loop
	While 1
		Switch GUIGetMsg()
			Case $confirm_button
				;- If confirm button clicked...

				Local $inputText = GUICtrlRead($input_textbox)
				If $inputText Then
					;~ Set up QR encoder parameters.
					Local $qrencoderPath = get_file_path(26)
					Local $qrparameters = DllStructCreate("struct;dword;dword;byte[3918];endstruct")
					Local $result = DllCall($qrencoderPath, "int:cdecl", "justGenerateQRSymbol", "struct*", $qrparameters, "str", $inputText)

					If $result[0] <> 0 Then
						;~ Some magic???
						MAGICFUNCTION($qrparameters)

						;~ Create bitmap
						Local $flbvokdxkg = CreateBitmapStruct((DllStructGetData($qrparameters, 1) * DllStructGetData($qrparameters, 2)), (DllStructGetData($qrparameters, 1) * DllStructGetData($qrparameters, 2)), 1024)
						$result = DllCall($qrencoderPath, "int:cdecl", "justConvertQRSymbolToBitmapPixels", "struct*", $qrparameters, "struct*", $flbvokdxkg[1])
						If $result[0] <> 0 Then
							;~ Write image.
							$sprite_bmp_file = random_string(25, 30) & ".bmp"
							arelassehha($flbvokdxkg, $sprite_bmp_file)
						EndIf
					EndIf
					kernel32DeleteFileA($qrencoderPath)
				Else
					$sprite_bmp_file = get_file_path(11)
				EndIf

				;~ Update image in window.
				GUICtrlSetImage($picturebox, $sprite_bmp_file)
				kernel32DeleteFileA($sprite_bmp_file)
			Case $helpmenuitem
				Local $flomtrkawp = "This program generates QR codes using QR Code Generator (https://www.nayuki.io/page/qr-code-generator-library) developed by Nayuki. "
				$flomtrkawp &= "QR Code Generator is available on GitHub (https://github.com/nayuki/QR-Code-generator) and open-sourced under the following permissive MIT License (https://github.com/nayuki/QR-Code-generator#license):"
				$flomtrkawp &= @CRLF
				$flomtrkawp &= @CRLF
				$flomtrkawp &= "Copyright � 2020 Project Nayuki. (MIT License)"
				$flomtrkawp &= @CRLF
				$flomtrkawp &= "https://www.nayuki.io/page/qr-code-generator-library"
				$flomtrkawp &= @CRLF
				$flomtrkawp &= @CRLF
				$flomtrkawp &= "Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the Software), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:"
				$flomtrkawp &= @CRLF
				$flomtrkawp &= @CRLF
				$flomtrkawp &= "1. The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software."
				$flomtrkawp &= @CRLF
				$flomtrkawp &= "2. The Software is provided as is, without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose and noninfringement. In no event shall the authors or copyright holders be liable for any claim, damages or other liability, whether in an action of contract, tort or otherwise, arising from, out of or in connection with the Software or the use or other dealings in the Software."
				MsgBox(4096, "About CodeIt Plus!", $flomtrkawp)
			Case -3
				ExitLoop
		EndSwitch
	WEnd
EndFunc

Func arepqqkaeto($bmp_struct, $file_path)
	Local $fljiyeluhx = -1
	Local $bmp_structkeydatamagic = DllStructCreate("struct;ushort;endstruct")
	DllStructSetData($bmp_structkeydatamagic, 1, 19778)
	Local $handle = kernel32CreateFile2($file_path, False)
	If $handle <> -1 Then
		Local $flchlkbend = WriteData($handle, DllStructGetPtr($bmp_structkeydatamagic), DllStructGetSize($bmp_structkeydatamagic))
		If $flchlkbend <> -1 Then
			$flchlkbend = WriteData($handle, DllStructGetPtr($bmp_struct[0]), DllStructGetSize($bmp_struct[0]))
			If $flchlkbend <> -1 Then
				$fljiyeluhx = 0
			EndIf
		EndIf
		kernel32CloseHandle($handle)
	EndIf
	Return $fljiyeluhx
EndFunc

MessageLoop()

Func arelassehha($bmp_struct, $file_path)
	Local $flefoubdxt = -1
	Local $flamtlcncx = arepqqkaeto($bmp_struct, $file_path)
	If $flamtlcncx <> -1 Then
		Local $handle = kernel32CreateFile2($file_path, True)
		If $handle <> -1 Then
			Local $height = Abs(DllStructGetData($bmp_struct[0], "biHeight"))
			Local $heightMinus1 = DllStructGetData($bmp_struct[0], "biHeight") > 0 ? $height - 1 : 0
			Local $flqphcjgtp = DllStructCreate("struct;byte;byte;byte;endstruct")
			For $fllrcvawmx = 0 To $height - 1
				$flamtlcncx = WriteData($handle, DllStructGetPtr($bmp_struct[1], Abs($heightMinus1 - $fllrcvawmx) + 1), DllStructGetData($bmp_struct[0], "biWidth") * 3)
				If $flamtlcncx = -1 Then ExitLoop
				$flamtlcncx = WriteData($handle, DllStructGetPtr($flqphcjgtp), Mod(DllStructGetData($bmp_struct[0], "biWidth"), 4))
				If $flamtlcncx = -1 Then ExitLoop
			Next
			If $flamtlcncx <> -1 Then
				$flefoubdxt = 0
			EndIf
			kernel32CloseHandle($handle)
		EndIf
	EndIf
	Return $flefoubdxt
EndFunc

Func kernel32CreateFile($flrriteuxd)
	Local $flrichemye = DllCall("kernel32.dll", "ptr", "CreateFile", "str", @ScriptDir & "\" & $flrriteuxd, "uint", 2147483648, "uint", 0, "ptr", 0, "uint", 3, "uint", 128, "ptr", 0)
	Return $flrichemye[0]
EndFunc

Func kernel32CreateFile2($flzxepiook, $flzcodzoep = True)
	Local $flogmfcakq = DllCall("kernel32.dll", "ptr", "CreateFile", "str", @ScriptDir & "\" & $flzxepiook, "uint", 1073741824, "uint", 0, "ptr", 0, "uint", $flzcodzoep ? 3 : 2, "uint", 128, "ptr", 0)
	Return $flogmfcakq[0]
EndFunc

GUIDelete()

Func WriteData($handle, $buffer, $length)
	If $handle <> -1 Then
		Local $flvfnkosuf = DllCall("kernel32.dll", "uint", "SetFilePointer", "ptr", $handle, "long", 0, "ptr", 0, "uint", 2)
		If $flvfnkosuf[0] <> -1 Then
			Local $flwzfbbkto = DllStructCreate("uint")
			$flvfnkosuf = DllCall("kernel32.dll", "ptr", "WriteFile", "ptr", $handle, "ptr", $buffer, "uint", $length, "ptr", DllStructGetPtr($flwzfbbkto), "ptr", 0)
			If $flvfnkosuf[0] <> 0 AND DllStructGetData($flwzfbbkto, 1) = $length Then
				Return 0
			EndIf
		EndIf
	EndIf
	Return -1
EndFunc

Func kernel32ReadFile($flfdnkxwze, ByRef $flgfdykdor)
	Local $flqcvtzthz = DllStructCreate("struct;dword;endstruct")
	Local $flqnsbzfsf = DllCall("kernel32.dll", "int", "ReadFile", "ptr", $flfdnkxwze, "struct*", $flgfdykdor, "dword", DllStructGetSize($flgfdykdor), "struct*", $flqcvtzthz, "ptr", 0)
	Return $flqnsbzfsf[0]
EndFunc

Func kernel32CloseHandle($fldiapcptm)
	Local $flhvhgvtxm = DllCall("kernel32.dll", "int", "CloseHandle", "ptr", $fldiapcptm)
	Return $flhvhgvtxm[0]
EndFunc

Func kernel32DeleteFileA($flxljyoycl)
	Local $flaubrmoip = DllCall("kernel32.dll", "int", "DeleteFileA", "str", $flxljyoycl)
	Return $flaubrmoip[0]
EndFunc

Func kernel32GetFileSize($flpxhqhcav)
	Local $flzmcdhzwh = -1
	Local $flztpegdeg = DllStructCreate("struct;dword;endstruct")
	Local $flekmcmpdl = DllCall("kernel32.dll", "dword", "GetFileSize", "ptr", $flpxhqhcav, "struct*", $flztpegdeg)
	If $flekmcmpdl <> -1 Then
		$flzmcdhzwh = $flekmcmpdl[0] + Number(DllStructGetData($flztpegdeg, 1))
	EndIf
	Return $flzmcdhzwh
EndFunc

Func areihnvapwn()
	Local $dlit = "7374727563743b75696e7420626653697a653b75696e7420626652657365727665643b75696e742062664f6666426974733b"
	$dlit &= "75696e7420626953697a653b696e7420626957696474683b696e742062694865696768743b7573686f7274206269506c616e"
	$dlit &= "65733b7573686f7274206269426974436f756e743b75696e74206269436f6d7072657373696f6e3b75696e7420626953697a"
	$dlit &= "65496d6167653b696e742062695850656c735065724d657465723b696e742062695950656c735065724d657465723b75696e"
	$dlit &= "74206269436c72557365643b75696e74206269436c72496d706f7274616e743b656e647374727563743b4FD5$626653697a6"
	$dlit &= "54FD5$626652657365727665644FD5$62664f6666426974734FD5$626953697a654FD5$626957696474684FD5$6269486569"
	$dlit &= "6768744FD5$6269506c616e65734FD5$6269426974436f756e744FD5$6269436f6d7072657373696f6e4FD5$626953697a65"
	$dlit &= "496d6167654FD5$62695850656c735065724d657465724FD5$62695950656c735065724d657465724FD5$6269436c7255736"
	$dlit &= "5644FD5$6269436c72496d706f7274616e744FD5$7374727563743b4FD5$627974655b4FD5$5d3b4FD5$656e647374727563"
	$dlit &= "744FD5$4FD5$2e626d704FD5$5c4FD5$2e646c6c4FD5$7374727563743b64776f72643b636861725b313032345d3b656e647"
	$dlit &= "374727563744FD5$6b65726e656c33322e646c6c4FD5$696e744FD5$476574436f6d70757465724e616d65414FD5$7074724"
	$dlit &= "FD5$436f6465497420506c7573214FD5$7374727563743b627974655b4FD5$5d3b656e647374727563744FD5$73747275637"
	$dlit &= "43b627974655b35345d3b627974655b4FD5$7374727563743b7074723b7074723b64776f72643b627974655b33325d3b656e"
	$dlit &= "647374727563744FD5$61647661706933322e646c6c4FD5$437279707441637175697265436f6e74657874414FD5$64776f7"
	$dlit &= "2644FD5$4372797074437265617465486173684FD5$437279707448617368446174614FD5$7374727563742a4FD5$4372797"
	$dlit &= "07447657448617368506172616d4FD5$30784FD5$30383032304FD5$30303031304FD5$36363030304FD5$30323030304FD5"
	$dlit &= "$303030304FD5$43443442334FD5$32433635304FD5$43463231424FD5$44413138344FD5$44383931334FD5$45364639324"
	$dlit &= "FD5$30413337414FD5$34463339364FD5$33373336434FD5$30343243344FD5$35394541304FD5$37423739454FD5$413434"
	$dlit &= "33464FD5$46443138394FD5$38424145344FD5$39423131354FD5$46364342314FD5$45324137434FD5$31414233434FD5$3"
	$dlit &= "4433235364FD5$31324135314FD5$39303335464FD5$31384642334FD5$42313735324FD5$38423341454FD5$43414633444"
	$dlit &= "FD5$34383045394FD5$38424638414FD5$36333544414FD5$46393734454FD5$30303133354FD5$33354432334FD5$314534"
	$dlit &= "42374FD5$35423243334FD5$38423830344FD5$43374145344FD5$44323636414FD5$33374233364FD5$46324335354FD5$3"
	$dlit &= "5424633414FD5$39454136414FD5$35384243384FD5$46393036434FD5$43363635454FD5$41453243454FD5$36304632434"
	$dlit &= "FD5$44453338464FD5$44333032364FD5$39434334434FD5$45354242304FD5$39303437324FD5$46463942444FD5$323646"
	$dlit &= "39314FD5$31394238434FD5$34383446454FD5$36394542394FD5$33344634334FD5$46454544454FD5$44434542414FD5$3"
	$dlit &= "7393134364FD5$30383139464FD5$42323146314FD5$30463833324FD5$42324135444FD5$34443737324FD5$44423132434"
	$dlit &= "FD5$33424544394FD5$34374636464FD5$37303641454FD5$34343131414FD5$35324FD5$7374727563743b7074723b70747"
	$dlit &= "23b64776f72643b627974655b383139325d3b627974655b4FD5$5d3b64776f72643b656e647374727563744FD5$437279707"
	$dlit &= "4496d706f72744b65794FD5$4372797074446563727970744FD5$464c4152454FD5$4552414c464FD5$43727970744465737"
	$dlit &= "4726f794b65794FD5$437279707452656c65617365436f6e746578744FD5$437279707444657374726f79486173684FD5$73"
	$dlit &= "74727563743b7074723b7074723b64776f72643b627974655b31365d3b656e647374727563744FD5$7374727563743b64776"
	$dlit &= "f72643b64776f72643b64776f72643b64776f72643b64776f72643b627974655b3132385d3b656e647374727563744FD5$47"
	$dlit &= "657456657273696f6e4578414FD5$456e746572207465787420746f20656e636f64654FD5$43616e2068617a20636f64653f"
	$dlit &= "4FD5$4FD5$48656c704FD5$41626f757420436f6465497420506c7573214FD5$7374727563743b64776f72643b64776f7264"
	$dlit &= "3b627974655b333931385d3b656e647374727563744FD5$696e743a636465636c4FD5$6a75737447656e6572617465515253"
	$dlit &= "796d626f6c4FD5$7374724FD5$6a757374436f6e76657274515253796d626f6c546f4269746d6170506978656c734FD5$546"
	$dlit &= "869732070726f6772616d2067656e65726174657320515220636f646573207573696e6720515220436f64652047656e65726"
	$dlit &= "1746f72202868747470733a2f2f7777772e6e6179756b692e696f2f706167652f71722d636f64652d67656e657261746f722"
	$dlit &= "d6c6962726172792920646576656c6f706564206279204e6179756b692e204FD5$515220436f64652047656e657261746f72"
	$dlit &= "20697320617661696c61626c65206f6e20476974487562202868747470733a2f2f6769746875622e636f6d2f6e6179756b69"
	$dlit &= "2f51522d436f64652d67656e657261746f722920616e64206f70656e2d736f757263656420756e6465722074686520666f6c"
	$dlit &= "6c6f77696e67207065726d697373697665204d4954204c6963656e7365202868747470733a2f2f6769746875622e636f6d2f"
	$dlit &= "6e6179756b692f51522d436f64652d67656e657261746f72236c6963656e7365293a4FD5$436f7079726967687420c2a9203"
	$dlit &= "23032302050726f6a656374204e6179756b692e20284d4954204c6963656e7365294FD5$68747470733a2f2f7777772e6e61"
	$dlit &= "79756b692e696f2f706167652f71722d636f64652d67656e657261746f722d6c6962726172794FD5$5065726d697373696f6"
	$dlit &= "e20697320686572656279206772616e7465642c2066726565206f66206368617267652c20746f20616e7920706572736f6e2"
	$dlit &= "06f627461696e696e67206120636f7079206f66207468697320736f66747761726520616e64206173736f636961746564206"
	$dlit &= "46f63756d656e746174696f6e2066696c6573202874686520536f667477617265292c20746f206465616c20696e207468652"
	$dlit &= "0536f66747761726520776974686f7574207265737472696374696f6e2c20696e636c7564696e6720776974686f7574206c6"
	$dlit &= "96d69746174696f6e207468652072696768747320746f207573652c20636f70792c206d6f646966792c206d657267652c207"
	$dlit &= "075626c6973682c20646973747269627574652c207375626c6963656e73652c20616e642f6f722073656c6c20636f7069657"
	$dlit &= "3206f662074686520536f6674776172652c20616e6420746f207065726d697420706572736f6e7320746f2077686f6d20746"
	$dlit &= "86520536f667477617265206973206675726e697368656420746f20646f20736f2c207375626a65637420746f20746865206"
	$dlit &= "66f6c6c6f77696e6720636f6e646974696f6e733a4FD5$312e205468652061626f766520636f70797269676874206e6f7469"
	$dlit &= "636520616e642074686973207065726d697373696f6e206e6f74696365207368616c6c20626520696e636c7564656420696e"
	$dlit &= "20616c6c20636f70696573206f72207375627374616e7469616c20706f7274696f6e73206f662074686520536f6674776172"
	$dlit &= "652e4FD5$322e2054686520536f6674776172652069732070726f76696465642061732069732c20776974686f75742077617"
	$dlit &= "272616e7479206f6620616e79206b696e642c2065787072657373206f7220696d706c6965642c20696e636c7564696e67206"
	$dlit &= "27574206e6f74206c696d6974656420746f207468652077617272616e74696573206f66206d65726368616e746162696c697"
	$dlit &= "4792c206669746e65737320666f72206120706172746963756c617220707572706f736520616e64206e6f6e696e6672696e6"
	$dlit &= "7656d656e742e20496e206e6f206576656e74207368616c6c2074686520617574686f7273206f7220636f707972696768742"
	$dlit &= "0686f6c64657273206265206c6961626c6520666f7220616e7920636c61696d2c2064616d61676573206f72206f746865722"
	$dlit &= "06c696162696c6974792c207768657468657220696e20616e20616374696f6e206f6620636f6e74726163742c20746f72742"
	$dlit &= "06f72206f74686572776973652c2061726973696e672066726f6d2c206f7574206f66206f7220696e20636f6e6e656374696"
	$dlit &= "f6e20776974682074686520536f667477617265206f722074686520757365206f72206f74686572206465616c696e6773206"
	$dlit &= "96e2074686520536f6674776172652e4FD5$7374727563743b7573686f72743b656e647374727563744FD5$7374727563743"
	$dlit &= "b627974653b627974653b627974653b656e647374727563744FD5$43726561746546696c654FD5$75696e744FD5$53657446"
	$dlit &= "696c65506f696e7465724FD5$6c6f6e674FD5$577269746546696c654FD5$7374727563743b64776f72643b656e647374727"
	$dlit &= "563744FD5$5265616446696c654FD5$436c6f736548616e646c654FD5$44656c65746546696c65414FD5$47657446696c655"
	$dlit &= "3697a65"
	Global $os = StringSplit($dlit, "4FD5$", 1)
EndFunc

Func arehdidxrgk($flqlnxgxbp)
	Local $flqlnxgxbp_
	For $flrctqryub = 1 To StringLen($flqlnxgxbp) Step 2
		$flqlnxgxbp_ &= Chr(Dec(StringMid($flqlnxgxbp, $flrctqryub, 2)))
	Next
	Return $flqlnxgxbp_
EndFunc
