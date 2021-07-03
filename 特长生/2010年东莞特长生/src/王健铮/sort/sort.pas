program sort;
 var
  a,b:array[1..200]of integer;
  i,j,k,n,g:integer;
 begin
  assign(input,'sort.in');
  reset(input);
  assign(output,'sort.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do
   begin
    read(a[i]);
    readln(b[i]);
   end;
  for i:=1 to n-1 do
   for j:=i+1 to n do
    if b[i]<b[j] then
     begin
      g:=a[i];
      a[i]:=a[j];
      a[j]:=g;
      g:=b[i];
      b[i]:=b[j];
      b[j]:=g;
     end;
  for i:=1 to n-1 do
   for j:=i+1 to n do
    if (b[i]=b[j])and(a[i]>a[j]) then
     begin
      g:=a[i];
      a[i]:=a[j];
      a[j]:=g;
      g:=b[i];
      b[i]:=b[j];
      b[j]:=g;
     end;
  writeln(a[1],' ',b[1],' ',1);
  a[1]:=1;
 for i:=2 to n do
  if b[i]=b[i-1] then begin writeln(a[i],' ',b[i],' ',a[i-1]);
                            a[i]:=a[i-1]; end
                      else  begin writeln(a[i],' ',b[i],' ',i);
                            a[i]:=i;
                      end;
  close(input);
  close(output);
 end.




