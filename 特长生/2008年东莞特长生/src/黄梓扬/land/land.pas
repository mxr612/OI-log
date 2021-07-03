var n,i,l2:integer;
    s:array [1..1000] of integer;
    f1,f2:text;

procedure land;
 var i,j,k,g,l1:integer;
     f:array [1..1000] of integer;
 begin
  f:=s;
  f[1]:=1;s[1]:=1;l1:=1;l2:=1;g:=0;
  for i:=1 to n*n-1 do
   begin
    for j:=1 to l1 do
     begin
      f[j]:=f[j]*2+g;
      g:=f[j] div 10;
      f[j]:=f[j] mod 10;
     end;
    while g>0 do begin l1:=l1+1;f[l1]:=g mod 10;g:=g div 10;end;
    if l1>l2 then l2:=l1;
    for j:=1 to l2 do
     begin
      s[j]:=s[j]+f[j]+g;
      g:=s[j] div 10;
      s[j]:=s[j] mod 10;
     end;
    while g>0 do begin l2:=l2+1;s[l2]:=g mod 10;g:=g div 10;end;
   end;
 end;

begin
 assign(f1,'land.in');assign(f2,'land.out');
 reset(f1);rewrite(f2);
 readln(f1,n);
 fillchar(s,sizeof(s),0);
 land;
 for i:=l2 downto 1 do write(f2,s[i]);
 close(f1);close(f2);
end.