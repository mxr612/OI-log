program tool;
var
 x,n,m,a,b,i,j,s,t:longint;
 d:array[1..20] of integer;
 fin,fout:text;
begin
  assign(fin,'tool.in');
  assign(fout,'tool.out');
  reset(fin);
  rewrite(fout);
  readln(fin,x,m,n);
  close(fin);
  s:=x; b:=0; t:=0;
  WHILE s > 0 do
    begin
      a:=s MOD 10;
      s:=s div 10;
      t:=t+1; j:=1;
      for i:=1 to t-1 do
        j:=j*m;
      b:=b+a*j;
    end;
  j:=0;
  WHILE b > 0 do
    begin
      a:= b MOD n;
      b:= b div n;
       j:= j + 1;
      d[j]:=a;
    END;
   FOR i:= j downto 1 do
     write(fout,d[i]);
     close(fout);
  END.