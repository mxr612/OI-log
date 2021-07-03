var
  d:boolean;
  i,j,k,n,m:integer;
  a:array [1..100,1..100] of word;

begin
  assign(input,'snake.in');
  assign(output,'snake.out');
  reset(input);
  rewrite(output);
  readln(n);
  m:=sqr(n)-1;
  i:=1;
  j:=1;
  a[1,1]:=m+1;
  d:=true;
  for k:=m downto 1 do
  begin
    if d then begin
      i:=i+1;
      j:=j-1;
    end else begin
      i:=i-1;
      j:=j+1;
    end;
    if i=n+1 then begin
      i:=n;
      j:=j+2;
      d:=false;
    end else
    if j=n+1 then begin
      j:=n;
      i:=i+2;
      d:=true;
    end else
    if i=0 then begin
      i:=1;
      d:=true;
    end else
    if j=0 then begin
      j:=1;
      d:=false;
    end;
    a[i,j]:=k;
  end;
  for i:=1 to n do begin
    write(a[i,1]);
    for j:=2 to n do
      write(' ',a[i,j]);
    writeln;
  end;
  close(input);
  close(output);
end.