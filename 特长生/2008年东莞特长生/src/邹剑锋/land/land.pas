var
  m,n,i,j,b,c,k:integer;
  a:array[1..500]of integer;
begin
  assign(input,'land.in'); reset(input);
  assign(output,'land.out'); rewrite(output);
  read(n);
  if n=1 then write('1');
  a[1]:=3;
  for i:=4 to n*n do begin
      k:=2;
     for j:=1 to i-2 do begin
         k:=2*k;
         c:=k;
         m:=1;
         while c<>0 do begin
               b:=c mod 10;
               c:=c div 10;
               a[m]:=a[m]+b;
               if a[m]>=10 then begin a[m]:=a[m]-10; a[m+1]:=a[m+1]+1; end;
               m:=m+1;
               end;
    end;
  end;
  for i:=500 downto 1 do if a[i]<>0 then break;
  for j:=i downto 1 do write(a[j]);
  close(input);
  close(output);
end.

