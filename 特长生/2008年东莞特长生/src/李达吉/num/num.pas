program num(input,output);
var
  a,b:array[1..100] of integer;
  n,k,i,j,t:integer;
begin
  assign(input,'num.in');
  assign(output,'num.out');
  reset(input); rewrite(output);
  readln(n);
  for i:=1 to n do begin read(a[i]); b[i]:=i; end;
  readln(k);
  for i:=1 to n do
    for j:=i+1 to n do
      if a[i]<a[j] then begin
        t:=a[i];
        a[i]:=a[j];
        a[j]:=t;
        t:=b[i];
        b[i]:=b[j];
        b[j]:=t;
      end;
  writeln(a[k]);
  writeln(b[k]);
  close(input); close(output);
end.