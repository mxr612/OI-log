var
  a,b:array[1..100] of longint;
  n,k,i,j,t:longint;
begin
  assign(input,'num.in'); reset(input);
  assign(output,'num.out'); rewrite(output);

  readln(n);
  for i:=1 to n do begin
    read(a[i]);
    b[i]:=a[i];
  end;
  readln(k);
  for i:=1 to n-1 do
    for j:=i to n do
      if b[i]<b[j] then begin
        t:=b[i];
        b[i]:=b[j];
        b[j]:=t;
      end;
  j:=0;
  for i:=1 to n do
    if b[k]=a[i] then j:=i;
  writeln(a[j]);
  writeln(j);
  close(input); close(output);
end.
