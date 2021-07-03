var n,q,q1,k,s1,s2,t:longint;
    s,jh:array[1..100]of longint;
procedure mp;
begin for q:=1 to n-1 do
         for q1:=q+1 to n do
           if s[q]<s[q1] then begin t:=s[q];s[q]:=s[q1];s[q1]:=t;
                                    t:=jh[q];jh[q]:=jh[q1];jh[q1]:=t;
                              end;
end;
begin assign(input,'num.in');
      assign(output,'num.out');
      reset(input);
      rewrite(output);
      readln(n);
      for q:=1 to n do
        read(s[q]);
      readln(k);
      for q:=1 to n do
        jh[q]:=q;
      mp;
      writeln(s[k]);
      writeln(jh[k]);
      close(input);
      close(output);
end.