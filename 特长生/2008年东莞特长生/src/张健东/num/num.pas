program num(input,output);
var
  a:array[0..100,1..2]of integer;
  i,j,k,n:integer;

begin
  assign(input,'num.in');
  assign(output,'num.out');
  reset(input);
  rewrite(output);
  readln(input,n);
  for i:=1 to n do begin
    a[i,1]:=i;
    read(input,a[i,2]);
  end;
  readln(input,k);
  for i:=2 to n do begin
    a[0,1]:=a[i,1];
    a[0,2]:=a[i,2];
    j:=i;
    while a[0,2]>a[j-1,2] do begin
      a[j,1]:=a[j-1,1];
      a[j,2]:=a[j-1,2];
      j:=j-1;
    end;
    a[j,1]:=a[0,1];
    a[j,2]:=a[0,2];
  end;
  writeln(output,a[k,2]);
  writeln(output,a[k,1]);
  close(input);
  close(output);
end.