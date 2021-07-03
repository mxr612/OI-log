var f:boolean;
    s,n,x,o:longint;
    j,i,m:array[1..20000] of longint;
begin assign(input,'reward.in');assign(output,'reward.out');
      reset(input);rewrite(output);
      read(s,n);
      for x:=1 to s do j[x]:=100;
      for x:=1 to n do read(i[x],m[x]);
      f:=true;o:=1;
       while (o<7) and (f) do
            begin f:=false;
                  for x:=1 to n do
                      if j[i[x]]<=j[m[x]] then begin f:=true;j[i[x]]:=j[i[x]]+1;end;
                  o:=o+1;
            end;
      n:=0;
      if o=7 then write(-1)
      else begin
      for x:=1 to s do
          n:=n+j[x];
      write(n);
      end;
      close(input);close(output);
end.
