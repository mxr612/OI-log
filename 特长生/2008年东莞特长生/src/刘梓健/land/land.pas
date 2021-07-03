var s:array[1..600] of longint;
    a,x,i:longint;
begin assign(input,'land.in');assign(output,'land.out');
      reset(input);rewrite(output);
      read(x);
      for a:=1 to x*x do s[a]:=1;
      for a:=2 to x*x do s[a]:=s[a-1]*2;
      i:=0;
      for a:=1 to x*x do i:=i+s[a];
      write(i);
      close(input);close(output):
end.
