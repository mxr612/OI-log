var a,h:array[1..32767] of longint;
    k,n,b,c,d:longint;
begin assign(input,'num.in');
      assign(output,'num.out');
      reset(input);rewrite(output);
      read(n);d:=0;
      for b:=1 to 32767 do
        a[b]:=0;
      for b:=1 to n do
      begin read(c);
            a[c]:=1;
            h[c]:=b;
      end;
      read(k);
      for b:=32767 downto 1 do
       if a[b]<>0 then begin d:=d+1;
                      if d=k then begin writeln(b);
                                        write(h[b]);end;
                       end;
      close(input);close(output);
end.