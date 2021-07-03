program num;
var
 i,j,n,k,temp:integer;
 a,b:array[1..100] of integer;
 fin,fout:text;
begin
  assign(fin,'num.in');
  assign(fout,'num.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  for i:=1 to n do
    begin
      read(fin,a[i]);
      b[i]:=i;
    end;
   readln(fin);
   readln(fin,k);
  for i:=1 to n-1 do
    for j:=i+1 to n do
     if a[i]<a[j] then
      begin
        temp:=a[i]; a[i]:=a[j]; a[j]:=temp;
        temp:=b[i]; b[i]:=b[j]; b[j]:=temp;
      end;
   writeln(fout,a[k]);
   writeln(fout,b[k]);
   close(fin);
   close(fout);
end.
