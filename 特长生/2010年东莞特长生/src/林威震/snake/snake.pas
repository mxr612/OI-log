var a:array[0..101,0..101]of longint;
    i,j,n,sum:longint;
begin
 assign(input,'snake.in');
 assign(output,'snake.out');
 reset(input);
 rewrite(output);
 read(n);
 sum:=n*n-1;
 a[1,1]:=n*n;
 i:=2;j:=1;
 while (sum>0) do
  begin
   a[i,j]:=sum;
   if n mod 2=1 then
    begin
     if (i=1)and(j mod 2=0) then inc(j)
     else if (i=1)and(j mod 2=1) then begin inc(i);dec(j);end
      else if (i=n)and(j mod 2=0) then begin dec(i);inc(j);end
       else if (i=n)and(j mod 2=1) then inc(j)
        else if (j=1)and(i mod 2=0) then begin dec(i);inc(j);end
         else if (j=1)and(i mod 2=1) then inc(i)
          else if (j=n)and(i mod 2=0) then inc(i)
           else if (j=n)and(i mod 2=1) then begin inc(i);dec(j);end
            else if a[i,j]=a[i-1,j+1]-1 then begin inc(i);dec(j);end
             else if a[i,j]=a[i+1,j-1]-1 then begin dec(i);inc(j);end;
     end
    else
     begin
      if (i=1)and(j mod 2=0)and(j<>n) then inc(j)
      else if (i=1)and(j mod 2=1) then begin inc(i);dec(j);end
       else if (i=n)and(j mod 2=1) then begin dec(i);inc(j);end
        else if (i=n)and(j mod 2=0) then inc(j)
         else if (j=1)and(i mod 2=0) then begin dec(i);inc(j);end
          else if (j=1)and(i mod 2=1) then inc(i)
           else if (j=n)and(i mod 2=0) then begin inc(i);dec(j);end
            else if (j=n)and(i mod 2=1) then inc(i)
             else if a[i,j]=a[i-1,j+1]-1 then begin inc(i);dec(j);end
              else if a[i,j]=a[i+1,j-1]-1 then begin dec(i);inc(j);end;
     end;
   dec(sum);
  end;
 for i:=1 to n do
  begin
   for j:=1 to n-1 do
    write(a[i,j],' ');
   write(a[i,n]);
   writeln;
  end;
 close(input);
 close(output);
end.