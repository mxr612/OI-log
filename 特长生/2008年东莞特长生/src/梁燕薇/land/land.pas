var
  a:array[1..500] of longint;
  n,i,j,k,t:longint;
begin
  assign(input,'land.in'); reset(input);
  assign(output,'land.out'); rewrite(output);
  readln(n);
  a[1]:=1;
  j:=1;
  t:=0;
  for i:=1 to n*n-1 do begin
    t:=0;
    for k:=1 to j do begin
      if k=1 then a[k]:=a[k]+a[k]+t+1
      else a[k]:=a[k]+a[k]+t;
      t:=a[k] div 10;
      a[k]:=a[k] mod 10;
    end;
    if t>0 then begin
      j:=j+1;
      a[j]:=t;
    end;
  end;
  for i:=j downto 1 do write(a[i]);

  close(input); close(output);

end.
