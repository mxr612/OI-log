program snake;
 var
  d,b,c,i,j,n,s:integer;
  a:array[1..100,1..100]of integer;
 begin
  assign(input,'snake.in');
  reset(input);
  assign(output,'snake.out');
  rewrite(output);
  readln(n);
  i:=1; j:=1;b:=n*2-1;c:=n*n+1;
  for s:=1 to  b do
    if s<=n then
    begin
    if odd(s) then
    begin
    if s<>1 then
    for d:=1 to s do
    begin
    c:=c-1;
    a[i,j]:=c;
    if i<n then
    i:=i+1;
    if j<>1 then j:=j-1;
    end
    else begin c:=c-1;a[i,j]:=c; i:=i+1; end;
    end
    else
     begin
      for d:=1 to s do
      if d<>s then
      begin
      c:=c-1;
      a[i,j]:=c;
      i:=i-1;j:=j+1;
      end
      else begin c:=c-1;a[i,j]:=c;if odd(n) then j:=j+1
                                            else if (j<>n)or(i<>1)
                                                 then j:=j+1;end;
     end;
     end
     else
      begin
       if odd(s) then
        begin
         i:=i+1;
         for d:=1 to b-s+1 do
          if d<>b-s+1 then
           begin
            c:=c-1;
            a[i,j]:=c;
             i:=i+1;j:=j-1;
           end
           else begin c:=c-1;a[i,j]:=c; end;
        end
        else
         begin
          j:=j+1;
          for d:=1 to b-s+1 do
          if d<>b-s+1 then
           begin
            c:=c-1;
            a[i,j]:=c;
            i:=i-1;
            j:=j+1;
           end
           else begin c:=c-1;a[i,j]:=c;end;
        end;
        end;
    for i:=1 to n do
     begin
     for j:=1 to n-1 do
      write(a[i,j],' ');
      writeln(a[i,n]);
     end;
    close(input);
    close(output);
end.



