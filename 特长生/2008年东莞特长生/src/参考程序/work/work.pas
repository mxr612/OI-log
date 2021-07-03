Program work;
Const Maxn=1000;
      Maxt=1100;
      Inf='work.in';
      Ouf='work.out';
Var T,A,B               :Array [0..Maxn] Of Longint;
    F                   :Array [0..Maxt+1] Of Longint;
    N,Start             :Longint;
Procedure Init;
Var P                   :Longint;
Begin
  Start:=Maxt;
  Assign(Input,Inf);
  Reset(Input);
  Readln(N);
  For P:=1 To N Do Begin
    Readln(T[P],A[P],B[P]);
    If A[P]<Start Then Start:=A[P];
  End;
  Close(Input);
End;
Procedure Main;
Var I,J                 :Longint;
    Find                :Boolean;
Begin
  Fillchar(F,Sizeof(F),$ff);
  F[Start]:=0;
  For I:=Start To Maxt Do
    If F[I]<>-1 Then Begin
      Find:=False;
      For J:=1 To N Do
        If (A[J]<=I) And (I+T[J]<=B[J]) Then Begin
          Find:=True;
          If (F[I+T[J]]=-1) Or (F[I+T[J]]>F[I]+T[J]) Then
            F[I+T[J]]:=F[I]+T[J];
        End;
     If Not Find Then
       If (F[I+1]=-1) Or (F[I+1]>F[I]) Then F[I+1]:=F[I];
    End;
  Assign(Output,Ouf);
  Rewrite(Output);
  Writeln(F[Maxt]);
  Close(Output);
End;
Begin
  Init;
  Main;
End.
