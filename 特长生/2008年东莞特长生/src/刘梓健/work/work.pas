var n,x,s,i:longint;
    ti,ai,bi:array[1..1000] of longint;
begin assign(input,'work.in');assign(output,'work.out');
      reset(input);rewrite(output);
      read(n);
      for s:=1 to n do
          read(ti[s],ai[s],bi[s]);
      for s:=1 to n-1 do
          for x:=s+1 to n do
              if ti[s]<ti[x] then
              begin
              i:=bi[s];bi[s]:=bi[x];bi[x]:=i;
              i:=ai[s];ai[s]:=ai[x];ai[x]:=i;
              i:=ti[s];ti[s]:=ti[x];ti[x]:=i;
              end;
      for s:=1 to n-1 do
          begin for i:=s+1 to n do
                    if (bi[s]-ti[s]-ai[s])>=ti[i] then begin bi[i]:=0;ai[i]:=0;
                                                             ti[s]:=ti[s]+ti[i];ti[i]:=0;

                                                       end;
          end;
      for s:=n downto 1 do
          if ti[s]>0 then begin write(ti[s]);break;end;
      close(input);close(output);
end.