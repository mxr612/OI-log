var a:array[1..10000] of longint;
    h:array[1..10000,1..10000] of integer;
    a1,b,b1,c,d,n,m:longint;
begin assign(input,'reward.in');
      assign(output,'reward.out');
      reset(input);rewrite(output);
      read(n,m);
      for b:=1 to n do
       a[b]:=100;
      for b:=1 to m do
      begin readln(a1,b1);h[a1,b1]:=1;
            if (a[a1]<=a[b1])and(h[b1,a1]<>1) then a[a1]:=a[b1]+1
             else if h[b1,a1]=1 then begin write(-1);close(output);break;end;
      end;
      for b:=1 to n do
       d:=d+a[b];
      write(d);
      close(input);close(output);
end.

