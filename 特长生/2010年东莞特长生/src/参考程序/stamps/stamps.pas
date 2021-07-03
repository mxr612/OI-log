program stamps;
var
 x:array[1..255] of integer;
 pieces:array[0..30000] of integer;
 max,m,n,I,j:integer;
 fin,fout:text;

begin
 assign(fin,'stamps.in');
 reset(fin);
assign(fout,'stamps.out');
rewrite(fout);
readln(fin,n);
readln(fin,m);
for I:=1 to m do
  readln(fin,x[I]);
close(fin);

fillchar(pieces,sizeof(pieces),0);
max:=0;
repeat
  max:=max+1;
   for I:=1 to m do
   if max-x[I]>=0 then
    begin
      if pieces[max]=0 then pieces[max]:=pieces[max-x[I]]+1;
      if pieces[max]>pieces[max-x[I]]+1 then pieces[max]:=pieces[max-x[I]]+1;
    end;
  if (pieces[max]=0) or (pieces[max]>n) then
   begin
     writeln(fout,max-1);
     close(fout);
     halt;
   end;
until false;
end.
