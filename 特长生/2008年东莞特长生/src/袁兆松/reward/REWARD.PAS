program reward(input,output);
var
  n,m,i,j,min,t:integer;
  a,b,c:array[1..10000]of integer;
begin
  assign(input,'reward.in'); reset(input);
  assign(output,'reward.out'); rewrite(output);
  read(n,m);
  for i:= 1 to m do
    read(a[i],b[i]);
  for i:= 1 to n do
    c[i]:=100;
  for i:=1 to m-1 do
  begin
    for j:=i+1 to m do
    if a[i]=b[j] then begin
                   if b[i]=a[j] then begin
                                       writeln('-1');
                                       t:=1;
                                     end;
                      end;
  end;
  if t<>1 then begin
                   for i:=1 to m do
                     c[a[i]]:=c[b[i]]+1;
                   for i:=1 to n do
                     min:=c[i]+min;
                   writeln(min);
                 end;
  close(input);  close(output);
end.
