program pp;
var a,b:array[0..1002] of integer;
    n,i,k,j:integer;
begin
  assign(input,'land.in');
  assign(output,'land.out');
  reset(input);rewrite(output);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  readln(n);
  a[1000]:=1;
  b[1000]:=1;
  for i:=2 to n*n+1 do
  begin
    for j:=1000 downto 1 do
    begin
      a[j]:=a[j]*2;
      if a[j+1]>10 then
      begin
        a[j]:=a[j]+a[j+1] div 10;
        a[j+1]:=a[j+1] mod 10;
      end;
    end;
    {for j:=1000 downto 1 do
    begin
      b[j]:=b[j]+a[j];
      b[j-1]:=b[j-1]+b[j] div 10;
      b[j]:=b[j] mod 10;
    end;}
  end;
  a[1000]:=a[1000]-1;
  for i:=1 to 1000 do if a[i]<>0 then begin k:=i;break; end;
  for i:=k to 1000 do write(a[i]);
  close(input);close(output);
end.
