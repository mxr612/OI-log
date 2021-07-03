var
  n,k,z,i,j,x,y:integer;
  a:array[1..100,1..100]of integer;
begin
  assign(input,'snake.in');reset(input);
  assign(output,'snake.out');rewrite(output);
  readln(n);
  k:=n*n;z:=0;
  a[1,1]:=k;x:=1;y:=1;
  while z+1<n do
   begin
    if y=1 then
      begin
        dec(k);
        inc(x);
        a[x,y]:=k;
        if z<n then
          inc(z);
        for i:=1 to z do
          begin
            dec(k);
            dec(x);inc(y);
            a[x,y]:=k;
          end;
      end
      else
      begin
        if x=1 then
          begin
            dec(k);
            inc(y);
            a[x,y]:=k;
            if z<n then
              inc(z);
            for i:=1 to z do
              begin
                dec(k);
                inc(x);dec(y);
                a[x,y]:=k;
              end;
          end;
      end;
  end;
  k:=n*n;
  for i:=n downto 2 do
    for j:=n downto n-i+2 do
      a[i,j]:=k-a[n-i+1,n-j+1]+1;
  for i:=1 to n do
    begin
      for j:=1 to n do
        write(a[i,j],' ');
        writeln;
    end;
  close(input);
  close(output);
end.
