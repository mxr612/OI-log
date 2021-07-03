{$Q+,R+,S+}
Program ex;
Const Maxn=10000;
      Inf='reward.in';
      Ouf='reward.out';
Type Gnode              =^Pnode;
     Pnode              =Record
                           Num:Longint;
                           Next:Gnode;
                         End;
Var N,M                 :Longint;
    G                   :Array [1..Maxn] Of Gnode;
    De,F                :Array [1..Maxn] Of Longint;
    List                :Array [1..Maxn] Of Longint;
    Len,Ans             :Longint;
Procedure Add(X,Y:Longint);
Var Tmp                 :Gnode;
Begin
  New(Tmp);
  Tmp^.Num:=Y;
  Tmp^.Next:=G[X];
  G[X]:=Tmp;
  Inc(De[Y]);
End;
Procedure Init;
Var P,X,Y               :Longint;
Begin
  Assign(Input,Inf);
  Reset(Input);
  Readln(N,M);
  For P:=1 To N Do G[P]:=Nil;
  For P:=1 To M Do Begin
    Readln(X,Y);
    Add(Y,X);
  End;
  Close(Input);
End;
Procedure Noans;
Begin
  Assign(Output,Ouf);
  Rewrite(Output);
  Writeln('-1');
  Close(Output);
  Halt;
End;
Procedure Main;
Var P,Q,Link            :Longint;
    Tmp                 :Gnode;
Begin
  Len:=0;
  For P:=1 To N Do
    If De[P]=0 Then Begin
      Inc(Len);
      List[Len]:=P;
    End;
  Link:=0;
  While Link<Len Do Begin
    Inc(Link);
    P:=List[Link];
    Tmp:=G[P];
    While Tmp<>Nil Do Begin
      Dec(De[Tmp^.Num]);
      If De[Tmp^.Num]=0 Then Begin
        Inc(Len);
        List[Len]:=Tmp^.Num;
      End;
      Tmp:=Tmp^.Next;
    End;
  End;
  If Len<>N Then Noans;
  For P:=1 To N Do F[P]:=100;
  For P:=1 To N Do Begin
    Q:=List[P];
    Tmp:=G[Q];
    While Tmp<>Nil Do Begin
      If F[Q]>=F[Tmp^.Num] Then F[Tmp^.Num]:=F[Q]+1;
      Tmp:=Tmp^.Next;
    End;
  End;
  Ans:=0;
  For P:=1 To N Do
    Ans:=Ans+F[P];
  Assign(Output,Ouf);
  Rewrite(Output);
  Writeln(Ans);
  Close(Output);
End;
Begin
  Init;
  Main;
End.
