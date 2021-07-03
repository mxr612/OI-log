program flower;
var
  value:array[0..100,0..100]of integer;
  look:array[1..100,1..100]of -50..50;
  i,j,k,f,v,total:integer;
  fin,fout:text;

procedure init;
begin
  fillchar(value,sizeof(value),0);
  fillchar(look,sizeof(look),0);
  assign(fin,'flower.in');
  reset(fin);
  readln(fin,f,v);
  for i:=1 to f do
    for j:=1 to v do
      read(fin,look[i,j]);
  close(fin);
  for i:=1 to f do begin
    total:=0;
    for j:=1 to i do
      inc(total,look[j,j]);
    value[i,i]:=total;
  end;
end;
procedure print;
begin
  assign(fout,'flower.out');
  rewrite(fout);
  writeln(fout,value[f,v]);
  close(fout);
end;

procedure main;
begin
  for i:=1 to f do
    for j:=i+1 to v-f+i do
      if value[i-1,j-1]+look[i,j]<value[i,j-1] then value[i,j]:=value[i,j-1]
      else value[i,j]:=value[i-1,j-1]+look[i,j];
end;

begin
  init;
  main;
  print;
end.
