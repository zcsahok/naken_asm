;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Amiga dos.library include file
;; Part of the naken_asm assembler
;;
;; Generated by: Michael Kohn (mike@mikekohn.net)
;;         Date: 2019-Jan-01
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; dos.library

Open           equ -30 ; Open (name,accessMode) (D1,D2)
Close          equ -36 ; Close (file) (Dl)
Read           equ -42 ; Read (file,buf fer,length) (D1,D2,D3)
Write          equ -48 ; Write (file,buffer.length) (D1,D2,D3)
Input          equ -54 ; Input ()
Output         equ -60 ; Output ()
Seek           equ -66 ; Seek (file,position,offset) (D1,D2,D3)
DeleteFile     equ -72 ; DeleteFile (name)(Dl)
Rename         equ -78 ; Rename (oldName,newName) (D1,D2)
Lock           equ -84 ; Lock (name,type) (D1,D2)
UnLock         equ -90 ; UnLock (lock) (Dl)
DupLock        equ -96 ; DupLock (lock)(Dl)
Examine        equ -102 ; Examine (lock,fileInfoBlock) (D1,D2)
ExNext         equ -108 ; ExNext (lock,fileInfoBlock) (D1,D2)
Info           equ -114 ; Info (lock,parameterBlock) (D1,D2)
CreateDir      equ -120 ; CreateDir (name)(Dl)
CurrentDir     equ -126 ; CurrentDir (lock)(Dl)
IoErr          equ -132 ; IoErr ()
CreateProc     equ -138 ; CreateProc (name,pri,segList,stackSize) (D1,D2,D3,D4)
Exit           equ -144 ; Exit (returnCode)(Dl)
LoadSeg        equ -150 ; LoadSeg (fileName) (Dl)
UnLoadSeg      equ -156 ; UnLoadSeg (segment)(Dl)
GetPacket      equ -162 ; GetPacket (wait)(Dl)
QueuePacket    equ -168 ; QueuePacket (packet)(Dl)
DeviceProc     equ -174 ; DeviceProc (name)(Dl)
SetComment     equ -180 ; SetComment (namefcomment) (D1,D2)
SetProtection  equ -186 ; SetProtection (name,mask) (D1,D2)
DateStamp      equ -192 ; DateStamp (date) (Dl)
Delay          equ -198 ; Delay (timeout) (Dl)
WaitForChar    equ -204 ; WaitForChar (file.timeout) (D1,D2)
ParentDir      equ -210 ; ParentDir (lock)(Dl)
IsInteractive  equ -216 ; Islnteractive (file)(Dl)
Execute        equ -222 ; Execute (string,file,file) (D1,D2,D3)
