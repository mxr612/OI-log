var
  i,j,n,a1,b1,jw,k:longint;
  f:boolean;
  a,b:array[0..1000] of integer;
begin
  assign(input,'land.in');assign(output,'land.out');
  reset(input);rewrite(output);
  readln(n);
  if n=1 then begin writeln(1);close(input);close(output);halt;end;
  n:=n*n-1;
  a[1000]:=1;b[1000]:=1;
  a1:=1000;b1:=1000;
  for i:=1 to n do
   begin
     jw:=0;
     f:=true;
     for j:=1000 downto b1 do
      begin
        b[j]:=b[j]*2+jw;
        jw:=b[j] div 10;
        b[j]:=b[j] mod 10;
        if (jw<>0) and (j=b1) then f:=false;
      end;
     if f=false then begin b1:=b1-1;b[b1]:=jw;end;
     if a1<b1 then a1:=b1;
     jw:=0;
     f:=true;
     for j:=1000 downto a1 do
      begin
        a[j]:=a[j]+b[j]+jw;
        jw:=a[j] div 10;
        a[j]:=a[j] mod 10;
        if (jw<>0) and (j=a1) then f:=false;
      end;
     if f=false then begin a1:=a1-1;a[a1]:=jw;end;
   end;
  for i:=a1 to 1000 do write(a[i]);
  close(input);close(output);
end.






