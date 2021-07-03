Program save;

Const
  Inf='save.in';
  Ouf='save.out';
  MaxN=1000;
  MaxNum=100000000;

Var
  N,Sx,Sy,Px,Py                 :Longint;
  Map                           :Array[1..MaxN,1..MaxN] Of Char;
  D                             :Array[1..MaxN,1..MaxN] Of Longint;
  List                          :Array[1..MaxN*MaxN,1..2] Of Longint;

  Procedure Init;
  Var
    I,J                         :Longint;
  Begin
    Assign(Input,Inf);
    Assign(Output,Ouf);
    Reset(Input);
    Readln(N);
    For I:=1 To N Do Begin
      For J:=1 To N Do
        Read(Map[I,J]);
      Readln;
    End;
    Readln(Sx,Sy,Px,Py);
    Close(Input);
    For I:=1 To N Do
      For J:=1 To N Do
        D[I,J]:=MaxNum;
  End;

  Procedure Work;
  Const
    Fx:Array[1..4,1..2] Of Longint=((1,0),(-1,0),(0,1),(0,-1));
  Var
    H,T,X,Y,X1,Y1,K             :Longint;
  Begin
    D[Sx,Sy]:=0;
    H:=0;T:=1;
    List[1,1]:=Sx;List[1,2]:=Sy;
    While H<T Do Begin
      Inc(H);
      X:=List[H,1];
      Y:=List[H,2];
      For K:=1 To 4 Do Begin
        X1:=X+Fx[K,1];Y1:=Y+Fx[K,2];
        If (X1>=1) And (X1<=N) Then
          If (Y1>=1) And (Y1<=N) Then
            If Map[X1,Y1]='0' Then
              If D[X1,Y1]=MaxNum Then Begin
                D[X1,Y1]:=D[X,Y]+1;
                Inc(T);
                List[T,1]:=X1;
                List[T,2]:=Y1;
              End;
      End;
    End;
  End;

  Procedure Out;
  Begin
    Rewrite(Output);
    Writeln(D[Px,Py]);
    Close(Output);
  End;

Begin
  Init;
  Work;
  Out;
End.



