var t,a,b,n,c,d:longint;
begin assign(input,'work.in');
      assign(output,'work.out');
      reset(input);rewrite(output);
      read(n);d:=0;
      for c:=1 to n do
      begin read(t,a,b);
            if b-(t-a)>d then d:=d+b-(t-a);
      end;
      write(d);
      close(input);close(output);
end.









