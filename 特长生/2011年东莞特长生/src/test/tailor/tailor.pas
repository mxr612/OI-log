program tailor;
var k,n,m:longint; s,ds:longint;

procedure input;
 var fi:text;
 begin
  assign(fi,'tailor.in'); reset(fi);
  readln(fi,k,n,m);
  close(fi);
 end;

procedure main;
 var fo:text;
 begin
  s:=1; ds:=0;
  while s<n*m do
   begin
    if s>=k then s:=s+k else s:=s+s;
    ds:=ds+1;
   end;
  assign(fo,'tailor.out'); rewrite(fo);
  write(fo,ds);
  close(fo);
 end;

begin
 input;
 main;
end.
