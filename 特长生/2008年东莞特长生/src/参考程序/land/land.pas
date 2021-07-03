program mason;
Const Maxn=500;
Var
    a:Array[1..Maxn] of Byte;
    i,j,k,s,m:longint;
    n,p:longint;
Begin
 assign(Input,'land.in');
 assign(output,'land.out');
 reset(Input);  rewrite(Output);
 Readln(n);
 p:=n*n;
 For i:=1 to Maxn do a[i]:=0;
 a[1]:=1;
  For i:=1 to p do
  Begin
   k:=0;
   For j:=1 to Maxn do
    Begin
      s:=a[j]*2+k;
      k:=s div 10;
      a[j]:=s mod 10
    End;
   End;
 a[1]:=a[1]-1;
 m:=maxn;
 while a[m]=0 do m:=m-1;
 For i:=m downto 1 do
     Write(a[i]);
 Close(Input);  Close(Output);
End.
