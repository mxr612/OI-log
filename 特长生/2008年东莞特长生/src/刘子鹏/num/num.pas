program num(input,output);
var n,i,j,k,t:longint;
    a,no:array[1..100] of longint;
begin
  assign(input,'num.in');
  assign(output,'num.out');
  reset(input); rewrite(output);

  readln(n);
  for i:=1 to n do begin
    read(a[i]); no[i]:=i;
  end;
  readln(k);
  for i:=1 to n-1 do
  for j:=i+1 to n do
    if a[i]<a[j] then begin
      t:=a[i]; a[i]:=a[j]; a[j]:=t;
      t:=no[i]; no[i]:=no[j]; no[j]:=t;
    end;
  writeln(a[k]);
  writeln(no[k]);
  close(input); close(output);
end.
