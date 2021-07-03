var s,x,i,n,l,k:longint;
    j,y:array[1..100] of longint;
begin assign(input,'num.in');assign(output,'num.out');
      reset(input);rewrite(output);
      read(s);
      for x:=1 to s do
          begin read(j[x]);y[x]:=x;end;
      read(k);
      for i:=1 to s-1 do
          for n:=i+1 to s do
              if j[i]<j[n] then begin l:=j[i];j[i]:=j[n];j[n]:=l;
                                      l:=y[i];y[i]:=y[n];y[n]:=l;
                                end;
      writeln(j[k]);write(y[k]);
      close(input);close(output);
end.