program num(input,output);
var
  n,i,k,j,t,m:integer;
  a,b:array[1..100]of integer;
begin
  assign(input,'num.in'); reset(input);
  assign(output,'num.out'); rewrite(output);
  read(n);
  readln;
  for i:=1 to n do
    begin
      read(a[i]); b[i]:=a[i];
    end;
  read(k);
  for i:=2 to n do
    begin
    for j:=1 to n do
      if b[j]<b[i] then begin
                          t:=b[i];
                          b[i]:=b[j];
                          b[j]:=t;
                        end;
    end;
  write(b[k]);
  writeln;
  for i:=1 to n do
    if b[k]=a[i] then begin
                        write(i);
                        break;
                      end;
  close(input); close(output);
end.