program x03;
var i,j,k,n,x,y,s:longint;   mx,my:longint;
    squa:array[0..250, 0..250]of longint;
    fir:boolean;

procedure readout;
begin
   for i:=1 to n do begin
      fir:=true;
      for j:=1 to n do begin
         if squa[i,j]=0 then continue;
         if fir then begin
           write(squa[i,j]);  fir:=false;
         end else write(' ',squa[i,j]);
      end;
      writeln;
   end;
end;

begin
   assign(input,'snake.in');
   reset(input);
   assign(output,'snake.out');
   rewrite(output);

   readln(n);
   fillchar(squa,sizeof(squa),0);

   x:=0; y:=0; s:=n*n; mx:=1; my:=1;
   while s>=1 do begin
      x:=x+mx;  y:=y+my;
      squa[y,x]:=s;
      if (y=1)and(odd(x)) then begin mx:=-1; my:=1; end;
      if (y=1)and(odd(x)=false) then begin mx:=1; my:=0;  end;
      if (x=1)and(odd(y)) then begin mx:=0; my:=1;  end;
      if (x=1)and(odd(y)=false) then begin mx:=1; my:=-1; end;
      if (y=n) then begin
         if squa[y-1,x+1] = 0 then begin mx:=1; my:=-1; end else
         begin mx:=1; my:=0; {Right} end;
      end;
      if (x=n) then begin
         if squa[y+1,x-1] = 0 then begin
            mx:=-1; my:=1;
         end else begin mx:=0; my:=1; {Down} end;
      end;
      if (x=1)and(y=1) then begin mx:=0; my:=1; end;
      dec(s);
   end;
   readout;
   close(input);
   close(output);
end.
